//
// Created by Zheng on 23/10/2020.
//

#include "SpellTab.h"

SpellTab::SpellTab(sf::RenderWindow *window, sf::Font *font, Player *player, State *state, ResourcesHandler *rsHandler,
                   std::map<std::string, sf::Texture> textures) : window(window), font(font), player(player),
                   rsHandler(rsHandler), textures(textures){
//init background
    this->background.setSize(sf::Vector2f(
            static_cast<float>(window->getSize().x),
            static_cast<float>(window->getSize().y)));
    this->background.setFillColor(sf::Color(20, 20, 20, 100));

    //init container
    this->container.setSize(sf::Vector2f(625.f,820.f));
    this->container.setFillColor(sf::Color(20, 20, 20, 200));

    this->container.setPosition(sf::Vector2f(
            static_cast<float>(window->getSize().x) / 2.f - this->container.getSize().x / 2.f,
            40.f));

    //init text
    this->containerTitle.setFont(*this->font);
    this->containerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    this->containerTitle.setCharacterSize(40);
    this->containerTitle.setString("Spells");
    this->containerTitle.setPosition(
            this->container.getPosition().x + (this->container.getGlobalBounds().width/2.f) - (this->containerTitle.getGlobalBounds().width/2.f),
            this->container.getPosition().y + 10.f);
}

SpellTab::~SpellTab() {

}

bool SpellTab::closeTabByClicking(const sf::Vector2f& mousePos, gui::Button* spellTab_Btn) {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
       this->background.getGlobalBounds().contains(mousePos)
       && !this->container.getGlobalBounds().contains(mousePos) && !spellTab_Btn->contains(mousePos)){
        return true;
    }
    return false;
}

void SpellTab::update(const sf::Vector2f &mousePos) {

}

void SpellTab::render(sf::RenderTarget &target) {
    target.draw(this->background);
    target.draw(this->container);
    target.draw(this->containerTitle);
}
