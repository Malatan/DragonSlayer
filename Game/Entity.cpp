//
// Created by Zheng on 07/10/2020.
//

#include "Entity.h"
#include "../Map/Tile.h"

Entity::Entity() = default;

Entity::~Entity() = default;

//component functions
void Entity::setTexture(sf::Texture& texture) {
    sprite.setTexture(texture);

}

void Entity::createHitboxComponent(sf::Sprite& entity_sprite, float offset_x, float offset_y, float width, float height) {
    hitboxComponent = std::make_shared<HitboxComponent>(entity_sprite, offset_x, offset_y, width, height);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration) {
    movementComponent = std::make_shared<MovementComponent>(sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createAnimationComponent(sf::Texture& texture_sheet) {
    animationComponent = std::make_shared<AnimationComponent>(sprite, texture_sheet);
   // this->sprite.setScale(3,3);
}

void Entity::createCollisionBoxComponent(sf::Sprite& entity_sprite, float offset_x, float offset_y, float radius) {
    collisionBoxComponent = std::make_shared<CollisionBoxComponent>(entity_sprite, offset_x, offset_y, radius);
}

//accessors
std::shared_ptr<MovementComponent> Entity::getMovementComponent() {
    return movementComponent;
}

std::shared_ptr<HitboxComponent> Entity::getHitboxComponent() {
    return hitboxComponent;
}


//functions
void Entity::setPosition(const float x, const float y) {
    if(hitboxComponent)  //
        hitboxComponent->setPosition(x, y);
    else
        sprite.setPosition(x, y);
}

void Entity::move(const float& dt, const float dir_x, const float dir_y) {
    if(movementComponent){
        //sets velocity
        movementComponent->move(dir_x, dir_y, dt);
    }

}

void Entity::update(const float &dt) {

}

void Entity::render(sf::RenderTarget& target) {

    target.draw(sprite);
}

sf::Vector2f Entity::getPosition() const{
    if(hitboxComponent) //
        return hitboxComponent->getPosition();

    return sprite.getPosition();
}

sf::FloatRect Entity::getGlobalBounds() const {
    if (hitboxComponent) //
        return hitboxComponent->getGlobalBounds();
    return sprite.getGlobalBounds();
}

sf::FloatRect Entity::getNextPositionBounds(const float& dt){

    if (hitboxComponent && movementComponent){ //
        sf::FloatRect np = hitboxComponent->getNextPosition(movementComponent->getVelocity() * dt);
        np.width = getGlobalBounds().width;
        np.height = getGlobalBounds().height;
        return np;
    }

    return {-1.f, -1.f, -1.f, -1.f};
}

sf::Vector2i Entity::getGridPosition() const {
    if (hitboxComponent)
        return {
                static_cast<int>(hitboxComponent->getPosition().x / Tile::TILE_SIZE),
                static_cast<int>(hitboxComponent->getPosition().y / Tile::TILE_SIZE)
        };

    return {
            static_cast<int>(sprite.getPosition().x / Tile::TILE_SIZE),
            static_cast<int>(sprite.getPosition().y / Tile::TILE_SIZE)
    };
}

void Entity::stopVelocity() {
    if(movementComponent){
        movementComponent->stopVelocity();
    }
}

void Entity::setSpritePositon(const sf::Vector2f pos) {
    sprite.setPosition(pos);
}

std::shared_ptr<CollisionBoxComponent> Entity::getCollisionBoxComponent() {
    return collisionBoxComponent;
}

void Entity::setOrigin(float x, float y) {
    sprite.setOrigin(x, y);
}











