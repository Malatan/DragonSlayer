//
// Created by Zheng on 07/10/2020.
//

#ifndef DRAGONSLAYER_GAMESTATE_H
#define DRAGONSLAYER_GAMESTATE_H

#include "State.h"
#include "../Game/Player.h"
#include "../Game/Enemy.h"
#include "../Gui/PauseMenu.h"
#include "../Gui/CharacterTab.h"
#include "../Gui/ShopTab.h"
#include "../Game/Npc.h"


class CharacterTab;
class ShopTab;

class GameState : public State{
private:
    sf::Font* font;
    sf::View view;
    sf::Text hints;
    sf::Text debugText;

    PauseMenu* pmenu;
    CharacterTab* cTab;
    ShopTab* shopTab;
    Player* player;

    std::vector<Enemy*> enemis;
    std::vector<Npc*> npcs;
    int stato; // 0 = in giocata, 1 = pause, menu 2 = character, 3 = shop
    npc_type npcInteract;


    //functions
    void initTextures();
    void initPauseMenu();
    void initPlayers();
    void initCharacterTab();
    void initShopTab();
    void initHintsTab();
    void initEquipSlotsTextures();
    void initInventoryItemTextures();
    void initShopItemTextures();
    void initBuffComponent();
    void initComponents();
    void initView();
    void initDebugText();

public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states, ResourcesHandler* rsHandler, sf::Font *font, bool* isFocused, sf::Event* sfEvent);
    virtual ~GameState();

    //functions
    void addItem(Item* item);
    void changeStato(int stato);
    void updateTabsGoldLbl();
    void updateTabsInvSpaceLbl();
    void updateInput(const float &dt);
    void updatePlayerInput(const float& dt);
    void updatePausedMenuButtons();
    void updateView(const float& dt);
    void updateDebugText();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);

};


#endif //DRAGONSLAYER_GAMESTATE_H
