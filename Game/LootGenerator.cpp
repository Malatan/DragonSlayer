//
// Created by Administrator on 03/12/2020.
//

#include "LootGenerator.h"

const int LootGenerator::MAX_PROBABILITY = 210;
const int LootGenerator::MAX_RARITY_PROBABILITY = 120;
const int LootGenerator::lootProbabilities[] = {60, 90, 105, 120, 135, 150, 165, 180, MAX_PROBABILITY};
const int LootGenerator::lootRarityProbabilities1[] = {60, 92, 108, 116, MAX_RARITY_PROBABILITY};
const int LootGenerator::lootRarityProbabilities2[] = {54, 87, 105, 115, MAX_RARITY_PROBABILITY};
const int LootGenerator::lootRarityProbabilities3[] = {48, 82, 102, 114, MAX_RARITY_PROBABILITY};
const int LootGenerator::lootRarityProbabilities4[] = {43, 77, 99, 113, MAX_RARITY_PROBABILITY};
const int LootGenerator::lootRarityProbabilities5[] = {36, 71, 95, 111, MAX_RARITY_PROBABILITY};
//Uncommon: 1-50, Common: 75-175, Rare: 200-350, Legendary: 375-600
const int LootGenerator::hpRange[] = {1, 50,   75, 175,   200, 350,   375, 600};
const int LootGenerator::mpRange[] = {1, 50,   75, 175,   200, 350, 375, 600};
const int LootGenerator::damageRange[] = {1, 20,   40, 80,   100, 150,   225, 350};
const int LootGenerator::armorRange[] = {1, 10,   15, 30,   45, 75,   90, 120};
const float LootGenerator::critchanceRange[] = {1, 50,   75, 175,   200, 350,   375, 600};
const float LootGenerator::evadechanceRange[] = {1, 50,   75, 175,   200, 350,   375, 600};

void LootGenerator::initDroppableMaterials() {
    rsHandler->loadMaterialsTxt(droppableMaterials);
}

void LootGenerator::initConsomablesList() {
    consumablesList["HealthPotion(S)"] = Item("C-potionS", "HealthPotion(S)", "Restore 100 hp",
                                        50, UNCOMMON, 0, 3,
                                        0, 0, 0, 0, 0.f, 0.f,
                                        1, true, rsHandler->generateId());
    consumablesList["HealthPotion(M)"] = Item("C-potionM", "HealthPotion(M)", "Restore 200 hp",
                                        100, COMMON, 7, 2,
                                        0, 0, 0, 0, 0.f, 0.f,
                                        1, true, rsHandler->generateId());
    consumablesList["HealthPotion(L)"] = Item("C-potionL", "HealthPotion(L)", "Restore 400 hp",
                                        200, RARE, 7, 3,
                                        0, 0, 0, 0, 0.f, 0.f,
                                        1, true, rsHandler->generateId());
    consumablesList["ManaPotion(S)"] = Item("C-potionS", "ManaPotion(S)", "Restore 100 mp",
                                      50, UNCOMMON, 3, 3,
                                      0, 0, 0, 0, 0.f, 0.f,
                                      1, true, rsHandler->generateId());
    consumablesList["ManaPotion(M)"] = Item("C-potionM", "ManaPotion(M)", "Restore 200 mp",
                                      100, COMMON, 10, 2,
                                      0, 0, 0, 0, 0.f, 0.f,
                                      1, true, rsHandler->generateId());
    consumablesList["ManaPotion(L)"] = Item("C-potionL", "ManaPotion(L)", "Restore 400 mp",
                                      200, RARE, 10, 3,
                                      0, 0, 0, 0, 0.f, 0.f,
                                      1, true, rsHandler->generateId());

    consumablesList["DamagePotion(S)"] = Item("C-potionS", "DamagePotion(S)", "Boosts your attack by 100 for 3 turns",
                                            100, UNCOMMON, 1, 3,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, true, rsHandler->generateId());
    consumablesList["DamagePotion(M)"] = Item("C-potionM", "DamagePotion(M)", "Boosts your attack by 300 for 3 turns",
                                            200, COMMON, 8, 2,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, true, rsHandler->generateId());
    consumablesList["DamagePotion(L)"] = Item("C-potionL", "DamagePotion(L)", "Boosts your attack by 600 for 3 turns",
                                            400, RARE, 8, 3,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, true, rsHandler->generateId());

    consumablesList["DefensePotion(S)"] = Item("C-potionS", "DefensePotion(S)", "Boosts your armor by 100 for 3 turns",
                                            100, UNCOMMON, 2, 3,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, true, rsHandler->generateId());
    consumablesList["DefensePotion(M)"] = Item("C-potionM", "DefensePotion(M)", "Boosts your armor by 300 for 3 turns",
                                            200, COMMON, 9, 2,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, true, rsHandler->generateId());
    consumablesList["DefensePotion(L)"] = Item("C-potionL", "DefensePotion(L)", "Boosts your armor by 600 for 3 turns",
                                            400, RARE, 9, 3,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, true, rsHandler->generateId());

    consumablesList["CriticalHitChancePotion(S)"] = Item("C-potionS", "CriticalHitChancePotion(S)",
                                                         "Boosts your critical hit chance by 10% for 3 turns",
                                            100, UNCOMMON, 4, 3,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, true, rsHandler->generateId());
    consumablesList["CriticalHitChancePotion(M)"] = Item("C-potionM", "CriticalHitChancePotion(M)",
                                                         "Boosts your critical hit chance by 15% for 3 turns",
                                            200, COMMON, 11, 2,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, true, rsHandler->generateId());
    consumablesList["CriticalHitChancePotion(L)"] = Item("C-potionL", "CriticalHitChancePotion(L)",
                                                         "Boosts your critical hit chance by 25% for 3 turns",
                                            400, RARE, 11, 3,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, true, rsHandler->generateId());

    consumablesList["EvadeChancePotion(S)"] = Item("C-potionS", "EvadeChancePotion(S)",
                                                   "Boosts your evade chance by 10% for 3 turns",
                                            100, UNCOMMON, 6, 3,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, true, rsHandler->generateId());
    consumablesList["EvadeChancePotion(M)"] = Item("C-potionM", "EvadeChancePotion(M)",
                                                   "Boosts your evade chance by 15% for 3 turns",
                                            200, COMMON, 13, 2,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, true, rsHandler->generateId());
    consumablesList["EvadeChancePotion(L)"] = Item("C-potionL", "EvadeChancePotion(L)",
                                                   "Boosts your evade chance by 25% for 3 turns",
                                            400, RARE, 13, 3,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, true, rsHandler->generateId());

    consumablesList["UpgradeInventory"] = Item("Upgrade", "UpgradeInventory", "Gives you extra 5 inventory capacity",
                                         1500, LEGENDARY, 0, 30,
                                         0, 0, 0, 0, 0.f, 0.f,
                                         1, false, rsHandler->generateId());
}

LootGenerator::LootGenerator(std::shared_ptr<ResourcesHandler> rs_handler) : rsHandler(std::move(rs_handler)){
    initDroppableMaterials();
    initConsomablesList();
    generateLoot(1);
}

LootGenerator::~LootGenerator() = default;



std::string LootGenerator::toStringMaterials() {
    stringstream ss;
    ss << "--------------------Drop Material List--------------------" << std::endl;
    for(auto &i : droppableMaterials){
        ss << i->listItem() << std::endl;
    }
    ss << "--------------------End-Drop Material List-End--------------------" << std::endl;
    return ss.str();
}

const vector<std::unique_ptr<Item>> &LootGenerator::getDroppableMaterials() const {
    return droppableMaterials;
}

const map<std::string, Item> &LootGenerator::getConsumablesList() const {
    return consumablesList;
}

void LootGenerator::generateLoot(int floor) {
    int count[] = {0,0,0,0,0,0,0,0,0};
    int count2[] = {0,0,0,0,0};
    for(int i = 0 ; i < 100 ; i++){
        int random_value = utils::generateRandomNumber(1, MAX_PROBABILITY);
        int starting_loot_type = 0;
        while(lootProbabilities[starting_loot_type] < random_value){
            starting_loot_type++;
        }
        count[starting_loot_type]++;
        auto loot_type_enum= static_cast<loot_type>(starting_loot_type);
        switch (loot_type_enum) {
            case MATERIAL_LOOT:
                break;
            case COMSUMABLE_LOOT:
                break;
            case WEAPON_LOOT: case SHIELD_LOOT: case HELMET_LOOT: case CHESTPLATE_LOOT: case GLOVES_LOOT: case BOOTS_LOOT:{
                random_value = utils::generateRandomNumber(1, MAX_RARITY_PROBABILITY) + floor;
                int starting_loot_rarity = 0;
                switch (floor) {
                    case 1:
                        while(lootRarityProbabilities1[starting_loot_rarity] < random_value){
                            starting_loot_rarity++;
                        }
                        break;
                    case 2:
                        while(lootRarityProbabilities2[starting_loot_rarity] < random_value){
                            starting_loot_rarity++;
                        }
                        break;
                    case 3:
                        while(lootRarityProbabilities3[starting_loot_rarity] < random_value){
                            starting_loot_rarity++;
                        }
                        break;
                    case 4:
                        while(lootRarityProbabilities4[starting_loot_rarity] < random_value){
                            starting_loot_rarity++;
                        }
                        break;
                    case 5:
                        while(lootRarityProbabilities5[starting_loot_rarity] < random_value){
                            starting_loot_rarity++;
                        }
                        break;
                    default:
                        break;
                }
                auto loot_rarity_enum= static_cast<loot_rarity>(starting_loot_rarity);
                count2[starting_loot_rarity]++;
                break;
            }
            case NO_LOOT:
                break;
        }
    }
    std::cout<< "Material: " << count[0] << endl;
    std::cout<< "Consumable: " << count[1] << endl;
  //  std::cout<< "Weapon: " << count[2] << endl;
   // std::cout<< "Shield: " << count[3] << endl;
  //  std::cout<< "Helmet: " << count[4] << endl;
  //  std::cout<< "Chestplate: " << count[5] << endl;
 //   std::cout<< "Gloves: " << count[6] << endl;
  //  std::cout<< "Boots: " << count[7] << endl;
    std::cout<< "Nothing: " << count[8] << endl;
    std::cout<< "Tot equipment: " << count[2]+count[3]+count[4]+count[5]+count[6]+count[7]<< endl;
    std::cout<< "        Uncommon: " << count2[0] << endl;
    std::cout<< "        Common: " << count2[1] << endl;
    std::cout<< "        Rare: " << count2[2] << endl;
    std::cout<< "        Epic: " << count2[3] << endl;
    std::cout<< "        Legendary: " << count2[4] << endl;
    std::cout<< "        Tot: " << count2[0]+count2[1]+count2[2]+count2[3]+count2[4] << endl;
}


