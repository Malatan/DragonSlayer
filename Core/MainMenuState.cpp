//
// Created by Zheng on 06/10/2020.
//

#include "MainMenuState.h"

void MainMenuState::initVariables() {
    this->background.setSize(
            sf::Vector2f(
                    static_cast<float>(this->window->getSize().x),
                    static_cast<float>(this->window->getSize().y)));

    if(!this->backgroundTexture.loadFromFile("../Resources/Images/Backgrounds/mainMenuBG.png")){
        throw("Errore mainmenustate failed to load background texture");
    }
    this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initBackground() {

}

void MainMenuState::initFonts() {
    if(!this->font.loadFromFile("../Fonts/BreatheFire-65pg.ttf")){
        throw("Errore: mainmenustate could not load font");
    }
}

void MainMenuState::initButtons() {
    float centerX = this->window->getSize().x / 2.f;
    float percentY = (this->window->getSize().y)/100.f;
    float btnWidth = 200.f;
    float btnHeight = 40.f;
    sf::Color text_idle_color = sf::Color(71, 17, 13,250);
    sf::Color text_hover_color = sf::Color(250, 250, 250, 250);
    sf::Color text_active_color = sf::Color(20, 20, 20, 50);

    sf::Color idle_color = sf::Color::Transparent;
    sf::Color hover_color = sf::Color(150, 150, 150, 0);
    sf::Color active_color = sf::Color(20, 20, 20, 0);

    this->buttons["GAME_STATE"] = new gui::Button(centerX - (btnWidth/2.f), percentY * 70.f , btnWidth, btnHeight,
                                                  &this->font, "Start Game", 40,
                                                  text_idle_color ,text_hover_color, text_active_color,
                                                  idle_color, hover_color, active_color);

    this->buttons["EXIT_STATE"] = new gui::Button(centerX - (btnWidth/2.f), percentY * 80.f, btnWidth, btnHeight,
                                                  &this->font, "Quit", 40,
                                                  text_idle_color ,text_hover_color, text_active_color,
                                                  idle_color, hover_color, active_color);
}

MainMenuState::MainMenuState(sf::RenderWindow *window, std::stack<State*>* states)
        : State(window, states){
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initButtons();
}

MainMenuState::~MainMenuState() {
    auto it = this->buttons.begin();
    for(it = this->buttons.begin(); it != this->buttons.end(); ++it){
        delete it->second;
    }
}

void MainMenuState::updateInput(const float &dt) {

}

void MainMenuState::updateButtons() {
    // Aggiorna tutti i buttoni
    for (auto &it : this->buttons){
        it.second->update((this->mousePosView));
    }

    //Nuovo gioco
    if(this->buttons["GAME_STATE"]->isPressed()){
        this->states->push(new GameState(this->window, this->states, &this->font));
    }

    //Esce dal gioco
    if(this->buttons["EXIT_STATE"]->isPressed()){
        this->endState();
    }
}

void MainMenuState::update(const float &dt) {
    this->updateMousePosition();
    this->updateInput(dt);
    this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget& target) {
    for (auto &it : this->buttons){
        it.second->render(target);
    }
}

void MainMenuState::render(sf::RenderTarget *target) {
    if(!target){
        target = this->window;
    }

    target->draw(this->background);
    this->renderButtons(*target);

    //tool per il debug : mostre le coordinate del mouse
    sf::Text mouseText;
    mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 15);
    mouseText.setFont(this->font);
    mouseText.setCharacterSize(14);
    std::stringstream ss;
    ss << this->mousePosView.x << " " << this->mousePosView.y;
    mouseText.setString(ss.str());
    target->draw(mouseText);

}