//
// Created by Administrator on 10/10/2020.
//

#ifndef DRAGONSLAYER_RESOURCESHANDLER_H
#define DRAGONSLAYER_RESOURCESHANDLER_H

#include "Resource.h"
#include "../Game/Stats.h"
#include "../Game/Inventory.h"

class ResourcesHandler {
private:
    std::vector<Resource*> resources;
protected:

public:
    ResourcesHandler();

    virtual ~ResourcesHandler();


    bool checkIfKeyExist(std::string key);
    void addResouce(Resource* rs);
    Resource* getResouceByKey(std::string key);

    bool loadPlayerStatsTxt(Stats* playerStats);
    bool loadPlayerInventoryTxt(Inventory* playerInventory);
    std::string toString();
};


#endif //DRAGONSLAYER_RESOURCESHANDLER_H
