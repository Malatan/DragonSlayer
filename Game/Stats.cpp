//
// Created by root on 10/6/20.
//

#include "Stats.h"

Stats::Stats(){
    this->maxHpBonus = 0;
    this->maxMpBonus = 0;
    this->damageBonus = 0;
    this->armorBonus = 0;
    this->critChanceBonus = 0;
    this->evadeChanceBonus = 0;
    this->spellDmgMultiplier = 1.f;
}

Stats::~Stats(){

}

bool Stats::addExp(int earned) {
    bool leveledUp = false;
    this->exp = this->exp + earned;

    while(this->exp >= this->maxExp){                //SE RAGGIUNTA QNT NECESSARIA A LIVELLARE

        int newExp = this->exp - this->maxExp;    //EXP IN ECCESSO AGGIUNTA PER FARE IL PROX LIVELLO

        int choise = 0;     //SCRIVERE CODICE PER EFFETTUARE SCELTA TRA 3 ATTRIBUTI

        this->levelUp(choise, newExp);
        leveledUp = true;
    }

    return leveledUp;
//    Stats::exportStats();
}

void Stats::addAttribute(int type) {
    if(type == 0){ //strength
        this->strength++;

        this->maxHp = this->maxHp +25;
        this->hp = this->maxHp;
        this->armor = this->armor +2;
        this->freePoints --;
    }else if(type == 1){ //wisdom
        this->wisdom ++;

        this->maxMp = Stats::maxMp +25;
        this->mp = Stats::maxMp;
        this->freePoints --;
    }else if(type ==2){ //agility
        this->agility ++;

        this->critChance = this->critChance +5;
        this->evadeChance = this->evadeChance +3;
        this->freePoints --;
    }
    this->updateMultipliers();
}

void Stats::levelUp(int choise, int newExp) {
   // this->importStats();

    this->level ++;
    this->exp = newExp;
    this->maxExp = Stats::maxExp +25;          //EXP MAX PER LIVELLARE AUMENTATA

    this->maxHp = Stats::maxHp +25;
    this->hp = this->maxHp + this->maxHpBonus;               //HP RIGENERATI
    this->maxMp = Stats::maxMp +25;
    this->mp = this->maxMp + this->maxMpBonus;               //MP RIGENERATI
    this->armor = Stats::armor +2;

    this->freePoints += 3;


    switch (choise) {           //SCELTA TRA AGILITY WISDOM E STRENGTH
        case 1:     //STRENGTH
            this->strength++;

            this->maxHp = this->maxHp +25;
            this->hp = this->maxHp;
            this->armor = this->armor +2;
            break;
        case 2:     //AGILITY
            this->agility ++;

            this->critChance = this->critChance +5;
            this->evadeChance = this->evadeChance +3;
            break;
        case 3:     //WISDOM
            this->wisdom ++;

            this->maxMp = Stats::maxMp +25;
            this->mp = Stats::maxMp;
            break;
        default:
            break;
    }

  //  this->exportStats();
}

bool Stats::exportStats() {

    ofstream file;
    file.open("Stats.txt");

    if (!file.is_open()){
        return false;
    } else {
        file<<to_string(Stats::level) + "\n";
        file<<to_string(Stats::exp) + "\n";
        file<<to_string(Stats::maxExp) + "\n";
        file<<to_string(Stats::maxHp) + "\n";
        file<<to_string(Stats::maxMp) + "\n";
        file<<to_string(Stats::armor) + "\n";
        file<<to_string(Stats::damage) + "\n";
        file<<to_string(Stats::critChance) + "\n";
        file<<to_string(Stats::evadeChance) + "\n";
        file<<to_string(Stats::agility) + "\n";
        file<<to_string(Stats::wisdom) + "\n";
        file<<to_string(Stats::strength) + "\n";
    }

    return true;

}

string Stats::listStats() {
    string desc = "";
    desc+=   "LEVEL " + to_string(Stats::level) + " [" + to_string(Stats::exp)+ "/" + to_string(Stats::maxExp)+ " exp]\n"
            +"HP - " + to_string(Stats::hp) + "/" + to_string(Stats::maxHp) + "\n"
            +"MP - " + to_string(Stats::mp) + "/" + to_string(Stats::maxMp) + "\n"
            +"Armor - " + to_string(Stats::armor + Stats::armorBonus) + "\n"
            +"Damage - " + to_string(Stats::damage + Stats::damageBonus) + "\n"
            +"Crtical Chance - " + to_string(Stats::critChance) + "%\n"
            +"Evade Chance - " + to_string(Stats::evadeChance) + "%\n"
            +"Agility - " + to_string(Stats::agility) + "\n"
            +"Wisdom - " + to_string(Stats::wisdom) + "\n"
            +"Strength - " + to_string(Stats::strength) + "\n";
    return desc;
}

int Stats::getLevel() {
    return this->level;
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
    Stats::agility = agility;
}

int Stats::getWisdom() {
    return wisdom;
}

void Stats::setWisdom(int wisdom) {
    Stats::wisdom = wisdom;
}

int Stats::getStrength(){
    return strength;
}

void Stats::setStrength(int strength) {
    Stats::strength = strength;
}

int Stats::getFreePoints() {
    return this->freePoints;
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
    return this->maxHp + this->maxHpBonus;
}

int Stats::getFinalMp() {
    return this->maxMp + this->maxMpBonus;
}

int Stats::getFinalDamage() {
    return this->damage + this->damageBonus;
}

int Stats::getFinalArmor() {
    return this->armor + this->armorBonus;
}

float Stats::getFinalCritChance() {
    return this->critChance + this->critChanceBonus;
}

float Stats::getFinalEvadeChance() {
    return this->evadeChance + this->evadeChanceBonus;
}

void Stats::checkHpLimit() {
    if(this->hp > (this->maxHp+this->maxHpBonus))
        this->hp = this->maxHp+this->maxHpBonus;
}

void Stats::checkMpLimit() {
    if(this->mp > (this->maxMp+this->maxMpBonus))
        this->mp = this->maxMp+this->maxMpBonus;
}

int Stats::gainHp(int gain_amount) {
    int restore_amount = gain_amount;
    if((this->hp + gain_amount) > this->getFinalHp()){
        restore_amount = this->getFinalHp() - this->hp;
        this->hp = this->getFinalHp();
    } // 250/300 150
    else{
        this->hp += gain_amount;
    }
    return restore_amount;
}

int Stats::gainMp(int gain_amount) {
    int restore_amount = gain_amount;
    if((this->mp + gain_amount) > this->getFinalMp()){
        restore_amount = this->getFinalMp() - this->mp;
        this->mp = this->getFinalMp();
    } // 250/300 150
    else{
        this->mp += gain_amount;
    }
    return restore_amount;
}

void Stats::updateSpellDmgMultiplier() {
    this->spellDmgMultiplier = 1.f + this->wisdom/10.f;
}

void Stats::updateMultipliers() {
    this->updateSpellDmgMultiplier();
}

float Stats::getSpellDmgMultiplier() {
    return this->spellDmgMultiplier;
}

