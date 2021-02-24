//
// Created by Zheng on 21/01/2021.
//

#ifndef DRAGONSLAYER_DEBUGTOOL_H
#define DRAGONSLAYER_DEBUGTOOL_H

#include "SFML/Graphics.hpp"
#include "GameState.h"

class GameState;

class DebugTool {
public:
    //constructors/destructor
    DebugTool(sf::Font* _font, State* state);
    ~DebugTool();

    //functions

    void applyFunctions(const std::string& key);
    void updateInput();
    void updateDebugText();
    void update(const float& dt, const sf::Vector2f &mousePos);
    void renderPlayerDebugInfo(sf::RenderTarget* target);
    void renderEnemisDebugInfo(sf::RenderTarget* target);
    void renderLootBagsDebugInfo(sf::RenderTarget* target);
    void renderMapDebugInfo(sf::RenderTarget* target);
    void render(sf::RenderTarget* target);

private:
    GameState* gstate;
    sf::RectangleShape container;
    sf::Font* font;
    sf::Text textLbl;
    std::map<std::string, gui::Button*> buttons;
    bool showMenu{};

    //initializers
    void addButton(const std::string& btn_key, const std::string& text);
    void initDebugTextLbl();
    void initButtons();
};


#endif //DRAGONSLAYER_DEBUGTOOL_H
