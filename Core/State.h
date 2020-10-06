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

class State {
private:


protected:
    std::stack<State*>* states;
    sf::RenderWindow* window;
    bool quit;
    bool paused;
    float keyTime;
    float keyTimeMax;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    //resources
    std::map<std::string, sf::Texture> textures;


public:
    State(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~State();

    //accessors
    const bool& getQuit() const;
    const bool getKeyTime();

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
