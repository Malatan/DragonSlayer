//
// Created by Zheng on 20/12/2020.
//

#include "Achievement.h"

//constructors/destructor
Achievement::Achievement() = default;

Achievement::~Achievement() = default;

//accessors/modifiers
void Achievement::setName(const std::string& a_name) {
    name = a_name;
}

void Achievement::setDescription(const std::string& a_description) {
    description = a_description;
}

void Achievement::setSeriesPos(int pos) {
    series_pos = pos;
}

void Achievement::setGoal(int value) {
    goal = value;
}

void Achievement::setAchievementEventType(int int_value) {
    achievement_event_type = static_cast<achievement_event>(int_value);
}

achievement_event Achievement::getAchievementEventType() {
    return achievement_event_type;
}

int Achievement::getSeriesPos() const {
    return series_pos;
}

int Achievement::getGoal() const {
    return goal;
}

void Achievement::setUnlocked(bool is_unlocked) {
    unlocked = is_unlocked;
}

std::string Achievement::getName() {
    return name;
}

std::string Achievement::getDescription() {
    return description;
}

//functions
std::string Achievement::toString() {
    std::stringstream ss;
    ss << "ae_type: " << achievement_event_type << " name: [" << name << "] desc: [" << description
    << "] series_pos: " << series_pos <<" goal: " << goal << std::endl;
    return ss.str();
}

bool Achievement::isUnlocked() const {
    return unlocked;
}








