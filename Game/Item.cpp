//
// Created by root on 10/2/20.
//

#include "Item.h"
#include "Buff.h"

Item::Item(string itemType, string name, string description, int value, string rarity, string icon) {
    Item::itemType = itemType;
    Item::name = name;
    Item::description = description;
    Item::value = value;
    Item::rarity = rarity;
    Item::iconFileName = icon;

    for (int i=0; i<10; i++)
    {
        Item::buffs[i] = Buff();
    }

}

Item::Item(){

};

Item::~Item() {

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
    stringstream ss;
    ss << "Itemtype: " << this->itemType
        << " name: " << this->name
        << " desc: " << this->description
        << " value: " << this->value
        << " rarity: " << this->rarity
        << " armor: " << this->armor
        << " damage: " << this->damage
        << " quantity: " << this->quantity
        << " iconfilename: " << this->iconFileName;

    return ss.str();
}


void Item::setItemType(string itemType) {
    Item::itemType = itemType;
}

string Item::getItemType() const {
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

string Item::getIconFileName() {
    return this->iconFileName;
}

void Item::setIconFileName(string icon) {
    this->iconFileName = icon;
}

int Item::getDamage() {
    return Item::damage;
}

void Item::setDamage(int damage) {
    Item::damage = damage;
}

int Item::getArmor() {
    return Item::armor;
}

void Item::setArmor(int armor) {
    Item::armor = armor;
}

Buff Item::getBuffbyIndex(int i) {

    return Item::buffs[i];
}
