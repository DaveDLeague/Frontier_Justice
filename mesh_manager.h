#pragma once

#include <vector>

#include <GL/glew.h>

#include "game_math.h"

struct Vertex{
   Vec3f position;
};

struct Mesh{
    GLuint vbo;
    int size;
};

class MeshManager
{
public:
    static Mesh* generateMesh();
    static Mesh* generateMesh(Vertex *verts, int size);
    static void addVertsToMesh(Mesh &mesh, Vertex *verts, int size);
    static void renderMeshes();

private:
    MeshManager();
    static std::vector<Mesh> meshes;

};

