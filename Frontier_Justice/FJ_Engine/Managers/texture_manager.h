#pragma once

#include <vector>

#include "../Render_Engine/texture.h"

class TextureManager{
public:
    TextureManager();
    Texture* createTexture();
    void deletTexture(Texture* t);

private:
    vector<Texture> textures;
};

