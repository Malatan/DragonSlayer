//
// Created by Zheng on 07/10/2020.
//

#include "PauseMenu.h"
PauseMenu::PauseMenu()= default;

PauseMenu::PauseMenu(const std::shared_ptr<sf::RenderWindow>& window, sf::Font* font) : font(font){
    //init background
    backgorund.setSize(sf::Vector2f(
            static_cast<float>(window->getSize().x),
            static_cast<float>(window->getSize().y)));
    backgorund.setFillColor(sf::Color(20, 20, 20, 100));

    //initi container
    container.setSize(sf::Vector2f(
            static_cast<float>(window->getSize().x / 4.f),
            static_cast<float>(window->getSize().y - 100.f )));
    container.setFillColor(sf::Color(20, 20, 20, 200));

    container.setPosition(sf::Vector2f(
            static_cast<float>(window->getSize().x) / 2.f - container.getSize().x / 2.f,
            40.f));

    //init text
    menuText.setFont(*font);
    menuText.setFillColor(sf::Color(255, 255, 255, 200));
    menuText.setCharacterSize(30);
    menuText.setString("Game Paused");
    menuText.setPosition(
            container.getPosition().x + container.getSize().x / 2.f - menuText.getGlobalBounds().width / 2.f,
            container.getPosition().y + 20.f);
}

PauseMenu::~PauseMenu() = default;

//functions
bool PauseMenu::isButtonPressed(const std::string& key) {
    return buttons[key].isPressed();
}

void PauseMenu::addButton(const std::string& key, float y, const std::string& text, unsigned char_size) {
    float width = 150.f;
    float height = 50.f;
    float center_x = container.getPosition().x + container.getSize().x / 2.f - width / 2.f;
    buttons[key] = gui::Button(
            center_x, y, width, height,
            font, text, char_size,
            sf::Color(200, 200, 200, 200),
            sf::Color(250, 250, 250, 250),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(20, 20, 20, 0));
}

void PauseMenu::update(const sf::Vector2f& mousePos) {
    for(auto &i : buttons){
        i.second.update(mousePos);
    }
}

void PauseMenu::render(sf::RenderTarget &target) {
    target.draw(backgorund);
    target.draw(container);

    for(auto &i : buttons){
        i.second.render(target);
    }

    target.draw(menuText);

}
