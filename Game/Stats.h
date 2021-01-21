//
// Created by root on 10/6/20.
//

#ifndef DRAGONSLAYER_STATS_H
#define DRAGONSLAYER_STATS_H
#include <string>
#include <sstream>
#include <../includers/CerealHeaders.h>

using namespace std;

enum attribute{
    AGILITY,
    WISDOM,
    STRENGTH
};

class Stats {
public:
    //CONSTRUCTOR & DESTRUCTOR
    Stats();
    Stats(const Stats& p_stats);
    virtual ~Stats();

    //functions
    bool addExp(int earned);
    void levelUp(int newExp);
    void addAttribute(attribute type, int quantity);
    void checkHpLimit();
    void checkMpLimit();
    void refillHp();
    void refillMp();
    int getHit(int hit_damage, float block_percentage, bool spell_damage);
    bool consumeMana(int mana_consumed);
    int gainHp(int gain_amount);
    int gainMp(int gain_amount);
    void updateSpellDmgMultiplier();
    void updateMultipliers();

    //GET & SET
    int getLevel() const;
    void setLevel(int new_level);
    int getExp() const;
    void setExp(int new_exp);
    int getMaxExp() const;
    void setMaxExp(int new_maxExp);
    int getHp() const;
    void setHp(int new_hp);
    int getMaxHp() const;
    void setMaxHp(int new_maxHp);
    int getMp() const;
    void setMp(int new_mp);
    int getMaxMp() const;
    void setMaxMp(int new_maxMp);
    int getArmor() const;
    void setArmor(int new_armor);
    int getDamage() const;
    void setDamage(int new_damage);
    float getCritChance() const;
    void setCritChance(float new_critChance);
    float getEvadeChance() const;
    void setEvadeChance(float new_evadeChance);
    int getAgility() const;
    void setAgility(int new_agility);
    int getWisdom() const;
    void setWisdom(int new_wisdom);
    int getStrength() const;
    void setStrength(int new_strength);
    int getFreePoints() const;
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
    float getSpellDmgMultiplier() const;
    int getFinalHp() const;
    int getFinalMp() const;
    int getFinalDamage() const;
    int getFinalArmor() const;
    float getFinalCritChance() const;
    float getFinalEvadeChance() const;
    std::string toString(const std::string& prefix) const;

private:
    friend class cereal::access;
    template <class Archive>
    void serialize(Archive & ar){
        ar(level, exp, maxExp, hp, maxHp, mp, maxMp, armor, damage, critChance, evadeChance, agility,
           wisdom, strength, freePoints, spellDmgMultiplier, maxHpBonus, maxMpBonus, damageBonus,
           armorBonus, critChanceBonus, evadeChanceBonus);
    }

    int level{};
    int exp{};
    int maxExp{};

    int hp{};
    int maxHp{};
    int mp{};
    int maxMp{};
    int armor{};
    int damage{};
    float critChance{};
    float evadeChance{};

    int agility{};
    int wisdom{};
    int strength{};
    int freePoints{};

    float spellDmgMultiplier{};

    int maxHpBonus{};
    int maxMpBonus{};
    int damageBonus{};
    int armorBonus{};
    float critChanceBonus{};
    float evadeChanceBonus{};
};


#endif //DRAGONSLAYER_STATS_H
