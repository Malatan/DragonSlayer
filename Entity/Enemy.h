//
// Created by Zheng on 08/10/2020.
//

#ifndef DRAGONSLAYER_ENEMY_H
#define DRAGONSLAYER_ENEMY_H

#include "Entity.h"

class Enemy : public Entity{
private:
    //variables

    //initializer functions
    void initVariables();
    void initAnimations();

protected:

public:
    Enemy(float x, float y,float scale_x ,float scale_y, sf::Texture& texture_sheet);
    Enemy(float x, float y,float scale_x ,float scale_y, float hitbox_offset_x, float hitbox_offset_y,
            float hitbox_width, float hitbox_height, sf::Texture& texture_sheet);
    virtual ~Enemy();

    //funtions
    void updateAnimation(const float &dt);
    virtual void update(const float &dt);
    void render(sf::RenderTarget& target, const bool show_hitbox = false);
};


#endif //DRAGONSLAYER_ENEMY_H
