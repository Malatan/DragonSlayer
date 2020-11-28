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

    void addBuff(const std::string& key, const std::shared_ptr<Buff>& buff);
    void addPlayerBuff(const std::shared_ptr<Buff>& buff);
    void applyItemBuff(const std::string& key, const std::shared_ptr<Stats>& stats, bool popup_text_center, float popup_text_x = 0.f,
            float popup_text_y = 0.f);
    void update();

    std::string toStringBuffs();

private:
    std::shared_ptr<PopUpTextComponent> popUpTextComponent;
    std::map<std::string, std::shared_ptr<Buff>> buffs;
    std::vector<std::shared_ptr<Buff>> playerBuffsList;
};


#endif //DRAGONSLAYER_BUFFCOMPONENT_H
