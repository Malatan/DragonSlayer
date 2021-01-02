//
// Created by Administrator on 01/01/2021.
//

#ifndef DRAGONSLAYER_LOOTBAGSAVEDATA_H
#define DRAGONSLAYER_LOOTBAGSAVEDATA_H

#include "../Game/Item.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

typedef std::pair<int, int> lifeTimePair;

class LootBagSaveData {
public:
    //constructor/destructor
    LootBagSaveData();
    LootBagSaveData(unsigned int _id, float _msCounter, lifeTimePair _lifeTime, std::vector<Item> _loots, float pos_x,
                    float pos_y);
    virtual ~LootBagSaveData();

    //getters/setters
    unsigned int getId() const;
    float getMsCounter() const;
    const lifeTimePair &getLifeTime() const;
    const vector<Item> &getLoots() const;
    float getPosX() const;
    float getPosY() const;

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version){
        ar & id;
        ar & msCounter;
        ar & lifeTime;
        ar & loots;
        ar & posX;
        ar & posY;
    }

    unsigned int id{};
    float msCounter{};
    lifeTimePair lifeTime;
    std::vector<Item> loots;
    float posX;
    float posY;
};


#endif //DRAGONSLAYER_LOOTBAGSAVEDATA_H
