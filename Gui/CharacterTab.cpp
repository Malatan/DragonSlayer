//
// Created by Zheng on 08/10/2020.
//

#include "CharacterTab.h"

//initializers

void CharacterTab::initStatsContainer(float sizeContainers) {
//containere per le statistiche
    this->statsContainer.setFillColor(sf::Color(50, 50, 50, 100));
    this->statsContainer.setSize(sf::Vector2f(sizeContainers, 720.f));
    this->statsContainer.setPosition(this->container.getPosition().x + 20.f,
                                          this->container.getPosition().y + 60.f);

    this->statsContainerTitle.setString("Stats");
    this->statsContainerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    this->statsContainerTitle.setFont(*this->font);
    this->statsContainerTitle.setCharacterSize(27);
    this->statsContainerTitle.setPosition(this->statsContainer.getPosition().x/2.f +
                  this->statsContainer.getGlobalBounds().width/2.f + this->statsContainerTitle.getGlobalBounds().width/2.f,
            this->statsContainer.getPosition().y + 10.f);


    this->statsName.setString("Level:\n"
                              "Exp:\n"
                              "Hp:\n"
                              "Mp:\n"
                              "Damage:\n"
                              "Armor:\n"
                              "Critical Chance:\n"
                              "Evade Chance:\n"
                              "\n\n\n"
                              "Strength:\n"
                              "Wisdom:\n"
                              "Agility:\n"
                              "Available Points:\n");
    this->statsName.setFillColor(sf::Color(255, 255, 255, 200));
    this->statsName.setFont(*this->font);
    this->statsName.setCharacterSize(23);
    this->statsName.setPosition(this->statsContainer.getPosition().x + 30.f,
                                this->statsContainer.getPosition().y + 50.f);

    this->statsValue.setString(this->playerStatsToString());
    this->statsValue.setFont(*this->font);
    this->statsValue.setCharacterSize(23);
    this->statsValue.setPosition(this->statsContainer.getPosition().x + 280.f,
                                 this->statsContainer.getPosition().y + 50.f);

    this->attributesHints.setString("Hints:\nStrength: increases your attack and hp\n"
                                    "Wisdom: increases your mp boost\n"
                                    "Agility: increases your evade chance boost\n");
    this->attributesHints.setFont(*this->font);
    this->attributesHints.setCharacterSize(23);
    this->attributesHints.setPosition(this->statsContainer.getPosition().x + 20.f,
                                      this->statsContainer.getPosition().y + 550.f);
}

void CharacterTab::initEquipContainer(float sizeContainers) {
    this->equipContainer.setFillColor(sf::Color(70, 70, 70, 100));
    this->equipContainer.setSize(sf::Vector2f(sizeContainers, 720.f));
    this->equipContainer.setPosition(this->statsContainer.getPosition().x + sizeContainers + 10.f,
                                     this->container.getPosition().y + 60.f);
}

void CharacterTab::initInventoryContainer(float sizeContainers) {
    this->inventoryContainer.setFillColor(sf::Color(90, 90, 90, 100));
    this->inventoryContainer.setSize(sf::Vector2f(sizeContainers, 720.f));
    this->inventoryContainer.setPosition(this->equipContainer.getPosition().x + sizeContainers + 10.f,
                                         this->container.getPosition().y + 60.f);
}

CharacterTab::CharacterTab(sf::RenderWindow& window, sf::Font* font, Player* player) : font(font), player(player){
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
    this->tabText.setFont(*this->font);
    this->tabText.setFillColor(sf::Color(255, 255, 255, 200));
    this->tabText.setCharacterSize(30);
    this->tabText.setString("Character Tab");
    this->tabText.setPosition(
            this->container.getPosition().x + 20.f,
            this->container.getPosition().y + 10.f);

    float sizeContainers = (this->container.getGlobalBounds().width - 60.f) / 3.f;

    this->initStatsContainer(sizeContainers);
    this->initEquipContainer(sizeContainers);
    this->initInventoryContainer(sizeContainers);

}

CharacterTab::~CharacterTab() {
}

//accessor


//functions
std::string CharacterTab::playerStatsToString() {
    std::stringstream ss;
    ss << this->player->getPlayerStats()->getLevel()  << "\n"
            <<this->player->getPlayerStats()->getExp() <<"/" << this->player->getPlayerStats()->getMaxExp() << "\n"
            <<this->player->getPlayerStats()->getHp() << "\n"
            <<this->player->getPlayerStats()->getMp() << "\n"
            <<this->player->getPlayerStats()->getDamage() << "\n"
            <<this->player->getPlayerStats()->getArmor() << "\n"
            <<this->player->getPlayerStats()->getCritChance() << "\n"
            <<this->player->getPlayerStats()->getEvadeChance() << "\n\n\n\n"
            <<this->player->getPlayerStats()->getStrength() << "\n"
            <<this->player->getPlayerStats()->getWisdom() << "\n"
            <<this->player->getPlayerStats()->getAgility() << "\n"
            <<this->player->getPlayerStats()->getFreePoints() << "\n";
    return ss.str();
}

void CharacterTab::statsContainerUpdate() {
    this->statsValue.setString(this->playerStatsToString());
}

void CharacterTab::update(const sf::Vector2f& mousePos) {
    this->statsContainerUpdate();
}

void CharacterTab::statsContainerRender(sf::RenderTarget &target) {
    target.draw(this->statsContainer);
    target.draw(this->statsContainerTitle);
    target.draw(this->statsName);
    target.draw(this->statsValue);
    target.draw(this->attributesHints);
}

void CharacterTab::render(sf::RenderTarget &target) {
    target.draw(this->backgorund);
    target.draw(this->container);
    target.draw(this->tabText);

    this->statsContainerRender(target);
    target.draw(this->equipContainer);
    target.draw(this->inventoryContainer);
}







