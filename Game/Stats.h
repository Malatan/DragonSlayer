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

enum attribute{
    AGILITY,
    WISDOM,
    STRENGTH
};

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
    float critChance;
    float evadeChance;

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
    float evadeChanceBonus;

public:

    //MANAGE STATS
    bool addExp(int earned);
    void levelUp(int choise, int newExp);
    void addAttribute(attribute type, int quantity);
    void checkHpLimit();
    void checkMpLimit();
    void refillHp();
    void refillMp();
    int getHit(int hit_damage, float block_percentage, bool spell_damage);
    bool consumeMana(int mana_consumed);
    int gainHp(int gain_amount);
    int gainMp(int gain_amount);

    int getFinalHp();
    int getFinalMp();
    int getFinalDamage();
    int getFinalArmor();
    float getFinalCritChance();
    float getFinalEvadeChance();
    std::string getFinalCritChanceFixed();
    std::string getFinalEvadeChanceFixed();
    void updateSpellDmgMultiplier();
    void updateMultipliers();

    //CONSTRUCTOR & DESTRUCTOR
    Stats();
    virtual ~Stats();

    //GET & SET
    int getLevel();
    void setLevel(int new_level);
    int getExp();
    void setExp(int new_exp);
    int getMaxExp();
    void setMaxExp(int new_maxExp);
    int getHp();
    void setHp(int new_hp);
    int getMaxHp();
    void setMaxHp(int new_maxHp);
    int getMp();
    void setMp(int new_mp);
    int getMaxMp();
    void setMaxMp(int new_maxMp);
    int getArmor();
    void setArmor(int new_armor);
    int getDamage();
    void setDamage(int new_damage);
    float getCritChance();
    void setCritChance(float new_critChance);
    float getEvadeChance();
    void setEvadeChance(float new_evadeChance);
    int getAgility();
    void setAgility(int new_agility);
    int getWisdom();
    void setWisdom(int new_wisdom);
    int getStrength();
    void setStrength(int new_strength);
    int getFreePoints();
    void setFreePoints(int new_freePoints);
    int getMaxHpBonus() const;
    void setMaxHpBonus(int new_maxHpBonus);
    int getMaxMpBonus() const;
    void setMaxMpBonus(int new_maxMpBonus);
    int getDamageBonus() const;
    void setDamageBonus(int new_damageBonus);
    int getArmorBonus() const;
    void setArmorBonus(int new_armorBonus);
    float getCritChanceBonus() const;
    void setCritChanceBonus(float new_critChanceBonus);
    float getEvadeChanceBonus() const;
    void setEvadeChanceBonus(float new_evadeChanceBonus);
    float getSpellDmgMultiplier();

};


#endif //DRAGONSLAYER_STATS_H
