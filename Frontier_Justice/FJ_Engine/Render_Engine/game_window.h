#pragma once

class GameWindow
{
public:
    GameWindow(const char* title, int locX, int locY, int width, int height);

    static bool init();

    void update();
    void shutdown();
    void toggleFullScreen();

private:
    bool fullScreen;
};
