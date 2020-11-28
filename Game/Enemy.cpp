//
// Created by Zheng on 08/10/2020.
//

#include "Enemy.h"

//initializer functions
void Enemy::initAnimations() {
    switch(type){
        case WITCH:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 2, 7, 2, 250 ,250);
            animationComponent->addAnimation("ATTACK", 10.f,
                    0, 0, 7, 0, 250 ,250);
            animationComponent->addAnimation("ATTACK2", 10.f,
                    0, 1, 7, 1, 250 ,250);
            animationComponent->addAnimation("WALK", 10.f,
                    0, 3, 7, 3, 250 ,250);
            animationComponent->addAnimation("GETHIT", 20.f,
                    0, 4, 2, 4, 250 ,250);
            animationComponent->addAnimation("DEATH", 10.f,
                    0, 5, 6, 5, 250 ,250);
            animationComponent->addAnimation("CORPSE", 10.f,
                    6, 5, 6, 5, 250 ,250);
            break;
        case SKELETON:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 2, 10, 2, 100 ,100);
            animationComponent->addAnimation("ATTACK", 10.f,
                    0, 0, 10, 0, 100 ,100);
            animationComponent->addAnimation("WALK", 10.f,
                    0, 1, 8, 1, 100 ,100);
            animationComponent->addAnimation("GETHIT", 10.f,
                    0, 3, 7, 3, 100 ,100);
            animationComponent->addAnimation("DEATH", 10.f,
                    0, 4, 10, 4, 100 ,100);
            animationComponent->addAnimation("CORPSE", 10.f,
                    10, 4, 10, 4, 100 ,100);
            break;
        case SKELETON_2:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 2, 3, 2, 150 ,150);
            animationComponent->addAnimation("ATTACK", 10.f,
                    0, 0, 7, 0, 150 ,150);
            animationComponent->addAnimation("SHIELD", 10.f,
                    0, 4, 3, 4, 150 ,150);
            animationComponent->addAnimation("WALK", 10.f,
                    0, 1, 3, 1, 150 ,150);
            animationComponent->addAnimation("GETHIT", 10.f,
                    0, 3, 3, 3, 150 ,150);
            animationComponent->addAnimation("DEATH", 10.f,
                    0, 5, 3, 5, 150 ,150);
            animationComponent->addAnimation("CORPSE", 10.f,
                    3, 5, 3, 5, 150 ,150);
            break;
        case FLYING_EYE:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 0, 7, 0, 150 ,150);
            animationComponent->addAnimation("ATTACK", 10.f,
                    0, 1, 7, 1, 150 ,150);
            animationComponent->addAnimation("WALK", 10.f,
                    0, 0, 7, 0, 150 ,150);
            animationComponent->addAnimation("GETHIT", 10.f,
                    0, 2, 3, 2, 150 ,150);
            animationComponent->addAnimation("DEATH", 10.f,
                    0, 3, 3, 3, 150 ,150);
            animationComponent->addAnimation("CORPSE", 10.f,
                    3, 3, 3, 3, 150 ,150);
            break;
        case GOBLIN:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 2, 3, 2, 150 ,150);
            animationComponent->addAnimation("ATTACK", 10.f,
                    0, 1, 7, 1, 150 ,150);
            animationComponent->addAnimation("WALK", 10.f,
                    0, 0, 7, 0, 150 ,150);
            animationComponent->addAnimation("GETHIT", 10.f,
                    0, 3, 3, 3, 150 ,150);
            animationComponent->addAnimation("DEATH", 10.f,
                    0, 4, 3, 4, 150 ,150);
            animationComponent->addAnimation("CORPSE", 10.f,
                    3, 4, 3, 4, 150 ,150);
            break;
        case MUSHROOM:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 2, 3, 2, 150 ,150);
            animationComponent->addAnimation("ATTACK", 10.f,
                    0, 1, 7, 1, 150 ,150);
            animationComponent->addAnimation("WALK", 10.f,
                    0, 0, 7, 0, 150 ,150);
            animationComponent->addAnimation("GETHIT", 10.f,
                    0, 3, 3, 3, 150 ,150);
            animationComponent->addAnimation("DEATH", 10.f,
                    0, 4, 3, 4, 150 ,150);
            animationComponent->addAnimation("CORPSE", 10.f,
                    3, 4, 3, 4, 150 ,150);
            break;
        case BANDIT_HEAVY:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 0, 3, 0, 48 ,48);
            animationComponent->addAnimation("ATTACK", 10.f,
                    3, 2, 7, 2, 48 ,48);
            animationComponent->addAnimation("WALK", 10.f,
                    0, 1, 7, 1, 48 ,48);
            animationComponent->addAnimation("GETHIT", 15.f,
                    0, 4, 2, 4, 48 ,48);
            animationComponent->addAnimation("DEATH", 10.f,
                    1, 4, 4, 4, 48 ,48);
            animationComponent->addAnimation("CORPSE", 10.f,
                    4, 4, 4, 4, 48 ,48);
            break;
        case BANDIT_LIGHT:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 0, 3, 0, 48 ,48);
            animationComponent->addAnimation("ATTACK", 10.f,
                    3, 2, 7, 2, 48 ,48);
            animationComponent->addAnimation("WALK", 10.f,
                    0, 1, 7, 1, 48 ,48);
            animationComponent->addAnimation("GETHIT", 15.f,
                    0, 4, 2, 4, 48 ,48);
            animationComponent->addAnimation("DEATH", 10.f,
                    1, 4, 4, 4, 48 ,48);
            animationComponent->addAnimation("CORPSE", 10.f,
                    4, 4, 4, 4, 48 ,48);
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
    animationEnum = IDLE_ANIMATION;
    nextAnimationEnum = IDLE_ANIMATION;
    animationDone = false;
    defense = false;

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
            name = "Skeleton Soldier";
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

void Enemy::copyStats(std::shared_ptr<Enemy> enemy) {
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
            evadeChance = 3.8f + mod + (agility/10.f);  //%
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
            evadeChance = 3.4f + mod + (agility/10.f);  //%
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
            evadeChance = 2.f + mod + (agility/10.f);  //%
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
            evadeChance = 5.8f + mod + (agility/10.f);  //%
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
            evadeChance = 2.f + mod + (agility/10.f);  //%
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
            evadeChance = 2.0f + mod + (agility/10.f);  //%
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
            evadeChance = 3.8f + mod + (agility/10.f);  //%
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
            evadeChance = 3.8f + mod + (agility/10.f);  //%
            mp = maxMp;
            hp = maxHp;
            break;
        default:
            std::cout<<"No such enemy: " << type;
            break;
    }
}

void Enemy::updateAnimation(const float &dt) {
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
        case SHIELD_ANIMATION:
            animationDone = animationComponent->play("SHIELD", dt);
            break;
        case WALK_ANIMATION:
            animationDone = animationComponent->play("WALK", dt);
            break;
        case GETHIT_ANIMATION:
            animationDone = animationComponent->play("GETHIT", dt);
            break;
        case DEATH_ANIMATION:
            animationDone = animationComponent->play("DEATH", dt);
            break;
        case CORPSE_ANIMATION:
            animationDone = animationComponent->play("CORPSE", dt);
            break;
    }
    if(animationDone)
        animationEnum = nextAnimationEnum;
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

void Enemy::setAnimation(entity_animation animation) {
    animationEnum = animation;
}

void Enemy::setAnimation(entity_animation animation, entity_animation next_animation) {
    animationEnum = animation;
    nextAnimationEnum = next_animation;
}


void Enemy::setNextAnimation(entity_animation next_animation) {
    nextAnimationEnum = next_animation;
}

int Enemy::getHit(int hit_damage, bool spell_damage) {
    if(!spell_damage){
        hit_damage -= armor;
        if(hit_damage < 0)
            hit_damage = 1;
    }
    hp -= hit_damage;
    if(hp < 0)
        hp = 0;
    return hit_damage;
}

void Enemy::setHp(int new_hp) {
    hp = new_hp;
}

void Enemy::setMp(int new_mp) {
    mp = new_mp;
}

bool Enemy::isDead() const {
    return hp == 0;
}

void Enemy::setDefense(bool b) {
    defense = b;
}

bool Enemy::isDefense() const {
    return defense;
}







