//
// Created by root on 10/2/20.
//

#include "Item.h"

#include <utility>
#include "Buff.h"

Item::Item(string itemType, string name, string description, int value, item_rarity rarity, int iconRectX,
           int iconRectY, int hp, int mp, int damage, int armor, float critchance, float evadechance, int quantity, bool isNew) :
           itemType(std::move(itemType)), name(std::move(name)), description(std::move(description)),
           value(value), rarityEnum(rarity), iconRectX(iconRectX), iconRectY(iconRectY),
           hp(hp), mp(hp), damage(damage), armor(armor), critChance(critchance), evadeChance(evadechance), quantity(quantity),
           isNew(isNew){
    equipped = false;
    updateUsageType();
    updateRarityString();
}

Item::Item(){
    equipped = false;
    value = 0;
    iconRectX = 0;
    iconRectY = 0;
    isNew = true;
    hp= 0;
    mp= 0;
    damage= 0;
    armor= 0;
    critChance= 0;
    evadeChance= 0;
    quantity= 0;
    usageType = DEFAULT_USAGE;
    rarityEnum = UNCOMMON;
    updateRarityString();
}

Item::Item(Item *item) : itemType(item->itemType), name(item->name), description(item->description), value(item->value),
rarity(item->rarity), iconRectX(item->iconRectX), iconRectY(item->iconRectY), hp(item->hp), mp(item->mp), damage(item->damage),
armor(item->armor), critChance(item->critChance), evadeChance(item->evadeChance), quantity(item->quantity), isNew(item->isNew),
usageType(item->usageType), equipped(item->equipped), rarityEnum(item->rarityEnum){

}


Item::~Item() {

}


string Item::listItem() {
    stringstream ss;
    ss << "Itemtype: " << itemType
        << " type: " << usageType
        << " name: " << name
        << " desc: " << description
        << " value: " << value
        << " rarity: " << rarity
        << "(" << rarityEnum << ")"
        << " hp: " << hp
        << " mp: " << mp
        << " damage: " << damage
        << " armor: " << armor
        << " critchance: " << critChance
        << " evadechance: " << evadeChance
        << " quantity: " << quantity
        << " iconRect: " << iconRectX
        << "-" << iconRectY;

    return ss.str();
}


void Item::setItemType(string itemType) {
    this->itemType = std::move(itemType);
}

string Item::getItemType() const {
    return itemType;
}

void Item::setName(string name) {
    this->name = std::move(name);
}

string Item::getName() const {
    return this->name;
}

void Item::setDescription(string description) {
    this->description = std::move(description);
}

string Item::getDescription() {
    return this->description;
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
    this->rarity = std::move(rarity);
    updateRarityEnum();
}

int Item::getIconRectX() {
    return iconRectX;
}

void Item::setIconRectX(int x) {
    iconRectX = x;
}

int Item::getIconRectY() {
    return iconRectY;
}

void Item::setIconRectY(int y) {
    iconRectY = y;
}

int Item::getDamage() {
    return Item::damage;
}

void Item::setDamage(int damage) {
    this->damage = damage;
}

int Item::getArmor() {
    return armor;
}

void Item::setArmor(int armor) {
    this->armor = armor;
}

std::string Item::getItemUsageTypeString() {
    std::string app = itemType.substr(2);
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
    isNew = b;
}

bool Item::getIsNew() {
    return isNew;
}

void Item::setEquipped(bool b) {
    equipped = b;
}

bool Item::isEquipped() {
    return equipped;
}

bool Item::isConsumable() {
    return getItemType().at(0) == 'C';
}

int Item::getHp() const {
    return hp;
}

void Item::setHp(int hp) {
    this->hp = hp;
}

int Item::getMp() const {
    return mp;
}

void Item::setMp(int mp) {
    this->mp = mp;
}

float Item::getCritChance() const {
    return critChance;
}

void Item::setCritChance(float critChance) {
    this->critChance = critChance;
}

float Item::getEvadeChance() const {
    return evadeChance;
}

void Item::setEvadeChance(float evadeChance) {
    this->evadeChance = evadeChance;
}

int Item::getUsageType() {
    return usageType;
}

void Item::updateUsageType() {
    std::string app = itemType.substr(2);
    if(app == "head"){
        usageType = HEAD_USAGE;
    } else if(app == "chest"){
        usageType = CHEST_USAGE;
    } else if(app == "arms"){
        usageType = ARMS_USAGE;
    } else if(app == "legs"){
        usageType = LEGS_USAGE;
    } else if(app == "sword" || app == "axe" || app == "bow"){
        usageType = WEAPON_USAGE;
    } else if(app == "shield"){
        usageType = SHIELD_USAGE;
    }else if(app == "potionS" || app == "potionM" || app == "potionL"){
        usageType = CONSUMABLE_USAGE;
    }
}

bool Item::use() {
    quantity--;
    return quantity > 0;
}

void Item::updateRarityString() {
    switch(rarityEnum){
        case UNCOMMON:
            rarity = "Uncommon";
            break;
        case COMMON:
            rarity = "Common";
            break;
        case RARE:
            rarity = "Rare";
            break;
        case EPIC:
            rarity = "Epic";
            break;
        case LEGENDARY:
            rarity = "Legendary";
            break;
    }
}

void Item::updateRarityEnum() {
    if(rarity == "Uncommon"){
        rarityEnum = UNCOMMON;
    } else if(rarity == "Common"){
        rarityEnum = COMMON;
    } else if(rarity == "Rare"){
        rarityEnum = RARE;
    } else if(rarity == "Epic"){
        rarityEnum = EPIC;
    } else if(rarity == "Legendary"){
        rarityEnum = LEGENDARY;
    }
}

item_rarity Item::getRarityEnum() const {
    return rarityEnum;
}

std::string Item::sortKeyWord() {
    stringstream ss;
    ss << itemType << rarity << name;
    return ss.str();
}





