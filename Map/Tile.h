#ifndef DRAGONSLAYER_TILE_H
#define DRAGONSLAYER_TILE_H

#include <SFML/Graphics.hpp>
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
};

class Tile {


private:
    float cx, cy;
    types type;
    bool traversable;
    bool up;
    bool down;
    bool right;
    bool left;

    sf::RectangleShape shape;

public:
    static const float TILE_SIZE;

    Tile(float cx, float cy, bool traversable);
    virtual ~Tile();

    //GETTERS AND SETTERS
    types GetType();
    void SetType(char type);
    void changeType(types type);
    void setTileTexture(const sf::Texture *texture, sf::IntRect intRect);
    const sf::FloatRect getGlobalBounds() const;
    const bool intersects(const sf::FloatRect bounds) const;
    bool IsTraversable();

    bool isUp() const;
    void setUp(bool up);
    bool isDown() const;
    void setDown(bool down);
    bool isRight() const;
    void setRight(bool right);
    bool isLeft() const;
    void setLeft(bool left);


    //RENDERING
    void render(sf::RenderTarget* target);


};

#endif