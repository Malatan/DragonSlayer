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
    if(!this->font.loadFromFile("../Fonts/WISHFULWAVES.ttf")){
        throw("Errore: mainmenustate could not load font");
    }
}

void MainMenuState::initButtons() {
   /* this->buttons["GAME_STATE"] = new gui::Button(325.f, 190.f, 150.f, 50.f,
                                                  &this->font, "Start Game", 20,
                                                  sf::Color(200, 200, 200, 200),
                                                  sf::Color(250, 250, 250, 250),
                                                  sf::Color(20, 20, 20, 50),

                                                  sf::Color(70, 70, 70, 0),
                                                  sf::Color(150, 150, 150, 0),
                                                  sf::Color(20, 20, 20, 0));

    this->buttons["EXIT_STATE"] = new gui::Button(325.f, 480.f, 150.f, 50.f,
                                                  &this->font, "Quit", 20,
                                                  sf::Color(200, 200, 200, 200),
                                                  sf::Color(250, 250, 250, 250),
                                                  sf::Color(20, 20, 20, 50),

                                                  sf::Color(70, 70, 70, 0),
                                                  sf::Color(150, 150, 150, 0),
                                                  sf::Color(20, 20, 20, 0));*/
}

MainMenuState::MainMenuState(sf::RenderWindow *window, std::stack<State*>* states)
        : State(window, states){
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initButtons();
}

MainMenuState::~MainMenuState() {
 /*   auto it = this->buttons.begin();
    for(it = this->buttons.begin(); it != this->buttons.end(); ++it){
        delete it->second;
    }*/
}

void MainMenuState::updateInput(const float &dt) {

}

void MainMenuState::updateButtons() {
/*    // updates all the buttons
    for (auto &it : this->buttons){
        it.second->update((this->mousePosView));
    }

    //new game
    if(this->buttons["GAME_STATE"]->isPressed()){
        this->states->push(new GameState(this->window, this->supportedKeys, this->states));
    }

    //quit the game
    if(this->buttons["EXIT_STATE"]->isPressed()){
        this->endState();
    }*/
}

void MainMenuState::update(const float &dt) {
    this->updateMousePosition();
    this->updateInput(dt);
    this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget& target) {
 /*   for (auto &it : this->buttons){
        it.second->render(target);
    }*/
}

void MainMenuState::render(sf::RenderTarget *target) {
    if(!target){
        target = this->window;
    }

    target->draw(this->background);
    this->renderButtons(*target);

    //debbuging tool: show mouse pos coords
    sf::Text mouseText;
    mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 15);
    mouseText.setFont(this->font);
    mouseText.setCharacterSize(14);
    std::stringstream ss;
    ss << this->mousePosView.x << " " << this->mousePosView.y;
    mouseText.setString(ss.str());
    target->draw(mouseText);

}