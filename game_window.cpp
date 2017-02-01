#include "game_window.h"

#include <SDL2/SDL.h>

#include "input_manager.h"

static SDL_Window* window;
static SDL_GLContext context;
static SDL_Event event;

GameWindow::GameWindow(){

}

void GameWindow::createWindow(int width, int height, char* title){
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(title, 0, 0, width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
    context = SDL_GL_CreateContext(window);

    InputManager::init();
}

void GameWindow::render(){
    SDL_GL_SwapWindow(window);
}

void GameWindow::update(){
    while(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_WINDOWEVENT:{

            break;
        }
        case SDL_KEYDOWN:
        case SDL_KEYUP:
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
        case SDL_MOUSEMOTION:
        case SDL_MOUSEWHEEL:{
            InputManager::update(event.type);
            break;
        }
        }
    }

    SDL_PumpEvents();
}

void GameWindow::dispose(){
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool GameWindow::isCloseRequested(){
    if(event.window.event == SDL_WINDOWEVENT_CLOSE){
        return true;
    }
    else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
        return true;
    }

    return false;
}
