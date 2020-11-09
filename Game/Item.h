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

    int usageType;      // 6-Consumable/5-Weapon/4-Shield/3-Head/2-Chest/1-Arms/0-Legs
    string itemType;    // ITEM/WEAPON/ARMATURE
    string name;
    string description;
    int value;
    string rarity;
    int iconRectX;
    int iconRectY;
    bool isNew;
    bool equipped;
    int quantity;

    //Bonus Attributes
    int hp;
    int mp;
    int damage;
    int armor;
    float critChance;
    float evadeChance;

public:

    //CONSTRUCTOR & DESTRUCTOR
    Item(string itemType, string name, string description, int value, string rarity,
            int iconRectX, int iconRectY, int hp, int mp, int damage, int armor, float critchance, float evadechance, int quantity, bool isNew);
    Item();
    Item(Item* item);
    virtual ~Item();

    //MANAGE ITEM
    bool use();
    bool isConsumable();
    void updateUsageType();

    //TOSTRING
    string listItem();
    std::string getItemUsageTypeString();

    //GET & SET
    int getUsageType();
    int getQuantity();
    void setQuantity(int quantity);
    int getDamage();
    void setDamage(int damage);
    int getArmor();
    void setArmor(int armor);
    void setItemType(string itemType);
    string getItemType() const;
    void setName(string name);
    string getName() const;
    void setDescription(string description);
    string getDescription();
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
    void setEquipped(bool b);
    bool isEquipped();
    int getHp() const;
    void setHp(int hp);
    int getMp() const;
    void setMp(int mp);
    float getCritChance() const;
    void setCritChance(float critChance);
    float getEvadeChance() const;
    void setEvadeChance(float evadeChance);
};


#endif //DRAGON_SLAYER_ITEM_H
