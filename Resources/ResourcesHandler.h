//
// Created by Administrator on 10/10/2020.
//

#ifndef DRAGONSLAYER_RESOURCESHANDLER_H
#define DRAGONSLAYER_RESOURCESHANDLER_H

#include "Resource.h"
#include "../Game/Stats.h"

class ResourcesHandler {
private:
    std::vector<Resource*> resources;
protected:

public:
    ResourcesHandler();

    virtual ~ResourcesHandler();


    void addResouce(Resource* rs);

    bool loadPlayerStatsTxt(Stats* playerStats);

    std::string toString();
};


#endif //DRAGONSLAYER_RESOURCESHANDLER_H
