#include "input_manager.h"

#include <vector>
#include <algorithm>

#include <SDL2/SDL.h>

static const int TOTAL_KEYS = 256;
static const int TOTAL_MOUSE_STATES = 5;

static std::vector<int> activeKeys;
static std::vector<int> keysUp;
static std::vector<int> keysDown;

static std::vector<int> activeMouse;
static std::vector<int> mouseUp;
static std::vector<int> mouseDown;

bool contains(const std::vector<int> *vec, int v){
    for(unsigned int i = 0; i < vec->size(); i++){
        if(vec->at(i) == v){
            return true;
        }
    }
    return false;
}

InputManager::InputManager(){

}

void InputManager::init(){
    SDL_Init(SDL_INIT_GAMECONTROLLER);
}

void InputManager::update(){
    mouseUp.clear();
    for(int i = 0; i < TOTAL_MOUSE_STATES; i++){
        if(!getMouseClick(i) && contains(&activeMouse, i)){
            mouseUp.push_back(i);
        }
    }

    mouseDown.clear();
    for(int i = 0; i < TOTAL_MOUSE_STATES; i++){
        if(getMouseClick(i) && !contains(&activeMouse, i)){
            mouseDown.push_back(i);
        }
    }

    keysUp.clear();
    for(int i = 0; i < TOTAL_KEYS; i++){
        if(!getKey(i) && contains(&activeKeys, i)){
            keysUp.push_back(i);
        }
    }

    keysDown.clear();
    for(int i = 0; i < TOTAL_KEYS; i++){
        if(getKey(i) && !contains(&activeKeys, i)){
            keysDown.push_back(i);
        }
    }

    activeKeys.clear();
    for(int i = 0; i < TOTAL_KEYS; i++){
        if(getKey(i)){
            activeKeys.push_back(i);
        }
    }

    activeMouse.clear();
    for(int i = 0; i < TOTAL_MOUSE_STATES; i++){
        if(getMouseClick(i)){
            activeMouse.push_back(i);
        }
    }
}

bool InputManager::getKey(unsigned int key){
    const Uint8 *keys = SDL_GetKeyboardState(NULL);
    return keys[key];
}

bool InputManager::getKeyUp(unsigned int key){
    return contains(&keysUp, key);
}

bool InputManager::getKeyDown(unsigned int key){
    return contains(&keysDown, key);
}

bool InputManager::getMouseClick(unsigned int button){
    return button == SDL_GetMouseState(NULL, NULL);
}

bool InputManager::getMouseButtonDown(unsigned int button){
    return contains(&mouseDown, button);
}

bool InputManager::getMouseButtonUp(unsigned int button){
    return contains(&mouseUp, button);
}

Vec2i InputManager::getMouseCursorLocation(){
    Vec2i pos;
    SDL_GetMouseState(&pos.x, &pos.y);
    return pos;
}
