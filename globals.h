#include "ui/ui.h"

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

cinepi_ipc_t cpdata;
cinepi_lv_t cplvdata;
controls_t cpcontrols = {
    {100, 160, 200, 250, 320, 400, 500, 640, 800, 1000, 1250, 1600, 2000},
    {11,22,45,72,90,120,144,172,180,216,270,360},
    {2500, 3200, 4500, 5600, 6500, 8000},
    {1.00, 5.00, 10.00, 15.00, 23.976, 24.00, 25.00, 29.97, 30.00, 36.00, 40.00, 48.00, 50.00, 60.00, 90.00, 96.00, 120.00}
};
button_t pwrButton;

char * cpfifo1 = "/tmp/fifo1";
char * cpfifo2 = "/tmp/fifo2";

int fifofd1;
int fifof2d;


void init_data(){
    pwrButton.state = 1;
    pwrButton.lastState = 1;
    pwrButton.down = false;

    cpdata.framerate = 0;
    cpdata.frames = 0;
    cplvdata.doRec = false;
    cplvdata.tc_on = false; 
    cplvdata.lvEn = 1;
    cplvdata.setLock = false;
    cplvdata.loadClips = false;
    cplvdata.stateSet = 0;

    int *iso = cpcontrols.iso;
    int *wb = cpcontrols.wb;
    int *shutter = cpcontrols.shutter;
    float *fps = cpcontrols.fps;
        
    int arr_size = 0;
    arr_size = NELEMS(cpcontrols.shutter);

    char *buf = "";
    for(int i=0; i<arr_size; i++){
        if(i != arr_size-1){
            asprintf(&buf,"%s%d°\n",buf,shutter[i]);
        }else{
            asprintf(&buf,"%s%d°",buf,shutter[i]);
        }
    }  
    lv_roller_set_options(ui_shutterControl, (const char*)buf, LV_ROLLER_MODE_NORMAL);
    free(buf);

    arr_size = NELEMS(cpcontrols.iso);
    char *buf2 = "";
    for(int i=0; i<arr_size; i++){
        if(i != arr_size-1){
            asprintf(&buf2,"%s%d\n",buf2,iso[i]);
        }else{
            asprintf(&buf2,"%s%d",buf2,iso[i]);
        }
    }  
    lv_roller_set_options(ui_isoControl, (const char*)buf2, LV_ROLLER_MODE_NORMAL);
    free(buf2);

    arr_size = NELEMS(cpcontrols.wb);
    char *buf3 = "";
    for(int i=0; i<arr_size; i++){
        if(i != arr_size-1){
            asprintf(&buf3,"%s%dK\n",buf3,wb[i]);
        }else{
            asprintf(&buf3,"%s%dK",buf3,wb[i]);
        }
    }  
    lv_roller_set_options(ui_whiteBalanceControl, (const char*)buf3, LV_ROLLER_MODE_NORMAL);
    free(buf3);

    arr_size = NELEMS(cpcontrols.fps);
    char *buf4 = "";
    for(int i=0; i<arr_size; i++){
        if(i != arr_size-1){
            asprintf(&buf4,"%s%.2f\n",buf4,fps[i]);
        }else{
            asprintf(&buf4,"%s%.2f",buf4,fps[i]);
        }
    }  
    lv_roller_set_options(ui_frameRateControl, (const char*)buf4, LV_ROLLER_MODE_NORMAL);
    free(buf4);
}

