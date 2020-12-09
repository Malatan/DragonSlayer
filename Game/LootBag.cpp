//
// Created by Zheng on 08/12/2020.
//

#include "LootBag.h"

#include <utility>

//constructors/destructor
LootBag::LootBag(sf::Vector2f position, std::map<std::string, sf::Texture> textures, std::vector<shared_ptr<Item>> loots)
                    : textures(std::move(textures)), loots(std::move(loots)){
    sprite.setScale(sf::Vector2f(0.16f, 0.16f));
    sprite.setTexture(this->textures["LOOTBAG_SPRITE"]);
    LootBag::setPosition(position.x, position.y);
    createHitboxComponent(sprite, 0.f, 0.f, 40.f, 40.f);
    createCollisionBoxComponent(sprite, 20.f, 38.f, 10.f);
    collisionBoxComponent->update();
}

LootBag::~LootBag() = default;

//functions
void LootBag::update(const float &dt) {

}

void LootBag::render(sf::RenderTarget &target, const bool show_hitbox) {
    collisionBoxComponent->render(target);
    target.draw(sprite);
    if(show_hitbox)
        hitboxComponent->render(target);
}

void LootBag::setPosition(float x, float y) {
    if(hitboxComponent)
        hitboxComponent->setPosition(x, y);
    else
        sprite.setPosition(x, y);
}
