//
// Created by Administrator on 01/01/2021.
//

#include "LootBagSaveData.h"

//constructor/destructor
LootBagSaveData::LootBagSaveData() = default;

LootBagSaveData::LootBagSaveData(unsigned int _id, float _msCounter, lifeTimePair _lifeTime, std::vector<Item> _loots,
                                 float pos_x, float pos_y) {
    id = _id;
    msCounter = _msCounter;
    lifeTime = _lifeTime;
    loots = std::move(_loots);
    posX = pos_x;
    posY = pos_y;
}

//getters/setters
unsigned int LootBagSaveData::getId() const {
    return id;
}

float LootBagSaveData::getMsCounter() const {
    return msCounter;
}

const lifeTimePair &LootBagSaveData::getLifeTime() const {
    return lifeTime;
}

const vector<Item> &LootBagSaveData::getLoots() const {
    return loots;
}

float LootBagSaveData::getPosX() const {
    return posX;
}

float LootBagSaveData::getPosY() const {
    return posY;
}

LootBagSaveData::~LootBagSaveData() = default;
