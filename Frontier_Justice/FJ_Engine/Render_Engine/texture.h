#pragma once

#include <string>

#include <GL/glew.h>

using namespace std;

class Texture{
public:
    int id;
    GLuint texID;

    Texture();
    void loadData(unsigned char* data, int width, int height, bool hasAlpha);
    void loadImage(const char* image, bool hasAlpha);
    void bind();
};

