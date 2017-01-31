#ifndef GAME_MATH_H
#define GAME_MATH_H

#include <stdio.h>

struct Vec2f{
    float x;
    float y;

    inline void print(){
        printf("(%f, %f)", x, y);
    }
};

#endif // GAME_MATH_H
