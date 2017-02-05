#include "mesh_manager.h"

std::vector<Mesh> MeshManager::meshes;

MeshManager::MeshManager(){

}

Mesh* MeshManager::generateMesh(){
    Mesh m;
    glGenBuffers(1, &m.vbo);
    m.size = 0;
    meshes.push_back(m);
    return &meshes.at(meshes.size() - 1);
}

Mesh* MeshManager::generateMesh(Vertex *verts, int size){
    Mesh m;
    glGenBuffers(1, &m.vbo);
    addVertsToMesh(m, verts, size);
    meshes.push_back(m);
    return &meshes.at(meshes.size() - 1);
}

void MeshManager::addVertsToMesh(Mesh &mesh, Vertex *verts, int size){
    GLfloat *f = new float[size * 3];

    int ctr = 0;
    for(int i = 0; i < size; i++){
        f[ctr++] = verts[i].position.x;
        f[ctr++] = verts[i].position.y;
        f[ctr++] = verts[i].position.z;
    }

    mesh.size = size;
    glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * size * 3, f, GL_STATIC_DRAW);

    delete(f);

}

void MeshManager::renderMeshes(){
    int len = meshes.size();

    for(int i = 0; i < len; i++){
        Mesh *m = &meshes.at(i);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, m->vbo);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 3, (GLvoid*)0);

        glDrawArrays(GL_TRIANGLES, 0, m->size);

        glDisableVertexAttribArray(0);
    }
}

