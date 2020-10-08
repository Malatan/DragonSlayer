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

Enemy::~Enemy() {

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
