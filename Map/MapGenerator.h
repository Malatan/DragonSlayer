#ifndef DRAGONSLAYER_MAPGENERATOR_H
#define DRAGONSLAYER_MAPGENERATOR_H

#include "Map.h"
class Map;

struct wh{
    int width;
    int height;
};

class MapGenerator {
private:
    std::vector<wh> dDims;
    wh hDims;
    GameState* gameState;

public:
    const vector<wh> &getDDims() const;

    void setDDims(const vector<wh> &dDims);

    MapGenerator();
    virtual ~MapGenerator();
    Map* GenerateFromFile(int floor, State* state);
    Map* GenerateHub(std::string path, int height, int width, State* state);
    void generateDungeon(int n);
};

#endif
