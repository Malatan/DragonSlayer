//
// Created by Zheng on 07/10/2020.
//

#include "GameState.h"

void GameState::initTextures() {

    this->rsHandler->addResouce("../Resources/Images/Sprites/Player/player_sheet.png", "player_sheet", "GameState");
    this->rsHandler->addResouce("../Resources/Images/Sprites/Enemy/wizard_Idle.png", "wizard_sheet", "GameState");
    this->rsHandler->addResouce("../Resources/Images/Sprites/Npc/shop_npc_idle.png", "shop_npc_sheet", "GameState");
    this->rsHandler->addResouce("../Resources/Images/Sprites/Npc/priest_npc_idle.png", "priest_npc_sheet", "GameState");
    this->rsHandler->addResouce("../Resources/Images/Sprites/Npc/wizard_npc_idle.png", "wizard_npc_sheet", "GameState");

    this->rsHandler->addResouce("../Resources/Images/chat.png", "chattable_icon", "GameState");

    this->rsHandler->addResouce("../Resources/Images/characterIcon.png", "characterIcon", "GameState");
    this->rsHandler->addResouce("../Resources/Images/inventoryIcon.png", "inventoryIcon", "GameState");
    this->rsHandler->addResouce("../Resources/Images/pauseMenuIcon.png", "pauseMenuIcon", "GameState");

    this->rsHandler->addResouce("../Resources/Images/equipslot_sheet.png", "EquipSlotsSheet", "GameState");
    this->rsHandler->addResouce("../Resources/Images/items_sheet.png", "items_sheet", "GameState");
    this->rsHandler->addResouce("../Resources/Images/selectedIcon.png", "selected", "GameState");
    this->rsHandler->addResouce("../Resources/Images/new.png", "newTag", "GameState");
    this->rsHandler->addResouce("../Resources/Images/weaponIcon.png", "weaponIcon", "GameState");
    this->rsHandler->addResouce("../Resources/Images/shieldIcon.png", "shieldIcon", "GameState");
    this->rsHandler->addResouce("../Resources/Images/helmetIcon.png", "helmetIcon", "GameState");
    this->rsHandler->addResouce("../Resources/Images/armorIcon.png", "armorIcon", "GameState");
    this->rsHandler->addResouce("../Resources/Images/glovesIcon.png", "glovesIcon", "GameState");
    this->rsHandler->addResouce("../Resources/Images/bootsIcon.png", "bootsIcon", "GameState");
    this->rsHandler->addResouce("../Resources/Images/randomIcon.png", "randomIcon", "GameState");

    this->textures["PLAYER_SHEET"].loadFromImage(this->rsHandler->getResouceByKey("player_sheet")->getImage());
    this->textures["ENEMY_WIZARD_SHEET"].loadFromImage(this->rsHandler->getResouceByKey("wizard_sheet")->getImage());
    this->textures["SHOP_NPC_SHEET"].loadFromImage(this->rsHandler->getResouceByKey("shop_npc_sheet")->getImage());
    this->textures["PRIEST_NPC_SHEET"].loadFromImage(this->rsHandler->getResouceByKey("priest_npc_sheet")->getImage());
    this->textures["WIZARD_NPC_SHEET"].loadFromImage(this->rsHandler->getResouceByKey("wizard_npc_sheet")->getImage());

    this->textures["CHATTABLE_ICON"].loadFromImage(this->rsHandler->getResouceByKey("chattable_icon")->getImage());

    this->textures["CHARACTER_ICON"].loadFromImage(this->rsHandler->getResouceByKey("characterIcon")->getImage());
    this->textures["INVENTORY_ICON"].loadFromImage(this->rsHandler->getResouceByKey("inventoryIcon")->getImage());
    this->textures["PAUSEMENU_ICON"].loadFromImage(this->rsHandler->getResouceByKey("pauseMenuIcon")->getImage());

    this->textures["ITEMS_SHEET"].loadFromImage(this->rsHandler->getResouceByKey("items_sheet")->getImage());
    this->textures["EquipSlotsSheet"].loadFromImage(this->rsHandler->getResouceByKey("EquipSlotsSheet")->getImage());
    this->textures["SELECTED_ICON"].loadFromImage(this->rsHandler->getResouceByKey("selected")->getImage());
    this->textures["NEW_TAG"].loadFromImage(this->rsHandler->getResouceByKey("newTag")->getImage());
    this->textures["WEAPON_ICON"].loadFromImage(this->rsHandler->getResouceByKey("weaponIcon")->getImage());
    this->textures["SHIELD_ICON"].loadFromImage(this->rsHandler->getResouceByKey("shieldIcon")->getImage());
    this->textures["HELMET_ICON"].loadFromImage(this->rsHandler->getResouceByKey("helmetIcon")->getImage());
    this->textures["ARMOR_ICON"].loadFromImage(this->rsHandler->getResouceByKey("armorIcon")->getImage());
    this->textures["GLOVES_ICON"].loadFromImage(this->rsHandler->getResouceByKey("glovesIcon")->getImage());
    this->textures["BOOTS_ICON"].loadFromImage(this->rsHandler->getResouceByKey("bootsIcon")->getImage());
    this->textures["RANDOM_ICON"].loadFromImage(this->rsHandler->getResouceByKey("randomIcon")->getImage());
}

void GameState::initPauseMenu() {
    this->pmenu = new PauseMenu(*this->window, this->font);

    this->pmenu->addButton("QUIT", 400.f, "Quit");
}

void GameState::initPlayers() {
    this->player = new Player(300.f, 300.f, 2.f, 2.f,
                              this->textures["PLAYER_SHEET"]);
    this->player->setGold(0);
    this->player->getInventory()->setCurrentMaxSpace(90);

    // legge i valori di default del Stats dal Data/Stats.txt
    this->rsHandler->loadPlayerStatsTxt(this->player->getPlayerStats());

    // legge i valori di default dell 'inventario dal Data/Inventory.txt
    this->rsHandler->loadPlayerInventoryTxt(this->player->getInventory());

    this->enemis.push_back(new Enemy(30.f, 30.f, 1.2f, 1.2f,
                                     127.f, 136.f, 50.f, 65.f,
                                     this->textures["ENEMY_WIZARD_SHEET"]));

    this->npcs.push_back(new Npc(SHOP, 30.f, 250.f, 1.5f, 1.5f,
                                 this->textures["SHOP_NPC_SHEET"], this->textures["CHATTABLE_ICON"]));
    this->npcs.push_back(new Npc(PRIEST, 30.f, 350.f, 1.5f, 1.5f,
                                 this->textures["PRIEST_NPC_SHEET"], this->textures["CHATTABLE_ICON"]));
    this->npcs.push_back(new Npc(WIZARD, 30.f, 450.f, 0.7f, 0.7f,
                                 this->textures["WIZARD_NPC_SHEET"], this->textures["CHATTABLE_ICON"]));
}

void GameState::initCharacterTab() {
    this->cTab = new CharacterTab(this->window, this->font, this->player,
            this, this->getTextures(), this->rsHandler, &this->npcInteract);
    this->initEquipSlotsTextures();
    this->initInventoryItemTextures();
}

void GameState::initShopTab() {
    this->shopTab = new ShopTab(this->window, this->font, this->player,
            this, this->rsHandler, this->textures);
    this->initShopItemTextures();
}

void GameState::initPriestTab() {
    this->priestTab = new PriestTab(this->window, this->font, this->player,
                                this, this->rsHandler, this->textures);
}

void GameState::initHintsTab() {
    this->hints.setFont(*this->font);
    this->hints.setCharacterSize(30);
    this->hints.setString(" Esc to pause\n"
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
                                );

    this->hints.setPosition(5.f, this->window->getSize().y - this->hints.getGlobalBounds().height + 20.f);
}

void GameState::initEquipSlotsTextures(){
    //weapon
    this->rsHandler->setEquipSlotsTextureIntRect(5 , sf::IntRect(0, 0, 67, 67));
    this->cTab->getEquipSlots()[5]->setSlotTexture(&this->textures["EquipSlotsSheet"],
            sf::IntRect(0, 0, 67, 67));
    //shield
    this->rsHandler->setEquipSlotsTextureIntRect(4 , sf::IntRect(67, 0, 67, 67));
    this->cTab->getEquipSlots()[4]->setSlotTexture(&this->textures["EquipSlotsSheet"],
            sf::IntRect(67, 0, 67, 67));
    //head
    this->rsHandler->setEquipSlotsTextureIntRect(3 , sf::IntRect(134, 0, 67, 67));
    this->cTab->getEquipSlots()[3]->setSlotTexture(&this->textures["EquipSlotsSheet"],
            sf::IntRect(134, 0, 67, 67));
    //chest
    this->rsHandler->setEquipSlotsTextureIntRect(2 , sf::IntRect(201, 0, 67, 67));
    this->cTab->getEquipSlots()[2]->setSlotTexture(&this->textures["EquipSlotsSheet"],
            sf::IntRect(201, 0, 67, 67));
    //arms
    this->rsHandler->setEquipSlotsTextureIntRect(1 , sf::IntRect(268, 0, 67, 67));
    this->cTab->getEquipSlots()[1]->setSlotTexture(&this->textures["EquipSlotsSheet"],
            sf::IntRect(268, 0, 67, 67));
    //legs
    this->rsHandler->setEquipSlotsTextureIntRect(0 , sf::IntRect(335, 0, 67, 67));
    this->cTab->getEquipSlots()[0]->setSlotTexture(&this->textures["EquipSlotsSheet"],
            sf::IntRect(335, 0, 67, 67));
}

void GameState::initInventoryItemTextures(){
    for(auto i : this->cTab->getInventorySlots()){
        i->setSlotTexture(&this->textures["ITEMS_SHEET"], 34.f);
        i->setDownRightTexture(&this->textures["SELECTED_ICON"]);
        i->setUpRightTexture(&this->textures["NEW_TAG"]);
    }
}

void GameState::initShopItemTextures() {
    for(auto i : this->shopTab->getShopSlots()){
        i->setSlotTexture(&this->textures["ITEMS_SHEET"], 34.f);
    }
}

void GameState::initBuffComponent() {
    this->buffComponent = new BuffComponent(this->popUpTextComponent);
    // add all buffs to map
    this->buffComponent->addBuff("HealthPotion(S)",
            new Buff("HealthPotion(S)", 100, 0, 0, 0, 0.f, 0.f, true));

    this->buffComponent->addBuff("HealthPotion(M)",
            new Buff("HealthPotion(M)", 200, 0, 0, 0, 0.f, 0.f, true));

    this->buffComponent->addBuff("HealthPotion(L)",
            new Buff("HealthPotion(L)", 400, 0, 0, 0, 0.f, 0.f, true));

    this->buffComponent->addBuff("ManaPotion(S)",
            new Buff("ManaPotion(S)", 0, 100, 0, 0, 0.f, 0.f, true));

    this->buffComponent->addBuff("ManaPotion(M)",
            new Buff("ManaPotion(M)", 0, 200, 0, 0, 0.f, 0.f, true));

    this->buffComponent->addBuff("ManaPotion(L)",
            new Buff("ManaPotion(L)", 0, 400, 0, 0, 0.f, 0.f, true));

    this->buffComponent->addBuff("DamagePotion(S)",
            new Buff("DamagePotion(S)", 0, 0, 30, 0, 0.f, 0.f, 3));
}

void GameState::initComponents() {
    this->popUpTextComponent = new PopUpTextComponent(*this->font, this->window);


    this->initBuffComponent();
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
    this->debugText.setFont(*this->font);
    this->debugText.setCharacterSize(25);
    this->debugText.setString("sss");
    this->debugText.setPosition(5.f, 40.f);
}

void GameState::initButtons() {
    this->pauseMenuBtn = new gui::Button(
            this->window->getSize().x - 100.f,
            this->window->getSize().y - 90.f, 70.f, 70.f,
            this->font, "", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color::Transparent,
            sf::Color(70, 70, 70, 60),
            sf::Color(130, 130, 130, 0));
    this->pauseMenuBtn->setBackgroundTexture(&this->textures["PAUSEMENU_ICON"]);
    this->pauseMenuBtn->setBackbgroundDisabled(false);

    this->cTabBtn = new gui::Button(
            this->pauseMenuBtn->getPosition().x - 100.f,
            this->pauseMenuBtn->getPosition().y, 70.f, 70.f,
            this->font, "", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color::Transparent,
            sf::Color(70, 70, 70, 60),
            sf::Color(130, 130, 130, 0));
    this->cTabBtn->setBackgroundTexture(&this->textures["INVENTORY_ICON"]);
    this->cTabBtn->setBackbgroundDisabled(false);

}

//constructors/destructors
GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, ResourcesHandler* rsHandler, sf::Font* font,
        bool* isFocused, sf::Event* sfEvent)
        : State(window, states, rsHandler, isFocused, sfEvent){
    this->font = font;
    this->stato = 0;
    this->npcInteract = NO_NPC;
    this->initTextures();
    this->initPauseMenu();
    this->initPlayers();
    this->initCharacterTab();
    this->initShopTab();
    this->initPriestTab();
    this->initHintsTab();
    this->initComponents();
    this->initView();
    this->initDebugText();
    this->initButtons();
}

GameState::~GameState() {
    delete this->pmenu;
    delete this->player;
    delete this->cTab;
    delete this->shopTab;
    delete this->priestTab;
    delete this->cTabBtn;
    delete this->pauseMenuBtn;
    for(auto i : this->enemis)
        delete i;
    for(auto i : this->npcs)
        delete i;
}

//functions
void GameState::addItem(Item *item) {
    if(this->player->getInventory()->addItem(item)){
        this->player->getInventory()->sortByItemType();
        this->cTab->initInventorySlots();
        this->initInventoryItemTextures();
        for(auto i : this->cTab->getInventorySlots()){
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
    if (*this->windowIsFocused) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && this->getKeyTime()) {
            this->changeStato(1);

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && this->getKeyTime()) {
            this->changeStato(2);
            this->cTab->unselectAll();

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && this->getKeyTime()) {
            this->player->getPlayerStats()->addExp(100);
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
                    std::cout<<"interacting with wizard npc\n";
                    break;
                default:
                    std::cout<<"no npc\n";
                    break;
            }


        }
    }
}

void GameState::updatePlayerInput(const float &dt) {
/*    if(this->getKeyTime()){
        cout<<this->player->getHitboxComponent()->getCenter().x<<" "<<this->player->getHitboxComponent()->getCenter().y<<"\n";
    }*/

    if(*this->windowIsFocused){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            this->player->move(dt, -1.f, 0.f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            this->player->move(dt, 1.f, 0.f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            this->player->move(dt, 0.f, -1.f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            this->player->move(dt, 0.f, 1.f);

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // not working properly
            sf::Vector2f diff = this->mousePosView - this->player->getHitboxComponent()->getCenter();

            this->player->move(dt, diff.x, diff.y);
        }
    }

}

void GameState::updateTabsGoldLbl() {
    this->cTab->updateGoldLbl();
    this->shopTab->updateGoldLbl();
    this->priestTab->updateGoldLbl();
}

void GameState::updateTabsInvSpaceLbl() {
    this->cTab->updateInventoryCapLbl();
    this->shopTab->updateInvSpaceLbl();
}

void GameState::updatePausedMenuButtons() {
    if(this->pmenu->isButtonPressed("QUIT")){
        this->endState();
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
    if(this->cTabBtn->isPressed() && this->getKeyTime()){
        this->cTabBtn->setButtonState(BTN_IDLE);
        this->changeStato(2);
        this->cTab->unselectAll();
    } else if(this->pauseMenuBtn->isPressed() && this->getKeyTime()){
        this->pauseMenuBtn->setButtonState(BTN_IDLE);
        this->changeStato(1);
    }
}

void GameState::update(const float& dt) {
    this->updateMousePosition(&this->view);
    this->updateKeyTime(dt);
    this->updateInput(dt);

    this->updateDebugText();

    if(!this->paused){ //unpaused update
        this->updateView(dt);
        this->updatePlayerInput(dt);
        this->updateButtons();

        this->player->update(dt);
        for(auto i : this->enemis){
            i->update(dt);
        }
        for(auto i : this->npcs){
            i->update(dt);
            i->updateCollsion(this->player, &this->npcInteract);
        }
        this->updateMousePosition(nullptr);
        this->cTabBtn->update(this->mousePosView);
        this->pauseMenuBtn->update(this->mousePosView);
        this->popUpTextComponent->update(dt);

    } else{ // paused update
        switch(stato){
            case 1:
                this->updateMousePosition(nullptr);
                this->pmenu->update(this->mousePosView);
                this->updatePausedMenuButtons();
                break;
            case 2:
                this->updateMousePosition(nullptr);
                this->cTab->update(this->mousePosView);
                if(this->cTab->closeCharacterTabByClicking(this->mousePosView, this->cTabBtn))
                    this->changeStato(0);
                this->popUpTextComponent->update(dt);
                break;
            case 3:
                this->updateMousePosition(nullptr);
                this->shopTab->update(this->mousePosView);
                if(this->shopTab->closeTabByClicking(this->mousePosView))
                    this->changeStato(0);
                this->popUpTextComponent->update(dt);
                break;
            case 4:
                this->updateMousePosition(nullptr);
                this->priestTab->update(this->mousePosView);
                if(this->priestTab->closeTabByClicking(this->mousePosView))
                    this->changeStato(0);
                this->popUpTextComponent->update(dt);
                break;
        }
    }
}

void GameState::render(sf::RenderTarget* target) {
    if(!target){
        target = this->window;
    }
    target->setView(this->view);

    this->player->render(*target, true);
    for(auto i : this->enemis){
        i->render(*target, true);
    }
    for(auto i : this->npcs){
        i->render(*target, true);
    }

    target->setView(target->getDefaultView());
    this->cTabBtn->render(*target);
    this->pauseMenuBtn->render(*target);
    target->draw(this->hints);

    if(this->paused){ // pause menu render
        switch(stato){
            case 1:
                this->pmenu->render(*target);
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
        }
    }
    target->draw(this->debugText);

    this->popUpTextComponent->render(*target);
}




























