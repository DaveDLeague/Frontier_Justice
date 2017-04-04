#pragma once

#include <vector>

#include "camera.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "../game_object.h"

using namespace std;

class Renderer{
public:
    int id = -1;
    int totalObjects = 0;
    int startingIndex = 0;

    Renderer();
    virtual void render(GameObject* objects, Camera* camera);

    void setShader(Shader s);
    void loadShader(const char* vShader, const char* fShader, const char* gShader = NULL);

protected:
    Shader shader;
};

