#include "fj_scene.h"

Scene::Scene(){

}


void Scene::render(Camera* camera){
    int meshSize = meshes.size();
    int shaderSize = shaders.size();

    for(int i = 0; i < shaderSize; i++){
        Shader* s = &shaders.at(i);
        s->use();
        for(int j = 0; j < meshSize; j++){
            Mesh* mesh = &meshes.at(j);
            glBindVertexArray(mesh->vao);
            s->loadUniformMat4("viewMat", camera->viewMatrix * mesh->parent->modelMatrix);
            glDrawArrays(GL_TRIANGLES, 0, (mesh->vertexCount / 3));
        }
    }
}

void Scene::addMeshToObject(FJ_Object* obj, float* verts, int vertCount){
    Mesh m(verts, vertCount);
    obj->meshId = meshes.size();
    m.parent = obj;
    meshes.push_back(m);
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
