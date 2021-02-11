#include "MapGenerator.h"

//constructors/destructor
MapGenerator::MapGenerator(State* state) {
    wh d = wh{0, 0};
    for (int i = 0; i <= 6; i++) {
        dDims.push_back(d);
    }
    dDims[0].height = 11;
    dDims[0].width = 17;
    dDims[6].height = 15;
    dDims[6].width = 33;
    gameState = dynamic_cast<GameState *>(state);
}

MapGenerator::~MapGenerator() = default;

//getters/setters
vector<wh> &MapGenerator::getDDims(){
    return dDims;
}

void MapGenerator::setDDims(const vector<pair<int, int>> &data) {
    dDims.clear();
    for(auto i : data){
        dDims.push_back({i.first, i.second});
    }
}

//function
Map *MapGenerator::GenerateFromFile(int floor, State *state) {
    Map *map = new Map(dDims[floor].height, dDims[floor].width, state);
    std::string prefix;
    if(gameState->getResourceHandler()->isUnitTesting()){
        prefix = "../";
    }
    std::fstream fin;
    char ch;
    switch(floor){
        case 0:{
            fin = std::fstream(prefix + "../Data/Hub.txt", std::fstream::in);
            break;
        }
        case 1:{
            fin = std::fstream(prefix + "../Data/Dungeon_1.txt", std::fstream::in);
            break;
        }
        case 2:{
            fin = std::fstream(prefix + "../Data/Dungeon_2.txt", std::fstream::in);
            break;
        }
        case 3:{
            fin = std::fstream(prefix + "../Data/Dungeon_3.txt", std::fstream::in);
            break;
        }
        case 4:{
            fin = std::fstream(prefix + "../Data/Dungeon_4.txt", std::fstream::in);
            break;
        }
        case 5:{
            fin = std::fstream(prefix + "../Data/Dungeon_5.txt", std::fstream::in);
            break;
        }
        case 6:{
            fin = std::fstream(prefix + "../Data/bossroom.txt", std::fstream::in);
            break;
        }
        default:
            break;
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

    fin.close();
    map->setWallType();
    map->setTexture();
    return map;
}

void MapGenerator::generateDungeon(int n) {
    std::string prefix;
    if(gameState->getResourceHandler()->isUnitTesting()){
        prefix = "../";
    }
    int width;
    int height;
    Dungeon d(0,0);

    generateMap:
    width = utils::generateRandomNumber(40, 40);
    height = utils::generateRandomNumber(30, 30);
    d = Dungeon(width, height);
    d.generate(50);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x){
            if(d.getTile(x,y) == ','){
                goto generateMap;
            }
        }
    }

    switch (n) {
        case 1: {
            d.writeOnFile(prefix + "../Data/Dungeon_1.txt");
            break;
        }
        case 2: {
            d.writeOnFile(prefix + "../Data/Dungeon_2.txt");
            break;
        }
        case 3: {
            d.writeOnFile(prefix + "../Data/Dungeon_3.txt");
            break;
        }
        case 4: {
            d.writeOnFile(prefix + "../Data/Dungeon_4.txt");
            break;
        }
        case 5: {
            d.writeOnFile(prefix + "../Data/Dungeon_5.txt");
            break;
        }
        default:
            break;
    }
    dDims[n].width = width;
    dDims[n].height = height;
}







