#ifndef DRAGONSLAYER_MAP_H
#define DRAGONSLAYER_MAP_H

#include "Tile.h"
#include "../Game/Entity.h"
#include "../Core/GameState.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"
#include "ctime"


class Map {
private:
    GameState* gState;
    int height;
    int width;

    //Culling
    int fromX;
    int toX;
    int fromY;
    int toY;
    sf::Texture texture;


public:
    Map(int heigth, int width, State* state);
    virtual ~Map();
    std::vector< std::vector<Tile*> > tiles;

    std::string printMap();

    void updateCollision(std::shared_ptr<Player> entity);

    void updateTileCollision(std::shared_ptr<Player> entity, const float & dt);

    void drawTiles(sf::RenderWindow* window);

    void setWallType();

    void setWallTextures();

    const std::vector<std::vector<Tile *>> &getTiles() const;

    void render(sf::RenderTarget* target);

    void setRandomFloorTexture();

    sf::IntRect  getRandomFloorTexture();

    void setDoorTexture();

    void setStairsTexture();

};

#endif