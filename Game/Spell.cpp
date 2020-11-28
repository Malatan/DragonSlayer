//
// Created by root on 10/7/20.
//

#include "Spell.h"

Spell::Spell() {

}

Spell::Spell(Spell *spell) : spellType(spell->spellType), name(spell->name), type(spell->type),
description(spell->description), cost(spell->cost), cooldown(spell->cooldown), damage(spell->damage),
aoe(spell->aoe), learned(spell->learned), intRectX(spell->intRectX), intRectY(spell->intRectY), level(spell->level),
learnCost(spell->learnCost), maxLevel(spell->maxLevel){
}

Spell::~Spell() {

}

void Spell::refreshSpell() {
    if(Spell::ready > 0)
        Spell:ready --;
}


string Spell::getDescription() {
    return description;
}

void Spell::setDescription(string description) {
    this->description = description;
}

bool Spell::isLearned() {
    return learned;
}

void Spell::setLearned(bool learned) {
    Spell::learned = learned;
}

string Spell::getName() {
    return name;
}

void Spell::setName(string name) {
    Spell::name = name;
}

string Spell::getType() {
    return type;
}

int Spell::getReady() {
    return ready;
}

void Spell::setReady(int ready) {
    Spell::ready = ready;
}


void Spell::setType(string type) {
    this->type = type;
    if(type == "fire"){
        spellType = FIRE;
    } else if(type == "water"){
        spellType = WATER;
    }else if(type == "ice"){
        spellType = ICE;
    }else if(type == "electric"){
        spellType = ELECTRIC;
    }else if(type == "holy"){
        spellType = HOLY;
    }else{
        spellType = DEFAULT_SPELL_TYPE;
    }
}

int Spell::getCost() {
    return cost;
}

void Spell::setCost(int cost) {
    Spell::cost = cost;
}

int Spell::getCooldown() {
    return cooldown;
}

void Spell::setCooldown(int cooldown) {
    Spell::cooldown = cooldown;
}

int Spell::getDamage() {
    return damage;
}

void Spell::setDamage(int damage) {
    Spell::damage = damage;
}

int Spell::getAoe() {
    return aoe;
}

void Spell::setAoe(int aoe) {
    Spell::aoe = aoe;
}

int Spell::getIntRectX() {
    return intRectX;
}

void Spell::setIntRectX(int intRectX) {
    this->intRectX = intRectX;
}

int Spell::getIntRectY() {
    return intRectY;
}

void Spell::setIntRectY(int intRectY) {
    this->intRectY = intRectY;
}

const std::string Spell::toString() const {
    std::stringstream ss;
    ss << "Name: " << name
       << " Type: " << type
       << "(" << spellType << ")"
       << " Lv: " << level
       << "(max lv" << maxLevel << ")"
       << " Cost: " << cost
       << " CD: " << cooldown
       << " Damage: " << damage
       << " Aoe: " << aoe
       << " Learned: " << std::boolalpha << learned
       << " IntRect: " << intRectX << "-" << intRectY
       << " description: " << description
       << " learn cost: " << learnCost;

    return ss.str();
}

spell_type Spell::getTypeEnum() {
    return spellType;
}

int Spell::getLevel() {
    return level;
}

void Spell::setLevel(int level) {
    if(level > maxLevel)
        this->level = maxLevel;
    else
        this->level = level;
}

int Spell::getLearnCost() {
    return learnCost;
}

void Spell::setLearnCost(int learnCost) {
    this->learnCost = learnCost;
}

int Spell::getMaxLevel() {
    return maxLevel;
}

void Spell::setMaxLevel(int max_level) {
    maxLevel = max_level;
}

bool Spell::isMaxed() {
    return level == maxLevel;
}

void Spell::levelUp() {
    setLevel(level+1);
}

int Spell::getFinalDamage() {
    return damage*level;
}

int Spell::getFinalCost() {
    return cost*level;
}

Spell::Spell(spell_type spellType, string name, string type, string description, int cost, int cooldown, int ready, int damage,
        int aoe, bool learned, int level, int maxLevel, int learnCost, int intRectX, int intRectY) :
        spellType(spellType), name(std::move(name)), type(std::move(type)), description(std::move(description)), cost(cost),
        cooldown(cooldown), ready(ready), damage(damage), aoe(aoe), learned(learned), level(level), maxLevel(maxLevel),
        learnCost(learnCost), intRectX(intRectX), intRectY(intRectY) {

}




