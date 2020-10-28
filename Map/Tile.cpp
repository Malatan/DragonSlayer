#include "Tile.h"

const float Tile::TILE_SIZE = 120.0f;

Tile::Tile(float cx, float cy, int type, bool traversable) {
    this->cx = cx;
    this->cy = cy;
    this->type = type;
    this->traversable = traversable;

    this->shape = sf::RectangleShape(sf::Vector2f(Tile::TILE_SIZE, Tile::TILE_SIZE));
    this->shape.setPosition(sf::Vector2f((cx - (Tile::TILE_SIZE / 2)), (cy - (Tile::TILE_SIZE / 2))));
    this->shape.setFillColor((type == 0)?(sf::Color::White):(sf::Color::Blue));
    this->shape.setOutlineColor(sf::Color::Red);
    this->shape.setOutlineThickness(-1.f);
}

Tile::~Tile() {

}

char Tile::GetType() {
    return this->type;
}

void Tile::SetType(int type) {
    this->type = type;
    if(type == 0) {
        this->traversable = true;
        this->shape.setFillColor(sf::Color::White);
    } else {
        this->traversable = false;
        this->shape.setFillColor(sf::Color::Blue);
    }
}


void Tile::SetType(char type){
    this->type = type;
    switch (type) {
        case ' ': {
            this->traversable = true;
            this->shape.setFillColor(sf::Color::White);
            break;
        }
        case '.':{
            this->traversable = false;
            this->shape.setFillColor(sf::Color::Black);
            break;
        }
        case '#':{
            this->traversable = false;
            this->shape.setFillColor(sf::Color::Blue);
            break;
        }
        case '+':{
            this->traversable = false;
            this->shape.setFillColor(sf::Color::Green);
            break;
        }
        case '-':{
            this->traversable = true;
            break;
        }
        case '<':{
            this->traversable = false;
            this->shape.setFillColor(sf::Color::Yellow);
            break;
        }
        case '>':{
            this->traversable = false;
            this->shape.setFillColor(sf::Color::Red);
            break;
        }
        case ',':{
            this->traversable = true;
            this->shape.setFillColor(sf::Color::White);
            break;
        }
    }
}

bool Tile::IsTraversable() {
    return this->traversable;
}

const sf::FloatRect Tile::getGlobalBounds() const
{
    return this->shape.getGlobalBounds();
}

const bool Tile::intersects(const sf::FloatRect bounds) const
{
    return this->shape.getGlobalBounds().intersects(bounds);
}

void Tile::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}
