#pragma once

#include <vector>

#include "object_manager.h"

struct GameScene{
public:
    GameScene();
    void addObject(GameObject *obj);
    void render();

private:
    GameObject *objects;
};

class SceneManager
{
public:
    SceneManager();

    static GameScene* createScene();

private:
    static std::vector<GameScene> scenes;
};

