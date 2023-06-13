#include "Mine_ui/ui_main.h"
#include "squerline_ui/ui.h"
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
}