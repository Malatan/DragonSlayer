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
    return this->description;
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
        this->spellType = FIRE;
    } else if(type == "water"){
        this->spellType = WATER;
    }else if(type == "ice"){
        this->spellType = ICE;
    }else if(type == "electric"){
        this->spellType = ELECTRIC;
    }else if(type == "holy"){
        this->spellType = HOLY;
    }else{
        this->spellType = DEFAULT_SPELL_TYPE;
    }
}

int Spell::getCost() {
    return this->cost;
}

void Spell::setCost(int cost) {
    Spell::cost = cost;
}

int Spell::getCooldown() {
    return this->cooldown;
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
    return this->intRectX;
}

void Spell::setIntRectX(int intRectX) {
    this->intRectX = intRectX;
}

int Spell::getIntRectY() {
    return this->intRectY;
}

void Spell::setIntRectY(int intRectY) {
    this->intRectY = intRectY;
}

const std::string Spell::toString() const {
    std::stringstream ss;
    ss << "Name: " << this->name
       << " Type: " << this->type
       << "(" << this->spellType << ")"
       << " Lv: " << this->level
       << "(max lv" << this->maxLevel << ")"
       << " Cost: " << this->cost
       << " CD: " << this->cooldown
       << " Damage: " << this->damage
       << " Aoe: " << this->aoe
       << " Learned: " << std::boolalpha << this->learned
       << " IntRect: " << this->intRectX << "-" << this->intRectY
       << " description: " << this->description
       << " learn cost: " << this->learnCost;

    return ss.str();
}

spell_type Spell::getTypeEnum() {
    return this->spellType;
}

int Spell::getLevel() {
    return this->level;
}

void Spell::setLevel(int level) {
    if(level > this->maxLevel)
        this->level = this->maxLevel;
    else
        this->level = level;
}

int Spell::getLearnCost() {
    return this->learnCost;
}

void Spell::setLearnCost(int learnCost) {
    this->learnCost = learnCost;
}

int Spell::getMaxLevel() {
    return this->maxLevel;
}

void Spell::setMaxLevel(int max_level) {
    this->maxLevel = max_level;
}

bool Spell::isMaxed() {
    if(this->level == this->maxLevel)
        return true;
    return false;
}

void Spell::levelUp() {
    this->setLevel(this->level+1);
}

int Spell::getFinalDamage() {
    return this->damage*this->level;
}

int Spell::getFinalCost() {
    return this->cost*this->level;
}




