//
// Created by Zheng on 24/10/2020.
//

#include "WizardTab.h"

void WizardTab::initWizardSpellSlots() {
    //init spellslots
    if(!spellSlots.empty()){
        spellSlots.clear();
    }

    int max_per_row = 3;
    float modifierX = 375.f;
    float modifierY = 100.f;
    float yMultiplier = 0;
    int count = 0;
    for(const auto& i : spellComponent->getPlayerSpells()){
        if((count % max_per_row) == 0 && count != 0){
            yMultiplier ++;
        }
        spellSlots.push_back(std::make_shared<gui::WizardSpellSlot>(350.f, 80.f,
                container.getPosition().x + 35.f + (modifierX * (float)(count % max_per_row)),
                container.getPosition().y + 80.f + (modifierY * yMultiplier) ,
                i, &textures["ITEMS_SHEET"], 34.f, font, 18
        ));
        count++;
    }
}

//constructors/destructor
WizardTab::WizardTab(const std::shared_ptr<sf::RenderWindow>& window, sf::Font* font, std::shared_ptr<Player> player, State *state,
                     std::map<std::string, sf::Texture> textures)
        : textures(std::move(textures)), player(std::move(player)), font(font), window(window){
    gState = dynamic_cast<GameState*>(state);
    spellComponent = gState->getSpellComponent();

    //init background
    background.setSize(sf::Vector2f(
            static_cast<float>(window->getSize().x),
            static_cast<float>(window->getSize().y)));
    background.setFillColor(sf::Color(20, 20, 20, 100));

    //init container
    container.setSize(sf::Vector2f(1170.f,820.f));
    container.setFillColor(sf::Color(20, 20, 20, 200));

    container.setPosition(sf::Vector2f(
            static_cast<float>(window->getSize().x) / 2.f - container.getSize().x / 2.f,
            40.f));

    //init text
    containerTitle.setFont(*this->font);
    containerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    containerTitle.setCharacterSize(40);
    containerTitle.setString("Wizard");
    containerTitle.setPosition(
            container.getPosition().x + (container.getGlobalBounds().width/2.f) - (containerTitle.getGlobalBounds().width/2.f),
            container.getPosition().y + 10.f);

    playerGoldLbl.setFont(*this->font);
    playerGoldLbl.setCharacterSize(30);
    playerGoldLbl.setPosition(container.getPosition().x + 20.f, 800.f);

    updateGoldLbl();
    initWizardSpellSlots();
    updateSpellInfo();
}

WizardTab::~WizardTab() = default;

//functions
void WizardTab::updateSpellInfo() {
    for(const auto& i : spellSlots){
        (i->getSpellDescriptionLbl())->clear();
        if(i->getSpell()->isMaxed() && i->getSpell()->isLearned()){
            *(i->getSpellDescriptionLbl()) << sf::Text::Bold << sf::Color::White << i->getSpell()->getName()
            << " (Lv." << to_string(i->getSpell()->getLevel()) << ")"
            << sf::Text::Regular << "\nCost: - ";
        } else if(i->getSpell()->isLearned()) {
            *(i->getSpellDescriptionLbl()) << sf::Text::Bold << sf::Color::White << i->getSpell()->getName()
            << " (Lv." << to_string(i->getSpell()->getLevel()) << ")"
            << sf::Text::Regular << "\nCost: " << sf::Color::Yellow << to_string(i->getSpell()->getLearnCost()*(i->getSpell()->getLevel()+1))
            << " gold";
        } else{
            *(i->getSpellDescriptionLbl()) << sf::Text::Bold << sf::Color::White << i->getSpell()->getName()
            << " (Lv." << to_string(i->getSpell()->getLevel()-1) << ")"
            << sf::Text::Regular << "\nCost: " << sf::Color::Yellow << to_string(i->getSpell()->getLearnCost()*i->getSpell()->getLevel())
            << " gold";
        }
    }
}

bool WizardTab::closeTabByClicking(const sf::Vector2f& mousePos) {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
           background.getGlobalBounds().contains(mousePos)
           && !container.getGlobalBounds().contains(mousePos);
}

void WizardTab::updateGoldLbl() {
    std::stringstream ss;
    std::string gold = to_string(player->getGold());
    unsigned len = gold.length();

    for(int index =(int) len-3; index > 0; index -= 3)
        gold.insert(index, ",");
    ss << "Gold: " << gold;

    playerGoldLbl.setString(ss.str());
}

void WizardTab::updateSpellLevel(const std::shared_ptr<gui::WizardSpellSlot>& i) {
    int upgrade_cost;
    if(i->getSpell()->isLearned())
        upgrade_cost = i->getSpell()->getLearnCost()*(i->getSpell()->getLevel()+1);
    else
        upgrade_cost = i->getSpell()->getLearnCost()*i->getSpell()->getLevel();

    if(player->getGold() >= upgrade_cost){
        player->minusGold(upgrade_cost);

        if(i->getSpell()->isLearned())
            i->getSpell()->levelUp();
        else{
            i->getSpell()->setLearned(true);
            gState->getSpellTab()->initSpellSlots();
        }


        i->updateBtnText();
        i->updateSpellInfo();
        updateSpellInfo();
        gState->updateTabsGoldLbl();
        gState->getSpellTab()->updateSpellsInfoLbl();
        gState->getPopUpTextComponent()->addPopUpTextCenter(DEFAULT_TAG, i->getSpell()->getName(), "", " lv + 1 !");
    }else{
        gState->getPopUpTextComponent()->addPopUpTextCenter(DEFAULT_TAG, "Insufficient Gold", "", "");
    }

}

void WizardTab::update(const sf::Vector2f &mousePos) {
    for(const auto& i : spellSlots){
        i->update(mousePos);
        if(i->isBtnPressed() && gState->getKeyTime()){
            updateSpellLevel(i);
        }
    }
}

void WizardTab::render(sf::RenderTarget &target) {
    target.draw(background);
    target.draw(container);
    target.draw(containerTitle);
    target.draw(playerGoldLbl);
    for(const auto& i : spellSlots){
        i->render(target);
    }
}






