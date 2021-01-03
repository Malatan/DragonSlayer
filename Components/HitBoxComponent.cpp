//
// Created by Administrator on 08/10/2020.
//

#include "HitBoxComponent.h"
HitboxComponent::HitboxComponent(sf::Sprite& sprite,
                                 float offset_x, float offset_y,
                                 float width, float height)
        : sprite(sprite), offsetX(offset_x), offsetY(offset_y) {
    nextPosition.left = 0.f;
    nextPosition.top = 0.f;
    nextPosition.height = 0.f;
    nextPosition.width = 0.f;
    hitbox.setPosition(sprite.getPosition().x + offset_x, sprite.getPosition().y + offset_y);
    hitbox.setSize(sf::Vector2f(width, height));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineThickness(-1.f);
    hitbox.setOutlineColor(sf::Color::Green);
    centerRect.setSize(sf::Vector2f(10.f, 10.f));
    centerRect.setFillColor(sf::Color::Red);
}

sf::FloatRect HitboxComponent::getCenterRect() {
    return centerRect.getGlobalBounds();
}

HitboxComponent::~HitboxComponent() = default;

//Accessors
const sf::Vector2f & HitboxComponent::getPosition() const {
    return hitbox.getPosition();
}

sf::FloatRect HitboxComponent::getGlobalBounds() const {
    return hitbox.getGlobalBounds();
}

//Modifiers
void HitboxComponent::setPosition(const sf::Vector2f& position) {
    hitbox.setPosition(position);
    sprite.setPosition(position.x - offsetX, position.y - offsetY);
}

void HitboxComponent::setPosition(const float x, const float y) {
    hitbox.setPosition(x, y);
    sprite.setPosition(x - offsetX, y - offsetY);
}

//Functions
bool HitboxComponent::intersects(const sf::FloatRect& frect) {
    return hitbox.getGlobalBounds().intersects(frect);
}

void HitboxComponent::update() {
    hitbox.setPosition(sprite.getPosition().x + offsetX, sprite.getPosition().y + offsetY);
    centerRect.setPosition(getCenter().x - 5.f, getCenter().y - 5.f);
}

void HitboxComponent::render(sf::RenderTarget & target) {
    target.draw(hitbox);
}

sf::Vector2f HitboxComponent::getCenter() {
    return {hitbox.getPosition().x + hitbox.getGlobalBounds().width/2.f,
            hitbox.getPosition().y + hitbox.getGlobalBounds().height/2.f};
}

const sf::FloatRect & HitboxComponent::getNextPosition(const sf::Vector2f &velocity){
    nextPosition.left = hitbox.getPosition().x + velocity.x;
    nextPosition.top = hitbox.getPosition().y + velocity.y;
    return nextPosition;
}
