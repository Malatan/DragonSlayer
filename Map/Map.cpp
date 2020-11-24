
#include "Map.h"


Map::Map(int height, int width, State* state) {
    this->gState = dynamic_cast<GameState*>(state);

    // Resize the tiles vector according to the width and height of the map.
    this->height = height;
    this->width = width;
    this->tiles.resize(height);
    for(int i = 0; i < height ; i++) {
        this->tiles.at(i).resize(width);
    }

    // Initialize the tiles in the vector.
    for(int r = 0; r < this->tiles.size(); r++) {
        for(int c = 0; c < this->tiles.at(r).size(); c++) {
            this->tiles[r][c] = new Tile(((c * Tile::TILE_SIZE) + (Tile::TILE_SIZE / 2)), ((r * Tile::TILE_SIZE) + (Tile::TILE_SIZE / 2)), 0, false);
        }
    }
}


Map::~Map() {

}

void Map::updateCollision(std::shared_ptr<Player> player){

    //World Bounds
    if(player->getPosition().x < 0.f){
        player->stopVelocity();
        player->setSpritePositon(player->getMovementComponent()->getPreviousPosition());
     //   entity->setPosition(0.0f, entity->getPosition().y);
    }
    else if(player->getPosition().x  + player->getGlobalBounds().width > (this->width * Tile::TILE_SIZE)){
      //  entity->setPosition(((float)this->width * Tile::TILE_SIZE) - entity->getGlobalBounds().width, entity->getPosition().y);
        player->stopVelocity();
        player->setSpritePositon(player->getMovementComponent()->getPreviousPosition());
    }
    if(player->getPosition().y < 0.f){
      //  entity->setPosition(entity->getPosition().x, 0.f);
        player->stopVelocity();
        player->setSpritePositon(player->getMovementComponent()->getPreviousPosition());
    }

    else if(player->getPosition().y + player->getGlobalBounds().height > (this->height * Tile::TILE_SIZE)){
      //  entity->setPosition(entity->getPosition().x, ((float)this->height * Tile::TILE_SIZE) - entity->getGlobalBounds().height);
        player->stopVelocity();
        player->setSpritePositon(player->getMovementComponent()->getPreviousPosition());
    }

    //Tiles
    
}

void Map::updateTileCollision(std::shared_ptr<Player> player, const float & dt) {


    this->fromX = player->getGridPosition().x - 1;
    if (this->fromX < 0)
        this->fromX = 0;
    else if (this->fromX > this->width)
        this->fromX = this->width;

    this->toX = player->getGridPosition().x + 3;
    if (this->toX < 0)
        this->toX = 0;
    else if (this->toX > this->width)
        this->toX = this->width;

    this->fromY = player->getGridPosition().y - 1;
    if (this->fromY < 0)
        this->fromY = 0;
    else if (this->fromY > this->height)
        this->fromY = this->height;

    this->toY = player->getGridPosition().y + 3;
    if (this->toY < 0)
        this->toY = 0;
    else if (this->toY > this->height)
        this->toY = this->height;

    for (int y = this->fromY; y < this->toY; y++)
     {
         for (int x = this->fromX; x < this->toX; x++){
            //TILES
            sf::FloatRect playerBounds = player->getCollisionBoxComponent()->getCollisionEllipse().getGlobalBounds();
            sf::FloatRect wallBounds = this->tiles[y][x]->getGlobalBounds();
            sf::FloatRect nextPositionBounds = player->getNextPositionBounds(dt);
           if (!this->tiles[y][x]->IsTraversable() && this->tiles[y][x]->intersects(playerBounds)) {
               /*   //Bottom collision
                  if (playerBounds.top < wallBounds.top
                      && playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
                      && playerBounds.left < wallBounds.left + wallBounds.width
                      && playerBounds.left + playerBounds.width > wallBounds.left
                          ){
                      std::cout<<"bottom \n";
                      entity->stopVelocityY();
                      entity->setPositionY(wallBounds.top - playerBounds.height);
                  }
                  //Top collision
                  else if (playerBounds.top > wallBounds.top
                           && playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
                           && playerBounds.left < wallBounds.left + wallBounds.width
                           && playerBounds.left + playerBounds.width > wallBounds.left
                          ){
                      std::cout<<"top \n";
                      entity->stopVelocityY();
                      entity->setPositionY(wallBounds.top + wallBounds.height);
                  }
                      //Right collision
                  if (playerBounds.left < wallBounds.left
                           && playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
                           && playerBounds.top < wallBounds.top + wallBounds.height
                           && playerBounds.top + playerBounds.height > wallBounds.top
                          ){
                          std::cout << "right \n";
                          entity->stopVelocityX();
                          entity->setPositionX(wallBounds.left - playerBounds.width);
                  }
                  //left collision
                  else if (playerBounds.left > wallBounds.left
                           && playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
                           && playerBounds.top < wallBounds.top + wallBounds.height
                           && playerBounds.top + playerBounds.height > wallBounds.top
                          ){
                          std::cout << "left \n";
                          entity->stopVelocityX();
                          entity->setPositionX(wallBounds.left + wallBounds.width);
                  }*/
               player->stopVelocity();
               player->setSpritePositon(player->getMovementComponent()->getPreviousPosition());
           }
         }
    }


   /* int x = entity->getGridPosition().x;
    int y = entity->getGridPosition().y;

    sf::FloatRect wallBounds = this->tiles[y][x]->getGlobalBounds();
    sf::FloatRect nextPositionBounds = entity->getNextPositionBounds(dt);
    sf::FloatRect playerBounds = entity->getGlobalBounds();

    std::cout<<this->tiles[y+1][x]->getGlobalBounds().top<<"\n";
    std::cout<<"playerPosition: "<<playerBounds.top + playerBounds.height<<"\n";
    std::cout<<"NextPosition: "<<nextPositionBounds.top + nextPositionBounds.height<<"\n";


    if((int)(nextPositionBounds.top + playerBounds.height ) == this->tiles[y+1][x]->getGlobalBounds().top
    && !this->tiles[y+1][x]->IsTraversable()){
        entity->setPosition(0,0);
    }*/
}




void Map::drawTiles(sf::RenderWindow* window) {
    for(int r = 0; r < this->height; r++) {
        for(int c = 0; c < this->width; c++) {
            //this->tiles[r][c]->Draw(window);
        }
    }
}

const std::vector<std::vector<Tile *>> &Map::getTiles() const {
    return tiles;
}

std::string Map::printMap() {
    std::stringstream ss;
    for(int r = 0; r < this->height; r++) {
        for(int c = 0; c < this->width; c++) {
            ss << this->tiles[r][c]->GetType();
        }
        ss << "\n";
    }

    return ss.str();
}

void Map::render(sf::RenderTarget *target) {
    for(int r = 0; r < this->height; r++) {
        for(int c = 0; c < this->width; c++) {
            this->tiles[r][c]->render(target);
        }
    }

}
