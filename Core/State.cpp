//
// Created by Zheng on 06/10/2020.
//

#include "State.h"

State::State()= default;

State::State(std::shared_ptr<sf::RenderWindow> window, std::stack<std::unique_ptr<State>>* states,
             std::shared_ptr<ResourcesHandler> rsHandler) {
    this->window = std::move(window);
    this->states = states;
    this->rsHandler = std::move(rsHandler);
    this->quit = false;
    this->paused = false;
    this->keyTime = 0.f;
    this->keyTimeMax = 10.f;
}

State::~State() = default;

//accessors
const bool &State::getQuit() const {
    return quit;
}

bool State::getKeyTime() {
    if(keyTime >= keyTimeMax){
        keyTime = 0.f;
        return true;
    }
    return false;
}

const map<string, sf::Texture> &State::getTextures() const {
    return textures;
}


//functions
void State::endState() {
    quit = true;
}

void State::pauseState() {
    paused = true;
}

void State::unpauseState() {
    paused = false;
}

void State::updateMousePosition(sf::View* view) {
    if(view)
        window->setView(*view);


    mousePosView = window->mapPixelToCoords(sf::Mouse::getPosition(*window));

    window->setView(window->getDefaultView());
}

void State::updateKeyTime(const float &dt) {
    if(keyTime < keyTimeMax){
        keyTime += 60.f * dt;
    }

}

void State::render(sf::RenderTarget *target) {

}

void State::update(const float &dt) {

}

void State::updateInput(const float &dt) {

}






