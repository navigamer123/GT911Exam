#include "Mine_ui/ui_main.h"
#include "squerline_ui/ui.h"

void ui_Screen9_screen_init_mian(void)
{
    fileMNG_screan = lv_obj_create(NULL);
    lv_obj_clear_flag(fileMNG_screan, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_img_src(fileMNG_screan, &ui_img_1695069766, LV_PART_MAIN | LV_STATE_DEFAULT);
    // back button
    ui_back = lv_btn_create(fileMNG_screan);
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
    lv_label_set_text(ui_back_label, "back");
    lv_obj_add_event_cb(ui_back, app_select, LV_EVENT_ALL, NULL);
    for (int x = -300; x < 300; x += 50)
    {
        lv_obj_t *listdir;
        lv_btn_create(listdir);
        lv_obj_set_width(ui_back, 50);
        lv_obj_set_height(ui_back, 50);
        lv_obj_set_x(ui_back, x);
        lv_obj_set_y(ui_back, 0);
    }
}