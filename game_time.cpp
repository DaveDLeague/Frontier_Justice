#include "game_time.h"

#include <chrono>

using namespace std::chrono;

Time::Time(){

}

void Time::setDeltaTime(double d){
    if(d){}
}

long Time::currentTime(){
    auto t = high_resolution_clock::now();
    return duration_cast<nanoseconds>(t.time_since_epoch()).count();
}

double Time::deltaTime(){

    return 0.0;
}
