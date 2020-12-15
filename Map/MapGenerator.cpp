#include "MapGenerator.h"
#include "Dungeon.h"


MapGenerator::MapGenerator() {
    wh d = wh{0, 0};
    for (int i = 0; i < 5; i++) {
        dDims.push_back(d);
    }
}

MapGenerator::~MapGenerator() {

}

Map *MapGenerator::GenerateFromFile(std::string path, int height, int width, State *state) {
    this->gameState = dynamic_cast<GameState *>(state);
    Map *map = new Map(height, width, state);
    char ch;
    std::fstream fin(path, std::fstream::in);
    int i = 0;
    int k = 0;
    std::cout<<"prima";
    while (fin >> std::noskipws >> ch) {
        if (i < width) {
            //std::cout << ch;
            map->tiles.at(k).at(i)->SetType(ch);
            i++;
        } else {
            k++;
            i = 0;
        }
    }
    std::cout<<"dopo";
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





