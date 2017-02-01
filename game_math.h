#ifndef GAME_MATH_H
#define GAME_MATH_H

#include <stdio.h>

struct Vec2i{
    int x;
    int y;

    Vec2i(int x = 0, int y = 0){
        this->x = x;
        this->y = y;
    }
};

struct Vec2f{
    float x;
    float y;

    Vec2f(int x = 0.0f, int y = 0.0f){
        this->x = x;
        this->y = y;
    }
};

struct Vec3i{
    int x;
    int y;
    int z;

    Vec3i(int x = 0, int y = 0, int z = 0){
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

struct Vec3f{
    float x;
    float y;
    float z;

    Vec3f(float x = 0, float y = 0, float z = 0){
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

class GameMath{
public:
    static void printVec(Vec2i v){
        printf("(%i, %i)", v.x, v.y);
    }

    static void printVec(Vec2f v){
        printf("(%f, %f)", v.x, v.y);
    }

    static Vec2f addVec2f(Vec2f v1, Vec2f v2){
        return Vec2f(v1.x + v2.x, v1.y + v2.y);
    }

    static Vec2i addVec2i(Vec2i v1, Vec2i v2){
        return Vec2i(v1.x + v2.x, v1.y + v2.y);
    }

    static Vec2f subVec2f(Vec2f v1, Vec2f v2){
        return Vec2f(v1.x - v2.x, v1.y - v2.y);
    }

    static Vec2i subVec2i(Vec2i v1, Vec2i v2){
        return Vec2i(v1.x - v2.x, v1.y - v2.y);
    }
};

#endif // GAME_MATH_H
