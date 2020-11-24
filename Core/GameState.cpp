//
// Created by Zheng on 07/10/2020.
//

#include "GameState.h"

#include <utility>

void GameState::initTextures() {

    rsHandler->addResouce("../Resources/Images/Sprites/Player/player_sheet.png", "player_sheet", "GameState");
    rsHandler->addResouce("../Resources/Images/Sprites/Npc/shop_npc_idle.png", "shop_npc_sheet", "GameState");
    rsHandler->addResouce("../Resources/Images/Sprites/Npc/priest_npc_idle.png", "priest_npc_sheet", "GameState");
    rsHandler->addResouce("../Resources/Images/Sprites/Npc/wizard_npc_idle.png", "wizard_npc_sheet", "GameState");

    rsHandler->addResouce("../Resources/Images/Sprites/Enemy/wizard_Idle.png", "wizard_enemy_sheet", "GameState");
    rsHandler->addResouce("../Resources/Images/Sprites/Enemy/Flying eye/Flight.png", "FlyingEye_enemy_sheet", "GameState");
    rsHandler->addResouce("../Resources/Images/Sprites/Enemy/Goblin/Idle.png", "Goblin_enemy_sheet", "GameState");
    rsHandler->addResouce("../Resources/Images/Sprites/Enemy/Mushroom/Idle.png", "Mushroom_enemy_sheet", "GameState");
    rsHandler->addResouce("../Resources/Images/Sprites/Enemy/Skeleton/Skeleton Idle.png", "Skeleton_enemy_sheet", "GameState");
    rsHandler->addResouce("../Resources/Images/Sprites/Enemy/Skeleton2/Idle.png", "Skeleton_2_enemy_sheet", "GameState");
    rsHandler->addResouce("../Resources/Images/Sprites/Enemy/HeavyBandit/HeavyBandit.png", "BanditHeavy_enemy_sheet", "GameState");
    rsHandler->addResouce("../Resources/Images/Sprites/Enemy/LightBandit/LightBandit.png", "BanditLight_enemy_sheet", "GameState");

    rsHandler->addResouce("../Resources/Images/chat.png", "chattable_icon", "GameState");

    rsHandler->addResouce("../Resources/Images/characterIcon.png", "characterIcon", "GameState");
    rsHandler->addResouce("../Resources/Images/inventoryIcon.png", "inventoryIcon", "GameState");
    rsHandler->addResouce("../Resources/Images/pauseMenuIcon.png", "pauseMenuIcon", "GameState");
    rsHandler->addResouce("../Resources/Images/spellIcon.png", "spellIcon", "GameState");

    rsHandler->addResouce("../Resources/Images/equipslot_sheet.png", "EquipSlotsSheet", "GameState");
    rsHandler->addResouce("../Resources/Images/items_sheet.png", "items_sheet", "GameState");
    rsHandler->addResouce("../Resources/Images/selectedIcon.png", "selected", "GameState");
    rsHandler->addResouce("../Resources/Images/new.png", "newTag", "GameState");
    rsHandler->addResouce("../Resources/Images/weaponIcon.png", "weaponIcon", "GameState");
    rsHandler->addResouce("../Resources/Images/shieldIcon.png", "shieldIcon", "GameState");
    rsHandler->addResouce("../Resources/Images/helmetIcon.png", "helmetIcon", "GameState");
    rsHandler->addResouce("../Resources/Images/armorIcon.png", "armorIcon", "GameState");
    rsHandler->addResouce("../Resources/Images/glovesIcon.png", "glovesIcon", "GameState");
    rsHandler->addResouce("../Resources/Images/bootsIcon.png", "bootsIcon", "GameState");
    rsHandler->addResouce("../Resources/Images/randomIcon.png", "randomIcon", "GameState");
    rsHandler->addResouce("../Resources/Images/arrow_down.png", "arrowDownIcon", "GameState");

    textures["PLAYER_SHEET"].loadFromImage(rsHandler->getResouceByKey("player_sheet")->getImage());
    textures["SHOP_NPC_SHEET"].loadFromImage(rsHandler->getResouceByKey("shop_npc_sheet")->getImage());
    textures["PRIEST_NPC_SHEET"].loadFromImage(rsHandler->getResouceByKey("priest_npc_sheet")->getImage());
    textures["WIZARD_NPC_SHEET"].loadFromImage(rsHandler->getResouceByKey("wizard_npc_sheet")->getImage());

    textures["ENEMY_WIZARD_SHEET"].loadFromImage(rsHandler->getResouceByKey("wizard_enemy_sheet")->getImage());
    textures["ENEMY_FLYINGEYE_SHEET"].loadFromImage(rsHandler->getResouceByKey("FlyingEye_enemy_sheet")->getImage());
    textures["ENEMY_GOBLIN_SHEET"].loadFromImage(rsHandler->getResouceByKey("Goblin_enemy_sheet")->getImage());
    textures["ENEMY_MUSHROOM_SHEET"].loadFromImage(rsHandler->getResouceByKey("Mushroom_enemy_sheet")->getImage());
    textures["ENEMY_SKELETON_SHEET"].loadFromImage(rsHandler->getResouceByKey("Skeleton_enemy_sheet")->getImage());
    textures["ENEMY_SKELETON_2_SHEET"].loadFromImage(rsHandler->getResouceByKey("Skeleton_2_enemy_sheet")->getImage());
    textures["ENEMY_BANDITHEAVY_SHEET"].loadFromImage(rsHandler->getResouceByKey("BanditHeavy_enemy_sheet")->getImage());
    textures["ENEMY_BANDITLIGHT_SHEET"].loadFromImage(rsHandler->getResouceByKey("BanditLight_enemy_sheet")->getImage());

    textures["CHATTABLE_ICON"].loadFromImage(rsHandler->getResouceByKey("chattable_icon")->getImage());

    textures["CHARACTER_ICON"].loadFromImage(rsHandler->getResouceByKey("characterIcon")->getImage());
    textures["INVENTORY_ICON"].loadFromImage(rsHandler->getResouceByKey("inventoryIcon")->getImage());
    textures["PAUSEMENU_ICON"].loadFromImage(rsHandler->getResouceByKey("pauseMenuIcon")->getImage());
    textures["SPELL_ICON"].loadFromImage(rsHandler->getResouceByKey("spellIcon")->getImage());

    textures["ITEMS_SHEET"].loadFromImage(rsHandler->getResouceByKey("items_sheet")->getImage());
    textures["EquipSlotsSheet"].loadFromImage(rsHandler->getResouceByKey("EquipSlotsSheet")->getImage());
    textures["SELECTED_ICON"].loadFromImage(rsHandler->getResouceByKey("selected")->getImage());
    textures["NEW_TAG"].loadFromImage(rsHandler->getResouceByKey("newTag")->getImage());
    textures["WEAPON_ICON"].loadFromImage(rsHandler->getResouceByKey("weaponIcon")->getImage());
    textures["SHIELD_ICON"].loadFromImage(rsHandler->getResouceByKey("shieldIcon")->getImage());
    textures["HELMET_ICON"].loadFromImage(rsHandler->getResouceByKey("helmetIcon")->getImage());
    textures["ARMOR_ICON"].loadFromImage(rsHandler->getResouceByKey("armorIcon")->getImage());
    textures["GLOVES_ICON"].loadFromImage(rsHandler->getResouceByKey("glovesIcon")->getImage());
    textures["BOOTS_ICON"].loadFromImage(rsHandler->getResouceByKey("bootsIcon")->getImage());
    textures["RANDOM_ICON"].loadFromImage(rsHandler->getResouceByKey("randomIcon")->getImage());
    textures["ARROWDOWN_ICON"].loadFromImage(rsHandler->getResouceByKey("arrowDownIcon")->getImage());
}

void GameState::initPauseMenu() {
    pmenu = PauseMenu(window, font);

    pmenu.addButton("SPELL", 300.f, "Spells", 30);
    pmenu.addButton("CHARACTER", 380.f, "Character", 30);
    pmenu.addButton("BACK", 460.f, "Resume", 30);
    pmenu.addButton("QUIT", 540.f, "QUIT", 50);
}

void GameState::initPlayers() {
    player = std::make_shared<Player>(750.f, 130.f, 2.f, 2.f,
                              textures["PLAYER_SHEET"]);
    player->setGold(0);
    player->getInventory()->setCurrentMaxSpace(35);

    // legge i valori di default del Stats dal Data/Stats.txt
    rsHandler->loadPlayerStatsTxt(player->getPlayerStats());
    player->getPlayerStats()->updateMultipliers();

    // legge i valori di default dell 'inventario dal Data/Inventory.txt
    rsHandler->loadPlayerInventoryTxt(player->getInventory());

    spawnEnemy(1232.f, 386.f,GOBLIN);
    spawnEnemy(1349.f, 393.f,MUSHROOM);
    spawnEnemy(1280.f, 159.f,BANDIT_LIGHT);
    spawnEnemy(1360.f, 159.f,SKELETON);
    spawnEnemy(1104.f, 159.f,SKELETON_2);
    spawnEnemy(1190.f, 159.f,FLYING_EYE);
    spawnEnemy(1356.f, 271.f,BANDIT_HEAVY);
    spawnEnemy(1475.f, 385.f,WITCH);

    npcs.push_back(new Npc(WIZARD, 30.f, 450.f, 0.7f, 0.7f,
                                 textures["WIZARD_NPC_SHEET"], textures["CHATTABLE_ICON"]));
    npcs.push_back(new Npc(SHOP, 30.f, 250.f, 1.5f, 1.5f,
                       textures["SHOP_NPC_SHEET"], textures["CHATTABLE_ICON"]));
    npcs.push_back(new Npc(PRIEST, 30.f, 350.f, 1.5f, 1.5f,
                       textures["PRIEST_NPC_SHEET"], textures["CHATTABLE_ICON"]));
}

void GameState::initCharacterTab() {
    cTab = std::make_shared<CharacterTab>(window, font, player,
            this, getTextures(), rsHandler, &npcInteract);
    initEquipSlotsTextures();
    initInventoryItemTextures();
}

void GameState::initShopTab() {
    shopTab = std::make_shared<ShopTab>(window, font, player, this, rsHandler, textures);
    this->initShopItemTextures();
}

void GameState::initPriestTab() {
    priestTab = std::make_shared<PriestTab>(window, font, player, this, rsHandler, textures);
}

void GameState::initSpellTab() {
    spellTab = std::make_shared<SpellTab>(window, font, player, this, rsHandler, textures);
}

void GameState::initWizardTab() {
    wizardTab = std::make_shared<WizardTab>(window, font, player, this, textures);
}

void GameState::initHintsTab() {
    hints.setFont(*font);
    hints.setCharacterSize(30);
    hints.setString(" Esc to pause\n"
                          " WASD to move\n"
                          " I to print inventory\n"
                          " C to open/close character tab and inventory\n"
                          " B to print ResourcesHandler\n"
                          " M to gain gold\n"
                          " N to print all buffs\n"
                          " Y to print player equipment\n"
                          " G to add an item\n"
                          " T to gain exp\n"
                          " H to add potions\n"
                          " E to interact with npcs\n"
                          " X to noclip\n"
                                );

    hints.setPosition(5.f, window->getSize().y - hints.getGlobalBounds().height + 20.f);
}

void GameState::initEquipSlotsTextures(){
    //weapon
    rsHandler->setEquipSlotsTextureIntRect(5 , sf::IntRect(0, 0, 67, 67));
    cTab->getEquipSlots()[5]->setSlotTexture(&textures["EquipSlotsSheet"],
            sf::IntRect(0, 0, 67, 67));
    //shield
    rsHandler->setEquipSlotsTextureIntRect(4 , sf::IntRect(67, 0, 67, 67));
    cTab->getEquipSlots()[4]->setSlotTexture(&textures["EquipSlotsSheet"],
            sf::IntRect(67, 0, 67, 67));
    //head
    rsHandler->setEquipSlotsTextureIntRect(3 , sf::IntRect(134, 0, 67, 67));
    cTab->getEquipSlots()[3]->setSlotTexture(&textures["EquipSlotsSheet"],
            sf::IntRect(134, 0, 67, 67));
    //chest
    rsHandler->setEquipSlotsTextureIntRect(2 , sf::IntRect(201, 0, 67, 67));
    cTab->getEquipSlots()[2]->setSlotTexture(&textures["EquipSlotsSheet"],
            sf::IntRect(201, 0, 67, 67));
    //arms
    rsHandler->setEquipSlotsTextureIntRect(1 , sf::IntRect(268, 0, 67, 67));
    cTab->getEquipSlots()[1]->setSlotTexture(&textures["EquipSlotsSheet"],
            sf::IntRect(268, 0, 67, 67));
    //legs
    rsHandler->setEquipSlotsTextureIntRect(0 , sf::IntRect(335, 0, 67, 67));
    cTab->getEquipSlots()[0]->setSlotTexture(&textures["EquipSlotsSheet"],
            sf::IntRect(335, 0, 67, 67));
}

void GameState::initInventoryItemTextures(){
    for(auto &i : cTab->getInventorySlots()){
        i->setSlotTexture(&textures["ITEMS_SHEET"], 34.f);
        i->setDownRightTexture(&textures["SELECTED_ICON"]);
        i->setUpRightTexture(&textures["NEW_TAG"]);
    }
}

void GameState::initShopItemTextures() {
    for(auto i : this->shopTab->getShopSlots()){
        i->setSlotTexture(&this->textures["ITEMS_SHEET"], 34.f);
    }
}

void GameState::initBuffComponent() {
    buffComponent = std::make_shared<BuffComponent>(popUpTextComponent);
    // add all buffs to map
    buffComponent->addBuff("HealthPotion(S)",
            new Buff("HealthPotion(S)", 100, 0, 0, 0, 0.f, 0.f, true));

    buffComponent->addBuff("HealthPotion(M)",
            new Buff("HealthPotion(M)", 200, 0, 0, 0, 0.f, 0.f, true));

    buffComponent->addBuff("HealthPotion(L)",
            new Buff("HealthPotion(L)", 400, 0, 0, 0, 0.f, 0.f, true));

    buffComponent->addBuff("ManaPotion(S)",
            new Buff("ManaPotion(S)", 0, 100, 0, 0, 0.f, 0.f, true));

    buffComponent->addBuff("ManaPotion(M)",
            new Buff("ManaPotion(M)", 0, 200, 0, 0, 0.f, 0.f, true));

    buffComponent->addBuff("ManaPotion(L)",
            new Buff("ManaPotion(L)", 0, 400, 0, 0, 0.f, 0.f, true));

    buffComponent->addBuff("DamagePotion(S)",
            new Buff("DamagePotion(S)", 0, 0, 30, 0, 0.f, 0.f, 3));
}

void GameState::initSpellComponent() {
    spellComponent = std::make_shared<SpellComponent>();
    rsHandler->loadSpellList(spellComponent);
}

void GameState::initComponents() {
    popUpTextComponent = std::make_shared<PopUpTextComponent>(*font, window);

    initBuffComponent();
    initSpellComponent();
}

void GameState::initView() {
    this->view.setSize(
            sf::Vector2f(
                    static_cast<float>(this->window->getSize().x / 1.3f),
                    static_cast<float>(this->window->getSize().y / 1.3f)
            )
    );

    this->view.setCenter(
            sf::Vector2f(
                    static_cast<float>(this->window->getSize().x / 2.f),
                    static_cast<float>(this->window->getSize().y / 2.f)
            )
    );


}

void GameState::initDebugText() {
    debugText.setFont(*this->font);
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

    spellTabBtn = gui::Button(
            pauseMenuBtn.getPosition().x - 100.f,
            pauseMenuBtn.getPosition().y, 70.f, 70.f,
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
    map = mg->GenerateFromFile("../Data/dungeon.txt", 24, 79, this);
    std::cout << map->printMap();
}

//constructors/destructors
GameState::GameState(std::shared_ptr<sf::RenderWindow> window, std::stack<std::unique_ptr<State>>* states,
                     std::shared_ptr<ResourcesHandler> rsHandler, sf::Font *font)
        : State(window, states, rsHandler){
    this->font = font;
    stato = 0;
    npcInteract = NO_NPC;
    noclip = false;
    currentFloor = 5;
    utils::generateRandomNumber(1, 10, true);

    initTextures();
    initPauseMenu();
    initPlayers();

    initComponents();
    initView();
    initDebugText();
    initButtons();

    initCharacterTab();
    initShopTab();
    initPriestTab();
    initSpellTab();
    initWizardTab();
    initHintsTab();
    initMaps();
}

GameState::~GameState() {
    delete map;
    delete mg;
    for(auto i : npcs)
        delete i;
    for(auto i : enemies)
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
//functions
void GameState::addItem(Item *item) {
    if(this->player->getInventory()->addItem(item)){
        this->player->getInventory()->sortByItemType();
        this->cTab->initInventorySlots();
        this->initInventoryItemTextures();
        for(auto &i : this->cTab->getInventorySlots()){
            if(i->getItem()->isEquipped()){
                switch(i->getItem()->getUsageType()){
                    case 5:
                        i->setUpRightTexture(&this->textures["WEAPON_ICON"]);
                        break;
                    case 4:
                        i->setUpRightTexture(&this->textures["SHIELD_ICON"]);
                        break;
                    case 3:
                        i->setUpRightTexture(&this->textures["HELMET_ICON"]);
                        break;
                    case 2:
                        i->setUpRightTexture(&this->textures["ARMOR_ICON"]);
                        break;
                    case 1:
                        i->setUpRightTexture(&this->textures["GLOVES_ICON"]);
                        break;
                    case 0:
                        i->setUpRightTexture(&this->textures["BOOTS_ICON"]);
                        break;
                    default:
                        break;
                }
            }
        }
        this->updateTabsInvSpaceLbl();
    }
}

void GameState::spawnEnemy(float x, float y, enemy_types type) {
    switch(type){
        case WITCH:
            enemies.push_back(new Enemy(WITCH, x, y, 1.2f, 1.2f,
                                       127.f, 136.f, 50.f, 65.f,
                                       150.f, 200.f, 9.f,
                                       textures["ENEMY_WIZARD_SHEET"], currentFloor));
            break;
        case SKELETON:
            enemies.push_back(new Enemy(SKELETON, x, y, 2.f, 2.3f,
                                       0.f, 15.f, 40.f, 60.f,
                                       19.f, 73.f, 8.f,
                                       textures["ENEMY_SKELETON_SHEET"], currentFloor));
            break;
        case SKELETON_2:
            enemies.push_back(new Enemy(SKELETON_2, x, y, 1.2f, 1.2f,
                                       70.f, 60.f, 50.f, 63.f,
                                       95.f, 122.f, 10.f,
                                       textures["ENEMY_SKELETON_2_SHEET"], currentFloor));
            break;
        case FLYING_EYE:
            enemies.push_back(new Enemy(FLYING_EYE, x, y, 1.3f, 1.3f,
                                       72.f, 85.f, 58.f, 60.f,
                                       100.f, 142.f, 11.f,
                                       textures["ENEMY_FLYINGEYE_SHEET"], currentFloor));
            break;
        case GOBLIN:
            enemies.push_back(new Enemy(GOBLIN, x, y, 1.2f, 1.4f,
                                       70.f, 94.f, 40.f, 48.f,
                                       90.f, 142.f, 8.f,
                                       textures["ENEMY_GOBLIN_SHEET"], currentFloor));
            break;
        case MUSHROOM:
            enemies.push_back(new Enemy(MUSHROOM, x, y, 1.4f, 1.4f,
                                       87.f, 87.f, 38.f, 57.f,
                                       106.f, 143.f, 8.f,
                                       textures["ENEMY_MUSHROOM_SHEET"], currentFloor));
            break;
        case BANDIT_HEAVY:
            enemies.push_back(new Enemy(BANDIT_HEAVY, x, y, 1.8f, 1.8f,
                                       25.f, 15.f, 45.f, 68.f,
                                       47.f, 83.f, 9.f,
                                       textures["ENEMY_BANDITHEAVY_SHEET"], currentFloor));
            break;
        case BANDIT_LIGHT:
            enemies.push_back(new Enemy(BANDIT_LIGHT, x, y, 1.8f, 1.8f,
                                       25.f, 15.f, 45.f, 68.f,
                                       47.f, 83.f, 9.f,
                                       textures["ENEMY_BANDITLIGHT_SHEET"], currentFloor));
            break;
        default:
            std::cout<<"No such enemy: " << type;
            break;
    }
}

void GameState::changeStato(int stato) {
    if(!this->paused){
        this->pauseState();
        this->stato = stato;
    } else{
        this->unpauseState();
        this->stato = 0;
        this->window->setMouseCursorVisible(true);
    }
}

void GameState::updateInput(const float &dt) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && this->getKeyTime()) {
            this->changeStato(1);

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && this->getKeyTime()) {
            this->changeStato(2);
            this->cTab->unselectAll();

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && this->getKeyTime()) {
            if(this->noclip){
                this->noclip = false;
                this->player->getMovementComponent()->enableSpeedControl(true);
            }
            else{
                this->noclip = true;
                this->player->getMovementComponent()->enableSpeedControl(false);
            }


        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && this->getKeyTime()) {
            if(this->player->getPlayerStats()->addExp(100)){
                this->updateTabsPlayerStatsLbl();
            }
            this->popUpTextComponent->addPopUpTextCenter(EXPERIENCE_TAG, 100, "+", "Exp");

        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::B) && this->getKeyTime()){
            std::cout << this->rsHandler->toString();

        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::I) && this->getKeyTime()){
            std::cout << this->player->getInventory()->listInventory();

        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::G) && this->getKeyTime()){
            std::stringstream ss;
            ss << "Dragon Gloves" << rand();
            this->addItem(new Item("E-arms", ss.str(),
                    "powerful helmet", 5000, "Legendary",
                    4, 7, 300, 200, 0, 350, 10.3, 17.3, 1, true));
            this->cTab->updateInventoryCapLbl();
            this->popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG, ss.str(), "", " added to the inventory");

        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::H) && this->getKeyTime()){
            unsigned n = rand();
            Item* item = new Item("C-potionS", "HealthPotion(S)",
                                  "Restore 100 hp", 5, "Common",
                                  0, 3, 0, 0, 0, 0, 0, 0, n, true);
            this->addItem(item);
            this->popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG, to_string(n), "", " HealthPotion(S) added to the inventory");
            delete item;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && this->getKeyTime()){
            std::cout<<this->player->toStringEquipment();

        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::N) && this->getKeyTime()){
            std::cout<<this->buffComponent->toStringBuffs();

        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::P) && this->getKeyTime()){
            std::cout<<this->shopTab->toStringShopItems();

        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::M) && this->getKeyTime()){
            unsigned gold = rand();
            this->player->addGold(gold);
            this->updateTabsGoldLbl();
            this->popUpTextComponent->addPopUpTextCenter(GOLD_TAG, gold, "+", " gold");
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && this->getKeyTime()
            && this->npcInteract != NO_NPC){
            switch(this->npcInteract){
                case SHOP:
                    this->changeStato(3);
                    break;
                case PRIEST:
                    this->changeStato(4);
                    break;
                case WIZARD:
                    this->changeStato(6);
                    break;
                default:
                    std::cout<<"no npc\n";
                    break;
            }


        }
}

void GameState::updatePlayerInput(const float &dt) {
/*    if(this->getKeyTime()){
        cout<<this->player->getHitboxComponent()->getCenter().x<<" "<<this->player->getHitboxComponent()->getCenter().y<<"\n";
    }*/

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            player->move(dt, -1.f, 0.f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            player->move(dt, 1.f, 0.f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            player->move(dt, 0.f, -1.f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            player->move(dt, 0.f, 1.f);

     /*   if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // not working properly
            sf::Vector2f diff = this->mousePosView - this->player->getHitboxComponent()->getCenter();

            this->player->move(dt, diff.x, diff.y);
        }*/


}

void GameState::updateTabsGoldLbl() {
    this->cTab->updateGoldLbl();
    this->shopTab->updateGoldLbl();
    this->priestTab->updateGoldLbl();
    this->wizardTab->updateGoldLbl();
}

void GameState::updateTabsInvSpaceLbl() {
    this->cTab->updateInventoryCapLbl();
    this->shopTab->updateInvSpaceLbl();
}

void GameState::updateTabsPlayerStatsLbl() {
    this->cTab->updatePlayerStatsLbl();
    this->spellTab->updateSpellsInfoLbl();
}

void GameState::updatePausedMenuButtons() {
    if(this->pmenu.isButtonPressed("QUIT")){
        this->endState();
    } else if(this->pmenu.isButtonPressed("BACK")){
        this->changeStato(0);
    } else if(this->pmenu.isButtonPressed("SPELL")){
        this->changeStato(0);
        this->changeStato(5);
    }else if(this->pmenu.isButtonPressed("CHARACTER")){
        this->changeStato(0);
        this->changeStato(2);
    }
}

void GameState::updateView(const float &dt) {
    this->view.setCenter(this->player->getHitboxComponent()->getCenter());
}

void GameState::updateDebugText() {
//debbuging tool: show mouse pos coords
    std::stringstream ss;
    ss << "Mouse pos: " << this->mousePosView.x << " " << this->mousePosView.y;
    this->debugText.setString(ss.str());
}

void GameState::updateButtons() {
    if(this->cTabBtn.isPressed() && this->getKeyTime()){
        this->cTabBtn.setButtonState(BTN_IDLE);
        this->changeStato(2);
        this->cTab->unselectAll();
    } else if(this->pauseMenuBtn.isPressed() && this->getKeyTime()){
        this->pauseMenuBtn.setButtonState(BTN_IDLE);
        this->changeStato(1);
    } else if(this->spellTabBtn.isPressed() && this->getKeyTime()){
        this->spellTabBtn.setButtonState(BTN_IDLE);
        this->changeStato(5);
    }
}

void GameState::update(const float& dt) {
    this->updateMousePosition(&this->view);
    this->updateKeyTime(dt);

    this->updateInput(dt);

    this->updateTileMap(dt);

    this->updateDebugText();

    if(!this->paused){ //unpaused update
        this->updateView(dt);
        this->updatePlayerInput(dt);
        this->updateButtons();

        this->player->update(dt);
        for(auto i : this->enemies){
            i->update(dt);
            if(i->getHitboxComponent()->intersects(player->getHitboxComponent()->getGlobalBounds())){
                states->push(std::make_unique<BattleState>(
                        window, player, states, popUpTextComponent,
                        rsHandler, textures,font, i, currentFloor));
                player->setPosition(750.f, 130.f);
                player->stopVelocity();
            }
        }
        for(auto i : this->npcs){
            i->update(dt);
            i->updateCollsion(this->player, &this->npcInteract);
        }
        this->updateMousePosition(nullptr);
        this->cTabBtn.update(this->mousePosView);
        this->pauseMenuBtn.update(this->mousePosView);
        this->spellTabBtn.update(this->mousePosView);
        this->popUpTextComponent->update(dt);

    } else{ // paused update
        this->updateMousePosition(nullptr);
        switch(stato){
            case 1:
                this->pmenu.update(this->mousePosView);
                this->updatePausedMenuButtons();
                break;
            case 2:
                this->cTab->update(this->mousePosView);
                if(this->cTab->closeCharacterTabByClicking(this->mousePosView, &this->cTabBtn))
                    this->changeStato(0);
                this->popUpTextComponent->update(dt);
                break;
            case 3:
                this->shopTab->update(this->mousePosView);
                if(this->shopTab->closeTabByClicking(this->mousePosView))
                    this->changeStato(0);
                this->popUpTextComponent->update(dt);
                break;
            case 4:
                this->priestTab->update(this->mousePosView);
                if(this->priestTab->closeTabByClicking(this->mousePosView))
                    this->changeStato(0);
                this->popUpTextComponent->update(dt);
                break;
            case 5:
                this->spellTab->update(this->mousePosView);
                if(this->spellTab->closeTabByClicking(this->mousePosView, &this->spellTabBtn))
                    this->changeStato(0);
                this->popUpTextComponent->update(dt);
                break;
            case 6:
                this->wizardTab->update(this->mousePosView);
                if(this->wizardTab->closeTabByClicking(this->mousePosView))
                    this->changeStato(0);
                this->popUpTextComponent->update(dt);
                break;
        }
    }
}

void GameState::render(sf::RenderTarget* target) {
    if(!target){
        target = window.get();
    }
    target->setView(this->view);

    this->map->render(target);
    this->player->render(*target, true, true);
    for(auto i : this->enemies){
        i->render(*target, true, true);
    }
    for(auto i : this->npcs){
        i->render(*target, true);
    }

    target->setView(target->getDefaultView());
    this->cTabBtn.render(*target);
    this->pauseMenuBtn.render(*target);
    this->spellTabBtn.render(*target);
    target->draw(this->hints);

    if(this->paused){ // pause menu render
        switch(stato){
            case 1:
                this->pmenu.render(*target);
                break;
            case 2:
                this->cTab->render(*target);
                break;
            case 3:
                this->shopTab->render(*target);
                break;
            case 4:
                this->priestTab->render(*target);
                break;
            case 5:
                this->spellTab->render(*target);
                break;
            case 6:
                this->wizardTab->render(*target);
                break;
        }
    }
    target->draw(this->debugText);

    this->popUpTextComponent->render(*target);
}

void GameState::updateTileMap(const float &dt) {
    this->map->updateCollision(this->player);
    if(!this->noclip)
        this->map->updateTileCollision(this->player, dt);
}












































