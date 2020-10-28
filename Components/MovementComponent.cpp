//
// Created by Zheng on 07/10/2020.
//

#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite,
                                     float maxVelocity, float acceleration, float deceleration)
        : sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration){

}

MovementComponent::~MovementComponent() {

}

//accessors
const float &MovementComponent::getMaxVelocity() const {
    return this->maxVelocity;
}

const sf::Vector2f &MovementComponent::getVelocity() const {
    return this->velocity;
}

//functions
const bool MovementComponent::getState(const short unsigned state) const {
    switch(state){
        case IDLE:
            if(this->velocity.x == 0.f && this->velocity.y == 0.f)
                return true;
            break;
        case MOVING:
            if(this->velocity.x == 0.f || this->velocity.y == 0.f)
                return true;
            break;
        case MOVING_LEFT:
            if(this->velocity.x < 0.f)
                return true;
            break;
        case MOVING_RIGHT:
            if(this->velocity.x > 0.f)
                return true;
            break;
        case MOVING_UP:
            if(this->velocity.y < 0.f)
                return true;
            break;
        case MOVING_DOWN:
            if(this->velocity.y > 0.f)
                return true;
            break;
    }
    return false;
}

void MovementComponent::move(const float dir_x, const float dir_y, const float &dt) {
    //accelera lo sprite fino alla velocita massima
    this->velocity.x += this->acceleration * dir_x;
    this->velocity.y += this->acceleration * dir_y;

}

void MovementComponent::update(const float &dt) {
    //decelera lo sprite e controlla la velocita massima
    //fa movere lo sprite

    //controllo hitbox collisions


    if(this->velocity.x > 0.f){//controlla per x positiva
        //controlla velocita massima per x positiva
        if(this->velocity.x > this->maxVelocity){
            this->velocity.x = this->maxVelocity;
        }
        //decelerazione per x positiva
        this->velocity.x -= deceleration;
        if(this->velocity.x < 0.f){
            this->velocity.x = 0.f;
        }
    } else if(this->velocity.x < 0.f){//controlla per x negativa
        //controlla velocita massima per x negativa
        if(this->velocity.x < -this->maxVelocity){
            this->velocity.x = -this->maxVelocity;
        }
        //decelerazione per x negativa
        this->velocity.x += deceleration;
        if(this->velocity.x > 0.f){
            this->velocity.x = 0.f;
        }
    }

    if(this->velocity.y > 0.f){//controlla per y positiva
        //controlla velocita massima per y positiva
        if(this->velocity.y > this->maxVelocity){
            this->velocity.y = this->maxVelocity;
        }
        //decelerazione per y positiva
        this->velocity.y -= deceleration;
        if(this->velocity.y < 0.f){
            this->velocity.y = 0.f;
        }
    } else if(this->velocity.y < 0.f){//controlla per y negativa
        //controlla velocita massima per y negativa
        if(this->velocity.y < -this->maxVelocity){
            this->velocity.y = -this->maxVelocity;
        }
        //decelerazione per y negativa
        this->velocity.y += deceleration;
        if(this->velocity.y > 0.f){
            this->velocity.y = 0.f;
        }
    }

    //movimento finale
    this->sprite.move(this->velocity * dt);
}

void MovementComponent::stopVelocity() {
    this->velocity.x = 0.f;
    this->velocity.y = 0.f;

}

void MovementComponent::stopVelocityX() {
    this->velocity.x = 0.f;
}

void MovementComponent::stopVelocityY() {
    this->velocity.y = 0.f;
}
