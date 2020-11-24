//
// Created by Zheng on 24/10/2020.
//

#include "WizardTab.h"

#include <utility>

void WizardTab::initWizardSpellSlots() {
    //init spellslots
    if(this->spellSlots.size() != 0){
        this->spellSlots.clear();
    }

    int max_per_row = 3;
    float modifierX = 375.f;
    float modifierY = 100.f;
    float yMultiplier = 0;
    int count = 0;
    for(auto i : this->spellComponent->getPlayerSpells()){
        if((count % max_per_row) == 0 && count != 0){
            yMultiplier ++;
        }
        this->spellSlots.push_back(new gui::WizardSpellSlot(350.f, 80.f,
                this->container.getPosition().x + 35.f + (modifierX * (count % max_per_row)),
                this->container.getPosition().y + 80.f + (modifierY * yMultiplier) ,
                i, &this->textures["ITEMS_SHEET"], 34.f, this->font, 18
        ));
        count++;
    }
}

//constructors/destructor
WizardTab::WizardTab(const std::shared_ptr<sf::RenderWindow>& window, sf::Font* font, std::shared_ptr<Player> player, State *state,
                     std::map<std::string, sf::Texture> textures)
        : textures(std::move(textures)), player(std::move(player)), font(font), window(window){
    gState = dynamic_cast<GameState*>(state);
    spellComponent = this->gState->getSpellComponent();

    //init background
    this->background.setSize(sf::Vector2f(
            static_cast<float>(window->getSize().x),
            static_cast<float>(window->getSize().y)));
    this->background.setFillColor(sf::Color(20, 20, 20, 100));

    //init container
    this->container.setSize(sf::Vector2f(1170.f,820.f));
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
    this->initWizardSpellSlots();
    this->updateSpellInfo();
}

WizardTab::~WizardTab() {
    for(auto i : this->spellSlots)
        delete i;
}

//functions
void WizardTab::updateSpellInfo() {
    for(auto i : this->spellSlots){
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
           this->background.getGlobalBounds().contains(mousePos)
           && !this->container.getGlobalBounds().contains(mousePos);
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

void WizardTab::updateSpellLevel(gui::WizardSpellSlot *i) {
    int upgrade_cost;
    if(i->getSpell()->isLearned())
        upgrade_cost = i->getSpell()->getLearnCost()*(i->getSpell()->getLevel()+1);
    else
        upgrade_cost = i->getSpell()->getLearnCost()*i->getSpell()->getLevel();

    if(this->player->getGold() >= upgrade_cost){
        this->player->minusGold(upgrade_cost);

        if(i->getSpell()->isLearned())
            i->getSpell()->levelUp();
        else{
            i->getSpell()->setLearned(true);
            this->gState->getSpellTab()->initSpellSlots();
        }


        i->updateBtnText();
        i->updateSpellInfo();
        this->updateSpellInfo();
        this->gState->updateTabsGoldLbl();
        this->gState->getSpellTab()->updateSpellsInfoLbl();
        this->gState->getPopUpTextComponent()->addPopUpTextCenter(DEFAULT_TAG, i->getSpell()->getName(), "", " lv + 1 !");
    }else{
        this->gState->getPopUpTextComponent()->addPopUpTextCenter(DEFAULT_TAG, "Insufficient Gold", "", "");
    }

}

void WizardTab::update(const sf::Vector2f &mousePos) {
    for(auto i : this->spellSlots){
        i->update(mousePos);
        if(i->isBtnPressed() && this->gState->getKeyTime()){
            this->updateSpellLevel(i);
        }
    }
}

void WizardTab::render(sf::RenderTarget &target) {
    target.draw(this->background);
    target.draw(this->container);
    target.draw(this->containerTitle);
    target.draw(this->playerGoldLbl);
    for(auto i : this->spellSlots){
        i->render(target);
    }
}






