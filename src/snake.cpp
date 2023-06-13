#include "snake.h"
#include "Mine_ui/screens/ui_screen8.h"
int otEkranenXdoRealenX(int x)
{
    return x + 100;
}
int otEkranenYdoRealenY(int y)
{
    return y + 40;
}

void Snake::loop()
{
    if (millis() - lasttick >= 50)
    {
        gfx->fillCircle(otEkranenXdoRealenX(snake_headX), otEkranenYdoRealenY(snake_headY), 25, gfx->color565(255, 255, 255));
        if (snake_headX - 25 - move_x < 0)
        {
            Serial.println(snake_headX);
            snake_headX = 475 - move_x;
        }
        if (snake_headX + 50 + move_x > 500)
        {
            snake_headX = 0 + 25;
        }
        if (snake_headY - 25 - move_y < 0)
        {
            Serial.println(snake_headY);
            snake_headY = 475 - move_x;
            
        }
        if (snake_headY + 25 + move_y > 300)
        {
            snake_headY = 0 + 25;
        }

        snake_headX = snake_headX - move_x;
        snake_headY = snake_headY - move_y;

        gfx->fillCircle(otEkranenXdoRealenX(snake_headX), otEkranenYdoRealenY(snake_headY), 25, gfx->color565(255, 0, 0));
        lasttick = millis();
    }
    PosMove();
}

void Snake::PosMove()
{
    move_x = jconMoveX;
    move_y = jconMoveY;
}
