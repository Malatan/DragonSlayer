#ifndef DRAGONSLAYER_MAPGENERATOR_H
#define DRAGONSLAYER_MAPGENERATOR_H

#include "Map.h"
class Map;

struct wh{
    int width;
    int height;
};

class MapGenerator {
public:
    //constructors/destructor
    MapGenerator(State* state);
    virtual ~MapGenerator();

    //getters/setters
    vector<wh> &getDDims();
    void setDDims(const vector<pair<int, int>>& data);

    //function
    Map* GenerateFromFile(int floor, State* state);
    void generateDungeon(int n);

private:
    std::vector<wh> dDims;
    GameState* gameState{};
};

#endif
