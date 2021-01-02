
#include "Map.h"

Map::Map(int height, int width, State *state) {
    this->gState = dynamic_cast<GameState *>(state);
    interacting = false;
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
            this->tiles[r][c] = new Tile((((float)c * Tile::TILE_SIZE) + (Tile::TILE_SIZE / 2)),
                                         (((float)r * Tile::TILE_SIZE) + (Tile::TILE_SIZE / 2)), false);
        }
    }
}


Map::~Map() = default;

//GETTERS AND SETTERS
bool Map::isHasTexture() const {
    return hasTexture;
}

void Map::setHasTexture(bool hasTexture) {
    Map::hasTexture = hasTexture;
}

const std::vector<std::vector<Tile *>> &Map::getTiles() const {
    return tiles;
}

bool Map::isInteracting() const {
    return interacting;
}

void Map::setInteracting(bool interacting) {
    Map::interacting = interacting;
}

IntTile Map::getIntTile() const {
    return intTile;
}

void Map::setIntTile(IntTile intTile) {
    Map::intTile = intTile;
}


//FUNCTIONS
void Map::updateCollision(const std::shared_ptr<Player>& entity) const {

    //World Bounds
    if (entity->getPosition().x < 0.f) {
        // entity->stopVelocity();
        // entity->setSpritePositon(entity->getMovementComponent()->getPreviousPosition());
        entity->setPosition(0.0f, entity->getPosition().y);
    } else if (entity->getPosition().x + entity->getGlobalBounds().width > ((float)width * Tile::TILE_SIZE)) {
        //  entity->setPosition(((float)this->width * Tile::TILE_SIZE) - entity->getGlobalBounds().width, entity->getPosition().y);
        entity->stopVelocity();
        entity->setSpritePositon(entity->getMovementComponent()->getPreviousPosition());
    }
    if (entity->getPosition().y < 0.f) {
        //  entity->setPosition(entity->getPosition().x, 0.f);
        entity->stopVelocity();
        entity->setSpritePositon(entity->getMovementComponent()->getPreviousPosition());
    } else if (entity->getPosition().y + entity->getGlobalBounds().height > ((float)height * Tile::TILE_SIZE)) {
        //  entity->setPosition(entity->getPosition().x, ((float)this->height * Tile::TILE_SIZE) - entity->getGlobalBounds().height);
        entity->stopVelocity();
        entity->setSpritePositon(entity->getMovementComponent()->getPreviousPosition());
    }

    //Tiles

}

void Map::updateTileCollision(const std::shared_ptr<Player>& entity, const float &dt) {

    bool flag = false;
    this->fromX = entity->getGridPosition().x - 2;
    if (this->fromX < 0)
        this->fromX = 0;
    else if (this->fromX > this->width)
        this->fromX = this->width;

    this->toX = entity->getGridPosition().x + 4;
    if (this->toX < 0)
        this->toX = 0;
    else if (this->toX > this->width)
        this->toX = this->width;

    this->fromY = entity->getGridPosition().y - 2;
    if (this->fromY < 0)
        this->fromY = 0;
    else if (this->fromY > this->height)
        this->fromY = this->height;

    this->toY = entity->getGridPosition().y + 4;
    if (this->toY < 0)
        this->toY = 0;
    else if (this->toY >= this->height)
        this->toY = this->height;

    for (int y = this->fromY; y < this->toY; y++) {
        for (int x = this->fromX; x < this->toX; x++) {
            //TILES
            sf::FloatRect playerBounds = entity->getCollisionBoxComponent()->getCollisionEllipse().getGlobalBounds();
            sf::FloatRect playerHitbox = entity->getHitboxComponent()->getGlobalBounds();
            if (!this->tiles[y][x]->IsTraversable() && this->tiles[y][x]->intersects(playerBounds)) {

                entity->stopVelocity();
                entity->setSpritePositon(entity->getMovementComponent()->getPreviousPosition());

            }
            if (this->tiles[y][x]->isInteractable()) {
                if (this->tiles[y][x]->intersects(playerHitbox)) {
                    this->tiles[y][x]->enableInteract(true);
                    flag = true;
                    intTile.type = tiles[y][x]->GetType();
                    intTile.y = y;
                    intTile.x = x;
                } else {
                    this->tiles[y][x]->enableInteract(false);
                }
            }
        }
    }
    interacting = flag;
}

void Map::drawTiles(sf::RenderWindow *window) const {
    for (int r = 0; r < this->height; r++) {
        for (int c = 0; c < this->width; c++) {
            //this->tiles[r][c]->Draw(window);
        }
    }
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

void Map::setWallType() {
    bool floorFound = false;
    for (int r = 0; r < this->tiles.size(); r++) {
        for (int c = 0; c < this->tiles.at(r).size(); c++) {
            if (tiles[r][c]->GetType() == WALL) {
                floorFound = false;
                if (r > 0 && (tiles[r - 1][c]->GetType() == FLOOR || tiles[r - 1][c]->GetType() == CLOSEDOOR ||
                              tiles[r - 1][c]->GetType() == OPENDOOR)) {
                    tiles[r][c]->changeType(UPPERWALL);
                    tiles[r][c]->setDown(true);
                    floorFound = true;
                }
                if (r < tiles.size() - 1 &&
                    (tiles[r + 1][c]->GetType() == FLOOR || tiles[r + 1][c]->GetType() == CLOSEDOOR ||
                     tiles[r + 1][c]->GetType() == OPENDOOR)) {
                    tiles[r][c]->changeType(UPPERWALL);
                    tiles[r][c]->setUp(true);
                    floorFound = true;
                }
                if (c < tiles.at(r).size() - 1 &&
                    (tiles[r][c + 1]->GetType() == FLOOR || tiles[r][c + 1]->GetType() == CLOSEDOOR ||
                     tiles[r][c + 1]->GetType() == OPENDOOR)) {
                    tiles[r][c]->setLeft(true);
                    floorFound = true;
                }
                if (c > 0 && (tiles[r][c - 1]->GetType() == FLOOR || tiles[r][c - 1]->GetType() == CLOSEDOOR ||
                              tiles[r][c - 1]->GetType() == OPENDOOR)) {
                    tiles[r][c]->setRight(true);
                    floorFound = true;
                }
                if (c == tiles[r].size() - 1) {
                    tiles[r][c]->setRight(true);
                } else if (c == 0) {
                    tiles[r][c]->setLeft(true);
                } else {
                    if (!floorFound && tiles[r][c + 1]->GetType() == WALL) {
                        tiles[r][c]->setLeft(true);
                    }
                    if (!floorFound && tiles[r][c - 1]->GetType() == UPPERWALL) {
                        tiles[r][c]->setRight(true);
                    }
                }

            }
        }
    }
    for (int r = 0; r < this->tiles.size(); r++) {
        for (int c = 0; c < this->tiles.at(r).size(); c++) {
            if ((tiles[r][c]->isLeft() &&
                 !tiles[r][c]->isRight() &&
                 !tiles[r][c]->isUp() &&
                 !tiles[r][c]->isDown()) &&
                (c > 0 && tiles[r][c - 1]->GetType() == UPPERWALL))
                tiles[r][c]->setRight(true);

            if ((!tiles[r][c]->isLeft() &&
                 tiles[r][c]->isRight() &&
                 !tiles[r][c]->isUp() &&
                 !tiles[r][c]->isDown()) &&
                (c < tiles.at(r).size() - 1 && tiles[r][c + 1]->GetType() == UPPERWALL))
                tiles[r][c]->setLeft(true);
        }
    }
}

sf::IntRect Map::getRandomFloorTexture() {
    int width;
    int height;
    width = utils::generateRandomNumber(1, 77);
    height = utils::generateRandomNumber(1, 45);
    return {width, height, 50, 50};
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
                    floorsPos.emplace_back(sf::Vector2f{c * Tile::TILE_SIZE, r * Tile::TILE_SIZE});
                    break;
                }
                case UPSTAIRS: {
                    tiles[r][c]->setTileTexture(&texture, sf::IntRect(625, 35, 50, 50));
                    tiles[r][c]->setInteract(sf::RectangleShape(sf::Vector2f(20.f, 20.f)));
                    tiles[r][c]->setInteractTexture(&interactableTexture);
                    break;
                }
                case DOWNSTAIRS: {
                    tiles[r][c]->setTileTexture(&texture, sf::IntRect(625, 103, 50, 50));
                    tiles[r][c]->setInteract(sf::RectangleShape(sf::Vector2f(20.f, 20.f)));
                    tiles[r][c]->setInteractTexture(&interactableTexture);
                    break;
                }
                case CLOSEDOOR: {
                    if (tiles[r + 1][c]->GetType() == FLOOR) {
                        tiles[r][c]->setTileTexture(&texture, sf::IntRect(487, 105, 50, 50));
                    } else if (tiles[r][c - 1]->GetType() == FLOOR) {
                        tiles[r][c]->setTileTexture(&texture, sf::IntRect(487, 35, 50, 50));
                    }
                    tiles[r][c]->setInteract(sf::RectangleShape(sf::Vector2f(20.f, 20.f)));
                    tiles[r][c]->setInteractTexture(&interactableTexture);
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
                case VOID:{
                    tiles[r][c]->setTileTexture(&texture, sf::IntRect(0, 750, 50, 50));
                    break;
                }
                default: {
                }
            }
        }
    }
}


//RENDER
void Map::render(sf::RenderTarget *target, const std::shared_ptr<Player>& entity, sf::Shader* shader, const sf::Vector2f playerPosition) {
    this->fromX = entity->getGridPosition().x - 10;
    if (this->fromX < 0)
        this->fromX = 0;
    else if (this->fromX > this->width)
        this->fromX = this->width;

    this->toX = entity->getGridPosition().x + 10;
    if (this->toX < 0)
        this->toX = 0;
    else if (this->toX > this->width)
        this->toX = this->width;

    this->fromY = entity->getGridPosition().y - 10;
    if (this->fromY < 0)
        this->fromY = 0;
    else if (this->fromY > this->height)
        this->fromY = this->height;

    this->toY = entity->getGridPosition().y + 10;
    if (this->toY < 0)
        this->toY = 0;
    else if (this->toY >= this->height)
        this->toY = this->height;

    for (int y = this->fromY; y < this->toY; y++) {
        for (int x = this->fromX; x < this->toX; x++) {
            this->tiles[y][x]->render(target, shader, playerPosition);
        }
    }
}

sf::Vector2f Map::findStairs() {
    sf::Vector2f pos;
    for (int r = 0; r < this->height; r++) {
        for (int c = 0; c < this->width; c++) {
            if (this->tiles[r][c]->GetType() == DOWNSTAIRS) {
                pos.y = r * Tile::TILE_SIZE;
                pos.x = c * Tile::TILE_SIZE;
            }
        }
    }
    return pos;
}

const vector<sf::Vector2f> &Map::getFloorsPos() const {
    return floorsPos;
}

void Map::setFloorsPos(const vector<sf::Vector2f> &floorsPos) {
    Map::floorsPos = floorsPos;
}

void Map::openDoor(int y, int x) {
    tiles[y][x]->changeType(OPENDOOR);
    tiles[y][x]->setTraversable(true);
    if (tiles[y + 1][x]->GetType() == FLOOR) {
        tiles[y][x]->setTileTexture(&texture, sf::IntRect(555, 105, 50, 50));
    } else if (tiles[y][x - 1]->GetType() == FLOOR) {
        tiles[y][x]->setTileTexture(&texture, sf::IntRect(555, 35, 50, 50));
    }
    tiles[y][x]->setInteractable(false);
}

std::vector<std::pair<int,int>> Map::getOpenDoors() {
    std::vector<std::pair<int,int>> v;
    for (int y = 0; y < tiles.size(); y++) {
        for (int x = 0; x < tiles[y].size(); x++) {
            if(tiles[y][x]->GetType() == OPENDOOR){
                v.emplace_back(y, x);
            }
        }
    }
    return v;
}

void Map::setOpenDoors(vector<std::pair<int, int>> &open_doors) {
    for(auto i : open_doors){
        if(tiles[i.first][i.second]->GetType() == CLOSEDOOR || tiles[i.first][i.second]->GetType() == OPENDOOR){
            openDoor(i.first, i.second);
        }
    }
}



