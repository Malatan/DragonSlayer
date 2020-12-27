//
// Created by andry on 15/12/2020.
//
#include "SelectLevelTab.h"

void SelectLevelTab::initButtons() {
    stringstream ss;
    float width = 300.f;
    float height = 40.f;
    ss << "Level 1" ;
    level1Btn = std::make_unique<gui::Button>(
            container.getPosition().x + container.getGlobalBounds().width/2.f - 150.f,
            container.getPosition().y + 100.f,
            width, height,
            font, ss.str(), 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    level1Btn->setBorderColor(sf::Color::White);
    level1Btn->setBorderLineThickness(5.f);
    level1Btn->setTooltipDisabled(false);
    level1Btn->setTooltipText("Teleport to the first lay (Enemies will respawn)");
    level1Btn->setId(0);

    ss.str("");
    ss << "Level 2" ;
    level2Btn = std::make_unique<gui::Button>(
            level1Btn->getPosition().x,
            level1Btn->getPosition().y + 100.f,
            width, height,
            font, ss.str(), 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    level2Btn->setBorderColor(sf::Color::White);
    level2Btn->setBorderLineThickness(5.f);
    level2Btn->setTooltipDisabled(false);
    level2Btn->setTooltipText("Teleport to the second lay (Enemies will respawn)");
    level2Btn->setId(1);

    ss.str("");
    ss << "Level 3" ;
    level3Btn = std::make_unique<gui::Button>(
            level1Btn->getPosition().x,
            level1Btn->getPosition().y + 200.f,
            width, height,
            font, ss.str(), 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    level3Btn->setBorderColor(sf::Color::White);
    level3Btn->setBorderLineThickness(5.f);
    level3Btn->setTooltipDisabled(false);
    level3Btn->setTooltipText("Teleport to the third lay (Enemies will respawn)");
    level3Btn->setId(2);

    ss.str("");
    ss << "Level 4" ;
    level4Btn = std::make_unique<gui::Button>(
            level1Btn->getPosition().x,
            level1Btn->getPosition().y + 300.f,
            width, height,
            font, ss.str(), 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    level4Btn->setBorderColor(sf::Color::White);
    level4Btn->setBorderLineThickness(5.f);
    level4Btn->setTooltipDisabled(false);
    level4Btn->setTooltipText("Teleport to the fourth lay (Enemies will respawn)");
    level4Btn->setId(3);


    ss.str("");
    ss << "Level 5" ;
    level5Btn = std::make_unique<gui::Button>(
            level1Btn->getPosition().x,
            level1Btn->getPosition().y + 400.f,
            width, height,
            font, ss.str(), 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    level5Btn->setBorderColor(sf::Color::White);
    level5Btn->setBorderLineThickness(5.f);
    level5Btn->setTooltipDisabled(false);
    level5Btn->setTooltipText("Teleport to the fifth lay (Enemies will respawn)");
    level5Btn->setId(4);
}

SelectLevelTab::SelectLevelTab(const std::shared_ptr<sf::RenderWindow>& window, sf::Font* font, std::shared_ptr<Player> player, State *state,
                     std::shared_ptr<ResourcesHandler> rsHandler) :
        window(window), font(font), player(std::move(player)),
        rsHandler(std::move(rsHandler)) {
    gState = dynamic_cast<GameState*>(state);
    //init background
    background.setSize(sf::Vector2f(
            static_cast<float>(window->getSize().x),
            static_cast<float>(window->getSize().y)));
    background.setFillColor(sf::Color(20, 20, 20, 100));

    //init container
    container.setSize(sf::Vector2f(625.f,820.f));
    container.setFillColor(sf::Color(20, 20, 20, 200));

    container.setPosition(sf::Vector2f(
            static_cast<float>(window->getSize().x) / 2.f - container.getSize().x / 2.f,
            40.f));
    container.setOutlineThickness(5.f);
    container.setOutlineColor(sf::Color(10, 10, 10));

    //init text
    containerTitle.setFont(*this->font);
    containerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    containerTitle.setCharacterSize(40);
    containerTitle.setString("Select Level");
    containerTitle.setPosition(
            container.getPosition().x + (container.getGlobalBounds().width/2.f) - (containerTitle.getGlobalBounds().width/2.f),
            container.getPosition().y + 10.f);

    playerGoldLbl.setFont(*this->font);
    playerGoldLbl.setCharacterSize(30);
    playerGoldLbl.setPosition(container.getPosition().x + 20.f, 800.f);

    initButtons();
}

SelectLevelTab::~SelectLevelTab()= default;

bool SelectLevelTab::closeTabByClicking(const sf::Vector2f& mousePos) {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
           background.getGlobalBounds().contains(mousePos)
           && !container.getGlobalBounds().contains(mousePos);
}

void SelectLevelTab::buttonFunctions(short unsigned btnId) {
    switch(btnId){
        case 0:{
            gState->changeMap(1);
            hide = true;
            break;
        }

        case 1: {
            gState->changeMap(2);
            hide = true;
            break;
        }

        case 2: {
            gState->changeMap(3);
            hide = true;
            break;
        }

        case 3: {
            gState->changeMap(4);
            hide = true;
            break;
        }

        case 4: {
            gState->changeMap(5);
            hide = true;
            break;
        }
        default:
            break;
    }
}

void SelectLevelTab::updateButtonsAccess(int reached_floor) {
    switch (reached_floor) {
        case 0: case 1:{
            level1Btn->setDisabled(false);
            level2Btn->setDisabled(true);
            level3Btn->setDisabled(true);
            level4Btn->setDisabled(true);
            level5Btn->setDisabled(true);
            break;
        }
        case 2:{
            level1Btn->setDisabled(false);
            level2Btn->setDisabled(false);
            level3Btn->setDisabled(true);
            level4Btn->setDisabled(true);
            level5Btn->setDisabled(true);
            break;
        }
        case 3:{
            level1Btn->setDisabled(false);
            level2Btn->setDisabled(false);
            level3Btn->setDisabled(false);
            level4Btn->setDisabled(true);
            level5Btn->setDisabled(true);
            break;
        }
        case 4:{
            level1Btn->setDisabled(false);
            level2Btn->setDisabled(false);
            level3Btn->setDisabled(false);
            level4Btn->setDisabled(false);
            level5Btn->setDisabled(true);
            break;
        }
        case 5:{
            level1Btn->setDisabled(false);
            level2Btn->setDisabled(false);
            level3Btn->setDisabled(false);
            level4Btn->setDisabled(false);
            level5Btn->setDisabled(false);
            break;
        }
    }
}

void SelectLevelTab::updateButtons() {
    if(level1Btn->isPressed() && gState->getKeyTime()){
        buttonFunctions(level1Btn->getId());

    } else if(level2Btn->isPressed() && gState->getKeyTime()){
        buttonFunctions(level2Btn->getId());

    } else if(level3Btn->isPressed() && gState->getKeyTime()){
        buttonFunctions(level3Btn->getId());

    } else if(level4Btn->isPressed() && gState->getKeyTime()){
        buttonFunctions(level4Btn->getId());

    } else if(level5Btn->isPressed() && gState->getKeyTime()){
        buttonFunctions(level5Btn->getId());

    }
}

void SelectLevelTab::updateInputs() {
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::E) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) &&
       gState->getKeyTime()){
        gState->changeStato(NO_TAB);
    }
}

void SelectLevelTab::update(const sf::Vector2f &mousePos) {
    level1Btn->update(mousePos);
    level2Btn->update(mousePos);
    level3Btn->update(mousePos);
    level4Btn->update(mousePos);
    level5Btn->update(mousePos);
    updateInputs();
    updateButtons();
}

void SelectLevelTab::render(sf::RenderTarget &target) {
    target.draw(background);
    target.draw(container);
    target.draw(containerTitle);
    level1Btn->render(target);
    level2Btn->render(target);
    level3Btn->render(target);
    level4Btn->render(target);
    level5Btn->render(target);
}

bool SelectLevelTab::isHide() const {
    return hide;
}

void SelectLevelTab::setHide(bool b) {
    hide = b;
}


