//
// Created by Zheng on 08/10/2020.
//

#include "Enemy.h"

//initializer functions
void Enemy::initAnimations() {
    switch(type){
        case WITCH:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 0, 7, 0, 250 ,250);
            break;
        case SKELETON:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 0, 10, 0, 24 ,32);
            break;
        case SKELETON_2:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 0, 3, 0, 150 ,150);
            break;
        case FLYING_EYE:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 0, 7, 0, 150 ,150);
            break;
        case GOBLIN:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 0, 3, 0, 150 ,150);
            break;
        case MUSHROOM:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 0, 3, 0, 150 ,150);
            break;
        case BANDIT_HEAVY:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 0, 3, 0, 48 ,48);
            break;
        case BANDIT_LIGHT:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 0, 3, 0, 48 ,48);
            break;
    }

}

//constructors/destructors
Enemy::Enemy(enemy_types type, float x, float y, float scale_x ,float scale_y, float hitbox_offset_x, float hitbox_offset_y,
             float hitbox_width, float hitbox_height, float clsBox_offset_x, float clsBox_offset_y, float clsBox_radius,
             sf::Texture& texture_sheet, int floor) : type(type){
    scale.x = scale_x;
    scale.y = scale_y;
    sprite.setScale(scale);

    createAnimationComponent(texture_sheet);
    createHitboxComponent(sprite, hitbox_offset_x, hitbox_offset_y, hitbox_width, hitbox_height);
    createCollisionBoxComponent(sprite, clsBox_offset_x, clsBox_offset_y, clsBox_radius);
    initAnimations();

    setPosition(x, y);
    if(floor > 0)
        generateEnemyStats(floor);
    generateNameByType();
}

Enemy::~Enemy() {

}

//functions
void Enemy::generateNameByType() {
    switch(type){
        case WITCH:
            name = "Witch";
            break;
        case SKELETON:
            name = "Skeleton";
            break;
        case SKELETON_2:
            name = "Skeleton 2";
            break;
        case FLYING_EYE:
            name = "Flying eye";
            break;
        case GOBLIN:
            name = "Goblin";
            break;
        case MUSHROOM:
            name = "Mushroom";
            break;
        case BANDIT_HEAVY:
            name = "Bandit Leader";
            break;
        case BANDIT_LIGHT:
            name = "Bandit Minion";
            break;
        default:
            std::cout<<"No such enemy: " << type;
            break;
    }
}

void Enemy::copyStats(Enemy *enemy) {
    level = enemy->getLevel();
    agility = enemy->getAgility();
    wisdom = enemy->getWisdom();
    strength = enemy->getStrength();
    maxHp = enemy->getMaxHp();
    maxMp = enemy->getMaxMp();
    armor = enemy->getArmor();
    damage = enemy->getDamage();
    critChance = enemy->getCritChance();  //%
    evadeChance = enemy->getEvadeChance();  //%
    mp = enemy->getMp();
    hp = enemy->getHp();
}

void Enemy::generateEnemyStats(int floor) {
    //floor 1 = 1-10, 2 = 11-20, 3 = 21-30, 4 = 31-40, 5 = 41-50
    int level = utils::generateRandomNumber((floor-1)*10+1, floor*10, false);
    float mod = (level/10.f) + floor;
    switch(type){
        case WITCH:
            this->level = level;
            agility = 2 * mod;
            wisdom = 4 * mod;
            strength = 2 * mod;
            maxHp = 100 * (mod + (strength/10.f));
            maxMp = 200 * (mod + (wisdom/10.f));
            armor = 15 * (mod + (strength/10.f));
            damage = 25 * (mod + (wisdom/10.f));
            critChance = 10.f + mod + (strength/10.f);  //%
            evadeChance = 12.8f + mod + (agility/10.f);  //%
            mp = maxMp;
            hp = maxHp;
            break;
        case SKELETON:
            this->level = level;
            agility = 3 * mod;
            wisdom = 2 * mod;
            strength = 3 * mod;
            maxHp = 130 * (mod + (strength/10.f));
            maxMp = 100 * (mod + (wisdom/10.f));
            armor = 15 * (mod + (strength/10.f));
            damage = 20 * (mod + (wisdom/10.f));
            critChance = 12.f + mod + (strength/10.f);  //%
            evadeChance = 11.4f + mod + (agility/10.f);  //%
            mp = maxMp;
            hp = maxHp;
            break;
        case SKELETON_2:
            this->level = level;
            agility = 3 * mod;
            wisdom = 2 * mod;
            strength = 3 * mod;
            maxHp = 150 * (mod + (strength/10.f));
            maxMp = 100 * (mod + (wisdom/10.f));
            armor = 20 * (mod + (strength/10.f));
            damage = 28 * (mod + (wisdom/10.f));
            critChance = 13.f + mod + (strength/10.f);  //%
            evadeChance = 8.f + mod + (agility/10.f);  //%
            mp = maxMp;
            hp = maxHp;
            break;
        case FLYING_EYE:
            this->level = level;
            agility = 4 * mod;
            wisdom = 2 * mod;
            strength = 2 * mod;
            maxHp = 100 * (mod + (strength/10.f));
            maxMp = 100 * (mod + (wisdom/10.f));
            armor = 10 * (mod + (strength/10.f));
            damage = 20 * (mod + (wisdom/10.f));
            critChance = 10.f + mod + (strength/10.f);  //%
            evadeChance = 20.8f + mod + (agility/10.f);  //%
            mp = maxMp;
            hp = maxHp;
            break;
        case GOBLIN:
            this->level = level;
            agility = 3 * mod;
            wisdom = 2 * mod;
            strength = 3 * mod;
            maxHp = 140 * (mod + (strength/10.f));
            maxMp = 100 * (mod + (wisdom/10.f));
            armor = 18 * (mod + (strength/10.f));
            damage = 22 * (mod + (wisdom/10.f));
            critChance = 14.f + mod + (strength/10.f);  //%
            evadeChance = 10.f + mod + (agility/10.f);  //%
            mp = maxMp;
            hp = maxHp;
            break;
        case MUSHROOM:
            this->level = level;
            agility = 3 * mod;
            wisdom = 3 * mod;
            strength = 2 * mod;
            maxHp = 130 * (mod + (strength/10.f));
            maxMp = 120 * (mod + (wisdom/10.f));
            armor = 12 * (mod + (strength/10.f));
            damage = 20 * (mod + (wisdom/10.f));
            critChance = 16.f + mod + (strength/10.f);  //%
            evadeChance = 11.0f + mod + (agility/10.f);  //%
            mp = maxMp;
            hp = maxHp;
            break;
        case BANDIT_HEAVY:
            this->level = level;
            agility = 4 * mod;
            wisdom = 4 * mod;
            strength = 4 * mod;
            maxHp = 200 * (mod + (strength/10.f));
            maxMp = 180 * (mod + (wisdom/10.f));
            armor = 25 * (mod + (strength/10.f));
            damage = 35 * (mod + (wisdom/10.f));
            critChance = 19.f + mod + (strength/10.f);  //%
            evadeChance = 15.8f + mod + (agility/10.f);  //%
            mp = maxMp;
            hp = maxHp;
            break;
        case BANDIT_LIGHT:
            this->level = level;
            agility = 3 * mod;
            wisdom = 2 * mod;
            strength = 3 * mod;
            maxHp = 160 * (mod + (strength/10.f));
            maxMp = 100 * (mod + (wisdom/10.f));
            armor = 20 * (mod + (strength/10.f));
            damage = 27 * (mod + (wisdom/10.f));
            critChance = 16.f + mod + (strength/10.f);  //%
            evadeChance = 12.8f + mod + (agility/10.f);  //%
            mp = maxMp;
            hp = maxHp;
            break;
        default:
            std::cout<<"No such enemy: " << type;
            break;
    }
}

void Enemy::updateAnimation(const float &dt) {
    animationComponent->play("IDLE", dt);
}

void Enemy::update(const float &dt) {
    updateAnimation(dt);
    hitboxComponent->update();
    collisionBoxComponent->update();
}

void Enemy::render(sf::RenderTarget &target, bool show_hitbox, bool show_clsBox) {
    if(show_clsBox)
        collisionBoxComponent->render(target);
    target.draw(sprite);
    if(show_hitbox)
        hitboxComponent->render(target);
}

//getters/setters
enemy_types Enemy::getType() const{
    return type;
}

std::string Enemy::toString() {
    stringstream ss;
    ss << " -----------------Enemy Info----------------- " << std::endl;
    switch(type){
        case WITCH:
            ss << "Enemy type: WITCH" << std::endl;
            break;
        case SKELETON:
            ss << "Enemy type: SKELETON" << std::endl;
            break;
        case SKELETON_2:
            ss << "Enemy type: SKELETON_2" << std::endl;
            break;
        case FLYING_EYE:
            ss << "Enemy type: FLYING_EYE" << std::endl;
            break;
        case GOBLIN:
            ss << "Enemy type: GOBLIN" << std::endl;
            break;
        case MUSHROOM:
            ss << "Enemy type: MUSHROOM" << std::endl;
            break;
        case BANDIT_HEAVY:
            ss << "Enemy type: BANDIT_HEAVY" << std::endl;
            break;
        case BANDIT_LIGHT:
            ss << "Enemy type: BANDIT_LIGHT" << std::endl;
            break;
    }
    ss << "Name: " << name << std::endl;
    ss << "Level: " << level << std::endl;
    ss << "Hp/Max hp: " << hp << "/" << maxHp << std::endl;
    ss << "Mp/Max mp: " << mp << "/" << maxMp << std::endl;
    ss << "Damage: " << damage << std::endl;
    ss << "Armor: " << armor << std::endl;
    ss << "Crit chance: " << critChance << " %" << std::endl;
    ss << "Evade chance: " << evadeChance << " %" << std::endl;
    ss << "Agility: " << agility << std::endl;
    ss << "Wisdom: " << wisdom << std::endl;
    ss << "Strength: " << strength << std::endl;

    return ss.str();
}

int Enemy::getLevel() const{
    return level;
}

int Enemy::getAgility() const {
    return agility;
}

int Enemy::getWisdom() const {
    return wisdom;
}

int Enemy::getStrength() const {
    return strength;
}

int Enemy::getMaxHp() const {
    return maxHp;
}

int Enemy::getMaxMp() const {
    return maxMp;
}

int Enemy::getArmor() const {
    return armor;
}

int Enemy::getDamage() const {
    return damage;
}

float Enemy::getCritChance() const {
    return critChance;
}

float Enemy::getEvadeChance() const {
    return evadeChance;
}

int Enemy::getHp() const {
    return hp;
}

int Enemy::getMp() const {
    return mp;
}

std::string Enemy::getName() const {
    return name;
}






