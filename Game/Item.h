//
// Created by root on 10/2/20.
//

#ifndef DRAGON_SLAYER_ITEM_H
#define DRAGON_SLAYER_ITEM_H
#include <string>
#include <iostream>
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
    string icon;

    //Weapon attributes
    int damage;
    string weaponType;
    int durability;

    //Armature attributes
    int armor;
    string armorType;

    //Consumable attributes
    int quantity;

public:

    //CONSTRUCTOR & DESTRUCTOR

    Item(string itemType, string name, string description, int value, string rarity, string icon);
    Item();
    virtual ~Item();


    //GET & SET

    int getQuantity();
    void setQuantity(int quantity);
    int getDamage();
    void setDamage(int damage);
    string getWeaponType();
    void setWeaponType(string weaponType);
    int getDurability();
    void setDurability(int durability);
    int getArmor();
    void setArmor(int armor);
    string getArmorType();
    void setArmorType(string armorType);
    void setItemType(string itemType);
    string getItemType();
    void setName(string name);
    string getName();
    void setDescription(string description);
    string getDescription();
    const Buff *getBuffs() const;
    void setValue(int value);
    int getValue();
    void setRarity(string rarity);
    string getRarity();
    void setIcon(string icon);
    string getIcon();


    //OTHER METHODS

    bool addBuff(Buff in);
    Buff getBuffbyIndex(int i);
    string listItem();






};


#endif //DRAGON_SLAYER_ITEM_H
