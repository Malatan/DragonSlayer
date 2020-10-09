//
// Created by Zheng on 08/10/2020.
//

#include "CharacterTab.h"

CharacterTab::CharacterTab(sf::RenderWindow& window, sf::Font* font) : font(font){
    //init background
    this->backgorund.setSize(sf::Vector2f(
            static_cast<float>(window.getSize().x),
            static_cast<float>(window.getSize().y)));
    this->backgorund.setFillColor(sf::Color(20, 20, 20, 100));

    //initi container
    this->container.setSize(sf::Vector2f(
            static_cast<float>(window.getSize().x / 1.1f),
            static_cast<float>(window.getSize().y - 100.f )));
    this->container.setFillColor(sf::Color(20, 20, 20, 200));

    this->container.setPosition(sf::Vector2f(
            static_cast<float>(window.getSize().x) / 2.f - this->container.getSize().x / 2.f,
            40.f));

    //init text
    this->tabText.setFont(*font);
    this->tabText.setFillColor(sf::Color(255, 255, 255, 200));
    this->tabText.setCharacterSize(30);
    this->tabText.setString("Character Tab");
    this->tabText.setPosition(
            this->container.getPosition().x + 20.f,
            this->container.getPosition().y + 10.f);

    float sizeContainers = (this->container.getGlobalBounds().width - 60.f) / 3.f;
    //containere per le statistiche
    this->attributesContainer.setFillColor(sf::Color(50, 50, 50, 100));
    this->attributesContainer.setSize(sf::Vector2f(sizeContainers, 720.f));
    this->attributesContainer.setPosition(this->container.getPosition().x + 20.f,
            this->container.getPosition().y + 60.f);

    //container per l'equippagiamento
    this->equipContainer.setFillColor(sf::Color(70, 70, 70, 100));
    this->equipContainer.setSize(sf::Vector2f(sizeContainers, 720.f));
    this->equipContainer.setPosition(this->attributesContainer.getPosition().x + sizeContainers + 10.f,
                                     this->container.getPosition().y + 60.f);

    //container per l'inventario
    this->inventoryContainer.setFillColor(sf::Color(90, 90, 90, 100));
    this->inventoryContainer.setSize(sf::Vector2f(sizeContainers, 720.f));
    this->inventoryContainer.setPosition(this->equipContainer.getPosition().x + sizeContainers + 10.f,
                                         this->container.getPosition().y + 60.f);

}

CharacterTab::~CharacterTab() {
}

//accessor


//functions
void CharacterTab::update(const sf::Vector2f& mousePos) {

}

void CharacterTab::render(sf::RenderTarget &target) {
    target.draw(this->backgorund);
    target.draw(this->container);
    target.draw(this->tabText);
    target.draw(this->attributesContainer);
    target.draw(this->equipContainer);
    target.draw(this->inventoryContainer);
}