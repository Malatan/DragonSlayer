//
// Created by Zheng on 08/10/2020.
//

#include "CharacterTab.h"

//initializers

void CharacterTab::initStatsContainer(float sizeContainers) {
//containere per le statistiche
    this->statsContainer.setFillColor(sf::Color(50, 50, 50, 100));
    this->statsContainer.setSize(sf::Vector2f(sizeContainers - 120.f, 720.f));
    this->statsContainer.setPosition(this->container.getPosition().x + 20.f,
                                          this->container.getPosition().y + 60.f);

    this->statsContainerTitle.setString("-Stats-");
    this->statsContainerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    this->statsContainerTitle.setFont(*this->font);
    this->statsContainerTitle.setCharacterSize(27);
    this->statsContainerTitle.setPosition(this->statsContainer.getPosition().x + this->statsContainer.getGlobalBounds().width/2.f
            - this->statsContainerTitle.getGlobalBounds().width/2.f,
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
    this->statsName.setCharacterSize(21);
    this->statsName.setPosition(this->statsContainer.getPosition().x + 10.f,
                                this->statsContainer.getPosition().y + 50.f);

    this->statsValue.setString(this->playerStatsToString());
    this->statsValue.setFont(*this->font);
    this->statsValue.setCharacterSize(21);
    this->statsValue.setPosition(this->statsContainer.getPosition().x + 160.f,
                                 this->statsContainer.getPosition().y + 50.f);

    this->attributesHints.setString("Hints:\n"
                                    "Strength: increases your hp and\n"
                                    "   armor\n"
                                    "Wisdom: increases your mp\n"
                                    "Agility: increases your evade and\n"
                                    "   critical chance\n");
    this->attributesHints.setFont(*this->font);
    this->attributesHints.setCharacterSize(20);
    this->attributesHints.setPosition(this->statsContainer.getPosition().x + 10.f,
                                      this->statsContainer.getPosition().y + 500.f);

    //add attributes btns
    float btnSide = 17.f;
    this->addStrengthBtn = new gui::Button(
            this->statsValue.getPosition().x + 60.f, this->statsValue.getPosition().y + 268.f, btnSide, btnSide,
            this->font, "+", 48.f,
            sf::Color(200, 200, 200, 200),
            sf::Color(250, 250, 250, 250),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(20, 20, 20, 0));

    this->addWisdomBtn = new gui::Button(
            this->statsValue.getPosition().x + 60.f, this->statsValue.getPosition().y + 294.f, btnSide, btnSide,
            this->font, "+", 48.f,
            sf::Color(200, 200, 200, 200),
            sf::Color(250, 250, 250, 250),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(20, 20, 20, 0));

    this->addAgilityBtn = new gui::Button(
            this->statsValue.getPosition().x + 60.f, this->statsValue.getPosition().y + 320.f, btnSide, btnSide,
            this->font, "+", 48.f,
            sf::Color(200, 200, 200, 200),
            sf::Color(250, 250, 250, 250),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(20, 20, 20, 0));

    this->addStrengthBtn->setTextPositionAddY(-22.f);
    this->addWisdomBtn->setTextPositionAddY(-22.f);
    this->addAgilityBtn->setTextPositionAddY(-22.f);
}

void CharacterTab::initEquipContainer(float sizeContainers) {
    this->equipContainer.setFillColor(sf::Color(70, 70, 70, 100));
    this->equipContainer.setSize(sf::Vector2f(sizeContainers, 720.f));
    this->equipContainer.setPosition(this->statsContainer.getPosition().x + this->statsContainer.getGlobalBounds().width + 10.f,
                                     this->container.getPosition().y + 60.f);

    this->equipContainerTitle.setString("-Equipment-");
    this->equipContainerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    this->equipContainerTitle.setFont(*this->font);
    this->equipContainerTitle.setCharacterSize(27);
    this->equipContainerTitle.setPosition(this->equipContainer.getPosition().x + this->equipContainer.getGlobalBounds().width/2.f
                                          - this->equipContainerTitle.getGlobalBounds().width/2.f,
                                          this->equipContainer.getPosition().y + 10.f);

}

void CharacterTab::initInventoryContainer(float sizeContainers) {
    this->inventoryContainer.setFillColor(sf::Color(90, 90, 90, 100));
    this->inventoryContainer.setSize(sf::Vector2f(sizeContainers + 120.f, 720.f));
    this->inventoryContainer.setPosition(this->equipContainer.getPosition().x + this->equipContainer.getGlobalBounds().width + 10.f,
                                         this->container.getPosition().y + 60.f);

    this->invContainerTitle.setString("-Inventory-");
    this->invContainerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    this->invContainerTitle.setFont(*this->font);
    this->invContainerTitle.setCharacterSize(27);
    this->invContainerTitle.setPosition(this->inventoryContainer.getPosition().x + this->inventoryContainer.getGlobalBounds().width/2.f
                                          - this->invContainerTitle.getGlobalBounds().width/2.f,
                                          this->inventoryContainer.getPosition().y + 10.f);
}

CharacterTab::CharacterTab(sf::RenderWindow& window, sf::Font* font, Player* player, State* state) : font(font), player(player), state(state)
{
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
            <<this->player->getPlayerStats()->getCritChance() << "%\n"
            <<this->player->getPlayerStats()->getEvadeChance() << "%\n\n\n\n"
            <<this->player->getPlayerStats()->getStrength() << "\n"
            <<this->player->getPlayerStats()->getWisdom() << "\n"
            <<this->player->getPlayerStats()->getAgility() << "\n"
            <<this->player->getPlayerStats()->getFreePoints() << "\n";
    return ss.str();
}

void CharacterTab::statsContainerUpdate(const sf::Vector2f& mousePos) {
    this->statsValue.setString(this->playerStatsToString());
    if(this->player->getPlayerStats()->getFreePoints() > 0) {
        this->addStrengthBtn->update(mousePos);
        this->addWisdomBtn->update(mousePos);
        this->addAgilityBtn->update(mousePos);
    }
}

void CharacterTab::statsContainerRender(sf::RenderTarget &target) {
    target.draw(this->statsContainer);
    target.draw(this->statsContainerTitle);
    target.draw(this->statsName);
    target.draw(this->statsValue);
    target.draw(this->attributesHints);
    if(this->player->getPlayerStats()->getFreePoints() > 0) {
        this->addStrengthBtn->render(target);
        this->addWisdomBtn->render(target);
        this->addAgilityBtn->render(target);
    }
}

void CharacterTab::equipContainerUpdate(const sf::Vector2f &mousePos) {

}

void CharacterTab::equipContainerRender(sf::RenderTarget &target) {
    target.draw(this->equipContainer);
    target.draw(this->equipContainerTitle);
}

void CharacterTab::invContainerUpdate(const sf::Vector2f &mousePos) {

}

void CharacterTab::invContainerRender(sf::RenderTarget &target) {
    target.draw(this->inventoryContainer);
    target.draw(this->invContainerTitle);
}

bool CharacterTab::closeCharacterTabByClicking(const sf::Vector2f& mousePos) {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            this->backgorund.getGlobalBounds().contains(mousePos)
       && !this->container.getGlobalBounds().contains(mousePos)){
        return true;
    }
    return false;
}

void CharacterTab::updateButtons() {
    if(this->addStrengthBtn->isPressed() && this->state->getKeyTime()){
        if(this->player->getPlayerStats()->getFreePoints() > 0){
            this->player->getPlayerStats()->addAttribute(0);
        }
    } else if(this->addWisdomBtn->isPressed() && this->state->getKeyTime()){
        if(this->player->getPlayerStats()->getFreePoints() > 0){
            this->player->getPlayerStats()->addAttribute(1);
        }
    } else if(this->addAgilityBtn->isPressed() && this->state->getKeyTime()){
        if(this->player->getPlayerStats()->getFreePoints() > 0){
            this->player->getPlayerStats()->addAttribute(2);
        }
    }

}

void CharacterTab::update(const sf::Vector2f& mousePos) {
    this->statsContainerUpdate(mousePos);
    this->updateButtons();


}

void CharacterTab::render(sf::RenderTarget &target) {
    target.draw(this->backgorund);
    target.draw(this->container);
    target.draw(this->tabText);

    this->statsContainerRender(target);
    this->equipContainerRender(target);
    this->invContainerRender(target);
}
















