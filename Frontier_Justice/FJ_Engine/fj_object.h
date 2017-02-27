#pragma once

#include "fj_math.h"

class FJ_Object{
public:
    int id = -1;
    int meshId = -1;
    int shaderId = -1;

    vec3 position = vec3(0, 0, 0);
    vec3 rotation = vec3(0, 0, 0);
    vec3 scale = vec3(1, 1, 1);

    quat rotQuat = quat();
    mat4 modelMatrix = mat4(1);
};

