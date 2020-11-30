#include "Tile.h"

const float Tile::TILE_SIZE = 120.0f;


Tile::Tile(float cx, float cy, bool traversable) {
    this->cx = cx;
    this->cy = cy;
    this->up = false;
    this->down = false;
    this->right = false;
    this->left = false;
    this->type = VOID;
    this->traversable = traversable;

    this->shape = sf::RectangleShape(sf::Vector2f(Tile::TILE_SIZE, Tile::TILE_SIZE));
    this->shape.setPosition(sf::Vector2f((cx - (Tile::TILE_SIZE / 2)), (cy - (Tile::TILE_SIZE / 2))));

   // this->shape.setOutlineColor(sf::Color::Red);
   // this->shape.setOutlineThickness(-1.f);
}

Tile::~Tile() {

}

types Tile::GetType() {
    return this->type;
}

void Tile::SetType(char type){
    switch (type) {
        case ' ': {
            this->type = FLOOR;
            traversable = true;
            shape.setFillColor(sf::Color::White);
            break;
        }
        case '.':{
            this->type = VOID;
            this->traversable = false;
            this->shape.setFillColor(sf::Color::Black);
            break;
        }
        case '#':{
            this->type = WALL;
            this->traversable = false;
            break;
        }
        case '+':{
            this->type = CLOSEDOOR;
            this->traversable = false;
            break;
        }
        case '-':{
            this->type = OPENDOOR;
            this->traversable = true;
            break;
        }
        case '<':{
            this->type = DOWNSTAIRS;
            this->traversable = false;
            break;
        }
        case '>':{
            this->type = UPSTAIRS;
            this->traversable = false;
            break;
        }
        case ',':{
            this->traversable = true;
            break;
        }
    }
}

bool Tile::IsTraversable() {
    return this->traversable;
}

const sf::FloatRect Tile::getGlobalBounds() const{
    return this->shape.getGlobalBounds();
}

const bool Tile::intersects(const sf::FloatRect bounds) const{
    return this->shape.getGlobalBounds().intersects(bounds);
}

void Tile::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}

void Tile::changeType(types type) {
    this->type = type;
}

void Tile::setTileTexture(const sf::Texture *texture, sf::IntRect intRect) {
    this->shape.setTexture(texture);
    this->shape.setTextureRect(intRect);
}

bool Tile::isUp() const {
    return up;
}

void Tile::setUp(bool up) {
    Tile::up = up;
}

bool Tile::isDown() const {
    return down;
}

void Tile::setDown(bool down) {
    Tile::down = down;
}

bool Tile::isRight() const {
    return right;
}

void Tile::setRight(bool right) {
    Tile::right = right;
}

bool Tile::isLeft() const {
    return left;
}

void Tile::setLeft(bool left) {
    Tile::left = left;
}


