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
#include "PopUpTextComponent.h"
#include <memory>

class BuffComponent {
public:
    BuffComponent(std::shared_ptr<PopUpTextComponent> popUpTextComponent);
    virtual ~BuffComponent();

    void addBuff(std::string key, Buff* buff);
    void addPlayerBuff(Buff* buff);
    void applyItemBuff(std::string key, Stats* stats);
    void update();

    std::string toStringBuffs();

private:
    std::shared_ptr<PopUpTextComponent> popUpTextComponent;
    std::map<std::string, Buff*> buffs;
    std::vector<Buff*> playerBuffsList;
};


#endif //DRAGONSLAYER_BUFFCOMPONENT_H
