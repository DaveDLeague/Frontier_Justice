#pragma once

#include "../math_util.h"

class Camera{
public:
    float yaw;
    float pitch;
    float roll;

    vec3 position;
    vec3 forward;
    vec3 up;
    vec3 right;
    vec3 worldUp;
    quat rotQuat;
    mat4 viewMatrix;

    Camera(vec3 location, vec3 up);

    void update();
    void setPerspective(float fov, float aspect, float znear, float zfar);
    inline mat4 getProjection(){ return projection; }

private:
    mat4 translation;
    mat4 rotation;
    mat4 projection;
    mat4 id;
};

