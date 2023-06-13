#include "Mine_ui/ui_main.h"
#include "squerline_ui/ui.h"
void ui_Screen6_screen_init_mian(void)
{
    ui_Screen6 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen6, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_img_src(ui_Screen6, &ui_img_1695069766, LV_PART_MAIN | LV_STATE_DEFAULT);
    // back button
    ui_back = lv_btn_create(ui_Screen6);
    lv_obj_set_width(ui_back, 122);
    lv_obj_set_height(ui_back, 85);
    lv_obj_set_x(ui_back, -286);
    lv_obj_set_y(ui_back, 177);
    lv_obj_set_align(ui_back, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_back, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_back, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    // back button label
    ui_back_label = lv_label_create(ui_back);
    lv_obj_set_width(ui_back_label, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_back_label, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_back_label, -3);
    lv_obj_set_y(ui_back_label, 1);
    lv_obj_set_align(ui_back_label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_back_label, "Main");
    lv_obj_add_event_cb(ui_back, mainscreen, LV_EVENT_ALL, NULL);
    // lamp button
    ui_hue = lv_btn_create(ui_Screen6);
    lv_obj_set_width(ui_hue, 110);
    lv_obj_set_height(ui_hue, 64);
    lv_obj_set_x(ui_hue, -320);
    lv_obj_set_y(ui_hue, -123);
    lv_obj_set_align(ui_hue, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_hue, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_hue, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    // lamp button label
    ui_hue_label = lv_label_create(ui_hue);
    lv_obj_set_width(ui_hue_label, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_hue_label, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_hue_label, -3);
    lv_obj_set_y(ui_hue_label, 1);
    lv_obj_set_align(ui_hue_label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_hue_label, "hue");
    lv_obj_add_event_cb(ui_hue, lamp_control, LV_EVENT_ALL, NULL);
    //////////////////CALCULATOR/////////////////////////
    ui_calculator_button = lv_btn_create(ui_Screen6);
    lv_obj_set_width(ui_calculator_button, 110);
    lv_obj_set_height(ui_calculator_button, 64);
    lv_obj_set_x(ui_calculator_button, -200);
    lv_obj_set_y(ui_calculator_button, -123);
    lv_obj_set_align(ui_calculator_button, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_calculator_button, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_calculator_button, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    // lamp button label
    ui_calculator_label = lv_label_create(ui_calculator_button);
    lv_obj_set_width(ui_calculator_label, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_calculator_label, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_calculator_label, -3);
    lv_obj_set_y(ui_calculator_label, 1);
    lv_obj_set_align(ui_calculator_label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_calculator_label, "claculator");
    lv_obj_add_event_cb(ui_calculator_button, calcurator, LV_EVENT_ALL, NULL);
    //game
    ui_snake_button = lv_btn_create(ui_Screen6);
    lv_obj_set_width(ui_snake_button, 110);
    lv_obj_set_height(ui_snake_button, 64);
    lv_obj_set_x(ui_snake_button, -80);
    lv_obj_set_y(ui_snake_button, -123);
    lv_obj_set_align(ui_snake_button, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_snake_button, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_snake_button, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    // lamp button label
    ui_snake_label = lv_label_create(ui_snake_button);
    lv_obj_set_width(ui_snake_label, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_snake_label, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_snake_label, -3);
    lv_obj_set_y(ui_snake_label, 1);
    lv_obj_set_align(ui_snake_label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_snake_label, "Snake");
    lv_obj_add_event_cb(ui_snake_button, snakemain, LV_EVENT_ALL, NULL);
}