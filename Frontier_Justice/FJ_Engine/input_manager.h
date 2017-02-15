#pragma once

#include <SDL2/SDL.h>

class InputManager
{
public:
    static const int ESC_KEY = SDL_SCANCODE_ESCAPE;
    static const int ENTER_KEY = SDL_SCANCODE_RETURN;

    static const int TOTAL_KEYS = 256;

    static bool keys[TOTAL_KEYS];

    static int mouseCursorX;
    static int mouseCursorY;

    InputManager();

    static void update();

private:
};
