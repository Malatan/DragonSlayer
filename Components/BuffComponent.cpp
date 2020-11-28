//
// Created by Zheng on 16/10/2020.
//

#include "BuffComponent.h"

#include <utility>

BuffComponent::BuffComponent(std::shared_ptr<PopUpTextComponent> popUpTextComponent) {
    this->popUpTextComponent = std::move(popUpTextComponent);
}

BuffComponent::~BuffComponent() {

}

void BuffComponent::applyItemBuff(const std::string& key, const std::shared_ptr<Stats>& stats, bool popup_text_center,
        float popup_text_x, float popup_text_y) {
    std::shared_ptr<Buff> buff = buffs[key];
    if(buff->isInstant()){
        TextTypes tag_type = DEFAULT_TAG;
        std::string text;
        std::string prefix;
        std::string postfix;
        if(buff->getAddHp() != 0){
            int amount = stats->gainHp(buff->getAddHp());
            tag_type = HEAL_TAG;
            text = to_string(amount);
            prefix = "+";
            postfix = "Hp";
        }

        if(buff->getAddMp() != 0){
            int amount = stats->gainMp(buff->getAddMp());
            tag_type = MANA_RESTORE_TAG;
            text = to_string(amount);
            prefix = "+";
            postfix = "Mp";
        }

        if(popup_text_center)
            popUpTextComponent->addPopUpTextCenter(tag_type, text, prefix, postfix);
        else{
            popUpTextComponent->addPopUpText(tag_type,
                                             popup_text_x,
                                             popup_text_y,
                                             text, prefix, postfix);
        }
    }
    else{ // if not instant then add to list
        addPlayerBuff(buff);
    }
}

void BuffComponent::addBuff(const std::string& key, const std::shared_ptr<Buff>& buff) {
    buffs.insert(std::pair<std::string, std::shared_ptr<Buff>>(key, buff));
}

void BuffComponent::addPlayerBuff(const std::shared_ptr<Buff>& buff) {
    playerBuffsList.push_back(buff);
}

std::string BuffComponent::toStringBuffs() {
    std::stringstream ss;
    for(const auto& i : buffs){
        ss << i.second->toString();
    }

    return ss.str();
}

void BuffComponent::update() {
/*    for(auto b : this->playerBuffsList){
     // update buffs here
    }*/
}



