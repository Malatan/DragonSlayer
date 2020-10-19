//
// Created by Zheng on 19/10/2020.
//

#ifndef DRAGONSLAYER_SHOPTAB_H
#define DRAGONSLAYER_SHOPTAB_H

#include "CharacterTab.h"

class ShopTab {
private:
    sf::RectangleShape container;
    sf::Text containerTitle;

    ResourcesHandler* rsHandler;
    sf::RenderWindow* window;
    Player* player;
    State* state;
    sf::Font* font;
protected:

public:
    ShopTab(sf::RenderWindow* window, sf::Font* font, Player* player, State* state, ResourcesHandler* rsHandler);
    virtual ~ShopTab();

    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);
};


#endif //DRAGONSLAYER_SHOPTAB_H
