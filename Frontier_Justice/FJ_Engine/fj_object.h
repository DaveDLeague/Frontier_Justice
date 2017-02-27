#pragma once

#include "fj_math.h"

class FJ_Object{
public:
    int id = -1;
    int meshId = -1;
    int shaderId = -1;

    vec3 position = vec3();
    vec3 rotation = vec3();
    vec3 scale = vec3();

    mat4 modelMatrix = mat4(1);
};

