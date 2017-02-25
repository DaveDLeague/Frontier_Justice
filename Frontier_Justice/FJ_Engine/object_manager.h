#pragma once

#include <vector>
#include <map>

struct GameObject{

};

class ObjectManager
{
public:
    ObjectManager();

    static GameObject *createObject();

private:
    static std::vector<GameObject> objectList;
    static std::vector<std::vector<GameObject>> sceneObjectList;
};

