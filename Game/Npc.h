//
// Created by Zheng on 19/10/2020.
//

#ifndef DRAGONSLAYER_NPC_H
#define DRAGONSLAYER_NPC_H

#include "Entity.h"
#include "Player.h"
enum npc_type{
    DEFAULT,
    SHOP,
    PRIEST,
    WIZARD,
    NO_NPC
};

class Npc : public Entity{
public:
    Npc();
    Npc(npc_type type, float x, float y, float scale_x, float scale_y, sf::Texture& texture_sheet, sf::Texture& texture);
    virtual ~Npc();

    //funtions
    void updateAnimation(const float &dt);
    void update(const float &dt);
    void updateCollsion(const std::shared_ptr<Player>& player, npc_type* type);
    void render(sf::RenderTarget& target, const bool show_hitbox = false);

private:
    npc_type  type;
    sf::RectangleShape overHeadContainer;

    //initializer functions
    void initAnimations();
    void iniHitBoxComponents();
};


#endif //DRAGONSLAYER_NPC_H
