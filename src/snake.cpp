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
    if (millis() - lasttick >= move_delay)
    {
        curuntTail = (curuntTail + 1) % tail_count;
        drawTail(true);
        drawBg(true);
        drawfood(true);
        drawSnake(true);
        CameraMove();

        for (int i = 0; i < tail_count; i++)
        {
            if (i == 0)
            {
                tailX[i] = snake_headX;
                tailY[i] = snake_headY;
            }
            else
            {
                tailX[i] = tailX[i - 1] + move_x;
                tailY[i] = tailY[i - 1] + move_y;
            }
        }

        if (move_headX == true)
            snake_headX -= move_x;
        if (move_headY == true)
            snake_headY -= move_y;

        // lasttick = millis();
    }
    PosMove();
    if (millis() - lasttick >= move_delay)
    {
        drawBg(false);

        // gfx->fillRect(otEkranenXdoRealenX(0), otEkranenYdoRealenY(0), 500, bgWH, gfx->color565(bg_color));
        // gfx->fillRect(otEkranenXdoRealenX(0), otEkranenYdoRealenY(0), bgWH, 300, gfx->color565(bg_color));
        // gfx->fillRect(otEkranenXdoRealenX(0), otEkranenYdoRealenY(300 - bgWH), 500, bgWH, gfx->color565(bg_color));
        // gfx->fillRect(otEkranenXdoRealenX(500 - bgWH), otEkranenYdoRealenY(0), bgWH, 300, gfx->color565(bg_color));
        //  hrana
        drawfood(false);

        // opshka
        drawTail(false);
        // glawa
        drawSnake(false);
        lasttick = millis();
    }
}

void Snake::PosMove()
{
    move_x = jconMoveX;
    move_y = jconMoveY;
    // speed
#define move_max 6
    if (move_x >= move_max)
    {
        move_x = move_max;
    }
    else if (move_x <= move_max * -1)
    {
        move_x = move_max * -1;
    }
    if (move_y >= move_max)
    {
        move_y = move_max;
    }
    else if (move_y <= move_max * -1)
    {
        move_y = move_max * -1;
    }
    // head pos
    /*if (snake_headX < 25)
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
    }*/
    if (snake_headX < 25)
    {
        snake_headX = 250;

        snake_headY = 150;
        bgYofset_total = 0;

        bgXofset_total = 0;
    }
    else if (snake_headX > 475)
    {
        snake_headX = 250;

        snake_headY = 150;
        bgYofset_total = 0;

        bgXofset_total = 0;
    }

    if (snake_headY < 25)
    {
        snake_headY = 150;

        snake_headX = 250;
        bgXofset_total = 0;

        bgYofset_total = 0;
    }
    else if (snake_headY > 275)
    {
        snake_headY = 150;

        snake_headX = 250;
        bgXofset_total = 0;

        bgYofset_total = 0;
    }
}

void Snake::CameraMove()
{
    if (cameraXMove == true)
    {
        bgXofset -= move_x;
    }
    if (cameraYMove == true)
    {
        bgYofset -= move_y;
    }

    bgXofset_total -= move_x;
    bgYofset_total -= move_y;

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
    // make the head move again
    if (bgXofset_total > maxMove)
    {
        move_headX = true;
        cameraXMove = false;
    }
    else if (bgXofset_total < maxMove * -1)
    {
        move_headX = true;
        cameraXMove = false;
    }
    if (bgYofset_total > maxMove)
    {
        move_headY = true;
        cameraYMove = false;
    }
    else if (bgYofset_total < maxMove * -1)
    {
        move_headY = true;
        cameraYMove = false;
    }

    if (bgXofset_total < maxMove - 50 && bgXofset_total - 50 > maxMove * -1)
    {
        move_headX = false;
        cameraXMove = true;
    }
    if (bgYofset_total < maxMove - 50 && bgYofset_total - 50 > maxMove * -1)
    {
        move_headY = false;
        cameraYMove = true;
    }
}

void Snake::drawfood(bool remove)
{
    for (int x = 0; x < foodGen; x++)
    {
        if (bgXofset_total + foodSize + 1 + bgWH <= snakeFoodX[x] && snakeFoodX[x] <= bgXofset_total + 500 - (foodSize + 1 + bgWH))
        {
            if (bgYofset_total + foodSize + 1 + bgWH <= snakeFoodY[x] && snakeFoodY[x] <= bgYofset_total + 300 - (foodSize + 1 + bgWH))
            {
                if (!remove)
                {
                    gfx->fillCircle(otEkranenXdoRealenX(snakeFoodX[x] - bgXofset_total), otEkranenYdoRealenY(snakeFoodY[x] - bgYofset_total), foodSize, gfx->color565(255, 0, 0));
                }
                else
                {
                    gfx->fillCircle(otEkranenXdoRealenX(snakeFoodX[x] - bgXofset_total), otEkranenYdoRealenY(snakeFoodY[x] - bgYofset_total), foodSize, gfx->color565(bg_color));
                }
            }
        }
    }
}

void Snake::drawSnake(bool remove)
{
    if (!remove)
    {
        gfx->fillCircle(otEkranenXdoRealenX(snake_headX), otEkranenYdoRealenY(snake_headY), 20, gfx->color565(255, 0, 0));
        gfx->fillCircle(otEkranenXdoRealenX(snake_headX - 9), otEkranenYdoRealenY(snake_headY - 4), 4, gfx->color565(0, 0, 0));
        gfx->fillCircle(otEkranenXdoRealenX(snake_headX + 9), otEkranenYdoRealenY(snake_headY - 4), 4, gfx->color565(0, 0, 0));
    }
    else
    {
        gfx->fillCircle(otEkranenXdoRealenX(snake_headX), otEkranenYdoRealenY(snake_headY), 25, gfx->color565(bg_color));
    }
}

void Snake::drawTail(bool remove)
{

    if (!remove)
    {

        for (int i = 0; i < tail_count; i++)
        {
            gfx->fillCircle(otEkranenXdoRealenX(tailX[i]), otEkranenYdoRealenY(tailY[i]), 25, gfx->color565(255, 0, 0));
        }
    }
    else
    {
        for (int i = 0; i < tail_count; i++)
        {
            gfx->fillCircle(otEkranenXdoRealenX(tailX[i]), otEkranenYdoRealenY(tailY[i]), 25, gfx->color565(bg_color));
        }
        // gfx->fillCircle(otEkranenXdoRealenX(tailX[curuntTail]), otEkranenYdoRealenY(tailY[curuntTail]), 25, gfx->color565(bg_color));
    }
}

void Snake::drawBg(bool remove)
{
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
                    if (x == numTilesX - 1)
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
                    if (y == numTilesY - 1)
                    {
                        continue;
                    }
                }
            }
            if (!remove)
            {
                gfx->drawRect(otEkranenXdoRealenX(posX - bgXofset), otEkranenYdoRealenY(posY - bgYofset), bgWH, bgWH, gfx->color565(20, 20, 20));
            }
            else
            {

                gfx->drawRect(otEkranenXdoRealenX(posX - bgXofset), otEkranenYdoRealenY(posY - bgYofset), bgWH, bgWH, gfx->color565(bg_color));
            }
        }
    }
}

void Snake::setup()
{

    for (int i = 0; i < foodGen; i++)
    {
        snakeFoodX[i] = random(maxMove * -1, maxMove);
        snakeFoodY[i] = random(maxMove * -1, maxMove);
    }
}