#pragma once

#include <string>
#include <vector>

#include "fj_input_manager.h"
#include "fj_math.h"

#include "fj_object.h"
#include "fj_scene.h"

#include "Render_Engine/game_window.h"
#include "Render_Engine/shader.h"
#include "Render_Engine/camera.h"
#include "Render_Engine/mesh.h"
#include "Render_Engine/texture.h"

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

