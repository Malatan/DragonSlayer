//
// Created by Zheng on 28/10/2020.
//

#ifndef DRAGONSLAYER_COLLISIONBOXCOMPONENT_H
#define DRAGONSLAYER_COLLISIONBOXCOMPONENT_H

#include "HitBoxComponent.h"

class CollisionBoxComponent {
private:
    sf::Sprite* sprite;
    sf::CircleShape collisionEllipse;

private:
    float offsetX;
    float offsetY;
    float radius;
    float modX;


protected:

public:
    //constructors/destructor
    CollisionBoxComponent(sf::Sprite* sprite, float offset_x, float offset_y,float radius);
    virtual ~CollisionBoxComponent();

    //accessors
    sf::CircleShape &getCollisionEllipse();

    //modifiers


    //functions
    void update();
    void render(sf::RenderTarget& target);
};


#endif //DRAGONSLAYER_COLLISIONBOXCOMPONENT_H
