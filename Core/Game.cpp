//
// Created by Zheng on 06/10/2020.
//

#include <iostream>
#include "Game.h"

void Game::initVariables() {
    this->window = NULL;
    this->dt = 0.f;
}

void Game::initWindow() {
    std::ifstream ifs("../Resources/Config/window.ini");
    this->videomodes = sf::VideoMode::getFullscreenModes();

    this->Title = "None";
    sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
    unsigned framerate_limit = 144;
    bool veritcal_enabled = false;
    unsigned antialiasing_level = 0;

    if(ifs.is_open()){
        std::getline(ifs,this->Title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> veritcal_enabled;
        ifs >> antialiasing_level;
    } else{
        std::cout<<"window.ini not found"<<"\n";
    }
    ifs.close();

    this->windowSettings.antialiasingLevel = antialiasing_level;
    this->window = new sf::RenderWindow(window_bounds,
                                        this->Title,
                                        sf::Style::Close,
                                        this->windowSettings);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(veritcal_enabled);
    this->rtc = new RunTimeClock();
    this->rsHandler = new ResourcesHandler();
}


void Game::initStates() {
    this->states.push(new MainMenuState(this->window, &this->states, this->rsHandler, &this->isFocused, &this->sfEvent));
}

//Constructors/Destructors
Game::Game() {
    this->isFocused = true;
    this->unitTesting = false;
    this->initWindow();
    this->initStates();
}

Game::Game(bool unit_testing) {
    this->isFocused = true;
    this->unitTesting = unit_testing;
    this->initWindow();
    this->initStates();
}

Game::~Game() {
    delete this->window;
    delete this->rsHandler;
    delete this->rtc;
    while(this->states.empty()){
        delete this->states.top();
        this->states.pop();
    }

}

void Game::updateDt() {
    this->gameRunTime = this->dtClock.restart();
    this->dt = gameRunTime.asSeconds();
    this->rtc->addMilliseconds(gameRunTime.asMilliseconds());
}

//Functions
void Game::endApplication() {
    std::cout << "Ending Application" << "\n";
}

void Game::updateSFMLEvents() {
    while(this->window->pollEvent(this->sfEvent)){
        switch (this->sfEvent.type)
        {
            case sf::Event::Closed:       //check for CLOSED event
                this->window->close();
                break;
            case sf::Event::GainedFocus:
                this->isFocused = true;
                break;
            case sf::Event::LostFocus:
                this->isFocused = false;
                break;
        }
    }
}

void Game::update() {

    this->updateSFMLEvents();
    if(!this->states.empty()){

        this->states.top()->update(this->dt);
        if(this->states.top()->getQuit()){
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    } else{
        //application end
        this->endApplication();
        this->window->close();
    }
}

void Game::render() {
    this->window->clear(sf::Color(30,30,30,150));

    //Render items
    if(!this->states.empty()){
        this->states.top()->render();
    }

    this->window->display();
}

void Game::run() {
    while(this->window->isOpen()){
        this->window->setTitle(this->Title+this->rtc->toString());
        this->updateDt();
        this->update();
        this->render();
    }
}

void Game::unitTestingRun() {
    this->window->setVisible(false);
    while(this->window->isOpen()){
        this->updateDt();
        this->update();
    }
}

sf::RenderWindow *Game::getWindow(){
    return this->window;
}


