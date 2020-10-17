//
// Created by Administrator on 08/10/2020.
//

#include "HitBoxComponent.h"

HitboxComponent::HitboxComponent(sf::Sprite& sprite,
                                 float offset_x, float offset_y,
                                 float width, float height)
        : sprite(sprite), offsetX(offset_x), offsetY(offset_y)
{
    this->hitbox.setPosition(this->sprite.getPosition().x + offset_x, this->sprite.getPosition().y + offset_y);
    this->hitbox.setSize(sf::Vector2f(width, height));
    this->hitbox.setFillColor(sf::Color::Transparent);
    this->hitbox.setOutlineThickness(-1.f);
    this->hitbox.setOutlineColor(sf::Color::Green);
}

HitboxComponent::~HitboxComponent()
{

}

//Accessors
const sf::Vector2f & HitboxComponent::getPosition() const
{
    return this->hitbox.getPosition();
}

const sf::FloatRect HitboxComponent::getGlobalBounds() const
{
    return this->hitbox.getGlobalBounds();
}

//Modifiers
void HitboxComponent::setPosition(const sf::Vector2f& position)
{
    this->hitbox.setPosition(position);
    this->sprite.setPosition(position.x - this->offsetX, position.y - this->offsetY);
}

void HitboxComponent::setPosition(const float x, const float y)
{
    this->hitbox.setPosition(x, y);
    this->sprite.setPosition(x - this->offsetX, y - this->offsetY);
}

//Functions
bool HitboxComponent::intersects(const sf::FloatRect& frect)
{
    return this->hitbox.getGlobalBounds().intersects(frect);
}

void HitboxComponent::update()
{
    this->hitbox.setPosition(this->sprite.getPosition().x + this->offsetX, this->sprite.getPosition().y + this->offsetY);
}

void HitboxComponent::render(sf::RenderTarget & target)
{
    target.draw(this->hitbox);
}

sf::Vector2f HitboxComponent::getCenter() {
    return sf::Vector2f(this->hitbox.getPosition().x + this->hitbox.getGlobalBounds().width/2.f,
            this->hitbox.getPosition().y + this->hitbox.getGlobalBounds().height/2.f);
}
