//
// Created by Zheng on 07/10/2020.
//

#ifndef DRAGONSLAYER_GAMESTATE_H
#define DRAGONSLAYER_GAMESTATE_H

#include "State.h"
#include "../Entity/Player.h"
#include "../Entity/Enemy.h"
#include "../Gui/PauseMenu.h"

class GameState : public State{
private:
    sf::Font* font;
    PauseMenu* pmenu;
    Player* player;

    std::vector<Enemy*> enemis;

    sf::Text hints;

    //functions
    void initTextures();
    void initPauseMenu();
    void initPlayers();
    void initHintsTab();

public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states, sf::Font *font);
    virtual ~GameState();

    //functions
    void updateInput(const float &dt);
    void updatePlayerInput(const float& dt);
    void updatePausedMenuButtons();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);

};


#endif //DRAGONSLAYER_GAMESTATE_H
