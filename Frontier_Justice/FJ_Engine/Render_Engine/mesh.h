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

    Mesh(const float* verts, int count);
    void addTextureCoordinates(const float* coords, int count);
    void addNormalCoordinates(const float* coords, int count);

private:
};

