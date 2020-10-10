//
// Created by Zheng on 06/10/2020.
//

#ifndef DRAGONSLAYER_GAME_H
#define DRAGONSLAYER_GAME_H

#include "State.h"
#include "MainMenuState.h"
#include "RunTimeClock.h"
#include "../Resources/ResourcesHandler.h"

class Game {
private:
    //Variables
    ResourcesHandler* rsHandler;
    sf::RenderWindow *window;
    sf::Event sfEvent;
    std::vector<sf::VideoMode> videomodes;
    sf::ContextSettings windowSettings;

    sf::Clock dtClock;
    float dt; //delta time
    sf::Time gameRunTime;
    RunTimeClock* rtc;

    std::stack<State*> states;

    std::string Title;
    //Initialization
    void initVariables();
    void initWindow();
    void initStates();

public:
    //Constructors/Destructors
    Game();
    virtual ~Game();

    //Functions

    //regular
    void endApplication();

    //update
    void updateDt();
    void updateSFMLEvents();
    void update();

    //render
    void render();

    //core
    void run();
};


#endif //DRAGONSLAYER_GAME_H
