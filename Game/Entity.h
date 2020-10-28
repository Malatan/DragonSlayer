//
// Created by Zheng on 07/10/2020.
//

#ifndef DRAGONSLAYER_ENTITY_H
#define DRAGONSLAYER_ENTITY_H

#include "../Components/MovementComponent.h"
#include "../Components/AnimationComponent.h"
#include "../Components/HitBoxComponent.h"
#include <iostream>

class Entity {
private:
    void initVariables();

protected:
    sf::Sprite sprite;
    sf::Vector2f scale;

    MovementComponent* movementComponent;
    AnimationComponent* animationComponent;
    HitboxComponent* hitboxComponent;

public:
    Entity();
    virtual ~Entity();

    //component functions
    void setTexture(sf::Texture& texture);
    void createHitboxComponent(sf::Sprite& sprite,
                               float offset_x, float offset_y,
                               float width, float height);
    void createMovementComponent(const float maxVelocity, float acceleration, const float deceleration);
    void createAnimationComponent(sf::Texture& texture_sheet);

    //accessors
    virtual sf::Sprite getSprite();
    virtual MovementComponent* getMovementComponent();
    virtual AnimationComponent* getAnimationComponent();
    virtual HitboxComponent* getHitboxComponent();
    virtual const sf::Vector2f getPosition() const;
    virtual const sf::FloatRect getGlobalBounds() const;
    virtual const sf::FloatRect getNextPositionBounds(const float& dt) const;
    virtual const sf::Vector2i getGridPosition() const;

    //functions
    virtual void setPosition(const float x, const float y);
    virtual void move(const float& dt, const float x, const float y);
    virtual void setPositionY(const float y);
    virtual void setPositionX(const float x);

    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget& target);
    virtual void stopVelocity();
    virtual void stopVelocityX();
    virtual void stopVelocityY();
};


#endif //DRAGONSLAYER_ENTITY_H
