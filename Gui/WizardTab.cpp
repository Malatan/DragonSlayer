//
// Created by Zheng on 24/10/2020.
//

#include "WizardTab.h"

//constructors/destructor
WizardTab::WizardTab(sf::RenderWindow* window, sf::Font *font, Player *player, State *state, std::map<std::string, sf::Texture> textures)
        : textures(textures), player(player), font(font), window(window){
    this->gState = dynamic_cast<GameState*>(state);

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
    this->containerTitle.setString("Wizard");
    this->containerTitle.setPosition(
            this->container.getPosition().x + (this->container.getGlobalBounds().width/2.f) - (this->containerTitle.getGlobalBounds().width/2.f),
            this->container.getPosition().y + 10.f);

    this->playerGoldLbl.setFont(*this->font);
    this->playerGoldLbl.setCharacterSize(30);
    this->playerGoldLbl.setPosition(this->container.getPosition().x + 20.f, 800.f);

    this->updateGoldLbl();
}

WizardTab::~WizardTab() {

}

//functions
bool WizardTab::closeTabByClicking(const sf::Vector2f& mousePos) {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
       this->background.getGlobalBounds().contains(mousePos)
       && !this->container.getGlobalBounds().contains(mousePos)){
        return true;
    }
    return false;
}

void WizardTab::updateGoldLbl() {
    std::stringstream ss;
    std::string gold = to_string(this->player->getGold());
    unsigned len = gold.length();

    for(int index =(int) len-3; index > 0; index -= 3)
        gold.insert(index, ",");
    ss << "Gold: " << gold;

    this->playerGoldLbl.setString(ss.str());
}

void WizardTab::update(const sf::Vector2f &mousePos) {

}

void WizardTab::render(sf::RenderTarget &target) {
    target.draw(this->background);
    target.draw(this->container);
    target.draw(this->containerTitle);
    target.draw(this->playerGoldLbl);

}
