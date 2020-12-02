//
// Created by Administrator on 10/10/2020.
//

#ifndef DRAGONSLAYER_RESOURCESHANDLER_H
#define DRAGONSLAYER_RESOURCESHANDLER_H

#include "Resource.h"
#include "../Game/Stats.h"
#include "../Game/Inventory.h"
#include "../Components/SpellComponent.h"
#include "../Game/Utils.h"
#include <SFML/Graphics.hpp>
#include <memory>

class ResourcesHandler {
public:
    ResourcesHandler();
    virtual ~ResourcesHandler();

    //id
    unsigned int generateId();

    void setEquipSlotsTextureIntRect(int equip_slot, sf::IntRect intRect);
    sf::IntRect getEquipSlotTextureRect(int equip_slot);
    bool addResource(std::string path, const std::string& key, std::string state_name);
    std::shared_ptr<Resource> getResourceByKey(const std::string& key);

    static bool loadPlayerStatsTxt(const std::shared_ptr<Stats>& playerStats);
    bool loadPlayerInventoryTxt(const std::shared_ptr<Inventory>& playerInventory);
    static bool loadSpellList(const std::shared_ptr<SpellComponent>& spellComponent);
    std::string toString();

private:
    unsigned int IdCounter;

    std::vector<std::shared_ptr<Resource>> resources;
    sf::IntRect equipSlotsTextureIntRects[6];
};


#endif //DRAGONSLAYER_RESOURCESHANDLER_H
