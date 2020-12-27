//
// Created by Zheng on 24/10/2020.
//

#include "WizardTab.h"

void WizardTab::initWizardSpellSlots() {
    //init spellslots
    if(!spellSlots.empty()){
        spellSlots.clear();
    }
    maxPage = 1;
    currentPage = 1;
    int max_per_page = 4;
    float modifierY = 100.f;
    float width = 600.f;
    float height = 80.f;
    int count = 0;
    for(const auto& i : spellComponent->getPlayerSpells()){
        spellSlots.push_back(std::make_shared<gui::WizardSpellSlot>(width, height,
                container.getPosition().x + 35.f,
                container.getPosition().y + 80.f + (modifierY * (float)count) ,
                i, &textures["ITEMS_SHEET"], 34.f, font, 18
        ));
        count++;
        if(count == max_per_page){
            maxPage++;
            count = 0;
        }
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
    container.setSize(sf::Vector2f(670.f,580.f));
    container.setFillColor(sf::Color(20, 20, 20, 200));
    container.setPosition(sf::Vector2f(
            static_cast<float>(window->getSize().x)/2.f - container.getGlobalBounds().width/2.f,
            static_cast<float>(window->getSize().y)/2.f - container.getGlobalBounds().height/2.f
            ));
    container.setOutlineThickness(5.f);
    container.setOutlineColor(sf::Color(10, 10, 10));
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
    playerGoldLbl.setPosition(container.getPosition().x + 20.f, container.getPosition().y + 480.f);
    playerGoldLbl.setString("Gold: 0");

    pageLbl.setFont(*this->font);
    pageLbl.setCharacterSize(25);
    pageLbl.setString("1/1");
    pageLbl.setPosition(container.getPosition().x + container.getGlobalBounds().width/2.f - pageLbl.getGlobalBounds().width/2.f,
                        playerGoldLbl.getPosition().y + playerGoldLbl.getGlobalBounds().height + 20.f);

    nextPageBtn = std::make_unique<gui::Button>(pageLbl.getPosition().x + pageLbl.getGlobalBounds().width + 20.f, pageLbl.getPosition().y,
                              pageLbl.getGlobalBounds().height, pageLbl.getGlobalBounds().height,
                              this->font, "=>", 25);

    previousPageBtn = std::make_unique<gui::Button>(pageLbl.getPosition().x - pageLbl.getGlobalBounds().height - 20.f, pageLbl.getPosition().y,
                                  pageLbl.getGlobalBounds().height, pageLbl.getGlobalBounds().height,
                                  this->font, "<=", 25);
    updateGoldLbl();
    initWizardSpellSlots();
    updatePageLbl();
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
        if(i->getSpell()->isMaxed() && i->getSpell()->isLearned()){
            gState->notify(AE_P_MAXEDSPELL, spellComponent->maxedPlayerSpellsSize());
        }
        gState->updateTabsGoldLbl();
        gState->getSpellTab()->updateSpellsInfoLbl();
        gState->getPopUpTextComponent()->addPopUpTextCenter(DEFAULT_TAG, i->getSpell()->getName(), "", " lv + 1 !");
    }else{
        gState->getPopUpTextComponent()->addPopUpTextCenter(DEFAULT_TAG, "Insufficient Gold", "", "");
    }

}

void WizardTab::updatePageLbl() {
    stringstream ss;
    ss << currentPage << "/" << maxPage;
    pageLbl.setString(ss.str());
}

void WizardTab::updateButtons(const sf::Vector2f &mousePos) {
    nextPageBtn->update(mousePos);
    previousPageBtn->update(mousePos);
    if(nextPageBtn->isPressed() && gState->getKeyTime()){
        nextPageBtn->setButtonState(BTN_IDLE);
        if(currentPage < maxPage){
            currentPage++;
            updatePageLbl();
        }
    }else if(previousPageBtn->isPressed() && gState->getKeyTime()){
        previousPageBtn->setButtonState(BTN_IDLE);
        if(currentPage > 1){
            currentPage--;
            updatePageLbl();
        }
    }
}

void WizardTab::update(const sf::Vector2f &mousePos) {
    updateButtons(mousePos);
    updateInputs();
    for (int i = (currentPage - 1) * 4; i < ((currentPage) * 4); i++) {
        if (i < spellSlots.size() && i >= 0){
            spellSlots[i]->update(mousePos);
            if(spellSlots[i]->isBtnPressed() && gState->getKeyTime()){
                updateSpellLevel(spellSlots[i]);
            }
        }
    }
}

void WizardTab::render(sf::RenderTarget &target) {
    target.draw(background);
    target.draw(container);
    target.draw(containerTitle);
    target.draw(playerGoldLbl);
    target.draw(pageLbl);
    nextPageBtn->render(target);
    previousPageBtn->render(target);
    for (int i = (currentPage - 1) * 4; i < ((currentPage) * 4); i++) {
        if (i < spellSlots.size() && i >= 0)
            spellSlots[i]->render(target);
    }
}

void WizardTab::updateInputs() {
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::E) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) &&
       gState->getKeyTime()){
        gState->changeStato(NO_TAB);
    }
}









