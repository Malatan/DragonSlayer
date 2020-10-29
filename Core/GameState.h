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
#include "../Gui/WizardTab.h"
#include "../Components/BuffComponent.h"
#include "../Components/PopUpTextComponent.h"
#include "../Components/SpellComponent.h"
#include "../Map/Map.h"
#include "../Map/MapGenerator.h"

class CharacterTab;
class ShopTab;
class PriestTab;
class SpellTab;
class WizardTab;
class BuffComponent;
class PopUpTextComponent;
class SpellComponent;
class Map;
class MapGenerator;

class GameState : public State{
private:
    sf::Font* font;
    sf::View view;
    sf::Text hints;
    sf::Text debugText;

    gui::Button* cTabBtn;
    gui::Button* pauseMenuBtn;
    gui::Button* spellTabBtn;

    Map* map;
    MapGenerator* mg;
    PauseMenu* pmenu;
    CharacterTab* cTab;
    ShopTab* shopTab;
    PriestTab* priestTab;
    SpellTab* spellTab;
    WizardTab* wizardTab;
    Player* player;

    BuffComponent* buffComponent;
    PopUpTextComponent* popUpTextComponent;
    SpellComponent* spellComponent;

    std::vector<Enemy*> enemis;
    std::vector<Npc*> npcs;
    int stato; // 0 = in giocata, 1 = pause, menu 2 = character, 3 = shop, 4 = priest, 5 = spell, 6 = wizard
    npc_type npcInteract;
    bool noclip;

    //functions
    void initTextures();
    void initPauseMenu();
    void initPlayers();
    void initCharacterTab();
    void initShopTab();
    void initPriestTab();
    void initSpellTab();
    void initWizardTab();
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
    void initMaps();

public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states, ResourcesHandler* rsHandler, sf::Font *font, sf::Event* sfEvent);
    virtual ~GameState();

    //modifiers
    void setNoclip(bool b);

    //accessors
    BuffComponent* getBuffComponent();
    PopUpTextComponent* getPopUpTextComponent();
    SpellComponent* getSpellComponent();
    SpellTab* getSpellTab();
    const bool isNoclip() const;

    //functions
    void addItem(Item* item);
    void changeStato(int stato);
    void updateTabsGoldLbl();
    void updateTabsInvSpaceLbl();
    void updateTabsPlayerStatsLbl();
    void updateInput(const float &dt);
    void updatePlayerInput(const float& dt);
    void updatePausedMenuButtons();
    void updateView(const float& dt);
    void updateDebugText();
    void updateButtons();
    void update(const float& dt);
    void updateTileMap(const float& dt);
    void render(sf::RenderTarget* target = nullptr);

};


#endif //DRAGONSLAYER_GAMESTATE_H
