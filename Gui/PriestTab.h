//
// Created by Zheng on 22/10/2020.
//

#ifndef DRAGONSLAYER_PRIESTTAB_H
#define DRAGONSLAYER_PRIESTTAB_H

#include "ShopTab.h"

class GameState;

class PriestTab {
public:
    PriestTab(const std::shared_ptr<sf::RenderWindow>& window, sf::Font* font, std::shared_ptr<Player> player, State *state,
              std::shared_ptr<ResourcesHandler> rsHandler, std::map<std::string, sf::Texture> textures);
    virtual ~PriestTab();

    void initButtons();

    bool closeTabByClicking(const sf::Vector2f& mousePos);
    void updateGoldLbl();
    void buttonFunctions(short unsigned btnId);
    void updateButtons();
    void updateInputs();
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);

private:
    static const unsigned int RECOVER_HP_COST = 400;
    static const unsigned int RECOVER_MP_COST = 400;
    static const unsigned int REM_DEBUFFS_COST = 300;
    static const unsigned int RECOVER_ALL_COST = 600;

    sf::RectangleShape background;
    sf::RectangleShape container;
    sf::Text containerTitle;
    std::shared_ptr<sf::RenderWindow> window;
    sf::Font* font;
    std::map<std::string, sf::Texture> textures;
    sf::Text playerGoldLbl;

    std::shared_ptr<ResourcesHandler> rsHandler;
    std::shared_ptr<Player> player;
    GameState* gState;

    std::unique_ptr<gui::Button> restoreHpBtn;          // id = 0
    std::unique_ptr<gui::Button> restoreMpBtn;          // id = 1
    std::unique_ptr<gui::Button> removeAllDebuffsBtn;   // id = 2
    std::unique_ptr<gui::Button> recoverAllBtn;         // id = 3
};


#endif //DRAGONSLAYER_PRIESTTAB_H
