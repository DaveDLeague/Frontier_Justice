#include "input_manager.h"

static const float AXIS_MIN = -32768.0f;
static const float AXIS_MAX = 32767.0f;

bool InputManager::keys[TOTAL_KEYS];
bool InputManager::mouseButtons[TOTAL_MOUSE_BUTTONS];
bool InputManager::controller1Buttons[TOTAL_CONTROLLER_BUTTONS];
bool InputManager::controller2Buttons[TOTAL_CONTROLLER_BUTTONS];
float InputManager::controller1Axes[TOTAL_CONTROLLER_AXES];
float InputManager::controller2Axes[TOTAL_CONTROLLER_AXES];
int InputManager::mouseCursorX;
int InputManager::mouseCursorY;

SDL_GameController* InputManager::controller1;
SDL_GameController* InputManager::controller2;

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
        case SDL_CONTROLLERBUTTONDOWN:{
            if(e.cbutton.which == 0){
                controller1Buttons[e.cbutton.button] = true;
            }else{
                controller2Buttons[e.cbutton.button] = true;
            }
            break;
        }
        case SDL_CONTROLLERBUTTONUP:{
            if(e.cbutton.which == 0){
                controller1Buttons[e.cbutton.button] = false;
            }else{
                controller2Buttons[e.cbutton.button] = false;
            }
            break;
        }
        case SDL_CONTROLLERAXISMOTION:{
            if(e.cbutton.which == 0){
                controller1Axes[e.caxis.axis] = e.caxis.value / AXIS_MAX;
            }else{
                controller2Axes[e.caxis.axis] = e.caxis.value / AXIS_MAX;
            }
            break;
        }
        }
    }
}

void InputManager::initGameControllers(){
    SDL_Init(SDL_INIT_GAMECONTROLLER);

    for(int i = 0; i < SDL_NumJoysticks(); i++){
        if(SDL_IsGameController(i)){
            if(controller1 == NULL){
                controller1 = SDL_GameControllerOpen(i);
            }else if(controller2 == NULL){
                controller2 = SDL_GameControllerOpen(i);
            }else{
                break;
            }
        }
    }
}

void InputManager::cleanUp(){
    if(controller1 != NULL){ SDL_GameControllerClose(controller1); }
    if(controller2 != NULL){ SDL_GameControllerClose(controller2); }
}

