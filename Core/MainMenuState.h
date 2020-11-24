//
// Created by Zheng on 06/10/2020.
//

#ifndef DRAGONSLAYER_MAINMENUSTATE_H
#define DRAGONSLAYER_MAINMENUSTATE_H

#include "GameState.h"

class MainMenuState : public State {
public:
    MainMenuState(std::shared_ptr<sf::RenderWindow> window, std::stack<std::unique_ptr<State>>* states,
                  std::shared_ptr<ResourcesHandler> rsHandler);
    virtual ~MainMenuState();

    //functions
    void startNewGame();
    void updateButtons();
    void renderButtons(sf::RenderTarget& target);
    void updateInput(const float& dt) override;
    void update(const float& dt) override;
    void render(sf::RenderTarget* target) override;

private:
    //variables
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;
    std::map<std::string, gui::Button> buttons;

    //functions
    void initVariables();
    void initBackground();
    void initFonts();
    void initButtons();
};


#endif //DRAGONSLAYER_MAINMENUSTATE_H
