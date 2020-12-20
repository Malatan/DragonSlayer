//
// Created by Zheng on 06/10/2020.
//

#include <iostream>
#include "Game.h"

void Game::initVariables() {
    window = nullptr;
    dt = 0.f;
}

void Game::initWindow() {
    std::ifstream ifs("../Resources/Config/window.ini");

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
    } else{
        std::cout<<"window.ini not found"<<"\n";
    }
    ifs.close();

    windowSettings.antialiasingLevel = antialiasing_level;
    window = std::make_shared<sf::RenderWindow>(window_bounds,
                                                window_title,
                                        sf::Style::Close,
                                        windowSettings);
    window->setFramerateLimit(framerate_limit);
    window->setVerticalSyncEnabled(veritcal_enabled);
    rsHandler = std::make_shared<ResourcesHandler>();
}


void Game::initStates() {
    states.push(std::make_unique<MainMenuState>(window, &states, rsHandler));
}

//Constructors/Destructors
Game::Game() {
    initVariables();
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

void Game::updateSFMLEvents() {
    while(window->pollEvent(sfEvent)) {
        switch (sfEvent.type) {
            case sf::Event::Closed:       //check for CLOSED event
                window->close();
                break;
        }
    }
}

void Game::update() {
    updateSFMLEvents();
    if(!states.empty()){
        if (window->hasFocus()) {
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

shared_ptr<sf::RenderWindow> Game::getWindow(){
    return window;
}


