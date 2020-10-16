//
// Created by Zheng on 16/10/2020.
//

#ifndef DRAGONSLAYER_BUFFCOMPONENT_H
#define DRAGONSLAYER_BUFFCOMPONENT_H

#include <iostream>
#include <map>
#include <vector>
#include "../Game/Stats.h"
#include "../Game/Buff.h"

class BuffComponent {
private:
    std::map<std::string, Buff*> buffs;

    std::vector<Buff*> playerBuffsList;


protected:

public:
    BuffComponent();
    virtual ~BuffComponent();

    void addBuff(std::string key, Buff* buff);
    void addPlayerBuff(Buff* buff);
    void applyItemBuff(std::string key, Stats* stats);
    void update();

    std::string toStringBuffs();
};


#endif //DRAGONSLAYER_BUFFCOMPONENT_H
