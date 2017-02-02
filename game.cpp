#include "game.h"

#include "input_manager.h"
#include "SDL2/SDL.h"
Game::Game(){

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

}
