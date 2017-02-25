#include "object_manager.h"

std::vector<GameObject> ObjectManager::objectList;

ObjectManager::ObjectManager(){

}

GameObject *ObjectManager::createObject(){
    objectList.push_back(GameObject());

    return &objectList.at(objectList.size() - 1);
}
