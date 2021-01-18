//
// Created by andry on 16/01/2021.
//

#ifndef DRAGONSLAYER_AIBEHAVIOUR_H
#define DRAGONSLAYER_AIBEHAVIOUR_H

#include "../Core/GameState.h"

enum AIStatus{
    AI_DEFAULT,
    AI_FOLLOW,
    AI_PATROL,
    AI_BACKTOSPAWN,
    AI_IDLE
};

class PathFinder;
class AIBehaviour {
public:


    AIBehaviour(PathFinder* pathFinder, Entity& enemy, Entity& player, sf::Vector2f spawnPos);
    virtual ~AIBehaviour();
     void update(const float& dt);
     bool getKeyTime();
     void updateKeyTime(const float& dt);
     void updateWayPoints();


private:
    PathFinder* pathFinder;
    Entity& enemy;
    Entity& player;
    sf::Vector2f spawnPos;
    AIStatus stato{};
    float keyTime = 0.f;
    float keyTimeMax = 20.f;
    float idleTime = 0;
    float idleTimeMax = 0;
    AIStatus statoP{};


};


#endif //DRAGONSLAYER_AIBEHAVIOUR_H
