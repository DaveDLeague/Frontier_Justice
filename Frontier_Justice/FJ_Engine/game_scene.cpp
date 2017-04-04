#include "game_scene.h"

unsigned char greyTex[] = {200, 200, 200};

Scene::Scene(){
    renderers.reserve(4);
}

void Scene::render(){
    int sz = renderers.size();

    for(int i = 0; i < sz; i++){
        renderers[i].render(objectManager.getPointerToObjects(), camera);
    }
}

void Scene::update(){
    objectManager.updateModelMatrices();
}

Renderer* Scene::createRenderer(){
    Renderer r;
    r.id = renderers.size();
    renderers.push_back(r);
    return &renderers[renderers.size() - 1];
}

GameObject* Scene::createObject(){
    return objectManager.createObject();
}

Mesh* Scene::createMesh(){
    return meshManager.createMesh();
}

Texture* Scene::createTexture(){
    return textureManager.createTexture();
}

void Scene::attachRenderer(GameObject*& g1, Renderer*& r){
    g1->rendererId = r->id;
    r->totalObjects++;
    objectManager.sortObjects();

    for(int i = r->id + 1; i < renderers.size(); i++){
        renderers[i].startingIndex++;
    }
}
