//
// Created by Zheng on 25/12/2020.
//

#include "Save.h"

#include <utility>

//constructors/destructor
Save::Save() = default;

Save::Save(std::string name, std::string modified_time, std::string game_version)
        : name(std::move(name)), lastModifiedTime(std::move(modified_time)), gameVersion(std::move(game_version)){

}

Save::~Save() = default;

//accessors/modifiers
std::string Save::getName() const {
    return name;
}

std::string Save::getLastModifiedTime() const {
    return lastModifiedTime;
}

void Save::setSaveImage(const sf::Image &save_image) {
    Save::saveImage = save_image;
}

void Save::loadSaveImage() {
    if(!saveImage.loadFromFile(imagePath)){
        std::cerr << name << " missing save image" << endl;
        if(!saveImage.loadFromFile("../Resources/Images/dragon.png")){
            std::cerr << " missing default save image" << endl;
        }
    }
}

void Save::setImagePath(const string &path) {
    imagePath = path;
}

//functions
void Save::saveRsHandlerInfo(const shared_ptr<ResourcesHandler> &rshandler_info) {
    rsHandlerIdCounter = rshandler_info->getIdCunter();
}

void Save::savePlayerInfo(const std::shared_ptr<Player>& player_info) {
    playerPosX = player_info->getPosition().x;
    playerPosY = player_info->getPosition().y;
    playerStats = *player_info->getPlayerStats();
    playerInventoryMaxSpace = player_info->getInventory()->getCurrentMaxSpace();
    inventory.clear();
    for(const auto& i : player_info->getInventory()->getItems()){
        inventory.emplace_back(i.get());
    }
    playerGold = player_info->getGold();

    equips.clear();
    player_equip_slot equip_enums[6] = {LEGS_SLOT, ARMS_SLOT, CHEST_SLOT, HEAD_SLOT, SHIELD_SLOT, WEAPON_SLOT};
    for(auto i : equip_enums){
        std::shared_ptr<Item> equip = player_info->getEquippedItem(i);
        if(equip){
            equips.insert(std::pair<player_equip_slot, unsigned int>(i, equip->getId()));
        }else{
            equips.insert(std::pair<player_equip_slot, unsigned int>(i, 0));
        }
    }
}

void Save::saveSpellsInfo(const shared_ptr<SpellComponent> &spell_component) {
    spells.clear();
    for(const auto& i : spell_component->getSpells()){
        spells.push_back(*i);
    }
    playerSpells.clear();
    for(const auto& i : spell_component->getPlayerSpells()){
        playerSpells.push_back(*i);
    }
}

void Save::saveAchievementsInfo(const std::shared_ptr<AchievementComponent> &achievement_component) {
    aeRecords.clear();
    achievements.clear();

    aeRecords = achievement_component->getRecords();
    for(const auto& i : achievement_component->getAchievements()){
        achievements.push_back(*i);
    }
}

void Save::saveBuffsInfo(const shared_ptr<BuffComponent> &buff_component) {
    playerBuffs.clear();
    playerBuffs.reserve(buff_component->getPlayerBuffsList().size());
    for(const auto& i : buff_component->getPlayerBuffsList()){
        playerBuffs.push_back(*i);
    }
}

void Save::saveMapsInfo(const std::shared_ptr<MapGenerator>& mg, Map* map, int current_floor, int reached_floor) {
    for(auto i : mg->getDDims()){
        levelDims.emplace_back(i.width, i.height);
    }
    openedDoors = map->getOpenDoors();
    currentFloor = current_floor;
    reachedFloor = reached_floor;
    floor1 = utils::readFile("../Data/Dungeon_1.txt");
    floor2 = utils::readFile("../Data/Dungeon_2.txt");
    floor3 = utils::readFile("../Data/Dungeon_3.txt");
    floor4 = utils::readFile("../Data/Dungeon_4.txt");
    floor5 = utils::readFile("../Data/Dungeon_5.txt");
}

void Save::saveEnemiesInfo(std::pair<int, int> n, std::vector<std::shared_ptr<Enemy>>& _enemies) {
    enemyCounts = n;
    enemiesLeaders.clear();
    enemiesLeaders.reserve(n.first);
    enemiesFollowers.clear();
    enemiesFollowers.reserve(n.second);
    for(const auto& i : _enemies){
        enemiesLeaders.emplace_back(i->getId(), 0, false, i->getName(),
                             i->getType(), i->getCurrentBoost(), *i->getStats(), i->getPosition().x, i->getPosition().y);
        if(i->getFollowersNumber() > 0){
            for(const auto& j : i->getFollowers()){
                enemiesFollowers.emplace_back(j->getId(), i->getId(), true, j->getName(),
                                     j->getType(), 0, *j->getStats(), 0.f, 0.f);
            }
        }
    }
}

void Save::saveLootBagsInfo(std::vector<std::shared_ptr<LootBag>>& loot_bags) {
    lootBags.clear();
    lootBags.reserve(loot_bags.size());
    for(const auto& i : loot_bags){
        std::vector<Item> v;
        for(const auto& j : i->getLoots()){
            v.push_back(*j);
        }
        lootBags.emplace_back(i->getId(), i->getMsCounter(), i->getLifeTimep(), v, i->getPosition().x, i->getPosition().y);
    }
}

std::string Save::toString() const {
    std::stringstream ss;
    ss << "Name:[" << name << "]"
    << " Time:[" << lastModifiedTime << "]"
    << " Version:[" << gameVersion << "]"
    << " Pos:[" << playerPosX << ", " << playerPosY << "]"
    << " Floor:[" << currentFloor << "]"
    << " Enemy:[" << enemyCounts.first << " + " << enemyCounts.second << "]" << std::endl;
    return ss.str();
}

const sf::Image &Save::getSaveImage() const {
    return saveImage;
}




