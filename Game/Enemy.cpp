//
// Created by Zheng on 08/10/2020.
//

#include "Enemy.h"


//initializer functions
void Enemy::initVariables() {

}

void Enemy::initAnimations() {
    this->animationComponent->addAnimation("IDLE", 10.f,
            0, 0, 7, 0, 250 ,250);
}

//constructors/destructors
Enemy::Enemy(float x, float y, float scale_x ,float scale_y, sf::Texture& texture_sheet) {
    this->scale.x = scale_x;
    this->scale.y = scale_y;
    this->sprite.setScale(this->scale);

    this->createAnimationComponent(texture_sheet);
    this->createHitboxComponent(this->sprite, 46, 26.f, 50.f, 65.f);
    this->initAnimations();

    this->setPosition(x, y);

}

Enemy::Enemy(float x, float y, float scale_x ,float scale_y, float hitbox_offset_x, float hitbox_offset_y,
             float hitbox_width, float hitbox_height, sf::Texture& texture_sheet) {
    this->scale.x = scale_x;
    this->scale.y = scale_y;
    this->sprite.setScale(this->scale);

    this->createAnimationComponent(texture_sheet);
    this->createHitboxComponent(this->sprite, hitbox_offset_x, hitbox_offset_y, hitbox_width, hitbox_height);
    this->initAnimations();

    this->setPosition(x, y);

}

//functions
void Enemy::updateAnimation(const float &dt) {
    this->animationComponent->play("IDLE", dt);
}

void Enemy::update(const float &dt) {
    this->updateAnimation(dt);
    this->hitboxComponent->update();
}

void Enemy::render(sf::RenderTarget &target, const bool show_hitbox) {
    target.draw(this->sprite);
    if(show_hitbox)
        this->hitboxComponent->render(target);
}

string Enemy::enemyDetails() {
    string desc = "";

    desc+= Enemy::name + " LIV." + to_string(Enemy::level) + "     HP[";

    int health =0;
    for(int i=0; i<Enemy::maxHp; i=i+10){
        if(health <= Enemy::hp)
            desc+="#";
        else
            desc+="-";
        health += 10;
    }

    desc+= to_string(Enemy::hp) + "/" + to_string(Enemy::maxHp) + "]\n"
           + "     Armor: " + to_string(Enemy::armor)
           + "     Damage: " + to_string(Enemy::damage) + "\n";

    return desc;
}

int Enemy::takeDamage(int dmg) {
    dmg = dmg - Enemy::armor;
    int newHp = Enemy::hp - dmg;
    Enemy::hp = newHp;

    return dmg;
}

string Enemy::getName() {
    return name;
}

void Enemy::setName(string name) {
    Enemy::name = name;
}

string Enemy::getType() {
    return type;
}

void Enemy::setType(string type) {
    Enemy::type = type;
}

int Enemy::getLevel() {
    return level;
}

void Enemy::setLevel(int level) {
    Enemy::level = level;
}

int Enemy::getHp() {
    return hp;
}

void Enemy::setHp(int hp) {
    Enemy::hp = hp;
}

int Enemy::getMaxHp() {
    return maxHp;
}

void Enemy::setMaxHp(int maxHp) {
    Enemy::maxHp = maxHp;
}

int Enemy::getArmor() {
    return armor;
}

void Enemy::setArmor(int armor) {
    Enemy::armor = armor;
}

int Enemy::getDamage() {
    return damage;
}

void Enemy::setDamage(int damage) {
    Enemy::damage = damage;
}

int Enemy::getCritChance() {
    return critChance;
}

void Enemy::setCritChance(int critChance) {
    Enemy::critChance = critChance;
}

int Enemy::getEvadeChance() {
    return evadeChance;
}

void Enemy::setEvadeChance(int evadeChance) {
    Enemy::evadeChance = evadeChance;
}

Enemy::Enemy() {

}

Enemy::~Enemy() {

}

Enemy::Enemy(string name, string type, int level, int hp, int maxHp, int armor, int damage, int critChance,
         int evadeChance) : name(name), type(type), level(level), hp(hp), maxHp(maxHp), armor(armor), damage(damage),
                            critChance(critChance), evadeChance(evadeChance) {}

