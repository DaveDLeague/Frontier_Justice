#pragma once

#include <SDL2/SDL.h>

class InputManager
{
public:
    static const int ESC_KEY = SDL_SCANCODE_ESCAPE;
    static const int ENTER_KEY = SDL_SCANCODE_RETURN;

    static const int UP_KEY = SDL_SCANCODE_UP;
    static const int DOWN_KEY = SDL_SCANCODE_DOWN;
    static const int LEFT_KEY = SDL_SCANCODE_LEFT;
    static const int RIGHT_KEY = SDL_SCANCODE_RIGHT;

    static const int A_KEY = SDL_SCANCODE_A;
    static const int D_KEY = SDL_SCANCODE_D;
    static const int E_KEY = SDL_SCANCODE_E;
    static const int F_KEY = SDL_SCANCODE_F;
    static const int Q_KEY = SDL_SCANCODE_Q;
    static const int R_KEY = SDL_SCANCODE_R;
    static const int S_KEY = SDL_SCANCODE_S;
    static const int W_KEY = SDL_SCANCODE_W;

    static const int LEFT_MOUSE_BUTTON = SDL_BUTTON_LEFT;
    static const int RIGHT_MOUSE_BUTTON = SDL_BUTTON_RIGHT;
    static const int MIDDLE_MOUSE_BUTTON = SDL_BUTTON_MIDDLE;

    static const int TOTAL_KEYS = 256;
    static const int TOTAL_MOUSE_BUTTONS = 5;

    static bool keys[TOTAL_KEYS];
    static bool mouseButtons[TOTAL_MOUSE_BUTTONS];

    static int mouseCursorX;
    static int mouseCursorY;

    InputManager();

    static void update();

private:
};
