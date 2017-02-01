#include "input_manager.h"

#include <SDL2/SDL.h>

InputManager::InputManager(){

}

void InputManager::init(){
    SDL_Init(SDL_INIT_GAMECONTROLLER);
}

void InputManager::update(int event){

}

bool InputManager::getKeyUp(int key){
    const Uint8 *keys = SDL_GetKeyboardState(NULL);
    return keys[key];
}

bool InputManager::getKeyDown(int key){
    const Uint8  *keys = SDL_GetKeyboardState(NULL);
    return keys[key];
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
