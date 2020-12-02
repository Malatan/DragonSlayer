//
// Created by Zheng on 16/10/2020.
//

#include "BuffComponent.h"

BuffComponent::BuffComponent(std::shared_ptr<PopUpTextComponent> popUpTextComponent, std::shared_ptr<Player> player,
        State *state, sf::Font* font) {
    this->player = std::move(player);
    this->popUpTextComponent = std::move(popUpTextComponent);
    this->font = font;
    gState = dynamic_cast<GameState *>(state);
}

BuffComponent::~BuffComponent() = default;

void BuffComponent::applyItemBuff(const std::string& key, bool popup_text_center, float popup_text_x, float popup_text_y) {
    TextTypes tag_type = DEFAULT_TAG;
    stringstream text;

    if(buffs[key]->isInstant()){
        if(buffs[key]->getAddHp() != 0){
            int amount = player->getPlayerStats()->gainHp(buffs[key]->getAddHp());
            tag_type = HEAL_TAG;
            text << "+" << amount << " Hp";
        }

        if(buffs[key]->getAddMp() != 0){
            int amount = player->getPlayerStats()->gainMp(buffs[key]->getAddMp());
            tag_type = MANA_RESTORE_TAG;
            if(text.rdbuf()->in_avail() != 0){
                text << std::endl;
            }
            text << "+" << amount << " Mp";
        }
    }
    else{ // if not instant then add to list
        if(!addPlayerBuff(buffs[key])){
            if(buffs[key]->getAddDamage() != 0){
                int new_damage = player->getPlayerStats()->getDamage() + buffs[key]->getAddDamage();
                player->getPlayerStats()->setDamage(new_damage);
                tag_type = DEFAULT_TAG;
                text << "+" << buffs[key]->getAddDamage() << " Damage";
            }

            if(buffs[key]->getAddArmor() != 0){
                int new_armor = player->getPlayerStats()->getArmor() + buffs[key]->getAddArmor();
                player->getPlayerStats()->setArmor(new_armor);
                tag_type = DEFAULT_TAG;
                if(text.rdbuf()->in_avail() != 0){
                    text << std::endl;
                }
                text << "+" << buffs[key]->getAddArmor() << " Armor";
            }

            if(buffs[key]->getAddCritChance() != 0){
                float new_critchance = player->getPlayerStats()->getCritChance() + buffs[key]->getAddCritChance();
                player->getPlayerStats()->setCritChance(new_critchance);
                tag_type = DEFAULT_TAG;
                if(text.rdbuf()->in_avail() != 0){
                    text << std::endl;
                }
                text << "+" << buffs[key]->getAddCritChance() << "% Critical chance";
            }

            if(buffs[key]->getAddEvadeChance() != 0){
                float new_evade = player->getPlayerStats()->getEvadeChance() + buffs[key]->getAddEvadeChance();
                player->getPlayerStats()->setEvadeChance(new_evade);
                tag_type = DEFAULT_TAG;
                if(text.rdbuf()->in_avail() != 0){
                    text << std::endl;
                }
                text << "+" << buffs[key]->getAddEvadeChance() << "% Evade chance";
            }
        }
    }

    if(popup_text_center)
        popUpTextComponent->addPopUpTextCenter(tag_type, text.str(), "", "");
    else{
        popUpTextComponent->addPopUpText(tag_type,
                                         popup_text_x,
                                         popup_text_y,
                                         text.str(), "", "");
    }
}

void BuffComponent::expireItemBuff(const std::shared_ptr<Buff>& expired_buff) {
    if(!expired_buff->isInstant()){
        if(expired_buff->getAddHp() != 0){
            int new_hp = player->getPlayerStats()->getHp() - expired_buff->getAddHp();
            player->getPlayerStats()->setHp(new_hp);
        }
        if(expired_buff->getAddMp() != 0){
            int new_mp = player->getPlayerStats()->getMp() - expired_buff->getAddMp();
            player->getPlayerStats()->setMp(new_mp);
        }
        if(expired_buff->getAddDamage() != 0){
            int new_damage = player->getPlayerStats()->getDamage() - expired_buff->getAddDamage();
            player->getPlayerStats()->setDamage(new_damage);
        }
        if(expired_buff->getAddArmor() != 0){
            int new_armor = player->getPlayerStats()->getArmor() - expired_buff->getAddArmor();
            player->getPlayerStats()->setArmor(new_armor);
        }
        if(expired_buff->getAddCritChance() != 0.f){
            float new_critchance = player->getPlayerStats()->getCritChance() - expired_buff->getAddCritChance();
            player->getPlayerStats()->setCritChance(new_critchance);
        }
        if(expired_buff->getAddEvadeChance() != 0.f){
            float new_evadechance = player->getPlayerStats()->getEvadeChance() - expired_buff->getAddEvadeChance();
            player->getPlayerStats()->setEvadeChance(new_evadechance);
        }
    }
}

void BuffComponent::addBuff(const std::string& key, const std::shared_ptr<Buff>& buff) {
    buffs.insert(std::pair<std::string, std::shared_ptr<Buff>>(key, buff));
}

bool BuffComponent::addPlayerBuff(const std::shared_ptr<Buff>& buff) {
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
    return override_buff;
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
        buffBar.push_back(std::make_unique<gui::BuffSlot>(
                start_x + ((float)column_count * slot_size),
                start_y + ((float)row_count * slot_size),
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
    //il vettore salave gli indici dei buff che sono scaduti
    std::vector<unsigned int> remove_indexs;
    for(unsigned int i = 0 ; i < playerBuffsList.size() ; i++){
        playerBuffsList[i]->updateLifeTime();
        if(playerBuffsList[i]->getTurns() == 0)
            remove_indexs.push_back(i);
    }

    //rimuovi i buff scaduti dalla lista e aggiorna il buff bar
    if(!remove_indexs.empty()){
        for(auto i : remove_indexs){
            expireItemBuff(playerBuffsList[i]);
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









