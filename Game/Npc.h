//
// Created by Zheng on 19/10/2020.
//

#ifndef DRAGONSLAYER_NPC_H
#define DRAGONSLAYER_NPC_H

#include "Entity.h"
#include "Player.h"
enum npc_type{
    DEFAULT_NPC,
    SHOP,
    PRIEST,
    WIZARD,
    NO_NPC
};

class Npc : public Entity{
public:
    Npc();
    Npc(npc_type type, float x, float y, float scale_x, float scale_y, sf::Texture& texture_sheet, sf::Texture& texture);
    ~Npc() override;

    //funtions
    void setPosition(float x, float y) override;
    void updateAnimation(const float &dt);
    void update(const float &dt) override;
    void updateCollsion(const std::shared_ptr<Player>& player, npc_type* current_type);
    void render(sf::RenderTarget& target, bool show_hitbox = false);

private:
    npc_type type{};
    sf::RectangleShape overHeadContainer;

    //initializer functions
    void initAnimations();
    void iniHitBoxComponents();
};


#endif //DRAGONSLAYER_NPC_H
