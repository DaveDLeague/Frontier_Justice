#pragma once

#include <string>
#include <vector>

#include "Managers/input_manager.h"
#include "Managers/mesh_manager.h"
#include "Managers/object_manager.h"
#include "Managers/texture_manager.h"

#include "math_util.h"

#include "game_object.h"
#include "game_scene.h"

#include "Render_Engine/camera.h"
#include "Render_Engine/mesh.h"
#include "Render_Engine/renderer.h"
#include "Render_Engine/shader.h"
#include "Render_Engine/texture.h"
#include "Render_Engine/window.h"

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

