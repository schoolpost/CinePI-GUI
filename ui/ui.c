// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: LIveView2

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
void ui_event_Liveview(lv_event_t * e);
lv_obj_t * ui_Liveview;
lv_obj_t * ui_sysStats;
lv_obj_t * ui_cpuBar;
lv_obj_t * ui_cpuLabel;
lv_obj_t * ui_memBar;
lv_obj_t * ui_memLabel;
lv_obj_t * ui_ctempBar;
lv_obj_t * ui_ctempValue;
lv_obj_t * ui_ctempLabel;

lv_obj_t * ui_voltLabel;
lv_obj_t * ui_voltValue;
lv_obj_t * ui_cpuValue;

lv_obj_t * ui_TrafficLights;
lv_obj_t * ui_rClip;
lv_obj_t * ui_gClip;
lv_obj_t * ui_bClip;

void ui_event_recButton(lv_event_t * e);
lv_obj_t * ui_recButton;
void ui_event_liveStats(lv_event_t * e);
lv_obj_t * ui_liveStats;
lv_obj_t * ui_storageBar;
lv_obj_t * ui_timecode;
lv_obj_t * ui_formatLabel;
lv_obj_t * ui_storageLabel;
lv_obj_t * ui_Spinner1;
void ui_event_viewfinder(lv_event_t * e);
lv_obj_t * ui_viewfinder;
lv_obj_t * ui_Panel3;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_actionPanel;

lv_obj_t * ui_exposurePanel;
lv_obj_t * ui_hTrafficLights;
lv_obj_t * ui_rClipH;
lv_obj_t * ui_gClipH;
lv_obj_t * ui_bClipH;
lv_obj_t * ui_sTrafficLights;
lv_obj_t * ui_rClipS;
lv_obj_t * ui_gClipS;
lv_obj_t * ui_bClipS;
lv_obj_t * ui_goalPosts;
lv_obj_t * ui_rGoalPost;
lv_obj_t * ui_gGoalPost;
lv_obj_t * ui_bGoalPost;

void ui_event_settingsLockButton(lv_event_t * e);
lv_obj_t * ui_settingsLockButton;
lv_obj_t * ui_settingsLockLabel;
void ui_event_clipBrowserButton(lv_event_t * e);
lv_obj_t * ui_clipBrowserButton;
lv_obj_t * ui_clipBrowserLabel;
void ui_event_settingsButton(lv_event_t * e);
lv_obj_t * ui_settingsButton;
lv_obj_t * ui_settingsLabel;
lv_obj_t * ui_cameraSettings;
void ui_event_frameRateControl(lv_event_t * e);
lv_obj_t * ui_frameRateControl;
void ui_event_isoControl(lv_event_t * e);
lv_obj_t * ui_isoControl;
void ui_event_shutterControl(lv_event_t * e);
lv_obj_t * ui_shutterControl;
void ui_event_whiteBalanceControl(lv_event_t * e);
lv_obj_t * ui_whiteBalanceControl;
void ui_event_ClipBrowser(lv_event_t * e);
lv_obj_t * ui_ClipBrowser;
lv_obj_t * ui_clipbrowserPageTitle;
lv_obj_t * ui_cbActionPanel;
void ui_event_exitButton(lv_event_t * e);
lv_obj_t * ui_exitButton;
lv_obj_t * ui_exitLabel;
lv_obj_t * ui_cbIconPanel;
void ui_event_cbIconButton(lv_event_t * e);
lv_obj_t * ui_cbIconButton;
lv_obj_t * ui_cbIconLabel;
void ui_event_Settings(lv_event_t * e);
lv_obj_t * ui_Settings;
lv_obj_t * ui_settingsPageTitle;
lv_obj_t * ui_sActionPanel;
void ui_event_exitButton1(lv_event_t * e);
lv_obj_t * ui_exitButton1;
lv_obj_t * ui_exitLabel1;
lv_obj_t * ui_sIconPanel;
void ui_event_sIconButton(lv_event_t * e);
lv_obj_t * ui_sIconButton;
lv_obj_t * ui_sIconLabel;
lv_obj_t * ui_settingsPanel;
lv_obj_t * ui_mediaLabel;
void ui_event_ejectMediaButton(lv_event_t * e);
lv_obj_t * ui_ejectMediaButton;
lv_obj_t * ui_ejetcMediaLabel;
void ui_event_formatMediaButton(lv_event_t * e);
lv_obj_t * ui_formatMediaButton;
lv_obj_t * ui_formatMediaLabel;
lv_obj_t * ui_dropdownResolution;
lv_obj_t * ui_dropdownCompression;
lv_obj_t * ui_resolutionLabel;
lv_obj_t * ui_compressionLabel;
lv_obj_t * ui_shutdownButton;
lv_obj_t * ui_shutdownButtonLabel;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Liveview(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_UNLOAD_START) {
        disableLv(e);
    }
}
void ui_event_recButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        recordTigger(e);
    }
}
void ui_event_liveStats(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        changeTc(e);
    }
}
void ui_event_viewfinder(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_TOP) {
        lvZoomControl(e, 1);
    } else if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
        lvZoomControl(e, -1);
    } else if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        lv_obj_add_flag(ui_actionPanel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_exposurePanel, LV_OBJ_FLAG_HIDDEN);
    } else if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_obj_add_flag(ui_exposurePanel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_actionPanel, LV_OBJ_FLAG_HIDDEN);
    }
}

void ui_event_settingsLockButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        lockSettings(e);
    }
}
void ui_event_clipBrowserButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_ClipBrowser, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0);
    }
}
void ui_event_settingsButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0);
    }
}
void ui_event_frameRateControl(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        updateFps(e);
    }
}
void ui_event_isoControl(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        updateIso(e);
    }
}
void ui_event_shutterControl(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        updateShutter(e);
    }
}
void ui_event_whiteBalanceControl(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        updateWhitebalance(e);
    }
}
void ui_event_ClipBrowser(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_UNLOAD_START) {
        enableLv(e);
    }
    if(event_code == LV_EVENT_SCREEN_LOAD_START) {
        clipBrowserLoad(e);
    }
}
void ui_event_exitButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Liveview, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0);
    }
}
void ui_event_cbIconButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Liveview, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0);
    }
}
void ui_event_Settings(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_UNLOAD_START) {
        enableLv(e);
    }
}
void ui_event_exitButton1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Liveview, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0);
    }
}
void ui_event_sIconButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Liveview, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0);
    }
}
void ui_event_ejectMediaButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        clearSysCache(e);
    }
}
void ui_event_formatMediaButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        formatMedia(e);
    }
}
void ui_event_shutdownButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        manualShutdown(e);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Liveview_screen_init(void)
{
    ui_Liveview = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Liveview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_text_align(ui_Liveview, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Liveview, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_sysStats = lv_obj_create(ui_Liveview);
    lv_obj_set_width(ui_sysStats, 160);
    lv_obj_set_height(ui_sysStats, 97);
    lv_obj_set_x(ui_sysStats, -65);
    lv_obj_set_y(ui_sysStats, 10);
    lv_obj_set_align(ui_sysStats, LV_ALIGN_TOP_RIGHT);
    lv_obj_clear_flag(ui_sysStats, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_sysStats, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_sysStats, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_sysStats, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_sysStats, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_sysStats, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_sysStats, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_sysStats, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_sysStats, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_sysStats, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_cpuBar = lv_bar_create(ui_sysStats);
    lv_obj_set_width(ui_cpuBar, 110);
    lv_obj_set_height(ui_cpuBar, 20);
    lv_obj_set_x(ui_cpuBar, 0);
    lv_obj_set_y(ui_cpuBar, -36);
    lv_obj_set_align(ui_cpuBar, LV_ALIGN_RIGHT_MID);
    lv_obj_set_style_radius(ui_cpuBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_cpuBar, LV_OBJ_FLAG_HIDDEN); 

    lv_obj_set_style_radius(ui_cpuBar, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cpuBar, lv_color_hex(0xFFC449), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cpuBar, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_cpuLabel = lv_label_create(ui_sysStats);
    lv_obj_set_width(ui_cpuLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_cpuLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_cpuLabel, 36);
    lv_obj_set_y(ui_cpuLabel, -36);
    lv_obj_set_align(ui_cpuLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_cpuLabel, "C");
    lv_obj_set_style_text_font(ui_cpuLabel, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_cpuValue = lv_label_create(ui_sysStats);
    lv_obj_set_width(ui_cpuValue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_cpuValue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_cpuValue, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_cpuValue, "");
    lv_obj_set_x(ui_cpuValue, 54);
    lv_obj_set_y(ui_cpuValue, -36);
    lv_obj_set_style_text_opa(ui_cpuValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_cpuValue, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_cpuValue, LV_BLEND_MODE_ADDITIVE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_memBar = lv_bar_create(ui_sysStats);
    lv_obj_set_width(ui_memBar, 110);
    lv_obj_set_height(ui_memBar, 20);
    lv_obj_set_x(ui_memBar, 0);
    lv_obj_set_y(ui_memBar, -9);
    lv_obj_add_flag(ui_memBar, LV_OBJ_FLAG_HIDDEN); 
    lv_obj_set_align(ui_memBar, LV_ALIGN_RIGHT_MID);
    lv_obj_set_style_radius(ui_memBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_memBar, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_memBar, lv_color_hex(0xFF4848), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_memBar, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_memLabel = lv_label_create(ui_sysStats);
    lv_obj_set_width(ui_memLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_memLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_memLabel, 34);
    lv_obj_set_y(ui_memLabel, -9);
    lv_obj_add_flag(ui_memLabel, LV_OBJ_FLAG_HIDDEN); 
    lv_obj_set_align(ui_memLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_memLabel, "M");
    lv_obj_set_style_text_font(ui_memLabel, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_voltLabel = lv_label_create(ui_sysStats);
    lv_obj_set_width(ui_voltLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_voltLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_voltLabel, 36);
    lv_obj_set_y(ui_voltLabel, -9);
    lv_obj_set_align(ui_voltLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_voltLabel, "V");
    lv_obj_set_style_text_font(ui_voltLabel, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_voltValue = lv_label_create(ui_sysStats);
    lv_obj_set_width(ui_voltValue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_voltValue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_voltValue, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_voltValue, "");
    lv_obj_set_x(ui_voltValue, 54);
    lv_obj_set_y(ui_voltValue, -9);
    lv_obj_set_style_text_opa(ui_voltValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_voltValue, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_voltValue, LV_BLEND_MODE_ADDITIVE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ctempBar = lv_bar_create(ui_sysStats);
    lv_obj_set_width(ui_ctempBar, 110);
    lv_obj_set_height(ui_ctempBar, 20);
    lv_obj_set_x(ui_ctempBar, 0);
    lv_obj_set_y(ui_ctempBar, 18);
    lv_obj_set_align(ui_ctempBar, LV_ALIGN_RIGHT_MID);
    lv_obj_set_style_radius(ui_ctempBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_ctempBar, LV_OBJ_FLAG_HIDDEN); 
    lv_obj_set_style_radius(ui_ctempBar, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ctempBar, lv_color_hex(0x4AFF73), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ctempBar, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_ctempValue = lv_label_create(ui_sysStats);
    lv_obj_set_width(ui_ctempValue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ctempValue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ctempValue, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ctempValue, "");
    lv_obj_set_x(ui_ctempValue, 54);
    lv_obj_set_y(ui_ctempValue, 18);
    lv_obj_set_style_text_color(ui_ctempValue, lv_color_hex(0xFF8500), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ctempValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ctempValue, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_ctempValue, LV_BLEND_MODE_ADDITIVE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ctempLabel = lv_label_create(ui_sysStats);
    lv_obj_set_width(ui_ctempLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ctempLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ctempLabel, 36);
    lv_obj_set_y(ui_ctempLabel, 18);
    lv_obj_set_align(ui_ctempLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ctempLabel, "T");
    lv_obj_set_style_text_font(ui_ctempLabel, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_recButton = lv_btn_create(ui_Liveview);
    lv_obj_set_width(ui_recButton, 77);
    lv_obj_set_height(ui_recButton, 77);
    lv_obj_set_x(ui_recButton, -10);
    lv_obj_set_y(ui_recButton, 10);
    lv_obj_set_align(ui_recButton, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_recButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_recButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_recButton, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_recButton, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_recButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_recButton, lv_color_hex(0x860000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_recButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_recButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_recButton, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_liveStats = lv_obj_create(ui_Liveview);
    lv_obj_set_width(ui_liveStats, 260);
    lv_obj_set_height(ui_liveStats, 97);
    lv_obj_set_align(ui_liveStats, LV_ALIGN_TOP_MID);
    lv_obj_add_state(ui_liveStats, LV_STATE_FOCUSED);       /// States
    lv_obj_clear_flag(ui_liveStats, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_liveStats, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_liveStats, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_liveStats, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_liveStats, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_liveStats, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_liveStats, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_liveStats, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_storageBar = lv_bar_create(ui_liveStats);
    lv_bar_set_range(ui_storageBar, 0, 448);
    lv_obj_set_width(ui_storageBar, 112);
    lv_obj_set_height(ui_storageBar, 14);
    lv_obj_set_x(ui_storageBar, 0);
    lv_obj_set_y(ui_storageBar, -10);
    lv_obj_set_align(ui_storageBar, LV_ALIGN_RIGHT_MID);
    lv_obj_set_style_radius(ui_storageBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_storageBar, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_storageBar, lv_color_hex(0x4AFF73), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_storageBar, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_timecode = lv_label_create(ui_liveStats);
    lv_obj_set_width(ui_timecode, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_timecode, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_timecode, 0);
    lv_obj_set_y(ui_timecode, 2);
    lv_obj_set_align(ui_timecode, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_timecode, "00:00:00:00");
    lv_obj_set_style_text_font(ui_timecode, &ui_font_MonoFont, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_formatLabel = lv_label_create(ui_liveStats);
    lv_obj_set_width(ui_formatLabel, lv_pct(100));
    lv_obj_set_height(ui_formatLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_formatLabel, 0);
    lv_obj_set_y(ui_formatLabel, 8);
    lv_obj_set_align(ui_formatLabel, LV_ALIGN_TOP_MID);
    lv_label_set_long_mode(ui_formatLabel, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_formatLabel, "");
    lv_obj_set_style_text_color(ui_formatLabel, lv_color_hex(0x4AFF73), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_formatLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui_formatLabel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_formatLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_formatLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_formatLabel, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_storageLabel = lv_label_create(ui_liveStats);
    lv_obj_set_width(ui_storageLabel, lv_pct(100));
    lv_obj_set_height(ui_storageLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_storageLabel, 0);
    lv_obj_set_y(ui_storageLabel, -10);
    lv_obj_set_align(ui_storageLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_storageLabel, "");
    lv_obj_set_style_text_color(ui_storageLabel, lv_color_hex(0x4AFF73), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_storageLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui_storageLabel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_storageLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_storageLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_storageLabel, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Spinner1 = lv_spinner_create(ui_liveStats, 1000, 90);
    // lv_obj_set_width(ui_Spinner1, 14);
    // lv_obj_set_height(ui_Spinner1, 14);
    // lv_obj_set_x(ui_Spinner1, 0);
    // lv_obj_set_y(ui_Spinner1, -10);
    // lv_obj_set_align(ui_Spinner1, LV_ALIGN_CENTER);
    // lv_obj_add_flag(ui_Spinner1, LV_OBJ_FLAG_HIDDEN);     /// Flags
    // lv_obj_clear_flag(ui_Spinner1, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    // lv_obj_set_style_arc_width(ui_Spinner1, 4, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_viewfinder = lv_obj_create(ui_Liveview);
    lv_obj_set_width(ui_viewfinder, 720);
    lv_obj_set_height(ui_viewfinder, 526);
    lv_obj_set_align(ui_viewfinder, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_viewfinder, LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_scrollbar_mode(ui_viewfinder, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_radius(ui_viewfinder, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_viewfinder, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_viewfinder, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_viewfinder, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_viewfinder, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_viewfinder, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_viewfinder, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_viewfinder, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_viewfinder, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_viewfinder, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_exposurePanel = lv_obj_create(ui_Liveview);
    lv_obj_set_width(ui_exposurePanel, 230);
    lv_obj_set_height(ui_exposurePanel, 97);
    lv_obj_clear_flag(ui_exposurePanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_exposurePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_exposurePanel, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_exposurePanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_exposurePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_exposurePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_exposurePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_exposurePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_exposurePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_hTrafficLights = lv_obj_create(ui_exposurePanel);
    lv_obj_set_width(ui_hTrafficLights, 60);
    lv_obj_set_height(ui_hTrafficLights, 120);
    lv_obj_set_x(ui_hTrafficLights, 0);
    lv_obj_set_y(ui_hTrafficLights, -12);
    lv_obj_set_align(ui_hTrafficLights, LV_ALIGN_TOP_RIGHT);
    lv_obj_clear_flag(ui_hTrafficLights, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_hTrafficLights, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_hTrafficLights, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_hTrafficLights, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_rClipH = lv_btn_create(ui_hTrafficLights);
    lv_obj_set_width(ui_rClipH, 20);
    lv_obj_set_height(ui_rClipH, 20);
    lv_obj_set_align(ui_rClipH, LV_ALIGN_TOP_MID);
    lv_obj_add_state(ui_rClipH, LV_STATE_DISABLED);       /// States
    lv_obj_add_flag(ui_rClipH, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_rClipH, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_radius(ui_rClipH, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_rClipH, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_rClipH, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_rClipH, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui_rClipH, 255, LV_PART_MAIN | LV_STATE_DISABLED);

    ui_gClipH = lv_btn_create(ui_hTrafficLights);
    lv_obj_set_width(ui_gClipH, 20);
    lv_obj_set_height(ui_gClipH, 20);
    lv_obj_set_align(ui_gClipH, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_gClipH, LV_STATE_DISABLED);       /// States
    lv_obj_add_flag(ui_gClipH, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_gClipH, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_radius(ui_gClipH, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_gClipH, lv_color_hex(0x00FF00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_gClipH, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_gClipH, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui_gClipH, 255, LV_PART_MAIN | LV_STATE_DISABLED);

    ui_bClipH = lv_btn_create(ui_hTrafficLights);
    lv_obj_set_width(ui_bClipH, 20);
    lv_obj_set_height(ui_bClipH, 20);
    lv_obj_set_align(ui_bClipH, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_state(ui_bClipH, LV_STATE_DISABLED);       /// States
    lv_obj_add_flag(ui_bClipH, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_bClipH, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_radius(ui_bClipH, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bClipH, lv_color_hex(0x0000FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bClipH, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bClipH, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui_bClipH, 255, LV_PART_MAIN | LV_STATE_DISABLED);

    ui_sTrafficLights = lv_obj_create(ui_exposurePanel);
    lv_obj_set_width(ui_sTrafficLights, 60);
    lv_obj_set_height(ui_sTrafficLights, 120);
    lv_obj_set_x(ui_sTrafficLights, 0);
    lv_obj_set_y(ui_sTrafficLights, -12);
    lv_obj_clear_flag(ui_sTrafficLights, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_sTrafficLights, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_sTrafficLights, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_sTrafficLights, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_rClipS = lv_btn_create(ui_sTrafficLights);
    lv_obj_set_width(ui_rClipS, 20);
    lv_obj_set_height(ui_rClipS, 20);
    lv_obj_set_align(ui_rClipS, LV_ALIGN_TOP_MID);
    lv_obj_add_state(ui_rClipS, LV_STATE_DISABLED);       /// States
    lv_obj_add_flag(ui_rClipS, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_rClipS, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_radius(ui_rClipS, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_rClipS, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_rClipS, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_rClipS, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui_rClipS, 255, LV_PART_MAIN | LV_STATE_DISABLED);

    ui_gClipS = lv_btn_create(ui_sTrafficLights);
    lv_obj_set_width(ui_gClipS, 20);
    lv_obj_set_height(ui_gClipS, 20);
    lv_obj_set_align(ui_gClipS, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_gClipS, LV_STATE_DISABLED);       /// States
    lv_obj_add_flag(ui_gClipS, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_gClipS, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_radius(ui_gClipS, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_gClipS, lv_color_hex(0x00FF00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_gClipS, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_gClipS, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui_gClipS, 255, LV_PART_MAIN | LV_STATE_DISABLED);

    ui_bClipS = lv_btn_create(ui_sTrafficLights);
    lv_obj_set_width(ui_bClipS, 20);
    lv_obj_set_height(ui_bClipS, 20);
    lv_obj_set_align(ui_bClipS, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_state(ui_bClipS, LV_STATE_DISABLED);       /// States
    lv_obj_add_flag(ui_bClipS, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_bClipS, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_radius(ui_bClipS, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bClipS, lv_color_hex(0x0000FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bClipS, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bClipS, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui_bClipS, 255, LV_PART_MAIN | LV_STATE_DISABLED);

    ui_goalPosts = lv_obj_create(ui_exposurePanel);
    lv_obj_set_width(ui_goalPosts, 144);
    lv_obj_set_height(ui_goalPosts, 120);
    lv_obj_set_align(ui_goalPosts, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_goalPosts, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_goalPosts, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_goalPosts, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_goalPosts, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_goalPosts, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_goalPosts, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_goalPosts, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_rGoalPost = lv_bar_create(ui_goalPosts);
    lv_bar_set_range(ui_rGoalPost, -100, 100);
    lv_bar_set_value(ui_rGoalPost, 50, LV_ANIM_OFF);
    lv_obj_set_width(ui_rGoalPost, 140);
    lv_obj_set_height(ui_rGoalPost, 20);
    lv_obj_set_align(ui_rGoalPost, LV_ALIGN_TOP_MID);
    lv_bar_set_mode(ui_rGoalPost, LV_BAR_MODE_RANGE);
    // lv_obj_add_state(ui_rGoalPost, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_radius(ui_rGoalPost, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_rGoalPost, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_rGoalPost, lv_color_hex(0xFF0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_rGoalPost, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_rGoalPost, lv_color_hex(0x102C41), LV_PART_INDICATOR | LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui_rGoalPost, 255, LV_PART_INDICATOR | LV_STATE_DISABLED);

    ui_gGoalPost = lv_bar_create(ui_goalPosts);
    lv_bar_set_range(ui_gGoalPost, -100, 100);
    lv_bar_set_value(ui_gGoalPost, 75, LV_ANIM_OFF);
    lv_obj_set_width(ui_gGoalPost, 140);
    lv_obj_set_height(ui_gGoalPost, 20);
    lv_obj_set_align(ui_gGoalPost, LV_ALIGN_CENTER);
    lv_bar_set_mode(ui_gGoalPost, LV_BAR_MODE_RANGE);
    // lv_obj_add_state(ui_gGoalPost, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_radius(ui_gGoalPost, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_gGoalPost, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_gGoalPost, lv_color_hex(0x00FF00), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_gGoalPost, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_gGoalPost, lv_color_hex(0x102C41), LV_PART_INDICATOR | LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui_gGoalPost, 255, LV_PART_INDICATOR | LV_STATE_DISABLED);

    ui_bGoalPost = lv_bar_create(ui_goalPosts);
    lv_bar_set_range(ui_bGoalPost, -100, 100);
    lv_bar_set_value(ui_bGoalPost, 60, LV_ANIM_OFF);
    lv_obj_set_width(ui_bGoalPost, 140);
    lv_obj_set_height(ui_bGoalPost, 20);
    lv_obj_set_align(ui_bGoalPost, LV_ALIGN_BOTTOM_MID);
    lv_bar_set_mode(ui_bGoalPost, LV_BAR_MODE_RANGE);
    // lv_obj_add_state(ui_bGoalPost, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_radius(ui_bGoalPost, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_bGoalPost, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bGoalPost, lv_color_hex(0x0000FF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bGoalPost, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bGoalPost, lv_color_hex(0x102C41), LV_PART_INDICATOR | LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui_bGoalPost, 255, LV_PART_INDICATOR | LV_STATE_DISABLED);


    ui_actionPanel = lv_obj_create(ui_Liveview);
    lv_obj_set_width(ui_actionPanel, 230);
    lv_obj_set_height(ui_actionPanel, 97);
    lv_obj_add_flag(ui_actionPanel, LV_OBJ_FLAG_HIDDEN);    
    lv_obj_clear_flag(ui_actionPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_actionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_actionPanel, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_actionPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_actionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_actionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_actionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_actionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_actionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_settingsLockButton = lv_btn_create(ui_actionPanel);
    lv_obj_set_width(ui_settingsLockButton, 47);
    lv_obj_set_height(ui_settingsLockButton, 77);
    lv_obj_set_x(ui_settingsLockButton, 19);
    lv_obj_set_y(ui_settingsLockButton, 0);
    lv_obj_set_align(ui_settingsLockButton, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_settingsLockButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_settingsLockButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_settingsLockButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_settingsLockButton, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_settingsLockButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_settingsLockLabel = lv_label_create(ui_settingsLockButton);
    lv_obj_set_width(ui_settingsLockLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_settingsLockLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_settingsLockLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_settingsLockLabel, "L");
    lv_obj_set_style_text_color(ui_settingsLockLabel, lv_color_hex(0x4AFF73), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_settingsLockLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_settingsLockLabel, &ui_font_extraSymbols, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_clipBrowserButton = lv_btn_create(ui_actionPanel);
    lv_obj_set_width(ui_clipBrowserButton, 44);
    lv_obj_set_height(ui_clipBrowserButton, 77);
    lv_obj_set_x(ui_clipBrowserButton, 1);
    lv_obj_set_y(ui_clipBrowserButton, 0);
    lv_obj_set_align(ui_clipBrowserButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_clipBrowserButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_clipBrowserButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_clipBrowserButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_clipBrowserButton, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_clipBrowserButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_clipBrowserLabel = lv_label_create(ui_clipBrowserButton);
    lv_obj_set_width(ui_clipBrowserLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_clipBrowserLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_clipBrowserLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_clipBrowserLabel, "P");
    lv_obj_set_style_text_color(ui_clipBrowserLabel, lv_color_hex(0x2095F6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_clipBrowserLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_clipBrowserLabel, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_settingsButton = lv_btn_create(ui_actionPanel);
    lv_obj_set_width(ui_settingsButton, 47);
    lv_obj_set_height(ui_settingsButton, 77);
    lv_obj_set_x(ui_settingsButton, -22);
    lv_obj_set_y(ui_settingsButton, 0);
    lv_obj_set_align(ui_settingsButton, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_settingsButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_settingsButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_settingsButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_settingsButton, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_settingsButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_settingsLabel = lv_label_create(ui_settingsButton);
    lv_obj_set_width(ui_settingsLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_settingsLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_settingsLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_settingsLabel, "S");
    lv_obj_set_style_text_color(ui_settingsLabel, lv_color_hex(0x2095F6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_settingsLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_settingsLabel, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_cameraSettings = lv_obj_create(ui_Liveview);
    lv_obj_set_height(ui_cameraSettings, 97);
    lv_obj_set_width(ui_cameraSettings, lv_pct(100));
    lv_obj_set_align(ui_cameraSettings, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(ui_cameraSettings, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_cameraSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cameraSettings, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cameraSettings, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cameraSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_cameraSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_cameraSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_cameraSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_cameraSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_frameRateControl = lv_roller_create(ui_cameraSettings);
    lv_obj_set_width(ui_frameRateControl, 180);
    lv_obj_set_height(ui_frameRateControl, 97);
    lv_obj_set_x(ui_frameRateControl, -90);
    lv_obj_set_y(ui_frameRateControl, 0);
    lv_obj_set_align(ui_frameRateControl, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_style_radius(ui_frameRateControl, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_frameRateControl, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_frameRateControl, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_frameRateControl, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_frameRateControl, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_isoControl = lv_roller_create(ui_cameraSettings);
    lv_obj_set_width(ui_isoControl, 180);
    lv_obj_set_height(ui_isoControl, 97);
    lv_obj_set_align(ui_isoControl, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_set_style_radius(ui_isoControl, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_isoControl, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_isoControl, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_isoControl, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_isoControl, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_isoControl, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_shutterControl = lv_roller_create(ui_cameraSettings);
    lv_obj_set_width(ui_shutterControl, 180);
    lv_obj_set_height(ui_shutterControl, 97);
    lv_obj_set_x(ui_shutterControl, 90);
    lv_obj_set_y(ui_shutterControl, 0);
    lv_obj_set_align(ui_shutterControl, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_style_radius(ui_shutterControl, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_shutterControl, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_shutterControl, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_shutterControl, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_shutterControl, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_whiteBalanceControl = lv_roller_create(ui_cameraSettings);
    lv_obj_set_width(ui_whiteBalanceControl, 180);
    lv_obj_set_height(ui_whiteBalanceControl, 97);
    lv_obj_set_align(ui_whiteBalanceControl, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_set_style_radius(ui_whiteBalanceControl, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_whiteBalanceControl, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_whiteBalanceControl, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_whiteBalanceControl, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_whiteBalanceControl, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_whiteBalanceControl, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui_whiteBalanceControl, 255, LV_PART_MAIN | LV_STATE_DISABLED);

    lv_obj_set_style_text_color(ui_whiteBalanceControl, lv_color_hex(0x808080), LV_PART_SELECTED | LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui_whiteBalanceControl, 255, LV_PART_SELECTED | LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui_whiteBalanceControl, lv_color_hex(0x52515B), LV_PART_SELECTED | LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui_whiteBalanceControl, 255, LV_PART_SELECTED | LV_STATE_DISABLED);

    lv_obj_add_event_cb(ui_recButton, ui_event_recButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_liveStats, ui_event_liveStats, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_viewfinder, ui_event_viewfinder, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_settingsLockButton, ui_event_settingsLockButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_clipBrowserButton, ui_event_clipBrowserButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_settingsButton, ui_event_settingsButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_frameRateControl, ui_event_frameRateControl, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_isoControl, ui_event_isoControl, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_shutterControl, ui_event_shutterControl, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_whiteBalanceControl, ui_event_whiteBalanceControl, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Liveview, ui_event_Liveview, LV_EVENT_ALL, NULL);

}
void ui_ClipBrowser_screen_init(void)
{
    ui_ClipBrowser = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ClipBrowser, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_text_font(ui_ClipBrowser, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_clipbrowserPageTitle = lv_label_create(ui_ClipBrowser);
    lv_obj_set_width(ui_clipbrowserPageTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_clipbrowserPageTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_clipbrowserPageTitle, 0);
    lv_obj_set_y(ui_clipbrowserPageTitle, 28);
    lv_obj_set_align(ui_clipbrowserPageTitle, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_clipbrowserPageTitle, "CLIP BROWSER");
    lv_obj_set_style_text_font(ui_clipbrowserPageTitle, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_cbActionPanel = lv_obj_create(ui_ClipBrowser);
    lv_obj_set_width(ui_cbActionPanel, 150);
    lv_obj_set_height(ui_cbActionPanel, 97);
    lv_obj_clear_flag(ui_cbActionPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_cbActionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cbActionPanel, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cbActionPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cbActionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_cbActionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_cbActionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_cbActionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_cbActionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_exitButton = lv_btn_create(ui_cbActionPanel);
    lv_obj_set_width(ui_exitButton, 67);
    lv_obj_set_height(ui_exitButton, 77);
    lv_obj_set_x(ui_exitButton, 9);
    lv_obj_set_y(ui_exitButton, 0);
    lv_obj_set_align(ui_exitButton, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_exitButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_exitButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_exitButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_exitButton, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_exitButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_exitLabel = lv_label_create(ui_exitButton);
    lv_obj_set_width(ui_exitLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_exitLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_exitLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_exitLabel, "H");
    lv_obj_set_style_text_color(ui_exitLabel, lv_color_hex(0x2095F6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_exitLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_exitLabel, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_cbIconPanel = lv_obj_create(ui_ClipBrowser);
    lv_obj_set_width(ui_cbIconPanel, 150);
    lv_obj_set_height(ui_cbIconPanel, 97);
    lv_obj_set_align(ui_cbIconPanel, LV_ALIGN_TOP_RIGHT);
    lv_obj_clear_flag(ui_cbIconPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_cbIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cbIconPanel, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cbIconPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cbIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_cbIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_cbIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_cbIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_cbIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_cbIconButton = lv_btn_create(ui_cbIconPanel);
    lv_obj_set_width(ui_cbIconButton, 67);
    lv_obj_set_height(ui_cbIconButton, 77);
    lv_obj_set_x(ui_cbIconButton, -9);
    lv_obj_set_y(ui_cbIconButton, 0);
    lv_obj_set_align(ui_cbIconButton, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_cbIconButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_cbIconButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_cbIconButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cbIconButton, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cbIconButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_cbIconLabel = lv_label_create(ui_cbIconButton);
    lv_obj_set_width(ui_cbIconLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_cbIconLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_cbIconLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_cbIconLabel, "C");
    lv_obj_set_style_text_font(ui_cbIconLabel, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_exitButton, ui_event_exitButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_cbIconButton, ui_event_cbIconButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ClipBrowser, ui_event_ClipBrowser, LV_EVENT_ALL, NULL);

}
void ui_Settings_screen_init(void)
{
    ui_Settings = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Settings, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_text_font(ui_Settings, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_settingsPageTitle = lv_label_create(ui_Settings);
    lv_obj_set_width(ui_settingsPageTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_settingsPageTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_settingsPageTitle, 0);
    lv_obj_set_y(ui_settingsPageTitle, 28);
    lv_obj_set_align(ui_settingsPageTitle, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_settingsPageTitle, "SETTINGS");
    lv_obj_set_style_text_letter_space(ui_settingsPageTitle, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_settingsPageTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_settingsPageTitle, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_sActionPanel = lv_obj_create(ui_Settings);
    lv_obj_set_width(ui_sActionPanel, 230);
    lv_obj_set_height(ui_sActionPanel, 97);
    lv_obj_clear_flag(ui_sActionPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_sActionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_sActionPanel, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_sActionPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_sActionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_sActionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_sActionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_sActionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_sActionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_exitButton1 = lv_btn_create(ui_sActionPanel);
    lv_obj_set_width(ui_exitButton1, 67);
    lv_obj_set_height(ui_exitButton1, 77);
    lv_obj_set_x(ui_exitButton1, 9);
    lv_obj_set_y(ui_exitButton1, 0);
    lv_obj_set_align(ui_exitButton1, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_exitButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_exitButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_exitButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_exitButton1, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_exitButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_exitLabel1 = lv_label_create(ui_exitButton1);
    lv_obj_set_width(ui_exitLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_exitLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_exitLabel1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_exitLabel1, "H");
    lv_obj_set_style_text_color(ui_exitLabel1, lv_color_hex(0x2095F6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_exitLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_exitLabel1, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_sIconPanel = lv_obj_create(ui_Settings);
    lv_obj_set_width(ui_sIconPanel, 230);
    lv_obj_set_height(ui_sIconPanel, 97);
    lv_obj_set_align(ui_sIconPanel, LV_ALIGN_TOP_RIGHT);
    lv_obj_clear_flag(ui_sIconPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_sIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_sIconPanel, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_sIconPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_sIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_sIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_sIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_sIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_sIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_sIconButton = lv_btn_create(ui_sIconPanel);
    lv_obj_set_width(ui_sIconButton, 67);
    lv_obj_set_height(ui_sIconButton, 77);
    lv_obj_set_x(ui_sIconButton, -9);
    lv_obj_set_y(ui_sIconButton, 0);
    lv_obj_set_align(ui_sIconButton, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_sIconButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_sIconButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_sIconButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_sIconButton, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_sIconButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_sIconLabel = lv_label_create(ui_sIconButton);
    lv_obj_set_width(ui_sIconLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_sIconLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_sIconLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_sIconLabel, "S");
    lv_obj_set_style_text_font(ui_sIconLabel, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_settingsPanel = lv_obj_create(ui_Settings);
    lv_obj_set_height(ui_settingsPanel, 623);
    lv_obj_set_width(ui_settingsPanel, lv_pct(100));
    lv_obj_set_align(ui_settingsPanel, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(ui_settingsPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_settingsPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_settingsPanel, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_settingsPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_settingsPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_settingsPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_settingsPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_mediaLabel = lv_label_create(ui_settingsPanel);
    lv_obj_set_width(ui_mediaLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_mediaLabel, LV_SIZE_CONTENT);    /// 1
    lv_label_set_text(ui_mediaLabel, "MEDIA:");

    ui_ejectMediaButton = lv_btn_create(ui_settingsPanel);
    lv_obj_set_height(ui_ejectMediaButton, 50);
    lv_obj_set_width(ui_ejectMediaButton, lv_pct(49));
    lv_obj_set_x(ui_ejectMediaButton, 0);
    lv_obj_set_y(ui_ejectMediaButton, 40);
    lv_obj_add_flag(ui_ejectMediaButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ejectMediaButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ejectMediaButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ejetcMediaLabel = lv_label_create(ui_ejectMediaButton);
    lv_obj_set_width(ui_ejetcMediaLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ejetcMediaLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ejetcMediaLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ejetcMediaLabel, "EJECT");

    ui_formatMediaButton = lv_btn_create(ui_settingsPanel);
    lv_obj_set_height(ui_formatMediaButton, 50);
    lv_obj_set_width(ui_formatMediaButton, lv_pct(49));
    lv_obj_set_x(ui_formatMediaButton, 0);
    lv_obj_set_y(ui_formatMediaButton, 40);
    lv_obj_set_align(ui_formatMediaButton, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_formatMediaButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_formatMediaButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_formatMediaButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_formatMediaButton, lv_color_hex(0xFF4848), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_formatMediaButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_formatMediaLabel = lv_label_create(ui_formatMediaButton);
    lv_obj_set_width(ui_formatMediaLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_formatMediaLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_formatMediaLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_formatMediaLabel, "FORMAT");

    ui_dropdownResolution = lv_dropdown_create(ui_settingsPanel);
    lv_dropdown_set_options(ui_dropdownResolution, "1332x990\n2028x1080\n2028x1520\n4056x3040");
    lv_obj_set_width(ui_dropdownResolution, lv_pct(49));
    lv_obj_set_height(ui_dropdownResolution, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_dropdownResolution, 0);
    lv_obj_set_y(ui_dropdownResolution, 162);
    lv_obj_add_flag(ui_dropdownResolution, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_radius(ui_dropdownResolution, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_dropdownCompression = lv_dropdown_create(ui_settingsPanel);
    lv_dropdown_set_options(ui_dropdownCompression, "None\nLossless");
    lv_obj_set_width(ui_dropdownCompression, lv_pct(49));
    lv_obj_set_height(ui_dropdownCompression, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_dropdownCompression, 0);
    lv_obj_set_y(ui_dropdownCompression, 162);
    lv_obj_set_align(ui_dropdownCompression, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_dropdownCompression, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_radius(ui_dropdownCompression, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_resolutionLabel = lv_label_create(ui_settingsPanel);
    lv_obj_set_width(ui_resolutionLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_resolutionLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_resolutionLabel, 0);
    lv_obj_set_y(ui_resolutionLabel, 120);
    lv_label_set_text(ui_resolutionLabel, "RESOLUTION:");

    ui_compressionLabel = lv_label_create(ui_settingsPanel);
    lv_obj_set_width(ui_compressionLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_compressionLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_compressionLabel, 346);
    lv_obj_set_y(ui_compressionLabel, 120);
    lv_label_set_text(ui_compressionLabel, "COMPRESSION:");

    ui_shutdownButton = lv_btn_create(ui_settingsPanel);
    lv_obj_set_height(ui_shutdownButton, 50);
    lv_obj_set_width(ui_shutdownButton, lv_pct(100));
    lv_obj_set_align(ui_shutdownButton, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_shutdownButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_shutdownButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_shutdownButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_shutdownButton, lv_color_hex(0xFF4848), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_shutdownButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_shutdownButtonLabel = lv_label_create(ui_shutdownButton);
    lv_obj_set_width(ui_shutdownButtonLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_shutdownButtonLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_shutdownButtonLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_shutdownButtonLabel, "SHUTDOWN");

    lv_obj_add_event_cb(ui_exitButton1, ui_event_exitButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_sIconButton, ui_event_sIconButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ejectMediaButton, ui_event_ejectMediaButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_formatMediaButton, ui_event_formatMediaButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_shutdownButton, ui_event_shutdownButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Settings, ui_event_Settings, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Liveview_screen_init();
    ui_ClipBrowser_screen_init();
    ui_Settings_screen_init();
    lv_disp_load_scr(ui_Liveview);
}
