//
// Created by Administrator on 20/12/2020.
//

#ifndef DRAGONSLAYER_SUBJECT_H
#define DRAGONSLAYER_SUBJECT_H

#include <vector>
#include "Observer.h"
#include "../Components/AchievementComponent.h"

class Subject{
public:
    virtual ~Subject() = default;

    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;

protected:
    virtual void notify(achievement_event event, int value) = 0;
    std::vector<Observer*> observers;
};
#endif //DRAGONSLAYER_SUBJECT_H
