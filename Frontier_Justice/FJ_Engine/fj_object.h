#pragma once

#include "fj_math.h"

class FJ_Object{
public:
    int id;
    int meshId;
    int shaderId;

    vec3 position;
    vec3 rotation;
    vec3 scale;

    mat4 modelMatrix = mat4(1);

    FJ_Object();

private:
    int vao;

};

