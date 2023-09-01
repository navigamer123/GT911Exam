#include "myDrawingLibraly/N_draw.h"

n_draw::n_draw(int x, int y, int w, int h, uint16_t bg_collor)
{
    x1 = x;
    y1 = y;
    w1 = w;
    h1 = h;
    bg_collor1 = bg_collor;
}
void n_draw::draw_pixel(int pixel_x, int pixel_y, uint16_t collor)
{
    buffer[(pixel_x * w1) + pixel_y] = collor;
}
uint16_t n_draw::color565(uint8_t r, uint8_t g, uint8_t b)
{
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
    // not mine Arduino gfx code
}
void n_draw::fillRect(int rect_x, int rect_y, int rect_w, int rect_h, uint16_t collor)
{
    for (int w = 0; w < rect_x + rect_w; w++)
    {
        for (int h = 0; h < rect_y + rect_h; h++)
        {
            if (rect_x <= w)
            {
                if (rect_y <= h)
                {
                    draw_pixel(h, w, collor);
                }
            }
        }
    }
}
void n_draw::drawRect(int rect_x, int rect_y, int rect_w, int rect_h, uint16_t collor)
{
    for (int w = 0; w < rect_x + rect_w; w++)
    {
        for (int h = 0; h < rect_y + rect_h; h++)
        {
            if (rect_x <= w)
            {
                if (rect_y <= h)
                {
                    if (w == rect_x || w == rect_x + rect_w)
                    {
                        if (h == rect_y || h == rect_y + rect_h)
                        {
                            draw_pixel(h, w, collor);
                        }
                    }
                }
            }
        }
    }
}
void n_draw::fillCircle(int circle_x, int circle_y, int r, uint16_t collor)
{
    float angle_circle;
    float x_edge = 0;
    float y_edge = 0;
    for (int j = 0; j < 360; j++)
    {
        angle_circle = (j * 0.01745331); // angle expressed in radians - 1 degree = 0,01745331 radians
        x_edge = (circle_x + (r * cos(angle_circle)));
        y_edge = (circle_y + (r * sin(angle_circle)));
        draw_pixel(x_edge, y_edge, collor);
    }
}
void n_draw::display(void)
{
    gfx->draw16bitBeRGBBitmap(x1, y1, buffer, w1, h1);
    for (int i = 0; i < w1 * h1; i++)
    {
        buffer[i] = bg_collor1;
    }
}
void n_draw::start_draw()
{
    buffer = (uint16_t *)malloc(w1 * h1);
    if (buffer == NULL)
    {
        Serial.println("malloc failed");
    }
    else
    {
        Serial.println("malloc succeeded");
    }
    for (int i = 0; i < w1 * h1; i++)
    {
        buffer[i] = bg_collor1;
    }
}
