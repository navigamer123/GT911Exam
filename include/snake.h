#ifndef SNAKE_H
#define SNAKE_H

#include "main.h"


class Snake
{
public:
    int move_x = 5;
    int move_y = 0;
    int lasttick = millis();
    int snake_headX = 250;
    int snake_headY = 150;
    int game[25][15];
    void loop();
    void PosMove();

private:
protected:
};
#endif
