//
// Created by Leonardo on 09/11/2020.
//

#ifndef DRAGONSLAYER_BATTLESTATE_H
#define DRAGONSLAYER_BATTLESTATE_H
#include <string>
#include <sstream>
#include "Item.h"
#include "Inventory.h"
#include "Stats.h"
#include "Player.h"
#include "iostream"
#include "fstream"
#include "Spell.h"
#include "Enemy.h"
#include "Generator.h"


class BattleState {

    const static int MAX_ENEMIES = 5;
    Player* player;
    int floor;              //castle FLOOR - affects droprate
    int killCounter = 0;    //CONT killed enemies
    int enemyCount;         //NUMBER of total enemies
    Enemy enemies[MAX_ENEMIES];
    Item drops[MAX_ENEMIES];

public:

    bool battle();      //TRUE if player WIN
    bool playerTurn();  //TRUE depends on CheckWin()
    bool enemyTurn(int enemyIndex);   //TRUE if player DIES
    bool checkWin();    //TRUE if all enemies are DEAD
    void dropItem(int enemyIndex);

    BattleState(Player* player, Enemy* enemies, int enemyCount, int floor);
};


#endif //DRAGONSLAYER_BATTLESTATE_H
