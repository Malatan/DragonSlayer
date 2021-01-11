//
// Created by Zheng on 06/10/2020.
//

#include "State.h"

State::State(std::shared_ptr<sf::RenderWindow> window, std::stack<std::unique_ptr<State>>* states,
             std::shared_ptr<ResourcesHandler> rsHandler, state_enum _state_enum) {
    this->window = std::move(window);
    this->states = states;
    this->rsHandler = std::move(rsHandler);
    stateEnum = _state_enum;
    quit = false;
    paused = false;
    keyTime = 0.f;
    keyTimeMax = 10.f;
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

state_enum State::getStateEnum() const {
    return stateEnum;
}

//functions
sf::Image State::getScreenShoot() {
    sf::Texture texture;
    texture.create(window->getSize().x, window->getSize().y);
    texture.update(*window);
    return texture.copyToImage();
}

std::string State::saveScreenShoot() {
    if (mkdir("../ScreenShoots") != -1)
        std::cout << "ScreenShoots Directory created" << std::endl;
    auto start = std::chrono::system_clock::now();
    auto legacyStart = std::chrono::system_clock::to_time_t(start);
    std::stringstream ss;
    ss << "../ScreenShoots/" << std::ctime(&legacyStart);
    std::string f_path = ss.str();
    f_path.erase(std::remove(f_path.begin(), f_path.end(), ':'), f_path.end());
    f_path.erase(std::remove(f_path.begin(), f_path.end(), ' '), f_path.end());
    f_path.pop_back();
    f_path += ".png";
    getScreenShoot().saveToFile(f_path);
    ss.str("");
    ss << "ScreenShot saved in " << f_path;
    return ss.str();
}

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







