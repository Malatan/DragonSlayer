#ifndef DRAGONSLAYER_MAPGENERATOR_H
#define DRAGONSLAYER_MAPGENERATOR_H

#include "Map.h"

class Map;

class MapGenerator {
private:
    GameState* gameState;

public:

    MapGenerator();
    virtual ~MapGenerator();

    Map* GenerateFromFile(std::string path, int height, int width, State* state);
    Map* GenerateHub(std::string path, int height, int width, State* state);
};

#endif
