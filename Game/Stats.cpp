//
// Created by root on 10/6/20.
//

#include "Stats.h"

//CONSTRUCTOR & DESTRUCTOR
Stats::Stats(){
    level = 1;
    exp = 0;
    maxExp = 0;
    hp = 0;
    maxHp = 0;
    mp = 0;
    maxMp = 0;
    damage = 0;
    armor = 0;
    critChance = 0.f;
    evadeChance = 0.f;
    agility = 0;
    wisdom = 0;
    strength = 0;
    freePoints = 0;
    maxHpBonus = 0;
    maxMpBonus = 0;
    damageBonus = 0;
    armorBonus = 0;
    critChanceBonus = 0;
    evadeChanceBonus = 0;
    spellDmgMultiplier = 1.f;
}

Stats::Stats(const Stats& p_stats) = default;

Stats::~Stats()= default;

//functions
bool Stats::addExp(int earned) {
    bool leveledUp = false;
    exp = exp + earned;
    while(exp >= maxExp){                //SE RAGGIUNTA QNT NECESSARIA A LIVELLARE
        int newExp = exp - maxExp;    //EXP IN ECCESSO AGGIUNTA PER FARE IL PROX LIVELLO
        levelUp(newExp);
        leveledUp = true;
    }
    return leveledUp;
}

void Stats::addAttribute(attribute type, int quantity) {
    switch(type){
        case AGILITY:
            agility += quantity;

            critChance = critChance + (0.4f * (float)quantity);
            evadeChance = evadeChance + (0.3f * (float)quantity);
            freePoints --;
            break;
        case WISDOM:
            wisdom += quantity;

            maxMp = maxMp + (15 * quantity);
            mp = maxMp;
            freePoints --;
            break;
        case STRENGTH:
            strength += quantity;

            maxHp = maxHp + (15 * quantity);
            hp = maxHp;
            armor = armor + (2 * quantity);
            damage = damage + (2 * quantity);
            freePoints --;
            break;
    }
    updateMultipliers();
}

void Stats::levelUp(int newExp) {
    level ++;
    exp = newExp;
    maxExp = maxExp + (int)(25 * (1.f + (float)level/10.f));          //EXP MAX PER LIVELLARE AUMENTATA

    maxHp = maxHp + 25;
    hp = maxHp + maxHpBonus;               //HP RIGENERATI
    maxMp = maxMp + 25;
    mp = maxMp + maxMpBonus;               //MP RIGENERATI
    armor = armor + 4;
    damage = damage + 4;

    freePoints += 3;
}

int Stats::getHit(int hit_damage, float block_percentage, bool spell_damage) {
    if(!spell_damage){
        //reduce damage with armor
        hit_damage -= getFinalArmor();
        //reduce damage with block
        if(block_percentage > 0.f)
            hit_damage -= (int)(((float)hit_damage/100.f) * block_percentage);
    }
    if(hit_damage < 0)
        hit_damage = 1;
    hp -= hit_damage;
    if(hp < 0)
        hp = 0;
    return hit_damage;
}

bool Stats::consumeMana(int mana_consumed) {
    if(mana_consumed > mp)
        return false;
    mp -= mana_consumed;
    if(mp < 0)
        mp = 0;
    return true;
}

void Stats::refillHp() {
    hp = getFinalHp();
}

void Stats::refillMp() {
    mp = getFinalMp();
}

void Stats::checkHpLimit() {
    if(hp > (maxHp + maxHpBonus))
        hp = maxHp + maxHpBonus;
}

void Stats::checkMpLimit() {
    if(mp > (maxMp + maxMpBonus))
        mp = maxMp + maxMpBonus;
}

int Stats::gainHp(int gain_amount) {
    int restore_amount = gain_amount;
    if((hp + gain_amount) > getFinalHp()){
        restore_amount = getFinalHp() - hp;
        hp = getFinalHp();
    } // 250/300 150
    else{
        hp += gain_amount;
    }
    return restore_amount;
}

int Stats::gainMp(int gain_amount) {
    int restore_amount = gain_amount;
    if((mp + gain_amount) > getFinalMp()){
        restore_amount = getFinalMp() - mp;
        mp = getFinalMp();
    } // 250/300 150
    else{
        mp += gain_amount;
    }
    return restore_amount;
}

void Stats::updateSpellDmgMultiplier() {
    spellDmgMultiplier = 1.f + (float)wisdom/10.f;
}

void Stats::updateMultipliers() {
    updateSpellDmgMultiplier();
}

//GET & SET
int Stats::getLevel() const {
    return level;
}

void Stats::setLevel(int new_level) {
    level = new_level;
}

int Stats::getExp() const {
    return exp;
}

void Stats::setExp(int new_exp) {
    exp = new_exp;
}

int Stats::getMaxExp() const {
    return maxExp;
}

void Stats::setMaxExp(int new_maxExp) {
    maxExp = new_maxExp;
}

int Stats::getHp() const {
    return hp;
}

void Stats::setHp(int new_hp) {
    hp = new_hp;
}

int Stats::getMaxHp() const {
    return maxHp;
}

void Stats::setMaxHp(int new_maxHp) {
    maxHp = new_maxHp;
}

int Stats::getMp() const {
    return mp;
}

void Stats::setMp(int new_mp) {
    mp = new_mp;
}

int Stats::getMaxMp() const {
    return maxMp;
}

void Stats::setMaxMp(int new_maxMp) {
    maxMp = new_maxMp;
}

int Stats::getArmor() const {
    return armor;
}

void Stats::setArmor(int new_armor) {
    armor = new_armor;
}

int Stats::getDamage() const {
    return damage;
}

void Stats::setDamage(int new_damage) {
    damage = new_damage;
}

float Stats::getCritChance() const {
    return critChance;
}

void Stats::setCritChance(float new_critChance) {
    critChance = new_critChance;
}

float Stats::getEvadeChance() const {
    return evadeChance;
}

void Stats::setEvadeChance(float new_evadeChance) {
    evadeChance = new_evadeChance;
}

int Stats::getAgility() const {
    return agility;
}

void Stats::setAgility(int new_agility) {
    agility = new_agility;
}

int Stats::getWisdom() const {
    return wisdom;
}

void Stats::setWisdom(int new_wisdom) {
    wisdom = new_wisdom;
}

int Stats::getStrength() const{
    return strength;
}

void Stats::setStrength(int new_strength) {
    strength = new_strength;
}

int Stats::getFreePoints() const {
    return freePoints;
}

void Stats::setFreePoints(int new_freePoints) {
    freePoints = new_freePoints;
}

int Stats::getMaxHpBonus() const {
    return maxHpBonus;
}

void Stats::setMaxHpBonus(int new_maxHpBonus) {
    maxHpBonus = new_maxHpBonus;
}

int Stats::getMaxMpBonus() const {
    return maxMpBonus;
}

void Stats::setMaxMpBonus(int new_maxMpBonus) {
    maxMpBonus = new_maxMpBonus;
}

int Stats::getDamageBonus() const {
    return damageBonus;
}

void Stats::setDamageBonus(int new_damageBonus) {
    damageBonus = new_damageBonus;
}

int Stats::getArmorBonus() const {
    return armorBonus;
}

void Stats::setArmorBonus(int new_armorBonus) {
    armorBonus = new_armorBonus;
}

float Stats::getCritChanceBonus() const {
    return critChanceBonus;
}

void Stats::setCritChanceBonus(float new_critChanceBonus) {
    critChanceBonus = new_critChanceBonus;
}

float Stats::getEvadeChanceBonus() const {
    return evadeChanceBonus;
}

void Stats::setEvadeChanceBonus(float new_evadeChanceBonus) {
    evadeChanceBonus = new_evadeChanceBonus;
}

int Stats::getFinalHp() const {
    return maxHp + maxHpBonus;
}

int Stats::getFinalMp() const {
    return maxMp + maxMpBonus;
}

int Stats::getFinalDamage() const {
    return damage + damageBonus;
}

int Stats::getFinalArmor() const {
    return armor + armorBonus;
}

float Stats::getFinalCritChance() const {
    return critChance + critChanceBonus;
}

float Stats::getFinalEvadeChance() const {
    return evadeChance + evadeChanceBonus;
}

float Stats::getSpellDmgMultiplier() const {
    return spellDmgMultiplier;
}

std::string Stats::toString(const std::string& prefix) const {
    std::stringstream ss;
    ss << "-------------------- " << prefix << " Stats --------------------" << std::endl;
    ss << "Level: [" << level << "]"
            << " Exp: [" << exp << "]"
            << " MaxExp: [" << maxExp << "]"
            << " Hp: [" << hp << "]"
            << " MaxHp: [" << maxHp << "]"
            << " Mp: [" << mp << "]"
            << " MaxMp: [" << maxMp << "]"
            << " Armor: [" << armor << "]"
            << " Damage: [" << damage << "]"
            << " CritChance: [" << critChance << "]"
            << " EvadeChance: [" << evadeChance << "]" << std::endl
            << "Agility: [" << agility << "]"
            << " Wisdom: [" << wisdom << "]"
            << " Strength: [" << strength << "]"
            << " Freepoints: [" << freePoints << "]"
            << " SpellDmgMultiplier: [" << spellDmgMultiplier << "]" << std::endl
            << "MaxHpBonus: [" << maxHpBonus << "]"
            << " MaxMpBonus: [" << maxMpBonus << "]"
            << " DamageBonus: [" << damageBonus << "]"
            << " ArmorBonus: [" << armorBonus << "]"
            << " CritchanceBonus: [" << critChanceBonus << "]"
            << " EvadeChanceBonus: [" << evadeChanceBonus << "]" << std::endl;
    ss << "------------------End- " << prefix << " Stats -End ------------------" << std::endl;
    return ss.str();
}
