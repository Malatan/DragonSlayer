#ifndef DRAGONSLAYER_BATTLEAI_H
#define DRAGONSLAYER_BATTLEAI_H

#include <string>
#include <sstream>
#include <cmath>

#include "../Core/BattleState.h"

class BattleAI {
public:
    //constructor/destructor
    BattleAI(std::shared_ptr<Enemy> currentEnemy, std::shared_ptr<Player> player);

    //functions
    int behaviour();

private:
    std::shared_ptr<Enemy> currentEnemy;
    std::shared_ptr<Player> player;

};


#endif //DRAGONSLAYER_BATTLEAI_H
