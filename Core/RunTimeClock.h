//
// Created by Administrator on 07/10/2020.
//

#ifndef DRAGONSLAYER_RUNTIMECLOCK_H
#define DRAGONSLAYER_RUNTIMECLOCK_H

#include <iostream>

class RunTimeClock {
private:
    int milliseconds;
    int seconds;
    int minutes;
    int hours;

public:
    RunTimeClock();
    virtual ~RunTimeClock();

    void addMilliseconds(int ms);
    void addSeconds(int s);
    void addMinutes(int m);
    void addHours(int h);
    const std::string toString() const;

};


#endif //DRAGONSLAYER_RUNTIMECLOCK_H
