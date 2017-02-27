#pragma once

#include <GL/glew.h>

class Texture{
public:
    int id;
    GLuint texID;

    Texture();
    void loadData(unsigned char* data, int width, int height);
    void loadImage(char* image);
};

