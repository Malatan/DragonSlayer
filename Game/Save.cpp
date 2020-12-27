//
// Created by Zheng on 25/12/2020.
//

#include "Save.h"

#include <utility>

Save::Save() = default;

Save::Save(std::string name, std::string modified_time, std::string game_version)
        : name(std::move(name)), lastModifiedTime(std::move(modified_time)), gameVersion(std::move(game_version)){

}

Save::~Save() = default;

void Save::saveRsHandlerInfo(const shared_ptr<ResourcesHandler> &rshandler_info) {
    rsHandlerIdCounter = rshandler_info->getIdCunter();
}

void Save::savePlayerInfo(const std::shared_ptr<Player>& player_info) {
    playerPos = player_info->getPosition();
    playerStats = *player_info->getPlayerStats();
    playerInventoryMaxSpace = player_info->getInventory()->getCurrentMaxSpace();
    for(const auto& i : player_info->getInventory()->getItems()){
        inventory.emplace_back(i.get());
    }
    playerGold = player_info->getGold();

    std::shared_ptr<Item> equip = player_info->getEquippedItem(5);
    if(equip)
        playerWeapon = Item(equip.get());
    equip = player_info->getEquippedItem(4);
    if(equip)
        playerShield = Item(equip.get());
    equip = player_info->getEquippedItem(3);
    if(equip)
        playerHead = Item(equip.get());
    equip = player_info->getEquippedItem(2);
    if(equip)
        playerChest = Item(equip.get());
    equip = player_info->getEquippedItem(1);
    if(equip)
        playerArms = Item(equip.get());
    equip = player_info->getEquippedItem(0);
    if(equip)
        playerLegs = Item(equip.get());
}

std::string Save::toString() const {
    std::stringstream ss;
    ss << "Name:[" << name << "] Time:[" << lastModifiedTime << "]" << std::endl;
    return ss.str();
}


