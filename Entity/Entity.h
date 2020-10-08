//
// Created by Zheng on 07/10/2020.
//

#ifndef DRAGONSLAYER_ENTITY_H
#define DRAGONSLAYER_ENTITY_H

#include "../Components/MovementComponent.h"
#include "../Components/AnimationComponent.h"
#include <iostream>

class Entity {
private:
    void initVariables();

protected:
    sf::Sprite sprite;
    sf::Vector2f scale;

    MovementComponent* movementComponent;
    AnimationComponent* animationComponent;

public:
    Entity();
    virtual ~Entity();

    //component functions
    void setTexture(sf::Texture& texture);
    void createMovementComponent(const float maxVelocity, float acceleration, const float deceleration);
    void createAnimationComponent(sf::Texture& texture_sheet);

    //accessors
    virtual sf::Sprite getSprite();
    //functions
    virtual void setPosition(const float x, const float y);
    virtual void move(const float& dt, const float x, const float y);

    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget& target);
};


#endif //DRAGONSLAYER_ENTITY_H
