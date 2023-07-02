#ifndef SNAKE_H
#define SNAKE_H

#include "main.h"
#include <Vector.h>

class Snake
{
public:
#define tail_count 10
#define bgWH 50
#define maxMove 1000
#define foodGen 100
#define foodSize 10
#define snakeSize 25
#define bg_color  250,250,250
#define move_delay 100
    int snakeFoodX[foodGen] = {0};
    int snakeFoodY[foodGen] = {0};
    int score = 0;
    int prev_score = 0;
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
    int tailX[tail_count];
    int tailY[tail_count];
    int numTilesX = 500 / bgWH;
    int numTilesY = 300 / bgWH;
    
    void loop();
    void PosMove();
    void CameraMove();
    void drawfood(bool remove );
    void drawSnake(bool remove );
    void drawTail(bool remove);
    void drawBg(bool remove);
    void drawScore(bool remove);
    void fruitCheck();

private:
protected:
};
#endif
