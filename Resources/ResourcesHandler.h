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

    std::string getGameVersion() const;
    void setUnitTesting(bool b);
    bool isUnitTesting() const;

    //id
    unsigned int generateId();
    void setIdCounter(unsigned int value);
    unsigned int getIdCunter() const;

    void setEquipSlotsTextureIntRect(int equip_slot, sf::IntRect intRect);
    sf::IntRect getEquipSlotTextureRect(int equip_slot);
    bool addResource(const std::string& path, const std::string& key, const std::string& state_name);
    std::shared_ptr<Resource> getResourceByKey(const std::string& key);

    void loadPlayerStatsTxt(const std::shared_ptr<Stats>& playerStats) const;
    void loadPlayerInventoryTxt(const std::shared_ptr<Inventory>& playerInventory);
    void loadSpellList(const std::shared_ptr<SpellComponent>& spellComponent) const;
    void loadMaterialsTxt(std::vector<std::unique_ptr<Item>>& material_list);
    void loadAchievementsTxt(std::vector<std::shared_ptr<Achievement>>& achievement_list) const;

    std::string toString();

private:
    bool unitTesting{};
    unsigned int IdCounter;
    std::string gameVersion;

    std::vector<std::shared_ptr<Resource>> resources;
    sf::IntRect equipSlotsTextureIntRects[6];
};


#endif //DRAGONSLAYER_RESOURCESHANDLER_H
