#include "input_manager.h"

#include <SDL2/SDL.h>

InputManager::InputManager(){

}

void InputManager::init(){
    SDL_Init(SDL_INIT_GAMECONTROLLER);
}

void InputManager::update(){

}

bool InputManager::getKeyUp(int key){
    return false;
}

bool InputManager::getKeyDown(int key){
    return false;
}

bool InputManager::getMouseClick(){
    return false;
}

bool InputManager::getMouseButtonDown(int button){
    return false;
}

bool InputManager::getMouseButtonUp(int button){
    return false;
}

Vec2f InputManager::getMouseCursorLocation(){
    return Vec2f();
}
