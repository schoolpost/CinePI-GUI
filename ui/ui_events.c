// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: LIveView

#include "ui.h"
#include <stdio.h>

void unmount_disk(){
	system("sudo sync");
	system("sudo umount /media/RAW");

	FILE* file;
	const int max_buffer = 256;
	char buffer[max_buffer];
    file = popen("cat /proc/mounts | grep /media/RAW", "r");
    if(file){
		while(!feof(file)){
			if (fgets(buffer, max_buffer, file) == NULL){
				LV_LOG_USER(buffer);
				system("sudo rmdir /media/RAW");
			} 
		}
		pclose(file);
	}
}

void recordTigger(lv_event_t * e)
{
	if(lv_event_get_user_data(e) != NULL){
		LV_LOG_USER("recordTigger");
		cinepi_lv_t *data = lv_event_get_user_data(e);
		bool doRec = (*data).doRec;
		data->doRec = !doRec;
	}
}

void mySwipeUp(lv_event_t * e)
{
	LV_LOG_USER("Swiped");
}

void manualShutdown(lv_event_t * e){
	LV_LOG_USER("shutdown");
	system("sync; echo 3 | sudo tee /proc/sys/vm/drop_caches");
	system("sudo shutdown now");
}

void formatMedia(lv_event_t * e){
	LV_LOG_USER("Format Media!");
	unmount_disk();
	system("sudo mkfs.ntfs -Q -L A007 /dev/sda2");
}

void clearSysCache(lv_event_t * e)
{
	LV_LOG_USER("Eject Media!");
	unmount_disk();
}

void clipBrowserLoad(lv_event_t * e)
{
	if(lv_event_get_user_data(e) != NULL){
		LV_LOG_USER("load clips!");
		cinepi_lv_t *data = lv_event_get_user_data(e);
		data->loadClips = true;
	}
};


void lockSettings(lv_event_t * e)
{
	if(lv_event_get_user_data(e) != NULL){
		
		cinepi_lv_t *data = lv_event_get_user_data(e);
		bool setLock = (*data).setLock;
		data->setLock = !setLock;
		lv_obj_t * btn = lv_event_get_target(e);
		lv_obj_t * label = lv_obj_get_child(btn, 0);
		if(setLock){
			lv_label_set_text(label, "\xEF\x82\x9C");
			lv_obj_set_style_text_color(label, lv_color_hex(0x4AFF73), LV_PART_MAIN | LV_STATE_DEFAULT);
		} else {
			lv_obj_set_style_text_color(label, lv_color_hex(0xFF4848), LV_PART_MAIN | LV_STATE_DEFAULT);
			lv_label_set_text(label, "\xEF\x80\xA3");
		}
		LV_LOG_USER("settingsLock %d", setLock);
	}
}

void disableLv(lv_event_t * e)
{
	if(lv_event_get_user_data(e) != NULL){
		LV_LOG_USER("disable LV");
		cinepi_lv_t *data = lv_event_get_user_data(e);
		data->lvEn = 0;
	}
}

void enableLv(lv_event_t * e)
{
	if(lv_event_get_user_data(e) != NULL){
		LV_LOG_USER("enable LV");
		cinepi_lv_t *data = lv_event_get_user_data(e);
		data->lvEn = 1;
	}
}

void lvZoomControl(lv_event_t * e, int dir)
{
	if(lv_event_get_user_data(e) != NULL){
		LV_LOG_USER("zoom! %d", dir);
		cinepi_lv_t *data = lv_event_get_user_data(e);
		data->zoomDir = dir;
	}
}


void changeTc(lv_event_t * e)
{
	if(lv_event_get_user_data(e) != NULL){
		LV_LOG_USER("ChangeTC");
		cinepi_lv_t *data = lv_event_get_user_data(e);
		bool tc_on = (*data).tc_on;
		data->tc_on = !tc_on;
	}
}

void updateFps(lv_event_t * e)
{
	if(lv_event_get_user_data(e) != NULL){
		LV_LOG_USER("UpdateFPS");
		cinepi_lv_t *data = lv_event_get_user_data(e);
		data->uFps = 1;
	}
}

void updateIso(lv_event_t * e)
{
	if(lv_event_get_user_data(e) != NULL){
		LV_LOG_USER("UpdateISO");
		cinepi_lv_t *data = lv_event_get_user_data(e);
		data->uIso = 1;
	}
}

void updateShutter(lv_event_t * e)
{
	if(lv_event_get_user_data(e) != NULL){
		LV_LOG_USER("UpdateSHUTTER");
		cinepi_lv_t *data = lv_event_get_user_data(e);
		data->uSh = 1;
	}
}

void updateWhitebalance(lv_event_t * e)
{
	if(lv_event_get_user_data(e) != NULL){
		LV_LOG_USER("UpdateWHITEBALANCE");
		cinepi_lv_t *data = lv_event_get_user_data(e);
		data->uWb = 1;
	}
}

