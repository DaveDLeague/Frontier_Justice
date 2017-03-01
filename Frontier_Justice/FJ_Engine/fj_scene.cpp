#include "fj_scene.h"

unsigned char greyTex[] = {200, 200, 200};

Scene::Scene(){
    shaders.reserve(8);
    objects.reserve(256);
    renderableObjects.reserve(128);
    meshes.reserve(64);

    defaultTexture.loadData(greyTex, 1, 1, true);
    defaultTexture.id = textures.size();
    textures.push_back(defaultTexture);
}

void Scene::render(Camera* camera){
    int objSize = renderableObjects.size();
    int shaderSize = shaders.size();

    for(int i = 0; i < shaderSize; i++){
        Shader* s = &shaders[i];
        s->use();
        for(int j = 0; j < objSize; j++){
            FJ_Object* o = &renderableObjects[j];
            Mesh* m = &meshes[o->meshId];
            Texture* t = &textures[m->textureId];

            glBindVertexArray(m->vao);
            glBindTexture(GL_TEXTURE_2D, t->texID);
            s->loadUniformMat4("viewMat", camera->viewMatrix);
            s->loadUniformMat4("modelMat", o->modelMatrix);
            glDrawArrays(GL_TRIANGLES, 0, (m->vertexCount / 3));
        }
    }
}

void Scene::update(){
    int objSz = objects.size();
    int renObjSz = renderableObjects.size();

    quat qyaw;
    quat qpitch;
    quat qroll;

    for(int i = 0; i < objSz; i++){
        FJ_Object* obj = &objects[i];
        obj->modelMatrix = mat4(1);

        qyaw = angleAxis(obj->rotation.y, vec3(0, 1, 0));
        qpitch = angleAxis(obj->rotation.x, vec3(1, 0, 0));
        qroll = angleAxis(obj->rotation.z, vec3(0, 0, 1));
        obj->rotQuat = qroll * qyaw * qpitch * obj->rotQuat;
        obj->modelMatrix = translate(obj->modelMatrix, obj->position);
        obj->modelMatrix = obj->modelMatrix * mat4_cast(obj->rotQuat);
        obj->modelMatrix = scale(obj->modelMatrix, obj->scale);    
    }

    for(int i = 0; i < renObjSz; i++){
        FJ_Object* obj = &renderableObjects[i];
        obj->modelMatrix = mat4(1);

        qyaw = angleAxis(obj->rotation.y, vec3(0, 1, 0));
        qpitch = angleAxis(obj->rotation.x, vec3(1, 0, 0));
        qroll = angleAxis(obj->rotation.z, vec3(0, 0, 1));
        obj->rotQuat = qroll * qyaw * qpitch * obj->rotQuat;
        obj->modelMatrix = translate(obj->modelMatrix, obj->position);
        obj->modelMatrix = obj->modelMatrix * mat4_cast(obj->rotQuat);
        obj->modelMatrix = scale(obj->modelMatrix, obj->scale);
    }
}

void Scene::addMeshToObject(FJ_Object *&obj, Mesh *m){
    obj->meshId = m->id;

    renderableObjects.push_back(objects.at(obj->id));
    objects.erase(objects.begin() + obj->id);
    obj = &renderableObjects[renderableObjects.size() - 1];
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
    return &objects[objects.size() - 1];
}

Shader* Scene::createShader(){
    Shader s;
    s.loc = shaders.size();
    shaders.push_back(s);
    return &shaders[shaders.size() - 1];
}

Mesh* Scene::createMesh(float* verts, int vertCount){
    Mesh m(verts, vertCount);
    m.id = meshes.size();
    m.textureId = defaultTexture.id;
    meshes.push_back(m);
    return &meshes[meshes.size() - 1];
}

Texture *Scene::createTexture(){
    Texture t;
    t.id = textures.size();
    textures.push_back(t);
    return &textures[textures.size() - 1];
}
