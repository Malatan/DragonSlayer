//
// Created by Zheng on 06/10/2020.
//

#ifndef DRAGONSLAYER_MAINMENUSTATE_H
#define DRAGONSLAYER_MAINMENUSTATE_H

#include "State.h"
#include "GameState.h"
#include "../Gui/gui.h"

class MainMenuState : public State {
private:
    //variables
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, gui::Button*> buttons;

    //functions
    void initVariables();
    void initBackground();
    void initFonts();
    void initButtons();
protected:


public:
    MainMenuState(sf::RenderWindow *window, std::stack<State*>* states, ResourcesHandler* rsHandler, sf::Event* sfEvent);
    virtual ~MainMenuState();

    //functions
    void startNewGame();
    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);

};


#endif //DRAGONSLAYER_MAINMENUSTATE_H
