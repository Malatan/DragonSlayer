//
// Created by andry on 16/01/2021.
//

#include "AIBehaviour.h"

//constructor/destructor
AIBehaviour::AIBehaviour(PathFinder *pathFinder, Entity &enemy, Entity &player, sf::Vector2f spawnPos) : enemy(enemy),
            player(player) {
    this->pathFinder = pathFinder;
    this->spawnPos = spawnPos;
    keyTimeMax = 20.f;
    chaseTimeMax = 5.f;
    stuckTimeMax = 5.f;
    canThink = true;
}

AIBehaviour::~AIBehaviour() = default;

//getters/setters
bool AIBehaviour::getKeyTime() {
    if (keyTime >= keyTimeMax) {
        keyTime = 0.f;
        return true;
    }
    return false;
}

std::string AIBehaviour::getStateString(AIStatus stato_enum) {
    switch (stato_enum) {
        case AI_DEFAULT:
            return "AI-DEFAULT";
        case AI_FOLLOW:
            return "AI-FOLLOW";
        case AI_PATROL:
            return "AI-PATROL";
        case AI_BACKTOSPAWN:
            return "AI-BACKTOSPAWN";
        case AI_IDLE:
            return "AI-IDLE";
        default:
            return "NO SUCH AI STATUS ENUM";
    }
}

std::string AIBehaviour::getCurrentStateString() const {
    return getStateString(stato);
}

void AIBehaviour::setCanThink(bool b) {
    canThink = b;
}

bool AIBehaviour::isCanThink() const {
    return canThink;
}

//functions
void AIBehaviour::update(const float &dt) {
    float MAXFollowRange = 200.f;
    float MAXRange = 450.f;
    float idleChance = 50.f;
    int MAXdistance = 300;
    updateKeyTime(dt);

    if(!noclip){
        if ((abs(enemy.getCollisionBoxCenter().x - spawnPos.x) > MAXRange ||
             abs(enemy.getCollisionBoxCenter().y - spawnPos.y) > MAXRange) || stato == AI_BACKTOSPAWN) {
            statoP = stato;
            stato = AI_BACKTOSPAWN;
        } else if (enemy.isPlayerInView()) {
            if(abs(enemy.getCollisionBoxCenter().x - player.getCollisionBoxCenter().x) <= MAXFollowRange &&
               abs(enemy.getCollisionBoxCenter().y - player.getCollisionBoxCenter().y) <= MAXFollowRange){
                statoP = stato;
                stato = AI_FOLLOW;
            }
        }
    }
    if(enemy.getMovementComponent()->getVelocity() == sf::Vector2f()){
        stuckTime += dt;
        if(stuckTime >= stuckTimeMax){
            stuckTime = 0.f;
            goto forceback;
        }
    }

    switch (stato) {
        case AI_PATROL: {
            if (enemy.isWayPointEmpty() && statoP == AI_PATROL) {
                statoP = stato;
                stato = AI_DEFAULT;
                break;
            }
            bool validTargetPos = false;
            while (!validTargetPos && enemy.isWayPointEmpty()) {
                auto distanceX = (float)utils::generateRandomNumber(-MAXdistance, MAXdistance);
                auto distanceY = (float)utils::generateRandomNumber(-MAXdistance, MAXdistance);
                sf::Vector2f targetPos = {spawnPos.x + distanceX, spawnPos.y + distanceY};
                int node_x = (int) (targetPos.x / (Tile::TILE_SIZE / (float) pathFinder->nodeMultiplier));
                int node_y = (int) (targetPos.y / (Tile::TILE_SIZE / (float) pathFinder->nodeMultiplier));
                if (node_y < pathFinder->nodes.size() && node_x < pathFinder->nodes[0].size()) {
                    if (pathFinder->nodes[node_y][node_x]->isWalkable()) {
                        if (pathFinder->FindPath(enemy.getCollisionBoxCenter(), targetPos, 300)) {
                            updateWayPoints();
                            enemy.getMovementComponent()->setMaxVelocity(100);
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
            if (idleTime >= idleTimeMax) {
                idleTime = 0;
                statoP = stato;
                stato = AI_DEFAULT;
            } else {
                idleTime += dt;
            }
            break;
        }
        case AI_FOLLOW: {
            if(noclip){
                statoP = stato;
                stato = AI_DEFAULT;
                break;
            }
            chaseTime += dt;
            if(chaseTime > chaseTimeMax){
                chaseTime = 0.f;
                statoP = stato;
                stato = AI_BACKTOSPAWN;
                break;
            }
            if (getKeyTime()) {
                if (pathFinder->FindPath(enemy.getCollisionBoxCenter(),
                                         player.getCollisionBoxCenter(), 300)) {
                    updateWayPoints();
                    enemy.getMovementComponent()->setMaxVelocity(200);
                    statoP = stato;
                    stato = AI_FOLLOW;
                }else{
                    statoP = stato;
                    stato = AI_DEFAULT;
                }
            }
            break;
        }
        case AI_BACKTOSPAWN: {
            if (enemy.isWayPointEmpty() && (statoP == AI_BACKTOSPAWN)) {
                statoP = stato;
                stato = AI_DEFAULT;
            } else if (statoP != AI_BACKTOSPAWN && !enemy.isWayPointEmpty()) {
                forceback:
                if (pathFinder->FindPath(enemy.getCollisionBoxCenter(), spawnPos, 9999)) {
                    updateWayPoints();
                    statoP = stato;
                    stato = AI_BACKTOSPAWN;
                }
            }
            break;
        }
        case AI_DEFAULT: {
            if (utils::trueFalse(idleChance)) {
                statoP = stato;
                stato = AI_IDLE;
                idleTimeMax = utils::generateRandomNumberf(1, 3, 0);
            } else {
                statoP = stato;
                stato = AI_PATROL;
            }
            break;
        }
    }
}

void AIBehaviour::updateKeyTime(const float &dt) {
    if (keyTime < keyTimeMax) {
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
