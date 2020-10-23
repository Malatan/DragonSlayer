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
    int damage;
    float critChance;     //in %
    float evadeChance;    //in %

    int agility;
    int wisdom;
    int strength;
    int freePoints;

    float spellDmgMultiplier;

    int maxHpBonus;
    int maxMpBonus;
    int damageBonus;
    int armorBonus;
    float critChanceBonus;
    float evadeChanceBonus;    //in %

public:

    bool exportStats();
    string listStats();
    bool addExp(int earned);
    void levelUp(int choise, int newExp);
    void addAttribute(int type);
    void checkHpLimit();
    void checkMpLimit();

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

    float getCritChance();
    void setCritChance(float critChance);

    float getEvadeChance();
    void setEvadeChance(float evadeChance);

    int getAgility();
    void setAgility(int agility);

    int getWisdom();
    void setWisdom(int wisdom);

    int getStrength();
    void setStrength(int strength);

    int getFreePoints();
    void setFreePoints(int freePoints);

    int getMaxHpBonus() const;

    void setMaxHpBonus(int maxHpBonus);

    int getMaxMpBonus() const;

    void setMaxMpBonus(int maxMpBonus);

    int getDamageBonus() const;

    void setDamageBonus(int damageBonus);

    int getArmorBonus() const;

    void setArmorBonus(int armorBonus);

    float getCritChanceBonus() const;

    void setCritChanceBonus(float critChanceBonus);

    float getEvadeChanceBonus() const;

    void setEvadeChanceBonus(float evadeChanceBonus);

    float getSpellDmgMultiplier();

    int getFinalHp();
    int getFinalMp();
    int getFinalDamage();
    int getFinalArmor();
    float getFinalCritChance();
    float getFinalEvadeChance();

    int gainHp(int gain_amount);
    int gainMp(int gain_amount);

    void updateSpellDmgMultiplier();
    void updateMultipliers();
};


#endif //DRAGONSLAYER_STATS_H
