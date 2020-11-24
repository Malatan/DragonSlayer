//
// Created by Zheng on 06/10/2020.
//

#include <iostream>
#include "Game.h"

void Game::initVariables() {
    window = NULL;
    dt = 0.f;
}

void Game::initWindow() {
    std::ifstream ifs("../Resources/Config/window.ini");
    videomodes = sf::VideoMode::getFullscreenModes();

    Title = "None";
    sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
    unsigned framerate_limit = 144;
    bool veritcal_enabled = false;
    unsigned antialiasing_level = 0;

    if(ifs.is_open()){
        std::getline(ifs,Title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> veritcal_enabled;
        ifs >> antialiasing_level;
    } else{
        std::cout<<"window.ini not found"<<"\n";
    }
    ifs.close();

    windowSettings.antialiasingLevel = antialiasing_level;
    window = std::make_shared<sf::RenderWindow>(window_bounds,
                                        Title,
                                        sf::Style::Close,
                                        windowSettings);
    window->setFramerateLimit(framerate_limit);
    window->setVerticalSyncEnabled(veritcal_enabled);
    rtc = std::make_shared<RunTimeClock>();
    rsHandler = std::make_shared<ResourcesHandler>();
}


void Game::initStates() {
    states.push(std::make_unique<MainMenuState>(window, &states, rsHandler));
}

//Constructors/Destructors
Game::Game() {
    isFocused = true;
    unitTesting = false;
    initWindow();
    initStates();
}

Game::Game(bool unit_testing) {
    isFocused = true;
    unitTesting = unit_testing;
    initWindow();
    initStates();
}

Game::~Game() {

}

void Game::updateDt() {
    gameRunTime = dtClock.restart();
    dt = gameRunTime.asSeconds();
    rtc->addMilliseconds(gameRunTime.asMilliseconds());
}

//Functions
void Game::endApplication() {
    std::cout << "Ending Application" << "\n";
}

void Game::updateSFMLEvents() {
    while(window->pollEvent(sfEvent)){
        switch (sfEvent.type)
        {
            case sf::Event::Closed:       //check for CLOSED event
                window->close();
                break;
            case sf::Event::GainedFocus:
                isFocused = true;
                break;
            case sf::Event::LostFocus:
                isFocused = false;
                break;
        }
    }
}

void Game::update() {
    updateSFMLEvents();
    if(!states.empty()){
        if (window->hasFocus()) {
            states.top()->update(dt);
            if(states.top()->getQuit()){
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

void Game::render() {
    window->clear(sf::Color(30,30,30,150));

    //Render items
    if(!states.empty()){
        states.top()->render();
    }

    window->display();
}

void Game::run() {
    while(window->isOpen()){
        window->setTitle(Title+rtc->toString());
        updateDt();
        update();
        render();
    }
}

void Game::unitTestingRun() {
    window->setVisible(false);
    while(window->isOpen()){
        updateDt();
        update();
    }
}

shared_ptr<sf::RenderWindow> Game::getWindow(){
    return window;
}


