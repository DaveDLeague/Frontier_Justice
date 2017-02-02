#pragma once

#include <stdio.h>
#include <math.h>

static const float PI = 3.14159265;

struct Vec2f{
    float x;
    float y;

    Vec2f(int x = 0.0f, int y = 0.0f){
        this->x = x;
        this->y = y;
    }
};

struct Vec3f{
    float x;
    float y;
    float z;

    Vec3f(float x = 0.0f, float y = 0.0f, float z = 0.0f){
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

struct Mat4f{
    float matrix[4][4];
};

struct Quaternion{
    float x;
    float y;
    float z;
    float w;

    Quaternion(float x = 0, float y = 0, float z = 0, float w = 0){
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }
};

class GameMath{
public:

    static void printVec(const Vec2f &v){
        printf("(%f, %f)", v.x, v.y);
    }

    static float length(const Vec2f &v){
        return (float)sqrt(v.x * v.x + v.y * v.y);
    }

    static float length(const Vec3f &v){
        return (float)sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    }

    static float length(const Quaternion &q){
        return (float)sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
    }

    static float dot(const Vec2f &v1, const Vec2f &v2){
        return v1.x * v2.x + v1.y * v2.y;
    }

    static float dot(const Vec3f &v1, const Vec3f &v2){
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    static Vec3f cross(const Vec3f &v1, const Vec3f &v2){
        float x = v1.y * v2.z - v1.z * v2.y;
        float y = v1.z * v2.x - v1.x * v2.z;
        float z = v1.x * v2.y - v1.y * v2.x;

        return Vec3f(x, y, z);
    }

    static Vec2f normalize(const Vec2f &v){
        float l = length(v);
        return Vec2f(v.x / l, v.y / l);
    }

    static Vec3f normalize(const Vec3f &v){
        float l = length(v);
        return Vec3f(v.x / l, v.y / l, v.z / l);
    }

    static Quaternion normalize(const Quaternion &q){
        float l = length(q);
        return Quaternion(q.x / l, q.y / l, q.z / l, q.w / l);

    }

    static Quaternion conjugate(const Quaternion &q){
        return Quaternion(-q.x, -q.y, -q.z, q.w);
    }

    static Quaternion mul(Quaternion q1, Quaternion q2){
        float w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
        float x = q1.x * q2.w + q1.w * q2.x + q1.y * q2.z - q1.z * q2.y;
        float y = q1.y * q2.w + q1.w * q2.y + q1.z * q2.x - q1.x * q2.z;
        float z = q1.z * q2.w + q1.w * q2.z + q1.x * q2.y - q1.y * q2.x;

        return Quaternion(x, y, z, w);

    }

    static Quaternion mul(Quaternion q, Vec3f v){
        float w = -q.x * v.x - q.y * v.y - q.z * v.z;
        float x =  q.w * v.x + q.y * v.z - q.z * v.y;
        float y =  q.w * v.y + q.z * v.x - q.x * v.z;
        float z =  q.w * v.z + q.x * v.y - q.y * v.x;

        return Quaternion(x, y, z, w);

    }

    static Vec2f rotate(const Vec2f &v, float angle){
        double cosine = cos(angle * PI / 180.0);
        double sine = sin(angle * PI / 180.0);
        return Vec2f((float)(v.x * cosine - v.y * sine), (float)(v.x * sine + v.y * cosine));
    }

    static Vec3f rotate(const Vec3f &v, float angle){

        return mul(v, angle);
    }

    static Vec2f add(const Vec2f &v1, const Vec2f &v2){
        return Vec2f(v1.x + v2.x, v1.y + v2.y);
    }

    static Vec2f add(const Vec2f &v1, float f){
        return Vec2f(v1.x + f, v1.y + f);
    }

    static Vec3f add(const Vec3f &v1, const Vec3f &v2){
        return Vec3f(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    }

    static Vec3f add(const Vec3f &v1, float f){
        return Vec3f(v1.x + f, v1.y + f, v1.z + f);
    }

    static Vec2f sub(Vec2f v1, Vec2f v2){
        return Vec2f(v1.x - v2.x, v1.y - v2.y);
    }

    static Vec2f sub(const Vec2f &v1, float f){
        return Vec2f(v1.x - f, v1.y - f);
    }

    static Vec3f sub(const Vec3f &v1, const Vec3f &v2){
        return Vec3f(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
    }

    static Vec3f sub(const Vec3f &v1, float f){
        return Vec3f(v1.x - f, v1.y - f, v1.z - f);
    }

    static Vec2f mul(Vec2f v1, Vec2f v2){
        return Vec2f(v1.x * v2.x, v1.y * v2.y);
    }

    static Vec2f mul(const Vec2f &v1, float f){
        return Vec2f(v1.x * f, v1.y * f);
    }

    static Vec3f mul(const Vec3f &v1, const Vec3f &v2){
        return Vec3f(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
    }

    static Vec3f mul(const Vec3f &v1, float f){
        return Vec3f(v1.x * f, v1.y * f, v1.z * f);
    }

    static Vec2f div(Vec2f v1, Vec2f v2){
        return Vec2f(v1.x / v2.x, v1.y / v2.y);
    }

    static Vec2f div(const Vec2f &v1, float f){
        return Vec2f(v1.x / f, v1.y / f);
    }

    static Vec3f div(const Vec3f &v1, const Vec3f &v2){
        return Vec3f(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
    }

    static Vec3f div(const Vec3f &v1, float f){
        return Vec3f(v1.x / f, v1.y / f, v1.z / f);
    }

    static Mat4f createIdentityMatrix(){
        Mat4f m;
        m.matrix[0][0] = 1; m.matrix[0][1] = 0; m.matrix[0][2] = 0; m.matrix[0][3] = 0;
        m.matrix[1][0] = 0; m.matrix[1][1] = 1; m.matrix[1][2] = 0; m.matrix[1][3] = 0;
        m.matrix[2][0] = 0; m.matrix[2][1] = 0; m.matrix[2][2] = 1; m.matrix[2][3] = 0;
        m.matrix[3][0] = 0; m.matrix[3][1] = 0; m.matrix[3][2] = 0; m.matrix[3][3] = 1;
        return m;
    }

    static Mat4f mul(const Mat4f &m1, const Mat4f &m2){
        Mat4f m;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                m.matrix[i][j] = m1.matrix[i][0] * m2.matrix[0][j] +
                                 m1.matrix[i][1] * m2.matrix[1][j] +
                                 m1.matrix[i][2] * m2.matrix[2][j] +
                                 m1.matrix[i][3] * m2.matrix[3][j];
            }
        }
        return m;
    }
};
