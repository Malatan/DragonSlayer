//
// Created by Zheng on 28/10/2020.
//

#include "CollisionBoxComponent.h"

//constructors/destructor
CollisionBoxComponent::CollisionBoxComponent(sf::Sprite& sprite, float offset_x, float offset_y,float radius)
    : sprite(sprite), offsetX(offset_x), offsetY(offset_y), radius(radius){
    modX = 0;
    collisionEllipse = sf::CircleShape(radius);
    collisionEllipse.setScale(2.5f, 0.3f);
    collisionEllipse.setOrigin(radius,radius);
    collisionEllipse.setFillColor(sf::Color(45,45,45));
}

CollisionBoxComponent::~CollisionBoxComponent() {

}

//accessors
sf::CircleShape &CollisionBoxComponent::getCollisionEllipse(){
    return collisionEllipse;
}

//functions
void CollisionBoxComponent::update() {
    collisionEllipse.setPosition(sprite.getPosition().x + offsetX + modX,
            sprite.getPosition().y + offsetY);
}

void CollisionBoxComponent::render(sf::RenderTarget &target) {
    target.draw(collisionEllipse);
}





