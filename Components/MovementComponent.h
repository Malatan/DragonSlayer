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
private:
    sf::Sprite& sprite;

    float maxVelocity;
    float acceleration;
    float deceleration;

    sf::Vector2f velocity;


protected:


public:
    MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration);
    virtual ~MovementComponent();

    //accessors
    const float& getMaxVelocity() const;
    const sf::Vector2f& getVelocity() const;

    //functions
    const bool getState(const short unsigned state) const;

    void move(const float dir_x, const float dir_y, const float &dt);
    void update(const float &dt);

};

#endif //DRAGONSLAYER_MOVEMENTCOMPONENT_H
