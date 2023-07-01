#ifndef SNAKE_H
#define SNAKE_H

#include "main.h"
#include <Vector.h>

class Snake
{
public:
#define tail_count 15
#define bgWH 50
#define maxMove 1000
#define foodGen 100
#define foodSize 15

    int snakeFoodX[foodGen] = {0};
    int snakeFoodY[foodGen] = {0};

    void setup();
    bool move_headX = false;
    bool move_headY = false;

    bool cameraXMove = false;
    bool cameraYMove = false;
    int curuntTail = 0;
    int move_x = 5;
    int move_y = 0;
    int lasttick = millis();
    int snake_headX = 250;
    int snake_headY = 150;
    int bgXofset = 0;
    int bgYofset = 0;
    int bgXofset_total = 0;
    int bgYofset_total = 0;
    int game[25][15];
    int gameObjCords[25][15];
    int tailX[tail_count] = {250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250};
    int tailY[tail_count] = {150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150};
    int numTilesX = 500 / bgWH;
    int numTilesY = 300 / bgWH;
    
    void loop();
    void PosMove();
    void CameraMove();
    void drawfood(bool remove );
    void drawSnake(bool remove );
    void drawTail(bool remove);
    void drawBg(bool remove);

private:
protected:
};
#endif
