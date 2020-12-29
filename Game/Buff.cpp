//
// Created by root on 10/2/20.
//

#include "Buff.h"

//constructor/destructor
Buff::Buff() = default;

Buff::Buff(const Buff &p_buff) = default;

Buff::Buff(Buff *buff) : name(buff->name), description(buff->description), keyWord(buff->keyWord), addHp(buff->addHp), addMp(buff->addMp),
                         addDamage(buff->addDamage), addArmor(buff->addArmor), addCritChance(buff->addCritChance),
                         addEvadeChance(buff->addEvadeChance), turns(buff->turns), instant(buff->instant), debuff(buff->debuff),
                         intRectX(buff->intRectX), intRectY(buff->intRectY){

}

Buff::Buff(std::string name, std::string description, std::string key_word, int add_hp, int add_mp, int add_damage, int add_armor, float add_critchance,
           float add_evadechance, int turns, bool is_debuff, int intRectX, int intRectY) :
           name(std::move(name)), description(std::move(description)), keyWord(std::move(key_word)), addHp(add_hp), addMp(add_mp),
           addDamage(add_damage), addArmor(add_armor), addCritChance(add_critchance), addEvadeChance(add_evadechance), turns(turns),
           instant(false), debuff(is_debuff), intRectX(intRectX), intRectY(intRectY){
}

Buff::Buff(std::string name, std::string description, std::string key_word, int add_hp, int add_mp, int add_damage, int add_armor, float add_critchance,
           float add_evadechance, bool instant, bool is_debuff, int intRectX, int intRectY) :
           name(std::move(name)), description(std::move(description)), keyWord(std::move(key_word)), addHp(add_hp), addMp(add_mp),
           addDamage(add_damage), addArmor(add_armor), addCritChance(add_critchance), addEvadeChance(add_evadechance), turns(0),
           instant(instant), debuff(is_debuff), intRectX(intRectX), intRectY(intRectY){
}

Buff::~Buff() = default;

//accessors
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

std::string Buff::toString() {
    std::stringstream ss;
    ss << "name: " << name;
    if(addHp != 0){
        ss << " add_hp: " << addHp;
    }
    if(addMp != 0){
        ss << " add_mp: " << addMp;
    }
    if(addDamage != 0){
        ss << " add_dmg: " << addDamage;
    }
    if(addArmor != 0){
        ss << " add_armor: " << addArmor;
    }
    if(addCritChance != 0){
        ss << " add_criticalchance: " << addCritChance<< "%";
    }
    if(addEvadeChance != 0){
        ss << " add_evadechance: " << addEvadeChance << "%";
    }

    ss << " turns: " << turns << "\n";
    return ss.str();
}

int Buff::getTurns() const{
    return turns;
}

bool Buff::isInstant() const {
    return instant;
}

int Buff::getIntRectX() const {
    return intRectX;
}

int Buff::getIntRectY() const {
    return intRectY;
}

bool Buff::isDebuff() const {
    return debuff;
}

std::string Buff::getKeyWord() const {
    return keyWord;
}

std::string Buff::getDescription() const {
    return description;
}

//functions
void Buff::updateLifeTime() {
    turns--;
    if(turns < 0)
        turns = 0;
}






