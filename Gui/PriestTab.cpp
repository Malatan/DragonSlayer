//
// Created by Zheng on 22/10/2020.
//

#include "PriestTab.h"

void PriestTab::initButtons() {
    stringstream ss;
    float width = 300.f;
    float height = 40.f;
    ss << "Restore hp (Cost: " << RECOVER_HP_COST << "g)" ;
    restoreHpBtn = gui::Button(
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
    restoreHpBtn.setBorderColor(sf::Color::White);
    restoreHpBtn.setBorderLineThickness(5.f);
    restoreHpBtn.setTooltipDisabled(false);
    restoreHpBtn.setTooltipText("Restore all your hp");
    restoreHpBtn.setId(0);

    ss.str("");
    ss << "Restore mp (Cost: " << RECOVER_MP_COST << "g)" ;
    restoreMpBtn = gui::Button(
            restoreHpBtn.getPosition().x,
            restoreHpBtn.getPosition().y + 100.f,
            width, height,
            font, ss.str(), 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    restoreMpBtn.setBorderColor(sf::Color::White);
    restoreMpBtn.setBorderLineThickness(5.f);
    restoreMpBtn.setTooltipDisabled(false);
    restoreMpBtn.setTooltipText("Restore all your mp");
    restoreMpBtn.setId(1);

    ss.str("");
    ss << "Cleanse (Cost: " << REM_DEBUFFS_COST << "g)" ;
    removeAllDebuffsBtn = gui::Button(
            restoreHpBtn.getPosition().x,
            restoreMpBtn.getPosition().y + 100.f,
            width, height,
            font, ss.str(), 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    removeAllDebuffsBtn.setBorderColor(sf::Color::White);
    removeAllDebuffsBtn.setBorderLineThickness(5.f);
    removeAllDebuffsBtn.setTooltipDisabled(false);
    removeAllDebuffsBtn.setTooltipText("Remove all your debuffs");
    removeAllDebuffsBtn.setId(2);

    ss.str("");
    ss << "Recover all (Cost: " << RECOVER_ALL_COST << "g)" ;
    recoverAllBtn = gui::Button(
            restoreHpBtn.getPosition().x,
            removeAllDebuffsBtn.getPosition().y + 100.f,
            width, height,
            font, ss.str(), 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    recoverAllBtn.setBorderColor(sf::Color::White);
    recoverAllBtn.setBorderLineThickness(5.f);
    recoverAllBtn.setTooltipDisabled(false);
    recoverAllBtn.setTooltipText("Recover all your hp and mp and remove debuffs");
    recoverAllBtn.setId(3);
}

PriestTab::PriestTab(const std::shared_ptr<sf::RenderWindow>& window, sf::Font* font, std::shared_ptr<Player> player, State *state,
                     std::shared_ptr<ResourcesHandler> rsHandler, std::map<std::string, sf::Texture> textures) :
                     window(window), font(font), player(std::move(player)),
                     rsHandler(std::move(rsHandler)), textures(std::move(textures)) {
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
    containerTitle.setString("Priest");
    containerTitle.setPosition(
            container.getPosition().x + (container.getGlobalBounds().width/2.f) - (containerTitle.getGlobalBounds().width/2.f),
            container.getPosition().y + 10.f);

    playerGoldLbl.setFont(*this->font);
    playerGoldLbl.setCharacterSize(30);
    playerGoldLbl.setPosition(container.getPosition().x + 20.f, 800.f);

    initButtons();
    updateGoldLbl();
}

PriestTab::~PriestTab() = default;

bool PriestTab::closeTabByClicking(const sf::Vector2f& mousePos) {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
           background.getGlobalBounds().contains(mousePos)
           && !container.getGlobalBounds().contains(mousePos);
}

void PriestTab::updateGoldLbl() {
    std::stringstream ss;
    std::string gold = to_string(player->getGold());
    unsigned len = gold.length();

    for(int index =(int) len-3; index > 0; index -= 3)
        gold.insert(index, ",");
    ss << "Gold: " << gold;

    playerGoldLbl.setString(ss.str());
}

void PriestTab::buttonFunctions(short unsigned btnId) {
    switch(btnId){
        case 0:{// hp
            if(player->getGold() >= RECOVER_HP_COST){
                player->minusGold(RECOVER_HP_COST);
                gState->updateTabsGoldLbl();
                player->getPlayerStats()->gainHp(player->getPlayerStats()->getFinalHp());
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        HEAL_TAG, "Your hp has been restored", "", "");
            }else{
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, "Insufficient gold", "", "");
            }
        }
            break;
        case 1: {// mp
            if(player->getGold() >= RECOVER_MP_COST){
                player->minusGold(RECOVER_MP_COST);
                gState->updateTabsGoldLbl();
                player->getPlayerStats()->gainMp(player->getPlayerStats()->getFinalMp());
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        MANA_RESTORE_TAG, "Your mp has been restored", "", "");
            }else{
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, "Insufficient gold", "", "");
            }
        }
            break;
        case 2: {// debuffs
            if(player->getGold() >= REM_DEBUFFS_COST){
                player->minusGold(REM_DEBUFFS_COST);
                gState->updateTabsGoldLbl();
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, "All your debuffs have been removed", "", "");
            }else{
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, "Insufficient gold", "", "");
            }
        }
            break;
        case 3: {// all
            if(player->getGold() >= RECOVER_ALL_COST){
                player->minusGold(RECOVER_ALL_COST);
                gState->updateTabsGoldLbl();
                player->getPlayerStats()->gainHp(player->getPlayerStats()->getFinalHp());
                player->getPlayerStats()->gainMp(player->getPlayerStats()->getFinalMp());
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, "You have been recovered", "", "");
            }else{
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, "Insufficient gold", "", "");
            }
        }
            break;
        default:
            break;
    }
}

void PriestTab::updateButtons() {
    if(restoreHpBtn.isPressed() && gState->getKeyTime()){
        buttonFunctions(restoreHpBtn.getId());

    } else if(restoreMpBtn.isPressed() && gState->getKeyTime()){
        buttonFunctions(restoreMpBtn.getId());

    } else if(removeAllDebuffsBtn.isPressed() && gState->getKeyTime()){
        buttonFunctions(removeAllDebuffsBtn.getId());

    } else if(recoverAllBtn.isPressed() && gState->getKeyTime()){
        buttonFunctions(recoverAllBtn.getId());

    }
}

void PriestTab::updateInputs() {
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::E) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) &&
       gState->getKeyTime()){
        gState->changeStato(NO_TAB);
    }
}

void PriestTab::update(const sf::Vector2f &mousePos) {
    updateInputs();
    restoreHpBtn.update(mousePos);
    restoreMpBtn.update(mousePos);
    removeAllDebuffsBtn.update(mousePos);
    recoverAllBtn.update(mousePos);
    updateButtons();
}

void PriestTab::render(sf::RenderTarget &target) {
    target.draw(background);
    target.draw(container);
    target.draw(containerTitle);
    target.draw(playerGoldLbl);
    restoreHpBtn.render(target);
    restoreMpBtn.render(target);
    removeAllDebuffsBtn.render(target);
    recoverAllBtn.render(target);
}




