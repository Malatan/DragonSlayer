//
// Created by Zheng on 19/10/2020.
//

#include "Npc.h"

void Npc::initVariables() {

}

void Npc::initAnimations() {
    switch(type){
        case DEFAULT:
            break;
        case SHOP:
            this->animationComponent->addAnimation("IDLE", 10.f,
                                                   0, 0, 17, 0, 128 ,128);
            break;
        case PRIEST:
            this->animationComponent->addAnimation("IDLE", 10.f,
                                                   0, 0, 9, 0, 128 ,128);
            break;
        case WIZARD:
            this->animationComponent->addAnimation("IDLE", 10.f,
                                                   0, 0, 5, 0, 231 ,190);
            break;
    }
}

void Npc::iniHitBoxComponents() {
    switch(type){
        case DEFAULT:
            break;
        case SHOP:
            this->createHitboxComponent(this->sprite, 80.f, 50.f, 32.f, 64.f);
            break;
        case PRIEST:
            this->createHitboxComponent(this->sprite, 80.f, 60.f, 32.f, 55.f);
            break;
        case WIZARD:
            this->createHitboxComponent(this->sprite, 55.f, 36.f, 42.f, 64.f);
            break;
    }
}

Npc::Npc() {

}

Npc::Npc(npc_type type, float x, float y, float scale_x, float scale_y, sf::Texture &texture_sheet, sf::Texture& texture) {
    this->type = type;
    this->scale.x = scale_x;
    this->scale.y = scale_y;
    this->sprite.setScale(this->scale);

    this->createAnimationComponent(texture_sheet);
//    this->createMovementComponent(120.f, 8.f, 4.f);
    this->initAnimations();
    this->iniHitBoxComponents();

    this->setPosition(x, y);

    this->overHeadContainer.setSize(sf::Vector2f(20.f, 20.f));
    this->overHeadContainer.setTexture(&texture);


}

Npc::~Npc() {

}

void Npc::updateAnimation(const float &dt) {
    this->animationComponent->play("IDLE", dt);
}

void Npc::update(const float &dt) {
    this->updateAnimation(dt);
    this->hitboxComponent->update();
    this->overHeadContainer.setPosition(this->hitboxComponent->getPosition().x + this->hitboxComponent->getGlobalBounds().width/2.f - 10.f,
                                        this->hitboxComponent->getPosition().y - 23.f);


}

void Npc::render(sf::RenderTarget &target, const bool show_hitbox) {
    target.draw(this->sprite);
    target.draw(this->overHeadContainer);
    if(show_hitbox)
        this->hitboxComponent->render(target);
}

void Npc::updateCollsion(Entity *entity, npc_type* type) {
    if(*type == NO_NPC || *type == this->type){
        if(entity->getHitboxComponent()->intersects(this->hitboxComponent->getGlobalBounds())){
            this->overHeadContainer.setFillColor(sf::Color::White);
            *type = this->type;
        } else{
            this->overHeadContainer.setFillColor(sf::Color(60,60,60,100));
            *type = NO_NPC;
        }
    }

}




