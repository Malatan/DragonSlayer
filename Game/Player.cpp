//
// Created by Zheng on 07/10/2020.
//

#include "Player.h"

//initializer functions
void Player::initAnimations() {
    animationComponent->addAnimation("IDLE", 15.f,
            0, 0, 3, 0, 50 ,37);
    animationComponent->addAnimation("WALK", 8.f,
            0, 1, 5, 1, 50 ,37);
    animationComponent->addAnimation("ATTACK", 6.f,
            0, 3, 13, 3, 50 ,37);
    animationComponent->addAnimation("ATTACK2", 9.f,
            0, 4, 8, 4, 50 ,37);

    animationComponent->addAnimation("ATTACK3", 9.f,
            0, 6, 13, 6, 50 ,37);
    animationComponent->addAnimation("ATTACK4", 9.f,
            0, 7, 13, 7, 50 ,37);

    animationComponent->addAnimation("CAST", 9.f,
            0, 2, 8, 2, 50 ,37);
    animationComponent->addAnimation("SHIELD", 9.f,
            0, 2, 8, 2, 50 ,37);
    animationComponent->addAnimation("GETHIT", 9.f,
            0, 5, 10, 5, 50 ,37);
    animationComponent->addAnimation("DEATH", 9.f,
            0, 5, 6, 5, 50 ,37);
}

void Player::initStats() {
    playerStats = std::make_shared<Stats>();
}

void Player::initInventory() {
    inventory = std::make_shared<Inventory>(&currentInventorySpace);
}

//constructors/destructors
Player::Player(float x, float y, float scale_x, float scale_y, sf::Texture& texture_sheet) {
    gold = 0;
    defense = false;

    scale.x = scale_x;
    scale.y = scale_y;
    sprite.setScale(this->scale);

    animationEnum = IDLE_ANIMATION;
    nextAnimationEnum = IDLE_ANIMATION;
    animationDone = false;

    createAnimationComponent(texture_sheet);
    createMovementComponent(200.f, 14.f, 6.f);
    createHitboxComponent(sprite, 27.f, 12.f, 41.f, 62.f);
    createCollisionBoxComponent(sprite, 48.f, 72.f, 4.5f);
    initAnimations();

    Player::setPosition(x, y);
    currentInventorySpace = 30;
    wayPoints.emplace_back(sf::Vertex(sf::Vector2f(x, y)));
    weapon = nullptr;
    shield = nullptr;
    head = nullptr;
    chest = nullptr;
    arms = nullptr;
    legs = nullptr;
}

Player::Player() = default;

Player::~Player() = default;

//functions
void Player::updateAnimation(const float &dt) {
    if(movementComponent->getState(IDLE)){
        switch(animationEnum){
            case IDLE_ANIMATION:
                animationDone = animationComponent->play("IDLE", dt);
                break;
            case ATTACK_ANIMATION:
                animationDone = animationComponent->play("ATTACK", dt);
                break;
            case ATTACK2_ANIMATION:
                animationDone = animationComponent->play("ATTACK2", dt);
                break;
            case ATTACK3_ANIMATION:
                animationDone = animationComponent->play("ATTACK3", dt);
                break;
            case ATTACK4_ANIMATION:
                animationDone = animationComponent->play("ATTACK4", dt);
                break;
            case SHIELD_ANIMATION:
                animationDone = animationComponent->play("SHIELD", dt);
                break;
            case CAST_ANIMATION:
                animationDone = animationComponent->play("CAST", dt);
                break;
            case GETHIT_ANIMATION:
                animationDone = animationComponent->play("GETHIT", dt);
                break;
            case DEATH_ANIMATION:
                animationDone = animationComponent->play("DEATH", dt);
                break;
            default:
                break;
        }
        if(animationDone)
            animationEnum = nextAnimationEnum;
    } else if(movementComponent->getState(MOVING_LEFT)){
        sprite.setOrigin(48.f, 0.f);
        sprite.setScale(-scale.x, scale.y);
        animationComponent->play("WALK", dt);
    } else if(movementComponent->getState(MOVING_RIGHT)){
        sprite.setOrigin(0.f, 0.f);
        sprite.setScale(scale.x, scale.y);
        animationComponent->play("WALK", dt);
    } else if(movementComponent->getState(MOVING_UP) || movementComponent->getState(MOVING_DOWN)){
        animationComponent->play("WALK", dt);
    }
}

void Player::update(const float &dt) {
    updateWaypoint(dt);
    movementComponent->update(dt);
    collisionBoxComponent->update();
    hitboxComponent->update();
    updateAnimation(dt);
}

void Player::render(sf::RenderTarget &target, sf::Shader* shader, sf::Vector2f light_position) {
    collisionBoxComponent->render(target);
    if(shader){
        shader->setUniform("hasTexture", true);
        shader->setUniform("lightPos", light_position);
        target.draw(sprite, shader);
    }
    else{
        target.draw(sprite);
    }
}

void Player::addGold(unsigned add_amount) {
    gold += add_amount;
}

void Player::minusGold(unsigned minus_amount) {
    if(minus_amount > gold){
        gold = 0;
    }else{
        gold -= minus_amount;
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
        default:
            break;
    }
}

//GET & SET
std::shared_ptr<Stats> Player::getPlayerStats() {
    return playerStats;
}

std::shared_ptr<Inventory> Player::getInventory() {
    return inventory;
}

unsigned Player::getGold() const {
    return gold;
}

void Player::setGold(unsigned new_gold) {
    this->gold = new_gold;
}

void Player::setEquipItem(const std::shared_ptr<Item>& equip_item, int equip_slot) {
    switch(equip_slot){
        case 5:  // weapon
            weapon = equip_item;
            break;
        case 4: // shield
            shield = equip_item;
            break;
        case 3: // helmet
            head = equip_item;
            break;
        case 2: // chest
            chest = equip_item;
            break;
        case 1: // arms
            arms = equip_item;
            break;
        case 0: // legs
            legs = equip_item;
            break;
        default:
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

void Player::setAnimation(entity_animation animation, entity_animation next_animation) {
    animationEnum = animation;
    nextAnimationEnum = next_animation;
}

std::string Player::getEquippedWeaponType() {
    if(weapon){
        return weapon->getItemUsageTypeString();
    }else{
        return "Empty Handed";
    }
}

void Player::setDefense(bool b) {
    defense = b;
}

bool Player::isDefense() const {
    return defense;
}

bool Player::isDead() {
    return playerStats->getHp() == 0;
}

void Player::setPosition(float x, float y) {
    if(hitboxComponent)
        hitboxComponent->setPosition(x, y);
    else
        sprite.setPosition(x, y);
}

void Player::setStats(Stats *new_stats) {
    playerStats = std::make_shared<Stats>(*new_stats);
}

void Player::setInventory(std::vector<Item>& items) {
    inventory = std::make_shared<Inventory>(&currentInventorySpace);
    inventory->fill(items);
}

bool Player::hasShield() {
    if(shield)
        return true;
    else
        return false;
}

std::string Player::toStringEquips() const {
    std::stringstream ss;
    ss << "--------------------Player Equips--------------------" << std::endl;
    if(weapon){
        ss << weapon->listItem(false);
    }else{
        ss << "No weapon equipped" << std::endl;
    }
    if(shield){
        ss << shield->listItem(false);
    }else{
        ss << "No shield equipped" << std::endl;
    }
    if(head){
        ss << head->listItem(false);
    }else{
        ss << "No head equipped" << std::endl;
    }
    if(chest){
        ss << chest->listItem(false);
    }else{
        ss << "No chest equipped" << std::endl;
    }
    if(arms){
        ss << arms->listItem(false);
    }else{
        ss << "No arms equipped" << std::endl;
    }
    if(legs){
        ss << legs->listItem(false);
    }else{
        ss << "No legs equipped" << std::endl;
    }
    ss << "------------------End-Player Equips-End------------------" << std::endl;
    return ss.str();
}
