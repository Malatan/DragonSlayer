//
// Created by root on 10/2/20.
//

#include "Item.h"

Item::Item(string itemType, string name, string description, int value, item_rarity rarity, int iconRectX,
           int iconRectY, int hp, int mp, int damage, int armor, float critchance, float evadechance, int quantity, bool isNew,
           unsigned int id) :
           itemType(std::move(itemType)), name(std::move(name)), description(std::move(description)),
           value(value), rarityEnum(rarity), iconRectX(iconRectX), iconRectY(iconRectY),
           hp(hp), mp(mp), damage(damage), armor(armor), critChance(critchance), evadeChance(evadechance), quantity(quantity),
           isNew(isNew), Id(id), usageType(DEFAULT_USAGE){
    equipped = false;
    updateUsageType();
    updateRarityString();
}

Item::Item(){
    Id = 0;
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
usageType(item->usageType), equipped(item->equipped), rarityEnum(item->rarityEnum), Id(item->Id){

}

Item::~Item() = default;

string Item::listItem() {
    stringstream ss;
    ss << "-------------------------Item Info-------------------------" << std::endl
        << "Id: " << Id
        << " Itemtype: " << itemType
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
        << "-" << iconRectY << std::endl
        << "-------------------------END-Item Info-END-------------------------" << std::endl;
    return ss.str();
}

void Item::setItemType(string new_itemType) {
    itemType = std::move(new_itemType);
}

string Item::getItemType() const {
    return itemType;
}

void Item::setName(string new_name) {
    name = std::move(new_name);
}

string Item::getName() const {
    return name;
}

void Item::setDescription(string new_description) {
    description = std::move(new_description);
}

string Item::getDescription() {
    return description;
}

int Item::getValue() const {
    return Item::value;
}

void Item::setValue(int new_value) {
    Item::value = new_value;
}

int Item::getQuantity() const {
    return Item::quantity;
}

void Item::setQuantity(int new_quantity) {
    Item::quantity = new_quantity;
}

string Item::getRarity() const {
    return Item::rarity;
}

void Item::setRarity(string new_rarity) {
    rarity = std::move(new_rarity);
    updateRarityEnum();
}

int Item::getIconRectX() const {
    return iconRectX;
}

void Item::setIconRectX(int x) {
    iconRectX = x;
}

int Item::getIconRectY() const {
    return iconRectY;
}

void Item::setIconRectY(int y) {
    iconRectY = y;
}

int Item::getDamage() const {
    return Item::damage;
}

void Item::setDamage(int new_damage) {
    damage = new_damage;
}

int Item::getArmor() const {
    return armor;
}

void Item::setArmor(int new_armor) {
    armor = new_armor;
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

bool Item::getIsNew() const {
    return isNew;
}

void Item::setEquipped(bool b) {
    equipped = b;
}

bool Item::isEquipped() const {
    return equipped;
}

bool Item::isConsumable() const {
    return getItemType().at(0) == 'C';
}

int Item::getHp() const {
    return hp;
}

void Item::setHp(int new_hp) {
    hp = new_hp;
}

int Item::getMp() const {
    return mp;
}

void Item::setMp(int new_mp) {
    mp = new_mp;
}

float Item::getCritChance() const {
    return critChance;
}

void Item::setCritChance(float new_critChance) {
    critChance = new_critChance;
}

float Item::getEvadeChance() const {
    return evadeChance;
}

void Item::setEvadeChance(float new_evadeChance) {
    evadeChance = new_evadeChance;
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

void Item::setId(unsigned int new_id) {
    Id = new_id;
}

unsigned int Item::getId() const {
    return Id;
}





