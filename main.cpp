#include <iostream>

#include "game_window.h"
#include "frontier_justice.h"

int main(int argc, char *argv[])
{
    char* title;
    argc > 1 ? title = argv[1] : title = "Frontier Justice\0";

    GameWindow::createWindow(800, 600, title);

    FrontierJustice fj;
    fj.start();

    return 0;
}
