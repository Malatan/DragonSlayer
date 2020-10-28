#ifndef DRAGONSLAYER_MAP_H
#define DRAGONSLAYER_MAP_H

#include "Tile.h"
#include "../Game/Entity.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Map {
private:
    int height;
    int width;

    //Culling
    int fromX;
    int toX;
    int fromY;
    int toY;


public:
    Map(int heigth, int width);
    virtual ~Map();
    std::vector< std::vector<Tile*> > tiles;

    std::string printMap();

    void updateCollision(Entity * entity);

    void updateTileCollision(Entity * entity, const float & dt);

    void drawTiles(sf::RenderWindow* window);

    const std::vector<std::vector<Tile *>> &getTiles() const;

    void render(sf::RenderTarget* target);

};

#endif