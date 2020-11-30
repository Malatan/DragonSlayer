#include "MapGenerator.h"


MapGenerator::MapGenerator() {

}

MapGenerator::~MapGenerator() {

}

Map* MapGenerator::GenerateFromFile(std::string path, int height, int width, State* state) {
    this->gameState = dynamic_cast<GameState*>(state);
    Map* map = new Map(height, width, state);
    char ch;
    std::fstream fin(path, std::fstream::in);
    int i=0;
    int k=0;
    while (fin >> std::noskipws >> ch) {
        if(i < width) {
            //std::cout << ch;
            map->tiles.at(k).at(i)->SetType(ch);
            i++;
        }
        else{
            k++;
            i=0;
        }
    }
    map->setWallType();
    map->setWallTextures();
    map->setRandomFloorTexture();
    map->setDoorTexture();
    map->setStairsTexture();
    return map;
}
