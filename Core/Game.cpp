//
// Created by Zheng on 06/10/2020.
//

#include <iostream>
#include "Game.h"
bool debug;
bool noclip;

void Game::initVariables(bool unit_testing) {
    debug = false;
    noclip = false;
    dt = 0.f;
    rsHandler = std::make_shared<ResourcesHandler>();
    rsHandler->setUnitTesting(unit_testing);
}

void Game::initWindow() {
    std::string config_path;
    std::string icon_path;
    if(rsHandler->isUnitTesting()){
        config_path = "../../Resources/Config/window.ini";
        icon_path = "../../Resources/Images/dragon.png";
    }else{
        config_path = "../Resources/Config/window.ini";
        icon_path = "../Resources/Images/dragon.png";
    }
    std::ifstream ifs(config_path);

    std::string window_title = "None";
    sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
    unsigned framerate_limit = 144;
    bool veritcal_enabled = false;
    unsigned antialiasing_level = 0;

    if(ifs.is_open()){
        std::getline(ifs,window_title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> veritcal_enabled;
        ifs >> antialiasing_level;
        ifs >> debugAccess;
    } else{
        std::cerr<<"window.ini not found. Default settings applied"<< std::endl;
    }
    ifs.close();
    auto image = sf::Image{};
    if (!image.loadFromFile(icon_path)){
        std::cerr<<"Could not load icon png file " << icon_path << std::endl;
    }
    window_title += " v" + rsHandler->getGameVersion();
    windowSettings.antialiasingLevel = antialiasing_level;
    window = std::make_shared<sf::RenderWindow>(window_bounds, window_title, sf::Style::Close, windowSettings);
    window->setFramerateLimit(framerate_limit);
    window->setVerticalSyncEnabled(veritcal_enabled);
    window->setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
}

void Game::initStates() {
    states.push(std::make_unique<MainMenuState>(window, &states, rsHandler, MAINMENU_STATE));
}

//Constructors/Destructors
Game::Game(bool unit_testing) {
    initVariables(unit_testing);
    initWindow();
    initStates();
}

Game::~Game() = default;

void Game::updateDt() {
    dt = dtClock.restart().asSeconds();
}

//Functions
void Game::endApplication() {
    std::cout << "Ending Application" << "\n";
}

void Game::updateInput() {
    if(!states.empty()){
        if(debugAccess){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Home) && states.top()->getKeyTime()){
                debug = !debug;
                states.top()->enableDisableDebugTool();
            }
        }
    }
}

void Game::updateSFMLEvents() {
    while(window->pollEvent(sfEvent)) {
        switch (sfEvent.type) {
            case sf::Event::Closed:       //check for CLOSED event
                window->close();
                break;
            default:
                break;
        }
    }
}

void Game::update() {
    updateSFMLEvents();
    if(!states.empty()){
        if (window->hasFocus()) {
            updateInput();
            states.top()->update(dt);
            if(states.top()->getQuit()) {
                states.top()->endState();
                states.pop();
            }
        }
    } else{
        //application end
        endApplication();
        window->close();
    }
}

void Game::testUpdate() {
    if(!states.empty()){
        states.top()->update(dt);
        if(states.top()->getQuit()) {
            states.top()->endState();
            states.pop();
        }
    } else{
        endApplication();
        window->close();
    }
}

void Game::render() {
    window->clear();

    //Render items
    if(!states.empty()){
        states.top()->render(nullptr);
    }

    window->display();
}

void Game::run() {
    while(window->isOpen()){
        updateDt();
        update();
        render();
    }
}

void Game::testRun(bool do_render) {
    updateDt();
    testUpdate();
    if(do_render)
        render();
}

shared_ptr<sf::RenderWindow> Game::getWindow(){
    return window;
}

State *Game::getTopState() {
    return states.top().get();
}

float Game::getDt() const {
    return dt;
}




