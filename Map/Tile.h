#ifndef DRAGONSLAYER_TILE_H
#define DRAGONSLAYER_TILE_H

#include <SFML/Graphics.hpp>
#include "../Core/Common.h"
#include "string"

enum types{
    FLOOR,
    WALL,
    VOID,
    OPENDOOR,
    CLOSEDOOR,
    UPSTAIRS,
    DOWNSTAIRS,
    UPPERWALL,
    LEFTWALL,
    RIGHTWALL,
    BOTTOMWALL,
    GRASS,
    GROUND,
    CART,
    CHURCH,
    STAIRSH,
    WALLH,
    DOORH,
    TREES,
    COLUMNS,
    COLUMND,
    SHOPH,
    ROOFL,
    ROOFD,
    ROOF
};

class Tile {
private:
    friend class PathFinder;
    float cx, cy;
    int gridX;
    int gridY;
    types type;
    bool traversable;
    bool up;
    bool down;
    bool right;
    bool left;
    sf::IntRect rTexture;
    bool interactable{};
    sf::Sprite shape;
    sf::RectangleShape interact;
    sf::RectangleShape rect;

public:
    static const float TILE_SIZE;

    //constructors/destructor
    Tile(float cx, float cy, bool traversable);
    virtual ~Tile();

    //GETTERS AND SETTERS
    types GetType();
    void SetType(char new_type);
    void changeType(types new_type);
    void setTileTexture(const sf::Texture *texture, sf::IntRect intRect);
    sf::FloatRect getGlobalBounds() const;
    bool IsTraversable() const;
    void setTraversable(bool b);
    bool isInteractable() const;
    void setInteractable(bool b);
    bool isUp() const;
    void setUp(bool b);
    bool isDown() const;
    void setDown(bool b);
    bool isRight() const;
    void setRight(bool b);
    bool isLeft() const;
    void setLeft(bool b);
    void setInteract(const sf::RectangleShape &_interact);
    void setInteractTexture(const sf::Texture *texture);
    void enableInteract(bool enable);
    float getCx() const;
    float getCy() const;
    bool isTraversable() const;

    int getGridX() const;

    int getGridY() const;

    //function
    bool intersects(sf::FloatRect bounds) const;
    void render(sf::RenderTarget* target, sf::Shader* shader = nullptr, sf::Vector2f player_position = sf::Vector2f());
    void renderF(sf::RenderTarget* target);
};

#endif