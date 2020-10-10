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
    std::ifstream ifs("../Config/window.ini");
    this->videomodes = sf::VideoMode::getFullscreenModes();

    this->Title = "None";
    sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
    unsigned framerate_limit = 120;
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
                                        sf::Style::Default  ,
                                        this->windowSettings);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(veritcal_enabled);
    this->rtc = new RunTimeClock();
    this->rsHandler = new ResourcesHandler();
}


void Game::initStates() {
    this->states.push(new MainMenuState(this->window, &this->states, this->rsHandler));
}

//Constructors/Destructors
Game::Game() {

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
    while(this->window->pollEvent((this->sfEvent))){
        if(this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update() {

    this->updateSFMLEvents();
    if(!this->states.empty()){

        this->states.top()->update(this->dt);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::B) && this->states.top()->getKeyTime()){
            std::cout << this->rsHandler->toString();
        }
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
    this->window->clear();

    //Render items
    if(!this->states.empty()){
        this->states.top()->render();
    }

    this->window->display();
}

void Game::run() {
    sf::Event event;
    while(this->window->isOpen()){
        if (event.type == sf::Event::Resized)
        {
            // update the view to the new size of the window
            sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
            this->window->setView(sf::View(visibleArea));
        }
        this->window->setTitle(this->Title+this->rtc->toString());
        this->updateDt();
        this->update();
        this->render();


    }
}