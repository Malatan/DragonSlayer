//
// Created by Zheng on 07/10/2020.
//

#ifndef DRAGONSLAYER_PAUSEMENU_H
#define DRAGONSLAYER_PAUSEMENU_H

#include "Gui.h"

class PauseMenu {
public:
    PauseMenu();
    PauseMenu(const std::shared_ptr<sf::RenderWindow>& window, sf::Font* font);
    virtual ~PauseMenu();

    //functions
    bool isButtonPressed(const std::string key);
    void addButton(const std::string key, float y, const std::string text, unsigned char_size);
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);

private:
    sf::Font* font;
    sf::Text menuText;
    sf::RectangleShape backgorund;
    sf::RectangleShape container;
    std::map<std::string, gui::Button> buttons;

};


#endif //DRAGONSLAYER_PAUSEMENU_H
