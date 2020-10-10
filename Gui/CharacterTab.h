//
// Created by Zheng on 08/10/2020.
//

#ifndef DRAGONSLAYER_CHARACTERTAB_H
#define DRAGONSLAYER_CHARACTERTAB_H

#include "Gui.h"
#include "../Game/Player.h"
#include "../Core/State.h"
#include "../Core/GameState.h"

class CharacterTab {
private:
    sf::Font* font;
    sf::Text tabText;
    Player* player;
    State* state;
    gui::ItemSlot* item;
    sf::Text hpBarLbl;
    sf::Text mpBarLbl;
    sf::Text expBarLbl;
    gui::ProgressBar* hpBar;
    gui::ProgressBar* mpBar;
    gui::ProgressBar* expBar;

    sf::RectangleShape backgorund;
    sf::RectangleShape container;

    //stats container
    sf::RectangleShape statsContainer;
    sf::Text statsContainerTitle;
    sf::Text statsName;
    sf::Text statsValue;
    sf::Text attributesHints;
    gui::Button* addStrengthBtn;
    gui::Button* addWisdomBtn;
    gui::Button* addAgilityBtn;

    //equip container
    sf::RectangleShape equipContainer;
    sf::Text equipContainerTitle;

    //inventory container
    sf::RectangleShape inventoryContainer;
    sf::Text invContainerTitle;

protected:

public:
    CharacterTab(sf::RenderWindow& window, sf::Font* font, Player* player, State* state);
    virtual ~CharacterTab();

    //initializers
    void initStatsContainer(float sizeContainers);
    void initEquipContainer(float sizeContainers);
    void initInventoryContainer(float sizeContainers);

    //accessor

    //functions
    std::string playerStatsToString();
    void statsContainerUpdate(const sf::Vector2f& mousePos);
    void statsContainerRender(sf::RenderTarget& target);
    void equipContainerUpdate(const sf::Vector2f& mousePos);
    void equipContainerRender(sf::RenderTarget& target);
    void invContainerUpdate(const sf::Vector2f& mousePos);
    void invContainerRender(sf::RenderTarget& target);
    bool closeCharacterTabByClicking(const sf::Vector2f& mousePos);
    void updateButtons();
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);

};


#endif //DRAGONSLAYER_CHARACTERTAB_H
