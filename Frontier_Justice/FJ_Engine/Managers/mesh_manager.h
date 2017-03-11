#pragma once

#include "../Render_Engine/mesh.h"

#include <vector>

using namespace std;

class MeshManager{
public:
    MeshManager();
    Mesh* createMesh();
    void deleteMesh(Mesh* m);

private:
    vector<Mesh> meshes;
};

