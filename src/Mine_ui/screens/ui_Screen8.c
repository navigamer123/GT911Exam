#include "Mine_ui/ui_main.h"
#include "squerline_ui/ui.h"

#define jcon_W 200
#define jcon_H 200
#define CANVAS_WIDTH 200
#define CANVAS_HEIGHT 150
int jconMoveX;
int jconMoveY;
void drag_event_handler(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    lv_indev_t *indev = lv_indev_get_act();
    if (indev == NULL)
        return;

    lv_point_t vect;
    lv_indev_get_vect(indev, &vect);
    lv_coord_t x;
    lv_coord_t y;
    x = lv_obj_get_x(obj) + vect.x;
    y = lv_obj_get_y(obj) + vect.y;
    if (vect.x != 0 && vect.y != 0)
    {
        jconMoveX = (50 - x) / 15;
        jconMoveY = (50 - y) / 15;
    }
    lv_obj_set_pos(obj, x, y);
}

static void backto00(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);

    lv_indev_t *indev = lv_indev_get_act();
    if (indev == NULL)
        return;

    lv_coord_t x = 35;
    lv_coord_t y = 35;
    lv_obj_set_pos(obj, x, y);
}

void ui_Screen8_screen_init_mian(void)
{
    ui_Screen_snake_game = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen_snake_game, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_img_src(ui_Screen_snake_game, &ui_img_1695069766, LV_PART_MAIN | LV_STATE_DEFAULT);
    // back button
    ui_back = lv_btn_create(ui_Screen_snake_game);
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

    /*ui_snake_Arrow_UP = lv_btn_create(ui_Screen_snake_game);
    lv_obj_set_width(ui_snake_Arrow_UP, 50);
    lv_obj_set_height(ui_snake_Arrow_UP, 50);
    lv_obj_set_x(ui_snake_Arrow_UP, 650);
    lv_obj_set_y(ui_snake_Arrow_UP, 350);

    ui_snake_Arrow_UP_lable = lv_label_create(ui_snake_Arrow_UP);
    lv_obj_set_width(ui_snake_Arrow_UP_lable, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_snake_Arrow_UP_lable, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_snake_Arrow_UP_lable, 0);
    lv_obj_set_y(ui_snake_Arrow_UP_lable, 0);
    lv_obj_set_align(ui_snake_Arrow_UP_lable, LV_ALIGN_CENTER);
    lv_label_set_text(ui_snake_Arrow_UP_lable, "/\\");

    ui_snake_Arrow_Down = lv_btn_create(ui_Screen_snake_game);
    lv_obj_set_width(ui_snake_Arrow_Down, 50);
    lv_obj_set_height(ui_snake_Arrow_Down, 50);
    lv_obj_set_x(ui_snake_Arrow_Down, 650);
    lv_obj_set_y(ui_snake_Arrow_Down, 410);

    ui_snake_Arrow_Down_lable = lv_label_create(ui_snake_Arrow_Down);
    lv_obj_set_width(ui_snake_Arrow_Down_lable, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_snake_Arrow_Down_lable, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_snake_Arrow_Down_lable, 0);
    lv_obj_set_y(ui_snake_Arrow_Down_lable, 0);
    lv_obj_set_align(ui_snake_Arrow_Down_lable, LV_ALIGN_CENTER);
    lv_label_set_text(ui_snake_Arrow_Down_lable, "\\/");

    ui_snake_Arrow_Left = lv_btn_create(ui_Screen_snake_game);
    lv_obj_set_width(ui_snake_Arrow_Left, 50);
    lv_obj_set_height(ui_snake_Arrow_Left, 50);
    lv_obj_set_x(ui_snake_Arrow_Left, 590);
    lv_obj_set_y(ui_snake_Arrow_Left, 410);

    ui_snake_Arrow_Left_lable = lv_label_create(ui_snake_Arrow_Left);
    lv_obj_set_width(ui_snake_Arrow_Left_lable, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_snake_Arrow_Left_lable, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_snake_Arrow_Left_lable, 0);
    lv_obj_set_y(ui_snake_Arrow_Left_lable, 0);
    lv_obj_set_align(ui_snake_Arrow_Left_lable, LV_ALIGN_CENTER);
    lv_label_set_text(ui_snake_Arrow_Left_lable, "<=");

    ui_snake_Arrow_Right = lv_btn_create(ui_Screen_snake_game);
    lv_obj_set_width(ui_snake_Arrow_Right, 50);
    lv_obj_set_height(ui_snake_Arrow_Right, 50);
    lv_obj_set_x(ui_snake_Arrow_Right, 710);
    lv_obj_set_y(ui_snake_Arrow_Right, 410);

    ui_snake_Arrow_Right_lable = lv_label_create(ui_snake_Arrow_Right);
    lv_obj_set_width(ui_snake_Arrow_Right_lable, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_snake_Arrow_Right_lable, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_snake_Arrow_Right_lable, 0);
    lv_obj_set_y(ui_snake_Arrow_Right_lable, 0);
    lv_obj_set_align(ui_snake_Arrow_Right_lable, LV_ALIGN_CENTER);
    lv_label_set_text(ui_snake_Arrow_Right_lable, "=>");*/

    ui_snake_jcon_out = lv_obj_create(ui_Screen_snake_game);
    lv_obj_set_width(ui_snake_jcon_out, jcon_W);
    lv_obj_set_height(ui_snake_jcon_out, jcon_H);
    lv_obj_set_x(ui_snake_jcon_out, 300);
    lv_obj_set_y(ui_snake_jcon_out, 80);
    lv_obj_set_align(ui_snake_jcon_out, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_snake_jcon_out, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_snake_jcon_out, jcon_W / 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_snake_jcon_in = lv_obj_create(ui_snake_jcon_out);
    lv_obj_set_size(ui_snake_jcon_in, 75, 75);
    lv_obj_set_x(ui_snake_jcon_in, 25);
    lv_obj_set_y(ui_snake_jcon_in, 25);
    lv_obj_add_event_cb(ui_snake_jcon_in, drag_event_handler, LV_EVENT_PRESSING, NULL);
    lv_obj_add_event_cb(ui_snake_jcon_in, backto00, LV_EVENT_RELEASED, NULL);
    lv_obj_set_style_bg_color(ui_snake_jcon_in, lv_color_hex(0x00000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_snake_jcon_in, 75, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_snake_box = lv_obj_create(ui_Screen_snake_game);
    lv_obj_set_width(ui_snake_box, 500);
    lv_obj_set_height(ui_snake_box, 300);
    lv_obj_set_x(ui_snake_box, -50);
    lv_obj_set_y(ui_snake_box, -50);
    lv_obj_set_align(ui_snake_box, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_snake_box, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_snake_box, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    /*Create colors with the indices of the palette*/
    /*
    ui_snake_Button3 = lv_btn_create(ui_Screen_snake_game);
    lv_obj_set_width(ui_snake_Button3, 150);
    lv_obj_set_height(ui_snake_Button3, 150);
    lv_obj_set_x(ui_snake_Button3, 256);
    lv_obj_set_y(ui_snake_Button3, 144);
    lv_obj_set_align(ui_snake_Button3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_snake_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_snake_Button3, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(ui_snake_Button3, 90, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_snake_Button3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_snake_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_snake_Button3, lv_color_hex(0x33F623), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_snake_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_snake_Button3, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_snake_Button3,LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui_snake_Button3,LV_OBJ_FLAG_CLICK_FOCUSABLE);
    ui_snake_Button2 = lv_btn_create(ui_snake_Button3);
    lv_obj_set_width(ui_snake_Button2, 40);
    lv_obj_set_height(ui_snake_Button2, 40);
    lv_obj_set_align(ui_snake_Button2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_snake_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_snake_Button2, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(ui_snake_Button2, 90, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_snake_Button2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_snake_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_snake_Button2, lv_color_hex(0x33F623), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_snake_Button2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_snake_Button2, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_snake_Button2,LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui_snake_Button2,LV_OBJ_FLAG_CLICK_FOCUSABLE);
    */
}