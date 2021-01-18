//
// Created by andry on 16/01/2021.
//

#include "AIBehaviour.h"

AIBehaviour::~AIBehaviour() {

}

AIBehaviour::AIBehaviour(PathFinder *pathFinder, Entity &enemy, Entity &player, sf::Vector2f spawnPos) : enemy(enemy), player(player) {
    this->pathFinder = pathFinder;
    this->spawnPos = spawnPos;
}

void AIBehaviour::update(const float &dt) {
    float MAXFollowRange = 300;
    float MAXRange = 600;
    float MAXdistance = 300;
    float idleChance = 50;
    float patrolChance = 50;
    std::cout<<statoP<<"->"<<stato<<"\n";

    updateKeyTime(dt);
   if ((abs(enemy.getCollisionBoxCenter().x - spawnPos.x) > MAXRange ||
        abs(enemy.getCollisionBoxCenter().y - spawnPos.y) > MAXRange) || stato == AI_BACKTOSPAWN){
        statoP = stato;
        stato = AI_BACKTOSPAWN;
    }else if (abs(enemy.getCollisionBoxCenter().x - player.getCollisionBoxCenter().x) <= MAXFollowRange &&
              abs(enemy.getCollisionBoxCenter().y - player.getCollisionBoxCenter().y) <= MAXFollowRange) {
        statoP = stato;
        stato = AI_FOLLOW;
    }


    switch (stato) {
        case AI_PATROL:{
            if(enemy.isWayPointEmpty() && statoP == AI_PATROL){
                statoP= stato;
                stato = AI_DEFAULT;
                break;
            }
            bool validTargetPos = false;
            while(!validTargetPos && enemy.isWayPointEmpty()) {
                float distanceX = utils::generateRandomNumber(-MAXdistance, MAXdistance);
                float distanceY = utils::generateRandomNumber(-MAXdistance, MAXdistance);
                sf::Vector2f targetPos = {spawnPos.x + distanceX, spawnPos.y + distanceY};
                int node_x = (int) (targetPos.x / (Tile::TILE_SIZE / (float) pathFinder->nodeMultiplier));
                int node_y = (int) (targetPos.y / (Tile::TILE_SIZE / (float) pathFinder->nodeMultiplier));
                if(node_y < pathFinder->nodes.size() && node_x < pathFinder->nodes[0].size()) {
                    if (pathFinder->nodes[node_y][node_x]->isWalkable()) {
                        if (pathFinder->FindPath(enemy.getCollisionBoxCenter(), targetPos, 300)) {
                            updateWayPoints();
                            enemy.getMovementComponent()->setMaxVelocity(100);
                            std::cout << targetPos.x << " / " << targetPos.y << "\n";
                            validTargetPos = true;
                            statoP = stato;
                            stato = AI_PATROL;
                        }
                    }
                }
            }
            break;
        }
        case AI_IDLE: {
            if(idleTime >= idleTimeMax){
                idleTime = 0;
                statoP= stato;
                stato = AI_DEFAULT;
            } else{
                idleTime += dt;
            }
            break;
        }
        case AI_FOLLOW:{
            if (getKeyTime()) {
                if (pathFinder->FindPath(enemy.getCollisionBoxCenter(), player.getCollisionBoxCenter(), 300)) {
                    updateWayPoints();
                    enemy.getMovementComponent()->setMaxVelocity(200);
                    statoP = stato;
                    stato = AI_FOLLOW;
                }
            }
            break;
        }
        case AI_BACKTOSPAWN:{
            if(enemy.isWayPointEmpty() && (statoP == AI_BACKTOSPAWN)) {
                statoP = stato;
                stato = AI_DEFAULT;
            } else if(statoP != AI_BACKTOSPAWN && !enemy.isWayPointEmpty()){
                if(pathFinder->FindPath(enemy.getCollisionBoxCenter(), spawnPos, 9999)) {
                    updateWayPoints();
                    statoP = stato;
                    stato = AI_BACKTOSPAWN;
                }
            }
            break;
        }
        case AI_DEFAULT:{
            if(utils::trueFalse(idleChance)){
                statoP= stato;
                stato = AI_IDLE;
                idleTimeMax = utils::generateRandomNumberf(1, 3,0);

            }
            else {
                statoP = stato;
                stato = AI_PATROL;
            }
            break;
        }

    }


}

bool AIBehaviour::getKeyTime() {
    if(keyTime >= keyTimeMax){
        keyTime = 0.f;
        return true;
    }
    return false;
}

void AIBehaviour::updateKeyTime(const float &dt) {
    if(keyTime < keyTimeMax){
        keyTime += 60.f * dt;
    }
}

void AIBehaviour::updateWayPoints() {
    enemy.clearWayPoints();
    for (auto i : pathFinder->path) {
        auto mod = (float) pathFinder->nodeMultiplier;
        sf::Vector2f new_waypoint = {((float) i->getPosX() * Tile::TILE_SIZE / mod)
                                     + Tile::TILE_SIZE / (2.f * mod),
                                     ((float) i->getPosY() * Tile::TILE_SIZE / mod)
                                     + Tile::TILE_SIZE / (2.f * mod)};
        enemy.addWayPoint(new_waypoint);
    }
}
