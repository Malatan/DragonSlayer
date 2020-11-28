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


class State {
private:


protected:
    std::stack<std::unique_ptr<State>>* states;
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<ResourcesHandler> rsHandler;

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
    State();
    State(std::shared_ptr<sf::RenderWindow> window, std::stack<std::unique_ptr<State>>* states,
            std::shared_ptr<ResourcesHandler> rsHandler);
    virtual ~State();

    //accessors
    const bool& getQuit() const;
    bool getKeyTime();
    std::shared_ptr<ResourcesHandler> getRsHandler() const;
    const map<string, sf::Texture> &getTextures() const;
    sf::Vector2f getMousePosView() const;

    //functions
    void endState();
    void pauseState();
    void unpauseState();

    virtual void updateMousePosition(sf::View* view = NULL);
    virtual void updateKeyTime(const float& dt);
    virtual void updateInput(const float& dt);
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target = nullptr);
};


#endif //DRAGONSLAYER_STATE_H
