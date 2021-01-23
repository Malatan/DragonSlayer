//
// Created by Zheng on 07/10/2020.
//

#ifndef DRAGONSLAYER_GAMESTATE_H
#define DRAGONSLAYER_GAMESTATE_H

#include <chrono>
#include "State.h"
#include "Subject.h"
#include "../Map/Map.h"
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
#include "../Gui/AchievementTab.h"
#include "../Gui/LoadSaveTab.h"
#include "../Components/BuffComponent.h"
#include "../Components/PopUpTextComponent.h"
#include "../Components/SpellComponent.h"
#include "BattleState.h"
#include "../Game/BattleResult.h"
#include "../Map/MapGenerator.h"
#include "../Map/PathFinder.h"
#include "../Resources/LootBagSaveData.h"
#include "../Resources/EnemySaveData.h"
#include "../Game/LootGenerator.h"
#include "DebugTool.h"
#include "../Map/MiniMap.h"

class PauseMenu;
class CharacterTab;
class ShopTab;
class PriestTab;
class SpellTab;
class WizardTab;
class SelectLevelTab;
class AchievementTab;
class LoadSaveTab;
class BuffComponent;
class PopUpTextComponent;
class SpellComponent;
class AchievementComponent;
class Map;
class MapGenerator;
class PathFinder;
class EnemySaveData;
class DebugTool;
class MiniMap;

typedef std::pair<unsigned int, unsigned int> lootBagAccessPair;

enum state_tab{
    NO_TAB,
    PAUSEMENU_TAB,
    CHARACTER_TAB,
    SHOP_TAB,
    PRIEST_TAB,
    SPELL_TAB,
    WIZARD_TAB,
    LOOTBAG_TAB,
    SELECTLEVEL_TAB,
    ACHIEVEMENT_TAB,
    LOADSAVE_TAB
};

class GameState : public State, public Subject{
public:
    //constructor/destructor
    GameState(std::shared_ptr<sf::RenderWindow> window, std::stack<std::unique_ptr<State>>* states,
            std::shared_ptr<ResourcesHandler> rsHandler, std::shared_ptr<PopUpTextComponent> popuptext_component,
            std::shared_ptr<LoadSaveTab> loadsave_tab,
            sf::Font *font, state_enum _state_enum);
    virtual ~GameState();

    //accessors
    std::shared_ptr<BuffComponent>& getBuffComponent();
    std::shared_ptr<PopUpTextComponent>& getPopUpTextComponent();
    std::shared_ptr<SpellComponent>& getSpellComponent();
    std::shared_ptr<AchievementComponent>& getAchievementComponent();
    std::shared_ptr<SpellTab>& getSpellTab();
    std::shared_ptr<LootGenerator>& getLootGenerator();
    std::shared_ptr<Player>& getPlayer();
    std::shared_ptr<ResourcesHandler>& getResourceHandler();
    std::shared_ptr<MapGenerator>& getMapGenerator();
    std::vector<std::shared_ptr<Enemy>>& getEnemies();
    std::vector<std::shared_ptr<LootBag>>& getLootBags();
    Npc* getNpc(int index);
    const vector<Npc *> &getNpcs() const;
    npc_type getInteractNpc() const;
    std::shared_ptr<Enemy>& getEnemy(int index);
    bool getStateKeyTime();
    int getCurrentFloor() const;
    int getReachedFloor() const;
    Map* getMap();
    PathFinder* getPathFinder() const;
    std::pair<int, int> getEnemyCount(bool count_followers = false) const;

    //observer
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notify(achievement_event event, int value);

    //functions
    void changeMap(int floor, bool load_from_save = false);
    void checkBattleResult(BattleResult* battle_result);
    void loadEnemyFromSave();
    std::shared_ptr<Enemy> enemyFactory(float x, float y, enemy_types type, bool generate_stats);
    void spawnEnemy(float x, float y, enemy_types type, unsigned int enemy_followers = 5);
    void spawnNpc(float x, float y, npc_type spawn_npc_type);
    bool deleteEnemyById(unsigned int enemy_id);
    void addItem(const std::shared_ptr<Item>& new_item);
    void changeStato(state_tab current_stato);
    void spawnEnemyOnMap();
    void enableDisableDebugTool() override;
    void updateTabsGoldLbl();
    void updateTabsInvSpaceLbl();
    void updateTabsPlayerStatsLbl(state_tab update_tab = NO_TAB);
    void updateInput(const float &dt) override;
    void updateGlobalInput(const float &dt);
    void updateMouseInput(const float &dt);
    void updatePlayerInput(const float& dt);
    void updatePausedMenuButtons();
    void updateView();
    void updateButtons();
    void updateEnemy(const float& dt);
    void updateTileMap(const float& dt);
    void update(const float& dt) override;
    void render(sf::RenderTarget* target) override;

private:
    friend class DebugTool;
    sf::Font* font;
    sf::View view;

    sf::Text hints;
    std::unique_ptr<gui::Button> cTabBtn;
    std::unique_ptr<gui::Button> pauseMenuBtn;
    std::unique_ptr<gui::Button> spellTabBtn;
    std::unique_ptr<gui::Button> achievementTabBtn;

    sf::Shader coreShader;
    DebugTool* debugTool{};
    Map* map{};
    std::shared_ptr<MiniMap> minimap;
    std::shared_ptr<PathFinder> pathFinder;
    std::shared_ptr<MapGenerator> mg;
    std::unique_ptr<PauseMenu> pmenu;
    std::shared_ptr<CharacterTab> cTab;
    std::shared_ptr<ShopTab> shopTab;
    std::shared_ptr<PriestTab> priestTab;
    std::shared_ptr<SpellTab> spellTab;
    std::shared_ptr<WizardTab> wizardTab;
    std::shared_ptr<SelectLevelTab> selectLevelTab;
    std::shared_ptr<AchievementTab> achievementTab;
    std::shared_ptr<Player> player;
    std::shared_ptr<LoadSaveTab> loadSaveTab;
    std::shared_ptr<BuffComponent> buffComponent;
    std::shared_ptr<PopUpTextComponent> popUpTextComponent;
    std::shared_ptr<SpellComponent> spellComponent;
    std::shared_ptr<LootGenerator> lootGenerator;
    std::shared_ptr<AchievementComponent> achievementComponent;

    std::vector<std::shared_ptr<LootBag>> lootBags;
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<Npc*> npcs;
    sf::Vector2f spawnPos;
    state_tab stato;
    npc_type npcInteract;
    lootBagAccessPair interactLootBag;
    int currentFloor{};
    int floorReached{};
    float enemyRenderDistance{};

    //init
    void applySaveValue();
    void generateInitialInventory();
    void initTextures();
    void initPauseMenu();
    void initPlayers();
    void initTabs();
    void initHintsTab();
    void initEquipSlotsTextures();
    void initShopItemTextures();
    void initComponents();
    void initLootGenerator();
    void initView();
    void initButtons();
    void initMaps();
    void initShader();
    void initObservers();
    void preNotifiers();
};


#endif //DRAGONSLAYER_GAMESTATE_H
