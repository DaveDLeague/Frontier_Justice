#pragma once


class Time
{
public:
    static const long SECOND = 1000000000L;

    Time();
    static void setDeltaTime(double d);
    static long currentTime();
    static double deltaTime();

private:
};

