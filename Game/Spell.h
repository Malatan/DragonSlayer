//
// Created by root on 10/7/20.
//

#ifndef DRAGONSLAYER_SPELL_H
#define DRAGONSLAYER_SPELL_H
#include <string>
#include <sstream>
#include "iostream"
#include "fstream"

enum spell_type{
    FIRE,
    WATER,
    ICE,
    ELECTRIC,
    HOLY,
    DEFAULT_SPELL_TYPE
};

using namespace std;

class Spell {

private:
    spell_type spellType;
    string name;
    string type;
    string description;
    int cost;
    int cooldown;
    int damage;
    int aoe;        //NUMERO DI NEMICI COLPIBILI DALLA SPELL
    bool learned;

    int intRectX;
    int intRectY;
public:

    string getName();
    void setName(string name);
    string getType();
    void setType(string type);
    spell_type getTypeEnum();
    string getDescription();
    void setDescription(string description);
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
    int getIntRectX();
    void setIntRectX(int intRectX);
    int getIntRectY();
    void setIntRectY(int intRectY);
    const std::string toString() const;

    Spell();
    Spell(Spell* spell);
    virtual ~Spell();
};


#endif //DRAGONSLAYER_SPELL_H
