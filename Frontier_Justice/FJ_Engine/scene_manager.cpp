#include "scene_manager.h"

std::vector<GameScene> SceneManager::scenes;

GameScene::GameScene(){

}

void GameScene::render(){

}

void GameScene::addObject(GameObject *obj){

}

SceneManager::SceneManager(){

}

GameScene *SceneManager::createScene(){
    GameScene s;
    scenes.push_back(s);
    return &scenes[scenes.size() - 1];
}
