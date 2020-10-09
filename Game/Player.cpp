//
// Created by Zheng on 07/10/2020.
//

#include "Player.h"

//initializer functions
void Player::initVariables() {

}

void Player::initAnimations() {
    this->animationComponent->addAnimation("IDLE", 10.f,
            0, 0, 14, 0, 64 ,64);
    this->animationComponent->addAnimation("WALK", 6.f,
            0, 1, 7, 1, 64 ,64);
}

//constructors/destructors
Player::Player(float x, float y, float scale_x, float scale_y, sf::Texture& texture_sheet) {
    this->scale.x = scale_x;
    this->scale.y = scale_y;
    this->sprite.setScale(this->scale);

    this->createAnimationComponent(texture_sheet);
    this->createMovementComponent(120.f, 8.f, 4.f);
    this->createHitboxComponent(this->sprite, 46, 26.f, 50.f, 65.f);
    this->initAnimations();

    this->setPosition(x, y);

    this->setPlayerStats(new Stats());

}

Player::Player(int gold, Inventory invent) {
    this->gold = gold;
    this->invent = invent;
}

Player::Player() {

}

Player::~Player() {

}

//functions
void Player::updateAnimation(const float &dt) {

    if(this->movementComponent->getState(IDLE)){
        this->animationComponent->play("IDLE", dt);

    } else if(this->movementComponent->getState(MOVING_LEFT)){
        this->sprite.setOrigin(70.f, 0.f);
        this->sprite.setScale(-this->scale.x, this->scale.y);
        this->animationComponent->play("WALK", dt,
                                       this->movementComponent->getVelocity().x,
                                       this->movementComponent->getMaxVelocity());

    } else if(this->movementComponent->getState(MOVING_RIGHT)){
        this->sprite.setOrigin(0.f, 0.f);
        this->sprite.setScale(this->scale.x, this->scale.y);
        this->animationComponent->play("WALK", dt,
                                       this->movementComponent->getVelocity().x,
                                       this->movementComponent->getMaxVelocity());

    } else if(this->movementComponent->getState(MOVING_UP)){
        this->animationComponent->play("WALK", dt,
                                       this->movementComponent->getVelocity().y,
                                       this->movementComponent->getMaxVelocity());

    } else if(this->movementComponent->getState(MOVING_DOWN)){
        this->animationComponent->play("WALK", dt,
                                       this->movementComponent->getVelocity().y,
                                       this->movementComponent->getMaxVelocity());

    }
}

void Player::update(const float &dt) {
    this->movementComponent->update(dt);
    this->updateAnimation(dt);
    this->hitboxComponent->update();
}

void Player::render(sf::RenderTarget &target, const bool show_hitbox) {
    target.draw(this->sprite);
    if(show_hitbox)
        this->hitboxComponent->render(target);
}

string Player::playerDetails() {
    string desc = "";

    desc+= "PLAYER LIV." + to_string(Player::getPlayerStats()->getLevel())
           + "     HP[";

    int health =0;
    for(int i=0; i<Player::getPlayerStats()->getMaxHp(); i=i+10){
        if(health <= Player::getPlayerStats()->getHp())
            desc+="#";
        else
            desc+="-";
        health += 10;
    }

    desc+= to_string(Player::getPlayerStats()->getHp()) + "/" + to_string(Player::getPlayerStats()->getMaxHp()) + "]\n"
           + "     Armor: " + to_string(Player::getPlayerStats()->getArmor() + Player::getPlayerStats()->getArmorBonus())
           + "     Damage: " + to_string(Player::getPlayerStats()->getDamage() + Player::getPlayerStats()->getDamageBonus()) + "\n";

    return desc;
}

int Player::takeDamage(int dmg) {
    dmg = dmg - this->playerStats.getArmor();
    int newHp = this->playerStats.getHp() - dmg;
    this->playerStats.setHp(newHp);

    return dmg;
}

void Player::earnExp(int exp) {
    this->playerStats.addExp(exp);       //SE CON EXP IL PLAYER SALE DI LIVELLO
}

void Player::learnSpell(string spell) {
    for(int i=0; i<3; i++){
        if(spells[i].getName() == spell){
            spells[i].setLearned(true);
        }
    }
}

void Player::reloadEquipStats() {
    int armorBonus = 0;
    int damageBonus = 0;

    damageBonus += Player::weapon.getDamage();
    armorBonus += Player::shield.getArmor();
    armorBonus += Player::head.getArmor();
    armorBonus += Player::chest.getArmor();
    armorBonus += Player::arms.getArmor();
    armorBonus += Player::legs.getArmor();

    Player::playerStats.setArmorBonus(armorBonus);
    Player::playerStats.setDamageBonus(damageBonus);
}

string  Player::listEquipment() {
    string desc = "";
    desc+=  "Weapon: " + Player::weapon.getName() + "\n" +
            " - " + Player::weapon.getDescription() + "\n" +
            " - " + Player::weapon.getRarity() + "\n" +
            " - " + to_string(Player::weapon.getValue()) + " gold\n" +
            " - " + to_string(Player::weapon.getDamage()) + " dmg\n" +
            " - " + to_string(Player::weapon.getDurability()) + " uses\n" +
            "Shield: " + Player::shield.getName() + "\n" +
            " - " + Player::shield.getDescription() + "\n" +
            " - " + Player::shield.getRarity() + "\n" +
            " - " + to_string(Player::shield.getValue()) + " gold\n" +
            " - " + to_string(Player::shield.getArmor()) + " armor\n" +
            "Head: " + Player::head.getName() + "\n" +
            " - " + Player::head.getDescription() + "\n" +
            " - " + Player::head.getRarity() + "\n" +
            " - " + to_string(Player::head.getValue()) + " gold\n" +
            " - " + to_string(Player::head.getArmor()) + " armor\n" +
            "Chest: " + Player::chest.getName() + "\n" +
            " - " + Player::chest.getDescription() + "\n" +
            " - " + Player::chest.getRarity() + "\n" +
            " - " + to_string(Player::chest.getValue()) + " gold\n" +
            " - " + to_string(Player::chest.getArmor()) + " armor\n" +
            "Arms: " + Player::arms.getName() + "\n" +
            " - " + Player::arms.getDescription() + "\n" +
            " - " + Player::arms.getRarity() + "\n" +
            " - " + to_string(Player::arms.getValue()) + " gold\n" +
            " - " + to_string(Player::arms.getArmor()) + " armor\n" +
            "Legs: " + Player::legs.getName() + "\n"
                                                " - " + Player::legs.getDescription() + "\n" +
            " - " + Player::legs.getRarity() + "\n" +
            " - " + to_string(Player::legs.getValue()) + " gold\n" +
            " - " + to_string(Player::legs.getArmor()) + " armor\n";

    return desc;
}

string Player::listSpells(){
    string desc = "";
    string lock;

    for (int i=0; i<3; i++){
        if(Player::spells[i].isLearned() == true)
            lock = "UNLOCKED";
        else
            lock = "LOCKED";

        desc+=  Player::spells[i].getName() + "[" + lock +"]\n"
                + " - " + Player::spells[i].getType() + "\n"
                + " - " + to_string(Player::spells[i].getDamage()) + " damage\n"
                + " - target " + to_string(Player::spells[i].getAoe()) + " enemies\n"
                + " - " + to_string(Player::spells[i].getCost()) + " mp\n"
                + " - " + to_string(Player::spells[i].getCooldown()) + "s cooldown \n";
    }



    return desc;
}

void Player::importSpells() {
    ifstream file;
    file.open("Spells.txt");

    if (!file.is_open()){
        cout<<"#Can't open Spells.txt";
    } else {
        string word;
        int current = 0;
        int i = 0;

        while (file >> word) {
            if(current == 0){
                spells[i].setName(word);
                current ++;
            }else if(current == 1){
                spells[i].setType(word);
                current ++;
            }else if(current == 2){
                stringstream intCost(word);
                int cost;
                intCost >> cost;
                spells[i].setCost(cost);
                current ++;
            }else if(current == 3){
                stringstream intCooldown(word);
                int cooldown;
                intCooldown >> cooldown;
                spells[i].setCooldown(cooldown);
                current ++;
            }else if(current == 4){
                stringstream intDamage(word);
                int damage;
                intDamage >> damage;
                spells[i].setDamage(damage);
                current ++;
            }else if(current == 5){
                stringstream intAoe(word);
                int aoe;
                intAoe >> aoe;
                spells[i].setAoe(aoe);
                current ++;
            }else if(current == 6){
                stringstream intLearned(word);
                int learned;
                intLearned >> learned;
                if(learned == 1){
                    spells[i].setLearned(true);
                }else{
                    spells[i].setLearned(false);
                }
                current = 0;
                i++;
            }
        }
    }
}

bool Player::exportSpells() {

    ofstream file;
    file.open("Spells.txt");

    if(!file.is_open()) {
        return false;
    } else {
        int learn;
        for (int i=0; i<3; i++) {
            file<<Player::spells[i].getName() + " ";
            file<<Player::spells[i].getType() + " ";
            file<<to_string(Player::spells[i].getCost()) + " ";
            file<<to_string(Player::spells[i].getCooldown()) + " ";
            file<<to_string(Player::spells[i].getDamage()) + " ";
            file<<to_string(Player::spells[i].getAoe()) + " ";
            if(Player::spells[i].isLearned())
                learn = 1;
            else
                learn = 0;
            file<<to_string(learn) + " \n";
        }

        file.close();
        return true;
    }

}

bool Player::exportEquipment() {

    ofstream file;
    file.open("Equipment.txt");

    if (!file.is_open()){
        return false;
    } else {
        file<<Player::weapon.getItemType()+ " ";
        file<<Player::weapon.getName() + " ";
        file<<Player::weapon.getDescription() + " ";
        file<<to_string(Player::weapon.getValue()) + " ";
        file<<Player::weapon.getRarity() + " ";
        file<<Player::weapon.getIcon() + " ";
        file<<to_string(Player::weapon.getDamage()) + " ";
        file<<Player::weapon.getWeaponType() + " ";
        file<<to_string(Player::weapon.getDurability()) + " \n";

        file<<Player::shield.getItemType()+ " ";
        file<<Player::shield.getName() + " ";
        file<<Player::shield.getDescription() + " ";
        file<<to_string(Player::shield.getValue()) + " ";
        file<<Player::shield.getRarity() + " ";
        file<<Player::shield.getIcon() + " ";
        file<<to_string(Player::shield.getArmor()) + " ";
        file<<Player::shield.getArmorType() + " \n";

        file<<Player::head.getItemType()+ " ";
        file<<Player::head.getName() + " ";
        file<<Player::head.getDescription() + " ";
        file<<to_string(Player::head.getValue()) + " ";
        file<<Player::head.getRarity() + " ";
        file<<Player::head.getIcon() + " ";
        file<<to_string(Player::head.getArmor()) + " ";
        file<<Player::head.getArmorType() + " \n";

        file<<Player::chest.getItemType()+ " ";
        file<<Player::chest.getName() + " ";
        file<<Player::chest.getDescription() + " ";
        file<<to_string(Player::chest.getValue()) + " ";
        file<<Player::chest.getRarity() + " ";
        file<<Player::chest.getIcon() + " ";
        file<<to_string(Player::chest.getArmor()) + " ";
        file<<Player::chest.getArmorType() + " \n";

        file<<Player::arms.getItemType()+ " ";
        file<<Player::arms.getName() + " ";
        file<<Player::arms.getDescription() + " ";
        file<<to_string(Player::arms.getValue()) + " ";
        file<<Player::arms.getRarity() + " ";
        file<<Player::arms.getIcon() + " ";
        file<<to_string(Player::arms.getArmor()) + " ";
        file<<Player::arms.getArmorType() + " \n";

        file<<Player::legs.getItemType()+ " ";
        file<<Player::legs.getName() + " ";
        file<<Player::legs.getDescription() + " ";
        file<<to_string(Player::legs.getValue()) + " ";
        file<<Player::legs.getRarity() + " ";
        file<<Player::legs.getIcon() + " ";
        file<<to_string(Player::legs.getArmor()) + " ";
        file<<Player::legs.getArmorType() + " \n";

        file.close();
        return true;
    }

}

void Player::importEquipment() {
    ifstream file;
    file.open("Equipment.txt");

    if (!file.is_open()){
        cout<<"#Can't open Equipment.txt";
    } else {
        string word;

        int newlineCont = 0;
        int current;
        Item i = Item();

        while (file >> word) {
            if(newlineCont == 0){
                if(word == "W"){            //ITEM
                    current = 1;
                    newlineCont = 8;
                    i.setItemType(word);
                }else if(word == "E"){      //EQUIP
                    current = 2;
                    newlineCont = 7;
                    i.setItemType(word);
                }
            }else{
                switch(current){
                    case 1:             //WEAPON
                        if(newlineCont == 8){
                            i.setName(word);
                        }else if(newlineCont == 7){
                            i.setDescription(word);
                        }else if(newlineCont == 6){
                            stringstream intValue(word);
                            int value;
                            intValue >> value;
                            i.setValue(value);
                        }else if(newlineCont == 5){
                            i.setRarity(word);
                        }else if(newlineCont == 4){
                            i.setIcon(word);
                        }else if(newlineCont == 3){
                            stringstream intValue(word);
                            int damage;
                            intValue >> damage;
                            i.setDamage(damage);
                        }else if(newlineCont == 2){
                            i.setWeaponType(word);
                        }else if(newlineCont == 1){
                            stringstream intValue(word);
                            int durability;
                            intValue >> durability;
                            i.setDurability(durability);

                            i.setArmor(0);
                            i.setArmorType("");

                            Player::weapon = i;
                        }

                        newlineCont --;
                        break;

                    case 2:             //ARMATURE
                        if(newlineCont == 7){
                            i.setName(word);
                        }else if(newlineCont == 6){
                            i.setDescription(word);
                        }else if(newlineCont == 5){
                            stringstream intValue(word);
                            int value;
                            intValue >> value;
                            i.setValue(value);
                        }else if(newlineCont == 4){
                            i.setRarity(word);
                        }else if(newlineCont == 3){
                            i.setIcon(word);
                        }else if(newlineCont == 2){
                            stringstream intValue(word);
                            int armor;
                            intValue >> armor;
                            i.setArmor(armor);
                        }else if(newlineCont == 1){
                            i.setArmorType(word);

                            i.setDamage(0);
                            i.setWeaponType("");
                            i.setDurability(0);

                            if(i.getArmorType() == "head"){
                                Player::head = i;
                            }else if(i.getArmorType() == "chest"){
                                Player::chest = i;
                            }else if(i.getArmorType() == "arms"){
                                Player::arms = i;
                            }else if(i.getArmorType() == "legs"){
                                Player::legs = i;
                            }else if(i.getArmorType() == "shield"){
                                Player::shield = i;
                            }
                        }

                        newlineCont --;
                        break;

                    default:
                        cout<<"#Import error"<<endl;
                        break;
                }

            }

        }
    }
}

Stats* Player::getPlayerStats() {
    return &this->playerStats;
}

void Player::setPlayerStats(Stats *playerStats) {
    this->playerStats = *playerStats;
}

Inventory Player::getInvent() {
    return Player::invent;
}

void Player::setInvent(Inventory invent) {
    Player::invent = invent;
}

int Player::getGold() {
    return Player::gold;
}

void Player::setGold(int gold) {
    Player::gold = gold;
}

Item Player::getWeapon() {
    return Player::weapon;
}

void Player::equipWeapon(Item weapon) {
    if(weapon.getItemType() == "W"){

        if(Player::weapon.getName() != ""){         //SE HA GIA' ARMA EQUIPAGGIATA
            Item move = Player::weapon;
            Player::weapon = weapon;

            for(int i=0; i<invent.getCurrentSpace(); i++){
                if(Player::invent.getItemByIndex(i).getName() == weapon.getName() ){
                    Player::invent.replaceItem(i,move);
                }
            }
        }else{
            Player::weapon = weapon;
        }

    } else {
        cout<<"The item is not a weapon";
    }

}

Item Player::getShield() {
    return Player::shield;
}

void Player::equipShield(Item shield) {
    if(shield.getItemType() == "E"){
        if(shield.getArmorType() == "shield"){
            if(Player::shield.getName() != ""){         //SE HA GIA' SCUDO EQUIPAGGIATO
                Item move = Player::shield;
                Player::shield = shield;

                for(int i=0; i<invent.getCurrentSpace(); i++){
                    if(Player::invent.getItemByIndex(i).getName() == shield.getName() ){
                        Player::invent.replaceItem(i,move);
                    }
                }
            }else{
                Player::shield = shield;
            }
        }else{
            cout<<"The armature is not a shield";
        }
    } else {
        cout<<"The item is not a shield";
    }
}

Item Player::getHead() {
    return Player::head;
}

void Player::equipHead(Item head) {
    if(head.getItemType() == "E"){
        if(head.getArmorType() == "head"){
            if(Player::head.getName() != ""){
                Item move = Player::head;
                Player::head = head;

                for(int i=0; i<invent.getCurrentSpace(); i++){
                    if(Player::invent.getItemByIndex(i).getName() == head.getName() ){
                        Player::invent.replaceItem(i,move);
                    }
                }
            }else{
                Player::head = head;
            }
        }else{
            cout<<"The armature is not a head";
        }
    } else {
        cout<<"The item is not a head";
    }
}

Item Player::getChest() {
    return Player::chest;
}

void Player::equipChest(Item chest) {
    if(chest.getItemType() == "E"){
        if(chest.getArmorType() == "chest"){
            if(Player::chest.getName() != ""){
                Item move = Player::chest;
                Player::chest = chest;

                for(int i=0; i<invent.getCurrentSpace(); i++){
                    if(Player::invent.getItemByIndex(i).getName() == chest.getName() ){
                        Player::invent.replaceItem(i,move);
                    }
                }
            }else{
                Player::chest = chest;
            }
        }else{
            cout<<"The armature is not a chest";
        }
    } else {
        cout<<"The item is not a chest";
    }
}

Item Player::getLegs() {
    return Player::legs;
}

void Player::equipLegs(Item legs) {
    if(legs.getItemType() == "E"){
        if(legs.getArmorType() == "legs"){
            if(Player::legs.getName() != ""){
                Item move = Player::legs;
                Player::legs = legs;

                for(int i=0; i<invent.getCurrentSpace(); i++){
                    if(Player::invent.getItemByIndex(i).getName() == legs.getName() ){
                        Player::invent.replaceItem(i,move);
                    }
                }
            }else{
                Player::legs = legs;
            }
        }else{
            cout<<"The armature is not a legs";
        }
    } else {
        cout<<"The item is not a legs";
    }
}

Item Player::getArms() {
    return Player::arms;
}

void Player::equipArms(Item arms) {
    if(arms.getItemType() == "E"){
        if(arms.getArmorType() == "arms"){
            if(Player::arms.getName() != ""){
                Item move = Player::arms;
                Player::arms = arms;

                for(int i=0; i<invent.getCurrentSpace(); i++){
                    if(Player::invent.getItemByIndex(i).getName() == arms.getName() ){
                        Player::invent.replaceItem(i,move);
                    }
                }
            }else{
                Player::arms = arms;
            }
        }else{
            cout<<"The armature is not a arms";
        }
    } else {
        cout<<"The item is not a arms";
    }
}



