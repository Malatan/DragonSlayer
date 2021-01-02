//
// Created by Zheng on 25/12/2020.
//

#ifndef DRAGONSLAYER_SAVE_H
#define DRAGONSLAYER_SAVE_H

#include <iostream>
#include <sstream>
#include "../Core/GameState.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>

class AchievementComponent;
class BuffComponent;
class MapGenerator;
class EnemySaveData;
class LootBagSaveData;
class LootBag;
class Map;
struct wh;
typedef std::pair<int, int> achievementRecord;

class Save {
public:
    //constructors/destructor
    Save();
    Save(std::string  name, std::string modified_time, std::string game_version);
    virtual ~Save();

    //accessors/modifiers
    std::string getName() const;
    std::string getLastModifiedTime() const;

    //functions
    void saveRsHandlerInfo(const std::shared_ptr<ResourcesHandler>& rshandler_info);
    void savePlayerInfo(const std::shared_ptr<Player>& player_info);
    void saveSpellsInfo(const std::shared_ptr<SpellComponent>& spell_component);
    void saveAchievementsInfo(const std::shared_ptr<AchievementComponent>& achievement_component);
    void saveBuffsInfo(const std::shared_ptr<BuffComponent>& buff_component);
    void saveMapsInfo(const std::shared_ptr<MapGenerator>& mg, Map* map, int current_floor, int reached_floor);
    void saveEnemiesInfo(std::pair<int, int> n, std::vector<std::shared_ptr<Enemy>>& _enemies);
    void saveLootBagsInfo(std::vector<std::shared_ptr<LootBag>>& loot_bags);
    std::string toString() const;

private:
    friend class boost::serialization::access;
    friend class GameState;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version){
        ar & name;
        ar & lastModifiedTime;
        ar & gameVersion;
        ar & rsHandlerIdCounter;
        ar & playerPos;
        ar & playerStats;
        ar & playerGold;
        ar & playerInventoryMaxSpace;
        ar & inventory;
        ar & equips;
        ar & spells;
        ar & playerSpells;
        ar & aeRecords;
        ar & achievements;
        ar & playerBuffs;
        ar & levelDims;
        ar & openedDoors;
        ar & currentFloor;
        ar & reachedFloor;
        ar & floor1;
        ar & floor2;
        ar & floor3;
        ar & floor4;
        ar & floor5;
        ar & enemyCounts;
        ar & enemiesLeaders;
        ar & enemiesFollowers;
        ar & lootBags;
    }

    //save info
    std::string name{};
    std::string lastModifiedTime{};
    std::string gameVersion{};

    //rshandler info
    unsigned int rsHandlerIdCounter{};

    //player info
    sf::Vector2f playerPos;
    Stats playerStats;
    unsigned playerGold{};
    int playerInventoryMaxSpace{};
    std::vector<Item> inventory;
    std::map<player_equip_slot, unsigned int> equips;

    //spells info
    std::vector<Spell> spells;
    std::vector<Spell> playerSpells;

    //achievements info
    std::map<achievement_event, achievementRecord> aeRecords;
    std::vector<Achievement> achievements;

    //buffs info
    std::vector<Buff> playerBuffs;

    //maps info
    std::vector<std::pair<int, int>> levelDims;
    std::vector<std::pair<int, int>> openedDoors;
    int currentFloor{};
    int reachedFloor{};
    std::string floor1;
    std::string floor2;
    std::string floor3;
    std::string floor4;
    std::string floor5;

    //enemies info
    std::pair<int, int> enemyCounts;
    std::vector<EnemySaveData> enemiesLeaders;
    std::vector<EnemySaveData> enemiesFollowers;

    //lootbags info
    std::vector<LootBagSaveData> lootBags;
};


#endif //DRAGONSLAYER_SAVE_H
