//
// Created by root on 10/2/20.
//

#ifndef DRAGON_SLAYER_ITEM_H
#define DRAGON_SLAYER_ITEM_H
#include <string>
#include <iostream>
#include <sstream>
#include "Buff.h"

using namespace std;

class Item {

protected:

    string itemType;    // ITEM/WEAPON/ARMATURE

    string name;
    string description;
    Buff buffs[10];
    int value;
    string rarity;
    int iconRectX;
    int iconRectY;
    bool isNew;
    //Weapon attributes
    int damage;

    //Armature attributes
    int armor;

    //Consumable attributes
    int quantity;

public:
    //CONSTRUCTOR & DESTRUCTOR

    Item(string itemType, string name, string description, int value, string rarity,
            int iconRectX, int iconRectY, int damage, int armor, int quantity, bool isNew);
    Item();
    virtual ~Item();


    //GET & SET

    int getQuantity();
    void setQuantity(int quantity);

    int getDamage();
    void setDamage(int damage);

    int getArmor();
    void setArmor(int armor);

    void setItemType(string itemType);
    string getItemType() const;

    void setName(string name);
    string getName();

    void setDescription(string description);
    string getDescription();

    const Buff *getBuffs() const;

    void setValue(int value);
    int getValue();

    void setRarity(string rarity);
    string getRarity() const;

    void setIconRectX(int x);
    int getIconRectX();

    void setIconRectY(int y);
    int getIconRectY();

    void setIsNew(bool b);
    bool getIsNew();

    std::string getItemUsageType();
    //OTHER METHODS

    bool addBuff(Buff in);
    Buff getBuffbyIndex(int i);
    string listItem();
};


#endif //DRAGON_SLAYER_ITEM_H
