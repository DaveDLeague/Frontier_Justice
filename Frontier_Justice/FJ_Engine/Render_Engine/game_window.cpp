#include "game_window.h"

#include <SDL2/SDL.h>
#include <GL/glew.h>

SDL_Window *window;
SDL_GLContext context;

GameWindow::GameWindow(const char* title, int locX, int locY, int width, int height){
    fullScreen = false;
    window = SDL_CreateWindow(title, locX, locY, width, height, SDL_WINDOW_OPENGL);
    if (!window) {
        printf("ERROR Creating Game Window:\n%s\n", SDL_GetError());
        return;
    }

    context = SDL_GL_CreateContext(window);
    if(!context){
        printf("ERROR Creating OpenGL Context:\n%s\n", SDL_GetError());
        return;
    }

    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (GLEW_OK != err){
      printf("ERROR Initializing GLEW\n%s\n", glewGetErrorString(err));
      return;
    }
    printf("Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

    glClearColor(0, 0, 0.5, 1);
}

bool GameWindow::init(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

void GameWindow::update(){
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(window);
}

void GameWindow::shutdown(){
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
}

void GameWindow::toggleFullScreen(){
    fullScreen = !fullScreen;

    if(fullScreen){
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    }else{
        SDL_SetWindowFullscreen(window, 0);
    }

}
