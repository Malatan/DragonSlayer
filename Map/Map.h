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
#include "Node.h"

class GameState; 
struct IntTile{
    types type;
    int y;
    int x;
};

class Map {
public:
    //variables
    std::vector<std::vector<Tile *> > tiles;

    //constructors/destructor
    Map(int height, int width, State *state);
    virtual ~Map();

    //getters/setters
    const std::vector<std::vector<Tile *>> &getTiles() const;
    IntTile getIntTile() const;
    std::vector<std::pair<int,int>> getOpenDoors();
    const vector<sf::Vector2f> &getFloorsPos() const;
    static sf::IntRect getRandomFloorTexture();
    int getHeight() const;
    int getWidth() const;
    float getHeightP() const;
    float getWidthP() const;
    int getFromX() const;
    int getToX() const;
    int getFromY() const;
    int getToY() const;
    void setTexture();
    void setIntTile(IntTile int_tile);
    void setOpenDoors(std::vector<std::pair<int,int>>& open_doors);
    void setWallType();
    bool isInteracting() const;

    //function
    sf::Vector2f findStairs();
    void updateCollision(const std::shared_ptr<Player>& entity) const;
    void updateTileCollision(const std::shared_ptr<Player>& entity, const float &dt);
    void openDoor(int y, int x);
    void render(sf::RenderTarget *target, const std::shared_ptr<Player>& entity,
                sf::Shader* shader = nullptr, const sf::Vector2f playerPosition = sf::Vector2f());
    void renderF(sf::RenderTarget *target);

private:
    GameState *gState;
    int height{};
    int width{};
    float heightP{};
    float widthP{};
    bool interacting{};
    IntTile intTile{};
    std::vector<sf::Vector2f> floorsPos{};

    int fromX{};
    int toX{};
    int fromY{};
    int toY{};
    sf::Texture texture;
    sf::Texture interactableTexture;
};

#endif