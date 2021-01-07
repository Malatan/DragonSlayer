//
// Created by root on 10/2/20.
//

#include "Item.h"

Item::Item(const Item &p_item) = default;

Item::Item(string itemType, string name, string description, int value, item_rarity rarity, int iconRectX,
           int iconRectY, int hp, int mp, int damage, int armor, float critchance, float evadechance, int quantity, bool isNew,
           unsigned int id) :
        itemType(std::move(itemType)), name(std::move(name)), description(std::move(description)),
        value(value), rarityEnum(rarity), iconRectX(iconRectX), iconRectY(iconRectY),
        hp(hp), mp(mp), damage(damage), armor(armor), critChance(critchance), evadeChance(evadechance), quantity(quantity),
        isNew(isNew), Id(id), usageType(DEFAULT_USAGE), descriptionWrapped(false){
    equipped = false;
    updateUsageType();
    updateRarityString();
}

Item::Item(){
    Id = 0;
    descriptionWrapped = false;
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
    rarityEnum = DEFAULT_RARITY;
    updateRarityString();
}

Item::Item(Item *item) : itemType(item->itemType), name(item->name), description(item->description), value(item->value),
                         rarity(item->rarity), iconRectX(item->iconRectX), iconRectY(item->iconRectY), hp(item->hp), mp(item->mp), damage(item->damage),
                         armor(item->armor), critChance(item->critChance), evadeChance(item->evadeChance), quantity(item->quantity), isNew(item->isNew),
                         usageType(item->usageType), equipped(item->equipped), rarityEnum(item->rarityEnum), Id(item->Id),
                         descriptionWrapped(item->descriptionWrapped){

}

Item::~Item() = default;

string Item::listItem(bool abbreviate) {
    stringstream ss;
    ss << "-------------------------Item Info-------------------------" << std::endl
        << "Id: " << Id << std::endl
        << "Itemtype: " << itemType << std::endl
        << "usage type: " << getItemUsageTypeString() << std::endl
        << "name: " << name << std::endl;
        if(description.size() > 60 && abbreviate){
            int count = 60;
            ss << "desc: [";
            for(auto c : description){
                ss << c;
                count--;
                if(count == 0)
                    break;
            }
            ss << "...]" << std::endl;
        }else{
            ss << "desc: [" << description << "]" << std::endl;
        }
    ss  << "value: " << value << std::endl
        << "rarity: " << rarity
        << "(" << rarityEnum << ")" << std::endl
        << "hp: " << hp << std::endl
        << "mp: " << mp << std::endl
        << "damage: " << damage << std::endl
        << "armor: " << armor << std::endl
        << "critchance: " << critChance << std::endl
        << "evadechance: " << evadeChance << std::endl
        << "quantity: " << quantity << std::endl
        << "iconRect: " << iconRectX
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
        return "Helmet";
    } else if(app == "chest"){
        return "Chest";
    } else if(app == "arms"){
        return "Gloves";
    } else if(app == "legs"){
        return "Boots";
    } else if(app == "sword" || app == "axe"){
        return "Melee";
    } else if(app == "bow"){
        return "Ranged";
    } else if(app == "shield"){
        return "Shield";
    }else if(app == "potionS" || app == "potionM" || app == "potionL"){
        return "Consumable";
    }
    return itemType;
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

item_usage_type Item::getUsageType() {
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
    } else if(app == "potionS" || app == "potionM" || app == "potionL"){
        usageType = CONSUMABLE_USAGE;
    } else if(app == "Material"){
        usageType = MATERIAL_USAGE;
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
        case DEFAULT_RARITY:
            rarity = "DEFAULT";
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
    } else{
        rarityEnum = DEFAULT_RARITY;
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

bool Item::canBeMultiple() const {
    return usageType == CONSUMABLE_USAGE || usageType == MATERIAL_USAGE;
}

void Item::minusQuantity(int minus_value) {
    if(minus_value < quantity)
        quantity -= minus_value;
}

void Item::setRarity(item_rarity new_rarity) {
    rarityEnum = new_rarity;
    updateRarityString();
}

void Item::updateValueByRarity() {
    switch (rarityEnum) {
        case DEFAULT_RARITY:
        case UNCOMMON:
            break;
        case COMMON:
            value = (int)((float)value * 1.5f);
            break;
        case RARE:
            value = value * 2;
            break;
        case EPIC:
            value = (int)((float)value * 2.5f);
            break;
        case LEGENDARY:
            value = value * 3;
            break;
    }
}

void Item::addQuantity(int add_value) {
    quantity += add_value;
}

std::string Item::getWeaponType() const {
    if(usageType == WEAPON_USAGE){
        return itemType.substr(2);
    }
    return "";
}

bool Item::isDescriptionWrapped() const {
    return descriptionWrapped;
}

void Item::setDescriptionWrapped(bool b) {
    descriptionWrapped = b;
}





