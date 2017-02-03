#include "game.h"

#include "input_manager.h"
#include "SDL2/SDL.h"

#include "mesh_manager.h"
#include "shader.h"

Shader *s;

Game::Game(){
    s = new Shader("../shaders/flat_vs.glsl", "../shaders/flat_fs.glsl");

    Vertex data[3];
    data[0].position = Vec3f(-1, -1, 0);
    data[1].position = Vec3f(0, 1, 0);
    data[2].position = Vec3f(1, -1, 0);
    Mesh *m = MeshManager::generateMesh(data, 3);
    if(m->size){}
}

void Game::input(){

    if(InputManager::getMouseButtonDown(SDL_BUTTON_LEFT)){
        GameMath::printVec(InputManager::getMouseCursorLocation());
        printf("\n");
    }
}

void Game::update(){

}

void Game::render(){
    s->useProgram();
    MeshManager::renderMeshes();
}
