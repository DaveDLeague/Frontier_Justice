#include <iostream>

#include "game_window.h"
#include "frontier_justice.h"

int main(int argc, char *argv[])
{
    GameWindow::createWindow(800, 600, "Frontier Justice");

    FrontierJustice fj;
    fj.start();

    return 0;
}
