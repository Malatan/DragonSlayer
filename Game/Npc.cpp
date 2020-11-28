//
// Created by Zheng on 19/10/2020.
//

#include "Npc.h"

void Npc::initAnimations() {
    switch(type){
        case DEFAULT:
            break;
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
    }
}

void Npc::iniHitBoxComponents() {
    switch(type){
        case DEFAULT:
            break;
        case SHOP:
            createHitboxComponent(sprite, 80.f, 50.f, 32.f, 64.f);
            break;
        case PRIEST:
            createHitboxComponent(sprite, 80.f, 60.f, 32.f, 55.f);
            break;
        case WIZARD:
            createHitboxComponent(sprite, 55.f, 36.f, 42.f, 64.f);
            break;
    }
}

Npc::Npc() {

}

Npc::Npc(npc_type type, float x, float y, float scale_x, float scale_y, sf::Texture &texture_sheet, sf::Texture& texture) {
    this->type = type;
    scale.x = scale_x;
    scale.y = scale_y;
    sprite.setScale(this->scale);
    createAnimationComponent(texture_sheet);
    initAnimations();
    iniHitBoxComponents();
    setPosition(x, y);
    overHeadContainer.setSize(sf::Vector2f(20.f, 20.f));
    overHeadContainer.setTexture(&texture);
}

Npc::~Npc() {

}

void Npc::updateAnimation(const float &dt) {
    animationComponent->play("IDLE", dt);
}

void Npc::update(const float &dt) {
    updateAnimation(dt);
    hitboxComponent->update();
    overHeadContainer.setPosition(hitboxComponent->getPosition().x + hitboxComponent->getGlobalBounds().width/2.f - 10.f,
                                        hitboxComponent->getPosition().y - 23.f);
}

void Npc::render(sf::RenderTarget &target, const bool show_hitbox) {
    target.draw(sprite);
    target.draw(overHeadContainer);
    if(show_hitbox)
        hitboxComponent->render(target);
}

void Npc::updateCollsion(const std::shared_ptr<Player>& player, npc_type* type) {
    if(*type == NO_NPC || *type == this->type){
        if(player->getHitboxComponent()->intersects(hitboxComponent->getGlobalBounds())){
            overHeadContainer.setFillColor(sf::Color::White);
            *type = this->type;
        } else{
            overHeadContainer.setFillColor(sf::Color(60,60,60,100));
            *type = NO_NPC;
        }
    }
}




