//
// Created by Zheng on 06/10/2020.
//


#include "Game.h"

void Game::initVariables() {
    this->window = NULL;
    this->dt = 0.f;
}

void Game::initWindow() {
    std::ifstream ifs("../Config/window.ini");
    this->videomodes = sf::VideoMode::getFullscreenModes();

    std::string title = "None";
    sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
    unsigned framerate_limit = 120;
    bool veritcal_enabled = false;
    unsigned antialiasing_level = 0;

    if(ifs.is_open()){
        std::getline(ifs,title);
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
                                        title,
                                        sf::Style::Close,
                                        this->windowSettings);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(veritcal_enabled);

}


void Game::initStates() {
    this->states.push((new MainMenuState(this->window, &this->states)));
}

//Constructors/Destructors
Game::Game() {
    this->initWindow();
    this->initStates();
}

Game::~Game() {
    delete this->window;
    while(this->states.empty()){
        delete this->states.top();
        this->states.pop();
    }

}

void Game::updateDt() {
    this->dt = this->dtClock.restart().asSeconds();
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
    while(this->window->isOpen()){
        this->updateDt();
        this->update();
        this->render();
    }
}