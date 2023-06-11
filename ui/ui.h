// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: LIveView2

#ifndef _LIVEVIEW2_UI_H
#define _LIVEVIEW2_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

void ui_event_Liveview(lv_event_t * e);
extern lv_obj_t * ui_Liveview;
extern lv_obj_t * ui_sysStats;
extern lv_obj_t * ui_cpuBar;
extern lv_obj_t * ui_cpuLabel;
extern lv_obj_t * ui_memBar;
extern lv_obj_t * ui_memLabel;
extern lv_obj_t * ui_ctempBar;
extern lv_obj_t * ui_ctempValue;
extern lv_obj_t * ui_ctempLabel;

extern lv_obj_t * ui_voltLabel;
extern lv_obj_t * ui_voltValue;
extern lv_obj_t * ui_cpuValue;

extern lv_obj_t * ui_TrafficLights;
extern lv_obj_t * ui_rClip;
extern lv_obj_t * ui_gClip;
extern lv_obj_t * ui_bClip;
void ui_event_recButton(lv_event_t * e);
extern lv_obj_t * ui_recButton;
void ui_event_liveStats(lv_event_t * e);
extern lv_obj_t * ui_liveStats;
extern lv_obj_t * ui_storageBar;
extern lv_obj_t * ui_timecode;
extern lv_obj_t * ui_formatLabel;
extern lv_obj_t * ui_storageLabel;
extern lv_obj_t * ui_Spinner1;
void ui_event_viewfinder(lv_event_t * e);
extern lv_obj_t * ui_viewfinder;
extern lv_obj_t * ui_Panel3;
extern lv_obj_t * ui_Panel1;
extern lv_obj_t * ui_actionPanel;

extern lv_obj_t * ui_exposurePanel;
extern lv_obj_t * ui_hTrafficLights;
extern lv_obj_t * ui_rClipH;
extern lv_obj_t * ui_gClipH;
extern lv_obj_t * ui_bClipH;
extern lv_obj_t * ui_sTrafficLights;
extern lv_obj_t * ui_rClipS;
extern lv_obj_t * ui_gClipS;
extern lv_obj_t * ui_bClipS;
extern lv_obj_t * ui_goalPosts;
extern lv_obj_t * ui_rGoalPost;
extern lv_obj_t * ui_gGoalPost;
extern lv_obj_t * ui_bGoalPost;

void ui_event_settingsLockButton(lv_event_t * e);
extern lv_obj_t * ui_settingsLockButton;
extern lv_obj_t * ui_settingsLockLabel;
void ui_event_clipBrowserButton(lv_event_t * e);
extern lv_obj_t * ui_clipBrowserButton;
extern lv_obj_t * ui_clipBrowserLabel;
void ui_event_settingsButton(lv_event_t * e);
extern lv_obj_t * ui_settingsButton;
extern lv_obj_t * ui_settingsLabel;
extern lv_obj_t * ui_cameraSettings;
void ui_event_frameRateControl(lv_event_t * e);
extern lv_obj_t * ui_frameRateControl;
void ui_event_isoControl(lv_event_t * e);
extern lv_obj_t * ui_isoControl;
void ui_event_shutterControl(lv_event_t * e);
extern lv_obj_t * ui_shutterControl;
void ui_event_whiteBalanceControl(lv_event_t * e);
extern lv_obj_t * ui_whiteBalanceControl;
void ui_event_ClipBrowser(lv_event_t * e);
extern lv_obj_t * ui_ClipBrowser;
extern lv_obj_t * ui_clipbrowserPageTitle;
extern lv_obj_t * ui_cbActionPanel;
void ui_event_exitButton(lv_event_t * e);
extern lv_obj_t * ui_exitButton;
extern lv_obj_t * ui_exitLabel;
extern lv_obj_t * ui_cbIconPanel;
void ui_event_cbIconButton(lv_event_t * e);
extern lv_obj_t * ui_cbIconButton;
extern lv_obj_t * ui_cbIconLabel;
void ui_event_Settings(lv_event_t * e);
extern lv_obj_t * ui_Settings;
extern lv_obj_t * ui_settingsPageTitle;
extern lv_obj_t * ui_sActionPanel;
void ui_event_exitButton1(lv_event_t * e);
extern lv_obj_t * ui_exitButton1;
extern lv_obj_t * ui_exitLabel1;
extern lv_obj_t * ui_sIconPanel;
void ui_event_sIconButton(lv_event_t * e);
extern lv_obj_t * ui_sIconButton;
extern lv_obj_t * ui_sIconLabel;
extern lv_obj_t * ui_settingsPanel;
extern lv_obj_t * ui_mediaLabel;
void ui_event_ejectMediaButton(lv_event_t * e);
extern lv_obj_t * ui_ejectMediaButton;
extern lv_obj_t * ui_ejetcMediaLabel;
void ui_event_formatMediaButton(lv_event_t * e);
extern lv_obj_t * ui_formatMediaButton;
extern lv_obj_t * ui_formatMediaLabel;
extern lv_obj_t * ui_dropdownResolution;
extern lv_obj_t * ui_dropdownCompression;
extern lv_obj_t * ui_resolutionLabel;
extern lv_obj_t * ui_compressionLabel;
extern lv_obj_t * ui_shutdownButton;
extern lv_obj_t * ui_shutdownButtonLabel;
void ui_event_shutdownButton(lv_event_t * e);

void disableLv(lv_event_t * e);
void recordTigger(lv_event_t * e);
void changeTc(lv_event_t * e);
// void lvZoomControl(lv_event_t * e);
void lockSettings(lv_event_t * e);
void updateFps(lv_event_t * e);
void updateIso(lv_event_t * e);
void updateShutter(lv_event_t * e);
void updateWhitebalance(lv_event_t * e);
void enableLv(lv_event_t * e);
void clipBrowserLoad(lv_event_t * e);
void enableLv(lv_event_t * e);
void clearSysCache(lv_event_t * e);
void formatMedia(lv_event_t * e);
void manualShutdown(lv_event_t * e);



LV_FONT_DECLARE(ui_font_extraSymbols);
LV_FONT_DECLARE(ui_font_MonoFont);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
