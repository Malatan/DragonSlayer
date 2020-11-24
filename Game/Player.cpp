//
// Created by Zheng on 07/10/2020.
//

#include "Player.h"

//initializer functions
void Player::initAnimations() {
    animationComponent->addAnimation("IDLE", 15.f,
            0, 0, 3, 0, 50 ,37);
    animationComponent->addAnimation("WALK", 6.f,
            1, 1, 6, 1, 50 ,37);
}

//constructors/destructors
Player::Player(float x, float y, float scale_x, float scale_y, sf::Texture& texture_sheet) {
    gold = 0;

    scale.x = scale_x;
    scale.y = scale_y;
    sprite.setScale(this->scale);

    createAnimationComponent(texture_sheet);
    createMovementComponent(200.f, 14.f, 6.f);
    createHitboxComponent(sprite, 27.f, 12.f, 41.f, 62.f);
    createCollisionBoxComponent(sprite, 48.f, 72.f, 9.f);
    initAnimations();

    setPosition(x, y);

    currentInventorySpace = 30;
    playerStats = new Stats();
    inventory = new Inventory(&currentInventorySpace);

    weapon = nullptr;
    shield = nullptr;
    head = nullptr;
    chest = nullptr;
    arms = nullptr;
    legs = nullptr;
}

Player::Player() {

}

Player::~Player() {
    delete this->playerStats;
    delete this->inventory;
}

//functions
void Player::updateAnimation(const float &dt) {

    if(movementComponent->getState(IDLE)){
        animationComponent->play("IDLE", dt);

    } else if(movementComponent->getState(MOVING_LEFT)){
        sprite.setOrigin(48.f, 0.f);
        sprite.setScale(-scale.x, scale.y);

        animationComponent->play("WALK", dt,
                                       movementComponent->getVelocity().x,
                                       movementComponent->getMaxVelocity());

    } else if(movementComponent->getState(MOVING_RIGHT)){
        sprite.setOrigin(0.f, 0.f);
        sprite.setScale(scale.x, scale.y);

        animationComponent->play("WALK", dt,
                                       movementComponent->getVelocity().x,
                                       movementComponent->getMaxVelocity());

    } else if(movementComponent->getState(MOVING_UP)){
        animationComponent->play("WALK", dt,
                                       movementComponent->getVelocity().y,
                                       movementComponent->getMaxVelocity());

    } else if(movementComponent->getState(MOVING_DOWN)){
        animationComponent->play("WALK", dt,
                                       movementComponent->getVelocity().y,
                                       movementComponent->getMaxVelocity());

    }
}

void Player::update(const float &dt) {
    movementComponent->update(dt);
    updateAnimation(dt);
    hitboxComponent->update();
    collisionBoxComponent->update();
}

void Player::render(sf::RenderTarget &target, const bool show_hitbox, const bool show_clsBox) {
    if(show_clsBox)
        collisionBoxComponent->render(target);
    target.draw(sprite);
    if(show_hitbox)
        hitboxComponent->render(target);
}

void Player::heal(int hp) {
    playerStats->gainHp(hp);
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

int Player::takeDamage(int dmg) {
    dmg = dmg - Player::playerStats->getFinalArmor();
    if(dmg < 0){
        dmg = 0;
    }
    int newHp = Player::playerStats->getHp() - dmg;
    Player::playerStats->setHp(newHp);

    return dmg;
}

void Player::useSpell(string spell) {
    int mana;
    for(int i=0; i<30; i++){
        if(Player::spells[i].getName() == spell)
            mana = Player::spells[i].getCost();
    }
    Player::playerStats->setMp( Player::playerStats->getMp() - mana  );
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

string Player::listSpells(){
    string desc = "";

    for (int i=0; i<3; i++){
        if(Player::spells[i].isLearned()){
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

Stats* Player::getPlayerStats() {
    return playerStats;
}

Inventory* Player::getInventory() {
    return inventory;
}

unsigned Player::getGold() {
    return gold;
}

void Player::setGold(unsigned gold) {
    this->gold = gold;
}

void Player::setEquipItem(std::shared_ptr<Item> item, int equip_slot) {
    switch(equip_slot){
        case 5:  // weapon
            weapon = item;
            break;
        case 4: // shield
            shield = item;
            break;
        case 3: // helmet
            head = item;
            break;
        case 2: // chest
            chest = item;
            break;
        case 1: // arms
            arms = item;
            break;
        case 0: // legs
            legs = item;
            break;
    }
}

bool Player::isSlotEquipped(int equip_slot) {
    switch(equip_slot){
        case 5:  // weapon
            if(weapon != nullptr)
                return true;
            else
                return false;
        case 4: // shield
            if(shield)
                return true;
            else
                return false;
        case 3: // head
            if(head)
                return true;
            else
                return false;
        case 2: // chest
            if(chest)
                return true;
            else
                return false;
        case 1: // arms
            if(arms)
                return true;
            else
                return false;
        case 0: // legs
            if(legs)
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
            if(weapon != nullptr){
                weapon->setEquipped(false);
                weapon = nullptr;
            }
            break;
        case 4: // shield
            if(shield != nullptr){
                shield->setEquipped(false);
                shield = nullptr;
            }
            break;
        case 3: // helmet
            if(head != nullptr){
                head->setEquipped(false);
                head = nullptr;
            }
            break;
        case 2: // chest
            if(chest != nullptr){
                chest->setEquipped(false);
                chest = nullptr;
            }
            break;
        case 1: // arms
            if(arms != nullptr){
                arms->setEquipped(false);
                arms = nullptr;
            }
            break;
        case 0: // legs
            if(legs != nullptr){
                legs->setEquipped(false);
                legs = nullptr;
            }
            break;
    }
}

std::string Player::toStringEquipment() {
    std::stringstream ss;
    ss << "\nWeapon: ";
    if(weapon != nullptr)
        ss << weapon->getName();
    else
        ss << "Nothing";

    ss << "\nShield: ";
    if(shield != nullptr)
        ss << shield->getName();
    else
        ss << "Nothing";

    ss << "\nHead: ";
    if(head != nullptr)
        ss << head->getName();
    else
        ss << "Nothing";

    ss << "\nChest: ";
    if(chest != nullptr)
        ss << chest->getName();
    else
        ss << "Nothing";

    ss << "\nArms: ";
    if(arms != nullptr)
        ss << arms->getName();
    else
        ss << "Nothing";

    ss << "\nLegs: ";
    if(legs != nullptr)
        ss << legs->getName();
    else
        ss << "Nothing";

    return ss.str();
}

std::shared_ptr<Item> Player::getEquippedItem(int equip_slot) {
    switch(equip_slot){
        case 5:  // weapon
            return weapon;
        case 4: // shield
            return shield;
        case 3: // helmet
            return head;
        case 2: // chest
            return chest;
        case 1: // arms
            return arms;
        case 0: // legs
            return legs;
        default:
            return nullptr;
    }
}

void Player::setBonusStats(int hp, int mp, int dmg, int armor, float cc, float ec) {
    playerStats->setMaxHpBonus(hp);
    playerStats->setMaxMpBonus(mp);
    playerStats->setDamageBonus(dmg);
    playerStats->setArmorBonus(armor);
    playerStats->setCritChanceBonus(cc);
    playerStats->setEvadeChanceBonus(ec);
    playerStats->checkHpLimit();
    playerStats->checkMpLimit();
}

void Player::addGold(unsigned gold) {
    this->gold += gold;
}

void Player::minusGold(unsigned gold) {
    if(gold > this->gold){
        this->gold = 0;
    }else{
        this->gold -= gold;
    }
}
