#pragma once

#include <vector>

#include <GL/glew.h>

#include "fj_object.h"

#include "Render_Engine/camera.h"
#include "Render_Engine/shader.h"
#include "Render_Engine/mesh.h"
#include "Render_Engine/texture.h"

using namespace std;

class Scene{
public:
    Scene();

    void render(Camera* camera);
    void update();
    void addMeshToObject(FJ_Object*& obj, Mesh* m);
    void addTextureToMesh(Mesh* m, Texture* t, float* coords, int count);
    void attatchShaderToObject(FJ_Object* obj, Shader* shdr);

    FJ_Object* createObject();
    Shader* createShader();
    Mesh* createMesh(float* verts, int vertCount);
    Texture* createTexture();

private:
    Texture defaultTexture;

    vector<Shader> shaders;
    vector<FJ_Object> objects;
    vector<FJ_Object> renderableObjects;
    vector<Mesh> meshes;
    vector<Texture> textures;
};

