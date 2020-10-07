//
// Created by Zheng on 07/10/2020.
//

#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow& window, sf::Font* font) : font(font){
    //init background
    this->backgorund.setSize(sf::Vector2f(
            static_cast<float>(window.getSize().x),
            static_cast<float>(window.getSize().y)));
    this->backgorund.setFillColor(sf::Color(20, 20, 20, 100));

    //initi container
    this->container.setSize(sf::Vector2f(
            static_cast<float>(window.getSize().x / 4.f),
            static_cast<float>(window.getSize().y - 100.f )));
    this->container.setFillColor(sf::Color(20, 20, 20, 200));

    this->container.setPosition(sf::Vector2f(
            static_cast<float>(window.getSize().x) / 2.f - this->container.getSize().x / 2.f,
            40.f));

    //init text
    this->menuText.setFont(*font);
    this->menuText.setFillColor(sf::Color(255, 255, 255, 200));
    this->menuText.setCharacterSize(30);
    this->menuText.setString("Game Paused");
    this->menuText.setPosition(
            this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f,
            this->container.getPosition().y + 20.f);
}

PauseMenu::~PauseMenu() {
    auto it = this->buttons.begin();
    for(it = this->buttons.begin(); it != this->buttons.end(); ++it){
        delete it->second;
    }
}

//accessor
std::map<std::string, gui::Button *> &PauseMenu::getButtons() {
    return this->buttons;
}

//functions
const bool PauseMenu::isButtonPressed(const std::string key) {
    return this->buttons[key]->isPressed();
}

void PauseMenu::addButton(const std::string key, float y, const std::string text) {
    float width = 150.f;
    float height = 50.f;
    float center_x = this->container.getPosition().x + this->container.getSize().x / 2.f - width / 2.f;
    this->buttons[key] = new gui::Button(
            center_x, y, width, height,
            this->font, text, 30,
            sf::Color(200, 200, 200, 200),
            sf::Color(250, 250, 250, 250),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(20, 20, 20, 0));
}

void PauseMenu::update(const sf::Vector2f& mousePos) {
    for(auto &i : this->buttons){
        i.second->update(mousePos);
    }
}

void PauseMenu::render(sf::RenderTarget &target) {
    target.draw(this->backgorund);
    target.draw(this->container);

    for(auto &i : this->buttons){
        i.second->render(target);
    }

    target.draw(this->menuText);

}