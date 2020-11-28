//
// Created by root on 10/2/20.
//

#ifndef DRAGONSLAYER_BUFF_H
#define DRAGONSLAYER_BUFF_H
#include <iostream>
#include <sstream>
using namespace std;


class Buff {

private:
    string name;

    int addHp;
    int addMp;
    int addDamage;
    int addArmor;
    float addCritChance;
    float addEvadeChance;

    int turns;
    bool instant;

public:
    Buff();
    Buff(std::string name, int add_hp, int add_mp, int add_damage, int add_armor, float add_critchance, float add_evadechance, int turns);
    Buff(std::string name, int add_hp, int add_mp, int add_damage, int add_armor, float add_critchance, float add_evadechance, bool instant);
    virtual ~Buff();

    //accessors
    int getTurns() const;
    bool isInstant() const;
    const string &getName() const;

    int getAddHp() const;

    int getAddMp() const;

    int getAddDamage() const;

    int getAddArmor() const;

    float getAddCritChance() const;

    float getAddEvadeChance() const;

    std::string toString();
};


#endif //DRAGONSLAYER_BUFF_H
