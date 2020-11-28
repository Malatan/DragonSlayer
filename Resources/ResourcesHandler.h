//
// Created by Administrator on 10/10/2020.
//

#ifndef DRAGONSLAYER_RESOURCESHANDLER_H
#define DRAGONSLAYER_RESOURCESHANDLER_H

#include "Resource.h"
#include "../Game/Stats.h"
#include "../Game/Inventory.h"
#include "../Components/SpellComponent.h"
#include <SFML/Graphics.hpp>
#include <memory>

class ResourcesHandler {
public:
    ResourcesHandler();

    virtual ~ResourcesHandler();


    void setEquipSlotsTextureIntRect(int equip_slot, sf::IntRect intRect);
    sf::IntRect getEquipSlotTextureRect(int equip_slot);
    bool checkIfKeyExist(const std::string& key);
    bool addResouce(std::string path, const std::string& key, std::string state_name);
    std::shared_ptr<Resource> getResouceByKey(const std::string& key);

    bool loadPlayerStatsTxt(const std::shared_ptr<Stats>& playerStats);
    bool loadPlayerInventoryTxt(const std::shared_ptr<Inventory>& playerInventory);
    bool loadSpellList(const std::shared_ptr<SpellComponent>& spellComponent);
    std::string toString();

private:
    std::vector<std::shared_ptr<Resource>> resources;
    sf::IntRect equipSlotsTextureIntRects[6];
};


#endif //DRAGONSLAYER_RESOURCESHANDLER_H
