
#include "Map.h"
#include "Tile.h"


Map::Map(int height, int width, State *state) {
    this->gState = dynamic_cast<GameState *>(state);
    hasTexture = false;
    texture.loadFromFile("../Resources/Images/Map/Dungeon2.png");
    interactableTexture.loadFromFile("../Resources/Images/chat.png");


    this->height = height;
    this->width = width;
    this->tiles.resize(height);
    for (int i = 0; i < height; i++) {
        this->tiles.at(i).resize(width);
    }

    for (int r = 0; r < this->tiles.size(); r++) {
        for (int c = 0; c < this->tiles.at(r).size(); c++) {
            this->tiles[r][c] = new Tile(((c * Tile::TILE_SIZE) + (Tile::TILE_SIZE / 2)),
                                         ((r * Tile::TILE_SIZE) + (Tile::TILE_SIZE / 2)), false);
        }
    }
}


Map::~Map() {

}

void Map::updateCollision(std::shared_ptr<Player> entity) {

    //World Bounds
    if (entity->getPosition().x < 0.f) {
        // entity->stopVelocity();
        // entity->setSpritePositon(entity->getMovementComponent()->getPreviousPosition());
        entity->setPosition(0.0f, entity->getPosition().y);
    } else if (entity->getPosition().x + entity->getGlobalBounds().width > (this->width * Tile::TILE_SIZE)) {
        //  entity->setPosition(((float)this->width * Tile::TILE_SIZE) - entity->getGlobalBounds().width, entity->getPosition().y);
        entity->stopVelocity();
        entity->setSpritePositon(entity->getMovementComponent()->getPreviousPosition());
    }
    if (entity->getPosition().y < 0.f) {
        //  entity->setPosition(entity->getPosition().x, 0.f);
        entity->stopVelocity();
        entity->setSpritePositon(entity->getMovementComponent()->getPreviousPosition());
    } else if (entity->getPosition().y + entity->getGlobalBounds().height > (this->height * Tile::TILE_SIZE)) {
        //  entity->setPosition(entity->getPosition().x, ((float)this->height * Tile::TILE_SIZE) - entity->getGlobalBounds().height);
        entity->stopVelocity();
        entity->setSpritePositon(entity->getMovementComponent()->getPreviousPosition());
    }

    //Tiles

}

bool Map::isHasTexture() const {
    return hasTexture;
}

void Map::setHasTexture(bool hasTexture) {
    Map::hasTexture = hasTexture;
}


void Map::updateTileCollision(std::shared_ptr<Player> entity, const float &dt) {


    this->fromX = entity->getGridPosition().x - 1;
    if (this->fromX < 0)
        this->fromX = 0;
    else if (this->fromX > this->width)
        this->fromX = this->width;

    this->toX = entity->getGridPosition().x + 3;
    if (this->toX < 0)
        this->toX = 0;
    else if (this->toX > this->width)
        this->toX = this->width;

    this->fromY = entity->getGridPosition().y - 1;
    if (this->fromY < 0)
        this->fromY = 0;
    else if (this->fromY > this->height)
        this->fromY = this->height;

    this->toY = entity->getGridPosition().y + 3;
    if (this->toY < 0)
        this->toY = 0;
    else if (this->toY > this->height)
        this->toY = this->height;

    for (int y = this->fromY; y < this->toY; y++) {
        for (int x = this->fromX; x < this->toX; x++) {
            //TILES
            sf::FloatRect playerBounds = entity->getCollisionBoxComponent()->getCollisionEllipse().getGlobalBounds();
            sf::FloatRect playerHitbox = entity->getHitboxComponent()->getGlobalBounds();
            sf::FloatRect wallBounds = this->tiles[y][x]->getGlobalBounds();
            sf::FloatRect nextPositionBounds = entity->getNextPositionBounds(dt);
            if (!this->tiles[y][x]->IsTraversable() && this->tiles[y][x]->intersects(playerBounds)) {

                entity->stopVelocity();
                entity->setSpritePositon(entity->getMovementComponent()->getPreviousPosition());

            }
            if (this->tiles[y][x]->isInteractable() && this->tiles[y][x]->intersects(playerHitbox) ) {
                this->tiles[y][x]->enableInteract(true);
            }
            else {
                this->tiles[y][x]->enableInteract(false);
            }
        }
    }
}


void Map::drawTiles(sf::RenderWindow *window) {
    for (int r = 0; r < this->height; r++) {
        for (int c = 0; c < this->width; c++) {
            //this->tiles[r][c]->Draw(window);
        }
    }
}

const std::vector<std::vector<Tile *>> &Map::getTiles() const {
    return tiles;
}

std::string Map::printMap() {
    std::stringstream ss;
    for (int r = 0; r < this->height; r++) {
        for (int c = 0; c < this->width; c++) {
            ss << this->tiles[r][c]->GetType();
        }
        ss << "\n";
    }

    return ss.str();
}

void Map::render(sf::RenderTarget *target) {
    for (int r = 0; r < this->height; r++) {
        for (int c = 0; c < this->width; c++) {
            this->tiles[r][c]->render(target);
        }
    }

}


void Map::setWallType() {
    bool floorFound = false;
    for (int r = 0; r < this->tiles.size(); r++) {
        for (int c = 0; c < this->tiles.at(r).size(); c++) {
            if (tiles[r][c]->GetType() == WALL) {
                floorFound = false;
                if (r > 0 && (tiles[r - 1][c]->GetType() == FLOOR || tiles[r - 1][c]->GetType() == CLOSEDOOR)) {
                    tiles[r][c]->changeType(UPPERWALL);
                    tiles[r][c]->setDown(true);
                    floorFound = true;
                }
                if (r < tiles.size() - 1 &&
                    (tiles[r + 1][c]->GetType() == FLOOR || tiles[r + 1][c]->GetType() == CLOSEDOOR)) {
                    tiles[r][c]->changeType(UPPERWALL);
                    tiles[r][c]->setUp(true);
                    floorFound = true;
                }
                if (c < tiles.at(r).size() - 1 &&
                    (tiles[r][c + 1]->GetType() == FLOOR || tiles[r][c + 1]->GetType() == CLOSEDOOR)) {
                    tiles[r][c]->setLeft(true);
                    floorFound = true;
                }
                if (c > 0 && (tiles[r][c - 1]->GetType() == FLOOR || tiles[r][c - 1]->GetType() == CLOSEDOOR)) {
                    tiles[r][c]->setRight(true);
                    floorFound = true;
                }
                if (!floorFound && tiles[r][c + 1]->GetType() == WALL) {
                    tiles[r][c]->setLeft(true);
                    floorFound = true;
                }
                if (!floorFound && tiles[r][c - 1]->GetType() == UPPERWALL) {
                    tiles[r][c]->setRight(true);
                }
            }
        }
    }
}


sf::IntRect Map::getRandomFloorTexture() {
    int width;
    int height;
    width = utils::generateRandomNumber(1, 77);
    height = utils::generateRandomNumber(1, 45);
    return sf::IntRect(width, height, 50, 50);
}


void Map::setTexture() {
    Tile *tile;
    types type;
    for (int r = 0; r < this->tiles.size(); r++) {
        for (int c = 0; c < this->tiles.at(r).size(); c++) {
            type = tiles[r][c]->GetType();
            switch (type) {
                case UPPERWALL: {

                }
                case WALL: {
                    tile = tiles[r][c];
                    if ((tile->isUp() && !tile->isDown() && !tile->isLeft() && !tile->isRight()) ||
                        (tile->isUp() && tile->isDown() && tile->isLeft() && !tile->isRight()) ||
                        (tile->isUp() && tile->isDown() && !tile->isLeft() && tile->isRight()) ||
                        (tile->isUp() && tile->isDown() && !tile->isLeft() && !tile->isRight())) {
                        tiles[r][c]->setTileTexture(&texture, sf::IntRect(0, 134, 64, 64));
                    }
                        //DOWN WALL
                    else if (!tile->isUp() && tile->isDown() && !tile->isLeft() && !tile->isRight()) {
                        tiles[r][c]->setTileTexture(&texture, sf::IntRect(0, 134, 64, 64));
                    }
                        //LEFT WALL
                    else if (!tile->isUp() && !tile->isDown() && tile->isLeft() && !tile->isRight()) {
                        tiles[r][c]->setTileTexture(&texture, sf::IntRect(64, 134, 64, 64));
                    }
                        //RIGHT WALL
                    else if (!tile->isUp() && !tile->isDown() && !tile->isLeft() && tile->isRight()) {
                        tiles[r][c]->setTileTexture(&texture, sf::IntRect(0, 198, 64, 64));
                    }
                        //LEFT RIGHT WALL
                    else if (!tile->isUp() && !tile->isDown() && tile->isLeft() && tile->isRight()) {
                        tiles[r][c]->setTileTexture(&texture, sf::IntRect(128, 134, 64, 64));
                    }
                        //TOP LEFT WALL
                    else if (tile->isUp() && !tile->isDown() && tile->isLeft() && !tile->isRight()) {
                        tiles[r][c]->setTileTexture(&texture, sf::IntRect(320, 134, 64, 64));
                    }
                        //TOP RIGHT WALL
                    else if (tile->isUp() && !tile->isDown() && !tile->isLeft() && tile->isRight()) {
                        tiles[r][c]->setTileTexture(&texture, sf::IntRect(192, 134, 64, 64));
                    }
                        //TOP RIGHT LEFT WALL
                    else if (tile->isUp() && !tile->isDown() && tile->isLeft() && tile->isRight()) {
                        tiles[r][c]->setTileTexture(&texture, sf::IntRect(256, 134, 64, 64));
                    }
                        //DOWN LEFT WALL
                    else if (!tile->isUp() && tile->isDown() && tile->isLeft() && !tile->isRight()) {
                        tiles[r][c]->setTileTexture(&texture, sf::IntRect(320, 198, 64, 64));
                    }
                        //DOWN RIGHT WALL
                    else if (!tile->isUp() && tile->isDown() && !tile->isLeft() && tile->isRight()) {
                        tiles[r][c]->setTileTexture(&texture, sf::IntRect(192, 198, 64, 64));
                    }
                        //DOWN RIGHT LEFT WALL
                    else if (!tile->isUp() && tile->isDown() && tile->isLeft() && tile->isRight()) {
                        tiles[r][c]->setTileTexture(&texture, sf::IntRect(256, 198, 64, 64));
                    }
                    break;
                }
                case FLOOR: {
                    tiles[r][c]->setTileTexture(&texture, getRandomFloorTexture());
                    break;
                }
                case UPSTAIRS: {
                    tiles[r][c]->setTileTexture(&texture, sf::IntRect(625, 35, 50, 50));
                    break;
                }
                case DOWNSTAIRS: {
                    tiles[r][c]->setTileTexture(&texture, sf::IntRect(625, 103, 50, 50));
                    break;
                }
                case CLOSEDOOR: {
                    if (tiles[r + 1][c]->GetType() == FLOOR) {
                        tiles[r][c]->setTileTexture(&texture, sf::IntRect(487, 105, 50, 50));
                    } else if (tiles[r][c - 1]->GetType() == FLOOR) {
                        tiles[r][c]->setTileTexture(&texture, sf::IntRect(487, 35, 50, 50));
                    }
                    break;
                }
                case OPENDOOR: {
                    if (tiles[r + 1][c]->GetType() == FLOOR) {
                        tiles[r][c]->setTileTexture(&texture, sf::IntRect(555, 105, 50, 50));
                    } else if (tiles[r][c - 1]->GetType() == FLOOR) {
                        tiles[r][c]->setTileTexture(&texture, sf::IntRect(555, 35, 50, 50));
                    }
                    break;
                }
                case GRASS: {
                    tiles[r][c]->setTileTexture(&texture, sf::IntRect(0, 270, 70, 70));
                    break;
                }
                case GROUND: {
                    tiles[r][c]->setTileTexture(&texture, sf::IntRect(200, 320, 50, 50));
                    break;
                }
                case WALLH: {
                    tiles[r][c]->setTileTexture(&texture, sf::IntRect(110, 270, 48, 48));
                    break;
                }
                case DOORH: {
                    tiles[r][c]->setTileTexture(&texture, sf::IntRect(251, 320, 48, 48));
                    tiles[r][c]->setInteract(sf::RectangleShape(sf::Vector2f(20.f, 20.f)));
                    tiles[r][c]->setInteractTexture(&interactableTexture);
                    break;
                }
                case TREES: {
                    tiles[r][c]->setTileTexture(&texture, sf::IntRect(299, 320, 50, 50));
                    break;
                }
                case COLUMNS: {
                    tiles[r][c]->setTileTexture(&texture, sf::IntRect(100, 322, 48, 48));
                    break;
                }
                case COLUMND: {
                    tiles[r][c]->setTileTexture(&texture, sf::IntRect(146, 370, 48, 48));
                    break;
                }
                case CHURCH: {
                    tiles[r][c]->setTileTexture(&texture, sf::IntRect(0, 370, 50, 50));
                    break;
                }
                case SHOPH: {
                    tiles[r][c]->setTileTexture(&texture, sf::IntRect(0, 420, 50, 50));
                    break;
                }
                case ROOFL: {
                    tiles[r][c]->setTileTexture(&texture, sf::IntRect(51, 420, 50, 50));
                    break;
                }
                case ROOFD: {
                    tiles[r][c]->setTileTexture(&texture, sf::IntRect(75, 420, 50, 50));
                    break;
                }
                case ROOF: {
                    tiles[r][c]->setTileTexture(&texture, sf::IntRect(63, 420, 50, 50));
                    break;
                }
                default: {
                }
            }
        }
    }
}
