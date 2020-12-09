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
    float cx, cy;
    types type;
    bool traversable;
    bool up;
    bool down;
    bool right;
    bool left;
    sf::IntRect rTexture;
    bool interactable;
    sf::RectangleShape shape;
    sf::RectangleShape interact;
public:
    bool isInteractable() const;

    void setInteractable(bool interactable);

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

     sf::RectangleShape &getInteract();

    void setInteract(const sf::RectangleShape &interact);
    void setInteractTexture(const sf::Texture *texture);
    void enableInteract(bool enable);

    //RENDERING
    void render(sf::RenderTarget* target);


};

#endif