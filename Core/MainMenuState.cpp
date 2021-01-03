//
// Created by Zheng on 06/10/2020.
//

#include "MainMenuState.h"

void MainMenuState::initResources() {
    rsHandler->addResource("../Resources/Images/Backgrounds/mainMenuBG.png",
                           "mainmenu background", "MainMenuState");

    if(!font.loadFromFile("../Resources/Fonts/BreatheFire-65pg.ttf")){
        std::cerr<<"Errore: mainmenustate could not load font" << std::endl;
    }
}

void MainMenuState::initLoadingScreen() {
    loadingBackground.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    loadingBackground.setFillColor(sf::Color(30, 30, 30));
    textLbl.setFont(font);
    textLbl.setCharacterSize(100);
    textLbl.setString("Loading...");
    textLbl.setPosition(window->getSize().x/2.f - textLbl.getGlobalBounds().width/2.f,
                        window->getSize().y/2.f - textLbl.getGlobalBounds().height/2.f);
}

void MainMenuState::initBackground() {
    background.setSize(
            sf::Vector2f(
                    static_cast<float>(window->getSize().x),
                    static_cast<float>(window->getSize().y)));
    backgroundTexture.loadFromImage(rsHandler->getResourceByKey("mainmenu background")->getImage());
    background.setTexture(&backgroundTexture);

    versionLbl.setFont(font);
    versionLbl.setCharacterSize(25);
    versionLbl.setStyle(sf::Text::Italic);
    versionLbl.setString("v" + rsHandler->getGameVersion());
    versionLbl.setPosition(1000.f, 200.f);
}

void MainMenuState::initButtons() {
    float percentY = (window->getSize().y)/100.f;
    float btnWidth = 100.f;
    float btnHeight = 40.f;
    sf::Color text_idle_color =  sf::Color(250, 250, 250, 250);
    sf::Color text_hover_color = sf::Color(14, 12, 18,250);
    sf::Color text_active_color = sf::Color(20, 20, 20, 50);

    sf::Color idle_color = sf::Color::Transparent;
    sf::Color hover_color = sf::Color(150, 150, 150, 0);
    sf::Color active_color = sf::Color(20, 20, 20, 0);

    buttons["GAME_STATE"] = gui::Button(375.f, percentY * 60.f , btnWidth, btnHeight,
                                        &font, "New", 40,
                                        text_idle_color ,text_hover_color, text_active_color,
                                        idle_color, hover_color, active_color);

    buttons["LOAD_TAB"] = gui::Button(375.f, percentY * 70.f , btnWidth, btnHeight,
                                        &font, "Load", 40,
                                        text_idle_color ,text_hover_color, text_active_color,
                                        idle_color, hover_color, active_color);

    buttons["EXIT_STATE"] = gui::Button(375, percentY * 80.f, btnWidth, btnHeight,
                                        &font, "Quit", 40,
                                        text_idle_color ,text_hover_color, text_active_color,
                                        idle_color, hover_color, active_color);

}

void MainMenuState::initLoadSaveTab() {
    loadSaveTab = std::make_shared<LoadSaveTab>(window, rsHandler, popUpTextComponent, &font, this);
    loadSaveTab->setAccessOption(LOAD_ONLY);
}

void MainMenuState::initComponents() {
    popUpTextComponent = std::make_shared<PopUpTextComponent>(font, window);
}

MainMenuState::MainMenuState(std::shared_ptr<sf::RenderWindow> window, std::stack<std::unique_ptr<State>>* states,
        std::shared_ptr<ResourcesHandler> rsHandler, state_enum _state_enum)
        : State(std::move(window), states, std::move(rsHandler), _state_enum){
    stateTab = NO_TAB;
    initResources();
    initBackground();
    initButtons();
    initComponents();
    initLoadSaveTab();
    initLoadingScreen();
}

MainMenuState::~MainMenuState() = default;

void MainMenuState::startGame() {
    loading = false;
    states->push(std::make_unique<GameState>(window, states, rsHandler, popUpTextComponent, loadSaveTab, &font, GAME_STATE));
}

void MainMenuState::updateInput(const float &dt) {

}

void MainMenuState::updateButtons() {
    if(loading){
        loading = true;
        startGame();
    }else{
        loading = loadSaveTab->canApplySave();
    }
    // Aggiorna tutti i buttoni
    for (auto &it : buttons){
        it.second.update((mousePosView));
    }

    //Nuovo gioco
    if(buttons["GAME_STATE"].isPressed() && getKeyTime()){
        loading = true;
    }

    //Esce dal gioco
    if(buttons["EXIT_STATE"].isPressed() && getKeyTime()){
        endState();
    }

    if(buttons["LOAD_TAB"].isPressed() && getKeyTime()){
        stateTab = LOADSAVE_TAB;
        loadSaveTab->setHide(false);
    }
}

void MainMenuState::renderButtons(sf::RenderTarget& target) {
    for (auto &it : buttons){
        it.second.render(target);
    }
}

void MainMenuState::update(const float &dt) {
    updateMousePosition(nullptr);
    updateKeyTime(dt);
    if(!loadSaveTab->stateMatch(getStateEnum())){
        loadSaveTab->setState(this);
    }
    if(loadSaveTab->getSLOption() != LOAD_ONLY){
        loadSaveTab->setAccessOption(LOAD_ONLY);
    }
    switch (stateTab) {
        case NO_TAB:
            updateInput(dt);
            updateKeyTime(dt);
            updateButtons();
            break;
        case LOADSAVE_TAB:
            loadSaveTab->update(mousePosView);
            if(loadSaveTab->isHide()){
                stateTab = NO_TAB;
                loadSaveTab->setHide(true);
            }
            break;
        default:
            break;
    }
    popUpTextComponent->update(dt);
}

void MainMenuState::render(sf::RenderTarget *target) {
    if(!target){
        target = window.get();
    }
    if(loading){
        target->draw(loadingBackground);
        target->draw(textLbl);
    }else{
        target->draw(background);
        target->draw(versionLbl);
        renderButtons(*target);
        switch (stateTab) {
            case LOADSAVE_TAB:
                loadSaveTab->render(*target);
                break;
            default:
                break;
        }
        popUpTextComponent->render(*target);
    }

}




