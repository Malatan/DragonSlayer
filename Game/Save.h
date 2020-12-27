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

class Save {
public:
    Save();
    Save(std::string  name, std::string modified_time, std::string game_version);
    virtual ~Save();

    void saveRsHandlerInfo(const std::shared_ptr<ResourcesHandler>& rshandler_info);
    void savePlayerInfo(const std::shared_ptr<Player>& player_info);
    std::string toString() const;
private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version){
        ar & name;
        ar & lastModifiedTime;
        ar & rsHandlerIdCounter;
        ar & playerPos;
        ar & playerStats;
        ar & playerGold;
        ar & playerInventoryMaxSpace;
        ar & inventory;
        ar & playerWeapon;
        ar & playerShield;
        ar & playerHead;
        ar & playerChest;
        ar & playerArms;
        ar & playerLegs;
    }

    //save info
    std::string name;
    std::string lastModifiedTime;
    std::string gameVersion;

    //rshandler info
    unsigned int rsHandlerIdCounter{};

    //player info
    sf::Vector2f playerPos;
    Stats playerStats;
    unsigned playerGold{};
    int playerInventoryMaxSpace{};
    std::vector<Item> inventory;
    Item playerWeapon;
    Item playerShield;
    Item playerHead;
    Item playerChest;
    Item playerArms;
    Item playerLegs;

};


#endif //DRAGONSLAYER_SAVE_H
