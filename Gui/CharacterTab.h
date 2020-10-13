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
    sf::RenderWindow* window;
    sf::Font* font;
    Player* player;
    State* state;
    int* updateSlot;
    gui::ConfirmDialog* confirmDialog;
    int selectedItem;

    bool openDialog;

    std::map<std::string, sf::Texture> textures;
    //container
    sf::RectangleShape backgorund;
    sf::RectangleShape container;
    sf::Text tabText;
    sf::Text hpBarLbl;
    sf::Text mpBarLbl;
    sf::Text expBarLbl;
    gui::ProgressBar* hpBar;
    gui::ProgressBar* mpBar;
    gui::ProgressBar* expBar;

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
    sf::Text equipBonusLbl;
    gui::ItemSlot* equipSlots[6];


    //inventory container
    std::vector<gui::ItemSlot*> inventorySlots;
    sf::RectangleShape inventoryContainer;
    sf::Text invContainerTitle;
    sf::Text selectedNumberLbl;
    sf::Text goldLbl;
    sf::Text inventorySpaceLbl;
    gui::Button* EquipUnEquipBtn;
    gui::Button* deleteBtn;

protected:

public:
    CharacterTab(sf::RenderWindow* window, sf::Font* font, Player* player, State* state, map<string, sf::Texture> textures);
    virtual ~CharacterTab();

    //initializers
    void initStatsContainer();
    void initEquipContainer();
    void initInventoryContainer();
    void initInventorySlots();

    //accessor
    gui::ItemSlot** getEquipSlots();
    const vector<gui::ItemSlot *> &getInventorySlots() const;

    //functions
    std::string playerStatsToString();

    void unselectAll();
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
