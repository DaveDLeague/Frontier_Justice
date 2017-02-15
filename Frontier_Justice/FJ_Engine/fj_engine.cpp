#include "fj_engine.h"

#include <SDL2/SDL.h>

vector<GameWindow> FJEngine::windows;

FJEngine::FJEngine(){

}

bool FJEngine::init(){
    if(!GameWindow::init()){
        printf("Error initializing Game Window");
        return false;
    }

    return true;
}

void FJEngine::update(){
    InputManager::update();
}

void FJEngine::shutdown(){
    int size = windows.size();
    for(int i = 0; i < size; i++){
        windows[i].shutdown();
    }

    SDL_Quit();
}

GameWindow *FJEngine::createGameWindow(string title, int x, int y, int w, int h){
    windows.push_back(GameWindow(title.c_str(), x, y, w, h));
    return &windows[windows.size() - 1];
}


