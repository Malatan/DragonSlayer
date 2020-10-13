//
// Created by root on 10/2/20.
//

#include "Item.h"
#include "Buff.h"

Item::Item(string itemType, string name, string description, int value, string rarity, int iconRectX,
           int iconRectY, int damage, int armor, int quantity, bool isNew) : itemType(itemType), name(name), description(description),
           value(value), rarity(rarity), iconRectX(iconRectX), iconRectY(iconRectY), damage(damage), armor(armor), quantity(quantity),
           isNew(isNew){

}

Item::Item(){
    this->equipped = false;
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
        << " iconRect: " << this->iconRectX
        << " - " << this->iconRectY;

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

string Item::getName() const {
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

string Item::getRarity() const {
    return Item::rarity;
}

void Item::setRarity(string rarity) {
    Item::rarity = rarity;
}

int Item::getIconRectX() {
    return this->iconRectX;
}

void Item::setIconRectX(int x) {
    this->iconRectX = x;
}

int Item::getIconRectY() {
    return this->iconRectY;
}

void Item::setIconRectY(int y) {
    this->iconRectY = y;
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

std::string Item::getItemUsageType() {
    std::string app = this->itemType.substr(2);
    if(app == "head"){
        app = "Helmet";
    } else if(app == "chest"){
        app = "Chest";
    } else if(app == "arms"){
        app = "Gloves";
    } else if(app == "legs"){
        app = "Boots";
    } else if(app == "sword" || app == "axe"){
        app = "Melee";
    } else if(app == "bow"){
        app = "Ranged";
    } else if(app == "shield"){
        app = "Shield";
    }else if(app == "potionS" || app == "potionM" || app == "potionL"){
        app = "Consumable";
    }
    return app;
}

void Item::setIsNew(bool b) {
    this->isNew = b;
}

bool Item::getIsNew() {
    return this->isNew;
}

void Item::setEquipped(bool b) {
    this->equipped = b;
}

bool Item::isEquipped() {
    return this->equipped;
}


