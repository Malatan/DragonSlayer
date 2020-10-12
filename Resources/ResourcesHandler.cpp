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

    file.close();
    return true;
}

bool ResourcesHandler::loadPlayerInventoryTxt(Inventory *playerInventory) {
    Item* item;
    ifstream file;
    file.open("../Data/Inventory.txt");
    if (!file.is_open()){
        cout<<"Resource load error: Could not load Inventory.txt";
    } else{
        std::string app;
        while(!file.eof()){
            file >> app;
            item = new Item();
            if(app.at(0) == 'E'){ // equipment
                item->setItemType(app);
                file >> app;
                item->setName(app);
                file >> app;
                item->setDescription(app);
                file >> app;
                item->setValue(std::stoi(app));
                file >> app;
                item->setRarity(app);
                file >> app;
                item->setArmor(std::stoi(app));
                file >> app;
                item->setIconRectX(std::stoi(app));
                file >> app;
                item->setIconRectY(std::stoi(app));

                item->setDamage(0);
                item->setQuantity(1);
                playerInventory->addItem(item);
            } else if(app.at(0) == 'W'){ // weapon
                item->setItemType(app);
                file >> app;
                item->setName(app);
                file >> app;
                item->setDescription(app);
                file >> app;
                item->setValue(std::stoi(app));
                file >> app;
                item->setRarity(app);
                file >> app;
                item->setDamage(std::stoi(app));
                file >> app;
                item->setIconRectX(std::stoi(app));
                file >> app;
                item->setIconRectY(std::stoi(app));


                item->setArmor(0);
                item->setQuantity(1);
                playerInventory->addItem(item);
            } else if(app.at(0) == 'C'){ // consumable
                item->setItemType(app);
                file >> app;
                item->setName(app);
                file >> app;
                item->setDescription(app);
                file >> app;
                item->setValue(std::stoi(app));
                file >> app;
                item->setRarity(app);
                file >> app;
                item->setQuantity(std::stoi(app));
                file >> app;
                item->setIconRectX(std::stoi(app));
                file >> app;
                item->setIconRectY(std::stoi(app));

                item->setArmor(0);
                item->setDamage(0);
                playerInventory->addItem(item);
            }
        }
        if(playerInventory->getItemsSize() > 1){
            playerInventory->sortByItemType();
        }
    }

    return true;
}





