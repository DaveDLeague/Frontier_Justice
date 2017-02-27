#include "mesh.h"

Mesh::Mesh(float* verts, int count){
    this->vertexCount = count;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);


    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float*) * count, verts, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    vbos.push_back(vbo);
}

void Mesh::addTextureCoordinates(float *coords, int count){
    GLuint vbo;
    int attrib = vbos.size();

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float*) * count, coords, GL_STATIC_DRAW);
    glVertexAttribPointer(attrib, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
    glEnableVertexAttribArray(attrib);
    glBindVertexArray(0);
    vbos.push_back(vbo);
}


