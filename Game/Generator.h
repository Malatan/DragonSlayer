//
// Created by Leonardo on 09/11/2020.
//
#ifndef DRAGONSLAYER_GENERATOR_H
#define DRAGONSLAYER_GENERATOR_H

#include "iostream"
#include "fstream"
#include "Item.h"
#include "Utils.h"


class Generator {

public:
    static Item generateItem(int floor, unsigned int enemy_level);

    Generator();
    virtual ~Generator();

};


#endif //DRAGONSLAYER_GENERATOR_H
