//
// Created by root on 10/7/20.
//

#include "Spell.h"

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

void Spell::setType(string type) {
    Spell::type = type;
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

Spell::Spell() {

}

Spell::~Spell() {

}