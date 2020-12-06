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

enum item_rarity{
    DEFAULT_RARITY,
    UNCOMMON,
    COMMON,
    RARE,
    EPIC,
    LEGENDARY
};

enum item_usage_type{
    LEGS_USAGE = 0,
    ARMS_USAGE = 1,
    CHEST_USAGE = 2,
    HEAD_USAGE = 3,
    SHIELD_USAGE = 4,
    WEAPON_USAGE = 5,
    CONSUMABLE_USAGE = 6,
    MATERIAL_USAGE,
    DEFAULT_USAGE
};

class Item {

protected:
    unsigned int Id;
    item_usage_type usageType;      // 6-Consumable/5-Weapon/4-Shield/3-Head/2-Chest/1-Arms/0-Legs
    string itemType;    // ITEM/WEAPON/ARMATURE
    string name;
    string description;
    int value;
    string rarity;
    item_rarity rarityEnum;
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
    Item();
    Item(string itemType, string name, string description, int value, item_rarity rarity,
            int iconRectX, int iconRectY, int hp, int mp, int damage, int armor, float critchance,
            float evadechance, int quantity, bool isNew, unsigned int id);
    explicit Item(Item* item);
    virtual ~Item();

    //functions
    std::string sortKeyWord();
    void updateRarityString();
    void updateRarityEnum();
    void updateValueByRarity();
    bool use();
    bool canBeMultiple() const;
    void updateUsageType();
    std::string getWeaponType() const;

    //TOSTRING
    string listItem(bool abbreviate);
    std::string getItemUsageTypeString();

    //GET & SET
    void setId(unsigned int new_id);
    unsigned int getId() const;
    item_usage_type getUsageType();
    int getQuantity() const;
    void setQuantity(int new_quantity);
    void minusQuantity(int minus_value);
    void addQuantity(int add_value);
    int getDamage() const;
    void setDamage(int new_damage);
    int getArmor() const;
    void setArmor(int new_armor);
    void setItemType(string new_itemType);
    string getItemType() const;
    void setName(string new_name);
    string getName() const;
    void setDescription(string new_description);
    string getDescription();
    void setValue(int new_value);
    int getValue() const;
    void setRarity(string new_rarity);
    string getRarity() const;
    void setRarity(item_rarity new_rarity);
    item_rarity getRarityEnum() const;
    void setIconRectX(int x);
    int getIconRectX() const;
    void setIconRectY(int y);
    int getIconRectY() const;
    void setIsNew(bool b);
    bool getIsNew() const;
    void setEquipped(bool b);
    bool isEquipped() const;
    int getHp() const;
    void setHp(int new_hp);
    int getMp() const;
    void setMp(int new_mp);
    float getCritChance() const;
    void setCritChance(float new_critChance);
    float getEvadeChance() const;
    void setEvadeChance(float new_evadeChance);
};


#endif //DRAGON_SLAYER_ITEM_H
