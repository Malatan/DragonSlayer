//
// Created by Zheng on 19/10/2020.
//

#include "ShopTab.h"

ShopTab::ShopTab(sf::RenderWindow *window, sf::Font *font, Player *player, State *state, ResourcesHandler *rsHandler)
: window(window), font(font), player(player), state(state), rsHandler(rsHandler){
    //init container
    this->container.setSize(sf::Vector2f(
            static_cast<float>(window->getSize().x / 1.1f),
            static_cast<float>(window->getSize().y - 100.f )));
    this->container.setFillColor(sf::Color(20, 20, 20, 200));

    this->container.setPosition(sf::Vector2f(
            static_cast<float>(window->getSize().x) / 2.f - this->container.getSize().x / 2.f,
            40.f));

    //init text
    this->containerTitle.setFont(*this->font);
    this->containerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    this->containerTitle.setCharacterSize(40);
    this->containerTitle.setString("Shop");
    this->containerTitle.setPosition(
            this->container.getPosition().x + (this->container.getGlobalBounds().width/2.f) - (this->containerTitle.getGlobalBounds().width/2.f),
            this->container.getPosition().y + 10.f);
}

ShopTab::~ShopTab() {

}

void ShopTab::update(const sf::Vector2f &mousePos) {

}

void ShopTab::render(sf::RenderTarget &target) {
    target.draw(this->container);
    target.draw(this->containerTitle);
}


