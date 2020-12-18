#include "MapGenerator.h"
#include "Dungeon.h"


MapGenerator::MapGenerator() {
    wh d = wh{0, 0};
    for (int i = 0; i <= 5; i++) {
        dDims.push_back(d);
    }
    dDims[0].height = 11;
    dDims[0].width = 29;
}

MapGenerator::~MapGenerator() {

}

Map *MapGenerator::GenerateFromFile(int floor, State *state) {
    this->gameState = dynamic_cast<GameState *>(state);
    Map *map = new Map(dDims[floor].height, dDims[floor].width, state);
    std::fstream fin;
    char ch;
    switch(floor){
        case 0:{
            fin = std::fstream("../Data/Hub.txt", std::fstream::in);
            break;
        }
        case 1:{
            fin = std::fstream("../Data/Dungeon_1.txt", std::fstream::in);
            break;
        }
        case 2:{
            fin = std::fstream("../Data/Dungeon_2.txt", std::fstream::in);
            break;
        }
        case 3:{
            fin = std::fstream("../Data/Dungeon_3.txt", std::fstream::in);
            break;
        }
        case 4:{
            fin = std::fstream("../Data/Dungeon_4.txt", std::fstream::in);
            break;
        }
        case 5:{
            fin = std::fstream("../Data/Dungeon_5.txt", std::fstream::in);
            break;
        }
    }
    int i = 0;
    int k = 0;
    while (fin >> std::noskipws >> ch) {
        if (i < dDims[floor].width) {
            map->tiles.at(k).at(i)->SetType(ch);
            i++;
        } else {
            k++;
            i = 0;
        }
    }

        map->setWallType();
    map->setTexture();
    return map;
}

void MapGenerator::generateDungeon(int n) {
    int width;
    int height;
    width = utils::generateRandomNumber(40, 60);
    height = utils::generateRandomNumber(40, 60);
    Dungeon d = Dungeon(width, height);
    d.generate(50);
    switch (n) {
        case 1: {
            d.writeOnFile("../Data/Dungeon_1.txt");
            break;
        }
        case 2: {
            d.writeOnFile("../Data/Dungeon_2.txt");
            break;
        }
        case 3: {
            d.writeOnFile("../Data/Dungeon_3.txt");
            break;
        }
        case 4: {
            d.writeOnFile("../Data/Dungeon_4.txt");
            break;
        }
        case 5: {
            d.writeOnFile("../Data/Dungeon_5.txt");
            break;
        }
    }
    dDims[n].width = width;
    dDims[n].height = height;
}

const vector<wh> &MapGenerator::getDDims() const {
    return dDims;
}

void MapGenerator::setDDims(const vector<wh> &dDims) {
    MapGenerator::dDims = dDims;
}





