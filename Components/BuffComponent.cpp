//
// Created by Zheng on 16/10/2020.
//

#include "BuffComponent.h"

BuffComponent::BuffComponent() {

}

BuffComponent::~BuffComponent() {
    for(auto b : this->buffs){
        delete b.second;
    }
}

void BuffComponent::applyItemBuff(std::string key, Stats *stats) {
    Buff* buff = this->buffs[key];
    if(buff->isInstant()){
        std::cout<<stats->gainHp(buff->getAddHp());
        std::cout<<"\n";
        std::cout<<stats->gainMp(buff->getAddMp());
        std::cout<<"\n";
    }
    else{ // if not instant then add to list
        this->addPlayerBuff(buff);
    }
}

void BuffComponent::addBuff(std::string key, Buff *buff) {
    this->buffs.insert(std::pair<std::string, Buff*>(key, buff));
}

void BuffComponent::addPlayerBuff(Buff *buff) {
    this->playerBuffsList.push_back(buff);
}

std::string BuffComponent::toStringBuffs() {
    std::stringstream ss;
    for(auto i : this->buffs){
        ss << i.second->toString();
    }

    return ss.str();
}

void BuffComponent::update() {
/*    for(auto b : this->playerBuffsList){
     // update buffs here
    }*/
}



