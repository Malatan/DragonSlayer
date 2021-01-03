//
// Created by Zheng on 06/10/2020.
//

#ifndef DRAGONSLAYER_STATE_H
#define DRAGONSLAYER_STATE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <stack>
#include <map>
#include "../Resources/ResourcesHandler.h"
#include <memory>

enum state_enum{
    MAINMENU_STATE,
    GAME_STATE,
    BATTLE_STATE
};

class State {

protected:
    std::stack<std::unique_ptr<State>>* states{};
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<ResourcesHandler> rsHandler;

    bool quit{};
    bool paused{};
    float keyTime{};
    float keyTimeMax{};
    state_enum stateEnum{};
    sf::Vector2f mousePosView;

    //resources
    std::map<std::string, sf::Texture> textures;

public:
    State(std::shared_ptr<sf::RenderWindow> window, std::stack<std::unique_ptr<State>>* states,
            std::shared_ptr<ResourcesHandler> rsHandler, state_enum _state_enum);
    virtual ~State();

    //accessors
    const bool& getQuit() const;
    bool getKeyTime();
    const map<string, sf::Texture> &getTextures() const;
    state_enum getStateEnum() const;

    //functions
    void endState();
    void pauseState();
    void unpauseState();

    virtual void updateMousePosition(sf::View* view);
    virtual void updateKeyTime(const float& dt);
    virtual void updateInput(const float& dt);
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};


#endif //DRAGONSLAYER_STATE_H
