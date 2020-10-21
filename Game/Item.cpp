//
// Created by root on 10/2/20.
//

#include "Item.h"
#include "Buff.h"

Item::Item(string itemType, string name, string description, int value, string rarity, int iconRectX,
           int iconRectY, int hp, int mp, int damage, int armor, float critchance, float evadechance, int quantity, bool isNew) :
           itemType(itemType), name(name), description(description),
           value(value), rarity(rarity), iconRectX(iconRectX), iconRectY(iconRectY),
           hp(hp), mp(hp), damage(damage), armor(armor), critChance(critchance), evadeChance(evadechance), quantity(quantity),
           isNew(isNew){
    this->equipped = false;
    this->updateUsageType();
}

Item::Item(){
    this->equipped = false;
    this->value = 0;
    this->iconRectX = 0;
    this->iconRectY = 0;
    this->isNew = true;
    this->hp= 0;
    this->mp= 0;
    this->damage= 0;
    this->armor= 0;
    this->critChance= 0;
    this->evadeChance= 0;
    this->quantity= 0;
    this->usageType = 7;


}

Item::Item(Item *item) : itemType(item->itemType), name(item->name), description(item->description), value(item->value),
rarity(item->rarity), iconRectX(item->iconRectX), iconRectY(item->iconRectY), hp(item->hp), mp(item->mp), damage(item->damage),
armor(item->armor), critChance(item->critChance), evadeChance(item->evadeChance), quantity(item->quantity), isNew(item->isNew),
usageType(item->usageType), equipped(item->equipped){

}


Item::~Item() {

}


string Item::listItem() {
    stringstream ss;
    ss << "Itemtype: " << this->itemType
        << " type: " << this->usageType
        << " name: " << this->name
        << " desc: " << this->description
        << " value: " << this->value
        << " rarity: " << this->rarity
        << " hp: " << this->hp
        << " mp: " << this->mp
        << " damage: " << this->damage
        << " armor: " << this->armor
        << " critchance: " << this->critChance
        << " evadechance: " << this->evadeChance
        << " quantity: " << this->quantity
        << " iconRect: " << this->iconRectX
        << "-" << this->iconRectY;

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

std::string Item::getItemUsageTypeString() {
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

bool Item::isConsumable() {
    if(this->getItemType().at(0) == 'C')
        return true;
    return false;
}

int Item::getHp() const {
    return hp;
}

void Item::setHp(int hp) {
    Item::hp = hp;
}

int Item::getMp() const {
    return mp;
}

void Item::setMp(int mp) {
    Item::mp = mp;
}

float Item::getCritChance() const {
    return critChance;
}

void Item::setCritChance(float critChance) {
    Item::critChance = critChance;
}

float Item::getEvadeChance() const {
    return evadeChance;
}

void Item::setEvadeChance(float evadeChance) {
    Item::evadeChance = evadeChance;
}

int Item::getUsageType() {
    return this->usageType;
}

void Item::updateUsageType() {
    std::string app = this->itemType.substr(2);
    if(app == "head"){
        this->usageType = 3;
    } else if(app == "chest"){
        this->usageType = 2;
    } else if(app == "arms"){
        this->usageType = 1;
    } else if(app == "legs"){
        this->usageType = 0;
    } else if(app == "sword" || app == "axe" || app == "bow"){
        this->usageType = 5;
    } else if(app == "shield"){
        this->usageType = 4;
    }else if(app == "potionS" || app == "potionM" || app == "potionL"){
        this->usageType = 6;
    }
}

bool Item::use() {
    this->quantity--;
    if(this->quantity <= 0)
        return false;
    else
        return true;
}





