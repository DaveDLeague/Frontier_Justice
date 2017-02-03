#include "input_manager.h"

#include <vector>
#include <algorithm>

#include <SDL2/SDL.h>

static const int TOTAL_KEYS = 256;
static const int TOTAL_MOUSE_STATES = 5;

static std::vector<int> activeKeys;
static std::vector<int> activeMouse;

static bool contains(const std::vector<int> &vec, int v){
    for(unsigned int i = 0; i < vec.size(); i++){
        if(vec[i] == v){
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
    return !getKey(key) && contains(activeKeys, key);
}

bool InputManager::getKeyDown(unsigned int key){
    return getKey(key) && !contains(activeKeys, key);
}

bool InputManager::getMouseClick(unsigned int button){
    return button == SDL_GetMouseState(NULL, NULL);
}

bool InputManager::getMouseButtonDown(unsigned int button){
    return getMouseClick(button) && !contains(activeMouse, button);
}

bool InputManager::getMouseButtonUp(unsigned int button){
    return !getMouseClick(button) && contains(activeMouse, button);
}

Vec2f InputManager::getMouseCursorLocation(){
    Vec2f pos;
    int x, y;
    SDL_GetMouseState(&x, &y);
    pos.x = x; pos.y = y;
    return pos;
}
