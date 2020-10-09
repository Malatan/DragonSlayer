//
// Created by root on 10/7/20.
//

#ifndef DRAGONSLAYER_SPELL_H
#define DRAGONSLAYER_SPELL_H
#include <string>
#include <sstream>
#include "iostream"
#include "fstream"

using namespace std;

class Spell {

private:

    string name;
    string type;
    int cost;
    int cooldown;
    int damage;
    int aoe;        //NUMERO DI NEMICI COLPIBILI DALLA SPELL
    bool learned;

public:

    string getName();
    void setName(string name);
    string getType();
    void setType(string type);
    int getCost();
    void setCost(int cost);
    int getCooldown();
    void setCooldown(int cooldown);
    int getDamage();
    void setDamage(int damage);
    int getAoe();
    void setAoe(int aoe);
    bool isLearned();
    void setLearned(bool learned);


    Spell();
    virtual ~Spell();
};


#endif //DRAGONSLAYER_SPELL_H
