#include "frontier_justice.h"

#include <SDL2/SDL.h>

FrontierJustice::FrontierJustice(){
    isRunning = false;
}

void FrontierJustice::start(){
    run();
}

void FrontierJustice::stop(){
    if(!isRunning){
        return;
    }

    isRunning = false;
}

void FrontierJustice::run(){
    isRunning = true;

    int numFrames = 0;
    long frameCtr = 0;

    const double frameTime = 1.0 / 10000;

    long endTime = Time::currentTime();
    double waitTime = 0;

    while(isRunning){
        bool renderFrame = false;

        long startTime = Time::currentTime();
        long elapsedTime = startTime - endTime;
        endTime = startTime;

        waitTime += elapsedTime / (double)Time::SECOND;
        frameCtr += elapsedTime;

        printf("%lu\n", frameCtr);

        while(waitTime > frameTime){
            renderFrame = true;
            waitTime -= frameTime;

            game.input();
            game.update();

            if(frameCtr >= Time::SECOND){
                printf("%lu\n", frameCtr);

                numFrames = 0;
                frameCtr = 0;
            }
        }

        if(renderFrame){
            render();

            numFrames++;
        }else{
            //SDL_Delay(1);
        }

        if(GameWindow::isCloseRequested()){
            stop();
        }
    }
    clean();
}

void FrontierJustice::render(){
    game.render();
}

void FrontierJustice::clean(){
    GameWindow::dispose();
}
