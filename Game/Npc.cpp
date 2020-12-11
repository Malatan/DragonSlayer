//
// Created by Zheng on 19/10/2020.
//

#include "Npc.h"

void Npc::initAnimations() {
    switch(type){
        case SHOP:
            animationComponent->addAnimation("IDLE", 10.f,
                                                   0, 0, 17, 0, 128 ,128);
            break;
        case PRIEST:
            animationComponent->addAnimation("IDLE", 10.f,
                                                   0, 0, 9, 0, 128 ,128);
            break;
        case WIZARD:
            animationComponent->addAnimation("IDLE", 10.f,
                                                   0, 0, 5, 0, 231 ,190);
            break;
        case NO_NPC: case DEFAULT_NPC:
            break;
    }
}

void Npc::iniHitBoxComponents() {
    switch(type){
        case SHOP:
            createHitboxComponent(sprite, 80.f, 50.f, 32.f, 64.f);
            break;
        case PRIEST:
            createHitboxComponent(sprite, 80.f, 60.f, 32.f, 55.f);
            break;
        case WIZARD:
            createHitboxComponent(sprite, 55.f, 36.f, 42.f, 64.f);
            break;
        case NO_NPC: case DEFAULT_NPC:
            break;
    }
}

void Npc::initCollisionComponents() {
    switch(type){
        case SHOP:
            createCollisionBoxComponent(sprite, 95.f, 114.f, 7.f);
            break;
        case PRIEST:
            createCollisionBoxComponent(sprite, 96.f, 115.f, 7.f);
            break;
        case WIZARD:
            createCollisionBoxComponent(sprite, 75.f, 99.f, 8.f);
            break;
        case NO_NPC: case DEFAULT_NPC:
            break;
    }
}

Npc::Npc() = default;

Npc::Npc(npc_type type, float x, float y, float scale_x, float scale_y, sf::Texture &texture_sheet, sf::Texture& texture) {
    this->type = type;
    scale.x = scale_x;
    scale.y = scale_y;
    sprite.setScale(this->scale);
    createAnimationComponent(texture_sheet);
    initAnimations();
    iniHitBoxComponents();
    initCollisionComponents();
    Npc::setPosition(x, y);
    hitboxComponent->update();
    collisionBoxComponent->update();
    overHeadContainer.setSize(sf::Vector2f(20.f, 20.f));
    overHeadContainer.setTexture(&texture);
    overHeadContainer.setPosition(hitboxComponent->getPosition().x + hitboxComponent->getGlobalBounds().width/2.f - 10.f,
                                  hitboxComponent->getPosition().y - 23.f);
}

Npc::~Npc() = default;

void Npc::updateAnimation(const float &dt) {
    animationComponent->play("IDLE", dt);
}

void Npc::update(const float &dt) {
    updateAnimation(dt);
}

void Npc::render(sf::RenderTarget &target, const bool show_hitbox) {
    collisionBoxComponent->render(target);
    target.draw(sprite);
    target.draw(overHeadContainer);
    if(show_hitbox)
        hitboxComponent->render(target);
}

void Npc::updateCollision(const std::shared_ptr<Player>& player, npc_type* current_type) {
    if(*current_type == NO_NPC || *current_type == this->type){
        if(player->getHitboxComponent()->intersects(hitboxComponent->getGlobalBounds())){
            overHeadContainer.setFillColor(sf::Color::White);
            *current_type = this->type;
        } else{
            overHeadContainer.setFillColor(sf::Color(60,60,60,100));
            *current_type = NO_NPC;
        }
    }
}

void Npc::setPosition(float x, float y) {
    if(hitboxComponent)
        hitboxComponent->setPosition(x, y);
    else
        sprite.setPosition(x, y);
}





