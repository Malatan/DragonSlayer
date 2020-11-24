//
// Created by Leonardo on 09/11/2020.
//

#ifndef DRAGONSLAYER_BATTLESTATE_H
#define DRAGONSLAYER_BATTLESTATE_H
#include <string>
#include <sstream>
#include "../Game/Item.h"
#include "../Game/Inventory.h"
#include "../Game/Stats.h"
#include "../Game/Player.h"
#include "../Game/Spell.h"
#include "../Game/Enemy.h"
#include "../Game/Generator.h"
#include "../Gui/Gui.h"
#include "State.h"
#include "../Game/Utils.h"
#include "../Components/PopUpTextComponent.h"

class BattleState : public State{
    const static int MAX_ENEMIES = 5;
    std::shared_ptr<Player> player;
    std::unique_ptr<Enemy> enemies[MAX_ENEMIES];
    std::vector<std::shared_ptr<Enemy>> enemiesModels;
    Player* playerModel;
    Item drops[MAX_ENEMIES];
    std::shared_ptr<PopUpTextComponent> popUpTextComponent;

    int floor;              //castle FLOOR - affects droprate
    int killCounter = 0;    //CONT killed enemies
    int enemyCount;         //NUMBER of tota{}l enemies
    int currentPanel;       // 0 = nothing, 1 = action, 2 = inventory, 3 = escape
    int selectedId;

    sf::Font* font;
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::RectangleShape mainActionPanel;
    sf::RectangleShape actionPanel;
    gui::Button actionBtn;
    sf::RectangleShape itemActionPanel;
    gui::Button itemActionBtn;

    //escape panel
    float escapeChance;
    sf::RectangleShape escapeActionPanel;
    sf::Text escapeText;
    gui::Button escapeActionBtn;
    gui::Button escapeConfirmBtn;

    //battle field
    sf::RectangleShape enemyPos[5];
    sf::RectangleShape playerPos;
    gui::PlayerStatusPanel playerStatusPanel;
    gui::EnemyStatusPanel enemiesStatusPanel[5];

public:
    //constructors/destructor
    BattleState(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Player> player, std::stack<std::unique_ptr<State>>* states,
                std::shared_ptr<PopUpTextComponent> popUpTextComponent,
                std::shared_ptr<ResourcesHandler> rsHandler, std::map<std::string, sf::Texture> textures,
                sf::Font *font, Enemy* enemy, int floor);
    ~BattleState() override;

    void initResources();
    void initButtons();
    void initBattleFieldComponents();
    void initEscapePanel();
    void spawnEnemy(sf::Vector2f pos, enemy_types type, bool generateStats);
    void generateModels(Enemy* enemy);

    bool battle();      //TRUE if player WIN
    bool playerTurn();  //TRUE depends on CheckWin()
    bool enemyTurn(int enemyIndex);   //TRUE if player DIES
    bool checkWin();    //TRUE if all enemies are DEAD
    void dropItem(int enemyIndex);


    void updatePlayerInput(const float &dt);
    void updateButtons();
    void updateInput(const float &dt) override;
    void update(const float& dt) override;
    void render(sf::RenderTarget* target) override;

};


#endif //DRAGONSLAYER_BATTLESTATE_H
