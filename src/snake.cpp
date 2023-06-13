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
    if (millis() - lasttick >= 75)
    {
        curuntTail = (curuntTail + 1) % tail_count;

        // Erase previous tail positions
        if (tailX[curuntTail] != 0)
        {
            gfx->fillCircle(otEkranenXdoRealenX(tailX[curuntTail]), otEkranenYdoRealenY(tailY[curuntTail]), 25, gfx->color565(255, 255, 255));
        }

        // Update tail position
        tailX[curuntTail] = snake_headX;
        tailY[curuntTail] = snake_headY;

        // Erase previous snake head position
        gfx->fillCircle(otEkranenXdoRealenX(snake_headX), otEkranenYdoRealenY(snake_headY), 25, gfx->color565(255, 255, 255));

        // Update snake head position
        snake_headX -= move_x;
        snake_headY -= move_y;

        // Wrap snake head around the screen boundaries
        if (snake_headX < 25)
        {
            snake_headX = 475 - move_x;
        }
        else if (snake_headX > 475)
        {
            snake_headX = 25 - move_x;
        }

        if (snake_headY < 25)
        {
            snake_headY = 275 - move_y;
        }
        else if (snake_headY > 275)
        {
            snake_headY = 25 - move_y;
        }

        // Draw new snake head and tail positions
        gfx->fillCircle(otEkranenXdoRealenX(snake_headX), otEkranenYdoRealenY(snake_headY), 25, gfx->color565(255, 0, 0));
        gfx->fillCircle(otEkranenXdoRealenX(tailX[curuntTail]), otEkranenYdoRealenY(tailY[curuntTail]), 25, gfx->color565(255, 0, 0));

        PosMove();
        lasttick = millis();
    }
}

void Snake::PosMove()
{
    move_x = jconMoveX;
    move_y = jconMoveY;
}
