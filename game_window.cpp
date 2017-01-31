#include "game_window.h"

#include <SDL2/SDL.h>

static SDL_Window* window;
static SDL_GLContext context;
static SDL_Event event;

GameWindow::GameWindow()
{


}

void GameWindow::createWindow(int width, int height, char* title){
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(title, 0, 0, width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
    context = SDL_GL_CreateContext(window);

}

void GameWindow::render(){

}

void GameWindow::dispose(){
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool GameWindow::isCloseRequested(){
    if(SDL_PollEvent(&event)){
        if(event.window.event == SDL_WINDOWEVENT_CLOSE){
            return true;
        }
        else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
            return true;
        }
    }

    return false;
}
