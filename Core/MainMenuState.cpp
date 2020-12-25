//
// Created by Zheng on 06/10/2020.
//

#include "MainMenuState.h"

void MainMenuState::initResources() {
    rsHandler->addResource("../Resources/Images/Backgrounds/mainMenuBG.png",
                           "mainmenu background", "MainMenuState");

    if(!font.loadFromFile("../Resources/Fonts/BreatheFire-65pg.ttf")){
        std::cout<<"Errore: mainmenustate could not load font" << std::endl;
    }
}

void MainMenuState::initBackground() {
    background.setSize(
            sf::Vector2f(
                    static_cast<float>(window->getSize().x),
                    static_cast<float>(window->getSize().y)));
    backgroundTexture.loadFromImage(rsHandler->getResourceByKey("mainmenu background")->getImage());
    background.setTexture(&backgroundTexture);
}

void MainMenuState::initButtons() {
    float centerX = window->getSize().x / 2.f;
    float percentY = (window->getSize().y)/100.f;
    float btnWidth = 200.f;
    float btnHeight = 40.f;
    sf::Color text_idle_color =  sf::Color(250, 250, 250, 250);
    sf::Color text_hover_color = sf::Color(14, 12, 18,250);
    sf::Color text_active_color = sf::Color(20, 20, 20, 50);

    sf::Color idle_color = sf::Color::Transparent;
    sf::Color hover_color = sf::Color(150, 150, 150, 0);
    sf::Color active_color = sf::Color(20, 20, 20, 0);

    buttons["GAME_STATE"] = gui::Button(375.f, percentY * 70.f , btnWidth, btnHeight,
                                        &font, "Start Game", 40,
                                        text_idle_color ,text_hover_color, text_active_color,
                                        idle_color, hover_color, active_color);

    buttons["EXIT_STATE"] = gui::Button(375, percentY * 80.f, btnWidth, btnHeight,
                                        &font, "Quit", 40,
                                        text_idle_color ,text_hover_color, text_active_color,
                                        idle_color, hover_color, active_color);

}

MainMenuState::MainMenuState(std::shared_ptr<sf::RenderWindow> window, std::stack<std::unique_ptr<State>>* states,
        std::shared_ptr<ResourcesHandler> rsHandler, state_enum _state_enum)
        : State(std::move(window), states, std::move(rsHandler), _state_enum){
    initResources();
    initBackground();
    initButtons();
}

MainMenuState::~MainMenuState() = default;

void MainMenuState::startNewGame() {
    states->push(std::make_unique<GameState>(window, states, rsHandler, &font, GAME_STATE));
}

void MainMenuState::updateInput(const float &dt) {

}

void MainMenuState::updateButtons() {
    // Aggiorna tutti i buttoni
    for (auto &it : buttons){
        it.second.update((mousePosView));
    }

    //Nuovo gioco
    if(buttons["GAME_STATE"].isPressed()){
        startNewGame();
    }

    //Esce dal gioco
    if(buttons["EXIT_STATE"].isPressed()){
        endState();
    }
}

void MainMenuState::update(const float &dt) {
    updateMousePosition(nullptr);
    updateInput(dt);
    updateKeyTime(dt);
    updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget& target) {
    for (auto &it : buttons){
        it.second.render(target);
    }
}

void MainMenuState::render(sf::RenderTarget *target) {
    if(!target){
        target = window.get();
    }

    target->draw(background);
    renderButtons(*target);

  /*  //tool per il debug : mostre le coordinate del mouse
    sf::Text mouseText;
    mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 15);
    mouseText.setFont(this->font);
    mouseText.setCharacterSize(14);
    std::stringstream ss;
    ss << this->mousePosView.x << " " << this->mousePosView.y;
    mouseText.setString(ss.str());
    target->draw(mouseText);*/

}




