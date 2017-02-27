#pragma once

#include <vector>

#include <GL/glew.h>

#include "../fj_math.h"
#include "../fj_object.h"

using namespace std;

class Mesh{
public:
    int vertexCount;
    int id;
    int textureId;
    GLuint vao;
    vector<GLuint> vbos;

    Mesh(float* verts, int count);
    void addTextureCoordinates(float* coords, int count);

private:
};

