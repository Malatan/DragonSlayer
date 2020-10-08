//
// Created by Zheng on 07/10/2020.
//

#include "Player.h"

//initializer functions
void Player::initVariables() {
}

//constructors/destructors
Player::Player(float x, float y, float scale_x, float scale_y, sf::Texture& texture_sheet) {
    this->initVariables();

    this->scale.x = scale_x;
    this->scale.y = scale_y;

    this->sprite.setScale(this->scale);

    this->setPosition(x, y);
    this->createAnimationComponent(texture_sheet);
    this->createMovementComponent(120.f, 8.f, 4.f);

    this->animationComponent->addAnimation("IDLE", 10.f, 0, 0, 14, 0, 64 ,64);
    this->animationComponent->addAnimation("WALK", 6.f, 0, 1, 7, 1, 64 ,64);


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
}