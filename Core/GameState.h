//
// Created by Zheng on 07/10/2020.
//

#ifndef DRAGONSLAYER_GAMESTATE_H
#define DRAGONSLAYER_GAMESTATE_H

#include "State.h"
#include "../Entity/Player.h"
#include "../Entity/Enemy.h"
#include "../Gui/PauseMenu.h"
#include "../Gui/CharacterTab.h"

class GameState : public State{
private:
    sf::Font* font;
    PauseMenu* pmenu;
    CharacterTab* cTab;
    Player* player;

    std::vector<Enemy*> enemis;

    sf::Text hints;

    int stato; // 0 = in giocata 1 = pause menu 2 = character tab
    //functions
    void initTextures();
    void initPauseMenu();
    void initCharacterTab();
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
