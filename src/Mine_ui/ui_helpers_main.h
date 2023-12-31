// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: Test

#ifndef _TEST_UI_HELPERS_Main_H
#define _TEST_UI_HELPERS_Main_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui_main.h"

#define _UI_TEMPORARY_STRING_BUFFER_SIZE 32
#define _UI_BAR_PROPERTY_VALUE 0
#define _UI_BAR_PROPERTY_VALUE_WITH_ANIM 1
void _ui_bar_set_property_main(lv_obj_t * target, int id, int val);

#define _UI_BASIC_PROPERTY_POSITION_X 0
#define _UI_BASIC_PROPERTY_POSITION_Y 1
#define _UI_BASIC_PROPERTY_WIDTH 2
#define _UI_BASIC_PROPERTY_HEIGHT 3
void _ui_basic_set_property_main(lv_obj_t * target, int id, int val);

#define _UI_DROPDOWN_PROPERTY_SELECTED 0
void _ui_dropdown_set_property_main(lv_obj_t * target, int id, int val);

#define _UI_IMAGE_PROPERTY_IMAGE 0
void _ui_image_set_property_main(lv_obj_t * target, int id, uint8_t * val);

#define _UI_LABEL_PROPERTY_TEXT 0
void _ui_label_set_property_main(lv_obj_t * target, int id, const char * val);

#define _UI_ROLLER_PROPERTY_SELECTED 0
#define _UI_ROLLER_PROPERTY_SELECTED_WITH_ANIM 1
void _ui_roller_set_property_main(lv_obj_t * target, int id, int val);

#define _UI_SLIDER_PROPERTY_VALUE 0
#define _UI_SLIDER_PROPERTY_VALUE_WITH_ANIM 1
void _ui_slider_set_property_main(lv_obj_t * target, int id, int val);

void _ui_screen_change_main(lv_obj_t * target, lv_scr_load_anim_t fademode, int spd, int delay);

void _ui_arc_increment_main(lv_obj_t * target, int val);

void _ui_bar_increment_main(lv_obj_t * target, int val, int anm);

void _ui_slider_increment_main(lv_obj_t * target, int val, int anm);

void _ui_keyboard_set_target_main(lv_obj_t * keyboard, lv_obj_t * textarea);

#define _UI_MODIFY_FLAG_ADD 0
#define _UI_MODIFY_FLAG_REMOVE 1
#define _UI_MODIFY_FLAG_TOGGLE 2
void _ui_flag_modify_main(lv_obj_t * target, int32_t flag, int value);

#define _UI_MODIFY_STATE_ADD 0
#define _UI_MODIFY_STATE_REMOVE 1
#define _UI_MODIFY_STATE_TOGGLE 2
void _ui_state_modify_main(lv_obj_t * target, int32_t state, int value);

void _ui_opacity_set_main(lv_obj_t * target, int val);

/** Describes an animation*/
void _ui_arc_set_text_value_main(lv_obj_t * trg, lv_obj_t * src, const char * prefix, const char * postfix);

void _ui_slider_set_text_value_main(lv_obj_t * trg, lv_obj_t * src, const char * prefix, const char * postfix);

void _ui_checked_set_text_value_main(lv_obj_t * trg, lv_obj_t * src, const char * txt_on, const char * txt_off);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
