//
// Created by Zheng on 16/10/2020.
//

#include "BuffComponent.h"

BuffComponent::BuffComponent(std::shared_ptr<PopUpTextComponent> popUpTextComponent) {
    this->popUpTextComponent = popUpTextComponent;
}

BuffComponent::~BuffComponent() {
    for(auto b : buffs){
        delete b.second;
    }
}

void BuffComponent::applyItemBuff(std::string key, Stats *stats) {
    Buff* buff = this->buffs[key];
    if(buff->isInstant()){
        if(buff->getAddHp() != 0){
            int amount = stats->gainHp(buff->getAddHp());
            popUpTextComponent->addPopUpTextCenter(HEAL_TAG, amount, "+", "Hp");
        }

        if(buff->getAddMp() != 0){
            int amount = stats->gainMp(buff->getAddMp());
            popUpTextComponent->addPopUpTextCenter(MANA_RESTORE_TAG, amount, "+", "Mp");
        }

    }
    else{ // if not instant then add to list
        this->addPlayerBuff(buff);
    }
}

void BuffComponent::addBuff(std::string key, Buff *buff) {
    buffs.insert(std::pair<std::string, Buff*>(key, buff));
}

void BuffComponent::addPlayerBuff(Buff *buff) {
    playerBuffsList.push_back(buff);
}

std::string BuffComponent::toStringBuffs() {
    std::stringstream ss;
    for(auto i : buffs){
        ss << i.second->toString();
    }

    return ss.str();
}

void BuffComponent::update() {
/*    for(auto b : this->playerBuffsList){
     // update buffs here
    }*/
}



