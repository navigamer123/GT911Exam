#include "Mine_ui/ui_main.h"
#include "squerline_ui/ui.h"

lv_obj_t *Reload;
lv_obj_t *Reload_lb;

void ui_Screen1_screen_init_mian(void)
{
    ui_Apps = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Apps, 122);
    lv_obj_set_height(ui_Apps, 85);
    lv_obj_set_x(ui_Apps, -286);
    lv_obj_set_y(ui_Apps, 177);
    lv_obj_set_align(ui_Apps, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Apps, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_Apps, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_Label3 = lv_label_create(ui_Apps);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_Label3, -3);
    lv_obj_set_y(ui_Label3, 1);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "Apps");
    lv_obj_add_event_cb(ui_Apps, app_select, LV_EVENT_ALL, NULL);
    
    Reload= lv_btn_create(ui_Screen2);
    lv_obj_set_width(Reload, 122);
    lv_obj_set_height(Reload, 85);
    lv_obj_set_x(Reload, -286);
    lv_obj_set_y(Reload, 177);
    lv_obj_set_align(Reload, LV_ALIGN_CENTER);
    lv_obj_add_flag(Reload, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(Reload, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    Reload_lb = lv_label_create(Reload);
    lv_obj_set_width(Reload_lb, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(Reload_lb, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(Reload_lb, -3);
    lv_obj_set_y(Reload_lb, 1);
    lv_obj_set_align(Reload_lb, LV_ALIGN_CENTER);
    lv_label_set_text(Reload_lb, "Redresh");
    lv_obj_add_event_cb(Reload_lb, reload_WiFi, LV_EVENT_ALL, NULL);
}