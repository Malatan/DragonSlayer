//
// Created by root on 10/7/20.
//

#ifndef DRAGONSLAYER_SPELL_H
#define DRAGONSLAYER_SPELL_H
#include <string>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

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
public:
    //CONSTRUCTOR & DESTRUCTOR
    Spell();
    Spell(spell_type spellType, string name, string type, string description, int cost,
          int cooldown, int damage, int aoe, bool learned, int level, int maxLevel, int learnCost,
          int intRectX, int intRectY);
    Spell(const Spell& p_spell);
    explicit Spell(Spell* spell);
    virtual ~Spell();

    //function
    bool isMaxed() const;
    void levelUp();
    int getFinalDamage() const;
    int getFinalCost() const;

    //GET & SET
    std::string toString() const;
    string getName();
    void setName(string new_name);
    string getType();
    void setType(spell_type new_spell_type);
    spell_type getTypeEnum();
    string getDescription();
    void setDescription(string new_description);
    int getLevel() const;
    void setLevel(int new_level);
    void setMaxLevel(int max_level);
    int getLearnCost() const;
    void setLearnCost(int new_learnCost);
    int getCost() const;
    void setCost(int new_cost);
    int getCooldown() const;
    void setCooldown(int new_cooldown);
    int getDamage() const;
    void setDamage(int new_damage);
    int getAoe() const;
    void setAoe(int new_aoe);
    bool isLearned() const;
    void setLearned(bool is_learned);
    int getIntRectX() const;
    void setIntRectX(int new_intRectX);
    int getIntRectY() const;
    void setIntRectY(int new_intRectY);

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version){
        ar & spellType;
        ar & name;
        ar & type;
        ar & description;
        ar & cost;
        ar & cooldown;
        ar & damage;
        ar & aoe;
        ar & learned;
        ar & level;
        ar & maxLevel;
        ar & learnCost;
        ar & intRectX;
        ar & intRectY;
    }

    spell_type spellType{};
    string name;
    string type;
    string description;
    int cost{};
    int cooldown{};
    int damage{};
    int aoe{};        //NUMERO DI NEMICI COLPIBILI DALLA SPELL
    bool learned{};
    int level{};
    int maxLevel{};
    int learnCost{};

    int intRectX{};
    int intRectY{};
};


#endif //DRAGONSLAYER_SPELL_H
