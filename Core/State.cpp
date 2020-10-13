//
// Created by Zheng on 06/10/2020.
//

#include "State.h"

State::State(sf::RenderWindow *window, std::stack<State*>* states, ResourcesHandler* rsHandler, bool* isFocused, sf::Event* sfEvent) {
    this->window = window;
    this->states = states;
    this->sfEvent =sfEvent;
    this->rsHandler = rsHandler;
    this->windowIsFocused = isFocused;
    this->quit = false;
    this->paused = false;
    this->keyTime = 0.f;
    this->keyTimeMax = 10.f;
}

State::~State() {

}

//accessors
const bool &State::getQuit() const {
    return this->quit;
}

const bool State::getKeyTime() {
    if(this->keyTime >= this->keyTimeMax){
        this->keyTime = 0.f;
        return true;
    }
    return false;
}

//functions
void State::endState() {
    this->quit = true;
}

void State::pauseState() {
    this->paused = true;
}

void State::unpauseState() {
    this->paused = false;
}

void State::updateMousePosition() {
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void State::updateKeyTime(const float &dt) {
    if(this->keyTime < this->keyTimeMax){
        this->keyTime += 60.f * dt;
    }

}

ResourcesHandler *State::getRsHandler() const {
    return this->rsHandler;
}
