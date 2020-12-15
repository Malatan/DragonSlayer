#ifndef DRAGONSLAYER_MAP_H
#define DRAGONSLAYER_MAP_H

#include "Tile.h"
#include "../Game/Entity.h"
#include "../Core/GameState.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"
#include "ctime"
#include "../Game/Utils.h"


class Map {
private:
    GameState* gState;
    int height;
    int width;
    bool hasTexture;
    bool interacting;
    types intTile;

    //Culling
    int fromX;
    int toX;
    int fromY;
    int toY;
    sf::Texture texture;
    sf::Texture interactableTexture;


public:
    Map(int height, int width, State* state);
    virtual ~Map();
    std::vector< std::vector<Tile*> > tiles;

    std::string printMap();

    void updateCollision(std::shared_ptr<Player> entity);

    void updateTileCollision(std::shared_ptr<Player> entity, const float & dt);

    void drawTiles(sf::RenderWindow* window);

    void setWallType();

    const std::vector<std::vector<Tile *>> &getTiles() const;

    void render(sf::RenderTarget* target);

    sf::IntRect  getRandomFloorTexture();

    bool isHasTexture() const;

    void setHasTexture(bool hasTexture);

    void setTexture();


};

#endif