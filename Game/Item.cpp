//
// Created by root on 10/2/20.
//

#include "Item.h"
#include "Buff.h"

void Item::setItemType(string itemType) {
    Item::itemType = itemType;
}

string Item::getItemType() {
    return Item::itemType;
}

void Item::setName(string name) {
    Item::name = name;
}

string Item::getName() {
    return Item::name;
}

void Item::setDescription(string description) {
    Item::description = description;
}

string Item::getDescription() {
    return Item::description;
}

const Buff *Item::getBuffs() const {
    return buffs;
}

int Item::getValue() {
    return Item::value;
}

void Item::setValue(int value) {
    Item::value = value;
}

int Item::getQuantity() {
    return Item::quantity;
}

void Item::setQuantity(int quantity) {
    Item::quantity = quantity;
}

string Item::getRarity() {
    return Item::rarity;
}

void Item::setRarity(string rarity) {
    Item::rarity = rarity;
}

string Item::getIcon() {
    return Item::icon;
}

void Item::setIcon(string icon) {
    Item::icon = icon;
}

int Item::getDamage() {
    return Item::damage;
}

void Item::setDamage(int damage) {
    Item::damage = damage;
}

string Item::getWeaponType()  {
    return Item::weaponType;
}

void Item::setWeaponType(string weaponType) {
    Item::weaponType = weaponType;
}

int Item::getDurability()  {
    return Item::durability;
}

void Item::setDurability(int durability) {
    Item::durability = durability;
}

int Item::getArmor() {
    return Item::armor;
}

void Item::setArmor(int armor) {
    Item::armor = armor;
}

string Item::getArmorType()  {
    return Item::armorType;
}

void Item::setArmorType(string armorType) {
    Item::armorType = armorType;
}

Buff Item::getBuffbyIndex(int i) {

    return Item::buffs[i];
}

bool Item::addBuff(Buff in) {
    for(int i=0; i<10; i++){
        if(Item::buffs[i].getName() == ""){
            Item::buffs[i] = in;
            return true;
        }
    }
    return false;
}

string Item::listItem() {
    string desc = "";
    desc+= Item::name + "\n"
            + " - " + Item::description + "\n"
            + " - " + Item::rarity + "\n"
            + " - " + to_string(Item::value) + " gold";

    if(Item::itemType == "W"){
        desc+=  "\n - " + to_string(Item::damage) + " dmg\n" +
                " - " + to_string(Item::durability) + " uses";
    }

    if(Item::itemType == "E"){
        desc+=  "\n - " + to_string(Item::armor) + " armor";
    }
    return desc;
}


Item::Item(string itemType, string name, string description, int value, string rarity, string icon) {
    Item::itemType = itemType;
    Item::name = name;
    Item::description = description;
    Item::value = value;
    Item::rarity = rarity;
    Item::icon = icon;

    for (int i=0; i<10; i++)
    {
        Item::buffs[i] = Buff();
    }

}

Item::Item(){

    for (int i=0; i<10; i++)
    {
        Item::buffs[i] = Buff();
    }
};

Item::~Item() {

}

