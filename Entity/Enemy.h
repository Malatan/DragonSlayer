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

protected:

public:
    Enemy(float x, float y, sf::Texture& texture_sheet);
    virtual ~Enemy();

    //funtions
    void updateAnimation(const float &dt);
    virtual void update(const float &dt);
};


#endif //DRAGONSLAYER_ENEMY_H
