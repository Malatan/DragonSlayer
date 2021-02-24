//
// Created by root on 10/2/20.
//

#ifndef DRAGONSLAYER_BUFF_H
#define DRAGONSLAYER_BUFF_H
#include <iostream>
#include <sstream>
#include <memory>
#include "Stats.h"
#include <../includers/CerealHeaders.h>

using namespace std;

class Buff {
public:
    //constructor/destructor
    Buff();
    Buff(const Buff& p_buff);
    explicit Buff(Buff *buff);
    Buff(std::string name, std::string description, std::string key_word, int add_hp, int add_mp, int add_damage, int add_armor,
         float add_critchance, float add_evadechance, int turns, bool is_debuff, int intRectX, int intRectY);
    Buff(std::string name, std::string description, std::string key_word, int add_hp, int add_mp, int add_damage, int add_armor,
         float add_critchance, float add_evadechance, bool instant, bool is_debuff, int intRectX, int intRectY);
    ~Buff();

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

    //functions
    void updateLifeTime();

private:
    friend class cereal::access;
    template <class Archive>
    void serialize(Archive & ar){
        ar(name, description, keyWord, addHp, addMp, addDamage, addArmor, addCritChance, addEvadeChance, turns, instant,
           debuff, intRectX, intRectY);
    }

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


};


#endif //DRAGONSLAYER_BUFF_H
