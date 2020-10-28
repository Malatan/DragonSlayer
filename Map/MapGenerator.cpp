#include "MapGenerator.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

MapGenerator::MapGenerator() {

}

MapGenerator::~MapGenerator() {

}

Map* MapGenerator::GenerateFromFile(std::string path, int height, int width) {
    Map* map = new Map(height, width);
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
    return map;
}
