#include "mesh_manager.h"

MeshManager::MeshManager(){

}

Mesh* MeshManager::createMesh(){
    Mesh m;
    m.id = meshes.size();
    meshes.push_back(m);
    return &meshes[meshes.size() - 1];
}

void MeshManager::deleteMesh(Mesh* m){
    meshes.erase(meshes.begin() + m->id);
}
