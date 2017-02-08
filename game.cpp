#include "game.h"

#include "input_manager.h"
#include "SDL2/SDL.h"

#include "mesh_manager.h"
#include "shader.h"
#include "game_math.h"

Shader s;
int loc;
Mat4f mat;

float val = 0.0;

Game::Game(){
    s.createProgram("../shaders/flat_vs.glsl", "../shaders/flat_fs.glsl");
    loc = s.getUniformLocation("m");

    mat = GameMath::createIdentityMatrix();


    Vertex data[6];
    data[0].position = Vec3f(-1, -1, 0);
    data[1].position = Vec3f(-1, 1, 0);
    data[2].position = Vec3f(1, 1, 0);
    data[3].position = Vec3f(1, 1, 0);
    data[4].position = Vec3f(1, -1, 0);
    data[5].position = Vec3f(-1, -1, 0);
    Mesh *m = MeshManager::generateMesh(data, 6);
}

void Game::input(){

    if(InputManager::getMouseButtonDown(SDL_BUTTON_LEFT)){
        GameMath::scale(mat, Vec3f(0.5, 0.5, 1));
    }
    if(InputManager::getMouseButtonDown(SDL_BUTTON_X1)){
        GameMath::scale(mat, Vec3f(2, 2, 1));
    }
}

void Game::update(){

}

Quaternion q;

void Game::render(){


    GameMath::rotate(q, Vec3f(1, 1, 1), val);
    val += 0.001;
    GameMath::quaternionToMatrix(mat, q);
    //mat.matrix[0][0] = 0.5;
    //mat.matrix[1][1] = 0.5;

    s.useProgram();
    s.setUniformMat4(loc, mat);
    MeshManager::renderMeshes();
}
