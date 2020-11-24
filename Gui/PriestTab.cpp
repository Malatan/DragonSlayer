//
// Created by Zheng on 22/10/2020.
//

#include "PriestTab.h"


void PriestTab::initButtons() {
    float width = 300.f;
    float height = 40.f;
    this->restoreHpBtn = gui::Button(
            this->container.getPosition().x + this->container.getGlobalBounds().width/2.f - 150.f,
            this->container.getPosition().y + 100.f,
            width, height,
            this->font, "Restore hp (Cost: 400g)", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    this->restoreHpBtn.setBorderColor(sf::Color::White);
    this->restoreHpBtn.setBorderLineThickness(5.f);
    this->restoreHpBtn.setTooltipDisabled(false);
    this->restoreHpBtn.setTooltipText("Restore all your hp");
    this->restoreHpBtn.setId(0);

    this->restoreMpBtn = gui::Button(
            this->restoreHpBtn.getPosition().x,
            this->restoreHpBtn.getPosition().y + 100.f,
            width, height,
            this->font, "Restore mp (Cost: 400g)", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    this->restoreMpBtn.setBorderColor(sf::Color::White);
    this->restoreMpBtn.setBorderLineThickness(5.f);
    this->restoreMpBtn.setTooltipDisabled(false);
    this->restoreMpBtn.setTooltipText("Restore all your mp");
    this->restoreMpBtn.setId(1);

    this->removeAllDebuffsBtn = gui::Button(
            this->restoreHpBtn.getPosition().x,
            this->restoreMpBtn.getPosition().y + 100.f,
            width, height,
            this->font, "Cleanse (Cost: 300g)", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    this->removeAllDebuffsBtn.setBorderColor(sf::Color::White);
    this->removeAllDebuffsBtn.setBorderLineThickness(5.f);
    this->removeAllDebuffsBtn.setTooltipDisabled(false);
    this->removeAllDebuffsBtn.setTooltipText("Remove all your debuffs");
    this->removeAllDebuffsBtn.setId(2);

    this->recoverAllBtn = gui::Button(
            this->restoreHpBtn.getPosition().x,
            this->removeAllDebuffsBtn.getPosition().y + 100.f,
            width, height,
            this->font, "Recover all (Cost: 600g)", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    this->recoverAllBtn.setBorderColor(sf::Color::White);
    this->recoverAllBtn.setBorderLineThickness(5.f);
    this->recoverAllBtn.setTooltipDisabled(false);
    this->recoverAllBtn.setTooltipText("Recover all your hp and mp and remove debuffs");
    this->recoverAllBtn.setId(3);
}

PriestTab::PriestTab(std::shared_ptr<sf::RenderWindow> window, sf::Font* font, std::shared_ptr<Player> player, State *state,
                     std::shared_ptr<ResourcesHandler> rsHandler, std::map<std::string, sf::Texture> textures) :
                     window(window), font(font), player(player),
                     rsHandler(rsHandler), textures(textures) {
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
    this->containerTitle.setString("Priest");
    this->containerTitle.setPosition(
            this->container.getPosition().x + (this->container.getGlobalBounds().width/2.f) - (this->containerTitle.getGlobalBounds().width/2.f),
            this->container.getPosition().y + 10.f);

    this->playerGoldLbl.setFont(*this->font);
    this->playerGoldLbl.setCharacterSize(30);
    this->playerGoldLbl.setPosition(this->container.getPosition().x + 20.f, 800.f);


    this->initButtons();

    this->updateGoldLbl();
}

PriestTab::~PriestTab() {

}

bool PriestTab::closeTabByClicking(const sf::Vector2f& mousePos) {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
           this->background.getGlobalBounds().contains(mousePos)
           && !this->container.getGlobalBounds().contains(mousePos);
}

void PriestTab::updateGoldLbl() {
    std::stringstream ss;
    std::string gold = to_string(this->player->getGold());
    unsigned len = gold.length();

    for(int index =(int) len-3; index > 0; index -= 3)
        gold.insert(index, ",");
    ss << "Gold: " << gold;

    this->playerGoldLbl.setString(ss.str());
}

void PriestTab::buttonFunctions(short unsigned btnId) {
    switch(btnId){
        case 0:{// hp
            unsigned cost = 400;
            if(this->player->getGold() >= cost){
                this->player->minusGold(cost);
                this->gState->updateTabsGoldLbl();
                this->player->getPlayerStats()->gainHp(this->player->getPlayerStats()->getFinalHp());
                this->gState->getPopUpTextComponent()->addPopUpTextCenter(
                        HEAL_TAG, "Your hp has been restored", "", "");
            }else{
                this->gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, "Insufficient gold", "", "");
            }
        }
            break;
        case 1: {// mp
            unsigned cost = 400;
            if(this->player->getGold() >= cost){
                this->player->minusGold(cost);
                this->gState->updateTabsGoldLbl();
                this->player->getPlayerStats()->gainMp(this->player->getPlayerStats()->getFinalMp());
                this->gState->getPopUpTextComponent()->addPopUpTextCenter(
                        MANA_RESTORE_TAG, "Your mp has been restored", "", "");
            }else{
                this->gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, "Insufficient gold", "", "");
            }
        }
            break;
        case 2: {// debuffs
            unsigned cost = 300;
            if(this->player->getGold() >= cost){
                this->player->minusGold(cost);
                this->gState->updateTabsGoldLbl();
                this->gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, "All your debuffs have been removed", "", "");
            }else{
                this->gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, "Insufficient gold", "", "");
            }
        }
            break;
        case 3: {// all
            unsigned cost = 600;
            if(this->player->getGold() >= cost){
                this->player->minusGold(cost);
                this->gState->updateTabsGoldLbl();
                this->player->getPlayerStats()->gainHp(this->player->getPlayerStats()->getFinalHp());
                this->player->getPlayerStats()->gainMp(this->player->getPlayerStats()->getFinalMp());
                this->gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, "You have been recovered", "", "");
            }else{
                this->gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, "Insufficient gold", "", "");
            }
        }
            break;
        default:
            break;
    }
}

void PriestTab::updateButtons() {
    if(this->restoreHpBtn.isPressed() && this->gState->getKeyTime()){
        this->buttonFunctions(this->restoreHpBtn.getId());

    } else if(this->restoreMpBtn.isPressed() && this->gState->getKeyTime()){
        this->buttonFunctions(this->restoreMpBtn.getId());

    } else if(this->removeAllDebuffsBtn.isPressed() && this->gState->getKeyTime()){
        this->buttonFunctions(this->removeAllDebuffsBtn.getId());

    } else if(this->recoverAllBtn.isPressed() && this->gState->getKeyTime()){
        this->buttonFunctions(this->recoverAllBtn.getId());

    }
}

void PriestTab::update(const sf::Vector2f &mousePos) {
    this->restoreHpBtn.update(mousePos);
    this->restoreMpBtn.update(mousePos);
    this->removeAllDebuffsBtn.update(mousePos);
    this->recoverAllBtn.update(mousePos);
    this->updateButtons();
}

void PriestTab::render(sf::RenderTarget &target) {
    target.draw(this->background);
    target.draw(this->container);
    target.draw(this->containerTitle);
    target.draw(this->playerGoldLbl);
    this->restoreHpBtn.render(target);
    this->restoreMpBtn.render(target);
    this->removeAllDebuffsBtn.render(target);
    this->recoverAllBtn.render(target);
}




