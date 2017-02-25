#pragma once

#include <vector>

#include <GL/glew.h>

#include "fj_object.h"

#include "Render_Engine/camera.h"
#include "Render_Engine/shader.h"
#include "Render_Engine/mesh.h"

using namespace std;

class Scene{
public:
    Scene();

    void render(Camera* camera);
    void addMeshToObject(FJ_Object* obj, float* verts, int vertCount);
    void attatchShaderToObject(FJ_Object* obj, Shader* shdr);

    FJ_Object* createObject();
    Shader* createShader();

private:
    vector<Shader> shaders;
    vector<FJ_Object> objects;
    vector<Mesh> meshes;
    vector<GLuint> vaos;
    vector<GLuint> vbos;
};

