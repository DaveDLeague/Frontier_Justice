#include "object_manager.h"

bool operator<(const GameObject& o1, const GameObject& o2){
    return o1.rendererId < o2.rendererId;
}

ObjectManager::ObjectManager(){

}

GameObject *ObjectManager::createObject(){
    GameObject obj;
    obj.id = objects.size();
    objects.push_back(obj);
    return &objects[objects.size() - 1];
}

GameObject *ObjectManager::getPointerToObjects(){
    return &objects[0];
}

void ObjectManager::deleteObject(GameObject *obj){
    objects.erase(objects.begin() + obj->id);
}

void ObjectManager::sortObjects(){
    sort(objects.begin(), objects.end(), less<GameObject>());
}

void ObjectManager::updateModelMatrices(){
    int sz = objects.size();
    quat qyaw;
    quat qpitch;
    quat qroll;
    for(int i = 0; i < sz; i++){
        objects[i].modelMatrix = mat4(1);

        qyaw = angleAxis(objects[i].rotation.y, vec3(0, 1, 0));
        qpitch = angleAxis(objects[i].rotation.x, vec3(1, 0, 0));
        qroll = angleAxis(objects[i].rotation.z, vec3(0, 0, 1));
        objects[i].rotQuat = qroll * qyaw * qpitch * objects[i].rotQuat;
        objects[i].modelMatrix = translate(objects[i].modelMatrix, objects[i].position);
        objects[i].modelMatrix = objects[i].modelMatrix * mat4_cast(objects[i].rotQuat);
        objects[i].modelMatrix = scale(objects[i].modelMatrix, objects[i].scale);
    }

}
