//
// Created by Zheng on 20/12/2020.
//

#include "AchievementTab.h"

void AchievementTab::initAchievementsSlots() {
    if(!achievementsSlots.empty()){
        achievementsSlots.clear();
    }
    maxPage = 1;
    currentPage = 1;
    int max_per_page = 8;
    float modifierY = 80.f;
    float width = 600.f;
    float height = 70.f;
    int count = 0;
    for(const auto& i : achievementComponent->getAchievements()){
        achievementsSlots.push_back(
                std::make_unique<gui::AchievementSlot>(
                        width, height,
                        container.getPosition().x + 35.f,
                        container.getPosition().y + 70.f + (modifierY * (float)count),
                        font, i, achievementComponent->getAchievementEventValue(i->getAchievementEventType())
        ));
        count++;
        if(count == max_per_page){
            maxPage++;
            count = 0;
        }
    }
}

AchievementTab::AchievementTab(const shared_ptr<sf::RenderWindow> &window, sf::Font *font, State *state,
                               std::shared_ptr<AchievementComponent> achievementComponent) :
                               achievementComponent(std::move(achievementComponent)), window(window), font(font){
    gState = dynamic_cast<GameState*>(state);

    //init background
    background.setSize(sf::Vector2f(
            static_cast<float>(window->getSize().x),
            static_cast<float>(window->getSize().y)));
    background.setFillColor(sf::Color(20, 20, 20, 100));

    //init container
    container.setSize(sf::Vector2f(670.f,820.f));
    container.setFillColor(sf::Color(20, 20, 20, 200));
    container.setOutlineColor(sf::Color(20, 20, 20));
    container.setOutlineThickness(5.f);
    container.setPosition(sf::Vector2f(
            static_cast<float>(window->getSize().x) / 2.f - container.getSize().x / 2.f,
            40.f));

    //init text
    containerTitle.setFont(*this->font);
    containerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    containerTitle.setCharacterSize(35);
    containerTitle.setString("Achievements");
    containerTitle.setPosition(
            container.getPosition().x + (container.getGlobalBounds().width/2.f) - (containerTitle.getGlobalBounds().width/2.f),
            container.getPosition().y + 10.f);

    pageLbl.setFont(*this->font);
    pageLbl.setCharacterSize(25);
    pageLbl.setString("99/99");
    pageLbl.setPosition(container.getPosition().x + container.getGlobalBounds().width/2.f - pageLbl.getGlobalBounds().width/2.f,
                        container.getPosition().y + container.getGlobalBounds().height - 50.f);

    textLbl.setFont(*this->font);
    textLbl.setCharacterSize(20);
    textLbl.setStyle(sf::Text::Bold);
    textLbl.setString("99/99 Achievements unlocked\n"
                            "Exp & Gold bonus: x1.0");
    textLbl.setPosition(container.getPosition().x + 35,
                        pageLbl.getPosition().y - textLbl.getGlobalBounds().height - 10.f);

    nextPageBtn = std::make_unique<gui::Button>(pageLbl.getPosition().x + pageLbl.getGlobalBounds().width + 20.f, pageLbl.getPosition().y,
                              pageLbl.getGlobalBounds().height, pageLbl.getGlobalBounds().height,
                              this->font, "=>", 25);

    previousPageBtn = std::make_unique<gui::Button>(pageLbl.getPosition().x - pageLbl.getGlobalBounds().height - 20.f, pageLbl.getPosition().y,
                                  pageLbl.getGlobalBounds().height, pageLbl.getGlobalBounds().height,
                                  this->font, "<=", 25);
    nextPageBtn->setIdleTextColor(sf::Color::Blue);
    previousPageBtn->setIdleTextColor(sf::Color::Blue);

    //inits
    initAchievementsSlots();
    updatePageLbl();
    updateTextLbl();
}

AchievementTab::~AchievementTab() = default;

bool AchievementTab::closeTabByClicking(const sf::Vector2f &mousePos, gui::Button *achievementTab_Btn) {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
           background.getGlobalBounds().contains(mousePos)
           && !container.getGlobalBounds().contains(mousePos) && !achievementTab_Btn->contains(mousePos);
}

void AchievementTab::updateAchievementsSlots(bool achieved) {
    for(auto &i : achievementsSlots){
        i->updateAchievement(achievementComponent->getAchievementEventValue(i->getAchievementEventType()), achieved);
    }
}

void AchievementTab::updateAchievementsSlot(achievement_event event_type) {
    for(auto &i : achievementsSlots){
        if(i->getAchievementEventType() == event_type){
            i->updateAchievement(achievementComponent->getAchievementEventValue(i->getAchievementEventType()));
        }
    }
}

void AchievementTab::updateTextLbl() {
    std::stringstream ss;
    achievementComponent->calculateExpGoldBonus();
    float bonus = achievementComponent->getExpGoldBonus();
    ss << achievementComponent->getUnlockedAchievementsSize() << "/" << achievementComponent->getAchievementsSize()
        << " Achievements unlocked" << std::endl
        << "Exp & Gold bonus: x" << bonus;
    textLbl.setString(ss.str());
}

void AchievementTab::updateInputs() {
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::O) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) &&
       gState->getKeyTime()){
        gState->changeStato(NO_TAB);
    }
}

void AchievementTab::updatePageLbl() {
    stringstream ss;
    ss << currentPage << "/" << maxPage;
    pageLbl.setString(ss.str());
    pageLbl.setPosition(container.getPosition().x + container.getGlobalBounds().width/2.f - pageLbl.getGlobalBounds().width/2.f,
                        container.getPosition().y + container.getGlobalBounds().height - 50.f);
    nextPageBtn->setPosition(pageLbl.getPosition().x + pageLbl.getGlobalBounds().width + 20.f, pageLbl.getPosition().y);
    previousPageBtn->setPosition(pageLbl.getPosition().x - pageLbl.getGlobalBounds().height - 20.f, pageLbl.getPosition().y);
}

void AchievementTab::updateButtons() {
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

void AchievementTab::update(const sf::Vector2f &mousePos) {
    updateInputs();
    updateButtons();
    nextPageBtn->update(mousePos);
    previousPageBtn->update(mousePos);
   /* for (int i = (currentPage - 1) * 8; i < ((currentPage) * 8); i++) {
        if (i < achievementsSlots.size() && i >= 0){
            achievementsSlots[i]->update(mousePos);
        }
    }*/
}

void AchievementTab::render(sf::RenderTarget &target) {
    target.draw(background);
    target.draw(container);
    target.draw(containerTitle);
    target.draw(textLbl);
    target.draw(pageLbl);
    nextPageBtn->render(target);
    previousPageBtn->render(target);
    for (int i = (currentPage - 1) * 8; i < ((currentPage) * 8); i++) {
        if (i < achievementsSlots.size() && i >= 0)
            achievementsSlots[i]->render(target);
    }
}



