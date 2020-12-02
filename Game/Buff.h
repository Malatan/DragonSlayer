//
// Created by root on 10/2/20.
//

#ifndef DRAGONSLAYER_BUFF_H
#define DRAGONSLAYER_BUFF_H
#include <iostream>
#include <sstream>
#include <memory>
#include "Stats.h"

using namespace std;

class Buff {

private:
    string name;
    string description;
    string keyWord;
    int addHp{};
    int addMp{};
    int addDamage{};
    int addArmor{};
    float addCritChance{};
    float addEvadeChance{};
    int turns{};
    bool instant{};
    bool debuff{};
    int intRectX{};
    int intRectY{};

public:
    Buff();
    explicit Buff(Buff *buff);
    Buff(std::string name, std::string description, std::string key_word, int add_hp, int add_mp, int add_damage, int add_armor,
         float add_critchance, float add_evadechance, int turns, bool is_debuff, int intRectX, int intRectY);
    Buff(std::string name, std::string description, std::string key_word, int add_hp, int add_mp, int add_damage, int add_armor,
         float add_critchance, float add_evadechance, bool instant, bool is_debuff, int intRectX, int intRectY);
    virtual ~Buff();

    void updateLifeTime();

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
    std::string getDescription() const;
    int getIntRectX() const;
    int getIntRectY() const;
    bool isDebuff() const;
    std::string getKeyWord() const;
    std::string toString();
};


#endif //DRAGONSLAYER_BUFF_H
