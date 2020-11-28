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

enum spell_base_effect{
    HEAL_BASE_POINT = 60,
    MEDITATION_BASE_POINT = 40
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
    int ready;      //CONT per il cooldown
    int damage;
    int aoe;        //NUMERO DI NEMICI COLPIBILI DALLA SPELL
    bool learned;
    int level;
    int maxLevel;
    int learnCost;

    int intRectX;
    int intRectY;
public:

    //MANAGE SPELL
    void refreshSpell();   //SCORRE IL CONT PER RIUSARE LA SPELL
    bool isMaxed();
    void levelUp();

    //TOSTRING
    const std::string toString() const;

    //GET & SET
    int getReady();
    void setReady(int ready);
    string getName();
    void setName(string name);
    string getType();
    void setType(string type);
    spell_type getTypeEnum();
    string getDescription();
    void setDescription(string description);
    int getLevel();
    void setLevel(int level);
    int getMaxLevel();
    void setMaxLevel(int max_level);
    int getLearnCost();
    void setLearnCost(int learnCost);
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
    int getFinalDamage();
    int getFinalCost();

    //CONSTRUCTOR & DESTRUCTOR
    Spell();
    Spell(spell_type spellType, string name, string type, string description, int cost,
          int cooldown, int ready, int damage, int aoe, bool learned, int level, int maxLevel, int learnCost,
          int intRectX, int intRectY);
    Spell(Spell* spell);
    virtual ~Spell();
};


#endif //DRAGONSLAYER_SPELL_H
