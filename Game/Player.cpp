//
// Created by Zheng on 07/10/2020.
//

#include "Player.h"

//initializer functions
void Player::initVariables() {

}

void Player::initAnimations() {
    this->animationComponent->addAnimation("IDLE", 15.f,
            0, 0, 3, 0, 50 ,37);
    this->animationComponent->addAnimation("WALK", 6.f,
            1, 1, 6, 1, 50 ,37);
}

//constructors/destructors
Player::Player(float x, float y, float scale_x, float scale_y, sf::Texture& texture_sheet) {
    this->gold = 0;

    this->scale.x = scale_x;
    this->scale.y = scale_y;
    this->sprite.setScale(this->scale);

    this->createAnimationComponent(texture_sheet);
    this->createMovementComponent(200.f, 14.f, 6.f);
    this->createHitboxComponent(this->sprite, 27.f, 12.f, 41.f, 62.f);
    this->createCollisionBoxComponent(&this->sprite, 48.f, 72.f, 9.f);
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
    delete this->playerStats;
    delete this->inventory;
}

//functions
void Player::updateAnimation(const float &dt) {

    if(this->movementComponent->getState(IDLE)){
        this->animationComponent->play("IDLE", dt);

    } else if(this->movementComponent->getState(MOVING_LEFT)){
        this->sprite.setOrigin(48.f, 0.f);
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
    this->collisionBoxComponent->update();
}

void Player::render(sf::RenderTarget &target, const bool show_hitbox) {
    this->collisionBoxComponent->render(target);
    target.draw(this->sprite);
    if(show_hitbox)
        this->hitboxComponent->render(target);
}

void Player::heal(int hp) {
    this->playerStats->gainHp(hp);
}

string Player::playerDetails() {
    string desc = "";

    desc+= "PLAYER LIV." + to_string(Player::getPlayerStats()->getLevel())
           + "     HP[";

    int health =0;
    for(int i=0; i<Player::getPlayerStats()->getFinalHp(); i=i+10){
        if(health <= Player::getPlayerStats()->getHp())
            desc+="#";
        else
            desc+="-";
        health += 10;
    }

    desc+= to_string(Player::getPlayerStats()->getHp()) + "/" + to_string(Player::getPlayerStats()->getFinalHp()) + "]\n"
           + "     MP: " +to_string(Player::getPlayerStats()->getMp()) + "/" + to_string(Player::getPlayerStats()->getFinalMp())
           + "     Armor: " + to_string(Player::getPlayerStats()->getFinalArmor())
           + "     Damage: " + to_string(Player::getPlayerStats()->getFinalDamage())
           + "     \nCrit: " + to_string(Player::getPlayerStats()->getFinalCritChance())
           + "     Evade: " + to_string(Player::getPlayerStats()->getFinalEvadeChance()) + "\n";

    return desc;
}

bool Player::takeItem(Item *item) {
    if(this->inventory->addItem(item))
        return true;
    else
        return false;
}

int Player::takeDamage(int dmg) {
    dmg = dmg - Player::playerStats->getFinalArmor();
    if(dmg < 0){
        dmg = 0;
    }
    int newHp = Player::playerStats->getHp() - dmg;
    Player::playerStats->setHp(newHp);

    return dmg;
}

void Player::earnExp(int exp) {
    Player::playerStats->addExp(exp);
}

void Player::learnSpell(string spell) {
    for(int i=0; i<3; i++){
        if(spells[i].getName() == spell){
            spells[i].setLearned(true);
        }
    }
}

void Player::useSpell(string spell) {
    int mana;
    for(int i=0; i<30; i++){
        if(Player::spells[i].getName() == spell)
            mana = Player::spells[i].getCost();
    }
    Player::playerStats->setMp( Player::playerStats->getMp() - mana  );
}

Spell *Player::getSpells() {
    return this->spells;
}

Spell *Player::getSpellbyIndex(int i) {
    return &Player::spells[i];
}

bool Player::useItem(string item) {
    int qnt = this->inventory->getItem(item)->getQuantity();
    if(qnt > 0){
        this->inventory->getItem(item)->setQuantity(qnt-1);
        return true;
    }else{
        return false;
    }
}

void Player::loadEquipment() {

    for(auto i : this->inventory->items){
        if(i->isEquipped()){
            int use = i->getUsageType();
            Player::setEquipItem(i, use);
        }

    }
}

void Player::reloadEquipBonus() {
    int hp, mp, dmg, armor;
    float cc, ec;

    hp = weapon->getHp() + shield->getHp() + head->getHp() + chest->getHp() + arms->getHp() + legs->getHp();
    mp = weapon->getMp() + shield->getMp() + head->getMp() + chest->getMp() + arms->getMp() + legs->getMp();
    dmg = weapon->getDamage() + shield->getDamage() + head->getDamage() + chest->getDamage() + arms->getDamage() + legs->getDamage();
    armor = weapon->getDamage() + shield->getDamage() + head->getDamage() + chest->getDamage() + arms->getDamage() + legs->getDamage();
    cc = weapon->getCritChance() + shield->getCritChance() + head->getCritChance() + chest->getCritChance() + arms->getCritChance() + legs->getCritChance();
    ec = weapon->getEvadeChance() + shield->getEvadeChance() + head->getEvadeChance() + chest->getEvadeChance() + arms->getEvadeChance() + legs->getEvadeChance();

    Player::setBonusStats(hp, mp, dmg, armor, cc, ec);
}

string  Player::listEquipment() {
    string equip = "";
    equip += this->weapon->listItem() + "\n";
    equip += this->shield->listItem() + "\n";
    equip += this->head->listItem()   + "\n";
    equip += this->chest->listItem()  + "\n";
    equip += this->arms->listItem()   + "\n";
    equip += this->legs->listItem()   + "\n";
    return equip;
}

string Player::listSpells(){
    string desc = "";

    for (int i=0; i<3; i++){
        if(Player::spells[i].isLearned() == true){
            desc+= to_string(i+1) + ") ";
            desc+=  Player::spells[i].getName()
                    + " - " + to_string(Player::spells[i].getDamage()) + " damage\n"
                    + " - target " + to_string(Player::spells[i].getAoe()) + " enemies\n"
                    + " - " + to_string(Player::spells[i].getCost()) + " mp\n";

            if(Player::spells[i].getReady() == 0){
                desc+= " - READY\n";
            } else {
                desc+= " - " + to_string(Player::spells[i].getReady()) + " TURN cooldown\n";
            }
        }
    }
    return desc;
}

void Player::refreshSpells() {
    for(int i=0; i<30; i++){
        Player::spells[i].refreshSpell();
    }
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
                spells[i].setReady(0);
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
        case 3: // head
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

void Player::minusGold(unsigned gold) {
    if(gold > this->gold){
        gold = 0;
    }else{
        this->gold -= gold;
    }
}
