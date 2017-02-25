#pragma once

#include <string>
#include <vector>

#include "input_manager.h"
#include "scene_manager.h"
#include "object_manager.h"
#include "component_manager.h"

#include "fj_math.h"

#include "Render_Engine/game_window.h"
#include "Render_Engine/shader.h"
#include "Render_Engine/camera.h"

using namespace std;

class FJEngine
{
public:

    static bool init();
    static void update();
    static void shutdown();
    static GameWindow *createGameWindow(string title, int x, int y, int w, int h);

private:
    FJEngine();
    static vector<GameWindow> windows;
};

