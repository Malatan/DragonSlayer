//
// Created by Zheng on 08/10/2020.
//

#ifndef DRAGONSLAYER_CHARACTERTAB_H
#define DRAGONSLAYER_CHARACTERTAB_H

#include "Gui.h"
#include "../Game/Player.h"

class CharacterTab {
private:
    sf::Font* font;
    sf::Text tabText;
    Player* player;

    sf::RectangleShape backgorund;
    sf::RectangleShape container;

    //stats container
    sf::RectangleShape statsContainer;
    sf::Text statsContainerTitle;
    sf::Text statsName;
    sf::Text statsValue;
    sf::Text attributesHints;

    //equip container
    sf::RectangleShape equipContainer;

    sf::RectangleShape inventoryContainer;


protected:

public:
    CharacterTab(sf::RenderWindow& window, sf::Font* font, Player* player);
    virtual ~CharacterTab();

    //initializers
    void initStatsContainer(float sizeContainers);
    void initEquipContainer(float sizeContainers);
    void initInventoryContainer(float sizeContainers);

    //accessor

    //functions
    std::string playerStatsToString();
    void statsContainerUpdate();
    void statsContainerRender(sf::RenderTarget& target);
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);

};


#endif //DRAGONSLAYER_CHARACTERTAB_H
