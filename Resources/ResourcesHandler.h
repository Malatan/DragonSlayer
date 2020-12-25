//
// Created by Administrator on 10/10/2020.
//

#ifndef DRAGONSLAYER_RESOURCESHANDLER_H
#define DRAGONSLAYER_RESOURCESHANDLER_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Resource.h"
#include "../Components/SpellComponent.h"
#include "../Game/Stats.h"
#include "../Game/Inventory.h"
#include "../Game/Utils.h"
#include "../Game/Achievement.h"

class Inventory;
class Resource;

class ResourcesHandler {
public:
    ResourcesHandler();
    virtual ~ResourcesHandler();

    //id
    unsigned int generateId();

    void setEquipSlotsTextureIntRect(int equip_slot, sf::IntRect intRect);
    sf::IntRect getEquipSlotTextureRect(int equip_slot);
    bool addResource(const std::string& path, const std::string& key, const std::string& state_name);
    std::shared_ptr<Resource> getResourceByKey(const std::string& key);

    static void loadPlayerStatsTxt(const std::shared_ptr<Stats>& playerStats);
    void loadPlayerInventoryTxt(const std::shared_ptr<Inventory>& playerInventory);
    static void loadSpellList(const std::shared_ptr<SpellComponent>& spellComponent);
    void loadMaterialsTxt(std::vector<std::unique_ptr<Item>>& material_list);
    void loadAchievementsTxt(std::vector<std::shared_ptr<Achievement>>& achievement_list);

    std::string toString();

private:
    unsigned int IdCounter;

    std::vector<std::shared_ptr<Resource>> resources;
    sf::IntRect equipSlotsTextureIntRects[6];
};


#endif //DRAGONSLAYER_RESOURCESHANDLER_H
