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

class State {
private:


protected:
    std::stack<State*>* states;
    sf::RenderWindow* window;
    ResourcesHandler* rsHandler;
    sf::Event* sfEvent;

    bool quit;
    bool paused;
    bool* windowIsFocused;
    float keyTime;
    float keyTimeMax;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    //resources
    std::map<std::string, sf::Texture> textures;

public:
    State(sf::RenderWindow* window, std::stack<State*>* states, ResourcesHandler* rsHandler, bool* isFocused, sf::Event* sfEvent);
    virtual ~State();

    //accessors
    const bool& getQuit() const;
    const bool getKeyTime();
    ResourcesHandler *getRsHandler() const;
    const map<string, sf::Texture> &getTextures() const;

    //functions
    void endState();
    void pauseState();
    void unpauseState();

    virtual void updateMousePosition();
    virtual void updateKeyTime(const float& dt);
    virtual void updateInput(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};


#endif //DRAGONSLAYER_STATE_H
