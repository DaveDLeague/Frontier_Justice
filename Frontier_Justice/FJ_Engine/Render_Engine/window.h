#pragma once

class GameWindow
{
public:
    GameWindow(const char* title, int locX, int locY, int width, int height);

    static bool init();

    void update();
    void shutdown();
    void setFullScreen(bool b);
    void setVSync(bool b);
    inline int getWidth(){ return width; }
    inline int getHeight(){ return height; }

private:
    static bool initialized;
    bool fullScreen;
    int width;
    int height;
};
