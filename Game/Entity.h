//
// Created by Zheng on 07/10/2020.
//

#ifndef DRAGONSLAYER_ENTITY_H
#define DRAGONSLAYER_ENTITY_H

#include "../Core/Common.h"
#include "../Components/MovementComponent.h"
#include "../Components/AnimationComponent.h"
#include "../Components/HitBoxComponent.h"
#include "../Components/CollisionBoxComponent.h"
#include <iostream>
#include <queue>
#include <cmath>
#include <../Game/Utils.h>

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
    void createHitboxComponent(sf::Sprite& entity_sprite,
                               float offset_x, float offset_y,
                               float width, float height);
    void createMovementComponent(float maxVelocity, float acceleration, float deceleration);
    void createAnimationComponent(sf::Texture& texture_sheet);
    void createCollisionBoxComponent(sf::Sprite& entity_sprite, float offset_x, float offset_y, float radius);

    //waypoints
    const vector<sf::Vertex> &getWayPoints() const;
    void addWayPoint(sf::Vector2f point);
    void clearWayPoints();
    bool isWayPointEmpty();

    //accessors
    virtual std::shared_ptr<MovementComponent> getMovementComponent();
    virtual std::shared_ptr<HitboxComponent> getHitboxComponent();
    virtual std::shared_ptr<CollisionBoxComponent> getCollisionBoxComponent();
    virtual sf::Vector2f getPosition() const;
    virtual sf::Vector2f getCenter() const;
    virtual sf::Vector2f getCollisionBoxCenter();
    virtual sf::FloatRect getGlobalBounds() const;
    virtual sf::Vector2i getGridPosition() const;
    virtual bool isPlayerInView() const;
    virtual void setPlayerInView(bool player_in_view);

    //functions
    virtual void setPosition(float x, float y);
    virtual void setOrigin(float x, float y);
    virtual void move(const float& dt, float x, float y);
    virtual void setSpritePositon(sf::Vector2f pos);
    virtual void updateWaypoint(const float& dt);
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget& target);
    virtual void stopVelocity();

protected:
    sf::Sprite sprite;
    sf::Vector2f scale;
    std::vector<sf::Vertex> wayPoints;
    bool playerInView{};
    std::shared_ptr<MovementComponent> movementComponent;
    std::shared_ptr<AnimationComponent> animationComponent;
    std::shared_ptr<HitboxComponent> hitboxComponent;
    std::shared_ptr<CollisionBoxComponent> collisionBoxComponent;
};


#endif //DRAGONSLAYER_ENTITY_H
