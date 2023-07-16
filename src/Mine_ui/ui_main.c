// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: Test

#include "ui_main.h"
#include "ui_helpers_main.h"
///////////////////// VARIABLES ////////////////////
lv_obj_t *ui_Apps;
lv_obj_t *ui_Label3;
lv_obj_t *ui_back;
lv_obj_t *ui_back_label;
lv_obj_t *ui_back;
lv_obj_t *ui_back_label;
lv_obj_t *ui_hue;
lv_obj_t *ui_hue_label;
///////////////////// SCREENS ////////////////////
lv_obj_t *ui_Screen6;
lv_obj_t *ui_Screen1;
lv_obj_t *ui_Screen7;
lv_obj_t *ui_Screen_calculator;
lv_obj_t *ui_Screen_snake_game;
//////////////////////////////////////////////////
//////////////////CALCULATOR/////////////////////////
lv_obj_t *ui_calculator_button;
lv_obj_t *ui_calculator_label;
///////////// CALCULATOR KEY BOARD///////////////////
lv_obj_t *ui_calculator_number_1;
lv_obj_t *ui_calculator_number_1_lable;
lv_obj_t *ui_calculator_number_2;
lv_obj_t *ui_calculator_number_2_lable;
lv_obj_t *ui_calculator_number_3;
lv_obj_t *ui_calculator_number_3_lable;
lv_obj_t *ui_calculator_number_4;
lv_obj_t *ui_calculator_number_4_lable;
lv_obj_t *ui_calculator_number_5;
lv_obj_t *ui_calculator_number_5_lable;
lv_obj_t *ui_calculator_number_6;
lv_obj_t *ui_calculator_number_6_lable;
lv_obj_t *ui_calculator_number_7;
lv_obj_t *ui_calculator_number_7_lable;
lv_obj_t *ui_calculator_number_8;
lv_obj_t *ui_calculator_number_8_lable;
lv_obj_t *ui_calculator_number_9;
lv_obj_t *ui_calculator_number_9_lable;
lv_obj_t *ui_calculator_number_0;
lv_obj_t *ui_calculator_number_0_lable;
lv_obj_t *ui_calculator_panel;
lv_obj_t *ui_calculator_number_mulltiply;
lv_obj_t *ui_calculator_number_devide;
lv_obj_t *ui_calculator_number_addition;
lv_obj_t *ui_calculator_number_subtraction;
lv_obj_t *ui_calculator_number_equals;
lv_obj_t *ui_calculator_number_removeone;
lv_obj_t *ui_calculator_textbox;
lv_obj_t *ui_calculator_number_mulltiply;
lv_obj_t *ui_calculator_number_mulltiply_lable;
lv_obj_t *ui_calculator_number_devide;
lv_obj_t *ui_calculator_number_devide_lable;
lv_obj_t *ui_calculator_number_addition;
lv_obj_t *ui_calculator_number_addition_lable;
lv_obj_t *ui_calculator_number_subtraction;
lv_obj_t *ui_calculator_number_subtractio_lable;
lv_obj_t *ui_calculator_number_equals;
lv_obj_t *ui_calculator_number_equals_lable;
lv_obj_t *ui_calculator_number_removeone;
lv_obj_t *ui_calculator_number_removeone_lable;
lv_obj_t *ui_calculator_textbox;
//////////////////////////////////////////////////
lv_obj_t *ui_snake_button;
lv_obj_t *ui_snake_label;
lv_obj_t *SnakeBox;
lv_obj_t *fileMNG_screan;
lv_obj_t *ui_snake_Button3;
lv_obj_t *ui_snake_Button2;
lv_obj_t *ui_snake_Arrow_UP;
lv_obj_t *ui_snake_Arrow_Down;
lv_obj_t *ui_snake_Arrow_Left;
lv_obj_t *ui_snake_Arrow_Right;
lv_obj_t *ui_snake_Arrow_UP_lable;
lv_obj_t *ui_snake_Arrow_Down_lable;
lv_obj_t *ui_snake_Arrow_Left_lable;
lv_obj_t *ui_snake_Arrow_Right_lable;
lv_obj_t *ui_snake_box;
lv_obj_t *ui_snake_jcon_out;
lv_obj_t *ui_snake_jcon_in;
lv_obj_t *scoreboard_text;
lv_obj_t *scoreboard_panel;
lv_obj_t *FileMb;
lv_obj_t *FileMb_label;
//////////////////////////////////////////////////
void app_select(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change_main(ui_Screen6, LV_SCR_LOAD_ANIM_NONE, 500, 0);
    }
}
void mainscreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change_main(ui_Screen1, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    }
}
void lamp_control(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change_main(ui_Screen7, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    }
}
void calcurator(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change_main(ui_Screen_calculator, LV_SCR_LOAD_ANIM_NONE, 500, 0);
    }
}
void snakemain(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change_main(ui_Screen_snake_game, LV_SCR_LOAD_ANIM_NONE, 500, 0);
    }
}
void FileLoad(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change_main(fileMNG_screan, LV_SCR_LOAD_ANIM_NONE, 0, 0);
    }
}
void ui_init_main(void)
{
    ui_Screen1_screen_init_mian();
    ui_Screen6_screen_init_mian();
    ui_Screen7_screen_init_mian();
    ui_Screen8_screen_init_mian();
    ui_Screen_calculator_screen_init_mian();
    ui_Screen9_screen_init_mian();
}
