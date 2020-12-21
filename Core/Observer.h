//
// Created by Zheng on 20/12/2020.
//

#ifndef DRAGONSLAYER_OBSERVER_H
#define DRAGONSLAYER_OBSERVER_H

#include "../Components/AchievementsEnum.h"

class Observer{
public:
    virtual ~Observer() = default;
    virtual void onNotify(achievement_event event, int value) = 0;
};

#endif //DRAGONSLAYER_OBSERVER_H
