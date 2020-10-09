//
// Created by root on 10/6/20.
//

#include "Stats.h"

bool Stats::addExp(int earned) {
    Stats::exp = Stats::exp + earned;

    if(Stats::exp >= Stats::maxExp){                //SE RAGGIUNTA QNT NECESSARIA A LIVELLARE

        int newExp = Stats::exp - Stats::maxExp;    //EXP IN ECCESSO AGGIUNTA PER FARE IL PROX LIVELLO

        int choise = 2;     //SCRIVERE CODICE PER EFFETTUARE SCELTA TRA 3 ATTRIBUTI

        Stats::levelUp(choise, newExp);

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
    Stats::importStats();

    Stats::level ++;
    Stats::exp = newExp;
    Stats::maxExp = Stats::maxExp +25;          //EXP MAX PER LIVELLARE AUMENTATA

    Stats::maxHp = Stats::maxHp +25;
    Stats::hp = Stats::maxHp;               //HP RIGENERATI
    Stats::maxMp = Stats::maxMp +25;
    Stats::mp = Stats::maxMp;               //MP RIGENERATI
    Stats::armor = Stats::armor +2;


    switch (choise) {           //SCELTA TRA AGILITY WISDOM E STRENGTH
        case 1:     //STRENGTH
            Stats::strength++;

            Stats::maxHp = Stats::maxHp +25;
            Stats::hp = Stats::maxHp;
            Stats::armor = Stats::armor +2;
            break;
        case 2:     //AGILITY
            Stats::agility ++;

            Stats::critChance = Stats::critChance +5;
            Stats::evadeChance = Stats::evadeChance +3;
            break;
        case 3:     //WISDOM
            Stats::wisdom ++;

            Stats::maxMp = Stats::maxMp +25;
            Stats::mp = Stats::maxMp;
            break;
        default:
            break;
    }

    Stats::exportStats();
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

Stats::Stats(){

}

Stats::~Stats(){

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
