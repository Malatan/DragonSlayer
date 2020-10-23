//
// Created by Zheng on 07/10/2020.
//

#ifndef DRAGONSLAYER_GAMESTATE_H
#define DRAGONSLAYER_GAMESTATE_H

#include "State.h"
#include "../Game/Player.h"
#include "../Game/Enemy.h"
#include "../Game/Npc.h"
#include "../Gui/PauseMenu.h"
#include "../Gui/CharacterTab.h"
#include "../Gui/ShopTab.h"
#include "../Gui/SpellTab.h"
#include "../Gui/PriestTab.h"
#include "../Components/BuffComponent.h"
#include "../Components/PopUpTextComponent.h"
#include "../Components/SpellComponent.h"


class CharacterTab;
class ShopTab;
class PriestTab;
class SpellTab;
class BuffComponent;
class PopUpTextComponent;
class SpellComponent;

class GameState : public State{
private:
    sf::Font* font;
    sf::View view;
    sf::Text hints;
    sf::Text debugText;

    gui::Button* cTabBtn;
    gui::Button* pauseMenuBtn;
    gui::Button* spellTabBtn;

    PauseMenu* pmenu;
    CharacterTab* cTab;
    ShopTab* shopTab;
    PriestTab* priestTab;
    SpellTab* spellTab;
    Player* player;

    BuffComponent* buffComponent;
    PopUpTextComponent* popUpTextComponent;
    SpellComponent* spellComponent;

    std::vector<Enemy*> enemis;
    std::vector<Npc*> npcs;
    int stato; // 0 = in giocata, 1 = pause, menu 2 = character, 3 = shop, 4 = priest, 5 = spell
    npc_type npcInteract;


    //functions
    void initTextures();
    void initPauseMenu();
    void initPlayers();
    void initCharacterTab();
    void initShopTab();
    void initPriestTab();
    void initSpellTab();
    void initHintsTab();
    void initEquipSlotsTextures();
    void initInventoryItemTextures();
    void initShopItemTextures();
    void initBuffComponent();
    void initSpellComponent();
    void initComponents();
    void initView();
    void initDebugText();
    void initButtons();

public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states, ResourcesHandler* rsHandler, sf::Font *font, sf::Event* sfEvent);
    virtual ~GameState();

    //accessors
    BuffComponent* getBuffComponent();
    PopUpTextComponent* getPopUpTextComponent();

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
    void updateButtons();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);

};


#endif //DRAGONSLAYER_GAMESTATE_H
