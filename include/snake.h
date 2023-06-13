#ifndef SNAKE_H
#define SNAKE_H

#include "main.h"

class Snake
{
public:
#define tail_count 15
#define bgWH 50
    int curuntTail = 0;
    int move_x = 5;
    int move_y = 0;
    int lasttick = millis();
    int snake_headX = 250;
    int snake_headY = 150;
    int bgX = 400;
    int bgY = 400;
    int game[25][15];
    int gameObjCords[25][15];
    int tailX[tail_count];
    int tailY[tail_count];
    void loop();
    void PosMove();
    void CameraMove();

private:
protected:
};
#endif
