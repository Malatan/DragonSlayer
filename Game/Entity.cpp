//
// Created by Zheng on 07/10/2020.
//

#include "Entity.h"
#include "../Map/Tile.h"

void Entity::initVariables() {
    this->movementComponent = NULL;
    this->animationComponent = NULL;
}

Entity::Entity() {
    this->initVariables();

}

Entity::~Entity() {
    delete this->movementComponent;
    delete this->animationComponent;
}

//component functions
void Entity::setTexture(sf::Texture& texture) {
    this->sprite.setTexture(texture);

}

void Entity::createHitboxComponent(sf::Sprite &sprite, float offset_x, float offset_y, float width, float height) {
    this->hitboxComponent = new HitboxComponent(sprite, offset_x, offset_y, width, height);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration) {
    this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createAnimationComponent(sf::Texture& texture_sheet) {
    this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
   // this->sprite.setScale(3,3);
}

//accessors
sf::Sprite Entity::getSprite(){
    return this->sprite;
}

MovementComponent *Entity::getMovementComponent() {
    return this->movementComponent;
}

AnimationComponent *Entity::getAnimationComponent() {
    return this->animationComponent;
}

HitboxComponent *Entity::getHitboxComponent() {
    return this->hitboxComponent;
}


//functions
void Entity::setPosition(const float x, const float y) {
    if(this->hitboxComponent)
        this->hitboxComponent->setPosition(x, y);
    else
        this->sprite.setPosition(x, y);
}


void Entity::move(const float& dt, const float dir_x, const float dir_y) {
    if(this->movementComponent){
        //sets velocity
        this->movementComponent->move(dir_x, dir_y, dt);
    }

}

void Entity::update(const float &dt) {

}

void Entity::render(sf::RenderTarget& target) {

    target.draw(this->sprite);
}

const sf::Vector2f Entity::getPosition() const{
    if(this->hitboxComponent)
        return this->hitboxComponent->getPosition();

    return this->sprite.getPosition();
}

const sf::FloatRect Entity::getGlobalBounds() const {
    if (this->hitboxComponent)
        return this->hitboxComponent->getGlobalBounds();
    return this->sprite.getGlobalBounds();
}

const sf::FloatRect Entity::getNextPositionBounds(const float& dt) const
{

    if (this->hitboxComponent && this->movementComponent){
        sf::FloatRect np = this->hitboxComponent->getNextPosition(this->movementComponent->getVelocity() * dt);
        np.width = this->getGlobalBounds().width;
        np.height = this->getGlobalBounds().height;
        return np;
    }



    return sf::FloatRect(-1.f, -1.f, -1.f, -1.f);
}

const sf::Vector2i Entity::getGridPosition() const
{
    if (this->hitboxComponent)
        return sf::Vector2i(
                static_cast<int>(this->hitboxComponent->getPosition().x) / Tile::TILE_SIZE,
                static_cast<int>(this->hitboxComponent->getPosition().y) / Tile::TILE_SIZE
        );

    return sf::Vector2i(
            static_cast<int>(this->sprite.getPosition().x) / Tile::TILE_SIZE,
            static_cast<int>(this->sprite.getPosition().y) / Tile::TILE_SIZE
    );
}

void Entity::stopVelocity() {
    if(this->movementComponent){
        this->movementComponent->stopVelocity();
    }
}

void Entity::stopVelocityX() {
    if(this->movementComponent){
        this->movementComponent->stopVelocityX();
    }
}

void Entity::stopVelocityY() {
    if(this->movementComponent){
        this->movementComponent->stopVelocityY();
    }
}

void Entity::setPositionY(const float y) {
    if(this->hitboxComponent)
        this->hitboxComponent->setPositionY(y);
    else
        this->sprite.setPosition(this->sprite.getPosition().x, y);
}

void Entity::setPositionX(const float x) {
    if(this->hitboxComponent)
        this->hitboxComponent->setPositionX(x);
    else
        this->sprite.setPosition(x, this->sprite.getPosition().y);
}

void Entity::setSpritePositon(const sf::Vector2f pos) {
    this->sprite.setPosition(pos);
}









