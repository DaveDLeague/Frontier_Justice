#pragma once

#include <GL/glew.h>

#include "../fj_math.h"

#include "../fj_object.h"

class Mesh{
public:
    int vertexCount;
    GLuint vao;
    GLuint vbo;
    FJ_Object* parent;

    Mesh(float* verts, int count);

private:
};

