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
public:
    //Constructors/Destructors
    Game();
    virtual ~Game();

    //accessors
    shared_ptr<sf::RenderWindow> getWindow();

    //Functions
    static void endApplication();

    //update
    void updateDt();
    void updateSFMLEvents();
    void update();

    //render
    void render();

    //core
    void run();

private:
    //Variables
    std::shared_ptr<ResourcesHandler> rsHandler;
    std::shared_ptr<sf::RenderWindow> window;
    sf::Event sfEvent{};
    sf::ContextSettings windowSettings;

    sf::Clock dtClock;
    float dt{}; //delta time
    sf::Time gameRunTime;
    std::shared_ptr<RunTimeClock> rtc;

    std::stack<std::unique_ptr<State>> states;

    std::string Title;
    //Initialization
    void initVariables();
    void initWindow();
    void initStates();
};


#endif //DRAGONSLAYER_GAME_H
