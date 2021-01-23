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
    //constructor/destructor
    AIBehaviour(PathFinder* pathFinder, Entity& enemy, Entity& player, sf::Vector2f spawnPos);
    virtual ~AIBehaviour();

    //getters/setters
    bool getKeyTime();
    static std::string getStateString(AIStatus stato_enum);
    std::string getCurrentStateString() const;

    //functions
    void update(const float& dt);
    void updateKeyTime(const float& dt);
    void updateWayPoints();

private:
    PathFinder* pathFinder;
    Entity& enemy;
    Entity& player;
    sf::Vector2f spawnPos;
    AIStatus stato{};
    float keyTime{};
    float keyTimeMax;
    float idleTime{};
    float idleTimeMax{};
    float chaseTime{};
    float chaseTimeMax;
    AIStatus statoP{};
};


#endif //DRAGONSLAYER_AIBEHAVIOUR_H
