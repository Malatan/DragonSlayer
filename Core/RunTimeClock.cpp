//
// Created by Administrator on 07/10/2020.
//

#include "RunTimeClock.h"
#include <string>
#include <sstream>

RunTimeClock::RunTimeClock() {
    this->milliseconds = 0;
    this->seconds = 0;
    this->minutes = 0;
    this->hours = 0;

}

RunTimeClock::~RunTimeClock() {

}

void RunTimeClock::addMilliseconds(int ms) {
    this->milliseconds += ms;
    if(this->milliseconds >= 1000){
        this->addSeconds(1);
        this->milliseconds -= 1000;
    }

}

void RunTimeClock::addSeconds(int s) {
    this->seconds += s;
    if(this->seconds == 60){
        this->addMinutes(1);
        this->seconds = 0;
    }
}

void RunTimeClock::addMinutes(int m) {
    this->minutes += m;
    if(this->minutes == 60){
        this->addHours(1);
        this->minutes = 0;
    }
}

void RunTimeClock::addHours(int h) {
    this->hours += h;
}

const std::string RunTimeClock::toString() const {
    std::ostringstream oss;
    oss << " Run time: " << this->hours << ":" << this->minutes << ":" << this->seconds << ":" << this->milliseconds;

    return oss.str();
}

