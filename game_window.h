#pragma once

class GameWindow
{
public:
    GameWindow();

    static void createWindow(int width, int height, char* title);
    static void render();
    static void update();
    static void dispose();
    static bool isCloseRequested();
};

