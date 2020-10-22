//
// Created by Administrator on 10/10/2020.
//

#ifndef DRAGONSLAYER_RESOURCESHANDLER_H
#define DRAGONSLAYER_RESOURCESHANDLER_H

#include "Resource.h"
#include "../Game/Stats.h"
#include "../Game/Inventory.h"
#include <SFML/Graphics.hpp>

class ResourcesHandler {
private:
    std::vector<Resource*> resources;
    sf::IntRect equipSlotsTextureIntRects[6];

protected:

public:
    ResourcesHandler();

    virtual ~ResourcesHandler();


    void setEquipSlotsTextureIntRect(int equip_slot, sf::IntRect intRect);
    sf::IntRect getEquipSlotTextureRect(int equip_slot);
    bool checkIfKeyExist(std::string key);
    bool addResouce(std::string path, std::string key, std::string state_name);
    Resource* getResouceByKey(std::string key);

    bool loadPlayerStatsTxt(Stats* playerStats);
    bool loadPlayerInventoryTxt(Inventory* playerInventory);
    std::string toString();
};


#endif //DRAGONSLAYER_RESOURCESHANDLER_H
