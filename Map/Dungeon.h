
#ifndef DRAGONSLAYER_DUNGEON_H
#define DRAGONSLAYER_DUNGEON_H

#include <vector>
#include <iostream>
#include <fstream>
#include "../Game/Utils.h"

struct Rect {
    int x, y;
    int width, height;
};

enum Direction {
    North,
    South,
    West,
    East,
    DirectionCount
};

class Dungeon {
public:
    enum Tile{
        Unused = ' ',
        Floor = '.',
        Corridor = ',',
        Wall = '#',
        ClosedDoor = '+',
        OpenDoor = '-',
        UpStairs = '<',
        DownStairs = '>'
    };

    //constructors/destructor
    Dungeon(int width, int height);

    //setters/getters
    char getTile(int x, int y) const;
    void setTile(int x, int y, char tile);
    void print() const;
    std::string getGenerationLog() const;

    //functions
    void generate(int maxFeatures);
    void writeOnFile(const std::string& path) const;
    bool createFeature();
    bool createFeature(int x, int y, Direction dir);
    bool makeRoom(int x, int y, Direction dir, bool firstRoom = false);
    bool makeCorridor(int x, int y, Direction dir);
    bool placeRect(const Rect &rect, char tile);
    bool placeObject(char tile);

private:
    int _width, _height;
    std::vector<char> _tiles;
    std::vector<Rect> _rooms; // rooms for place stairs or monsters
    std::vector<Rect> _exits; // 4 sides of rooms or corridors
    std::string generationLog;
};


#endif //DRAGONSLAYER_DUNGEON_H
