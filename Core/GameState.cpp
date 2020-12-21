//
// Created by Zheng on 07/10/2020.
//

#include "GameState.h"

#include <random>

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
}

void GameState::initPauseMenu() {
    pmenu = PauseMenu(window, font);

    pmenu.addButton("SPELL", 300.f, "Spells", 30);
    pmenu.addButton("CHARACTER", 380.f, "Character", 30);
    pmenu.addButton("ACHIEVEMENT", 460.f, "Achievement", 30);
    pmenu.addButton("BACK", 540.f, "Resume", 30);
    pmenu.addButton("QUIT", 620.f, "QUIT", 50);
}

void GameState::initPlayers() {
    player = std::make_shared<Player>(spawnPos.x, spawnPos.y, 2.f, 2.f,
                              textures["PLAYER_SHEET"]);
    player->setGold(0);
    player->getInventory()->setCurrentMaxSpace(35);

    // legge i valori di default del Stats dal Data/Stats.txt
    rsHandler->loadPlayerStatsTxt(player->getPlayerStats());
    player->getPlayerStats()->updateMultipliers();

    // legge i valori di default dell 'inventario dal Data/Inventory.txt
    rsHandler->loadPlayerInventoryTxt(player->getInventory());

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

void GameState::initBuffComponent() {
    buffComponent = std::make_shared<BuffComponent>(popUpTextComponent, player, this, font);
    // add all buffs to map
    buffComponent->addBuff("HealthPotion(S)",
            std::make_shared<Buff>("HealthPotion(S)", "Recovers your hp by 100", "HealthPotion",
                    100, 0, 0, 0, 0.f, 0.f, true,
                    false,7, 22));

    buffComponent->addBuff("HealthPotion(M)",
            std::make_shared<Buff>("HealthPotion(M)", "Recovers your hp by 200", "HealthPotion",
                    200, 0, 0, 0, 0.f, 0.f, true,
                    false, 7, 22));

    buffComponent->addBuff("HealthPotion(L)",
            std::make_shared<Buff>("HealthPotion(L)", "Recovers your hp by 400", "HealthPotion",
                    400, 0, 0, 0, 0.f, 0.f, true,
                    false, 7, 22));

    buffComponent->addBuff("ManaPotion(S)",
            std::make_shared<Buff>("ManaPotion(S)", "Recovers your mp by 100", "ManaPotion",
                    0, 100, 0, 0, 0.f, 0.f, true,
                    false, 9, 22));

    buffComponent->addBuff("ManaPotion(M)",
            std::make_shared<Buff>("ManaPotion(M)", "Recovers your mp by 200", "ManaPotion",
                    0, 200, 0, 0, 0.f, 0.f, true,
                    false, 9, 22));

    buffComponent->addBuff("ManaPotion(L)",
            std::make_shared<Buff>("ManaPotion(L)", "Recovers your mp by 400", "ManaPotion",
                    0, 400, 0, 0, 0.f, 0.f, true,
                    false, 9, 22));

    buffComponent->addBuff("DamagePotion(S)",
            std::make_shared<Buff>("DamagePotion(S)", "Boosts your attack by 100 for 3 turns", "DamagePotion",
                    0, 0, 100, 0, 0.f, 0.f, 3,
                    false, 6 ,26));

    buffComponent->addBuff("DamagePotion(M)",
            std::make_shared<Buff>("DamagePotion(M)", "Boosts your attack by 300 for 3 turns", "DamagePotion",
                    0, 0, 300, 0, 0.f, 0.f, 3,
                    false, 6 ,26));

    buffComponent->addBuff("DamagePotion(L)",
            std::make_shared<Buff>("DamagePotion(L)", "Boosts your attack by 600 for 3 turns", "DamagePotion",
                    0, 0, 600, 0, 0.f, 0.f, 3,
                    false, 6 ,26));

    buffComponent->addBuff("DefensePotion(S)",
            std::make_shared<Buff>("DefensePotion(S)", "Boosts your armor by 100 for 3 turns", "DefensePotion",
                    0, 0, 0, 100, 0.f, 0.f, 3,
                    false, 4, 26));

    buffComponent->addBuff("DefensePotion(M)",
            std::make_shared<Buff>("DefensePotion(M)", "Boosts your armor by 300 for 3 turns", "DefensePotion",
                    0, 0, 0, 300, 0.f, 0.f, 3,
                    false, 4, 26));

    buffComponent->addBuff("DefensePotion(L)",
            std::make_shared<Buff>("DefensePotion(L)", "Boosts your armor by 600 for 3 turns", "DefensePotion",
                    0, 0, 0, 600, 0.f, 0.f, 3,
                    false, 4, 26));

    buffComponent->addBuff("CriticalHitChancePotion(S)",
            std::make_shared<Buff>("CriticalHitChancePotion(S)", "Boosts your critical hit chance by 10% for 3 turns",
                    "CriticalHitChancePotion", 0, 0, 0, 0, 10.f, 0.f,
                    3, false, 1, 26));

    buffComponent->addBuff("CriticalHitChancePotion(M)",
            std::make_shared<Buff>("CriticalHitChancePotion(M)", "Boosts your critical hit chance by 15% for 3 turns",
                    "CriticalHitChancePotion", 0, 0, 0, 0, 15.f, 0.f,
                    3, false, 1, 26));

    buffComponent->addBuff("CriticalHitChancePotion(L)",
            std::make_shared<Buff>("CriticalHitChancePotion(L)", "Boosts your critical hit chance by 25% for 3 turns",
                    "CriticalHitChancePotion", 0, 0, 0, 0, 25.f, 0.f,
                    3, false, 1, 26));

    buffComponent->addBuff("EvadeChancePotion(S)",
            std::make_shared<Buff>("EvadeChancePotion(S)", "Boosts your evade chance by 10% for 3 turns",
                    "EvadeChancePotion", 0, 0, 0, 0, 0.f, 10.f,3,
                    false, 3, 26));

    buffComponent->addBuff("EvadeChancePotion(M)",
            std::make_shared<Buff>("EvadeChancePotion(M)", "Boosts your evade chance by 15% for 3 turns",
                    "EvadeChancePotion", 0, 0, 0, 0, 0.f, 15.f,3,
                    false, 3, 26));

    buffComponent->addBuff("EvadeChancePotion(L)",
            std::make_shared<Buff>("EvadeChancePotion(L)", "Boosts your evade chance by 25% for 3 turns",
                    "EvadeChancePotion", 0, 0, 0, 0, 0.f, 25.f,3,
                    false, 3, 26));
}

void GameState::initSpellComponent() {
    spellComponent = std::make_shared<SpellComponent>();
    rsHandler->loadSpellList(spellComponent);
}

void GameState::initComponents() {
    popUpTextComponent = std::make_shared<PopUpTextComponent>(*font, window);
    achievementComponent = std::make_shared<AchievementComponent>(font);
    rsHandler->loadAchievementsTxt(achievementComponent->getAchievements());

    initBuffComponent();
    initSpellComponent();

    addObserver(achievementComponent.get());
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
    debugText.setString("sss");
    debugText.setPosition(5.f, 40.f);
}

void GameState::initButtons() {
    pauseMenuBtn = gui::Button(
            window->getSize().x - 100.f,
            window->getSize().y - 90.f, 70.f, 70.f,
            font, "", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color::Transparent,
            sf::Color(70, 70, 70, 60),
            sf::Color(130, 130, 130, 0));
    pauseMenuBtn.setBackgroundTexture(&textures["PAUSEMENU_ICON"]);
    pauseMenuBtn.setBackbgroundDisabled(false);

    achievementTabBtn = gui::Button(
            pauseMenuBtn.getPosition().x - 100.f,
            pauseMenuBtn.getPosition().y, 70.f, 70.f,
            font, "", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color::Transparent,
            sf::Color(70, 70, 70, 60),
            sf::Color(130, 130, 130, 0));
    achievementTabBtn.setBackgroundTexture(&textures["ACHIEVEMENT_ICON"]);
    achievementTabBtn.setBackbgroundDisabled(false);

    spellTabBtn = gui::Button(
            achievementTabBtn.getPosition().x - 100.f,
            achievementTabBtn.getPosition().y, 70.f, 70.f,
            font, "", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color::Transparent,
            sf::Color(70, 70, 70, 60),
            sf::Color(130, 130, 130, 0));
    spellTabBtn.setBackgroundTexture(&textures["SPELL_ICON"]);
    spellTabBtn.setBackbgroundDisabled(false);

    cTabBtn = gui::Button(
            spellTabBtn.getPosition().x - 100.f,
            spellTabBtn.getPosition().y, 70.f, 70.f,
            font, "", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color::Transparent,
            sf::Color(70, 70, 70, 60),
            sf::Color(130, 130, 130, 0));
    cTabBtn.setBackgroundTexture(&textures["INVENTORY_ICON"]);
    cTabBtn.setBackbgroundDisabled(false);

}

void GameState::initMaps() {
    mg = new MapGenerator();
    mg->generateDungeon(1);
    mg->generateDungeon(2);
    mg->generateDungeon(3);
    mg->generateDungeon(4);
    mg->generateDungeon(5);
    changeMap(0);
}

void GameState::initShader() {
    if(!coreShader.loadFromFile("../Shader/vertex_shader.vert", "../Shader/fragment_shader.frag")){
        std::cout<<"Error shader";
    }
}

//constructors/destructors
GameState::GameState(std::shared_ptr<sf::RenderWindow> window, std::stack<std::unique_ptr<State>>* states,
                     std::shared_ptr<ResourcesHandler> rsHandler, sf::Font *font)
        : State(std::move(window), states, std::move(rsHandler)){
    this->font = font;
    stato = NO_TAB;
    npcInteract = NO_NPC;
    noclip = false;
    spawnPos = {1730.f, 770.f};
    floorReached = 0;

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
}

GameState::~GameState() {
    delete map;
    delete mg;
    for(auto i : npcs)
        delete i;
}

//accessors
std::shared_ptr<BuffComponent> GameState::getBuffComponent() {
    return buffComponent;
}

std::shared_ptr<PopUpTextComponent> GameState::getPopUpTextComponent() {
    return popUpTextComponent;
}

std::shared_ptr<SpellComponent> GameState::getSpellComponent() {
    return spellComponent;
}

std::shared_ptr<SpellTab> GameState::getSpellTab() {
    return spellTab;
}

std::shared_ptr<LootGenerator> GameState::getLootGenerator() {
    return lootGenerator;
}

bool GameState::getStateKeyTime() {
    return getKeyTime();
}

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

void GameState::spawnEnemy(float x, float y, enemy_types type, unsigned int enemy_followers) {
    std::shared_ptr<Enemy> new_enemy;
    bool new_enemy_spawned = false;
    switch(type){
        case WITCH:
            new_enemy = std::make_shared<Enemy>(WITCH, x, y, 1.2f, 1.2f,
                                                127.f, 136.f, 50.f, 65.f,
                                                150.f, 200.f, 9.f,
                                                textures["ENEMY_WIZARD_SHEET"], currentFloor, rsHandler->generateId());
            enemies.push_back(new_enemy);
            new_enemy_spawned = true;
            break;
        case SKELETON:
            new_enemy = std::make_shared<Enemy>(SKELETON, x, y, 2.f, 2.3f,
                                       85.f, 100.f, 40.f, 60.f,
                                       105.f, 159.f, 8.f,
                                       textures["ENEMY_SKELETON_SHEET"], currentFloor, rsHandler->generateId());
            enemies.push_back(new_enemy);
            new_enemy_spawned = true;
            break;
        case SKELETON_2:
            new_enemy = std::make_shared<Enemy>(SKELETON_2, x, y, 1.2f, 1.2f,
                                       70.f, 60.f, 50.f, 63.f,
                                       95.f, 122.f, 10.f,
                                       textures["ENEMY_SKELETON_2_SHEET"], currentFloor, rsHandler->generateId());
            enemies.push_back(new_enemy);
            new_enemy_spawned = true;
            break;
        case FLYING_EYE:
            new_enemy = std::make_shared<Enemy>(FLYING_EYE, x, y, 1.3f, 1.3f,
                                       72.f, 85.f, 58.f, 60.f,
                                       100.f, 142.f, 11.f,
                                       textures["ENEMY_FLYINGEYE_SHEET"], currentFloor, rsHandler->generateId());
            enemies.push_back(new_enemy);
            new_enemy_spawned = true;
            break;
        case GOBLIN:
            new_enemy = std::make_shared<Enemy>(GOBLIN, x, y, 1.2f, 1.4f,
                                       70.f, 94.f, 40.f, 48.f,
                                       90.f, 142.f, 8.f,
                                       textures["ENEMY_GOBLIN_SHEET"], currentFloor, rsHandler->generateId());
            enemies.push_back(new_enemy);
            new_enemy_spawned = true;
            break;
        case MUSHROOM:
            new_enemy = std::make_shared<Enemy>(MUSHROOM, x, y, 1.4f, 1.4f,
                                       87.f, 87.f, 38.f, 57.f,
                                       106.f, 143.f, 8.f,
                                       textures["ENEMY_MUSHROOM_SHEET"], currentFloor, rsHandler->generateId());
            enemies.push_back(new_enemy);
            new_enemy_spawned = true;
            break;
        case BANDIT_HEAVY:
            new_enemy = std::make_shared<Enemy>(BANDIT_HEAVY, x, y, 1.8f, 1.8f,
                                       25.f, 15.f, 45.f, 68.f,
                                       47.f, 83.f, 9.f,
                                       textures["ENEMY_BANDITHEAVY_SHEET"], currentFloor, rsHandler->generateId());
            enemies.push_back(new_enemy);
            new_enemy_spawned = true;
            break;
        case BANDIT_LIGHT:
            new_enemy = std::make_shared<Enemy>(BANDIT_LIGHT, x, y, 1.8f, 1.8f,
                                       25.f, 15.f, 45.f, 68.f,
                                       47.f, 83.f, 9.f,
                                       textures["ENEMY_BANDITLIGHT_SHEET"], currentFloor, rsHandler->generateId());
            enemies.push_back(new_enemy);
            new_enemy_spawned = true;
            break;
        default:
            std::cout<<"No such enemy: " << type;
            break;
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

void GameState::checkBattleResult(BattleResult& battle_result) {
    std::cout<<battle_result.generateReport();
    switch(battle_result.getResultType()){
        case WIN:{
            int exp_gain = battle_result.getExpGainCount();
            int gold_gain = battle_result.getGoldGainCount();

            if(exp_gain > 0){
                if(player->getPlayerStats()->addExp(exp_gain)){
                    updateTabsPlayerStatsLbl();
                }
                popUpTextComponent->addPopUpTextCenter(EXPERIENCE_TAG, exp_gain,"+", "Exp");
            }

            if(gold_gain > 0){
                player->addGold(gold_gain);
                updateTabsGoldLbl();
                popUpTextComponent->addPopUpTextCenterYShifted(GOLD_TAG, gold_gain, "+", " gold", -50.f);
            }

            for(const auto& i : enemies){
                if(i->getId() == battle_result.getEnemyLeaderId()){
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
            if(deleteEnemyById(battle_result.getEnemyLeaderId()))
                std::cout<<"Enemy " << battle_result.getEnemyLeaderId() << " deleted" << endl;
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
    if(battle_result.getResultType() != QUIT_GAME){
        //notifica achivements data
        for(auto i : battle_result.getAchievementDataSet()){
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
        if(player->getPlayerStats()->addExp(100)){
            updateTabsPlayerStatsLbl();
        }
        popUpTextComponent->addPopUpTextCenter(EXPERIENCE_TAG, 100, "+", "Exp");
        notify(AE_P_EXP, 100);


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
            }
        }
    }
}

void GameState::updatePlayerInput(const float &dt) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        player->move(dt, -1.f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player->move(dt, 1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        player->move(dt, 0.f, -1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        player->move(dt, 0.f, 1.f);
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

void GameState::updateTabsPlayerStatsLbl() {
    cTab->updatePlayerStatsLbl();
    spellTab->updateSpellsInfoLbl();
}

void GameState::updatePausedMenuButtons() {
    if(pmenu.isButtonPressed("QUIT") && getKeyTime()){
        endState();
    } else if(pmenu.isButtonPressed("BACK") && getKeyTime()){
        changeStato(NO_TAB);
    } else if(pmenu.isButtonPressed("SPELL") && getKeyTime()){
        changeStato(NO_TAB);
        changeStato(SPELL_TAB);
    } else if(pmenu.isButtonPressed("CHARACTER") && getKeyTime()){
        changeStato(NO_TAB);
        changeStato(CHARACTER_TAB);
    } else if(pmenu.isButtonPressed("ACHIEVEMENT") && getKeyTime()){
        changeStato(NO_TAB);
        changeStato(ACHIEVEMENT_TAB);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && getKeyTime()){
        changeStato(NO_TAB);
    }
}

void GameState::updateView(const float &dt) {
    view.setCenter(player->getHitboxComponent()->getCenter());
}

void GameState::updateDebugText() {
//debbuging tool: show mouse pos coords
    std::stringstream ss;
    ss << "Mouse pos: " << mousePosView.x << " " << mousePosView.y;
    debugText.setString(ss.str());
}

void GameState::updateButtons() {
    if(cTabBtn.isPressed() && getKeyTime()){
        cTabBtn.setButtonState(BTN_IDLE);
        changeStato(CHARACTER_TAB);
        cTab->unselectAll();
    } else if(pauseMenuBtn.isPressed() && getKeyTime()){
        pauseMenuBtn.setButtonState(BTN_IDLE);
        changeStato(PAUSEMENU_TAB);
    } else if(spellTabBtn.isPressed() && getKeyTime()){
        spellTabBtn.setButtonState(BTN_IDLE);
        changeStato(SPELL_TAB);
    } else if(achievementTabBtn.isPressed() && getKeyTime()){
        achievementTabBtn.setButtonState(BTN_IDLE);
        changeStato(ACHIEVEMENT_TAB);
    }
}

void GameState::update(const float& dt) {
    updateMousePosition(&view);
    updateKeyTime(dt);
    updateTileMap(dt);
    updateDebugText();
    updateButtons();

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
        updateMousePosition(nullptr);
        cTabBtn.update(mousePosView);
        pauseMenuBtn.update(mousePosView);
        spellTabBtn.update(mousePosView);
        achievementTabBtn.update(mousePosView);
        popUpTextComponent->update(dt);
        buffComponent->update(dt, mousePosView);
        achievementComponent->update(dt, mousePosView);
        for(const auto& i : enemies){
            i->update(dt);
            if(!noclip){
                if(i->getHitboxComponent()->intersects(player->getHitboxComponent()->getGlobalBounds())){
                    states->push(std::make_unique<BattleState>(
                            window, player, states,
                            popUpTextComponent, spellComponent, buffComponent,
                            rsHandler, textures, font, i, achievementComponent->getExpGoldBonus(), currentFloor, cTab));
                    break;
                }
            }

        }
    } else{ // paused update
        updateMousePosition(nullptr);
        switch(stato){
            case PAUSEMENU_TAB:
                pmenu.update(mousePosView);
                updatePausedMenuButtons();
                break;
            case CHARACTER_TAB:
                cTab->update(mousePosView);
                if(cTab->closeCharacterTabByClicking(mousePosView, &cTabBtn))
                    changeStato(NO_TAB);
                popUpTextComponent->update(dt);
                break;
            case SHOP_TAB:
                shopTab->update(mousePosView);
                if(shopTab->closeTabByClicking(mousePosView))
                    changeStato(NO_TAB);
                popUpTextComponent->update(dt);
                break;
            case PRIEST_TAB:
                priestTab->update(mousePosView);
                if(priestTab->closeTabByClicking(mousePosView))
                    changeStato(NO_TAB);
                popUpTextComponent->update(dt);
                break;
            case SPELL_TAB:
                spellTab->update(mousePosView);
                if(spellTab->closeTabByClicking(mousePosView, &spellTabBtn))
                    changeStato(NO_TAB);
                popUpTextComponent->update(dt);
                break;
            case WIZARD_TAB:
                wizardTab->update(mousePosView);
                if(wizardTab->closeTabByClicking(mousePosView))
                    changeStato(NO_TAB);
                popUpTextComponent->update(dt);
                break;
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
            case ACHIEVEMENT_TAB:
                achievementTab->update(mousePosView);
                if(achievementTab->closeTabByClicking(mousePosView, &achievementTabBtn))
                    changeStato(NO_TAB);
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
        map->render(target, player, nullptr, player->getCenter());
    else
        map->render(target, player, &coreShader, player->getCenter());
    player->render(*target, &coreShader, player->getCenter(), true, true);
    for(const auto& i : enemies){
        i->render(*target, &coreShader, player->getCenter(), true, true);
    }
    for(auto i : npcs){
        i->render(*target, true);
        if(player->getCollisionBoxComponent()->getPosition().y > i->getCollisionBoxComponent()->getPosition().y){
            player->render(*target, &coreShader, player->getCenter(), true, true);
        }
    }
    for(const auto& i : lootBags){
        i->render(*target, &coreShader, player->getCenter(), true);
        if(player->getCollisionBoxComponent()->getPosition().y > i->getCollisionBoxComponent()->getPosition().y){
            player->render(*target, &coreShader, player->getCenter(), true, true);
        }
    }

    target->setView(target->getDefaultView());
    cTabBtn.render(*target);
    pauseMenuBtn.render(*target);
    spellTabBtn.render(*target);
    achievementTabBtn.render(*target);
    target->draw(hints);
    target->draw(locationLbl);
    buffComponent->render(*target);
    popUpTextComponent->render(*target);
    achievementComponent->render(*target);

    if(paused){ // pause menu render
        switch(stato){
            case PAUSEMENU_TAB:
                pmenu.render(*target);
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
            case NO_TAB:
                break;
        }
    }
    target->draw(debugText);
}

void GameState::updateTileMap(const float &dt) {
    map->updateCollision(player);
    if(!noclip)
        map->updateTileCollision(player, dt);
}

void GameState::changeMap(int floor) {
    currentFloor = floor;
    if(currentFloor > floorReached){
        floorReached = currentFloor;
        notify(AE_FLOOR_REACHED, floorReached);
    }
    selectLevelTab->updateButtonsAccess(floorReached);
    updateLocationLbl();
    map = mg->GenerateFromFile(floor, this);
    if(!lootBags.empty())
        lootBags.clear();
    if(floor != 0) {
        if (!npcs.empty())
            npcs.clear();
        spawnPos.x = map->findStairs().x + 30;
        spawnPos.y = map->findStairs().y + Tile::TILE_SIZE;
        player->setPosition(spawnPos.x, spawnPos.y);
        spawnEnemyOnMap();
    }
    else {
        spawnPos = sf::Vector2f(1430, 620);
        player->setPosition(spawnPos.x, spawnPos.y);
        if (!enemies.empty())
            enemies.clear();
        npcs.push_back(new Npc(WIZARD, 1430.f, 870.f, 0.7f, 0.7f,
                               textures["WIZARD_NPC_SHEET"], textures["CHATTABLE_ICON"]));
        npcs.push_back(new Npc(SHOP, 1960.f, 570.f, 1.5f, 1.5f,
                               textures["SHOP_NPC_SHEET"], textures["CHATTABLE_ICON"]));
        npcs.push_back(new Npc(PRIEST, 910.f, 570.f, 1.5f, 1.5f,
                               textures["PRIEST_NPC_SHEET"], textures["CHATTABLE_ICON"]));
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

    std::shuffle(&f.at(0),&f.at(f.size() - 1), std::mt19937(std::random_device()()));
    for(int i = 0; i < 30; i++){
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





























































