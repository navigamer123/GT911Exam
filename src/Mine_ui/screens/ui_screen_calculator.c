#include "Mine_ui/ui_main.h"
#include "squerline_ui/ui.h"
void crete_button_whit_labble(lv_obj_t *button_obj, lv_obj_t *lable_obj, lv_obj_t *pannel, int buttonX, int buttonY, int buttonW, int buttonH, const char *text, int textX, int textY, lv_event_cb_t event_cb)
{

    button_obj = lv_btn_create(pannel);
    lv_obj_set_width(button_obj, buttonW);
    lv_obj_set_height(button_obj, buttonH);
    lv_obj_set_x(button_obj, buttonX);
    lv_obj_set_y(button_obj, buttonY);
    lv_obj_set_align(button_obj, LV_ALIGN_CENTER);
    lv_obj_add_flag(button_obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(button_obj, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_add_event_cb(button_obj, event_cb, LV_EVENT_ALL, NULL);
    // back button label
    lable_obj = lv_label_create(button_obj);
    lv_obj_set_width(lable_obj, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(lable_obj, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(lable_obj, textX);
    lv_obj_set_y(lable_obj, textY);
    lv_obj_set_align(lable_obj, LV_ALIGN_CENTER);
    lv_label_set_text(lable_obj, text);
    lv_obj_set_style_text_color(lable_obj, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(lable_obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
}
void ui_Screen_calculator_screen_init_mian(void)
{
    ui_Screen_calculator = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen_calculator, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_img_src(ui_Screen_calculator, &ui_img_1695069766, LV_PART_MAIN | LV_STATE_DEFAULT);
    // back button
    ui_back = lv_btn_create(ui_Screen_calculator);
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

    ui_calculator_panel = lv_obj_create(ui_Screen_calculator);
    lv_obj_set_width(ui_calculator_panel, 352);
    lv_obj_set_height(ui_calculator_panel, 400);
    lv_obj_set_x(ui_calculator_panel, 0);
    lv_obj_set_y(ui_calculator_panel, -30);
    lv_obj_set_align(ui_calculator_panel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_calculator_panel, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_calculator_textbox = lv_textarea_create(ui_calculator_panel);
    lv_obj_set_width(ui_calculator_textbox, 352); /// 1
    lv_obj_set_height(ui_calculator_textbox, 75); /// 1
    lv_obj_set_x(ui_calculator_textbox, 0);
    lv_obj_set_y(ui_calculator_textbox, -125);
    lv_obj_set_align(ui_calculator_textbox, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_calculator_textbox, "");
    lv_obj_set_style_text_color(ui_calculator_textbox, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_calculator_textbox, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    crete_button_whit_labble(ui_calculator_number_7, ui_calculator_number_7_lable, ui_calculator_panel, -126, -50, 50, 50, "7", 0, 0, button7);
    crete_button_whit_labble(ui_calculator_number_8, ui_calculator_number_8_lable, ui_calculator_panel, -126 + 75, -50, 50, 50, "8", 0, 0, button8);
    crete_button_whit_labble(ui_calculator_number_9, ui_calculator_number_9_lable, ui_calculator_panel, -126 + 150, -50, 50, 50, "9", 0, 0, button9);
    crete_button_whit_labble(ui_calculator_number_4, ui_calculator_number_4_lable, ui_calculator_panel, -126, 25, 50, 50, "4", 0, 0, button4);
    crete_button_whit_labble(ui_calculator_number_5, ui_calculator_number_5_lable, ui_calculator_panel, -126 + 75, 25, 50, 50, "5", 0, 0, button5);
    crete_button_whit_labble(ui_calculator_number_6, ui_calculator_number_6_lable, ui_calculator_panel, -126 + 150, 25, 50, 50, "6", 0, 0, button6);
    crete_button_whit_labble(ui_calculator_number_1, ui_calculator_number_1_lable, ui_calculator_panel, -126, 100, 50, 50, "1", 0, 0, button1);
    crete_button_whit_labble(ui_calculator_number_2, ui_calculator_number_2_lable, ui_calculator_panel, -126 + 75, 100, 50, 50, "2", 0, 0, button2);
    crete_button_whit_labble(ui_calculator_number_3, ui_calculator_number_3_lable, ui_calculator_panel, -126 + 150, 100, 50, 50, "3", 0, 0, button3);
    crete_button_whit_labble(ui_calculator_number_0, ui_calculator_number_0_lable, ui_calculator_panel, -126 + 75, 175, 50, 50, "0", 0, 0, button0);
    crete_button_whit_labble(ui_calculator_number_devide, ui_calculator_number_devide_lable, ui_calculator_panel, -126 + 225, -50, 50, 50, "/", 0, 0, devide);
    crete_button_whit_labble(ui_calculator_number_mulltiply, ui_calculator_number_mulltiply_lable, ui_calculator_panel, -126 + 225, 25, 50, 50, "*", 0, 0, multiplecation);
    crete_button_whit_labble(ui_calculator_number_subtraction, ui_calculator_number_subtractio_lable, ui_calculator_panel, -126 + 225, 100, 50, 50, "-", 0, 0, subtraction);
    crete_button_whit_labble(ui_calculator_number_addition, ui_calculator_number_addition_lable, ui_calculator_panel, -126 + 225, 175, 50, 50, "+", 0, 0, adding);
    crete_button_whit_labble(ui_calculator_number_equals, ui_calculator_number_equals_lable, ui_calculator_panel, -126 + 150, 175, 50, 50, "=", 0, 0, calculate);
    crete_button_whit_labble(ui_calculator_number_removeone, ui_calculator_number_removeone_lable, ui_calculator_panel, -126, 175, 50, 50, "<=", 0, 0, removeone);
}