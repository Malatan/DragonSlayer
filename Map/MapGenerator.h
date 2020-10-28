#ifndef DRAGONSLAYER_MAPGENERATOR_H
#define DRAGONSLAYER_MAPGENERATOR_H

#include "Map.h"
#include <vector>


class MapGenerator {
private:


public:

    MapGenerator();
    virtual ~MapGenerator();

    Map* GenerateFromFile(std::string path, int heigth, int width);
};

#endif
