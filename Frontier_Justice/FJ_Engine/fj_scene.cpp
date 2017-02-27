#include "fj_scene.h"

unsigned char greyTex[] = {200, 200, 200};

Scene::Scene(){
    shaders.reserve(8);
    objects.reserve(256);
    renderableObjects.reserve(128);
    meshes.reserve(64);

    defaultTexture.loadData(greyTex, 1, 1);
    defaultTexture.id = textures.size();
    textures.push_back(defaultTexture);
}

void Scene::render(Camera* camera){
    int objSize = renderableObjects.size();
    int shaderSize = shaders.size();

    for(int i = 0; i < shaderSize; i++){
        Shader* s = &shaders.at(i);
        s->use();
        for(int j = 0; j < objSize; j++){
            FJ_Object* o = &renderableObjects.at(j);
            Mesh* m = &meshes.at(o->meshId);
            Texture* t = &textures.at(m->textureId);

            glBindVertexArray(m->vao);
            glBindTexture(GL_TEXTURE_2D, t->texID);
            s->loadUniformMat4("viewMat", camera->viewMatrix * o->modelMatrix);
            glDrawArrays(GL_TRIANGLES, 0, (m->vertexCount / 3));
        }
    }
}

void Scene::addMeshToObject(FJ_Object *&obj, Mesh *m){
    obj->meshId = m->id;

    renderableObjects.push_back(objects.at(obj->id));
    objects.erase(objects.begin() + obj->id);
    obj = &renderableObjects.at(renderableObjects.size() - 1);
    obj->id = renderableObjects.size() - 1;
}

void Scene::addTextureToMesh(Mesh* m, Texture *t, float* coords, int count){
    m->addTextureCoordinates(coords, count);
    m->textureId = t->id;
}

void Scene::attatchShaderToObject(FJ_Object *obj, Shader *shdr){
    obj->shaderId = shdr->loc;
}


FJ_Object* Scene::createObject(){
    FJ_Object obj;
    obj.id = objects.size();
    objects.push_back(obj);
    return &objects.at(objects.size() - 1);
}

Shader* Scene::createShader(){
    Shader s;
    s.loc = shaders.size();
    shaders.push_back(s);
    return &shaders.at(shaders.size() - 1);
}

Mesh* Scene::createMesh(float* verts, int vertCount){
    Mesh m(verts, vertCount);
    m.id = meshes.size();
    m.textureId = defaultTexture.id;
    meshes.push_back(m);
    return &meshes.at(meshes.size() - 1);
}

Texture *Scene::createTexture(){
    Texture t;
    t.id = textures.size();
    textures.push_back(t);
    return &textures.at(textures.size() - 1);
}
