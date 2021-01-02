#include "Tile.h"

const float Tile::TILE_SIZE = 100.0f;


Tile::Tile(float cx, float cy, bool traversable) {
    this->cx = cx;
    this->cy = cy;
    up = false;
    down = false;
    right = false;
    left = false;
    type = VOID;
    this->traversable = traversable;

  //  shape = sf::Sprite(sf::Vector2f(Tile::TILE_SIZE, Tile::TILE_SIZE));

    shape.setPosition(sf::Vector2f((cx - (Tile::TILE_SIZE / 2)), (cy - (Tile::TILE_SIZE / 2))));
    interact.setPosition(sf::Vector2f((cx - (Tile::TILE_SIZE / 2)), (cy - (Tile::TILE_SIZE / 2))));



}

Tile::~Tile() = default;



void Tile::SetType(char type){
    switch (type) {
        case ' ': {
            this->type = FLOOR;
            traversable = true;
            interactable = false;
            break;
        }
        case '.':{
            this->type = VOID;
            this->traversable = false;
            interactable = false;
          // this->shape.setFillColor(sf::Color::Black);
            break;
        }
        case '#':{
            this->type = WALL;
            this->traversable = false;
            interactable = false;
            break;
        }
        case '+':{
            this->type = CLOSEDOOR;
            this->traversable = false;
            interactable = true;
            break;
        }
        case '-':{
            this->type = OPENDOOR;
            this->traversable = true;
            interactable = true;
            break;
        }
        case '<':{
            this->type = DOWNSTAIRS;
            this->traversable = false;
            interactable = true;
            break;
        }
        case '>':{
            this->type = UPSTAIRS;
            this->traversable = false;
            interactable = true;
            break;
        }
        case ',':{
            this->traversable = true;
            interactable = false;
            break;
        }
        case 'g':{
            this->type = GRASS;
            this->traversable = true;
            interactable = false;
            break;
        }
        case 't':{
            this->type = GROUND;
            this->traversable = true;
            interactable = false;
            break;
        }
        case 'i':{
            this->type = COLUMNS;
            this->traversable = false;
            interactable = false;
            break;
        }
        case 'c':{
            this->type = COLUMND;
            this->traversable = false;
            interactable = false;
            break;
        }
        case 'h':{
            this->type = CHURCH;
            this->traversable = false;
            interactable = false;
            break;
        }
        case 's':{
            this->type = STAIRSH;
            this->traversable = true;
            interactable = false;
            break;
        }
        case 'm':{
            this->type = WALLH;
            this->traversable = false;
            interactable = false;
            break;
        }
        case 'd':{
            this->type = DOORH;
            this->traversable = false;
            interactable = true;
            break;
        }
        case 'a':{
            this->type = TREES;
            this->traversable = false;
            interactable = false;
            break;
        }
        case 'p':{
            this->type = SHOPH;
            this->traversable = false;
            interactable = false;
            break;
        }
        case 'w':{
            this->type = ROOFL;
            this->traversable = false;
            interactable = false;
            break;
        }
        case 'W':{
            this->type = ROOFD;
            this->traversable = false;
            interactable = false;
            break;
        }
        case 'r':{
            this->type = ROOF;
            this->traversable = false;
            interactable = false;
            break;
        }
        default:
            break;
    }
}

bool Tile::IsTraversable() const {
    return this->traversable;
}

sf::FloatRect Tile::getGlobalBounds() const{
    return this->shape.getGlobalBounds();
}

bool Tile::intersects(const sf::FloatRect bounds) const{
    return this->shape.getGlobalBounds().intersects(bounds);
}


void Tile::changeType(types type) {
    this->type = type;
}

void Tile::setTileTexture(const sf::Texture *texture, sf::IntRect intRect) {
    shape.setScale(TILE_SIZE/intRect.width, TILE_SIZE/intRect.height);
    this->shape.setTexture(*texture);
    this->shape.setTextureRect(intRect);
    this->rTexture = intRect;
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

void Tile::render(sf::RenderTarget *target, sf::Shader* shader, const sf::Vector2f player_position) {
    if(shader){
        shader->setUniform("hasTexture", true);
        shader->setUniform("lightPos", player_position);

        target->draw(shape, shader);
    }
    else
        target->draw(shape);
    if (interactable) {
        target->draw(interact);
    }
}

bool Tile::isInteractable() const {
    return interactable;
}

void Tile::setInteractable(bool interactable) {
    Tile::interactable = interactable;
}

sf::RectangleShape &Tile::getInteract()  {
    return interact;
}

void Tile::setInteract(const sf::RectangleShape &interact) {
    Tile::interact = interact;
}

void Tile::setInteractTexture(const sf::Texture *texture) {
    interact.setTexture(texture);
    interact.setPosition(sf::Vector2f(cx, cy));
    interact.setFillColor(sf::Color(60,60,60,100));
}

void Tile::enableInteract(bool enable) {
    if(enable){
        interact.setFillColor(sf::Color::White);
    }
    else{
        interact.setFillColor(sf::Color(60,60,60,100));
    }

}

void Tile::setOutlineColor(sf::Color color) {
   // shape.setOutlineColor(color);

}

void Tile::setOutlineThickness(float f) {
  //  shape.setOutlineThickness(f);
}

void Tile::setTraversable(bool traversable) {
    Tile::traversable = traversable;
}

const sf::Sprite &Tile::getShape() const {
    return shape;
}

types Tile::GetType() {
    return this->type;
}

