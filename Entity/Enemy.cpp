//
// Created by Zheng on 08/10/2020.
//

#include "Enemy.h"


//initializer functions
void Enemy::initVariables() {
}

//constructors/destructors
Enemy::Enemy(float x, float y, sf::Texture& texture_sheet) {
    this->initVariables();
    this->setPosition(x, y);
    this->createAnimationComponent(texture_sheet);
    this->animationComponent->addAnimation("IDLE", 10.f, 0, 0, 7, 0, 250 ,250);
}

Enemy::~Enemy() {

}

//functions
void Enemy::updateAnimation(const float &dt) {
    this->animationComponent->play("IDLE", dt);
}

void Enemy::update(const float &dt) {
    this->updateAnimation(dt);
}