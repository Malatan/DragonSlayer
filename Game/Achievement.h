//
// Created by Zheng on 20/12/2020.
//

#ifndef DRAGONSLAYER_ACHIEVEMENT_H
#define DRAGONSLAYER_ACHIEVEMENT_H

#include <iostream>
#include <sstream>
#include "../Components/AchievementsEnum.h"
#include <../includers/CerealHeaders.h>

class Achievement {
public:
    //constructors/destructor
    Achievement();
    Achievement(const Achievement& p_achievement);
    ~Achievement();

    //accessors/modifiers
    void setAchievementEventType(int int_value);
    void setName(const std::string& a_name);
    void setDescription(const std::string& a_description);
    void setSeriesPos(int pos);
    void setGoal(int value);
    void setUnlocked(bool is_unlocked);
    std::string getName();
    std::string getDescription();
    achievement_event getAchievementEventType();
    int getSeriesPos() const;
    int getGoal() const;
    bool isUnlocked() const;

    //functions
    std::string toString();

private:
    friend class cereal::access;
    template <class Archive>
    void serialize(Archive & ar){
        ar(achievement_event_type, name, description, series_pos, goal, unlocked);
    }

    achievement_event achievement_event_type{};
    std::string name{};
    std::string description{};
    int series_pos{}; // 1 = primo, 2 = secondo etc..
    int goal{};
    bool unlocked{};
};


#endif //DRAGONSLAYER_ACHIEVEMENT_H
