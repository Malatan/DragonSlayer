//
// Created by Zheng on 07/10/2020.
//

#include "Entity.h"

void Entity::initVariables() {
    this->movementComponent = NULL;
    this->animationComponent = NULL;
}

Entity::Entity() {
    this->initVariables();

}

Entity::~Entity() {
    delete this->movementComponent;
    delete this->animationComponent;
}

//component functions
void Entity::setTexture(sf::Texture& texture) {
    this->sprite.setTexture(texture);

}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration) {
    this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createAnimationComponent(sf::Texture& texture_sheet) {
    this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
   // this->sprite.setScale(3,3);
}

//accessors
sf::Sprite Entity::getSprite(){
    return this->sprite;
}


//functions
void Entity::setPosition(const float x, const float y) {
    this->sprite.setPosition(x, y);
}

void Entity::move(const float& dt, const float dir_x, const float dir_y) {
    if(this->movementComponent){
        //sets velocity
        this->movementComponent->move(dir_x, dir_y, dt);
    }

}

void Entity::update(const float &dt) {

}

void Entity::render(sf::RenderTarget& target) {

    target.draw(this->sprite);
}


