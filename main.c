#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include "sys/types.h"
#include "sys/sysinfo.h"
#include <sys/time.h>
#include <fcntl.h>
#include "globals.h"
#include "sync.h"
#include <sys/statvfs.h>
#include "linki2c.h"
#include <spawn.h>
#include <sys/wait.h>

#include <dirent.h>
#include <sys/stat.h>

#include "mean.h"

#define DISK_LOCATION "/media/RAW"
#define REDIS_ADDR "127.0.0.1"
#define REDIS_PORT 6379

#define DISPLAY_WIDTH 720
#define DISPLAY_HEIGHT 720

#define SYSTATS_INTERVAL_MS 1000
#define MAIN_THREAD_INTERVAL_US 16667

#define DISP_BUF_SIZE (DISPLAY_WIDTH*DISPLAY_HEIGHT)
#define STATUS_NORMAL 0x4AFF73
#define STATUS_WARNING 0xFFC449
#define STATUS_CRITICAL 0xFF4848

#define LOCK_SYMBOL "\xEF\x80\xA3"
#define UNLOCK_SYMBOL "\xEF\x8F\x81"

meanqueue_t *vBattMean;

uint32_t timer = 0;
uint32_t timer2 = 0;
uint32_t recTimer = 0;
struct sysinfo memInfo;
static unsigned long long lastTotalUser, lastTotalUserLow, lastTotalSys, lastTotalIdle;
double fsize, fblocks, ffree;
struct statvfs statV;

redisContext *context;
redisReply *reply;

pthread_t cameraThread;
extern char **environ;

lv_obj_t * clipList;

int redis_init(){
    context = redisConnect(REDIS_ADDR, REDIS_PORT);
    if (!context) {
        fprintf(stderr, "Error:  Can't connect to Redis\n");
        return -1;
    }
}

static bool getDiskAttached(){
	FILE* file;
	const int max_buffer = 256;
	char buffer[max_buffer];
    file = popen("cat /proc/mounts | grep /media/RAW", "r");
    if(file){
		while(!feof(file)){
			if (fgets(buffer, max_buffer, file) != NULL){
				return true;
			} 
		}
		pclose(file);
	}
    return false;
}

static void get_disk_stats(){
    if (statvfs(DISK_LOCATION, &statV) != 0) {
        fsize = 0;
        ffree = 0;
        lv_obj_set_style_text_color(ui_storageLabel, lv_color_hex(STATUS_WARNING), LV_PART_MAIN | LV_STATE_DEFAULT);
    } else {
        fsize = ((double)statV.f_frsize) / (double)(1024);
        fblocks = ((double)statV.f_blocks) / (double)(1024);
        ffree = ((double)statV.f_bfree) / (double)(1024);
        lv_obj_set_style_text_color(ui_storageLabel, lv_color_hex(STATUS_NORMAL), LV_PART_MAIN | LV_STATE_DEFAULT);
    }

    char buffer[32];
    sprintf(buffer, "\xEF\x8a\x87: %0.0f/%0.0f GB",(fsize * ffree)/1000, (fsize * fblocks)/1000);
    lv_label_set_text(ui_storageLabel,(const char *)buffer);
}

static void get_cpu_util(){

    double percent;
    FILE* file;
    unsigned long long totalUser, totalUserLow, totalSys, totalIdle, total;

    file = fopen("/proc/stat", "r");
    fscanf(file, "cpu %llu %llu %llu %llu", &totalUser, &totalUserLow,
        &totalSys, &totalIdle);
    fclose(file);

    if (totalUser < lastTotalUser || totalUserLow < lastTotalUserLow ||
        totalSys < lastTotalSys || totalIdle < lastTotalIdle){
        //Overflow detection. Just skip this value.
        percent = -1.0;
    }
    else{
        total = (totalUser - lastTotalUser) + (totalUserLow - lastTotalUserLow) +
            (totalSys - lastTotalSys);
        percent = total;
        total += (totalIdle - lastTotalIdle);
        percent /= total;
        percent *= 100;
    }

    lastTotalUser = totalUser;
    lastTotalUserLow = totalUserLow;
    lastTotalSys = totalSys;
    lastTotalIdle = totalIdle;

    int p = (int)percent;
    int bg_color = STATUS_NORMAL;

    char buffer[16];
    snprintf(buffer, sizeof(buffer), "%3.2f%%\0", percent);
    lv_label_set_text(ui_cpuValue, buffer);

    lv_bar_set_value(ui_cpuBar, p, LV_ANIM_ON);
    if(p >= 67){
        bg_color = STATUS_CRITICAL;
    } else if(p < 67 && p >= 34){
        bg_color = STATUS_WARNING;
    }
    lv_obj_set_style_text_color(ui_cpuValue, lv_color_hex(bg_color), LV_PART_MAIN | LV_STATE_DEFAULT);
    
}

static int get_mem_usage(){
    int used;
    int available;
    float res = 1.0;
    char buffer[16];
    FILE *f;
    f = popen("free | awk 'NR!=1 {print $3}'", "r");
    fgets(buffer, 16, f);
    used = atoi(buffer);

    f = popen("free | awk 'NR!=1 {print $2}'", "r");
    fgets(buffer, 16, f);
    available = atoi(buffer);

    pclose(f);

    res = ((float)used/(float)available)*100.0;
    return (int)res;
}

static void get_mem_util(){
    // sysinfo (&memInfo);
    // long long totalPhysMem = memInfo.totalram;
    //Multiply in next statement to avoid int overflow on right hand side...
    // totalPhysMem *= memInfo.mem_unit;

    // long long physMemUsed = memInfo.totalram - memInfo.freeram;
    //Multiply in next statement to avoid int overflow on right hand side...
    // physMemUsed *= memInfo.mem_unit;

    // int p = (int)(((float)physMemUsed/(float)totalPhysMem)*100.0);
    int p = get_mem_usage();
    int bg_color = STATUS_NORMAL;

    lv_bar_set_value(ui_memBar, p, LV_ANIM_ON);
    if(p >= 67){
        bg_color = STATUS_CRITICAL;
    } else if(p < 67 && p >= 34){
        bg_color = STATUS_WARNING;
    }
    lv_obj_set_style_bg_color(ui_memBar, lv_color_hex(bg_color), LV_PART_INDICATOR | LV_STATE_DEFAULT);
}

static void get_cpu_temp(){
    float systemp, millideg;
    FILE *thermal;
    int n;

    thermal = fopen("/sys/class/thermal/thermal_zone0/temp","r");
    n = fscanf(thermal,"%f",&millideg);
    fclose(thermal);
    systemp = millideg / 1000;

    int p = (int)systemp;
    int bg_color = STATUS_NORMAL;

    // lv_bar_set_value(ui_ctempBar, p, LV_ANIM_ON); 

    char buffer[12];
    snprintf(buffer, sizeof(buffer), "%d°c", p);
    lv_label_set_text(ui_ctempValue, buffer);

    if(p >= 79){
        bg_color = STATUS_CRITICAL;
    } else if(p < 70 && p >= 60){
        bg_color = STATUS_WARNING;
    }
    lv_obj_set_style_text_color(ui_ctempValue, lv_color_hex(bg_color), LV_PART_MAIN | LV_STATE_DEFAULT);
}

void frames_to_timecode(uint32_t f,  uint16_t fr, bool tc_on){
    char buffer[32];
    if(!tc_on){
        int t1 = f / (3600*fr);
        int t2 = (f / (60*fr)) % 60;
        int t3 = (f / fr) % 60;
        int t4 = (f % fr);
        snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d:%02d\0", t1, t2, t3, t4);
    } else {
        char ms[3];
        time_t t;
		time(&t);
		struct tm *time_info = localtime(&t);
        struct timeval tmnow;
        gettimeofday(&tmnow, NULL);
		strftime(buffer, sizeof(buffer), "%H:%M:%S:00", time_info);
        snprintf(ms, sizeof(ms), "%02d", (tmnow.tv_usec / 1000) / (1000/fr));
        buffer[9] = ms[0];
        buffer[10] = ms[1];
    }

    lv_label_set_text(ui_timecode, (const char*)buffer);
    // int recPin = myDigitalRead(&i2cnode, 4);
    int recPin = myDigitalRead(&i2cnode, 4);
    int bg_color = 0xFFFFFF;
    if(recPin){
        bg_color = 0xFF0000;
    } 
    lv_obj_set_style_text_color(ui_timecode, lv_color_hex(bg_color), LV_PART_MAIN | LV_STATE_DEFAULT);
}

static int handleClipLoad(){
    if(!cplvdata.loadClips){
        return -1;
    } else {
        cplvdata.loadClips = false;
    }
        

    lv_obj_clean(clipList);

    const char* path = "/media/RAW";
    int recursive = 0;

    struct dirent *direntp = NULL;
    DIR *dirp = NULL;
    DIR *dirpF = NULL;
    size_t path_len;

    /* Check input parameters. */
    if (!path)
        return -1;
    path_len = strlen(path);  

    if (!path || !path_len || (path_len > _POSIX_PATH_MAX))
        return -1;

    /* Open directory */
    dirp = opendir(path);
    if (dirp == NULL)
        return -1;

    while ((direntp = readdir(dirp)) != NULL)
    {
        /* For every directory entry... */
        struct stat fstat;
        char full_name[_POSIX_PATH_MAX + 1];

        /* Calculate full name, check we are in file length limts */
        if ((path_len + strlen(direntp->d_name) + 1) > _POSIX_PATH_MAX)
            continue;

        strcpy(full_name, path);
        if (full_name[path_len - 1] != '/')
            strcat(full_name, "/");
        strcat(full_name, direntp->d_name);

        /* Ignore special directories. */
        if ((strcmp(direntp->d_name, ".") == 0) ||
            (strcmp(direntp->d_name, "..") == 0))
            continue;

        /* Print only if it is really directory. */
        if (stat(full_name, &fstat) < 0)
            continue;
        if (S_ISDIR(fstat.st_mode))
        {
            int file_count = 0;
            dirpF = opendir(full_name);
            struct dirent * entry;
            while ((entry = readdir(dirpF)) != NULL) {
                if (entry->d_type == DT_REG) { /* If the entry is a regular file */
                    file_count++;
                }
            }
            char buffer[64];
            sprintf(buffer,"%d frames", file_count);
            // printf("%s\n", full_name);
            lv_list_add_text(clipList, direntp->d_name);
            lv_list_add_btn(clipList, NULL, (const char*)buffer);
        }
    }

    /* Finalize resources. */
    (void)closedir(dirp);
    return 0;
}

static void handleUpdateControls(){

    if(cplvdata.uFps){
        cplvdata.uFps = 0;  
        char buf[32];
        lv_roller_get_selected_str(ui_frameRateControl, buf, 32);
        float fps = atof(buf);
        reply = redisCommand(context, "SET %s %.2f", "fps", fps);
        if (!reply || context->err) {
            fprintf(stderr, "Error:  Can't send command to Redis\n");
        }
        freeReplyObject(reply);
    }

    if(cplvdata.uSh){
        cplvdata.uSh = 0;  
        char buf[32];
        lv_roller_get_selected_str(ui_shutterControl, buf, 32);
        int shutter = atoi(buf);
        reply = redisCommand(context, "SET %s %d", "shutter", shutter);
        if (!reply || context->err) {
            fprintf(stderr, "Error:  Can't send command to Redis\n");
        }
        freeReplyObject(reply);
    }

    if(cplvdata.uIso){
        cplvdata.uIso = 0;  
        char buf[32];
        lv_roller_get_selected_str(ui_isoControl, buf, 32);
        int iso = atoi(buf);
        reply = redisCommand(context, "SET %s %d", "iso", iso);
        if (!reply || context->err) {
            fprintf(stderr, "Error:  Can't send command to Redis\n");
        }
        freeReplyObject(reply);
    }

    if(cplvdata.uWb){
        cplvdata.uWb = 0;  
        char buf[32];
        lv_roller_get_selected_str(ui_whiteBalanceControl, buf, 32);
        int wb = atoi(buf);
        reply = redisCommand(context, "SET %s %d", "wb", wb);
        if (!reply || context->err) {
            fprintf(stderr, "Error:  Can't send command to Redis\n");
        }
        freeReplyObject(reply);
    }

    reply = (redisReply*)redisCommand(context, "GET %s", "update");
    if (!reply || context->err || reply->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }
    int update = atoi(reply->str);
    freeReplyObject(reply);

    cplvdata.stateSet = (bool)update;


}

static void handleCompressionSwitch(){

    int selected = lv_dropdown_get_selected(ui_dropdownCompression);
    int compression = 1;
    if(selected){
        compression = 7;
    }
    reply = redisCommand(context, "SET %s %d", "compression", compression);
    if (!reply || context->err) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }
    freeReplyObject(reply);
}

static void handleResolution(){

    int selected = lv_dropdown_get_selected(ui_dropdownResolution);
    int width, height;
    switch(selected){    
        case 1:    
            width = 2028;
            height = 1080;  
            break; 
        case 2:    
            width = 2028;
            height = 1520;     
            break;  
        case 3:    
            width = 4056;
            height = 3040;     
            break;  
        default:
            width = 2028;
            height = 1080; 
    }  
    reply = redisCommand(context, "SET %s %d", "width", width);
    if (!reply || context->err) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }
    freeReplyObject(reply);
    reply = redisCommand(context, "SET %s %d", "height", height);
    if (!reply || context->err) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }
    freeReplyObject(reply);
}

static void bufferStatus(){
    reply = (redisReply*)redisCommand(context, "GET %s", "recording");
    if (!reply || context->err || reply->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }

    int recording = atoi(reply->str);
    freeReplyObject(reply);

    if(recording){
        int bg_color = STATUS_CRITICAL;
        lv_obj_set_style_text_color(ui_storageLabel, lv_color_hex(bg_color), LV_PART_MAIN | LV_STATE_DEFAULT);
    } 
    
}

static void handleGetFrames(){
    reply = (redisReply*)redisCommand(context, "GET %s", "frames");
    if (!reply || context->err || reply->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }
    cpdata.frames = atoi(reply->str);
    freeReplyObject(reply);

    reply = (redisReply*)redisCommand(context, "GET %s", "fps");
    if (!reply || context->err || reply->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }
    cpdata.framerate = atoi(reply->str);
    freeReplyObject(reply);
}

static void handleGetBuffers(){
    reply = (redisReply*)redisCommand(context, "GET %s", "buffers");
    if (!reply || context->err || reply->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }

    int buffers = atoi(reply->str);
    freeReplyObject(reply);

    int bg_color = STATUS_NORMAL;
    if(buffers >= 400){
        bg_color = STATUS_CRITICAL;
    } else if(buffers < 400 && buffers >= 448/2){
        bg_color = STATUS_WARNING;
    }
    lv_obj_set_style_bg_color(ui_storageBar, lv_color_hex(bg_color), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_bar_set_value(ui_storageBar, buffers, LV_ANIM_ON);
}

static void handleRecTrigger(){
    if(cplvdata.doRec){
        cplvdata.doRec = false;
        LV_LOG_USER("DO THE REC!");
        reply = redisCommand(context, "SET %s %d", "record", 1);
        if (!reply || context->err) {
            fprintf(stderr, "Error:  Can't send command to Redis\n");
        }
        freeReplyObject(reply);
    }
}

static void handleZoom(){
    if(cplvdata.zoomDir != 0){
        int val = cplvdata.zoomDir;
        cplvdata.zoomDir = 0;
        reply = redisCommand(context, "SET %s %d", "zoom", val);
        if (!reply || context->err) {
            fprintf(stderr, "Error:  Can't send command to Redis\n");
        }
        freeReplyObject(reply);
    }
}

static void handleLiveView(){
    // if(cplvdata.lvEn == 0){
    //     int val = cplvdata.lvEn;
    //     cplvdata.lvEn = -1;
    //     reply = redisCommand(context, "SET %s %d", "lv", 0);
    //     if (!reply || context->err) {
    //         fprintf(stderr, "Error:  Can't send command to Redis\n");
    //     }
    //     freeReplyObject(reply);
    // }
    // if(cplvdata.lvEn == 1){
    //     int val = cplvdata.lvEn;
    //     cplvdata.lvEn = -1;
    //     reply = redisCommand(context, "SET %s %d", "lv", 1);
    //     if (!reply || context->err) {
    //         fprintf(stderr, "Error:  Can't send command to Redis\n");
    //     }
    //     freeReplyObject(reply);
    // }
    reply = redisCommand(context, "SET %s %d", "lv", cplvdata.lvEn);
    if (!reply || context->err) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }
    freeReplyObject(reply);
}

static void handleLockControls(){
    if(cplvdata.setLock){
        lv_obj_add_state(ui_isoControl,LV_STATE_DISABLED);
        lv_obj_add_state(ui_whiteBalanceControl,LV_STATE_DISABLED);
        lv_obj_add_state(ui_shutterControl,LV_STATE_DISABLED);
        lv_obj_add_state(ui_frameRateControl,LV_STATE_DISABLED);
        lv_obj_add_state(ui_recButton,LV_STATE_DISABLED);
    } else {
        lv_obj_clear_state(ui_isoControl,LV_STATE_DISABLED);
        lv_obj_clear_state(ui_whiteBalanceControl,LV_STATE_DISABLED);
        lv_obj_clear_state(ui_shutterControl,LV_STATE_DISABLED);
        lv_obj_clear_state(ui_frameRateControl,LV_STATE_DISABLED);
        lv_obj_clear_state(ui_recButton,LV_STATE_DISABLED);
    }
}

void handlePwrNode(){
    int v = pwrRead(&pwrnode, 17);
    if(v < 2){
        pwrButton.state = v;
    }

    if(pwrButton.state != pwrButton.lastState){
        if(pwrButton.state == KEY_PRESSED){
            pwrButton.pressTime = custom_tick_get();
            pwrButton.down = true;
        } else {
            pwrButton.down = false;
        }
    }

    pwrButton.lastState = pwrButton.state;

    if(pwrButton.down == true && custom_tick_get() - pwrButton.pressTime >= KEY_DURATION){
        pwrButton.down = false;
        system("sudo shutdown now");
    }
}

void handleBatteryStatus(){
    int vi = pwrRead(&pwrnode, 3);
    int vd = pwrRead(&pwrnode, 4);
    int vBattI = (vi*100)+vd;

    if(vBattI > 900 && vBattI < 1700){
        meanqueue_offer(vBattMean, vBattI);
    }

    char buffer[12];
    float vBatt = meanqueue_get_value(vBattMean)/100.0;
    sprintf(buffer,"%.2fv", vBatt);
    lv_label_set_text(ui_voltValue, buffer);

    int bg_color = STATUS_NORMAL;

    if(vBatt <= 12){
        bg_color = STATUS_CRITICAL;
    } else if(vBatt > 12 && vBatt <= 13.2){
        bg_color = STATUS_WARNING;
    }
    lv_obj_set_style_text_color(ui_voltValue, lv_color_hex(bg_color), LV_PART_MAIN | LV_STATE_DEFAULT);    
}

static void handleGetExposure(){
    reply = (redisReply*)redisCommand(context, "GET %s", "rClipH");
    if (!reply || context->err || reply->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }

    int rClipH = atoi(reply->str);
    freeReplyObject(reply);

    reply = (redisReply*)redisCommand(context, "GET %s", "gClipH");
    if (!reply || context->err || reply->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }

    int gClipH = (atoi(reply->str))/2;
    freeReplyObject(reply);

    reply = (redisReply*)redisCommand(context, "GET %s", "bClipH");
    if (!reply || context->err || reply->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }

    int bClipH = atoi(reply->str);
    freeReplyObject(reply);

    reply = (redisReply*)redisCommand(context, "GET %s", "rClipS");
    if (!reply || context->err || reply->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }

    int rClipS = atoi(reply->str);
    freeReplyObject(reply);

    reply = (redisReply*)redisCommand(context, "GET %s", "gClipS");
    if (!reply || context->err || reply->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }

    int gClipS = (atoi(reply->str))/2;
    freeReplyObject(reply);

    reply = (redisReply*)redisCommand(context, "GET %s", "bClipS");
    if (!reply || context->err || reply->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }

    int bClipS = atoi(reply->str);
    freeReplyObject(reply);

    reply = (redisReply*)redisCommand(context, "GET %s", "width");
    if (!reply || context->err || reply->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }
    int width = atoi(reply->str);
    freeReplyObject(reply);

    reply = (redisReply*)redisCommand(context, "GET %s", "height");
    if (!reply || context->err || reply->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }
    int height = atoi(reply->str);
    freeReplyObject(reply);

    int allpx = width*height;

    int rMax = (allpx / 4)*0.02;
    int gMax = (allpx / 2)*0.02;
    int bMax = (allpx / 4)*0.02;

    int rMaxGP = (allpx / 4)*0.25;
    int gMaxGP = (allpx / 2)*0.25;
    int bMaxGP = (allpx / 4)*0.25;

    lv_bar_set_range(ui_rGoalPost, (rMaxGP*-1), rMaxGP);
    lv_bar_set_value(ui_rGoalPost, rClipH, LV_ANIM_OFF);
    lv_bar_set_start_value(ui_rGoalPost, (rClipS*-1), LV_ANIM_OFF);

    lv_bar_set_range(ui_gGoalPost, (gMaxGP*-1), gMaxGP);
    lv_bar_set_value(ui_gGoalPost, gClipH, LV_ANIM_OFF);
    lv_bar_set_start_value(ui_gGoalPost, (gClipS*-1), LV_ANIM_OFF);

    lv_bar_set_range(ui_bGoalPost, (bMaxGP*-1), bMaxGP);
    lv_bar_set_value(ui_bGoalPost, bClipH, LV_ANIM_OFF);
    lv_bar_set_start_value(ui_bGoalPost, (bClipS*-1), LV_ANIM_OFF);

    if(rClipH > rMax){
        lv_obj_clear_state(ui_rClipH, LV_STATE_DISABLED); 
    } else {
        lv_obj_add_state(ui_rClipH, LV_STATE_DISABLED); 
    }

    if(rClipS > rMax){
        lv_obj_clear_state(ui_rClipS, LV_STATE_DISABLED); 
    } else {
        lv_obj_add_state(ui_rClipS, LV_STATE_DISABLED); 
    }

    if(gClipH > gMax){
        lv_obj_clear_state(ui_gClipH, LV_STATE_DISABLED); 
    } else {
        lv_obj_add_state(ui_gClipH, LV_STATE_DISABLED); 
    }

    if(gClipS > gMax){
        lv_obj_clear_state(ui_gClipS, LV_STATE_DISABLED); 
    } else {
        lv_obj_add_state(ui_gClipS, LV_STATE_DISABLED); 
    }

    if(bClipH > bMax){
        lv_obj_clear_state(ui_bClipH, LV_STATE_DISABLED); 
    } else {
        lv_obj_add_state(ui_bClipH, LV_STATE_DISABLED); 
    }

    if(bClipS > bMax){
        lv_obj_clear_state(ui_bClipS, LV_STATE_DISABLED); 
    } else {
        lv_obj_add_state(ui_bClipS, LV_STATE_DISABLED); 
    }

    // LV_LOG_USER("%d %d %d", rClipS, gClipS, bClipS);
}


static int getEvdevNum(){
    int devNum = -1;
    FILE *f = popen("grep -E 'Handlers|EV=' /proc/bus/input/devices | grep -B1 'EV=b' | grep -Eo 'event[0-9]+' | grep -Eo '[0-9]+' | tr -d '\n'", "r");
    char buffer[16];
    fgets(buffer, 16, f);
    devNum = atoi(buffer);
    pclose(f);
    return devNum;
}

int main(void)
{
    /*LittlevGL init*/
    lv_init();

    /*Linux frame buffer device init*/
    fbdev_init();

    if(!pcf8574Setup(&i2cnode,I2C_PIN_BASE, I2C_DEV_ADR)){
        LV_LOG_WARN("Failed to connect to i2c adapter!");
    }

    if(!pwrSetup(&pwrnode,I2C_POWER_ADR)){
        LV_LOG_WARN("Failed to connect to power i2c adapter!");
    }

    redis_init();

    vBattMean = meanqueue_new(16);

    /*A small buffer for LittlevGL to draw the screen's content*/
    static lv_color_t buf[DISP_BUF_SIZE];
    static lv_color_t buf2[DISP_BUF_SIZE];

    /*Initialize a descriptor for the buffer*/
    static lv_disp_draw_buf_t disp_buf;
    lv_disp_draw_buf_init(&disp_buf, buf, buf2, DISP_BUF_SIZE);

    /*Initialize and register a display driver*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf   = &disp_buf;
    disp_drv.flush_cb   = fbdev_flush;
    disp_drv.hor_res    = DISPLAY_WIDTH;
    disp_drv.ver_res    = DISPLAY_HEIGHT;
    lv_disp_drv_register(&disp_drv);

    evdev_init();
    int evdev_num = getEvdevNum();
    if(evdev_num > -1){
        char evdev_name[128];
        const char *evroot = "/dev/input/event"; 
        snprintf(evdev_name, 128, "%s%d\0", evroot, evdev_num);
        LV_LOG_USER(evdev_name);
        evdev_set_file(evdev_name);
    }

    static lv_indev_drv_t indev_drv_1;
    lv_indev_drv_init(&indev_drv_1); /*Basic initialization*/
    indev_drv_1.type = LV_INDEV_TYPE_POINTER;

    /*This function will be called periodically (by the library) to get the mouse position and state*/
    indev_drv_1.read_cb = evdev_read;
    lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv_1);

    ui_init();
    init_data();

    lv_bar_set_start_value(ui_cpuBar, 0, LV_ANIM_ON);
    lv_bar_set_start_value(ui_memBar, 0, LV_ANIM_ON);
    lv_bar_set_start_value(ui_ctempBar, 0, LV_ANIM_ON);
    
    lv_label_set_text(ui_settingsLockLabel, "\xEF\x82\x9C");
    lv_label_set_text(ui_clipBrowserLabel, LV_SYMBOL_LIST);
    lv_label_set_text(ui_settingsLabel, LV_SYMBOL_SETTINGS);
    lv_label_set_text(ui_storageLabel, LV_SYMBOL_USB);
    lv_label_set_text(ui_exitLabel, LV_SYMBOL_NEW_LINE);
    lv_label_set_text(ui_exitLabel1, LV_SYMBOL_NEW_LINE);

    lv_label_set_text(ui_sIconLabel, LV_SYMBOL_SETTINGS);
    lv_label_set_text(ui_cbIconLabel, LV_SYMBOL_LIST);

    lv_obj_set_style_anim_time(ui_cpuBar, 1000, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_anim_time(ui_memBar, 1000, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_anim_time(ui_ctempBar, 1000, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_anim_time(ui_storageBar, 1000, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_recButton, ui_event_recButton, LV_EVENT_ALL, &cplvdata);
    lv_obj_add_event_cb(ui_liveStats, ui_event_liveStats, LV_EVENT_ALL, &cplvdata);
    lv_obj_add_event_cb(ui_Liveview, ui_event_Liveview, LV_EVENT_ALL, &cplvdata);
    lv_obj_add_event_cb(ui_Settings, ui_event_Settings, LV_EVENT_ALL, &cplvdata);
    lv_obj_add_event_cb(ui_viewfinder, ui_event_viewfinder, LV_EVENT_ALL, &cplvdata);
    lv_obj_add_event_cb(ui_settingsLockButton, ui_event_settingsLockButton, LV_EVENT_ALL, &cplvdata);
    lv_obj_add_event_cb(ui_ClipBrowser, ui_event_ClipBrowser, LV_EVENT_ALL, &cplvdata);

    lv_obj_add_event_cb(ui_shutterControl, ui_event_shutterControl, LV_EVENT_ALL, &cplvdata);
    lv_obj_add_event_cb(ui_isoControl, ui_event_isoControl, LV_EVENT_ALL, &cplvdata);
    lv_obj_add_event_cb(ui_whiteBalanceControl, ui_event_whiteBalanceControl, LV_EVENT_ALL, &cplvdata);
    lv_obj_add_event_cb(ui_frameRateControl, ui_event_frameRateControl, LV_EVENT_ALL, &cplvdata);

    clipList = lv_list_create(ui_ClipBrowser);
    lv_obj_set_x(clipList, 0);
    lv_obj_set_y(clipList, 0);
    lv_obj_set_align(clipList, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_size(clipList, LV_PCT(100), LV_PCT(85));


    // ADD THIS YO UI.C LATER!!
    lv_obj_set_style_text_color(ui_isoControl, lv_color_hex(0x808080), LV_PART_SELECTED | LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui_isoControl, 255, LV_PART_SELECTED | LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui_isoControl, lv_color_hex(0x52515B), LV_PART_SELECTED | LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui_isoControl, 255, LV_PART_SELECTED | LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui_isoControl, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui_isoControl, 255, LV_PART_MAIN | LV_STATE_DISABLED);

    lv_obj_set_style_text_color(ui_shutterControl, lv_color_hex(0x808080), LV_PART_SELECTED | LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui_shutterControl, 255, LV_PART_SELECTED | LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui_shutterControl, lv_color_hex(0x52515B), LV_PART_SELECTED | LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui_shutterControl, 255, LV_PART_SELECTED | LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui_shutterControl, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui_shutterControl, 255, LV_PART_MAIN | LV_STATE_DISABLED);

    lv_obj_set_style_text_color(ui_frameRateControl, lv_color_hex(0x808080), LV_PART_SELECTED | LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui_frameRateControl, 255, LV_PART_SELECTED | LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui_frameRateControl, lv_color_hex(0x52515B), LV_PART_SELECTED | LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui_frameRateControl, 255, LV_PART_SELECTED | LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui_frameRateControl, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui_frameRateControl, 255, LV_PART_MAIN | LV_STATE_DISABLED);
    // ADD THIS YO UI.C LATER!!
    
    /*Handle LitlevGL tasks (tickless mode)*/
    while(1) {

        uint32_t currentMillis = custom_tick_get();

        if(currentMillis - timer > SYSTATS_INTERVAL_MS) {
            timer = currentMillis;
            get_cpu_util();   
            get_cpu_temp();
            get_mem_util();
            get_disk_stats();
        }

        if(currentMillis - timer2 > 250) {
            timer2 = currentMillis;
            handleGetBuffers();
            bufferStatus();
            handleBatteryStatus();
            handleGetExposure();
        }

        if(!cplvdata.stateSet){
            cplvdata.stateSet = 1;
            stateSync(context, reply);
        }

        handlePwrNode();
        redisSync(context, reply);
        handleLockControls();
        handleUpdateControls();
        handleCompressionSwitch();
        handleClipLoad();
        handleResolution();
        handleRecTrigger();
        handleLiveView();
        handleGetFrames();
        handleZoom();

        frames_to_timecode(cpdata.frames, cpdata.framerate, cplvdata.tc_on);
        lv_timer_handler();
        usleep(MAIN_THREAD_INTERVAL_US);
    }

    return 0;
}

/*Set in lv_conf.h as `LV_TICK_CUSTOM_SYS_TIME_EXPR`*/
uint32_t custom_tick_get(void)
{
    static uint64_t start_ms = 0;
    if(start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}
