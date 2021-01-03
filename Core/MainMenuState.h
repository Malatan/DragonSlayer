//
// Created by Zheng on 06/10/2020.
//

#ifndef DRAGONSLAYER_MAINMENUSTATE_H
#define DRAGONSLAYER_MAINMENUSTATE_H

#include "GameState.h"

class MainMenuState : public State {
public:
    MainMenuState(std::shared_ptr<sf::RenderWindow> window, std::stack<std::unique_ptr<State>>* states,
                  std::shared_ptr<ResourcesHandler> rsHandler, state_enum _state_enum);
    ~MainMenuState() override;

    //functions
    void startGame();
    void updateButtons();
    void renderButtons(sf::RenderTarget& target);
    void updateInput(const float& dt) override;
    void update(const float& dt) override;
    void render(sf::RenderTarget* target) override;

private:
    //variables
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Text versionLbl;
    sf::Font font;
    std::map<std::string, gui::Button> buttons;
    std::shared_ptr<LoadSaveTab> loadSaveTab;
    state_tab stateTab;
    std::shared_ptr<PopUpTextComponent> popUpTextComponent;

    //loading screen
    bool loading{};
    sf::RectangleShape loadingBackground;
    sf::Text textLbl;

    //functions
    void initResources();
    void initLoadingScreen();
    void initBackground();
    void initButtons();
    void initLoadSaveTab();
    void initComponents();
};


#endif //DRAGONSLAYER_MAINMENUSTATE_H
