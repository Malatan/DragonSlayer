//
// Created by Zheng on 07/10/2020.
//

#include "MovementComponent.h"
MovementComponent::MovementComponent(sf::Sprite& sprite,
                                     float maxVelocity, float acceleration, float deceleration)
        : sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration){
    previousPosition = sprite.getPosition();
    speedControl = true;
}

MovementComponent::~MovementComponent() = default;

//accessors
const float &MovementComponent::getMaxVelocity() const {
    return maxVelocity;
}

const sf::Vector2f &MovementComponent::getVelocity() const {
    return velocity;
}

const sf::Vector2f &MovementComponent::getPreviousPosition() const {
    return previousPosition;
}

bool MovementComponent::getState(const short unsigned state) const {
    switch(state){
        case IDLE:
            if(velocity.x == 0.f && velocity.y == 0.f)
                return true;
            break;
        case MOVING:
            if(velocity.x == 0.f || velocity.y == 0.f)
                return true;
            break;
        case MOVING_LEFT:
            if(velocity.x < 0.f)
                return true;
            break;
        case MOVING_RIGHT:
            if(velocity.x > 0.f)
                return true;
            break;
        case MOVING_UP:
            if(velocity.y < 0.f)
                return true;
            break;
        case MOVING_DOWN:
            if(velocity.y > 0.f)
                return true;
            break;
        default:
            break;
    }
    return false;
}

void MovementComponent::setVelocity(sf::Vector2f new_vel) {
    velocity = new_vel;
}

//modifers
void MovementComponent::enableSpeedControl(bool b) {
    speedControl = b;
}

//functions
void MovementComponent::move(const float dir_x, const float dir_y, const float &dt) {
    direction.x = dir_x;
    direction.y = dir_y;
    //accelera lo sprite fino alla velocita massima
    velocity.x += acceleration * dir_x;
    velocity.y += acceleration * dir_y;
}

void MovementComponent::pathMove(float dir_x, float dir_y, const float &dt) {
    direction.x = dir_x;
    direction.y = dir_y;

    velocity.x = maxVelocity * dir_x;
    velocity.y = maxVelocity * dir_y;
}

void MovementComponent::stopVelocity() {
    velocity.x = 0.f;
    velocity.y = 0.f;

}

void MovementComponent::update(const float &dt) {
    //decelera lo sprite e controlla la velocita massima
    //fa movere lo sprite
    //controllo hitbox collisions

    if(velocity.x > 0.f){//controlla per x positiva
        //controlla velocita massima per x positiva
        if(velocity.x > maxVelocity && speedControl){
            velocity.x = maxVelocity;
        }
        //decelerazione per x positiva
        velocity.x -= deceleration;
        if(velocity.x < 0.f){
            velocity.x = 0.f;
        }
    } else if(velocity.x < 0.f){//controlla per x negativa
        //controlla velocita massima per x negativa
        if(velocity.x < -maxVelocity && speedControl){
            velocity.x = -maxVelocity;
        }
        //decelerazione per x negativa
        velocity.x += deceleration;
        if(velocity.x > 0.f){
            velocity.x = 0.f;
        }
    }

    if(velocity.y > 0.f){//controlla per y positiva
        //controlla velocita massima per y positiva
        if(velocity.y > maxVelocity && speedControl){
            velocity.y = maxVelocity;
        }
        //decelerazione per y positiva
        velocity.y -= deceleration;
        if(velocity.y < 0.f){
            velocity.y = 0.f;
        }
    } else if(velocity.y < 0.f){//controlla per y negativa
        //controlla velocita massima per y negativa
        if(velocity.y < -maxVelocity && speedControl){
            velocity.y = -maxVelocity;
        }
        //decelerazione per y negativa
        velocity.y += deceleration;
        if(velocity.y > 0.f){
            velocity.y = 0.f;
        }
    }

    //movimento finale
    previousPosition = sprite.getPosition();
    sprite.move(velocity * dt);
}

void MovementComponent::render(sf::RenderTarget &target) {

}

const sf::Vector2f &MovementComponent::getDirection() const {
    return direction;
}




