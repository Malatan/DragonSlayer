//
// Created by Zheng on 07/10/2020.
//

#ifndef DRAGONSLAYER_ENTITY_H
#define DRAGONSLAYER_ENTITY_H

#include "../Components/MovementComponent.h"
#include "../Components/AnimationComponent.h"
#include "../Components/HitBoxComponent.h"
#include "../Components/CollisionBoxComponent.h"
#include <iostream>

enum entity_animation{
    IDLE_ANIMATION,
    ATTACK_ANIMATION,
    ATTACK2_ANIMATION,
    ATTACK3_ANIMATION,
    ATTACK4_ANIMATION,
    SHIELD_ANIMATION,
    WALK_ANIMATION,
    CAST_ANIMATION,
    GETHIT_ANIMATION,
    DEATH_ANIMATION,
    CORPSE_ANIMATION
};

class Entity {

public:
    Entity();
    virtual ~Entity();

    //component functions
    void setTexture(sf::Texture& texture);
    void createHitboxComponent(sf::Sprite& sprite,
                               float offset_x, float offset_y,
                               float width, float height);
    void createMovementComponent(float maxVelocity, float acceleration, float deceleration);
    void createAnimationComponent(sf::Texture& texture_sheet);
    void createCollisionBoxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float radius);

    //accessors
    virtual sf::Sprite getSprite();
    virtual std::shared_ptr<MovementComponent> getMovementComponent();
    virtual std::shared_ptr<AnimationComponent> getAnimationComponent();
    virtual std::shared_ptr<HitboxComponent> getHitboxComponent();
    virtual std::shared_ptr<CollisionBoxComponent> getCollisionBoxComponent();
    virtual sf::Vector2f getPosition() const;
    virtual sf::Vector2f getSpritePosition() const;
    virtual sf::FloatRect getGlobalBounds() const;
    virtual sf::FloatRect getSpriteGlobalBounds() const;
    virtual sf::FloatRect getNextPositionBounds(const float& dt);
    virtual sf::Vector2i getGridPosition() const;

    //functions
    virtual void setPosition(float x, float y);
    virtual void setOrigin(float x, float y);
    virtual void setScale(float x, float y);
    virtual void move(const float& dt, float x, float y);
    virtual void setPositionY(float y);
    virtual void setPositionX(float x);
    virtual void setSpritePositon(sf::Vector2f pos);


    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget& target);
    virtual void stopVelocity();
    virtual void stopVelocityX();
    virtual void stopVelocityY();

protected:
    sf::Sprite sprite;
    sf::Vector2f scale;

    std::shared_ptr<MovementComponent> movementComponent;
    std::shared_ptr<AnimationComponent> animationComponent;
    std::shared_ptr<HitboxComponent> hitboxComponent;
    std::shared_ptr<CollisionBoxComponent> collisionBoxComponent;
};


#endif //DRAGONSLAYER_ENTITY_H
