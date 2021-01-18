//
// Created by Zheng on 07/10/2020.
//

#include "GameState.h"

//init
void GameState::initTextures() {
    rsHandler->addResource("../Resources/Images/Sprites/Player/player_sheet.png", "player_sheet", "GameState");
    rsHandler->addResource("../Resources/Images/Sprites/Npc/shop_npc_idle.png", "shop_npc_sheet", "GameState");
    rsHandler->addResource("../Resources/Images/Sprites/Npc/priest_npc_idle.png", "priest_npc_sheet", "GameState");
    rsHandler->addResource("../Resources/Images/Sprites/Npc/wizard_npc_idle.png", "wizard_npc_sheet", "GameState");

    rsHandler->addResource("../Resources/Images/Sprites/Enemy/Witch/sprite_sheet.png", "wizard_enemy_sheet",
                           "GameState");
    rsHandler->addResource("../Resources/Images/Sprites/Enemy/Flying eye/sprite_sheet.png", "FlyingEye_enemy_sheet",
                           "GameState");
    rsHandler->addResource("../Resources/Images/Sprites/Enemy/Goblin/sprite_sheet.png", "Goblin_enemy_sheet",
                           "GameState");
    rsHandler->addResource("../Resources/Images/Sprites/Enemy/Mushroom/sprite_sheet.png", "Mushroom_enemy_sheet",
                           "GameState");
    rsHandler->addResource("../Resources/Images/Sprites/Enemy/Skeleton/sprite_sheet.png", "Skeleton_enemy_sheet",
                           "GameState");
    rsHandler->addResource("../Resources/Images/Sprites/Enemy/Skeleton2/sprite_sheet.png", "Skeleton_2_enemy_sheet",
                           "GameState");
    rsHandler->addResource("../Resources/Images/Sprites/Enemy/HeavyBandit/HeavyBandit.png", "BanditHeavy_enemy_sheet",
                           "GameState");
    rsHandler->addResource("../Resources/Images/Sprites/Enemy/LightBandit/LightBandit.png", "BanditLight_enemy_sheet",
                           "GameState");

    rsHandler->addResource("../Resources/Images/chat.png", "chattable_icon", "GameState");

    rsHandler->addResource("../Resources/Images/characterIcon.png", "characterIcon", "GameState");
    rsHandler->addResource("../Resources/Images/inventoryIcon.png", "inventoryIcon", "GameState");
    rsHandler->addResource("../Resources/Images/pauseMenuIcon.png", "pauseMenuIcon", "GameState");
    rsHandler->addResource("../Resources/Images/spellIcon.png", "spellIcon", "GameState");
    rsHandler->addResource("../Resources/Images/achievements.png", "achievementIcon", "GameState");

    rsHandler->addResource("../Resources/Images/equipslot_sheet.png", "EquipSlotsSheet", "GameState");
    rsHandler->addResource("../Resources/Images/items_sheet.png", "items_sheet", "GameState");
    rsHandler->addResource("../Resources/Images/selectedIcon.png", "selected", "GameState");
    rsHandler->addResource("../Resources/Images/new.png", "newTag", "GameState");
    rsHandler->addResource("../Resources/Images/weaponIcon.png", "weaponIcon", "GameState");
    rsHandler->addResource("../Resources/Images/shieldIcon.png", "shieldIcon", "GameState");
    rsHandler->addResource("../Resources/Images/helmetIcon.png", "helmetIcon", "GameState");
    rsHandler->addResource("../Resources/Images/armorIcon.png", "armorIcon", "GameState");
    rsHandler->addResource("../Resources/Images/glovesIcon.png", "glovesIcon", "GameState");
    rsHandler->addResource("../Resources/Images/bootsIcon.png", "bootsIcon", "GameState");
    rsHandler->addResource("../Resources/Images/arrow_down.png", "arrowDownIcon", "GameState");
    rsHandler->addResource("../Resources/Images/loot_bag.png", "lootBagSprite", "GameState");
    rsHandler->addResource("../Resources/Images/plus.png", "plusIcon", "GameState");

    textures["PLAYER_SHEET"].loadFromImage(rsHandler->getResourceByKey("player_sheet")->getImage());
    textures["SHOP_NPC_SHEET"].loadFromImage(rsHandler->getResourceByKey("shop_npc_sheet")->getImage());
    textures["PRIEST_NPC_SHEET"].loadFromImage(rsHandler->getResourceByKey("priest_npc_sheet")->getImage());
    textures["WIZARD_NPC_SHEET"].loadFromImage(rsHandler->getResourceByKey("wizard_npc_sheet")->getImage());

    textures["ENEMY_WIZARD_SHEET"].loadFromImage(rsHandler->getResourceByKey("wizard_enemy_sheet")->getImage());
    textures["ENEMY_FLYINGEYE_SHEET"].loadFromImage(rsHandler->getResourceByKey("FlyingEye_enemy_sheet")->getImage());
    textures["ENEMY_GOBLIN_SHEET"].loadFromImage(rsHandler->getResourceByKey("Goblin_enemy_sheet")->getImage());
    textures["ENEMY_MUSHROOM_SHEET"].loadFromImage(rsHandler->getResourceByKey("Mushroom_enemy_sheet")->getImage());
    textures["ENEMY_SKELETON_SHEET"].loadFromImage(rsHandler->getResourceByKey("Skeleton_enemy_sheet")->getImage());
    textures["ENEMY_SKELETON_2_SHEET"].loadFromImage(rsHandler->getResourceByKey("Skeleton_2_enemy_sheet")->getImage());
    textures["ENEMY_BANDITHEAVY_SHEET"].loadFromImage(rsHandler->getResourceByKey("BanditHeavy_enemy_sheet")->getImage());
    textures["ENEMY_BANDITLIGHT_SHEET"].loadFromImage(rsHandler->getResourceByKey("BanditLight_enemy_sheet")->getImage());

    textures["CHATTABLE_ICON"].loadFromImage(rsHandler->getResourceByKey("chattable_icon")->getImage());

    textures["CHARACTER_ICON"].loadFromImage(rsHandler->getResourceByKey("characterIcon")->getImage());
    textures["INVENTORY_ICON"].loadFromImage(rsHandler->getResourceByKey("inventoryIcon")->getImage());
    textures["PAUSEMENU_ICON"].loadFromImage(rsHandler->getResourceByKey("pauseMenuIcon")->getImage());
    textures["SPELL_ICON"].loadFromImage(rsHandler->getResourceByKey("spellIcon")->getImage());
    textures["ACHIEVEMENT_ICON"].loadFromImage(rsHandler->getResourceByKey("achievementIcon")->getImage());

    textures["ITEMS_SHEET"].loadFromImage(rsHandler->getResourceByKey("items_sheet")->getImage());
    textures["EquipSlotsSheet"].loadFromImage(rsHandler->getResourceByKey("EquipSlotsSheet")->getImage());
    textures["SELECTED_ICON"].loadFromImage(rsHandler->getResourceByKey("selected")->getImage());
    textures["NEW_TAG"].loadFromImage(rsHandler->getResourceByKey("newTag")->getImage());
    textures["WEAPON_ICON"].loadFromImage(rsHandler->getResourceByKey("weaponIcon")->getImage());
    textures["SHIELD_ICON"].loadFromImage(rsHandler->getResourceByKey("shieldIcon")->getImage());
    textures["HELMET_ICON"].loadFromImage(rsHandler->getResourceByKey("helmetIcon")->getImage());
    textures["ARMOR_ICON"].loadFromImage(rsHandler->getResourceByKey("armorIcon")->getImage());
    textures["GLOVES_ICON"].loadFromImage(rsHandler->getResourceByKey("glovesIcon")->getImage());
    textures["BOOTS_ICON"].loadFromImage(rsHandler->getResourceByKey("bootsIcon")->getImage());
    textures["ARROWDOWN_ICON"].loadFromImage(rsHandler->getResourceByKey("arrowDownIcon")->getImage());
    textures["LOOTBAG_SPRITE"].loadFromImage(rsHandler->getResourceByKey("lootBagSprite")->getImage());
    textures["PLUS_ICON"].loadFromImage(rsHandler->getResourceByKey("plusIcon")->getImage());
}

void GameState::initPauseMenu() {
    pmenu = std::make_unique<PauseMenu>(window, font);

    pmenu->addButton("SPELL", 200.f, "Spells", 30);
    pmenu->addButton("CHARACTER", 300.f, "Character", 30);
    pmenu->addButton("ACHIEVEMENT", 400.f, "Achievement", 30);
    pmenu->addButton("LOADSAVE", 500.f, "Load/Save", 30);
    pmenu->addButton("BACK", 600.f, "Resume", 30);
    pmenu->addButton("QUIT", 700.f, "QUIT", 50);
}

void GameState::initPlayers() {
    player = std::make_shared<Player>(spawnPos.x, spawnPos.y, 2.f, 2.f,
                                      textures["PLAYER_SHEET"]);
    if(loadSaveTab->canApplySave()){
        Save* save = loadSaveTab->getApplySave();
        player->setGold(save->playerGold);
        player->setStats(&save->playerStats);
        player->setInventory(save->inventory);
        player->getInventory()->setCurrentMaxSpace(save->playerInventoryMaxSpace);
    }else{
        player->setGold(0);
        // legge i valori di default del Stats dal Data/Stats.txt
        player->initStats();
        rsHandler->loadPlayerStatsTxt(player->getPlayerStats());
        // legge i valori di default dell 'inventario dal Data/Inventory.txt
        player->initInventory();
        player->getInventory()->setCurrentMaxSpace(35);
        rsHandler->loadPlayerInventoryTxt(player->getInventory());
    }
    player->getPlayerStats()->updateMultipliers();
}

void GameState::initTabs() {
    cTab = std::make_shared<CharacterTab>(window, font, player,
                                          this, getTextures(), rsHandler, &npcInteract);
    initEquipSlotsTextures();
    shopTab = std::make_shared<ShopTab>(window, font, player, this,
                                        rsHandler, lootGenerator, textures);
    initShopItemTextures();
    priestTab = std::make_shared<PriestTab>(window, font, player, this, rsHandler, textures);
    spellTab = std::make_shared<SpellTab>(window, font, player, this, rsHandler, textures);
    wizardTab = std::make_shared<WizardTab>(window, font, player, this, textures);
    selectLevelTab = std::make_shared<SelectLevelTab>(window, font, player, this, rsHandler);
    achievementTab = std::make_shared<AchievementTab>(window, font, this, achievementComponent);
    achievementComponent->setAchievementTab(achievementTab);
    if(loadSaveTab->canApplySave()){
        Save* save = loadSaveTab->getApplySave();
        for(auto i : save->equips){
            if(i.second != 0){
                player->getInventory()->getItemById(i.second)->setEquipped(false);
                cTab->selectItemById(i.second);
                cTab->equipUnEquipBtnFunction();
                player->setStats(&save->playerStats);
            }
        }
    }
   // achievementComponent->unlockAllAchievements();
}

void GameState::initHintsTab() {
    hints.setFont(*font);
    hints.setCharacterSize(30);
    hints.setString(" <Esc> to pause\n"
                          " <W,A,S,D> to move\n"
                          " <E> to interact\n"
                          " <P> to open/close spell tab\n"
                          " <C> to open/close character tab\n"
                          " <O> to open/close achievements tab\n"
                          " <M> to gain gold\n"
                          " <T> to gain exp\n"
                          " <X> to noclip\n"
                          " <F12> to screenshot\n"
                                );

    hints.setPosition(5.f, window->getSize().y - hints.getGlobalBounds().height + 20.f);
}

void GameState::initEquipSlotsTextures(){
    //weapon
    rsHandler->setEquipSlotsTextureIntRect(5 , sf::IntRect(0, 0, 67, 67));
    cTab->getEquipSlots()[WEAPON_SLOT]->setSlotTexture(&textures["EquipSlotsSheet"],
            sf::IntRect(0, 0, 67, 67));
    //shield
    rsHandler->setEquipSlotsTextureIntRect(4 , sf::IntRect(67, 0, 67, 67));
    cTab->getEquipSlots()[SHIELD_SLOT]->setSlotTexture(&textures["EquipSlotsSheet"],
            sf::IntRect(67, 0, 67, 67));
    //head
    rsHandler->setEquipSlotsTextureIntRect(3 , sf::IntRect(134, 0, 67, 67));
    cTab->getEquipSlots()[HEAD_SLOT]->setSlotTexture(&textures["EquipSlotsSheet"],
            sf::IntRect(134, 0, 67, 67));
    //chest
    rsHandler->setEquipSlotsTextureIntRect(2 , sf::IntRect(201, 0, 67, 67));
    cTab->getEquipSlots()[CHEST_SLOT]->setSlotTexture(&textures["EquipSlotsSheet"],
            sf::IntRect(201, 0, 67, 67));
    //arms
    rsHandler->setEquipSlotsTextureIntRect(1 , sf::IntRect(268, 0, 67, 67));
    cTab->getEquipSlots()[ARMS_SLOT]->setSlotTexture(&textures["EquipSlotsSheet"],
            sf::IntRect(268, 0, 67, 67));
    //legs
    rsHandler->setEquipSlotsTextureIntRect(0 , sf::IntRect(335, 0, 67, 67));
    cTab->getEquipSlots()[LEGS_USAGE]->setSlotTexture(&textures["EquipSlotsSheet"],
            sf::IntRect(335, 0, 67, 67));
}

void GameState::initShopItemTextures() {
    for(const auto& i : shopTab->getShopSlots()){
        i->setSlotTexture(&textures["ITEMS_SHEET"], 34.f);
    }
}

void GameState::initComponents() {
    pathFinder = std::make_shared<PathFinder>();
    spellComponent = std::make_shared<SpellComponent>();
    achievementComponent = std::make_shared<AchievementComponent>(font);
    buffComponent = std::make_shared<BuffComponent>(popUpTextComponent, player, this, font);
    if(loadSaveTab->canApplySave()){
        Save* save = loadSaveTab->getApplySave();
        spellComponent->fill(save->spells, save->playerSpells);
        achievementComponent->loadRecords(save->aeRecords);
        achievementComponent->loadAchievements(save->achievements);
        buffComponent->loadPlayerBuffs(save->playerBuffs);
    }else{
        rsHandler->loadSpellList(spellComponent);
        rsHandler->loadAchievementsTxt(achievementComponent->getAchievements());
    }
}

void GameState::initLootGenerator() {
    lootGenerator = std::make_shared<LootGenerator>(rsHandler);
}

void GameState::initView() {
    locationLbl.setFont(*font);
    locationLbl.setCharacterSize(20);

    view.setSize(
            sf::Vector2f(
                    static_cast<float>(window->getSize().x / 1.3f),
                    static_cast<float>(window->getSize().y / 1.3f)
            )
    );

    view.setCenter(
            sf::Vector2f(
                    static_cast<float>(window->getSize().x / 2.f),
                    static_cast<float>(window->getSize().y / 2.f)
            )
    );
}

void GameState::initDebugText() {
    debugText.setFont(*font);
    debugText.setCharacterSize(25);
    debugText.setFillColor(sf::Color::Red);
    debugText.setString("Debug text");
    debugText.setPosition(5.f, 40.f);
}

void GameState::initButtons() {
    pauseMenuBtn = std::make_unique<gui::Button>(
            window->getSize().x - 100.f,
            window->getSize().y - 90.f, 70.f, 70.f,
            font, "", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color::Transparent,
            sf::Color(70, 70, 70, 60),
            sf::Color(130, 130, 130, 0));
    pauseMenuBtn->setBackgroundTexture(&textures["PAUSEMENU_ICON"]);
    pauseMenuBtn->setBackbgroundDisabled(false);

    achievementTabBtn = std::make_unique<gui::Button>(
            pauseMenuBtn->getPosition().x - 100.f,
            pauseMenuBtn->getPosition().y, 70.f, 70.f,
            font, "", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color::Transparent,
            sf::Color(70, 70, 70, 60),
            sf::Color(130, 130, 130, 0));
    achievementTabBtn->setBackgroundTexture(&textures["ACHIEVEMENT_ICON"]);
    achievementTabBtn->setBackbgroundDisabled(false);

    spellTabBtn = std::make_unique<gui::Button>(
            achievementTabBtn->getPosition().x - 100.f,
            achievementTabBtn->getPosition().y, 70.f, 70.f,
            font, "", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color::Transparent,
            sf::Color(70, 70, 70, 60),
            sf::Color(130, 130, 130, 0));
    spellTabBtn->setBackgroundTexture(&textures["SPELL_ICON"]);
    spellTabBtn->setBackbgroundDisabled(false);

    cTabBtn = std::make_unique<gui::Button>(
            spellTabBtn->getPosition().x - 100.f,
            spellTabBtn->getPosition().y, 70.f, 70.f,
            font, "", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color::Transparent,
            sf::Color(70, 70, 70, 60),
            sf::Color(130, 130, 130, 0));
    cTabBtn->setBackgroundTexture(&textures["INVENTORY_ICON"]);
    cTabBtn->setBackbgroundDisabled(false);

}

void GameState::initMaps() {
    mg = std::make_shared<MapGenerator>(this);
    if(loadSaveTab->canApplySave()){
        Save* save = loadSaveTab->getApplySave();
        mg->setDDims(save->levelDims);
        utils::writeStringToFile(save->floor1, "../Data/Dungeon_1.txt");
        utils::writeStringToFile(save->floor2, "../Data/Dungeon_2.txt");
        utils::writeStringToFile(save->floor3, "../Data/Dungeon_3.txt");
        utils::writeStringToFile(save->floor4, "../Data/Dungeon_4.txt");
        utils::writeStringToFile(save->floor5, "../Data/Dungeon_5.txt");
        floorReached = save->reachedFloor;
        changeMap(save->currentFloor, true);
        if(!save->openedDoors.empty()){
            map->setOpenDoors(save->openedDoors);
        }
        if(!save->lootBags.empty()){
            lootBags.clear();
            lootBags.reserve(save->lootBags.size());
            for(const auto& i : save->lootBags){
                std::vector<std::shared_ptr<Item>> sp_loots;
                for(const auto& j : i.getLoots()){
                    sp_loots.push_back(std::make_shared<Item>(j));
                }
                std::shared_ptr<LootBag> lb = std::make_shared<LootBag>(
                        window, sf::Vector2f(i.getPosX(), i.getPosY()),
                        textures, player, this, sp_loots, font, 0, i.getId());
                lb->setLifeTimep(i.getLifeTime());
                lb->setMsCounter(i.getMsCounter());
                lootBags.push_back(lb);
            }
        }
        player->setPosition(save->playerPosX, save->playerPosY);
    }else{
        floorReached = 0;
        mg->generateDungeon(1);
        mg->generateDungeon(2);
        mg->generateDungeon(3);
        mg->generateDungeon(4);
        mg->generateDungeon(5);
        changeMap(0);
    }
}

void GameState::initShader() {
    if(rsHandler->isUnitTesting()){
        if(!coreShader.loadFromFile("../../Shader/vertex_shader.vert",
                                    "../../Shader/fragment_shader.frag")){
            std::cerr<<"Error while loading shader" << std::endl;
        }
    }else{
        if(!coreShader.loadFromFile("../Shader/vertex_shader.vert",
                                    "../Shader/fragment_shader.frag")){
            std::cerr<<"Error while loading shader" << std::endl;
        }
    }
}

void GameState::initObservers() {
    addObserver(achievementComponent.get());
}

void GameState::preNotifiers() {
    notify(AE_P_MAXEDSPELL, spellComponent->maxedPlayerSpellsSize());
    notify(AE_P_LEVEL, player->getPlayerStats()->getLevel());
}

void GameState::applySaveValue() {
    if(loadSaveTab->canApplySave()){
        Save* save = loadSaveTab->getApplySave();
        rsHandler->setIdCounter(save->rsHandlerIdCounter);
    }
}

//constructors/destructors
GameState::GameState(std::shared_ptr<sf::RenderWindow> window, std::stack<std::unique_ptr<State>>* states,
                     std::shared_ptr<ResourcesHandler> rsHandler, std::shared_ptr<PopUpTextComponent> popuptext_component,
                     std::shared_ptr<LoadSaveTab> loadsave_tab, sf::Font *font, state_enum _state_enum)
        : State(std::move(window), states, std::move(rsHandler), _state_enum), loadSaveTab(std::move(loadsave_tab)){
    this->font = font;
    popUpTextComponent = std::move(popuptext_component);
    stato = NO_TAB;
    npcInteract = NO_NPC;
    noclip = false;
    enemyRenderDistance = 350.f;
    loadSaveTab->setState(this);
    loadSaveTab->setAccessOption(LOAD_SAVE);
    applySaveValue();
    initShader();
    initTextures();
    initPauseMenu();
    initPlayers();
    initComponents();
    initLootGenerator();
    initView();
    initDebugText();
    initButtons();
    initTabs();
    initHintsTab();
    initMaps();
    initObservers();
    preNotifiers();
    this->loadSaveTab->endApplySave();
}

GameState::~GameState() {
    for(auto i : npcs)
        delete i;
}

//accessors
std::shared_ptr<BuffComponent>& GameState::getBuffComponent() {
    return buffComponent;
}

std::shared_ptr<PopUpTextComponent>& GameState::getPopUpTextComponent() {
    return popUpTextComponent;
}

std::shared_ptr<SpellComponent>& GameState::getSpellComponent() {
    return spellComponent;
}

std::shared_ptr<SpellTab>& GameState::getSpellTab() {
    return spellTab;
}

std::shared_ptr<LootGenerator>& GameState::getLootGenerator() {
    return lootGenerator;
}

std::shared_ptr<ResourcesHandler>& GameState::getResourceHandler() {
    return rsHandler;
}

std::shared_ptr<AchievementComponent> &GameState::getAchievementComponent() {
    return achievementComponent;
}

std::shared_ptr<MapGenerator> &GameState::getMapGenerator() {
    return mg;
}

std::shared_ptr<Player>& GameState::getPlayer() {
    return player;
}

std::shared_ptr<Enemy>& GameState::getEnemy(int index) {
    return enemies[index];
}

std::vector<std::shared_ptr<Enemy>> &GameState::getEnemies() {
    return enemies;
}

std::vector<std::shared_ptr<LootBag>> &GameState::getLootBags() {
    return lootBags;
}

Npc *GameState::getNpc(int index) {
    if(index < npcs.size())
        return npcs[index];
    return nullptr;
}

npc_type GameState::getInteractNpc() const {
    return npcInteract;
}

bool GameState::getStateKeyTime() {
    return getKeyTime();
}

int GameState::getCurrentFloor() const {
    return currentFloor;
}

int GameState::getReachedFloor() const {
    return floorReached;
}

Map *GameState::getMap() {
    return map;
}

//observer

void GameState::addObserver(Observer *observer) {
    observers.push_back(observer);
}

void GameState::removeObserver(Observer *observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void GameState::notify(achievement_event event, int value) {
    for(auto i : observers){
        i->onNotify(event, value);
    }
}

//functions
std::pair<int, int> GameState::getEnemyCount(bool count_followers) const {
    std::pair<int, int> p = {enemies.size(), 0};
    if(count_followers){
        for(const auto& i : enemies){
            p.second += i->getFollowersNumber();
        }
    }
    return p;
}

void GameState::addItem(const std::shared_ptr<Item>& new_item) {
    if(player->getInventory()->addItem(new_item)){
        player->getInventory()->sortByItemType();
        cTab->initInventorySlots();
        for(auto &i : cTab->getInventorySlots()){
            if(i->getItem()->isEquipped()){
                switch(i->getItem()->getUsageType()){
                    case WEAPON_USAGE:
                        i->setUpRightTexture(&textures["WEAPON_ICON"]);
                        break;
                    case SHIELD_USAGE:
                        i->setUpRightTexture(&textures["SHIELD_ICON"]);
                        break;
                    case HEAD_USAGE:
                        i->setUpRightTexture(&textures["HELMET_ICON"]);
                        break;
                    case CHEST_USAGE:
                        i->setUpRightTexture(&textures["ARMOR_ICON"]);
                        break;
                    case ARMS_USAGE:
                        i->setUpRightTexture(&textures["GLOVES_ICON"]);
                        break;
                    case LEGS_USAGE:
                        i->setUpRightTexture(&textures["BOOTS_ICON"]);
                        break;
                    default:
                        break;
                }
            }
        }
        updateTabsInvSpaceLbl();
    }
}

std::shared_ptr<Enemy> GameState::enemyFactory(float x, float y, enemy_types type, bool generate_stats) {
    std::shared_ptr<Enemy> new_enemy;
    switch(type){
        case WITCH:
            new_enemy = std::make_shared<Enemy>(WITCH, x, y, 1.2f, 1.2f,
                                                127.f, 136.f, 50.f, 65.f,
                                                150.f, 200.f, 9.f,
                                                textures["ENEMY_WIZARD_SHEET"], this);
            break;
        case SKELETON:
            new_enemy = std::make_shared<Enemy>(SKELETON, x, y, 2.f, 2.3f,
                                                85.f, 100.f, 40.f, 60.f,
                                                105.f, 159.f, 8.f,
                                                textures["ENEMY_SKELETON_SHEET"], this);
            break;
        case SKELETON_2:
            new_enemy = std::make_shared<Enemy>(SKELETON_2, x, y, 1.2f, 1.2f,
                                                70.f, 60.f, 50.f, 63.f,
                                                95.f, 122.f, 10.f,
                                                textures["ENEMY_SKELETON_2_SHEET"], this);
            break;
        case FLYING_EYE:
            new_enemy = std::make_shared<Enemy>(FLYING_EYE, x, y, 1.3f, 1.3f,
                                                72.f, 85.f, 58.f, 60.f,
                                                100.f, 142.f, 11.f,
                                                textures["ENEMY_FLYINGEYE_SHEET"], this);
            break;
        case GOBLIN:
            new_enemy = std::make_shared<Enemy>(GOBLIN, x, y, 1.2f, 1.4f,
                                                70.f, 94.f, 40.f, 48.f,
                                                90.f, 142.f, 8.f,
                                                textures["ENEMY_GOBLIN_SHEET"], this);
            break;
        case MUSHROOM:
            new_enemy = std::make_shared<Enemy>(MUSHROOM, x, y, 1.4f, 1.4f,
                                                87.f, 87.f, 38.f, 57.f,
                                                106.f, 143.f, 8.f,
                                                textures["ENEMY_MUSHROOM_SHEET"], this);
            break;
        case BANDIT_HEAVY:
            new_enemy = std::make_shared<Enemy>(BANDIT_HEAVY, x, y, 1.8f, 1.8f,
                                                25.f, 15.f, 45.f, 68.f,
                                                47.f, 83.f, 9.f,
                                                textures["ENEMY_BANDITHEAVY_SHEET"], this);
            break;
        case BANDIT_LIGHT:
            new_enemy = std::make_shared<Enemy>(BANDIT_LIGHT, x, y, 1.8f, 1.8f,
                                                25.f, 15.f, 45.f, 68.f,
                                                47.f, 83.f, 9.f,
                                                textures["ENEMY_BANDITLIGHT_SHEET"], this);
            break;
        default:
            std::cout<<"No such enemy: " << type;
            break;
    }
    return new_enemy;
}

void GameState::spawnEnemy(float x, float y, enemy_types type, unsigned int enemy_followers) {
    std::shared_ptr<Enemy> new_enemy;
    bool new_enemy_spawned = false;
    new_enemy = enemyFactory(x, y, type, true);
    if(new_enemy){
        new_enemy->setId(rsHandler->generateId());
        new_enemy->generateEnemyStats(currentFloor);
        new_enemy_spawned = true;
        enemies.push_back(new_enemy);
    }
    if(new_enemy_spawned){
        // se enemy_follwers == 5 allora si genera in modo randomico il numero dei follwers
        if(enemy_followers == 5){
            // genera n followers con n in [0,4]
            int n_followers = utils::generateRandomNumber(0, currentFloor - 1);
            if (n_followers > Enemy::MAX_FOLLOWERS)
                n_followers = Enemy::MAX_FOLLOWERS;

            if(n_followers > 0){
                //genera in modo randomico l'enum del tipo dei followers
                std::vector<int> enemyEnums = utils::generateRandomNumbers(0, 7, n_followers);
                for(auto i : enemyEnums){
                    //il livello del follower deve essere minore di [2,5] del nemico capo
                    int level_diff = utils::generateRandomNumber(2, 5);
                    int new_follower_level = new_enemy->getStats()->getLevel() - level_diff;

                    new_enemy->addFollower(std::make_shared<Enemy>(
                            static_cast<enemy_types>(i), new_follower_level, currentFloor, rsHandler->generateId()));
                }
                new_enemy->updateStatsBoost(true);
            }
        }else if(enemy_followers > 0){
            // altrimenti si genera n nemico dove n = enemy_follwers
            // se n <= 0 allora n = 0
            // se n > 4 allora n = 4
            if(enemy_followers > 4)
                enemy_followers = 4;

            //genera in modo randomico l'enum del tipo dei followers
            std::vector<int> enemyEnums = utils::generateRandomNumbers(0, 7, (int)enemy_followers);
            for(auto i : enemyEnums){
                //il livello del follower deve essere minore di [2,5] del nemico capo
                int level_diff = utils::generateRandomNumber(2, 5);
                int new_follower_level = new_enemy->getStats()->getLevel() - level_diff;

                new_enemy->addFollower(std::make_shared<Enemy>(
                        static_cast<enemy_types>(i), new_follower_level, currentFloor, rsHandler->generateId()));
            }
            new_enemy->updateStatsBoost(true);
        }
    }
}

void GameState::spawnNpc(float x, float y, npc_type spawn_npc_type) {
    switch (spawn_npc_type) {
        case SHOP:
            npcs.push_back(new Npc(spawn_npc_type, x, y, 1.5f, 1.5f,
                                   textures["SHOP_NPC_SHEET"], textures["CHATTABLE_ICON"]));
            break;
        case PRIEST:
            npcs.push_back(new Npc(spawn_npc_type, x, y, 1.5f, 1.5f,
                                   textures["PRIEST_NPC_SHEET"], textures["CHATTABLE_ICON"]));
            break;
        case WIZARD:
            npcs.push_back(new Npc(spawn_npc_type, x, y, 0.7f, 0.7f,
                                   textures["WIZARD_NPC_SHEET"], textures["CHATTABLE_ICON"]));
            break;
        case NO_NPC: case DEFAULT_NPC:
            break;
    }
}

bool GameState::deleteEnemyById(unsigned int enemy_id) {
    for(auto iter = enemies.begin(); iter != enemies.end(); ++iter ){
        if((*iter)->getId() == enemy_id){
            enemies.erase( iter );
            return true;
        }
    }
    return false;
}

void GameState::changeStato(state_tab current_stato) {
    if(!paused){
        pauseState();
        stato = current_stato;
    } else{
        unpauseState();
        stato = NO_TAB;
        window->setMouseCursorVisible(true);
    }
}

void GameState::checkBattleResult(BattleResult* battle_result) {
    switch(battle_result->getResultType()){
        case WIN:{
            int exp_gain = battle_result->getExpGainCount();
            int gold_gain = battle_result->getGoldGainCount();

            if(exp_gain > 0){
                if(player->getPlayerStats()->addExp(exp_gain)){
                    updateTabsPlayerStatsLbl();
                    notify(AE_P_LEVEL, player->getPlayerStats()->getLevel());
                }
                popUpTextComponent->addPopUpTextCenter(EXPERIENCE_TAG, exp_gain,"+", "Exp");
            }

            if(gold_gain > 0){
                player->addGold(gold_gain);
                updateTabsGoldLbl();
                popUpTextComponent->addPopUpTextCenterYShifted(GOLD_TAG, gold_gain, "+", " gold", -50.f);
            }

            for(const auto& i : enemies){
                if(i->getId() == battle_result->getEnemyLeaderId()){
                    std::vector<std::shared_ptr<Item>> juices = lootGenerator->generateLoot(i, currentFloor);
                    int lootbag_lifetime = 999;
                    if(!juices.empty()){
                        //controlla se e' nel mergerange di altri lootbag
                        bool merged = false;
                        sf::FloatRect app = {i->getGlobalBounds().left, i->getGlobalBounds().top,
                                             40.f, 40.f};
                        for(const auto& j : lootBags){
                            if(j->canMerge(app)){
                                j->mergeLoots(juices);
                                j->setLifeTime(lootbag_lifetime);
                                merged = true;
                                break;
                            }
                        }
                        if(!merged){
                            lootBags.push_back(
                                    std::make_shared<LootBag>(
                                            window, i->getPosition(), textures, player, this, juices, font,
                                            lootbag_lifetime, rsHandler->generateId()));
                        }
                    }
                    break;
                }
            }
            deleteEnemyById(battle_result->getEnemyLeaderId());
            player->stopVelocity();
            break;
        }
        case LOST:{
            changeMap(0);
            float new_hp = ((float)player->getPlayerStats()->getFinalHp()/100.f) * 10.f;
            float new_mp = ((float)player->getPlayerStats()->getFinalMp()/100.f) * 10.f;
            player->getPlayerStats()->setHp((int)new_hp);
            player->getPlayerStats()->setMp((int)new_mp);
            player->setPosition(spawnPos.x, spawnPos.y);
            player->stopVelocity();
            break;
        }
        case QUIT_GAME:
            enemies.clear();
            endState();
            break;
        case ESCAPED:
            player->setPosition(spawnPos.x, spawnPos.y);
            player->stopVelocity();
            break;
        case NOT_FINISHED:
            break;
    }
    player->clearWayPoints();
    if(battle_result->getResultType() != QUIT_GAME){
        //notifica achivements data
        for(auto i : battle_result->getAchievementDataSet()){
            notify(i.first, i.second);
        }
    }
}

void GameState::updateLocationLbl() {
    std::stringstream ss;
    ss << "Current location: ";
    switch (currentFloor) {
        case 0:{
            ss << "Hub";
            break;
        }
        case 1:{
            ss << "Dungeon - First Floor";
            break;
        }
        case 2:{
            ss << "Dungeon - Second Floor";
            break;
        }
        case 3:{
            ss << "Dungeon - Third Floor";
            break;
        }
        case 4:{
            ss << "Dungeon - Fourth Floor";
            break;
        }
        case 5:{
            ss << "Dungeon - Fifth Floor";
            break;
        }
        case 6:{
            ss << "Dungeon - Boss Room";
            break;
        }
        default:
            ss << "Unknown";
            break;
    }
    locationLbl.setString(ss.str());
    locationLbl.setPosition(window->getSize().x - locationLbl.getGlobalBounds().width - 10.f,
                            locationLbl.getGlobalBounds().height - 10.f);
}

void GameState::updateInput(const float &dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && getKeyTime()) {
        changeStato(PAUSEMENU_TAB);
        loadSaveTab->setGameScreen(getScreenShoot());
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && getKeyTime()) {
        changeStato(CHARACTER_TAB);
        cTab->unselectAll();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && getKeyTime()) {
        changeStato(SPELL_TAB);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) && getKeyTime()) {
        changeStato(ACHIEVEMENT_TAB);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && getKeyTime()) {
        player->getMovementComponent()->enableSpeedControl(noclip);
        noclip = !noclip;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && getKeyTime()) {
        int exp = utils::generateRandomNumber(100, 5000);
        if(player->getPlayerStats()->addExp(exp)){
            updateTabsPlayerStatsLbl();
            notify(AE_P_LEVEL, player->getPlayerStats()->getLevel());
        }
        popUpTextComponent->addPopUpTextCenter(EXPERIENCE_TAG, exp, "+", "Exp");
        notify(AE_P_EXP, exp);
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::M) && getKeyTime()){
        int gold = utils::generateRandomNumber(99999, 999999);
        player->addGold(gold);
        updateTabsGoldLbl();
        popUpTextComponent->addPopUpTextCenter(GOLD_TAG, gold, "+", " gold");
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && getKeyTime()){
        if(npcInteract != NO_NPC){
            switch(npcInteract){
                case SHOP:
                    changeStato(SHOP_TAB);
                    break;
                case PRIEST:
                    changeStato(PRIEST_TAB);
                    break;
                case WIZARD:
                    changeStato(WIZARD_TAB);
                    break;
                default:
                    std::cout<<"no npc\n";
                    break;
            }
            player->stopVelocity();
        } else if(interactLootBag.first != 0){
            changeStato(LOOTBAG_TAB);
            player->stopVelocity();
        } else if(map->isInteracting()){
            if(map->getIntTile().type == DOORH){
                selectLevelTab->setHide(false);
                changeStato(SELECTLEVEL_TAB);
                player->stopVelocity();
            } else if(map->getIntTile().type == DOWNSTAIRS){
                changeMap(0);
            } else if(map->getIntTile().type == UPSTAIRS){
                if(currentFloor < 5){
                    int next_floor = currentFloor + 1;
                    changeMap(next_floor);
                }
            } else if(map->getIntTile().type == CLOSEDOOR){
                map->openDoor(map->getIntTile().y, map->getIntTile().x);
                pathFinder->updateNodes(map, player->getGridPosition());
            }
        }
    }
}

void GameState::updateGlobalInput(const float &dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F12) && getKeyTime()) {
        std::string msg = saveScreenShoot();
        popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG, msg, "", "");
    }
}

void GameState::updateMouseInput(const float &dt) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && getKeyTime()) {
        int node_x = (int)(mousePosView.x/(Tile::TILE_SIZE/(float)pathFinder->nodeMultiplier));
        int node_y = (int)(mousePosView.y/(Tile::TILE_SIZE/(float)pathFinder->nodeMultiplier));
        if(pathFinder->nodes[node_y][node_x]->isWalkable()){
            bool path_found;
            if(currentFloor == 0){
                path_found = pathFinder->FindPath(player->getCollisionBoxCenter(), mousePosView, 9999);
            }else{
                path_found = pathFinder->FindPath(player->getCollisionBoxCenter(), mousePosView, 400);
            }
            if(path_found){
                player->clearWayPoints();
                for(auto i : pathFinder->path){
                    auto mod = (float)pathFinder->nodeMultiplier;
                    sf::Vector2f new_waypoint = {((float)i->getPosX() * Tile::TILE_SIZE/mod)
                                                 + Tile::TILE_SIZE/(2.f * mod),
                                                 ((float)i->getPosY() * Tile::TILE_SIZE/mod)
                                                 + Tile::TILE_SIZE/(2.f * mod)};
                    player->addWayPoint(new_waypoint);
                }
            }
        }
    }
}

void GameState::updatePlayerInput(const float &dt) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        player->move(dt, -1.f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        player->move(dt, 1.f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        player->move(dt, 0.f, -1.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        player->move(dt, 0.f, 1.f);
    }
}

void GameState::updateTabsGoldLbl() {
    cTab->updateGoldLbl();
    shopTab->updateGoldLbl();
    priestTab->updateGoldLbl();
    wizardTab->updateGoldLbl();
}

void GameState::updateTabsInvSpaceLbl() {
    cTab->updateInventoryCapLbl();
    shopTab->updateInvSpaceLbl();
}

void GameState::updateTabsPlayerStatsLbl(state_tab update_tab) {
    switch (update_tab) {
        case NO_TAB:
            cTab->updatePlayerStatsLbl();
            spellTab->updateSpellsInfoLbl();
            break;
        case CHARACTER_TAB:
            cTab->updatePlayerStatsLbl();
            break;
        case SPELL_TAB:
            spellTab->updateSpellsInfoLbl();
            break;
        default:
            std::cout<<"Unknown tab"<<endl;
            break;
    }

}

void GameState::updatePausedMenuButtons() {
    if(pmenu->isButtonPressed("QUIT") && getKeyTime()){
        endState();
    } else if(pmenu->isButtonPressed("BACK") && getKeyTime()){
        changeStato(NO_TAB);
    } else if(pmenu->isButtonPressed("SPELL") && getKeyTime()){
        changeStato(NO_TAB);
        changeStato(SPELL_TAB);
    } else if(pmenu->isButtonPressed("CHARACTER") && getKeyTime()){
        changeStato(NO_TAB);
        changeStato(CHARACTER_TAB);
    } else if(pmenu->isButtonPressed("ACHIEVEMENT") && getKeyTime()){
        changeStato(NO_TAB);
        changeStato(ACHIEVEMENT_TAB);
    } else if(pmenu->isButtonPressed("LOADSAVE") && getKeyTime()){
        changeStato(NO_TAB);
        changeStato(LOADSAVE_TAB);
        loadSaveTab->setHide(false);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && getKeyTime()){
        changeStato(NO_TAB);
    }
}

void GameState::updateView(const float &dt) {
    view.setCenter(player->getHitboxComponent()->getCenter());
    sf::Vector2f player_pos = player->getHitboxComponent()->getCenter();
    sf::Vector2f view_center = view.getCenter();
    sf::Vector2f view_size = view.getSize();
    float map_width = map->getWidthP();
    float map_height = map->getHeightP();
    if(player_pos.y - (view_size.y/2.f) < 0.f){
        view_center.y = view_size.y /2;
    }
    if(player_pos.y + (view_size.y/2.f) > map_height){
        view_center.y = map_height - (view_size.y/2);
    }
    if(player_pos.x - (view_size.x/2.f) < 0.f){
        view_center.x = view_size.x/2;
    }
    if(player_pos.x + (view_size.x/2) > map_width){
        view_center.x = map_width - (view_size.x/2);
    }
    view.setCenter(view_center);
}

void GameState::updateDebugText() {
    sf::Vector2f vv = player->getMovementComponent()->getVelocity();
    sf::Vector2f vd = player->getMovementComponent()->getDirection();
    //debbuging tool: show mouse pos coords
    std::stringstream ss;
    ss << "Mouse pos: x: " << mousePosView.x << " y: " << mousePosView.y << std::endl
        << "Enemies: " << enemies.size() << std::endl
        << "Lootbags: " << lootBags.size() << std::endl
        << "Nodes[x]: " << pathFinder->widthN << " Nodes[y]: " << pathFinder->heightN << std::endl
        << "Nodes: " << pathFinder->nodesN << " Empty nodes: " << pathFinder->emptyNodes << std::endl
        << "Dx: " << vd.x << std::endl << "Dy: " << vd.y << std::endl
        << "Vx: " << vv.x << std::endl << "Vy: " << vv.y;
    debugText.setString(ss.str());
}

void GameState::updateButtons() {
    if(cTabBtn->isPressed() && getKeyTime()){
        cTabBtn->setButtonState(BTN_IDLE);
        changeStato(CHARACTER_TAB);
        cTab->unselectAll();
    } else if(pauseMenuBtn->isPressed() && getKeyTime()){
        pauseMenuBtn->setButtonState(BTN_IDLE);
        changeStato(PAUSEMENU_TAB);
        loadSaveTab->setGameScreen(getScreenShoot());
    } else if(spellTabBtn->isPressed() && getKeyTime()){
        spellTabBtn->setButtonState(BTN_IDLE);
        changeStato(SPELL_TAB);
    } else if(achievementTabBtn->isPressed() && getKeyTime()){
        achievementTabBtn->setButtonState(BTN_IDLE);
        changeStato(ACHIEVEMENT_TAB);
    }
}

void GameState::update(const float& dt) {
    updateMousePosition(&view);
    updateKeyTime(dt);
    updateTileMap(dt);
    updateDebugText();
    updateButtons();
    updateGlobalInput(dt);
    if(!paused)
        updateMouseInput(dt);
    updateMousePosition(nullptr);
    achievementComponent->update(dt, mousePosView);
    buffComponent->update(dt, mousePosView);
    if(!paused){ //unpaused update
        updateView(dt);
        updatePlayerInput(dt);
        updateInput(dt);
        player->update(dt);
        interactLootBag.first = 0;
        for(auto i = 0 ; i < lootBags.size() ; i++){
            lootBags[i]->update(dt);
            if(lootBags[i]->isExpired()){
                lootBags.erase(lootBags.begin() + i);
            }else{
                if(lootBags[i]->getHitboxComponent()->getGlobalBounds().intersects(
                        player->getHitboxComponent()->getGlobalBounds())){
                    interactLootBag.first = lootBags[i]->getId();
                    interactLootBag.second = i;
                    lootBags[i]->canInteract(true);
                }else{
                    lootBags[i]->canInteract(false);
                }
            }
        }
        for(auto i : npcs){
            i->update(dt);
            i->updateCollision(player, &npcInteract);
        }

        cTabBtn->update(mousePosView);
        pauseMenuBtn->update(mousePosView);
        spellTabBtn->update(mousePosView);
        achievementTabBtn->update(mousePosView);
        popUpTextComponent->update(dt);

        for(const auto& i : enemies){
            i->update(dt);
            if(!noclip){
                if(i->getHitboxComponent()->intersects(player->getHitboxComponent()->getGlobalBounds())){
                    states->push(std::make_unique<BattleState>(
                            window, player, states, BATTLE_STATE,
                            popUpTextComponent, spellComponent, buffComponent,
                            rsHandler, textures, font, i, achievementComponent->getExpGoldBonus(), currentFloor, cTab));
                    break;
                }
            }
        }

    } else{ // paused update
        switch(stato){
            case PAUSEMENU_TAB:{
                pmenu->update(mousePosView);
                updatePausedMenuButtons();
                break;
            }
            case CHARACTER_TAB:{
                cTab->update(mousePosView);
                if(cTab->closeCharacterTabByClicking(mousePosView, cTabBtn.get()))
                    changeStato(NO_TAB);
                popUpTextComponent->update(dt);
                break;
            }
            case SHOP_TAB:{
                shopTab->update(mousePosView);
                if(shopTab->closeTabByClicking(mousePosView))
                    changeStato(NO_TAB);
                popUpTextComponent->update(dt);
                break;
            }
            case PRIEST_TAB:{
                priestTab->update(mousePosView);
                if(priestTab->closeTabByClicking(mousePosView))
                    changeStato(NO_TAB);
                popUpTextComponent->update(dt);
                break;
            }
            case SPELL_TAB:{
                spellTab->update(mousePosView);
                if(spellTab->closeTabByClicking(mousePosView, spellTabBtn.get()))
                    changeStato(NO_TAB);
                popUpTextComponent->update(dt);
                break;
            }
            case WIZARD_TAB:{
                wizardTab->update(mousePosView);
                if(wizardTab->closeTabByClicking(mousePosView))
                    changeStato(NO_TAB);
                popUpTextComponent->update(dt);
                break;
            }
            case LOOTBAG_TAB:{
                lootBags[interactLootBag.second]->updatePage(mousePosView);
                if(lootBags[interactLootBag.second]->isExpired()){
                    changeStato(NO_TAB);
                }
                popUpTextComponent->update(dt);
                break;
            }
            case SELECTLEVEL_TAB:{
                selectLevelTab->update(mousePosView);
                if(selectLevelTab->closeTabByClicking(mousePosView) || selectLevelTab->isHide()){
                    changeStato(NO_TAB);
                }
                popUpTextComponent->update(dt);
                break;
            }
            case ACHIEVEMENT_TAB:{
                achievementTab->update(mousePosView);
                if(achievementTab->closeTabByClicking(mousePosView, achievementTabBtn.get()))
                    changeStato(NO_TAB);
                popUpTextComponent->update(dt);
                break;
            }
            case LOADSAVE_TAB:
                if(!loadSaveTab->stateMatch(getStateEnum())){
                    loadSaveTab->setState(this);
                }
                loadSaveTab->update(mousePosView);
                if(loadSaveTab->isHide()){
                    changeStato(NO_TAB);
                    loadSaveTab->setHide(true);
                }
                popUpTextComponent->update(dt);
                break;
            case NO_TAB:
                break;
        }
    }
}

void GameState::render(sf::RenderTarget* target) {
    if(!target){
        target = window.get();
    }
    target->setView(view);

    if(currentFloor == 0)
        map->renderF(target);
    else
        map->render(target, player, &coreShader, player->getCenter());
    player->render(*target, &coreShader, player->getCenter(), true, true);

    for(const auto& i : enemies){
        if(i->canBeRendered(enemyRenderDistance, player->getPosition()))
            i->render(*target, &coreShader, player->getCenter(), false, true);
    }

    for(auto i : npcs){
        i->render(*target, false);
        if(player->getHitboxComponent()->getGlobalBounds().intersects(i->getHitboxComponent()->getGlobalBounds())){
            if(player->getCollisionBoxComponent()->getPosition().y > i->getCollisionBoxComponent()->getPosition().y){
                player->render(*target, &coreShader, player->getCenter(), false, true);
            }
        }
    }
    for(const auto& i : lootBags){
        i->render(*target, &coreShader, player->getCenter(), false);
        if(player->getHitboxComponent()->getGlobalBounds().intersects(i->getHitboxComponent()->getGlobalBounds())){
            if(player->getCollisionBoxComponent()->getPosition().y > i->getCollisionBoxComponent()->getPosition().y){
                player->render(*target, &coreShader, player->getCenter(), false, true);
            }
        }
    }

    target->setView(target->getDefaultView());
    cTabBtn->render(*target);
    pauseMenuBtn->render(*target);
    spellTabBtn->render(*target);
    achievementTabBtn->render(*target);
    target->draw(hints);
    target->draw(locationLbl);
    if(paused){ // pause menu render
        switch(stato){
            case PAUSEMENU_TAB:
                pmenu->render(*target);
                break;
            case CHARACTER_TAB:
                cTab->render(*target);
                break;
            case SHOP_TAB:
                shopTab->render(*target);
                break;
            case PRIEST_TAB:
                priestTab->render(*target);
                break;
            case SPELL_TAB:
                spellTab->render(*target);
                break;
            case WIZARD_TAB:
                wizardTab->render(*target);
                break;
            case LOOTBAG_TAB:
                lootBags[interactLootBag.second]->renderPage(*target);
                break;
            case SELECTLEVEL_TAB:
                selectLevelTab->render(*target);
                break;
            case ACHIEVEMENT_TAB:
                achievementTab->render(*target);
                break;
            case LOADSAVE_TAB:
                loadSaveTab->render(*target);
                break;
            case NO_TAB:
                break;
        }
    }
    target->draw(debugText);
    achievementComponent->render(*target);
    buffComponent->render(*target);
    popUpTextComponent->render(*target);
}

void GameState::updateTileMap(const float &dt) {
    map->updateCollision(player);
    if(!noclip)
        map->updateTileCollision(player, dt);
}

void GameState::loadEnemyFromSave() {
    Save* save = loadSaveTab->getApplySave();
    std::shared_ptr<Enemy> e;
    for(const auto& i : save->enemiesLeaders){
        e = enemyFactory(i.getPosX(), i.getPosY(), i.getType(), false);
        e->setId(i.getId());
        e->setStats(i.getStats());
        e->setCurrentBoost(i.getCurrentBoost());
        enemies.push_back(e);
    }
    for(const auto& i : save->enemiesFollowers){
        for(const auto& k : enemies){
            if(k->getId() == i.getLeaderId() && i.isFollower1()){
                k->addFollower(std::make_shared<Enemy>(i.getType(), i.getName(), i.getId(), i.getStats()));
                break;
            }
        }
    }
}

void GameState::changeMap(int floor, bool load_from_save) {
    currentFloor = floor;
    if(currentFloor > floorReached){
        floorReached = currentFloor;
        notify(AE_FLOOR_REACHED, floorReached);
    }
    selectLevelTab->updateButtonsAccess(floorReached);
    updateLocationLbl();
    map = mg->GenerateFromFile(floor, this);
    pathFinder->generateNodes(map);
    player->clearWayPoints();
    if(!lootBags.empty())
        lootBags.clear();
    if(floor != 0) {
        if (!npcs.empty())
            npcs.clear();
        spawnPos.x = map->findStairs().x + 30;
        spawnPos.y = map->findStairs().y + Tile::TILE_SIZE;
        player->setPosition(spawnPos.x, spawnPos.y);
        if(load_from_save){
            loadEnemyFromSave();
        }else{
            spawnEnemyOnMap();
        }
    }
    else {
        spawnPos = sf::Vector2f(830, 620);
        player->setPosition(spawnPos.x, spawnPos.y);
        if (!enemies.empty())
            enemies.clear();

        spawnNpc(830.f, 870.f, WIZARD);
        spawnNpc(1360.f, 570.f, SHOP);
        spawnNpc(310.f, 570.f, PRIEST);
    }
}

void GameState::spawnEnemyOnMap() {
    int randEnemy;
    sf::Vector2f dStairs = map->findStairs();
    if(!enemies.empty())
        enemies.clear();
    std::vector<sf::Vector2f> f = map->getFloorsPos();
    for(int i = 0; i < f.size(); i++){
        if((utils::absoluteValue(f[i].y - dStairs.y) < (5 * Tile::TILE_SIZE) &&
            (utils::absoluteValue(f[i].x - dStairs.x) < (5 * Tile::TILE_SIZE)))){
            f.erase(f.begin() + i);
            i--;
        }
    }

    std::shuffle(&f.at(0),&f.at(f.size() - 1), utils::generator);
    for(int i = 0; i < 1; i++){
        randEnemy = utils::generateRandomNumber(0, 6);
        switch(randEnemy) {
            case 0:{
                spawnEnemy(f.at(i).x + 30, f.at(i).y + 30, GOBLIN, 5);
                break;
            }
            case 1:{
                spawnEnemy(f.at(i).x + 30,f.at(i).y + 30, BANDIT_LIGHT, 5);
                break;
            }
            case 2:{
                spawnEnemy(f.at(i).x + 30, f.at(i).y + 30, SKELETON, 5);
                break;
            }
            case 3:{
                spawnEnemy(f.at(i).x + 30, f.at(i).y + 30, SKELETON_2, 5);
                break;
            }
            case 4:{
                spawnEnemy(f.at(i).x + 30, f.at(i).y + 30, FLYING_EYE, 5);
                break;
            }
            case 5:{
                spawnEnemy(f.at(i).x + 30, f.at(i).y + 30, BANDIT_HEAVY, 5);
                break;
            }
            case 6:{
                spawnEnemy(f.at(i).x + 30, f.at(i).y + 30, WITCH, 5);
                break;
            }
            default:
                break;
        }
    }
}

PathFinder* GameState::getPathFinder() const {
    return pathFinder.get();
}


































































