//
// Created by Zheng on 07/10/2020.
//

#ifndef DRAGONSLAYER_MOVEMENTCOMPONENT_H
#define DRAGONSLAYER_MOVEMENTCOMPONENT_H

#include <SFML/Graphics.hpp>
#include "../Core/Common.h"

enum movement_states{
    IDLE = 0,
    MOVING,
    MOVING_LEFT,
    MOVING_RIGHT,
    MOVING_UP,
    MOVING_DOWN
};

class MovementComponent {
public:
    MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration);
    virtual ~MovementComponent();

    //accessors
    void setVelocity(sf::Vector2f new_vel);
    const float& getMaxVelocity() const;
    const sf::Vector2f& getVelocity() const;
    const sf::Vector2f& getPreviousPosition() const;
    bool getState(short unsigned state) const;
    const sf::Vector2f &getDirection() const;
    void setMaxVelocity(float max_velocity);

    //functions
    void stopVelocity();
    void move(float dir_x, float dir_y, const float &dt);
    void pathMove(float dir_x, float dir_y, const float &dt);
    void update(const float &dt);
    void render(sf::RenderTarget & target);

private:
    sf::Sprite& sprite;

    float maxVelocity{};
    float acceleration{};
    float deceleration{};

    sf::Vector2f direction;
    sf::Vector2f velocity;
    sf::Vector2f previousPosition;
};

#endif //DRAGONSLAYER_MOVEMENTCOMPONENT_H
