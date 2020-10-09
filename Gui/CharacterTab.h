//
// Created by Zheng on 08/10/2020.
//

#ifndef DRAGONSLAYER_CHARACTERTAB_H
#define DRAGONSLAYER_CHARACTERTAB_H

#include "Gui.h"

class CharacterTab {
private:
    sf::Font* font;
    sf::Text tabText;

    sf::RectangleShape backgorund;
    sf::RectangleShape container;

    sf::RectangleShape equipContainer;
    sf::RectangleShape inventoryContainer;
    sf::RectangleShape attributesContainer;

protected:

public:
    CharacterTab(sf::RenderWindow& window, sf::Font* font);
    virtual ~CharacterTab();

    //accessor

    //functions
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);
};


#endif //DRAGONSLAYER_CHARACTERTAB_H
