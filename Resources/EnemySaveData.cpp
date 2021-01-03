//
// Created by Administrator on 01/01/2021.
//

#include "EnemySaveData.h"

EnemySaveData::EnemySaveData() = default;

EnemySaveData::EnemySaveData(unsigned int _id, unsigned int _leaderId, bool _isFollower, std::string _name,
                             enemy_types _type, int _currentBoost, const Stats &stats, float pos_x, float pos_y) {
    id = _id;
    leaderId = _leaderId;
    isFollower = _isFollower;
    name = std::move(_name);
    type = _type;
    currentBoost = _currentBoost;
    _stats = stats;
    posX = pos_x;
    posY = pos_y;
}

EnemySaveData::~EnemySaveData() = default;

//getters/setters
unsigned int EnemySaveData::getId() const {
    return id;
}

unsigned int EnemySaveData::getLeaderId() const {
    return leaderId;
}

bool EnemySaveData::isFollower1() const {
    return isFollower;
}

const string &EnemySaveData::getName() const {
    return name;
}

enemy_types EnemySaveData::getType() const {
    return type;
}

int EnemySaveData::getCurrentBoost() const {
    return currentBoost;
}

const Stats &EnemySaveData::getStats() const {
    return _stats;
}

float EnemySaveData::getPosX() const {
    return posX;
}

float EnemySaveData::getPosY() const {
    return posY;
}


