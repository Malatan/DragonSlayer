//
// Created by Zheng on 22/10/2020.
//

#ifndef DRAGONSLAYER_PRIESTTAB_H
#define DRAGONSLAYER_PRIESTTAB_H

#include "ShopTab.h"

class GameState;

class PriestTab {
private:
    sf::RectangleShape background;
    sf::RectangleShape container;
    sf::Text containerTitle;
    sf::RenderWindow* window;
    sf::Font* font;
    std::map<std::string, sf::Texture> textures;
    sf::Text playerGoldLbl;

    ResourcesHandler* rsHandler;
    Player* player;
    State* state;
    GameState* gState;

    gui::Button* restoreHpBtn;          // id = 0
    gui::Button* restoreMpBtn;          // id = 1
    gui::Button* removeAllDebuffsBtn;   // id = 2
    gui::Button* recoverAllBtn;         // id = 3


protected:

public:
    PriestTab(sf::RenderWindow* window, sf::Font* font, Player* player, State *state, ResourcesHandler* rsHandler,
    std::map<std::string, sf::Texture> textures);
    virtual ~PriestTab();

    void initButtons();

    bool closeTabByClicking(const sf::Vector2f& mousePos);
    void updateGoldLbl();
    void buttonFunctions(short unsigned btnId);
    void updateButtons();
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);
};


#endif //DRAGONSLAYER_PRIESTTAB_H
