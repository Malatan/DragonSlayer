//
// Created by Administrator on 10/10/2020.
//

#include "ResourcesHandler.h"


ResourcesHandler::ResourcesHandler() {

}

ResourcesHandler::~ResourcesHandler() {
    for(auto i : this->resources){
        delete i;
    }
}

bool ResourcesHandler::checkIfKeyExist(std::string key) {
    for(auto i : this->resources){
        if(i->getKey().compare(key) == 0){
            return true;
        }
    }
    return false;
}

void ResourcesHandler::addResouce(Resource *rs) {
    this->resources.push_back(rs);
}


Resource *ResourcesHandler::getResouceByKey(std::string key) {
    for(auto i : this->resources){
        if(i->getKey().compare(key) == 0)
            return i;
    }

    return nullptr;
}

std::string ResourcesHandler::toString() {
    std::string app = "";
    for(auto i : this->resources){
        app += i->toString() + "\n";
    }
    return app;
}

bool ResourcesHandler::loadPlayerStatsTxt(Stats* playerStats) {
    ifstream file;
    file.open("../Data/Stats.txt");
    if (!file.is_open()){
        cout<<"Resource load error: Could not load Stats.txt";
    } else{
        int app;
        file >> app;
        playerStats->setLevel(app);
        file >> app;
        playerStats->setExp(0);
        playerStats->setMaxExp(app);
        file >> app;
        playerStats->setMaxHp(app);
        playerStats->setHp(app);
        file >> app;
        playerStats->setMaxMp(app);
        playerStats->setMp(app);
        file >> app;
        playerStats->setArmor(app);
        file >> app;
        playerStats->setDamage(app);
        file >> app;
        playerStats->setCritChance(app);
        file >> app;
        playerStats->setEvadeChance(app);
        file >> app;
        playerStats->setStrength(app);
        file >> app;
        playerStats->setWisdom(app);
        file >> app;
        playerStats->setAgility(app);
        file >> app;
        playerStats->setFreePoints(app);
    }


    return false;
}





