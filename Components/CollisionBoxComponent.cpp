//
// Created by Zheng on 28/10/2020.
//

#include "CollisionBoxComponent.h"

//constructors/destructor
CollisionBoxComponent::CollisionBoxComponent(sf::Sprite* sprite, float offset_x, float offset_y,float radius)
    : sprite(sprite), offsetX(offset_x), offsetY(offset_y), radius(radius){
    this->modX = 0;
    this->collisionEllipse = sf::CircleShape(radius);
    this->collisionEllipse.setScale(2.5f, 0.3f);
    this->collisionEllipse.setOrigin(radius,radius);
    this->collisionEllipse.setFillColor(sf::Color(45,45,45));
}

CollisionBoxComponent::~CollisionBoxComponent() {

}

//accessors
sf::CircleShape &CollisionBoxComponent::getCollisionEllipse(){
    return this->collisionEllipse;
}

//functions
void CollisionBoxComponent::update() {
    this->collisionEllipse.setPosition(this->sprite->getPosition().x + this->offsetX + this->modX,
            this->sprite->getPosition().y + this->offsetY);
}

void CollisionBoxComponent::render(sf::RenderTarget &target) {
    target.draw(this->collisionEllipse);
}





