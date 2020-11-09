//
// Created by Leonardo on 09/11/2020.
//
#ifndef DRAGONSLAYER_GENERATOR_H
#define DRAGONSLAYER_GENERATOR_H
#include "Enemy.h"
#include "iostream"
#include "fstream"


class Generator {

public:
    Item generateItem(int floor, Enemy enemy);

    Generator();
    virtual ~Generator();

};


#endif //DRAGONSLAYER_GENERATOR_H
