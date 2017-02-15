#include "frontier_justice.h"

FrontierJustice::FrontierJustice(){

}

bool FrontierJustice::init(){
    if(!FJEngine::init()){
        return false;
    }

    return true;
}

void FrontierJustice::start(){
    GameWindow *window = FJEngine::createGameWindow("Frontier Justice" , 0, 0, 800, 600);
    window->toggleFullScreen();

    int ctr = 0;
    bool quit = false;
    while(!quit){


        FJEngine::update();
        window->update();
    }
}
