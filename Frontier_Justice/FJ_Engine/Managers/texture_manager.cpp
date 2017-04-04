#include "texture_manager.h"

TextureManager::TextureManager(){

}

Texture *TextureManager::createTexture(){
    Texture t;
    t.id = textures.size();
    textures.push_back(t);
    return &textures[textures.size() - 1];
}

void TextureManager::deletTexture(Texture *t){
    textures.erase(textures.begin() + t->id);
}

