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
struct IntTile{
    types type;
    int y;
    int x;
};

class Map {
private:
    GameState *gState;
    int height;
    int width;
    bool hasTexture;
    bool interacting;
    IntTile intTile{};
    std::vector<sf::Vector2f> floorsPos{};

    //Culling
    int fromX{};
public:
    const vector<sf::Vector2f> &getFloorsPos() const;

    void setFloorsPos(const vector<sf::Vector2f> &floorsPos);

private:
    int toX{};
    int fromY{};
    int toY{};



private:
    sf::Texture texture;
    sf::Texture interactableTexture;


public:
    Map(int height, int width, State *state);

    virtual ~Map();

    std::vector<std::vector<Tile *> > tiles;

    std::string printMap();

    void updateCollision(const std::shared_ptr<Player>& entity) const;

    void updateTileCollision(const std::shared_ptr<Player>& entity, const float &dt);

    void drawTiles(sf::RenderWindow *window) const;

    void setWallType();

    const std::vector<std::vector<Tile *>> &getTiles() const;

    void render(sf::RenderTarget *target, const std::shared_ptr<Player>& entity, sf::Shader* shader = NULL, const sf::Vector2f playerPosition = sf::Vector2f());

    sf::IntRect getRandomFloorTexture();

    bool isHasTexture() const;

    void setHasTexture(bool hasTexture);

    void setTexture();

    sf::Vector2f findStairs();

    IntTile getIntTile() const;

    void setIntTile(IntTile intTile);

    bool isInteracting() const;

    void setInteracting(bool interacting);

    void openDoor(int y, int x);

};

#endif