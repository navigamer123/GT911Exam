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
    if (millis() - lasttick >= 50) {
    curuntTail = (curuntTail + 1) % tail_count;

    if (tailX[curuntTail] != 0) {
        gfx->fillCircle(otEkranenXdoRealenX(tailX[curuntTail]), otEkranenYdoRealenY(tailY[curuntTail]), 25, gfx->color565(255, 255, 255));
    }

    tailX[curuntTail] = snake_headX;
    tailY[curuntTail] = snake_headY;

    gfx->fillCircle(otEkranenXdoRealenX(snake_headX), otEkranenYdoRealenY(snake_headY), 25, gfx->color565(255, 255, 255));
    
    snake_headX -= move_x;
    snake_headY -= move_y;

    PosMove();

    int numTilesX = 500 / bgWH;
    int numTilesY = 300 / bgWH;

    for (int x = 0; x < numTilesX; x++) {
        for (int y = 0; y < numTilesY; y++) {
            int posX = x * bgWH;
            int posY = y * bgWH;
            gfx->drawRect(otEkranenXdoRealenX(posX), otEkranenYdoRealenY(posY), bgWH, bgWH, gfx->color565(20, 20, 20));
        }
    }

    gfx->fillCircle(otEkranenXdoRealenX(tailX[curuntTail]), otEkranenYdoRealenY(tailY[curuntTail]), 25, gfx->color565(255, 0, 0));
    gfx->fillCircle(otEkranenXdoRealenX(snake_headX), otEkranenYdoRealenY(snake_headY), 25, gfx->color565(255, 0, 0));
    gfx->fillCircle(otEkranenXdoRealenX(snake_headX - 10), otEkranenYdoRealenY(snake_headY - 5), 5, gfx->color565(0, 0, 0));
    gfx->fillCircle(otEkranenXdoRealenX(snake_headX + 10), otEkranenYdoRealenY(snake_headY - 5), 5, gfx->color565(0, 0, 0));
    CameraMove();
    lasttick = millis();
}
}

void Snake::PosMove()
{
    move_x = jconMoveX;
    move_y = jconMoveY;
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
}

void Snake::CameraMove()
{
}
