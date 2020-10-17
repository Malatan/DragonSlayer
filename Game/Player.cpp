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
    this->gold = 0;

    this->scale.x = scale_x;
    this->scale.y = scale_y;
    this->sprite.setScale(this->scale);

    this->createAnimationComponent(texture_sheet);
    this->createMovementComponent(120.f, 8.f, 4.f);
    this->createHitboxComponent(this->sprite, 46, 26.f, 50.f, 65.f);
    this->initAnimations();

    this->setPosition(x, y);

    this->currentInventorySpace = 30;
    this->playerStats = new Stats();
    this->inventory = new Inventory(&this->currentInventorySpace);

    this->weapon = nullptr;
    this->shield = nullptr;
    this->head = nullptr;
    this->chest = nullptr;
    this->arms = nullptr;
    this->legs = nullptr;
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
   // dmg = dmg - this->playerStats.getArmor();
   // int newHp = this->playerStats.getHp() - dmg;
   // this->playerStats.setHp(newHp);

    return dmg;
}

void Player::earnExp(int exp) {
  //  this->playerStats.addExp(exp);       //SE CON EXP IL PLAYER SALE DI LIVELLO
}

void Player::learnSpell(string spell) {
    for(int i=0; i<3; i++){
        if(spells[i].getName() == spell){
            spells[i].setLearned(true);
        }
    }
}

void Player::reloadEquipStats() {
 /*   int armorBonus = 0;
    int damageBonus = 0;

    damageBonus += Player::weapon.getDamage();
    armorBonus += Player::shield.getArmor();
    armorBonus += Player::head.getArmor();
    armorBonus += Player::chest.getArmor();
    armorBonus += Player::arms.getArmor();
    armorBonus += Player::legs.getArmor();*/

 //   Player::playerStats.setArmorBonus(armorBonus);
 //   Player::playerStats.setDamageBonus(damageBonus);
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

Stats* Player::getPlayerStats() {
    return this->playerStats;
}

void Player::setPlayerStats(Stats* playerStats) {
    this->playerStats = playerStats;
}

Inventory* Player::getInventory() {
    return this->inventory;
}

void Player::setInventory(Inventory* inventory) {
    this->inventory = inventory;
}

unsigned Player::getGold() {
    return this->gold;
}

void Player::setGold(unsigned gold) {
    this->gold = gold;
}

void Player::setEquipItem(Item *item, int equip_slot) {
    switch(equip_slot){
        case 5:  // weapon
            this->weapon = item;
            break;
        case 4: // shield
            this->shield = item;
            break;
        case 3: // helmet
            this->head = item;
            break;
        case 2: // chest
            this->chest = item;
            break;
        case 1: // arms
            this->arms = item;
            break;
        case 0: // legs
            this->legs = item;
            break;
    }
}

bool Player::isSlotEquipped(int equip_slot) {
    switch(equip_slot){
        case 5:  // weapon
            if(this->weapon != nullptr)
                return true;
            else
                return false;
        case 4: // shield
            if(this->shield)
                return true;
            else
                return false;
        case 3: // helmet
            if(this->head)
                return true;
            else
                return false;
        case 2: // chest
            if(this->chest)
                return true;
            else
                return false;
        case 1: // arms
            if(this->arms)
                return true;
            else
                return false;
        case 0: // legs
            if(this->legs)
                return true;
            else
                return false;
        default:
            return false;
    }
}

void Player::unequipItem(int equip_slot) {
    switch(equip_slot){
        case 5:  // weapon
            if(this->weapon != nullptr){
                this->weapon->setEquipped(false);
                this->weapon = nullptr;
            }
            break;
        case 4: // shield
            if(this->shield != nullptr){
                this->shield->setEquipped(false);
                this->shield = nullptr;
            }
            break;
        case 3: // helmet
            if(this->head != nullptr){
                this->head->setEquipped(false);
                this->head = nullptr;
            }
            break;
        case 2: // chest
            if(this->chest != nullptr){
                this->chest->setEquipped(false);
                this->chest = nullptr;
            }
            break;
        case 1: // arms
            if(this->arms != nullptr){
                this->arms->setEquipped(false);
                this->arms = nullptr;
            }
            break;
        case 0: // legs
            if(this->legs != nullptr){
                this->legs->setEquipped(false);
                this->legs = nullptr;
            }
            break;
    }
}

std::string Player::toStringEquipment() {
    std::stringstream ss;
    ss << "\nWeapon: ";
    if(this->weapon != nullptr)
        ss << this->weapon->getName();
    else
        ss << "Nothing";

    ss << "\nShield: ";
    if(this->shield != nullptr)
        ss << this->shield->getName();
    else
        ss << "Nothing";

    ss << "\nHead: ";
    if(this->head != nullptr)
        ss << this->head->getName();
    else
        ss << "Nothing";

    ss << "\nChest: ";
    if(this->chest != nullptr)
        ss << this->chest->getName();
    else
        ss << "Nothing";

    ss << "\nArms: ";
    if(this->arms != nullptr)
        ss << this->arms->getName();
    else
        ss << "Nothing";

    ss << "\nLegs: ";
    if(this->legs != nullptr)
        ss << this->legs->getName();
    else
        ss << "Nothing";

    return ss.str();
}

Item *Player::getEquippedItem(int equip_slot) {
    switch(equip_slot){
        case 5:  // weapon
            return this->weapon;
        case 4: // shield
            return this->shield;
        case 3: // helmet
            return this->head;
        case 2: // chest
            return this->chest;
        case 1: // arms
            return this->arms;
        case 0: // legs
            return this->legs;
        default:
            return nullptr;
    }
}

void Player::setBonusStats(int hp, int mp, int dmg, int armor, float cc, float ec) {
    this->playerStats->setMaxHpBonus(hp);
    this->playerStats->setMaxMpBonus(mp);
    this->playerStats->setDamageBonus(dmg);
    this->playerStats->setArmorBonus(armor);
    this->playerStats->setCritChanceBonus(cc);
    this->playerStats->setEvadeChanceBonus(ec);
    this->playerStats->checkHpLimit();
    this->playerStats->checkMpLimit();
}

void Player::addGold(unsigned gold) {
    this->gold += gold;
}
