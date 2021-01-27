#ifndef DRAGONSLAYER_BATTLEAI_H
#define DRAGONSLAYER_BATTLEAI_H

#include <string>
#include <sstream>
#include <cmath>

#include "../Core/BattleState.h"

class BattleAI {
public:
    //constructor/destructor
    BattleAI(std::shared_ptr<Player> player, std::vector<std::shared_ptr<Enemy>> enemies, std::vector<unsigned int> enemiesOrder, unsigned int current, std::shared_ptr<PopUpTextComponent> popUpTextComponent);

    //functions
    int behaviour();

private:
    std::shared_ptr<PopUpTextComponent> popUpTextComponent;
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<unsigned int> enemiesOrder;
    unsigned int current;
};

#endif //DRAGONSLAYER_BATTLEAI_H
