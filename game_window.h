#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H


class GameWindow
{
public:
    GameWindow();

    static void createWindow(int width, int height, char* title);
    static void render();
    static void dispose();
    static bool isCloseRequested();
};

#endif // GAMEWINDOW_H
