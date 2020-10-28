#ifndef DRAGONSLAYER_TILE_H
#define DRAGONSLAYER_TILE_H

#include <SFML/Graphics.hpp>
#include "string"

class Tile {
private:
    float cx, cy;
    char type;
    bool traversable;

    sf::RectangleShape shape;

public:
    static const float TILE_SIZE;

    Tile(float cx, float cy, int type, bool traversable);
    virtual ~Tile();

    char GetType();
    void SetType(int type);
    void SetType(char type);

    const sf::FloatRect getGlobalBounds() const;
    const bool intersects(const sf::FloatRect bounds) const;
    void render(sf::RenderTarget* target);

    bool IsTraversable();
};

#endif