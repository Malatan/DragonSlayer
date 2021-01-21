//
// Created by Zheng on 06/10/2020.
//

#ifndef DRAGONSLAYER_GAME_H
#define DRAGONSLAYER_GAME_H

#include "State.h"
#include "MainMenuState.h"
#include "Common.h"
#include "../Resources/ResourcesHandler.h"

class Game {
public:
    //Constructors/Destructors
    explicit Game(bool unit_testing = false);
    virtual ~Game();

    //accessors
    shared_ptr<sf::RenderWindow> getWindow();

    //Functions
    static void endApplication();
    State* getTopState();
    float getDt() const;

    //update
    void updateInput();
    void updateDt();
    void updateSFMLEvents();
    void update();
    void testUpdate();

    //render
    void render();

    //core
    void run();
    void testRun(bool do_render = false);
private:
    //Variables
    std::shared_ptr<ResourcesHandler> rsHandler;
    std::shared_ptr<sf::RenderWindow> window;
    sf::Event sfEvent{};
    sf::ContextSettings windowSettings;
    sf::Clock dtClock;
    float dt{}; //delta time
    bool debugAccess{};
    std::stack<std::unique_ptr<State>> states;

    //Initialization
    void initVariables(bool unit_testing);
    void initWindow();
    void initStates();
};


#endif //DRAGONSLAYER_GAME_H
