//
// Created by Zheng on 25/12/2020.
//

#include "LoadSaveTab.h"

#include <utility>

void LoadSaveTab::initSlots() {
    float x = container.getPosition().x + 10.f;
    float y = containerTitle.getPosition().y + 65.f;
    float mod_y = 120.f;
    for(auto i = 0 ; i < 5 ; i++){
        slots.push_back(std::make_shared<gui::LoadSaveSlot>(x,y + (mod_y * i), 680.f, 100.f, font));
    }
}

//constructors/destructor
LoadSaveTab::LoadSaveTab(const std::shared_ptr<sf::RenderWindow>& window, std::shared_ptr<ResourcesHandler> rs_handler,
                         sf::Font* font, State* state) : font(font), state(state), rsHandler(std::move(rs_handler)){
    //init background
    background.setSize(sf::Vector2f(
            static_cast<float>(window->getSize().x),
            static_cast<float>(window->getSize().y)));
    background.setFillColor(sf::Color(20, 20, 20, 100));
    //init container
    container.setSize(sf::Vector2f(700.f,750.f));
    container.setFillColor(sf::Color(50, 50, 50));
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
    containerTitle.setString("Saves");
    containerTitle.setPosition(
            container.getPosition().x + (container.getGlobalBounds().width/2.f) - (containerTitle.getGlobalBounds().width/2.f),
            container.getPosition().y + 10.f);

    backBtn = std::make_unique<gui::Button>(container.getPosition().x + container.getGlobalBounds().width/2.f - 75.f,
                          container.getPosition().y + container.getGlobalBounds().height - 80.f,
                          150.f, 40.f, this->font, "Back", 30);

    initSlots();
}

LoadSaveTab::~LoadSaveTab() = default;

//accessor
void LoadSaveTab::setState(State *new_state) {
    state = new_state;
}

bool LoadSaveTab::isHide() const {
    return hide;
}

void LoadSaveTab::setHide(bool b) {
    hide = b;
}

//functions
void LoadSaveTab::generateSave() {
    std::time_t result = std::time(nullptr);
    Save new_save = Save("save001", std::asctime(std::localtime(&result)), rsHandler->getGameVersion());
    auto* game_state = dynamic_cast<GameState*>(state);
    new_save.saveRsHandlerInfo(game_state->getResourceHandler());
    new_save.savePlayerInfo(game_state->getPlayer());

    SavesHandler().write(new_save);
    std::cout<<new_save.toString();
}

void LoadSaveTab::loadSave() {
    if(state->getStateEnum() == MAINMENU_STATE){
        std::cout << "Loading save from MainMenuState" << std::endl;
        SavesHandler().read();
    }else if(state->getStateEnum() == GAME_STATE){
        std::cout << "Loading save from GameState" << std::endl;
        SavesHandler().read();
    }

}

void LoadSaveTab::setAccessOption(save_load_option option) {
    switch(option){
        case LOAD_SAVE:{
            for(const auto& i : slots){
                i->setLoadBtnDisabled(false);
                i->setSaveBtnDisabled(false);
            }
            break;
        }
        case SAVE_ONLY:{
            for(const auto& i : slots){
                i->setLoadBtnDisabled(true);
                i->setSaveBtnDisabled(false);
            }
            break;
        }
        case LOAD_ONLY:{
            for(const auto& i : slots){
                i->setLoadBtnDisabled(false);
                i->setSaveBtnDisabled(true);
            }
            break;
        }
        case NO_LOADSAVE:{
            for(const auto& i : slots){
                i->setLoadBtnDisabled(true);
                i->setSaveBtnDisabled(true);
            }
            break;
        }
    }
}

void LoadSaveTab::updateButtons(const sf::Vector2f &mousePos) {
    if(backBtn->isPressed() && state->getKeyTime()){
        hide = true;
    }
    for(const auto& i : slots){
        if(i->saveBtnIsPressed() && state->getKeyTime()){
            i->setSaveBtnDisabled(BTN_IDLE);
            generateSave();
            std::cout<<"Saving..."<<std::endl;
        }
        if(i->loadBtnIsPressed() && state->getKeyTime()){
            i->setLoadBtnDisabled(BTN_IDLE);
            loadSave();
            std::cout<<"Loading..."<<std::endl;
        }
    }
}

void LoadSaveTab::update(const sf::Vector2f &mousePos) {
    updateButtons(mousePos);
    backBtn->update(mousePos);
    for(const auto& i : slots)
        i->update(mousePos);
}

void LoadSaveTab::render(sf::RenderTarget &target) {
    target.draw(background);
    target.draw(container);
    target.draw(containerTitle);
    backBtn->render(target);
    for(const auto& i : slots)
        i->render(target);
}
