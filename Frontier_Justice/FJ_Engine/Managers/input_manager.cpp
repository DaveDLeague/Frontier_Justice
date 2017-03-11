#include "input_manager.h"

bool InputManager::keys[TOTAL_KEYS];
bool InputManager::mouseButtons[TOTAL_MOUSE_BUTTONS];
int InputManager::mouseCursorX;
int InputManager::mouseCursorY;

InputManager::InputManager(){

}

void InputManager::update(){
    SDL_Event e;
    while(SDL_PollEvent(&e)){
        switch(e.type){
        case SDL_KEYDOWN:{
            keys[e.key.keysym.scancode] = true;
            break;
        }
        case SDL_KEYUP:{
            keys[e.key.keysym.scancode] = false;
            break;
        }
        case SDL_MOUSEMOTION:{
            SDL_GetMouseState(&mouseCursorX, &mouseCursorY);
            break;
        }
        case SDL_MOUSEBUTTONDOWN:{
            mouseButtons[e.button.button] = true;
            break;
        }
        case SDL_MOUSEBUTTONUP:{
            mouseButtons[e.button.button] = false;
            break;
        }
        }
    }
}

