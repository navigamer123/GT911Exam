#ifndef N_DRAW_h
#define N_DRAW_h
#include "main.h"
#define red
class n_draw
{
public:
    int x1 = 0;
    int y1 = 0;
    uint16_t w1 = 800;
    uint16_t h1 = 480;
    uint16_t bg_collor1 = color565(255, 255, 255);
    uint16_t *buffer;
    n_draw(int x, int y, int w, int h, uint16_t bg_collor);
    uint16_t color565(uint8_t r, uint8_t g, uint8_t b);
    void fillRect(int rect_x, int rect_y, int rect_w, int rect_h, uint16_t collor);
    void drawRect(int rect_x, int rect_y, int rect_w, int rect_h, uint16_t collor);
    void fillCircle(int circle_x, int circle_y, int r, uint16_t collor);
    void draw_pixel(int pixel_x, int pixel_y, uint16_t collor);
    void display(void);
    void start_draw();
};

#endif