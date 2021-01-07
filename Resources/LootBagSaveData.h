//
// Created by Administrator on 01/01/2021.
//

#ifndef DRAGONSLAYER_LOOTBAGSAVEDATA_H
#define DRAGONSLAYER_LOOTBAGSAVEDATA_H

#include "../Game/Item.h"
#include <../includers/CerealHeaders.h>

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
    friend class cereal::access;
    template <class Archive>
    void serialize(Archive & ar){
        ar(id, msCounter, lifeTime, loots, posX, posY);
    }

    unsigned int id{};
    float msCounter{};
    lifeTimePair lifeTime;
    std::vector<Item> loots;
    float posX{};
    float posY{};
};


#endif //DRAGONSLAYER_LOOTBAGSAVEDATA_H
