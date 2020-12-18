//
// Created by Zheng on 07/10/2020.
//

#ifndef DRAGONSLAYER_GAMESTATE_H
#define DRAGONSLAYER_GAMESTATE_H

#include "State.h"
#include "BattleState.h"
#include "../Game/LootGenerator.h"
#include "../Game/BattleResult.h"
#include "../Game/Player.h"
#include "../Game/Enemy.h"
#include "../Game/Npc.h"
#include "../Game/LootBag.h"
#include "../Gui/PauseMenu.h"
#include "../Gui/CharacterTab.h"
#include "../Gui/ShopTab.h"
#include "../Gui/SpellTab.h"
#include "../Gui/PriestTab.h"
#include "../Gui/WizardTab.h"
#include "../Gui/SelectLevelTab.h"
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
class SelectLevelTab;
class BuffComponent;
class PopUpTextComponent;
class SpellComponent;
class Map;
class MapGenerator;
class LootBag;

typedef std::pair<unsigned int, unsigned int> lootBagAccessPair;

class GameState : public State{
public:
    GameState(std::shared_ptr<sf::RenderWindow> window, std::stack<std::unique_ptr<State>>* states,
            std::shared_ptr<ResourcesHandler> rsHandler, sf::Font *font);
    virtual ~GameState();

    //accessors
    std::shared_ptr<BuffComponent> getBuffComponent();
    std::shared_ptr<PopUpTextComponent> getPopUpTextComponent();
    std::shared_ptr<SpellComponent> getSpellComponent();
    std::shared_ptr<SpellTab> getSpellTab();
    std::shared_ptr<LootGenerator> getLootGenerator();
    bool getStateKeyTime();

    //functions
    void changeMap(int floor);
    void checkBattleResult(BattleResult& battle_result);
    void spawnEnemy(float x, float y, enemy_types type, unsigned int enemy_followers = 5);
    bool deleteEnemyById(unsigned int enemy_id);
    void addItem(const std::shared_ptr<Item>& new_item);
    void changeStato(int current_stato);
    void updateTabsGoldLbl();
    void updateTabsInvSpaceLbl();
    void updateTabsPlayerStatsLbl();
    void updateInput(const float &dt) override;
    void updatePlayerInput(const float& dt);
    void updatePausedMenuButtons();
    void updateView(const float& dt);
    void updateDebugText();
    void updateButtons();
    void update(const float& dt) override;
    void updateTileMap(const float& dt);
    void render(sf::RenderTarget* target) override;
    void spawnEnemyOnMap();


private:
    sf::Font* font;
    sf::View view;
    sf::Text hints;
    sf::Text debugText;
    gui::Button cTabBtn;
    gui::Button pauseMenuBtn;
    gui::Button spellTabBtn;

    Map* map{};
    MapGenerator* mg{};
    PauseMenu pmenu;
    std::shared_ptr<CharacterTab> cTab;
    std::shared_ptr<ShopTab> shopTab;
    std::shared_ptr<PriestTab> priestTab;
    std::shared_ptr<SpellTab> spellTab;
    std::shared_ptr<WizardTab> wizardTab;
    std::shared_ptr<SelectLevelTab> selectLevelTab;
    std::shared_ptr<Player> player;

    std::shared_ptr<BuffComponent> buffComponent;
    std::shared_ptr<PopUpTextComponent> popUpTextComponent;
    std::shared_ptr<SpellComponent> spellComponent;
    std::shared_ptr<LootGenerator> lootGenerator;

    std::vector<std::shared_ptr<LootBag>> lootBags;
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<Npc*> npcs;
    sf::Vector2f spawnPos;
    int stato; // 0 = in giocata, 1 = pause, menu 2 = character, 3 = shop, 4 = priest, 5 = spell, 6 = wizard, 7 = lootbag, 8 = selectLevel
    npc_type npcInteract;
    lootBagAccessPair interactLootBag;
    bool noclip;
    int currentFloor;

    //init
    void initTextures();
    void initPauseMenu();
    void initPlayers();
    void initCharacterTab();
    void initShopTab();
    void initPriestTab();
    void initSelectLevelTab();
    void initSpellTab();
    void initWizardTab();
    void initHintsTab();
    void initEquipSlotsTextures();
    void initShopItemTextures();
    void initBuffComponent();
    void initSpellComponent();
    void initComponents();
    void initLootGenerator();
    void initView();
    void initDebugText();
    void initButtons();
    void initMaps();
};


#endif //DRAGONSLAYER_GAMESTATE_H
