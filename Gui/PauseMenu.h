//
// Created by Zheng on 07/10/2020.
//

#ifndef DRAGONSLAYER_PAUSEMENU_H
#define DRAGONSLAYER_PAUSEMENU_H

#include "Gui.h"

class PauseMenu {
private:
    sf::Font* font;
    sf::Text menuText;

    sf::RectangleShape backgorund;
    sf::RectangleShape container;

    std::map<std::string, gui::Button*> buttons;



protected:

public:
    PauseMenu(sf::RenderWindow& window, sf::Font* font);
    virtual ~PauseMenu();

    //accessor
    std::map<std::string, gui::Button*>& getButtons();

    //functions
    const bool isButtonPressed(const std::string key);
    void addButton(const std::string key, float y, const std::string text);
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);

};


#endif //DRAGONSLAYER_PAUSEMENU_H
