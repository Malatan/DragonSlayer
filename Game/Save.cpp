//
// Created by Zheng on 25/12/2020.
//

#include "Save.h"

//constructors/destructor
Save::Save() = default;

Save::Save(std::string name, std::string modified_time, std::string game_version)
        : name(std::move(name)), lastModifiedTime(std::move(modified_time)), gameVersion(std::move(game_version)){

}

Save::~Save() = default;

//accessors/modifiers
std::string Save::getName() const {
    return name;
}

std::string Save::getLastModifiedTime() const {
    return lastModifiedTime;
}

//functions
void Save::saveRsHandlerInfo(const shared_ptr<ResourcesHandler> &rshandler_info) {
    rsHandlerIdCounter = rshandler_info->getIdCunter();
}

void Save::savePlayerInfo(const std::shared_ptr<Player>& player_info) {
    playerPos = player_info->getPosition();
    playerStats = *player_info->getPlayerStats();
    playerInventoryMaxSpace = player_info->getInventory()->getCurrentMaxSpace();
    inventory.clear();
    for(const auto& i : player_info->getInventory()->getItems()){
        inventory.emplace_back(i.get());
    }
    playerGold = player_info->getGold();

    equips.clear();
    player_equip_slot equip_enums[6] = {LEGS_SLOT, ARMS_SLOT, CHEST_SLOT, HEAD_SLOT, SHIELD_SLOT, WEAPON_SLOT};
    for(auto i : equip_enums){
        std::shared_ptr<Item> equip = player_info->getEquippedItem(i);
        if(equip){
            equips.insert(std::pair<player_equip_slot, unsigned int>(i, equip->getId()));
        }else{
            equips.insert(std::pair<player_equip_slot, unsigned int>(i, 0));
        }
    }
}

void Save::saveSpellsInfo(const shared_ptr<SpellComponent> &spell_component) {
    spells.clear();
    for(const auto& i : spell_component->getSpells()){
        spells.push_back(*i);
    }
    playerSpells.clear();
    for(const auto& i : spell_component->getPlayerSpells()){
        playerSpells.push_back(*i);
    }
}

void Save::saveAchievementsInfo(const std::shared_ptr<AchievementComponent> &achievement_component) {
    aeRecords.clear();
    achievements.clear();

    aeRecords = achievement_component->getRecords();
    for(const auto& i : achievement_component->getAchievements()){
        achievements.push_back(*i);
    }
}

void Save::saveBuffsInfo(const shared_ptr<BuffComponent> &buff_component) {
    playerBuffs.clear();
    playerBuffs.reserve(buff_component->getPlayerBuffsList().size());
    for(const auto& i : buff_component->getPlayerBuffsList()){
        playerBuffs.push_back(*i);
    }
}

std::string Save::toString() const {
    std::stringstream ss;
    ss << "Name:[" << name << "] Time:[" << lastModifiedTime << "]" << " Game version:[" << gameVersion << "]" << std::endl;
    return ss.str();
}


