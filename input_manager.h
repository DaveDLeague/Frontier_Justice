#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "game_math.h"

class InputManager
{
public:
    InputManager();

    static void init();
    static void update(int event);
    static bool getKeyUp(int key);
    static bool getKeyDown(int key);
    static bool getMouseClick();
    static bool getMouseButtonDown(int button);
    static bool getMouseButtonUp(int button);
    static Vec2f getMouseCursorLocation();


};

#endif // INPUT_MANAGER_H
