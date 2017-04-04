#pragma once

#include <vector>

#include "../game_object.h"
#include "../Render_Engine/renderer.h"

using namespace std;

class ObjectManager{
public:
    ObjectManager();
    GameObject* createObject();
    GameObject* getPointerToObjects();
    void deleteObject(GameObject* obj);
    void sortObjects();
    void updateModelMatrices();

private:
    vector<GameObject> objects;
};

