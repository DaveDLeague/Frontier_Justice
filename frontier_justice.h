#pragma once

#include "game.h"
#include "game_window.h"
#include "game_time.h"

class FrontierJustice
{
public:
    FrontierJustice();

    void start();
    void stop();

private:
    Game game;

    bool isRunning;

    void run();
    void clean();
    void render();
};


