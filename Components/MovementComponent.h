//
// Created by Zheng on 07/10/2020.
//

#ifndef DRAGONSLAYER_MOVEMENTCOMPONENT_H
#define DRAGONSLAYER_MOVEMENTCOMPONENT_H

#include <SFML/Graphics.hpp>

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

    //modifers
    void enableSpeedControl(bool b);

    //accessors
    void setVelocity(sf::Vector2f new_velocity);
    const float& getMaxVelocity() const;
    const sf::Vector2f& getVelocity() const;
    const sf::Vector2f& getPreviousPosition() const;

    //functions
    bool getState(short unsigned state) const;
    void move(float dir_x, float dir_y, const float &dt);
    void update(const float &dt);
    void stopVelocity();

private:
    sf::Sprite& sprite;

    float maxVelocity;
    float acceleration;
    float deceleration;
    bool speedControl;

    sf::Vector2f velocity;
    sf::Vector2f previousPosition;
};

#endif //DRAGONSLAYER_MOVEMENTCOMPONENT_H
