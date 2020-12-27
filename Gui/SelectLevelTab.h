


#ifndef DRAGONSLAYER_SELECTLEVELTAB_H
#define DRAGONSLAYER_SELECTLEVELTAB_H


#include "../Map/MapGenerator.h"
#include "ShopTab.h"

class GameState;

class SelectLevelTab {
public:
    SelectLevelTab(const std::shared_ptr<sf::RenderWindow>& window, sf::Font* font, std::shared_ptr<Player> player, State *state,
              std::shared_ptr<ResourcesHandler> rsHandler);
    ~SelectLevelTab();

    void initButtons();

    bool closeTabByClicking(const sf::Vector2f& mousePos);
    void buttonFunctions(short unsigned btnId);
    void updateButtons();
    void updateInputs();
    void updateButtonsAccess(int reached_floor);
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);
    bool isHide() const;
    void setHide(bool b);

private:

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
    bool hide{};

    std::unique_ptr<gui::Button> level1Btn;          // id = 0
    std::unique_ptr<gui::Button> level2Btn;          // id = 1
    std::unique_ptr<gui::Button> level3Btn;          // id = 2
    std::unique_ptr<gui::Button> level4Btn;          // id = 3
    std::unique_ptr<gui::Button> level5Btn;          // id = 4
};


#endif //DRAGONSLAYER_SELECTLEVELTAB_H
