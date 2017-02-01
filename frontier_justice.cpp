#include "frontier_justice.h"

#include <SDL2/SDL.h>

#include "input_manager.h"

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

    const double frameTime = 1.0 / 5000.0;

    long endTime = Time::currentTime();
    double waitTime = 0;

    while(isRunning){
        bool renderFrame = false;

        long startTime = Time::currentTime();
        long elapsedTime = startTime - endTime;
        endTime = startTime;

        waitTime += elapsedTime / (double)Time::SECOND;
        frameCtr += elapsedTime;

        while(waitTime > frameTime){
            renderFrame = true;
            waitTime -= frameTime;

            if(GameWindow::isCloseRequested()){
                stop();
            }

            Time::setDeltaTime(frameTime);

            GameWindow::update();
            InputManager::update();
            game.input();
            game.update();

            if(frameCtr >= Time::SECOND){
                //printf("%i\n", numFrames);

                numFrames = 0;
                frameCtr = 0;
            }
        }

        if(renderFrame){
            render();
            numFrames++;
        }else{
            SDL_Delay(1);
        }
    }
    clean();
}

void FrontierJustice::render(){
    game.render();
    GameWindow::render();
}

void FrontierJustice::clean(){
    GameWindow::dispose();
}
