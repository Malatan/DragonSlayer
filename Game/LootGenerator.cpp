//
// Created by Zheng on 03/12/2020.
//

#include "LootGenerator.h"

const int LootGenerator::MAX_PROBABILITY = 300;
const int LootGenerator::MAX_RARITY_PROBABILITY = 120;
const int LootGenerator::MAX_MATERIAL_RARITY_PROBABILITY = 105;
const int LootGenerator::MAX_MATERIAL_AMOUNT_PROBABILITY = 130;
const int LootGenerator::MAX_POTION_RARITY_PROBABILITY = 120;
const int LootGenerator::MAX_POTION_AMOUNT_PROBABILITY = 145;

const int LootGenerator::potionAmountProbabilities[]  = {60, 90, 105, 117, 125, MAX_POTION_AMOUNT_PROBABILITY};
const int LootGenerator::potionRarityProbabilities[] = {60, 100, MAX_POTION_RARITY_PROBABILITY};

//80% la rarita' del materiale corrisponde al floor, 20% rarita' floor+1, 10% rarita' floor+2
const int LootGenerator::materialRarityProbabilities[] = {80, 100, MAX_MATERIAL_RARITY_PROBABILITY};
//30% 1p, 28% 2p, 26% 3p, 24% 4p, 22% 5p, 20% 6p, 18% 7p, 10% 8p,
const int LootGenerator::materialAmountProbabilities[] = {40, 76, 102, 120, 132, 142, 150, MAX_MATERIAL_AMOUNT_PROBABILITY};

const int LootGenerator::lootProbabilities[] = {120, 140, 150, 160, 170, 180, 190, 200, MAX_PROBABILITY};
const int LootGenerator::lootRarityProbabilities1[] = {60, 92, 108, 116, MAX_RARITY_PROBABILITY};
const int LootGenerator::lootRarityProbabilities2[] = {54, 87, 105, 115, MAX_RARITY_PROBABILITY};
const int LootGenerator::lootRarityProbabilities3[] = {48, 82, 102, 114, MAX_RARITY_PROBABILITY};
const int LootGenerator::lootRarityProbabilities4[] = {43, 77, 99, 113, MAX_RARITY_PROBABILITY};
const int LootGenerator::lootRarityProbabilities5[] = {36, 71, 95, 111, MAX_RARITY_PROBABILITY};

//Uncommon: max 1 - 2 stats, Common: max 2 - 3, Rare: max 2 - 4, Epic: max 3 - 5, Legendary: max 4 - 6
const pairInt LootGenerator::statsAmount[] = {{1 , 2}, {2, 3}, {2, 4}, {3, 5}, {4, 6}}; // NOLINT(cert-err58-cpp)
//Uncommon - Common - Rare - Epic - Legendary
const pairInt LootGenerator::hpRange[] = {{1, 50}, {75, 125}, {180, 250}, {350, 450}, {600, 700}};// NOLINT(cert-err58-cpp)
const pairInt LootGenerator::mpRange[] = {{1, 50}, {75, 125}, {180, 250}, {350, 450}, {600, 700}};// NOLINT(cert-err58-cpp)
const pairInt LootGenerator::damageRange[] = {{1, 10}, {20, 40}, {60, 80}, {100, 120}, {150, 200}};// NOLINT(cert-err58-cpp)
const pairInt LootGenerator::armorRange[] = {{1, 5}, {10, 20}, {30, 50}, {60, 100}, {120, 180}};// NOLINT(cert-err58-cpp)
const pairFloat LootGenerator::critchanceRange[] = {{0.1f, 1.5f}, {2.f, 4.f}, {6.f, 10.f}, {12.f, 16.f},// NOLINT(cert-err58-cpp)
                                                    {18.f, 22.f}};
const pairFloat LootGenerator::evadechanceRange[] = {{0.1f, 1.f}, {1.5f, 3.f}, {4.f, 6.f}, {8.f, 12.f},// NOLINT(cert-err58-cpp)
                                                     {12.f, 15.f}};

const pairInt LootGenerator::swordIconIntRects[] = {{0,  5}, {1, 5}, {2, 5}, {3, 5}, {4, 5},// NOLINT(cert-err58-cpp)
                                                    {5,  5}, {6, 5}, {7, 5}, {8, 5}, {9, 5},
                                                    {10, 5}, {11, 5}, {12, 5}, {13, 5}};
const pairInt LootGenerator::axeIconIntRects[] = {{0,  10}, {1, 10}, {2, 10}, {3, 10}, {4, 10},// NOLINT(cert-err58-cpp)
                                                  {5,  10}, {6, 10}, {7, 10}, {8, 10}, {9, 10},
                                                  {10, 10}, {11, 10}, {12, 10}, {13, 10}};
const pairInt LootGenerator::bowIconIntRects[] = {{0,  11}, {1, 11}, {2, 11}, {3, 11}, {4, 11},// NOLINT(cert-err58-cpp)
                                                  {5,  11}, {6, 11}, {7, 11}, {8, 11}, {9, 11},
                                                  {10, 11}, {11, 11}, {12, 11}, {13, 11}};
const pairInt LootGenerator::shieldIconIntRects[] = {{0,  12}, {1, 12}, {2, 12}, {3, 12}, {4, 12},// NOLINT(cert-err58-cpp)
                                                     {5,  12}, {6, 12}, {7, 12}, {8, 12}, {9, 12},
                                                     {10, 12}, {11, 12}, {12, 12}, {13, 12}};
const pairInt LootGenerator::helmetIconIntRects[] = {{7,  13}, {8, 13}, {9, 13}, {10, 13},// NOLINT(cert-err58-cpp)
                                                     {11, 13}, {12, 13}, {13, 13}};
const pairInt LootGenerator::chestIntRects[] = {{0, 13}, {1, 13}, {2, 13}, {3, 13}, {4, 13},// NOLINT(cert-err58-cpp)
                                                {5, 13}, {6, 13}};
const pairInt LootGenerator::glovesIntRects[] = {{7,  14}, {8, 14}, {9, 14}, {10, 14}, {11, 14},// NOLINT(cert-err58-cpp)
                                                 {12, 14}, {13, 14}};
const pairInt LootGenerator::bootsIntRects[] = {{0, 14}, {1, 14}, {2, 14}, {3, 14}, {4, 14},// NOLINT(cert-err58-cpp)
                                                {5, 14}, {6, 14}};
const pairInt LootGenerator::shieldArmorRange[] = {{17, 22}, {25, 30}, {33, 38}, {45, 55}, {60, 70}};// NOLINT(cert-err58-cpp)

void LootGenerator::initDroppableMaterials() {
    rsHandler->loadMaterialsTxt(droppableMaterials);
}

void LootGenerator::initShopList() {
    shopList["HealthPotion(S)"] = Item("C-potionS", "HealthPotion(S)", "Restore 100 hp",
                                       50, UNCOMMON, 0, 3,
                                       0, 0, 0, 0, 0.f, 0.f,
                                       1, true, rsHandler->generateId());
    shopList["HealthPotion(M)"] = Item("C-potionM", "HealthPotion(M)", "Restore 200 hp",
                                       100, COMMON, 7, 2,
                                       0, 0, 0, 0, 0.f, 0.f,
                                       1, true, rsHandler->generateId());
    shopList["HealthPotion(L)"] = Item("C-potionL", "HealthPotion(L)", "Restore 400 hp",
                                       200, RARE, 7, 3,
                                       0, 0, 0, 0, 0.f, 0.f,
                                       1, true, rsHandler->generateId());
    shopList["ManaPotion(S)"] = Item("C-potionS", "ManaPotion(S)", "Restore 100 mp",
                                     50, UNCOMMON, 3, 3,
                                     0, 0, 0, 0, 0.f, 0.f,
                                     1, true, rsHandler->generateId());
    shopList["ManaPotion(M)"] = Item("C-potionM", "ManaPotion(M)", "Restore 200 mp",
                                     100, COMMON, 10, 2,
                                     0, 0, 0, 0, 0.f, 0.f,
                                     1, true, rsHandler->generateId());
    shopList["ManaPotion(L)"] = Item("C-potionL", "ManaPotion(L)", "Restore 400 mp",
                                     200, RARE, 10, 3,
                                     0, 0, 0, 0, 0.f, 0.f,
                                     1, true, rsHandler->generateId());

    shopList["DamagePotion(S)"] = Item("C-potionS", "DamagePotion(S)", "Boosts your attack by 100 for 3 turns",
                                       100, UNCOMMON, 1, 3,
                                       0, 0, 0, 0, 0.f, 0.f,
                                       1, true, rsHandler->generateId());
    shopList["DamagePotion(M)"] = Item("C-potionM", "DamagePotion(M)", "Boosts your attack by 300 for 3 turns",
                                       200, COMMON, 8, 2,
                                       0, 0, 0, 0, 0.f, 0.f,
                                       1, true, rsHandler->generateId());
    shopList["DamagePotion(L)"] = Item("C-potionL", "DamagePotion(L)", "Boosts your attack by 600 for 3 turns",
                                       400, RARE, 8, 3,
                                       0, 0, 0, 0, 0.f, 0.f,
                                       1, true, rsHandler->generateId());

    shopList["DefensePotion(S)"] = Item("C-potionS", "DefensePotion(S)", "Boosts your armor by 100 for 3 turns",
                                        100, UNCOMMON, 2, 3,
                                        0, 0, 0, 0, 0.f, 0.f,
                                        1, true, rsHandler->generateId());
    shopList["DefensePotion(M)"] = Item("C-potionM", "DefensePotion(M)", "Boosts your armor by 300 for 3 turns",
                                        200, COMMON, 9, 2,
                                        0, 0, 0, 0, 0.f, 0.f,
                                        1, true, rsHandler->generateId());
    shopList["DefensePotion(L)"] = Item("C-potionL", "DefensePotion(L)", "Boosts your armor by 600 for 3 turns",
                                        400, RARE, 9, 3,
                                        0, 0, 0, 0, 0.f, 0.f,
                                        1, true, rsHandler->generateId());

    shopList["CriticalHitChancePotion(S)"] = Item("C-potionS", "CriticalHitChancePotion(S)",
                                                  "Boosts your critical hit chance by 10% for 3 turns",
                                                  100, UNCOMMON, 4, 3,
                                                  0, 0, 0, 0, 0.f, 0.f,
                                                  1, true, rsHandler->generateId());
    shopList["CriticalHitChancePotion(M)"] = Item("C-potionM", "CriticalHitChancePotion(M)",
                                                  "Boosts your critical hit chance by 15% for 3 turns",
                                                  200, COMMON, 11, 2,
                                                  0, 0, 0, 0, 0.f, 0.f,
                                                  1, true, rsHandler->generateId());
    shopList["CriticalHitChancePotion(L)"] = Item("C-potionL", "CriticalHitChancePotion(L)",
                                                  "Boosts your critical hit chance by 25% for 3 turns",
                                                  400, RARE, 11, 3,
                                                  0, 0, 0, 0, 0.f, 0.f,
                                                  1, true, rsHandler->generateId());

    shopList["EvadeChancePotion(S)"] = Item("C-potionS", "EvadeChancePotion(S)",
                                            "Boosts your evade chance by 10% for 3 turns",
                                            100, UNCOMMON, 6, 3,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, true, rsHandler->generateId());
    shopList["EvadeChancePotion(M)"] = Item("C-potionM", "EvadeChancePotion(M)",
                                            "Boosts your evade chance by 15% for 3 turns",
                                            200, COMMON, 13, 2,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, true, rsHandler->generateId());
    shopList["EvadeChancePotion(L)"] = Item("C-potionL", "EvadeChancePotion(L)",
                                            "Boosts your evade chance by 25% for 3 turns",
                                            400, RARE, 13, 3,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, true, rsHandler->generateId());

    shopList["UpgradeInventory"] = Item("Upgrade", "Upgrade Inventory", "Gives you extra 5 inventory capacity",
                                        1500, LEGENDARY, 0, 30,
                                        0, 0, 0, 0, 0.f, 0.f,
                                        1, false, rsHandler->generateId());

    shopList["1_randLoot"] = Item("Mystery", "Mystery Box", "Gives you a random tier equipment",
                                  1500, LEGENDARY, 8, 30,
                                  0, 0, 0, 0, 0.f, 0.f,
                                  1, false, rsHandler->generateId());

    shopList["2_randUncommonLoot"] = Item("Mystery", "Mystery Box(Uncommon)", "Gives you an uncommon tier equipment",
                                        1000, UNCOMMON, 7, 30,
                                        0, 0, 0, 0, 0.f, 0.f,
                                        1, false, rsHandler->generateId());

    shopList["3_randCommonLoot"] = Item("Mystery", "Mystery Box(Common)", "Gives you a common tier equipment",
                                        2000, COMMON, 6, 30,
                                        0, 0, 0, 0, 0.f, 0.f,
                                        1, false, rsHandler->generateId());

    shopList["4_randRareLoot"] = Item("Mystery", "Mystery Box(Rare)", "Gives you a rare tier equipment",
                                        3000, RARE, 5, 30,
                                        0, 0, 0, 0, 0.f, 0.f,
                                        1, false, rsHandler->generateId());

    shopList["5_randEpicLoot"] = Item("Mystery", "Mystery Box(Epic)", "Gives you an epic tier equipment",
                                        4000, EPIC, 4, 30,
                                        0, 0, 0, 0, 0.f, 0.f,
                                        1, false, rsHandler->generateId());

    shopList["6_randLegendaryLoot"] = Item("Mystery", "Mystery Box(Legendary)", "Gives you a legendary tier equipment",
                                        5000, LEGENDARY, 3, 30,
                                        0, 0, 0, 0, 0.f, 0.f,
                                        1, false, rsHandler->generateId());

}

void LootGenerator::initDroppableConsumablesList() {
    droppableConsumablesList.emplace_back("HealthPotion(S)");
    droppableConsumablesList.emplace_back("HealthPotion(M)");
    droppableConsumablesList.emplace_back("HealthPotion(L)");
    droppableConsumablesList.emplace_back("ManaPotion(S)");
    droppableConsumablesList.emplace_back("ManaPotion(M)");
    droppableConsumablesList.emplace_back("ManaPotion(L)");
    droppableConsumablesList.emplace_back("DamagePotion(S)");
    droppableConsumablesList.emplace_back("DamagePotion(M)");
    droppableConsumablesList.emplace_back("DamagePotion(L)");
    droppableConsumablesList.emplace_back("DefensePotion(S)");
    droppableConsumablesList.emplace_back("DefensePotion(M)");
    droppableConsumablesList.emplace_back("DefensePotion(L)");
    droppableConsumablesList.emplace_back("CriticalHitChancePotion(S)");
    droppableConsumablesList.emplace_back("CriticalHitChancePotion(M)");
    droppableConsumablesList.emplace_back("CriticalHitChancePotion(L)");
    droppableConsumablesList.emplace_back("EvadeChancePotion(S)");
    droppableConsumablesList.emplace_back("EvadeChancePotion(M)");
    droppableConsumablesList.emplace_back("EvadeChancePotion(L)");
}

LootGenerator::LootGenerator(std::shared_ptr<ResourcesHandler> rs_handler) : rsHandler(std::move(rs_handler)) {
    initDroppableMaterials();
    initShopList();
    initDroppableConsumablesList();
    //generateLoot(10000, 5);
}

LootGenerator::~LootGenerator() = default;

std::string LootGenerator::toStringMaterials() {
    stringstream ss;
    ss << "--------------------Drop Material List--------------------" << std::endl;
    for (auto &i : droppableMaterials) {
        ss << i->listItem(false) << std::endl;
    }
    ss << "--------------------End-Drop Material List-End--------------------" << std::endl;
    return ss.str();
}

const vector<std::unique_ptr<Item>> &LootGenerator::getDroppableMaterials() const {
    return droppableMaterials;
}

const map<std::string, Item> &LootGenerator::getShopList() const {
    return shopList;
}

std::vector<std::shared_ptr<Item>> LootGenerator::generateLoot(const std::shared_ptr<Enemy>& defeated_enemy, int floor) {
    bool print_result = false;
    bool print_lootbag = false;
    bool print_generated_equip = false;
    bool add_materials = true;
    bool add_potions = true;
    bool add_equip = true;

    //dropcount
    std::vector<dropCount> drop_counts;
    if(defeated_enemy->getDeadFollowersNumber() == defeated_enemy->getFollowersNumber()){
        drop_counts.emplace_back(2, defeated_enemy->getType());
    }else{
        drop_counts.emplace_back(1, defeated_enemy->getType());
    }
    for(const auto& i : defeated_enemy->getFollowers()){
        if(i->isDead()){
            drop_counts.emplace_back(1, i->getType());
        }
    }
    int drop_count = 0;
    std::vector<std::shared_ptr<Item>> loot_bag;

    //   <rarita, quantita>
    std::map<int, int> materials;
    std::map<int, int> potions;
    int loot_type_count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int equip_rarity_count[] = {0, 0, 0, 0, 0};
    int material_piece_count[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int material_rarity_count[] = {0, 0, 0, 0, 0};
    int potion_piece_count[] = {0, 0, 0, 0, 0, 0};
    int potion_rarity_count[] = {0, 0, 0};
    for(auto i : drop_counts){
        enemy_types enemy_tipo = i.second;
        for (int ii = 0; ii < i.first; ii++) {
            drop_count++;
            //genera in modo randomico un numero
            int random_value = utils::generateRandomNumber(1, MAX_PROBABILITY);
            int starting_loot_type = 0;
            //si scorre il loot finche non troppa il range giusto
            while (lootProbabilities[starting_loot_type] < random_value)
                starting_loot_type++;
            loot_type_count[starting_loot_type]++;
            auto loot_type_enum = static_cast<loot_type>(starting_loot_type);
            std::string equip_type;
            switch (loot_type_enum) {
                case MATERIAL_LOOT:{
                    // genera in modo randomico la quantita' da 1 a 8
                    random_value = utils::generateRandomNumber(1, MAX_MATERIAL_AMOUNT_PROBABILITY);
                    int start = 0;
                    while (materialAmountProbabilities[start] < random_value)
                        start++;
                    material_piece_count[start]++;
                    int material_amount = start+1;
                    // genera in modo randomico la rarita' del materiale
                    for(int j = 0 ; j < material_amount ; j++){
                        random_value = utils::generateRandomNumber(1, MAX_MATERIAL_RARITY_PROBABILITY);
                        start = 0;
                        while (materialRarityProbabilities[start] < random_value)
                            start++;
                        int n_rarita = start+floor;
                        if(n_rarita > 5)
                            n_rarita = 5;
                        materials[n_rarita] += 1;
                        material_rarity_count[n_rarita-1]++;
                    }
                    break;
                }
                case COMSUMABLE_LOOT:{
                    // genera in modo randomico la quantita' da 1 a 6
                    random_value = utils::generateRandomNumber(1, MAX_POTION_AMOUNT_PROBABILITY);
                    int start = 0;
                    while (potionAmountProbabilities[start] < random_value)
                        start++;
                    potion_piece_count[start]++;
                    int potion_amount = start+1;
                    // genera in modo randomico la rarita' della pozione
                    for(int j = 0 ; j < potion_amount ; j++){
                        random_value = utils::generateRandomNumber(1, MAX_POTION_RARITY_PROBABILITY);
                        start = 0;
                        while (potionRarityProbabilities[start] < random_value)
                            start++;
                        potions[start+1] += 1;
                        potion_rarity_count[start]++;
                    }
                    break;
                }
                case WEAPON_LOOT: {
                    int n = utils::generateRandomNumber(0, 2);
                    switch (n) {
                        case 0:
                            equip_type = "W-sword";
                            break;
                        case 1:
                            equip_type = "W-axe";
                            break;
                        case 2:
                            equip_type = "W-bow";
                            break;
                        default:
                            equip_type = "W-sword";
                            break;
                    }
                }
                case SHIELD_LOOT: {
                    if(equip_type.empty())
                        equip_type = "E-shield";
                }
                case HELMET_LOOT: {
                    if(equip_type.empty())
                        equip_type = "E-head";
                }
                case CHESTPLATE_LOOT: {
                    if(equip_type.empty())
                        equip_type = "E-chest";
                }
                case GLOVES_LOOT: {
                    if(equip_type.empty())
                        equip_type = "E-arms";
                }
                case BOOTS_LOOT: {
                    if(equip_type.empty())
                        equip_type = "E-legs";
                    // genera il numero per determinare la rarita dell'equipaggiamento
                    random_value = utils::generateRandomNumber(1, MAX_RARITY_PROBABILITY);
                    int starting_loot_rarity = 0;
                    // la probabilita varia a seconda del piano(floor)
                    switch (floor) {
                        case 1:
                            while (lootRarityProbabilities1[starting_loot_rarity] < random_value)
                                starting_loot_rarity++;
                            break;
                        case 2:
                            while (lootRarityProbabilities2[starting_loot_rarity] < random_value)
                                starting_loot_rarity++;
                            break;
                        case 3:
                            while (lootRarityProbabilities3[starting_loot_rarity] < random_value)
                                starting_loot_rarity++;
                            break;
                        case 4:
                            while (lootRarityProbabilities4[starting_loot_rarity] < random_value)
                                starting_loot_rarity++;
                            break;
                        case 5:
                            while (lootRarityProbabilities5[starting_loot_rarity] < random_value)
                                starting_loot_rarity++;
                            break;
                        default:
                            break;
                    }
                    equip_rarity_count[starting_loot_rarity]++;
                    if(add_equip){
                        //prende un nome a caso dal file txt
                        ifstream file;
                        ifstream file_desc;
                        if(unitTesting){
                            file.open("../../Data/Equipment names/" + equip_type.substr(2) + ".txt");
                            file_desc.open("../../Data/random descriptions.txt");
                        }else{
                            file.open("../Data/Equipment names/" + equip_type.substr(2) + ".txt");
                            file_desc.open("../Data/random descriptions.txt");
                        }
                        if (!file.is_open()) {
                            cout << "Resource load error: Could not load name.txt";
                        } else if(!file_desc.is_open()){
                            cout << "Resource load error: Could not load random descriptions.txt";
                        } else {
                            std::string names;
                            std::vector<std::string> lines;
                            int total_lines=0;
                            while(getline(file, names)){
                                total_lines++;
                                lines.push_back(names);
                            }
                            auto loot_rarity_enum = static_cast<loot_rarity>(starting_loot_rarity);
                            int random_line = utils::generateRandomNumber(0, total_lines - 1);
                            std::string item_name = lines[random_line];
                            std::shared_ptr<Item> new_equip = std::make_shared<Item>();
                            new_equip->setItemType(equip_type);
                            new_equip->setName(item_name);
                            new_equip->setRarity(getRarityString(loot_rarity_enum));
                            new_equip->setId(rsHandler->generateId());
                            new_equip->updateUsageType();
                            new_equip->setQuantity(1);

                            //genera l'icona per l'oggetto
                            switch(new_equip->getUsageType()){
                                case LEGS_USAGE:{
                                    int array_size = sizeof(bootsIntRects)/sizeof(bootsIntRects[0]) - 1;
                                    int random_index = utils::generateRandomNumber(0, array_size);
                                    new_equip->setIconRectX(bootsIntRects[random_index].first);
                                    new_equip->setIconRectY(bootsIntRects[random_index].second);
                                    break;
                                }
                                case ARMS_USAGE:{
                                    int array_size = sizeof(glovesIntRects)/sizeof(glovesIntRects[0]) - 1;
                                    int random_index = utils::generateRandomNumber(0, array_size);
                                    new_equip->setIconRectX(glovesIntRects[random_index].first);
                                    new_equip->setIconRectY(glovesIntRects[random_index].second);
                                    break;
                                }
                                case CHEST_USAGE:{
                                    int array_size = sizeof(chestIntRects)/sizeof(chestIntRects[0]) - 1;
                                    int random_index = utils::generateRandomNumber(0, array_size);
                                    new_equip->setIconRectX(chestIntRects[random_index].first);
                                    new_equip->setIconRectY(chestIntRects[random_index].second);
                                    break;
                                }
                                case HEAD_USAGE:{
                                    int array_size = sizeof(helmetIconIntRects)/sizeof(helmetIconIntRects[0]) - 1;
                                    int random_index = utils::generateRandomNumber(0, array_size);
                                    new_equip->setIconRectX(helmetIconIntRects[random_index].first);
                                    new_equip->setIconRectY(helmetIconIntRects[random_index].second);
                                    break;
                                }
                                case SHIELD_USAGE:{
                                    int array_size = sizeof(shieldIconIntRects)/sizeof(shieldIconIntRects[0]) - 1;
                                    int random_index = utils::generateRandomNumber(0, array_size);
                                    new_equip->setIconRectX(shieldIconIntRects[random_index].first);
                                    new_equip->setIconRectY(shieldIconIntRects[random_index].second);
                                    break;
                                }
                                case WEAPON_USAGE:{
                                    if(new_equip->getWeaponType() == "sword"){
                                        int array_size = sizeof(swordIconIntRects)/sizeof(swordIconIntRects[0]) - 1;
                                        int random_index = utils::generateRandomNumber(0, array_size);
                                        new_equip->setIconRectX(swordIconIntRects[random_index].first);
                                        new_equip->setIconRectY(swordIconIntRects[random_index].second);
                                    }else if(new_equip->getWeaponType() == "axe"){
                                        int array_size = sizeof(axeIconIntRects)/sizeof(axeIconIntRects[0]) - 1;
                                        int random_index = utils::generateRandomNumber(0, array_size);
                                        new_equip->setIconRectX(axeIconIntRects[random_index].first);
                                        new_equip->setIconRectY(axeIconIntRects[random_index].second);
                                    }else if(new_equip->getWeaponType() == "bow"){
                                        int array_size = sizeof(bowIconIntRects)/sizeof(bowIconIntRects[0]) - 1;
                                        int random_index = utils::generateRandomNumber(0, array_size);
                                        new_equip->setIconRectX(bowIconIntRects[random_index].first);
                                        new_equip->setIconRectY(bowIconIntRects[random_index].second);
                                    }
                                    break;
                                }
                                case CONSUMABLE_USAGE: case MATERIAL_USAGE: case DEFAULT_USAGE:
                                    break;
                            }

                            //genera in modo randomico gli effetti dell'arma
                            int effect_amount = utils::generateRandomNumber(statsAmount[starting_loot_rarity].first,
                                                                            statsAmount[starting_loot_rarity].second);
                            std::vector<equip_effect> effects;
                            effects.reserve(effect_amount);
                            switch(new_equip->getUsageType()){
                                case LEGS_USAGE:
                                case ARMS_USAGE:
                                case CHEST_USAGE:
                                case HEAD_USAGE:
                                case SHIELD_USAGE:
                                    effects.push_back(ADD_ARMOR);
                                    effect_amount--;
                                    break;
                                case WEAPON_USAGE:
                                    effects.push_back(ADD_DAMAGE);
                                    effect_amount--;
                                    break;
                                case CONSUMABLE_USAGE: case MATERIAL_USAGE: case DEFAULT_USAGE:
                                    break;
                            }
                            while(effect_amount > 0){
                                bool repeated = false;
                                auto random_effect = static_cast<equip_effect>(utils::generateRandomNumber(0 ,5));
                                for(auto app : effects){
                                    if(app == random_effect){
                                        repeated = true;
                                        break;
                                    }
                                }
                                if(!repeated){
                                    effect_amount--;
                                    effects.push_back(random_effect);
                                }
                            }
                            for(auto app : effects){
                                switch (app) {
                                    case ADD_HP:{
                                        int value = utils::generateRandomNumber(hpRange[starting_loot_rarity].first,
                                                                                hpRange[starting_loot_rarity].second);
                                        new_equip->setHp(value);
                                        break;
                                    }
                                    case ADD_MP:{
                                        int value = utils::generateRandomNumber(mpRange[starting_loot_rarity].first,
                                                                                mpRange[starting_loot_rarity].second);
                                        new_equip->setMp(value);
                                        break;
                                    }
                                    case ADD_DAMAGE:{
                                        int value = utils::generateRandomNumber(damageRange[starting_loot_rarity].first,
                                                                                damageRange[starting_loot_rarity].second);
                                        new_equip->setDamage(value);
                                        break;
                                    }
                                    case ADD_ARMOR:{int value;
                                        if(new_equip->getUsageType() == SHIELD_USAGE){
                                            value = utils::generateRandomNumber(shieldArmorRange[starting_loot_rarity].first,
                                                                                shieldArmorRange[starting_loot_rarity].second);
                                        }else{
                                            value = utils::generateRandomNumber(armorRange[starting_loot_rarity].first,
                                                                                armorRange[starting_loot_rarity].second);
                                        }
                                        new_equip->setArmor(value);
                                        break;
                                    }
                                    case ADD_CRITCHANCE:{
                                        float valuef = utils::generateRandomNumberf(critchanceRange[starting_loot_rarity].first,
                                                                                    critchanceRange[starting_loot_rarity].second,
                                                                                    2);
                                        new_equip->setCritChance(valuef);
                                        break;
                                    }
                                    case ADD_EVADECHANCE:{
                                        float valuef = utils::generateRandomNumberf(evadechanceRange[starting_loot_rarity].first,
                                                                                    evadechanceRange[starting_loot_rarity].second,
                                                                                    2);
                                        new_equip->setEvadeChance(valuef);
                                        break;
                                    }
                                }
                            }
                            //calcola il valore dell'oggetto
                            float base_value = (float)new_equip->getHp() / 5.f + (float)new_equip->getHp() / 5.f +
                                               (float)new_equip->getDamage() * 5.f + (float)new_equip->getArmor() * 5.f +
                                               new_equip->getCritChance() * 10.f + new_equip->getEvadeChance() * 10.f;
                            switch(new_equip->getRarityEnum()){
                                case UNCOMMON:{
                                    base_value *= 1.5f;
                                    break;
                                }
                                case COMMON:{
                                    base_value *= 2.f;
                                    break;
                                }
                                case RARE:{
                                    base_value *= 2.5f;
                                    break;
                                }
                                case EPIC:{
                                    base_value *= 3.f;
                                    break;
                                }
                                case LEGENDARY:{
                                    base_value *= 3.5f;
                                    break;
                                }
                                case DEFAULT_RARITY: default:
                                    break;
                            }
                            new_equip->setValue(std::ceil(base_value));

                            //genera la descrizione per l'oggetto
                            if(new_equip->getUsageType() == SHIELD_USAGE){
                                stringstream ss;
                                ss << "Reduces " << new_equip->getArmor() << " % of damage when raised(Defensive mode).";
                                new_equip->setDescription(ss.str());
                            }else{
                                std::string descs;
                                lines.clear();
                                total_lines = 0;
                                while(getline(file_desc, descs)){
                                    total_lines++;
                                    lines.push_back(descs);
                                }
                                random_line = utils::generateRandomNumber(0, total_lines - 1);
                                std::string desc = lines[random_line];
                                new_equip->setDescription(desc);
                            }

                            //aggiunge l'oggetto nel lootbag
                            loot_bag.push_back(std::move(new_equip));
                            new_equip.reset();
                            file_desc.close();
                            file.close();
                            if(print_generated_equip){
                                std::cout<< equip_type << "(" << getRarityString(loot_rarity_enum) << ")-" << item_name << std::endl;
                                for(auto app : effects){
                                    switch (app) {
                                        case ADD_HP:
                                            std::cout<< "   Add hp: " << new_equip->getHp() << std::endl;
                                            break;
                                        case ADD_MP:
                                            std::cout<< "   Add mp: " << new_equip->getMp() << std::endl;
                                            break;
                                        case ADD_DAMAGE:
                                            std::cout<< "   Add damage: " << new_equip->getDamage() << std::endl;
                                            break;
                                        case ADD_ARMOR:
                                            std::cout<< "   Add armor: " << new_equip->getArmor() << std::endl;
                                            break;
                                        case ADD_CRITCHANCE:
                                            std::cout<< "   Add critchance: " << new_equip->getCritChance() << std::endl;
                                            break;
                                        case ADD_EVADECHANCE:
                                            std::cout<< "   Add evadechance: " << new_equip->getEvadeChance() << std::endl;
                                            break;
                                    }
                                }
                            }
                        }
                    }
                    break;
                }
                case NO_LOOT:
                    break;
            }
        }
        //aggiunge i materiali nel lootbag
        if(add_materials){
            for(auto j : materials){
                bool repeated = false;
                auto material_rarity = static_cast<item_rarity>(j.first);
                std::shared_ptr<Item> new_material = std::make_shared<Item>(getMaterialByEnemyType(enemy_tipo));
                new_material->setRarity(material_rarity);
                for(const auto& k : loot_bag){
                    if(k->getName() == new_material->getName() &&
                       k->getRarityEnum() == new_material->getRarityEnum()){
                        k->addQuantity(j.second - k->getQuantity());
                        repeated = true;
                        break;
                    }
                }
                if(!repeated){
                    new_material->setQuantity(j.second);
                    new_material->setRarity(material_rarity);
                    new_material->updateValueByRarity();
                    new_material->setId(rsHandler->generateId());
                    loot_bag.push_back(std::move(new_material));
                }
            }
            materials.clear();
        }
    }

    //aggiunge i comsumabili nel lootbag
    if(add_potions){
        for(auto j : potions){
            auto p_rarity = static_cast<item_rarity>(j.first);
            int p_count = j.second;
            while(p_count > 0){
                bool repeated = false;
                int rand_amount = utils::generateRandomNumber(1, p_count);
                p_count -= rand_amount;
                bool correct_rarity = false;
                std::string p_name;
                while(!correct_rarity){
                    int rand_index = utils::generateRandomNumber(1, (int)droppableConsumablesList.size() - 1);
                    p_name = droppableConsumablesList[rand_index];
                    if(shopList[p_name].getRarityEnum() == p_rarity)
                        correct_rarity = true;
                }
                for(const auto& p : loot_bag){
                    if(p->getName() == p_name){
                        p->addQuantity(rand_amount);
                        repeated = true;
                        break;
                    }
                }
                if(!repeated){
                    std::shared_ptr<Item> new_potion = std::make_shared<Item>(shopList[p_name]);
                    new_potion->setQuantity(rand_amount);
                    new_potion->setId(rsHandler->generateId());
                    loot_bag.push_back(std::move(new_potion));
                }
            }
        }
    }

    if(print_result){
        stringstream ss;
        ss << "-------------------------Floor " << floor << "-------------------------" << endl;
        ss << "Drop count: " << drop_count << endl;
        ss << "Material: " << loot_type_count[0] << endl;
        ss << "        1 piece: " << material_piece_count[0] << endl;
        ss << "        2 pieces: " << material_piece_count[1] << endl;
        ss << "        3 pieces: " << material_piece_count[2] << endl;
        ss << "        4 pieces: " << material_piece_count[3] << endl;
        ss << "        5 pieces: " << material_piece_count[4] << endl;
        ss << "        6 pieces: " << material_piece_count[5] << endl;
        ss << "        7 pieces: " << material_piece_count[6] << endl;
        ss << "        8 pieces: " << material_piece_count[7] << endl;
        int tot_count = 0;
        for(int i = 0 ; i < 5 ; i++){
            if(material_rarity_count[i] > 0){
                ss << "        " << getRarityString(static_cast<item_rarity>(i+1)) << ": "
                << material_rarity_count[i] << endl;
                tot_count += material_rarity_count[i];
            }
        }
        ss << "        Tot: " << tot_count << endl;
        ss << "Consumable: " << loot_type_count[1] << endl;
        ss << "        1 piece: " << potion_piece_count[0] << endl;
        ss << "        2 pieces: " << potion_piece_count[1] << endl;
        ss << "        3 pieces: " << potion_piece_count[2] << endl;
        ss << "        4 pieces: " << potion_piece_count[3] << endl;
        ss << "        5 pieces: " << potion_piece_count[4] << endl;
        ss << "        6 pieces: " << potion_piece_count[5] << endl;
        for(auto i : potions)
            ss << "        " << getRarityString(static_cast<item_rarity>(i.first)) << ": " << i.second << endl;
        ss << "        Tot: " << potion_rarity_count[0] + potion_rarity_count[1] + potion_rarity_count[2] << endl;
        ss << "Weapon: " << loot_type_count[2] << endl;
        ss << "Shield: " << loot_type_count[3] << endl;
        ss << "Helmet: " << loot_type_count[4] << endl;
        ss << "Chestplate: " << loot_type_count[5] << endl;
        ss << "Gloves: " << loot_type_count[6] << endl;
        ss << "Boots: " << loot_type_count[7] << endl;
        ss << "Nothing: " << loot_type_count[8] << endl;
        ss << "Tot equipment: " << loot_type_count[2] + loot_type_count[3] + loot_type_count[4] + loot_type_count[5] +
                                          loot_type_count[6] + loot_type_count[7] << endl;
        ss << "        Uncommon: " << equip_rarity_count[0] << endl;
        ss << "        Common: " << equip_rarity_count[1] << endl;
        ss << "        Rare: " << equip_rarity_count[2] << endl;
        ss << "        Epic: " << equip_rarity_count[3] << endl;
        ss << "        Legendary: " << equip_rarity_count[4] << endl;
        ss << "        Tot: " << equip_rarity_count[0] + equip_rarity_count[1] + equip_rarity_count[2] +
                                        equip_rarity_count[3] + equip_rarity_count[4] << endl;
        ss << "LootBag("<< loot_bag.size() << "): " << endl;
        if(print_lootbag){
            for(const auto& i : loot_bag)
                ss << i->listItem(true) << endl;
        }
        ss << "-------------------------End-Floor " << floor << "-End-------------------------" << endl;
        std::cout << ss.str();
    }

    return loot_bag;
}

Item *LootGenerator::getMaterialByEnemyType(enemy_types type) {
    std::string loot_name;
    switch (type) {
        case WITCH:
            loot_name = "Witch's notes";
            break;
        case SKELETON:
            loot_name = "Piece of bone";
            break;
        case SKELETON_2:
            loot_name = "Sharp tooth";
            break;
        case FLYING_EYE:
            loot_name = "Eyeball";
            break;
        case GOBLIN:
            loot_name = "Crab's claw";
            break;
        case MUSHROOM:
            loot_name = "Snail's shell";
            break;
        case BANDIT_HEAVY:
            loot_name = "Golden coin";
            break;
        case BANDIT_LIGHT:
            loot_name = "Silver coin";
            break;
    }
    for(auto &i : droppableMaterials){
        if(i->getName() == loot_name)
            return i.get();
    }
    return nullptr;
}

std::string LootGenerator::getRarityString(item_rarity rarity_enum) {
    switch (rarity_enum) {
        case UNCOMMON:
            return "Uncommon";
        case COMMON:
            return "Common";
        case RARE:
            return "Rare";
        case EPIC:
            return "Epic";
        case LEGENDARY:
            return "Legendary";
        case DEFAULT_RARITY:
        default:
            return "Default";
    }
}

std::string LootGenerator::getRarityString(loot_rarity rarity_enum) {
    switch (rarity_enum) {
        case UNCOMMON_LOOT:
            return "Uncommon";
        case COMMON_LOOT:
            return "Common";
        case RARE_LOOT:
            return "Rare";
        case EPIC_LOOT:
            return "Epic";
        case LEGENDARY_LOOT:
            return "Legendary";
        default:
            return "Default";
    }
}

std::shared_ptr<Item> LootGenerator::generateTierEquipment(item_rarity equip_rarity, bool random_rarity, loot_type item_type) {
    loot_type loot_type_enum;
    int random_value;
    if(item_type == NO_LOOT){
        random_value = utils::generateRandomNumber(lootProbabilities[1], lootProbabilities[7]);
        int starting_loot_type = 2;
        //si scorre il loot finche non troppa il range giusto
        while (lootProbabilities[starting_loot_type] < random_value)
            starting_loot_type++;
        loot_type_enum = static_cast<loot_type>(starting_loot_type);
    }else{
        loot_type_enum = item_type;
    }
    std::string equip_type;
    switch (loot_type_enum) {
        case WEAPON_LOOT: {
            int n = utils::generateRandomNumber(0, 2);
            switch (n) {
                case 0:
                    equip_type = "W-sword";
                    break;
                case 1:
                    equip_type = "W-axe";
                    break;
                case 2:
                    equip_type = "W-bow";
                    break;
                default:
                    equip_type = "W-sword";
                    break;
            }
        }
        case SHIELD_LOOT: {
            if(equip_type.empty())
                equip_type = "E-shield";
        }
        case HELMET_LOOT: {
            if(equip_type.empty())
                equip_type = "E-head";
        }
        case CHESTPLATE_LOOT: {
            if(equip_type.empty())
                equip_type = "E-chest";
        }
        case GLOVES_LOOT: {
            if(equip_type.empty())
                equip_type = "E-arms";
        }
        case BOOTS_LOOT: {
            if(equip_type.empty())
                equip_type = "E-legs";

            auto loot_rarity_enum = static_cast<loot_rarity>(equip_rarity - 1);
            if(random_rarity){
                // genera il numero per determinare la rarita dell'equipaggiamento
                random_value = utils::generateRandomNumber(1, MAX_RARITY_PROBABILITY);
                int starting_loot_rarity = 0;
                // la probabilita varia a seconda del piano(floor)
                while (lootRarityProbabilities5[starting_loot_rarity] < random_value)
                    starting_loot_rarity++;
                loot_rarity_enum = static_cast<loot_rarity>(starting_loot_rarity);
            }
            //prende un nome a caso dal file txt
            ifstream file;
            ifstream file_desc;
            if(unitTesting){
                file.open("../../Data/Equipment names/" + equip_type.substr(2) + ".txt");
                file_desc.open("../../Data/random descriptions.txt");
            }else{
                file.open("../Data/Equipment names/" + equip_type.substr(2) + ".txt");
                file_desc.open("../Data/random descriptions.txt");
            }
            if (!file.is_open()) {
                cout << "Resource load error: Could not load name .txt";
            } else if(!file_desc.is_open()){
                cout << "Resource load error: Could not load random descriptions.txt";
            } else {
                std::string names;
                std::vector<std::string> lines;
                int total_lines=0;
                while(getline(file, names)){
                    total_lines++;
                    lines.push_back(names);
                }

                int random_line = utils::generateRandomNumber(0, total_lines - 1);
                std::string item_name = lines[random_line];
                std::shared_ptr<Item> new_equip = std::make_shared<Item>();
                new_equip->setItemType(equip_type);
                new_equip->setName(item_name);
                new_equip->setRarity(getRarityString(loot_rarity_enum));
                new_equip->setId(rsHandler->generateId());
                new_equip->updateUsageType();
                new_equip->setQuantity(1);
                //genera l'icona per l'oggetto
                switch(new_equip->getUsageType()){
                    case LEGS_USAGE:{
                        int array_size = sizeof(bootsIntRects)/sizeof(bootsIntRects[0]) - 1;
                        int random_index = utils::generateRandomNumber(0, array_size);
                        new_equip->setIconRectX(bootsIntRects[random_index].first);
                        new_equip->setIconRectY(bootsIntRects[random_index].second);
                        break;
                    }
                    case ARMS_USAGE:{
                        int array_size = sizeof(glovesIntRects)/sizeof(glovesIntRects[0]) - 1;
                        int random_index = utils::generateRandomNumber(0, array_size);
                        new_equip->setIconRectX(glovesIntRects[random_index].first);
                        new_equip->setIconRectY(glovesIntRects[random_index].second);
                        break;
                    }
                    case CHEST_USAGE:{
                        int array_size = sizeof(chestIntRects)/sizeof(chestIntRects[0]) - 1;
                        int random_index = utils::generateRandomNumber(0, array_size);
                        new_equip->setIconRectX(chestIntRects[random_index].first);
                        new_equip->setIconRectY(chestIntRects[random_index].second);
                        break;
                    }
                    case HEAD_USAGE:{
                        int array_size = sizeof(helmetIconIntRects)/sizeof(helmetIconIntRects[0]) - 1;
                        int random_index = utils::generateRandomNumber(0, array_size);
                        new_equip->setIconRectX(helmetIconIntRects[random_index].first);
                        new_equip->setIconRectY(helmetIconIntRects[random_index].second);
                        break;
                    }
                    case SHIELD_USAGE:{
                        int array_size = sizeof(shieldIconIntRects)/sizeof(shieldIconIntRects[0]) - 1;
                        int random_index = utils::generateRandomNumber(0, array_size);
                        new_equip->setIconRectX(shieldIconIntRects[random_index].first);
                        new_equip->setIconRectY(shieldIconIntRects[random_index].second);
                        break;
                    }
                    case WEAPON_USAGE:{
                        if(new_equip->getWeaponType() == "sword"){
                            int array_size = sizeof(swordIconIntRects)/sizeof(swordIconIntRects[0]) - 1;
                            int random_index = utils::generateRandomNumber(0, array_size);
                            new_equip->setIconRectX(swordIconIntRects[random_index].first);
                            new_equip->setIconRectY(swordIconIntRects[random_index].second);
                        }else if(new_equip->getWeaponType() == "axe"){
                            int array_size = sizeof(axeIconIntRects)/sizeof(axeIconIntRects[0]) - 1;
                            int random_index = utils::generateRandomNumber(0, array_size);
                            new_equip->setIconRectX(axeIconIntRects[random_index].first);
                            new_equip->setIconRectY(axeIconIntRects[random_index].second);
                        }else if(new_equip->getWeaponType() == "bow"){
                            int array_size = sizeof(bowIconIntRects)/sizeof(bowIconIntRects[0]) - 1;
                            int random_index = utils::generateRandomNumber(0, array_size);
                            new_equip->setIconRectX(bowIconIntRects[random_index].first);
                            new_equip->setIconRectY(bowIconIntRects[random_index].second);
                        }
                        break;
                    }
                    case CONSUMABLE_USAGE: case MATERIAL_USAGE: case DEFAULT_USAGE:
                        break;
                }

                //genera in modo randomico gli effetti dell'arma
                std::vector<equip_effect> effects;
                int effect_amount = utils::generateRandomNumber(statsAmount[loot_rarity_enum].first,
                                                                statsAmount[loot_rarity_enum].second);
                effects.reserve(effect_amount);
                switch(new_equip->getUsageType()){
                    case LEGS_USAGE:
                    case ARMS_USAGE:
                    case CHEST_USAGE:
                    case HEAD_USAGE:
                    case SHIELD_USAGE:
                        effects.push_back(ADD_ARMOR);
                        effect_amount--;
                        break;
                    case WEAPON_USAGE:
                        effects.push_back(ADD_DAMAGE);
                        effect_amount--;
                        break;
                    case CONSUMABLE_USAGE: case MATERIAL_USAGE: case DEFAULT_USAGE:
                        break;
                }
                while(effect_amount > 0){
                    bool repeated = false;
                    auto random_effect = static_cast<equip_effect>(utils::generateRandomNumber(0 ,5));
                    for(auto app : effects){
                        if(app == random_effect){
                            repeated = true;
                            break;
                        }
                    }
                    if(!repeated){
                        effect_amount--;
                        effects.push_back(random_effect);
                    }
                }
                for(auto app : effects){
                    switch (app) {
                        case ADD_HP:{
                            int value = utils::generateRandomNumber(hpRange[loot_rarity_enum].first,
                                                                    hpRange[loot_rarity_enum].second);
                            new_equip->setHp(value);
                            break;
                        }
                        case ADD_MP:{
                            int value = utils::generateRandomNumber(mpRange[loot_rarity_enum].first,
                                                                    mpRange[loot_rarity_enum].second);
                            new_equip->setMp(value);
                            break;
                        }
                        case ADD_DAMAGE:{
                            int value = utils::generateRandomNumber(damageRange[loot_rarity_enum].first,
                                                                    damageRange[loot_rarity_enum].second);
                            new_equip->setDamage(value);
                            break;
                        }
                        case ADD_ARMOR:{
                            int value;
                            if(new_equip->getUsageType() == SHIELD_USAGE){
                                value = utils::generateRandomNumber(shieldArmorRange[loot_rarity_enum].first,
                                                                    shieldArmorRange[loot_rarity_enum].second);
                            }else{
                                value = utils::generateRandomNumber(armorRange[loot_rarity_enum].first,
                                                                    armorRange[loot_rarity_enum].second);
                            }
                            new_equip->setArmor(value);
                            break;
                        }
                        case ADD_CRITCHANCE:{
                            float valuef = utils::generateRandomNumberf(critchanceRange[loot_rarity_enum].first,
                                                                        critchanceRange[loot_rarity_enum].second, 2);
                            new_equip->setCritChance(valuef);
                            break;
                        }
                        case ADD_EVADECHANCE:{
                            float valuef = utils::generateRandomNumberf(evadechanceRange[loot_rarity_enum].first,
                                                                        evadechanceRange[loot_rarity_enum].second, 2);
                            new_equip->setEvadeChance(valuef);
                            break;
                        }
                    }
                }
                //calcola il valore dell'oggetto
                float base_value = (float)new_equip->getHp() / 5.f + (float)new_equip->getHp() / 5.f +
                                   (float)new_equip->getDamage() * 5.f + (float)new_equip->getArmor() * 5.f +
                                   new_equip->getCritChance() * 10.f + new_equip->getEvadeChance() * 10.f;
                switch(new_equip->getRarityEnum()){
                    case UNCOMMON:{
                        base_value *= 1.5f;
                        break;
                    }
                    case COMMON:{
                        base_value *= 2.f;
                        break;
                    }
                    case RARE:{
                        base_value *= 2.5f;
                        break;
                    }
                    case EPIC:{
                        base_value *= 3.f;
                        break;
                    }
                    case LEGENDARY:{
                        base_value *= 3.5f;
                        break;
                    }
                    case DEFAULT_RARITY: default:
                        break;
                }
                new_equip->setValue(std::ceil(base_value));

                //genera la descrizione per l'oggetto
                if(new_equip->getUsageType() == SHIELD_USAGE){
                    stringstream ss;
                    ss << "Reduces " << new_equip->getArmor() << " % of damage when raised(Defensive mode).";
                    new_equip->setDescription(ss.str());
                }else{
                    std::string descs;
                    lines.clear();
                    total_lines = 0;
                    while(getline(file_desc, descs)){
                        total_lines++;
                        lines.push_back(descs);
                    }
                    random_line = utils::generateRandomNumber(0, total_lines - 1);
                    std::string desc = lines[random_line];
                    new_equip->setDescription(desc);
                }

                file_desc.close();
                file.close();
                return new_equip;
            }
            break;
        }
        case NO_LOOT: case MATERIAL_LOOT: case COMSUMABLE_LOOT:
            break;
    }
    return nullptr;
}


