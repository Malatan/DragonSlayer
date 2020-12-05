//
// Created by Administrator on 03/12/2020.
//

#ifndef DRAGONSLAYER_LOOTGENERATOR_H
#define DRAGONSLAYER_LOOTGENERATOR_H

#include <iostream>
#include <vector>
#include "Item.h"
#include "ResourcesHandler.h"
#include "Enemy.h"

enum loot_type{
    MATERIAL_LOOT,
    COMSUMABLE_LOOT,
    WEAPON_LOOT,
    SHIELD_LOOT,
    HELMET_LOOT,
    CHESTPLATE_LOOT,
    GLOVES_LOOT,
    BOOTS_LOOT,
    NO_LOOT
};

enum loot_rarity{
    UNCOMMON_LOOT,
    COMMON_LOOT,
    RARE_LOOT,
    EPIC_LOOT,
    LEGENDARY_LOOT
};


class LootGenerator {
public:
    LootGenerator(std::shared_ptr<ResourcesHandler> rs_handler);
    virtual ~LootGenerator();

    void generateLoot(int floor);

    const vector<std::unique_ptr<Item>> &getDroppableMaterials() const;
    const map<std::string, Item> &getConsumablesList() const;

    std::string toStringMaterials();
private:
    static const int MAX_PROBABILITY;
    static const int MAX_RARITY_PROBABILITY;
    static const int lootProbabilities[];
    static const int lootRarityProbabilities1[];
    static const int lootRarityProbabilities2[];
    static const int lootRarityProbabilities3[];
    static const int lootRarityProbabilities4[];
    static const int lootRarityProbabilities5[];
    static const int hpRange[];
    static const int mpRange[];
    static const int damageRange[];
    static const int armorRange[];
    static const float critchanceRange[];
    static const float evadechanceRange[];

    std::shared_ptr<ResourcesHandler> rsHandler;
    std::vector<std::unique_ptr<Item>> droppableMaterials;
    std::map<std::string, Item> consumablesList;

    void initDroppableMaterials();
    void initConsomablesList();
};


#endif //DRAGONSLAYER_LOOTGENERATOR_H
