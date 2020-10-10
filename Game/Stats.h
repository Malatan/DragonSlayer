//
// Created by root on 10/6/20.
//

#ifndef DRAGONSLAYER_STATS_H
#define DRAGONSLAYER_STATS_H
#include <string>
#include <sstream>
#include "iostream"
#include "fstream"

using namespace std;

class Stats {

private:

    int level;
    int exp;
    int maxExp;

    int hp;
    int maxHp;
    int mp;
    int maxMp;
    int armor;
    int armorBonus;
    int damage;
    int damageBonus;
    int critChance;     //in %
    int evadeChance;    //in %
    int agility;
    int wisdom;
    int strength;

    int freePoints;
public:

    void importStats();
    bool exportStats();
    string listStats();
    void addExp(int earned);
    void levelUp(int choise, int newExp);
    void addAttribute(int type);

    Stats();
    virtual ~Stats();

    int getLevel();
    void setLevel(int level);
    int getExp();
    void setExp(int exp);
    int getMaxExp();
    void setMaxExp(int maxExp);
    int getHp();
    void setHp(int hp);
    int getMaxHp();
    void setMaxHp(int maxHp);
    int getMp();
    void setMp(int mp);
    int getMaxMp();
    void setMaxMp(int maxMp);
    int getArmor();
    void setArmor(int armor);
    int getDamage();
    void setDamage(int damage);
    int getCritChance();
    void setCritChance(int critChance);
    int getEvadeChance();
    void setEvadeChance(int evadeChance);
    int getAgility();
    void setAgility(int agility);
    int getWisdom();
    void setWisdom(int wisdom);
    int getStrength();
    void setStrength(int strength);
    int getArmorBonus();
    void setArmorBonus(int armorBonus);
    int getDamageBonus();
    void setDamageBonus(int damageBonus);
    int getFreePoints();
    void setFreePoints(int freePoints);
};


#endif //DRAGONSLAYER_STATS_H
