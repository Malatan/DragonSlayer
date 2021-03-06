//
// Created by Leonardo on 09/11/2020.
//

#ifndef DRAGONSLAYER_BATTLESTATE_H
#define DRAGONSLAYER_BATTLESTATE_H
#include <string>
#include <sstream>
#include <cmath>
#include "State.h"
#include "../Gui/Gui.h"
#include "../Gui/CharacterTab.h"
#include "../Game/Item.h"
#include "../Game/Inventory.h"
#include "../Game/Stats.h"
#include "../Game/Player.h"
#include "../Game/Spell.h"
#include "../Game/Enemy.h"
#include "../Game/Utils.h"
#include "../Game/BattleResult.h"
#include "../Components/PopUpTextComponent.h"
#include "../Components/BuffComponent.h"
#include "../AI/BattleAI.h"


class CharacterTab;
class BuffComponent;
class PauseMenu;
class BattleResult;

enum battle_result_types : unsigned int;

enum enemy_types : unsigned int;
namespace gui{
    class Button;
    class ActionRow;
    class ItemRow;
    class PlayerStatusPanel;
    class EnemyStatusPanel;
}

enum panel_types{
    ACTION_PANEL,
    INVENTORY_PANEL,
    ESCAPE_PANEL,
    DEFAULT_PANEL
};

enum window_states{
    UNPAUSED,
    PAUSE_MENU,
    BATTLE_REPORT
};

class BattleState : public State{
public:
    //constructors/destructor
    BattleState(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Player> player,
                std::stack<std::unique_ptr<State>>* states, state_enum _state_enum,
                std::shared_ptr<PopUpTextComponent> popUpTextComponent, std::shared_ptr<SpellComponent> spellComponent,
                std::shared_ptr<BuffComponent> buffComponent, std::shared_ptr<ResourcesHandler> rsHandler,
                std::map<std::string, sf::Texture> textures, sf::Font *font, std::shared_ptr<Enemy> enemy, float exp_gold_bonus,
                int floor, std::shared_ptr<CharacterTab> cTab);
    ~BattleState() override;

    void updateMessageLbl();
    void updatePlayerStatsLbl();
    void updateTurnPanel();
    void updatePageLbl(panel_types type);
    void updateEnemyStatsLbl(const std::shared_ptr<Enemy>& enemy);
    void updateButtons();
    void updateMainPanel(const float &dt);
    void updatePausedMenuButtons();
    void enableDisableDebugTool() override;
    void updateInput(const float &dt) override;
    void update(const float& dt) override;
    void render(sf::RenderTarget* target) override;

private:
    std::shared_ptr<Player> player;
    std::shared_ptr<Player> playerModel;
    std::shared_ptr<Enemy> enemyLeader;
    std::vector<std::shared_ptr<Enemy>> enemiesModels;
    std::shared_ptr<BuffComponent> buffComponent;
    std::shared_ptr<PopUpTextComponent> popUpTextComponent;
    std::shared_ptr<SpellComponent> spellComponent;
    std::shared_ptr<CharacterTab> cTab;

    float expGoldBonus;
    battle_result_types battleResultEnum;
    std::vector<unsigned int> enemiesMoveOrder;
    int floor;
    panel_types currentPanel;
    unsigned int selectedId;
    int enemyCount;
    float criticalhitMultiplier;
    float playerBlockPercentage{};
    bool potionUsed;
    window_states currentWindowState;
    std::shared_ptr<BattleResult> battleResult;

    unsigned int turnCount;
    bool whoseTurn; // true = player , false = enemies
    bool enemyMoveDone;
    unsigned int enemiesMoves;
    float turnLengthKeyTime;
    float turnLengthMaxKeyTime;
    bool countPlayerTurnTimer;

    sf::Font* font;
    sf::Texture backgroundTexture;
    sf::Texture commandsTexture;
    sf::Texture turnsTexture;
    sf::RectangleShape background;
    sf::RectangleShape mainActionPanel;
    sf::RectangleShape actionPanel;
    sf::Text tipsLbl;
    std::unique_ptr<gui::Button> actionBtn;
    sf::RectangleShape itemActionPanel;
    std::unique_ptr<gui::Button> itemActionBtn;
    std::unique_ptr<PauseMenu> pmenu;

    //Battle report
    sf::RectangleShape resultBackground;
    sf::RectangleShape resultContainer;
    sf::Text resultTitleLbl;
    sf::Text resultTextLbl;
    std::unique_ptr<gui::Button> continueBtn;

    //player stats panel
    sf::RectangleShape playerStatsPanel;
    sf::Text playerStatsPanelTitle;
    sf::Text playerStatsNameLbl;
    sf::Text playerStatsValueLbl;

    //enemy stats panel
    sf::RectangleShape enemyStatsPanel;
    sf::Text enemyStatsPanelTitle;
    sf::Text enemyStatsNameLbl;
    sf::Text enemyStatsValueLbl;
    sf::Text messageLbl;

    //action and inventory panel
    int currentActionPage{};
    int maxActionPage{};
    int currentInvPage{};
    int maxInvPage{};
    std::vector<std::unique_ptr<gui::ActionRow>> actionRows;
    std::vector<std::unique_ptr<gui::ItemRow>> itemRows;
    sf::Text pageLbl;
    std::unique_ptr<gui::Button> nextPageBtn;
    std::unique_ptr<gui::Button> previousPageBtn;

    //escape panel
    float escapeChance{};
    sf::RectangleShape escapeActionPanel;
    sf::Text escapeText;
    std::unique_ptr<gui::Button> escapeActionBtn;
    std::unique_ptr<gui::Button> escapeConfirmBtn;

    //battle field
    sf::RectangleShape enemyPos[5];
    sf::RectangleShape playerPos;
    std::unique_ptr<gui::PlayerStatusPanel> playerStatusPanel;
    std::unique_ptr<gui::EnemyStatusPanel> enemiesStatusPanel[5];

    sf::RectangleShape turnPanel;
    sf::Text turnPanelTitle;
    sf::Text turnPanelWho;
    sf::Text turnPanelLbl;
    sf::Text turnPanelActionLbl;

    void initResources();
    void initButtons();
    void initBattleFieldComponents();
    void initEscapePanel();
    void initStatsPanel();
    void initActionPanel();
    void initInventoryPanel();
    void initPauseMenu();
    void initBattleResultPanel();
    void spawnEnemyModel(sf::Vector2f pos, enemy_types type, unsigned int enemy_id);
    void generateModels();

    void playerBattle(unsigned int row_index);
    void useItem(unsigned int row_index);
    void endPlayerTurn();
    void enemyBattle(const float& dt);
    void endEnemyTurn();
    void endBattle();
};


#endif //DRAGONSLAYER_BATTLESTATE_H
