//
// Created by root on 10/7/20.
//

#include "Spell.h"

//CONSTRUCTOR & DESTRUCTOR
Spell::Spell() = default;

Spell::Spell(Spell *spell) : spellType(spell->spellType), name(spell->name), type(spell->type),
description(spell->description), cost(spell->cost), cooldown(spell->cooldown), damage(spell->damage),
aoe(spell->aoe), learned(spell->learned), intRectX(spell->intRectX), intRectY(spell->intRectY), level(spell->level),
learnCost(spell->learnCost), maxLevel(spell->maxLevel){
}

Spell::Spell(spell_type spellType, string name, string type, string description, int cost, int cooldown, int damage,
             int aoe, bool learned, int level, int maxLevel, int learnCost, int intRectX, int intRectY) :
        spellType(spellType), name(std::move(name)), type(std::move(type)), description(std::move(description)), cost(cost),
        cooldown(cooldown), damage(damage), aoe(aoe), learned(learned), level(level), maxLevel(maxLevel),
        learnCost(learnCost), intRectX(intRectX), intRectY(intRectY) {

}

Spell::Spell(const Spell& p_spell) = default;

Spell::~Spell() = default;

//function
bool Spell::isMaxed() const {
    return level == maxLevel;
}

void Spell::levelUp() {
    setLevel(level+1);
}

int Spell::getFinalDamage() const {
    return damage*level;
}

int Spell::getFinalCost() const {
    return cost*level;
}

//GET & SET
string Spell::getDescription() {
    return description;
}

void Spell::setDescription(string new_description) {
    description = std::move(new_description);
}

bool Spell::isLearned() const {
    return learned;
}

void Spell::setLearned(bool is_learned) {
    learned = is_learned;
}

string Spell::getName() {
    return name;
}

void Spell::setName(string new_name) {
    name = std::move(new_name);
}

string Spell::getType() {
    return type;
}

void Spell::setType(spell_type new_spell_type) {
    spellType = new_spell_type;
    switch(spellType){
        case FIRE:
            type = "Fire";
            break;
        case WATER:
            type = "Water";
            break;
        case ICE:
            type = "Ice";
            break;
        case ELECTRIC:
            type = "Electric";
            break;
        case HOLY:
            type = "Holy";
            break;
        case DEFAULT_SPELL_TYPE:
            type = "Default";
            break;
    }
}

int Spell::getCost() const {
    return cost;
}

void Spell::setCost(int new_cost) {
    Spell::cost = new_cost;
}

int Spell::getCooldown() const {
    return cooldown;
}

void Spell::setCooldown(int new_cooldown) {
    Spell::cooldown = new_cooldown;
}

int Spell::getDamage() const {
    return damage;
}

void Spell::setDamage(int new_damage) {
    Spell::damage = new_damage;
}

int Spell::getAoe() const {
    return aoe;
}

void Spell::setAoe(int new_aoe) {
    Spell::aoe = new_aoe;
}

int Spell::getIntRectX() const {
    return intRectX;
}

void Spell::setIntRectX(int new_intRectX) {
    intRectX = new_intRectX;
}

int Spell::getIntRectY() const {
    return intRectY;
}

void Spell::setIntRectY(int new_intRectY) {
    intRectY = new_intRectY;
}

std::string Spell::toString() const {
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

int Spell::getLevel() const {
    return level;
}

void Spell::setLevel(int new_level) {
    if(new_level > maxLevel)
        level = maxLevel;
    else
        level = new_level;
}

int Spell::getLearnCost() const {
    return learnCost;
}

void Spell::setLearnCost(int new_learnCost) {
    learnCost = new_learnCost;
}

void Spell::setMaxLevel(int max_level) {
    maxLevel = max_level;
}







