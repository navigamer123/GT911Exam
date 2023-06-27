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
        curuntTail = (curuntTail + 1) % tail_count;
        if (tailX[curuntTail] != 0)
        {
            gfx->fillCircle(otEkranenXdoRealenX(tailX[curuntTail]), otEkranenYdoRealenY(tailY[curuntTail]), 25, gfx->color565(255, 255, 255));
        }
        int numTilesX = 500 / bgWH;
        int numTilesY = 300 / bgWH;
        for (int x = 0; x < numTilesX; x++)
        {
            for (int y = 0; y < numTilesY; y++)
            {
                int posX = x * bgWH;
                int posY = y * bgWH;
                if (bgXofset != 0)
                {
                    if (bgXofset >= 1)
                    {
                        if (x == 0)
                        {
                            continue;
                        }
                    }
                    if (bgXofset <= -1)
                    {
                        if (x == numTilesX -1)
                        {
                            continue;
                        }
                    }
                }
                if (bgYofset != 0)
                {
                    if (bgYofset >= 1)
                    {
                        if (y == 0)
                        {
                            continue;
                        }
                    }
                    if (bgYofset <= -1)
                    {
                        if (y == numTilesY -1 )
                        {
                            continue;
                        }
                    }
                }
                gfx->drawRect(otEkranenXdoRealenX(posX - bgXofset), otEkranenYdoRealenY(posY - bgYofset), bgWH, bgWH, gfx->color565(255, 255, 255));
            }
        }
        CameraMove();
        if (curuntTail == 0)
        {
            tailX[curuntTail] = snake_headX;
            tailY[curuntTail] = snake_headY;
        }
        else
        {
            tailX[curuntTail] = tailX[curuntTail - 1] - move_x;
            tailY[curuntTail] = tailY[curuntTail - 1] - move_y;
        }

        gfx->fillCircle(otEkranenXdoRealenX(snake_headX), otEkranenYdoRealenY(snake_headY), 25, gfx->color565(255, 255, 255));

        // snake_headX -= move_x;
        // snake_headY -= move_y;
        PosMove();

        for (int x = 0; x < numTilesX; x++)
        {
            for (int y = 0; y < numTilesY; y++)
            {
                int posX = x * bgWH;
                int posY = y * bgWH;
                if (bgXofset != 0)
                {
                    if (bgXofset >= 1)
                    {
                        if (x == 0)
                        {
                            continue;
                        }
                    }
                    if (bgXofset <= -1)
                    {
                        if (x == numTilesX-1)
                        {
                            continue;
                        }
                    }
                }
                if (bgYofset != 0)
                {
                    if (bgYofset >= 1)
                    {
                        if (y == 0)
                        {;
                            continue;
                        }
                    }
                    if (bgYofset <= -1)
                    {
                        if (y == numTilesY-1)
                        {
                            continue;
                        }
                    }
                }
                gfx->drawRect(otEkranenXdoRealenX(posX - bgXofset), otEkranenYdoRealenY(posY - bgYofset), bgWH, bgWH, gfx->color565(20, 20, 20));
            }
        }
        gfx->fillRect(otEkranenXdoRealenX(0), otEkranenYdoRealenY(0), 500, bgWH, gfx->color565(255, 255, 255));
        gfx->fillRect(otEkranenXdoRealenX(0), otEkranenYdoRealenY(0), bgWH, 300, gfx->color565(255, 255, 255));
        gfx->fillRect(otEkranenXdoRealenX(0), otEkranenYdoRealenY(300 - bgWH), 500, bgWH, gfx->color565(255, 255, 255));
        gfx->fillRect(otEkranenXdoRealenX(500 - bgWH), otEkranenYdoRealenY(0), bgWH, 300, gfx->color565(255, 255, 255));
        for (int i = 0; i < tail_count; i++)
        {
            gfx->fillCircle(otEkranenXdoRealenX(tailX[i]), otEkranenYdoRealenY(tailY[i]), 25, gfx->color565(255, 0, 0));
        }

        gfx->fillCircle(otEkranenXdoRealenX(snake_headX), otEkranenYdoRealenY(snake_headY), 25, gfx->color565(255, 0, 0));
        gfx->fillCircle(otEkranenXdoRealenX(snake_headX - 10), otEkranenYdoRealenY(snake_headY - 5), 5, gfx->color565(0, 0, 0));
        gfx->fillCircle(otEkranenXdoRealenX(snake_headX + 10), otEkranenYdoRealenY(snake_headY - 5), 5, gfx->color565(0, 0, 0));
        lasttick = millis();
        if (bgXofset > bgWH)
        {
            bgXofset = 0;
        }
        else if (bgXofset < bgWH * -1)
        {
            bgXofset = 0;
        }
        if (bgYofset > bgWH)
        {
            bgYofset = 0;
        }
        else if (bgYofset < bgWH * -1)
        {
            bgYofset = 0;
        }
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
    bgXofset -= move_x;
    bgYofset -= move_y;
}
