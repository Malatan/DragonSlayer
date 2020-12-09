//
// Created by Zheng on 03/12/2020.
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

enum equip_effect{
    ADD_HP,
    ADD_MP,
    ADD_DAMAGE,
    ADD_ARMOR,
    ADD_CRITCHANCE,
    ADD_EVADECHANCE
};

typedef std::pair<int, int> pairInt;
typedef std::pair<float, float> pairFloat;
typedef std::pair<int, enemy_types> dropCount;

class LootGenerator {
public:
    explicit LootGenerator(std::shared_ptr<ResourcesHandler> rs_handler);
    virtual ~LootGenerator();

    std::vector<std::shared_ptr<Item>> generateLoot(const std::shared_ptr<Enemy>& defeated_enemy, int floor);
    std::shared_ptr<Item> generateTierEquipment(item_rarity equip_rarity, bool random_rarity);
    Item *getMaterialByEnemyType(enemy_types type);
    static std::string getRarityString(item_rarity rarity_enum);
    static std::string getRarityString(loot_rarity rarity_enum);

    const vector<std::unique_ptr<Item>> &getDroppableMaterials() const;
    const map<std::string, Item> &getShopList() const;

    std::string toStringMaterials();
private:
    static const int MAX_PROBABILITY;
    static const int MAX_RARITY_PROBABILITY;
    static const int MAX_POTION_RARITY_PROBABILITY;
    static const int MAX_POTION_AMOUNT_PROBABILITY;
    static const int MAX_MATERIAL_RARITY_PROBABILITY;
    static const int MAX_MATERIAL_AMOUNT_PROBABILITY;

    static const int lootProbabilities[];
    static const int lootRarityProbabilities1[];
    static const int lootRarityProbabilities2[];
    static const int lootRarityProbabilities3[];
    static const int lootRarityProbabilities4[];
    static const int lootRarityProbabilities5[];

    static const int materialRarityProbabilities[];
    static const int materialAmountProbabilities[];

    static const int potionAmountProbabilities[];
    static const int potionRarityProbabilities[];

    static const pairInt swordIconIntRects[];
    static const pairInt axeIconIntRects[];
    static const pairInt bowIconIntRects[];
    static const pairInt shieldIconIntRects[];
    static const pairInt helmetIconIntRects[];
    static const pairInt chestIntRects[];
    static const pairInt glovesIntRects[];
    static const pairInt bootsIntRects[];

    static const pairInt statsAmount[];
    static const pairInt hpRange[];
    static const pairInt mpRange[];
    static const pairInt damageRange[];
    static const pairInt armorRange[];
    static const pairInt shieldArmorRange[];
    static const pairFloat critchanceRange[];
    static const pairFloat evadechanceRange[];


    std::shared_ptr<ResourcesHandler> rsHandler;
    std::vector<std::unique_ptr<Item>> droppableMaterials;
    std::map<std::string, Item> shopList;
    std::vector<std::string> droppableConsumablesList;

    void initDroppableMaterials();
    void initShopList();
    void initDroppableConsumablesList();
};


#endif //DRAGONSLAYER_LOOTGENERATOR_H
