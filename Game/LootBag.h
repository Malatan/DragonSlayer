//
// Created by Administrator on 08/12/2020.
//

#ifndef DRAGONSLAYER_LOOTBAG_H
#define DRAGONSLAYER_LOOTBAG_H

#include "Entity.h"
#include "Item.h"


class LootBag : public Entity  {
public:
    //constructors/destructor
    LootBag(sf::Vector2f position, std::map<std::string, sf::Texture> textures, std::vector<shared_ptr<Item>> loots);
    virtual ~LootBag();

    //functions
    void setPosition(float x, float y) override;
    void update(const float& dt) override;
    void render(sf::RenderTarget& target, bool show_hitbox);

private:
    std::vector<shared_ptr<Item>> loots;
    std::map<std::string, sf::Texture> textures;

};


#endif //DRAGONSLAYER_LOOTBAG_H
