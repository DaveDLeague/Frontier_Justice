#pragma once

#include <vector>

#include <GL/glew.h>

#include "game_object.h"

#include "Managers/mesh_manager.h"
#include "Managers/object_manager.h"
#include "Managers/texture_manager.h"

#include "Render_Engine/camera.h"
#include "Render_Engine/mesh.h"
#include "Render_Engine/renderer.h"
#include "Render_Engine/texture.h"

using namespace std;

class Scene{
public:
    Scene();

    void render();
    void update();
    void attachRenderer(GameObject*& g1, Renderer*& r);
    inline void setCamera(Camera* cam){ camera = cam; }

    Renderer* createRenderer();
    GameObject* createObject();
    Mesh* createMesh();
    Texture* createTexture();

private:
    vector<Renderer> renderers;
    Camera* camera;
    MeshManager meshManager;
    ObjectManager objectManager;
    TextureManager textureManager;
};

