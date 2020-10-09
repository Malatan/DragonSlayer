//
// Created by root on 10/6/20.
//

#include "Stats.h"

Stats::Stats(){
    this->level = 0;
    this->exp = 0;
    this->maxExp = 100;

    this->hp = 100;
    this->maxHp = 100;
    this->mp = 100;
    this->maxMp = 100;
    this->armor = 10;
    this->armorBonus = 0;
    this->damage = 20;
    this->damageBonus = 0;
    this->critChance = 5;     //in %
    this->evadeChance = 5;    //in %
    this->agility = 3;
    this->wisdom = 3;
    this->strength = 3;
    this->freePoints = 0;
}

Stats::~Stats(){

}

bool Stats::addExp(int earned) {
    this->exp = this->exp + earned;

    if(this->exp >= this->maxExp){                //SE RAGGIUNTA QNT NECESSARIA A LIVELLARE

        int newExp = this->exp - this->maxExp;    //EXP IN ECCESSO AGGIUNTA PER FARE IL PROX LIVELLO

        int choise = 0;     //SCRIVERE CODICE PER EFFETTUARE SCELTA TRA 3 ATTRIBUTI

        this->levelUp(choise, newExp);

        return true;
    }

    Stats::exportStats();
    return false;
}

int Stats::getArmorBonus() {
    return armorBonus;
}

void Stats::setArmorBonus(int armorBonus) {
    Stats::armorBonus = armorBonus;
}

int Stats::getDamageBonus() {
    return damageBonus;
}

void Stats::setDamageBonus(int damageBonus) {
    Stats::damageBonus = damageBonus;
}

void Stats::levelUp(int choise, int newExp) {
   // this->importStats();

    this->level ++;
    this->exp = newExp;
    this->maxExp = Stats::maxExp +25;          //EXP MAX PER LIVELLARE AUMENTATA

    this->maxHp = Stats::maxHp +25;
    this->hp = Stats::maxHp;               //HP RIGENERATI
    this->maxMp = Stats::maxMp +25;
    this->mp = Stats::maxMp;               //MP RIGENERATI
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

void Stats::importStats() {

    ifstream file;
    file.open("Stats.txt");

    if (!file.is_open()){
        cout<<"#Can't open Stats.txt";
    } else {
        string word;
        int current=0;

        while (file >> word) {
            if(current==0){
                stringstream intLevel(word);
                int level;
                intLevel >> level;
                Stats::level = level;
                current++;
            }else if(current==1){
                stringstream intExp(word);
                int exp;
                intExp >> exp;
                Stats::exp = exp;
                current++;
            }else if(current==2){
                stringstream intMaxExp(word);
                int maxExp;
                intMaxExp >> maxExp;
                Stats::maxExp = maxExp;
                current++;
            }else if(current==3){
                stringstream intMaxHp(word);
                int maxHp;
                intMaxHp >> maxHp;
                Stats::maxHp = maxHp;
                Stats::hp = maxHp;          //quando carichiamo i salvataggi il player è "FULL HP"
                current++;
            }else if(current==4){
                stringstream intMaxMp(word);
                int maxMp;
                intMaxMp >> maxMp;
                Stats::maxMp = maxMp;
                Stats::mp = maxMp;             //quando carichiamo i salvataggi il player è "FULL MP"
                current++;
            }else if(current==5){
                stringstream intArmor(word);
                int armor;
                intArmor >> armor;
                Stats::armor = armor;
                current++;
            }else if(current==6) {
                stringstream intDamage(word);
                int damage;
                intDamage >> damage;
                Stats::damage = damage;
                current++;
            }else if(current==7){
                stringstream intCrit(word);
                int crit;
                intCrit >> crit;
                Stats::critChance = crit;
                current++;
            }else if(current==8){
                stringstream intEvade(word);
                int evade;
                intEvade >> evade;
                Stats::evadeChance = evade;
                current++;
            }else if(current==9){
                stringstream intAgility(word);
                int agility;
                intAgility >> agility;
                Stats::agility = agility;
                current++;
            }else if(current==10){
                stringstream intWisdom(word);
                int wisdom;
                intWisdom >> wisdom;
                Stats::wisdom = wisdom;
                current++;
            }else if(current==11){
                stringstream intStrength(word);
                int strength;
                intStrength >> strength;
                Stats::strength = strength;
                current++;
            }

        }
    }
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

int Stats::getCritChance() {
    return critChance;
}

void Stats::setCritChance(int critChance) {
    Stats::critChance = critChance;
}

int Stats::getEvadeChance() {
    return evadeChance;
}

void Stats::setEvadeChance(int evadeChance) {
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
