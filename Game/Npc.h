//
// Created by Zheng on 19/10/2020.
//

#ifndef DRAGONSLAYER_NPC_H
#define DRAGONSLAYER_NPC_H

#include "Entity.h"

enum npc_type{
    DEFAULT,
    SHOP,
    HEAL,
};

class Npc : public Entity{
private:
    npc_type  type;

    sf::RectangleShape overHeadContainer;


    //initializer functions
    void initVariables();
    void initAnimations();
    void iniHitBoxComponents();

public:
    Npc();
    Npc(npc_type type, float x, float y, float scale_x, float scale_y, sf::Texture& texture_sheet, sf::Texture& texture);
    virtual ~Npc();

    //funtions
    void updateAnimation(const float &dt);
    void update(const float &dt);
    bool updateCollsion(Entity* entity);
    void render(sf::RenderTarget& target, const bool show_hitbox = false);

};


#endif //DRAGONSLAYER_NPC_H
