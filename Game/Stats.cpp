//
// Created by root on 10/6/20.
//

#include "Stats.h"

Stats::Stats(){
    maxHpBonus = 0;
    maxMpBonus = 0;
    damageBonus = 0;
    armorBonus = 0;
    critChanceBonus = 0;
    evadeChanceBonus = 0;
    spellDmgMultiplier = 1.f;
}

Stats::~Stats(){

}

bool Stats::addExp(int earned) {
    bool leveledUp = false;
    exp = exp + earned;

    while(exp >= maxExp){                //SE RAGGIUNTA QNT NECESSARIA A LIVELLARE

        int newExp = exp - maxExp;    //EXP IN ECCESSO AGGIUNTA PER FARE IL PROX LIVELLO

        int choise = 0;     //SCRIVERE CODICE PER EFFETTUARE SCELTA TRA 3 ATTRIBUTI

        levelUp(choise, newExp);
        leveledUp = true;
    }

    return leveledUp;
//    Stats::exportStats();
}

void Stats::addAttribute(int type) {
    if(type == 0){ //strength
        strength++;

        maxHp = maxHp +25;
        hp = maxHp;
        armor = armor +2;
        freePoints --;
    }else if(type == 1){ //wisdom
        wisdom ++;

        maxMp = Stats::maxMp +25;
        mp = Stats::maxMp;
        freePoints --;
    }else if(type ==2){ //agility
        agility ++;

        critChance = critChance +5;
        evadeChance = evadeChance +3;
        freePoints --;
    }
    updateMultipliers();
}

void Stats::levelUp(int choise, int newExp) {
    level ++;
    exp = newExp;
    maxExp = Stats::maxExp +25;          //EXP MAX PER LIVELLARE AUMENTATA

    maxHp = Stats::maxHp +25;
    hp = maxHp + maxHpBonus;               //HP RIGENERATI
    maxMp = Stats::maxMp +25;
    mp = maxMp + maxMpBonus;               //MP RIGENERATI
    armor = armor + 4;
    damage = damage +4;

    freePoints += 3;
    switch (choise) {           //SCELTA TRA AGILITY WISDOM E STRENGTH
        case 1:     //STRENGTH
            strength++;
            maxHp = maxHp + 25;
            hp = maxHp;
            armor = armor + 2;
            break;
        case 2:     //AGILITY
            agility ++;
            critChance = critChance + 0.5f;
            evadeChance = evadeChance + 0.5f;
            break;
        case 3:     //WISDOM
            wisdom ++;
            maxMp = maxMp + 25;
            mp = maxMp;
            break;
        default:
            break;
    }
}

int Stats::getLevel() {
    return level;
}

void Stats::setLevel(int level) {
    Stats::level = level;
}

int Stats::getExp() {
    return exp;
}

void Stats::setExp(int exp) {
    Stats::exp = exp;
}

int Stats::getMaxExp() {
    return maxExp;
}

void Stats::setMaxExp(int maxExp) {
    Stats::maxExp = maxExp;
}

int Stats::getHp() {
    return hp;
}

void Stats::setHp(int hp) {
    Stats::hp = hp;
}

int Stats::getMaxHp() {
    return maxHp;
}

void Stats::setMaxHp(int maxHp) {
    Stats::maxHp = maxHp;
}

int Stats::getMp() {
    return mp;
}

void Stats::setMp(int mp) {
    Stats::mp = mp;
}

int Stats::getMaxMp() {
    return maxMp;
}

void Stats::setMaxMp(int maxMp) {
    Stats::maxMp = maxMp;
}

int Stats::getArmor() {
    return armor;
}

void Stats::setArmor(int armor) {
    Stats::armor = armor;
}

int Stats::getDamage() {
    return damage;
}

void Stats::setDamage(int damage) {
    Stats::damage = damage;
}

float Stats::getCritChance() {
    return critChance;
}

void Stats::setCritChance(float critChance) {
    Stats::critChance = critChance;
}

float Stats::getEvadeChance() {
    return evadeChance;
}

void Stats::setEvadeChance(float evadeChance) {
    Stats::evadeChance = evadeChance;
}

int Stats::getAgility() {
    return agility;
}

void Stats::setAgility(int agility) {
    this->agility = agility;
    critChance = critChance + (0.5f * agility);
    evadeChance = evadeChance + (0.5f * agility);
}

int Stats::getWisdom() {
    return wisdom;
}

void Stats::setWisdom(int wisdom) {
    Stats::wisdom = wisdom;
    maxMp = maxMp + (25 * wisdom);
    mp = maxMp;
}

int Stats::getStrength(){
    return strength;
}

void Stats::setStrength(int strength) {
    this->strength = strength;
    maxHp = maxHp + (25 * strength);
    hp = maxHp;
    armor = armor + (2 * strength);
}

int Stats::getFreePoints() {
    return freePoints;
}

void Stats::setFreePoints(int freePoints) {
    this->freePoints = freePoints;
}

int Stats::getMaxHpBonus() const {
    return maxHpBonus;
}

void Stats::setMaxHpBonus(int maxHpBonus) {
    Stats::maxHpBonus = maxHpBonus;
}

int Stats::getMaxMpBonus() const {
    return maxMpBonus;
}

void Stats::setMaxMpBonus(int maxMpBonus) {
    Stats::maxMpBonus = maxMpBonus;
}

int Stats::getDamageBonus() const {
    return damageBonus;
}

void Stats::setDamageBonus(int damageBonus) {
    Stats::damageBonus = damageBonus;
}

int Stats::getArmorBonus() const {
    return armorBonus;
}

void Stats::setArmorBonus(int armorBonus) {
    Stats::armorBonus = armorBonus;
}

float Stats::getCritChanceBonus() const {
    return critChanceBonus;
}

void Stats::setCritChanceBonus(float critChanceBonus) {
    Stats::critChanceBonus = critChanceBonus;
}

float Stats::getEvadeChanceBonus() const {
    return evadeChanceBonus;
}

void Stats::setEvadeChanceBonus(float evadeChanceBonus) {
    Stats::evadeChanceBonus = evadeChanceBonus;
}

int Stats::getFinalHp() {
    return maxHp + maxHpBonus;
}

int Stats::getFinalMp() {
    return maxMp + maxMpBonus;
}

int Stats::getFinalDamage() {
    return damage + damageBonus;
}

int Stats::getFinalArmor() {
    return armor + armorBonus;
}

float Stats::getFinalCritChance() {
    return critChance + critChanceBonus;
}

float Stats::getFinalEvadeChance() {
    return evadeChance + evadeChanceBonus;
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
    spellDmgMultiplier = 1.f + wisdom/10.f;
}

void Stats::updateMultipliers() {
    updateSpellDmgMultiplier();
}

float Stats::getSpellDmgMultiplier() {
    return spellDmgMultiplier;
}

std::string Stats::getFinalCritChanceFixed() {
    stringstream ss;
    ss << getFinalCritChance();
    return ss.str();
}

std::string Stats::getFinalEvadeChanceFixed() {
    stringstream ss;
    ss << getFinalEvadeChance();
    return ss.str();
}

int Stats::getHit(int hit_damage, float block_percentage) {
    //reduce damage with armor
    hit_damage -= getFinalArmor();
    //reduce damage with block
    hit_damage -= (float)(hit_damage/100.f) * block_percentage;

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

