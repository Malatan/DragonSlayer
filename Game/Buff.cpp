//
// Created by root on 10/2/20.
//

#include "Buff.h"
#include <iostream>

Buff::Buff(string name, string effect, string type, bool hidden, int turns) {
    Buff::name = name;
    Buff::effect = effect;
    Buff::type = type;
    Buff::hidden = hidden;
    Buff::turns = turns;
}

Buff::Buff() {

}

Buff::~Buff() {

}

void Buff::setName(string name) {
    Buff::name = name;
}

string Buff::getName() {
    return Buff::name;
}

void Buff::setEffect(string effect) {
    Buff::effect = effect;
}

string Buff::getEffect() {
    return Buff::effect;
}

void Buff::setType(string type) {
    Buff::type = type;
}

string Buff::getType() {
    return Buff::type;
}

void Buff::setHidden(bool hidden) {
    Buff::hidden = hidden;
}

bool Buff::isHidden() {
    return Buff::hidden;
}

void Buff::setTurns(int turns) {
    Buff::turns = turns;
}

int Buff::getTurns() {
    return Buff::turns;
}


