//
// Created by Administrator on 01/01/2021.
//

#include "../Game/Enemy.h"
#include <../includers/CerealHeaders.h>
#include <utility>

#ifndef DRAGONSLAYER_ENEMIESSAVEDATA_H
#define DRAGONSLAYER_ENEMIESSAVEDATA_H


class EnemySaveData {
public:
    //constructor/destructor
    EnemySaveData();
    EnemySaveData(unsigned int _id, unsigned int _leaderId, bool _isFollower, std::string _name, enemy_types _type,
                  int _currentBoost, const Stats &stats, float pos_x, float pos_y);
    virtual ~EnemySaveData();

    //getters/setters
    unsigned int getId() const;
    unsigned int getLeaderId() const;
    bool isFollower1() const;
    const string &getName() const;
    enemy_types getType() const;
    int getCurrentBoost() const;
    const Stats &getStats() const;
    float getPosX() const;
    float getPosY() const;

private:
    friend class cereal::access;
    template <class Archive>
    void serialize(Archive & ar){
        ar(id, leaderId, isFollower, name, type, currentBoost,
           _stats, posX, posY);
    }

    unsigned int id{};
    unsigned int leaderId{};
    bool isFollower{};
    std::string name;
    enemy_types type{};
    int currentBoost{};
    Stats _stats;
    float posX{};
    float posY{};
};


#endif //DRAGONSLAYER_ENEMIESSAVEDATA_H
