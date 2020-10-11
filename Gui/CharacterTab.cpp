//
// Created by Zheng on 08/10/2020.
//

#include "CharacterTab.h"

//initializers

void CharacterTab::initStatsContainer() {
//containere per le statistiche
    this->statsContainer.setFillColor(sf::Color(50, 50, 50, 100));
    this->statsContainer.setSize(sf::Vector2f(((this->container.getGlobalBounds().width - 60.f) / 3.f) - 120.f, 720.f));
    this->statsContainer.setPosition(this->container.getPosition().x + 20.f,
                                          this->container.getPosition().y + 60.f);

    this->statsContainerTitle.setString("-Stats-");
    this->statsContainerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    this->statsContainerTitle.setFont(*this->font);
    this->statsContainerTitle.setCharacterSize(27);
    this->statsContainerTitle.setPosition(this->statsContainer.getPosition().x + this->statsContainer.getGlobalBounds().width/2.f
            - this->statsContainerTitle.getGlobalBounds().width/2.f,
            this->statsContainer.getPosition().y);


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

void CharacterTab::initEquipContainer(sf::RenderWindow& window) {
    this->equipContainer.setFillColor(sf::Color(70, 70, 70, 100));
    this->equipContainer.setSize(sf::Vector2f(190.f, this->statsContainer.getGlobalBounds().height));
    this->equipContainer.setPosition(this->statsContainer.getPosition().x + this->statsContainer.getGlobalBounds().width + 10.f,
                                     this->container.getPosition().y + 60.f);

    this->equipContainerTitle.setString("-Equipment-");
    this->equipContainerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    this->equipContainerTitle.setFont(*this->font);
    this->equipContainerTitle.setCharacterSize(27);
    this->equipContainerTitle.setPosition(this->equipContainer.getPosition().x + this->equipContainer.getGlobalBounds().width/2.f
                                          - this->equipContainerTitle.getGlobalBounds().width/2.f,
                                          this->equipContainer.getPosition().y);

    this->equipBonusLbl.setString("Equip Effects:\n"
                                  "Damage +20\n"
                                  "Armor +15");
    this->equipBonusLbl.setFont(*this->font);
    this->equipBonusLbl.setCharacterSize(20);
    this->equipBonusLbl.setPosition(this->equipContainer.getPosition().x + 10.f,
                                    this->equipContainer.getPosition().y + 320.f);

    float posX = 15.f;
    float posY = 40.f;
    float slotSize = 70.f;

    this->equipSlots[5] = new gui::ItemSlot(this->equipContainer.getPosition().x + posX,
                                                  this->equipContainer.getPosition().y + posY, slotSize, slotSize, 5, &window, this->font
    );
    this->equipSlots[4] = new gui::ItemSlot(this->equipContainer.getPosition().x + posX + 90.f,
                                                  this->equipContainer.getPosition().y + posY, slotSize, slotSize, 4, &window, this->font
    );
    this->equipSlots[3] = new gui::ItemSlot(this->equipContainer.getPosition().x + posX,
                                                  this->equipContainer.getPosition().y + posY + 90.f, slotSize, slotSize, 3, &window, this->font
    );
    this->equipSlots[2] = new gui::ItemSlot(this->equipContainer.getPosition().x + posX + 90.f,
                                                  this->equipContainer.getPosition().y + posY + 90.f, slotSize, slotSize, 2, &window, this->font
    );
    this->equipSlots[1] = new gui::ItemSlot(this->equipContainer.getPosition().x + posX,
                                                  this->equipContainer.getPosition().y + posY + 180.f, slotSize, slotSize, 1, &window, this->font
    );
    this->equipSlots[0] = new gui::ItemSlot(this->equipContainer.getPosition().x + posX + 90.f,
                                                  this->equipContainer.getPosition().y + posY + 180.f, slotSize, slotSize, 0, &window, this->font
    );

}

void CharacterTab::initInventoryContainer() {
    this->inventoryContainer.setFillColor(sf::Color(90, 90, 90, 100));
    this->inventoryContainer.setSize(sf::Vector2f(this->container.getGlobalBounds().width - 60.f
    -this->statsContainer.getGlobalBounds().width -this->equipContainer.getGlobalBounds().width
            , this->statsContainer.getGlobalBounds().height));
    this->inventoryContainer.setPosition(this->equipContainer.getPosition().x + this->equipContainer.getGlobalBounds().width + 10.f,
            this->equipContainer.getPosition().y );

    this->invContainerTitle.setString("-Inventory-");
    this->invContainerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    this->invContainerTitle.setFont(*this->font);
    this->invContainerTitle.setCharacterSize(27);
    this->invContainerTitle.setPosition(this->inventoryContainer.getPosition().x + this->inventoryContainer.getGlobalBounds().width/2.f
                                        - this->invContainerTitle.getGlobalBounds().width/2.f,
                                        this->inventoryContainer.getPosition().y);
}

CharacterTab::CharacterTab(sf::RenderWindow& window, sf::Font* font, Player* player, State* state) : font(font), player(player), state(state)
{

    //init background
    this->backgorund.setSize(sf::Vector2f(
            static_cast<float>(window.getSize().x),
            static_cast<float>(window.getSize().y)));
    this->backgorund.setFillColor(sf::Color(20, 20, 20, 100));
    this->updateSlot = (int *) malloc(sizeof(int));
    *this->updateSlot = 6;
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

    this->hpBarLbl.setCharacterSize(20);
    this->hpBarLbl.setFont(*this->font);
    this->hpBarLbl.setString("Hp:");
    this->hpBarLbl.setPosition(
            this->tabText.getPosition().x + 300.f,
            this->tabText.getPosition().y + 10.f);

    this->hpBar = new gui::ProgressBar(&window, this->hpBarLbl.getPosition().x + 35.f, this->tabText.getPosition().y + 10.f, 150.f, 25.f,
                                       0, this->player->getPlayerStats()->getMaxHp(), this->player->getPlayerStats()->getHp(), font);

    this->mpBarLbl.setCharacterSize(20);
    this->mpBarLbl.setFont(*this->font);
    this->mpBarLbl.setString("Mp:");
    this->mpBarLbl.setPosition(
            this->hpBarLbl.getPosition().x + 230.f,
            this->tabText.getPosition().y + 10.f);

    this->mpBar = new gui::ProgressBar(&window, this->mpBarLbl.getPosition().x + 35.f, this->tabText.getPosition().y + 10.f, 150.f, 25.f,
                                       0, this->player->getPlayerStats()->getMaxMp(), this->player->getPlayerStats()->getMp(), font);
    this->mpBar->setProgressShapeColor(sf::Color::Blue);

    this->expBarLbl.setCharacterSize(20);
    this->expBarLbl.setFont(*this->font);
    this->expBarLbl.setString("Exp:");
    this->expBarLbl.setPosition(
            this->mpBarLbl.getPosition().x + 230.f,
            this->tabText.getPosition().y + 10.f);

    this->expBar = new gui::ProgressBar(&window, this->expBarLbl.getPosition().x + 35.f, this->tabText.getPosition().y + 10.f, 150.f, 25.f,
                                       0, this->player->getPlayerStats()->getMaxExp(), this->player->getPlayerStats()->getExp(), font);
    this->expBar->setProgressShapeColor(sf::Color::Yellow);


    this->initStatsContainer();
    this->initEquipContainer(window);
    this->initInventoryContainer();

}

CharacterTab::~CharacterTab() {
    delete this->addStrengthBtn;
    delete this->addWisdomBtn;
    delete this->addAgilityBtn;
    delete this->hpBar;
    delete this->mpBar;
    delete this->expBar;
    for(auto i : this->equipSlots)
        delete i;
}

//accessor

gui::ItemSlot** CharacterTab::getEquipSlots() {
    return this->equipSlots;
}


//functions
std::string CharacterTab::playerStatsToString() {
    std::stringstream ss;
    ss << this->player->getPlayerStats()->getLevel()  << "\n"
            <<this->player->getPlayerStats()->getExp() <<"/" << this->player->getPlayerStats()->getMaxExp() << "\n"
            <<this->player->getPlayerStats()->getMaxHp() << "\n"
            <<this->player->getPlayerStats()->getMaxMp() << "\n"
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
    int counter = 0;
    for(auto i : this->equipSlots){
        if(*this->updateSlot != 6){
            this->equipSlots[*this->updateSlot]->update(mousePos, this->updateSlot);
        }
        else{
            i->update(mousePos, this->updateSlot);
        }

        counter++;
    }
}

void CharacterTab::equipContainerRender(sf::RenderTarget &target) {
    target.draw(this->equipContainer);
    target.draw(this->equipContainerTitle);
    target.draw(this->equipBonusLbl);
    for(auto i : this->equipSlots){
        i->render(target);
    }
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
    this->equipContainerUpdate(mousePos);

    this->updateButtons();
    this->hpBar->update(this->player->getPlayerStats()->getHp(), this->player->getPlayerStats()->getMaxHp());
    this->mpBar->update(this->player->getPlayerStats()->getMp(), this->player->getPlayerStats()->getMaxMp());
    this->expBar->update(this->player->getPlayerStats()->getExp(), this->player->getPlayerStats()->getMaxExp());
}

void CharacterTab::render(sf::RenderTarget &target) {
    target.draw(this->backgorund);
    target.draw(this->container);
    target.draw(this->tabText);

    target.draw(this->hpBarLbl);
    this->hpBar->render(target);
    target.draw(this->mpBarLbl);
    this->mpBar->render(target);
    target.draw(this->expBarLbl);
    this->expBar->render(target);

    this->statsContainerRender(target);
    this->equipContainerRender(target);
    this->invContainerRender(target);
}



















