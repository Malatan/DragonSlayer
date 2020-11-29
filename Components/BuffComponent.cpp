//
// Created by Zheng on 16/10/2020.
//

#include "BuffComponent.h"

#include <utility>

BuffComponent::BuffComponent(std::shared_ptr<PopUpTextComponent> popUpTextComponent, State *state, sf::Font* font) {
    this->popUpTextComponent = std::move(popUpTextComponent);
    this->font = font;
    gState = dynamic_cast<GameState *>(state);
}

BuffComponent::~BuffComponent() = default;

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
    // fa la copia del buff passato dalla lista buff
    std::shared_ptr<Buff> new_buff = std::make_shared<Buff>(buff.get());

    // controlla se il buff stesso oppure uno dello stesso tipo e' gia stato applicato
    bool override_buff = false;
    for(auto &i : buffBar){
        if(i->getBuff()->getKeyWord() == new_buff->getKeyWord()){
            //aggiorna il player buff list
            for(auto & j : playerBuffsList){
                if(j->getName() == i->getBuff()->getName()){
                    j = new_buff;
                    break;
                }
            }
            //aggiorna il buff del buffslot
            i->setBuff(new_buff, true);

            override_buff = true;
            break;
        }
    }
    if(!override_buff){
        playerBuffsList.push_back(new_buff);
        updateBuffBar();
    }
    std::cout<<toStringPlayerBuffs();
}

std::string BuffComponent::toStringBuffs() const{
    std::stringstream ss;
    ss << "--------------------Buff list--------------------" << std::endl;
    for(const auto& i : buffs){
        ss << i.second->toString();
    }

    return ss.str();
}

std::string BuffComponent::toStringPlayerBuffs() const {
    std::stringstream ss;
    ss << "--------------------Player Buff list--------------------" << std::endl;
    for(const auto& i : playerBuffsList){
        ss << i->toString();
    }

    return ss.str();
}

void BuffComponent::updateBuffBar() {
    buffBar.clear();
    float slot_size = 30.f;
    int max_slot_per_row = 5;
    int row_count = 0;
    int column_count = 0;
    float start_x = 314.f;
    float start_y = 1.f;

    for(unsigned int i = 0 ; i < playerBuffsList.size() ; i++){
        buffBar.push_back(std::make_unique<gui::BuffSlot>(start_x + (column_count * slot_size), start_y + (row_count * slot_size),
                slot_size, slot_size,
                playerBuffsList[i], gState->getTextures().at("ITEMS_SHEET"), font));
        column_count ++;
        if((i % max_slot_per_row) == (max_slot_per_row - 1)){
            row_count ++;
            column_count = 0;
        }
    }
}

void BuffComponent::updatePlayerBuffList() {
    std::vector<unsigned int> remove_indexs;
    for(unsigned int i = 0 ; i < playerBuffsList.size() ; i++){
        playerBuffsList[i]->updateLifeTime();
        if(playerBuffsList[i]->getTurns() == 0)
            remove_indexs.push_back(i);
    }

    if(!remove_indexs.empty()){
        for(auto i : remove_indexs){
            playerBuffsList[i] = playerBuffsList.back();
            playerBuffsList.pop_back();
        }
        updateBuffBar();
    }
}

void BuffComponent::update(const float& dt, const sf::Vector2f& mousePos) {
    for (auto it = buffBar.rbegin(); it != buffBar.rend(); ++it) {
        (*it)->update(mousePos);
    }
}

void BuffComponent::render(sf::RenderTarget& target) {
    for (auto it = buffBar.rbegin(); it != buffBar.rend(); ++it) {
        (*it)->render(target);
    }
}







