//
// Created by root on 10/2/20.
//

#include "Buff.h"

Buff::Buff() {

}

Buff::Buff(std::string name, int add_hp, int add_mp, int add_damage, int add_armor, float add_critchance,
           float add_evadechance, int turns) : name(name), addHp(add_hp), addMp(add_mp), addDamage(add_damage), addArmor(add_armor),
                                               addCritChance(add_critchance), addEvadeChance(add_evadechance), turns(turns){

    this->instant = false;
}

const string &Buff::getName() const {
    return name;
}

int Buff::getAddHp() const {
    return addHp;
}

int Buff::getAddMp() const {
    return addMp;
}

int Buff::getAddDamage() const {
    return addDamage;
}

int Buff::getAddArmor() const {
    return addArmor;
}

float Buff::getAddCritChance() const {
    return addCritChance;
}

float Buff::getAddEvadeChance() const {
    return addEvadeChance;
}

Buff::Buff(std::string name, int add_hp, int add_mp, int add_damage, int add_armor, float add_critchance,
           float add_evadechance, bool instant) : name(name), addHp(add_hp), addMp(add_mp), addDamage(add_damage), addArmor(add_armor),
                                               addCritChance(add_critchance), addEvadeChance(add_evadechance), instant(instant){
    this->turns = 0;
}


Buff::~Buff() {

}

std::string Buff::toString() {
    std::stringstream ss;
    ss << "name: " << this->name;
    if(this->addHp != 0){
        ss << " add_hp: " << this->addHp;
    }
    if(this->addMp != 0){
        ss << " add_mp: " << this->addMp;
    }
    if(this->addDamage != 0){
        ss << " add_dmg: " << this->addDamage;
    }
    if(this->addArmor != 0){
        ss << " add_armor: " << this->addArmor;
    }
    if(this->addCritChance != 0){
        ss << " add_cc: " << this->addCritChance;
    }
    if(this->addEvadeChance != 0){
        ss << " add_ev: " << this->addEvadeChance;
    }

    ss << " turns: " << this->turns << "\n";
    return ss.str();
}

const int Buff::getTurns() const{
    return this->turns;
}

const bool Buff::isInstant() const {
    return this->instant;
}




