#include "mesh.h"

Mesh::Mesh(){
    totalAttributes = 0;
    glGenVertexArrays(1, &vao);
}

void Mesh::addVertices(const float *verts, int count){
    this->vertexCount = count;
    GLuint vbo;

    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float*) * count, verts, GL_STATIC_DRAW);
    glVertexAttribPointer(totalAttributes, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
    glEnableVertexAttribArray(totalAttributes);
    glBindVertexArray(0);
    totalAttributes++;
    vbos.push_back(vbo);
}

void Mesh::addTextureCoordinates(const float *coords, int count){
    GLuint vbo;

    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float*) * count, coords, GL_STATIC_DRAW);
    glVertexAttribPointer(totalAttributes, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
    glEnableVertexAttribArray(totalAttributes);
    glBindVertexArray(0);
    totalAttributes++;
    vbos.push_back(vbo);
}



void Mesh::addNormalCoordinates(const float *coords, int count){
    GLuint vbo;

    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float*) * count, coords, GL_STATIC_DRAW);
    glVertexAttribPointer(totalAttributes, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
    glEnableVertexAttribArray(totalAttributes);
    glBindVertexArray(0);
    totalAttributes++;
    vbos.push_back(vbo);
}
