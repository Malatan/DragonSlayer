//
// Created by Zheng on 07/10/2020.
//

#include "Player.h"

//initializer functions
void Player::initVariables() {
}

//constructors/destructors
Player::Player(float x, float y, sf::Texture& texture_sheet) {
    this->initVariables();

    this->setPosition(x, y);

    this->createMovementComponent(120.f, 8.f, 4.f);

    this->sprite.setTexture(texture_sheet);
}

Player::~Player() {

}

//functions

void Player::update(const float &dt) {
    this->movementComponent->update(dt);

}