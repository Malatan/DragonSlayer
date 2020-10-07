//
// Created by Zheng on 07/10/2020.
//

#ifndef DRAGONSLAYER_PLAYER_H
#define DRAGONSLAYER_PLAYER_H

#include "Entity.h"

class Player : public Entity{
private:
    //variables

    //initializer functions
    void initVariables();

protected:

public:
    Player(float x, float y, sf::Texture& texture_sheet);
    virtual ~Player();

    //funtions
    virtual void update(const float &dt);
};



#endif //DRAGONSLAYER_PLAYER_H
