#pragma once

#include <algorithm>
#include "math_util.h"

#include "Render_Engine/mesh.h"
#include "Render_Engine/texture.h"

using namespace std;

class GameObject{
public:
    int id = -1;
    int rendererId = -1;

    Mesh* mesh = NULL;
    Texture* texture = NULL;

    vec3 position = vec3(0, 0, 0);
    vec3 rotation = vec3(0, 0, 0);
    vec3 scale = vec3(1, 1, 1);

    quat rotQuat = quat();
    mat4 modelMatrix = mat4(1);
};

