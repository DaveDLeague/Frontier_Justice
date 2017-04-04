#include "texture.h"

#include <SOIL.h>

Texture::Texture(){

}

void Texture::loadData(unsigned char *data, int width, int height, bool hasAlpha){
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if(hasAlpha){
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }else{
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    }

    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_LOD_BIAS, -0.4);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::loadImage(const char *image, bool hasAlpha){
    int width;
    int height;
    unsigned char* data;
    if(hasAlpha){
        data = SOIL_load_image(image, &width, &height, 0, SOIL_LOAD_RGBA);
    }else{
        data = SOIL_load_image(image, &width, &height, 0, SOIL_LOAD_RGB);
    }
    loadData(data, width, height, hasAlpha);
    SOIL_free_image_data(data);
}

void Texture::bind(){
    glBindTexture(GL_TEXTURE_2D, texID);
}
