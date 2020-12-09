//
// Created by Administrator on 07/10/2020.
//

#include "RunTimeClock.h"
#include <string>
#include <sstream>

RunTimeClock::RunTimeClock() = default;

RunTimeClock::~RunTimeClock() = default;

void RunTimeClock::addMilliseconds(int ms) {
    milliseconds += ms;
    if(milliseconds >= 1000){
        addSeconds(1);
        milliseconds -= 1000;
    }

}

void RunTimeClock::addSeconds(int s) {
    seconds += s;
    if(seconds == 60){
        addMinutes(1);
        seconds = 0;
    }
}

void RunTimeClock::addMinutes(int m) {
    minutes += m;
    if(minutes == 60){
        addHours(1);
        minutes = 0;
    }
}

void RunTimeClock::addHours(int h) {
    hours += h;
}

std::string RunTimeClock::toString() const {
    std::ostringstream oss;
    oss << " Run time: " << hours << ":" << minutes << ":" << seconds << ":" << milliseconds;

    return oss.str();
}

