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

        snake_headX = snake_headX - move_x;
        snake_headY = snake_headY - move_y;

        if (snake_headX - 25 < 0)
        {
            Serial.println(snake_headX);
            snake_headX = 475;
        }
        else if (snake_headX + 25 > 500)
        {
            snake_headX = 25;
        }
        else if (snake_headY - 25 < 0)
        {
            Serial.println(snake_headY);
            snake_headY = 275;
        }
        else if (snake_headY + 25 > 300)
        {
            snake_headY = 25;
        }
        gfx->fillCircle(otEkranenXdoRealenX(snake_headX), otEkranenYdoRealenY(snake_headY), 25, gfx->color565(255, 0, 0));
        PosMove();
        lasttick = millis();
    }
}

void Snake::PosMove()
{
    move_x = jconMoveX;
    move_y = jconMoveY;
}
