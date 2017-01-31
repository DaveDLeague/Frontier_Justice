#include "game_time.h"

#include <time.h>

Time::Time(){

}

void Time::setDeltaTime(double d){
    if(d){}
}

long Time::currentTime(){
    return clock();
}

double Time::deltaTime(){

    return 0.0;
}
