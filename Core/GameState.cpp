//
// Created by Zheng on 07/10/2020.
//

#include "GameState.h"

void GameState::initTextures() {
    this->rsHandler->addResouce("../Resources/Images/Sprites/Player/player_sheet.png", "player_sheet", "GameState");
    this->rsHandler->addResouce("../Resources/Images/Sprites/Enemy/wizard_Idle.png", "wizard_sheet", "GameState");
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

    this->textures["PLAYER_SHEET"].loadFromImage(this->rsHandler->getResouceByKey("player_sheet")->getImage());
    this->textures["ENEMY_WIZARD_SHEET"].loadFromImage(this->rsHandler->getResouceByKey("wizard_sheet")->getImage());
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
}

void GameState::initPauseMenu() {
    this->pmenu = new PauseMenu(*this->window, this->font);

    this->pmenu->addButton("QUIT", 400.f, "Quit");
}

void GameState::initPlayers() {
    this->player = new Player(this->window->getSize().x/2.f,
                              this->window->getSize().y/2.f, 2.f, 2.f,
                              this->textures["PLAYER_SHEET"]);
    this->player->setGold(1000);

    // legge i valori di default del Stats dal Data/Stats.txt
    this->rsHandler->loadPlayerStatsTxt(this->player->getPlayerStats());

    // legge i valori di default dell 'inventario dal Data/Inventory.txt
    this->rsHandler->loadPlayerInventoryTxt(this->player->getInventory());

    this->enemis.push_back(new Enemy(30.f, 30.f, 1.2f, 1.2f,
                                     127.f, 134.f, 50.f, 65.f,
                                     this->textures["ENEMY_WIZARD_SHEET"]));

}

void GameState::initCharacterTab(Player* player) {
    this->cTab = new CharacterTab(this->window, this->font, player, this, this->getTextures());
    this->initEquipSlotsTextures();
    this->initInventoryItemTextures();
}

void GameState::initHintsTab() {
    this->hints.setFont(*this->font);
    this->hints.setCharacterSize(30);
    this->hints.setString(" Press Esc to pause\n"
                                " Press WASD to move\n"
                                " Press I to print inventory\n"
                                " Press C to open/close character tab and inventory\n"
                                " Press B to print ResourcesHandler\n"
                                " Press T in the character Tab to gain exp\n");

    this->hints.setPosition(5.f, this->window->getSize().y - this->hints.getGlobalBounds().height + 20.f);
}

void GameState::initEquipSlotsTextures(){
    //weapon
    this->cTab->getEquipSlots()[5]->setSlotTexture(&this->textures["EquipSlotsSheet"],
            sf::IntRect(0, 0, 67, 67));
    //shield
    this->cTab->getEquipSlots()[4]->setSlotTexture(&this->textures["EquipSlotsSheet"],
            sf::IntRect(67, 0, 67, 67));
    //head
    this->cTab->getEquipSlots()[3]->setSlotTexture(&this->textures["EquipSlotsSheet"],
            sf::IntRect(134, 0, 67, 67));
    //chest
    this->cTab->getEquipSlots()[2]->setSlotTexture(&this->textures["EquipSlotsSheet"],
            sf::IntRect(201, 0, 67, 67));
    //arms
    this->cTab->getEquipSlots()[1]->setSlotTexture(&this->textures["EquipSlotsSheet"],
            sf::IntRect(268, 0, 67, 67));
    //legs
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

//constructors/destructors
GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, ResourcesHandler* rsHandler, sf::Font* font,
        bool* isFocused, sf::Event* sfEvent)
        : State(window, states, rsHandler, isFocused, sfEvent){
    this->font = font;
    this->stato = 0;
    this->initTextures();
    this->initPauseMenu();
    this->initPlayers();
    this->initCharacterTab(this->player);
    this->initHintsTab();
}

GameState::~GameState() {
    delete this->pmenu;
    delete this->player;
    delete this->cTab;
    for(auto i : this->enemis)
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
                if(i->getItem()->getItemUsageType() == "Melee" || i->getItem()->getItemUsageType() == "Ranged"){
                    i->setUpRightTexture(&this->textures["WEAPON_ICON"]);
                }
                else if(i->getItem()->getItemUsageType() == "Shield"){
                    i->setUpRightTexture(&this->textures["SHIELD_ICON"]);
                }
                else if(i->getItem()->getItemUsageType() == "Helmet"){
                    i->setUpRightTexture(&this->textures["HELMET_ICON"]);
                }
                else if(i->getItem()->getItemUsageType() == "Chest"){
                    i->setUpRightTexture(&this->textures["ARMOR_ICON"]);
                }
                else if(i->getItem()->getItemUsageType() == "Gloves"){
                    i->setUpRightTexture(&this->textures["GLOVES_ICON"]);
                }
                else if(i->getItem()->getItemUsageType() == "Boots"){
                    i->setUpRightTexture(&this->textures["BOOTS_ICON"]);
                }
            }
        }
    }
}

void GameState::changeStato(int stato) {
    if(!this->paused){
        this->pauseState();
        this->stato = stato;
    } else{
        this->unpauseState();
        this->stato = 0;
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
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::B) && this->getKeyTime()){
            std::cout << this->rsHandler->toString();
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::I) && this->getKeyTime()){
            std::cout << this->player->getInventory()->listInventory();
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::G) && this->getKeyTime()){
            std::stringstream ss;
            ss << "Dragon Helmet" << rand();
            this->addItem(new Item("E-arms", ss.str(),
                    "powerful helmet", 5000, "Legendary",
                    4, 7, 300, 200, 0, 350, 10.3, 17.3, 1, true));
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R) && this->getKeyTime()){
            std::cout<<this->player->toStringEquipment();
        }
    }
}

void GameState::updatePlayerInput(const float &dt) {
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
    }

}

void GameState::updatePausedMenuButtons() {
    if(this->pmenu->isButtonPressed("QUIT")){
        this->endState();
    }
}

void GameState::update(const float& dt) {
    this->updateMousePosition();
    this->updateKeyTime(dt);
    this->updateInput(dt);


    if(!this->paused){ //unpaused update

        this->updatePlayerInput(dt);

        this->player->update(dt);
        for(auto i : this->enemis){
            i->update(dt);
           /* if(this->player->getHitboxComponent()->intersects(i->getHitboxComponent()->getGlobalBounds())){
                std::cout<<"Collision"<<"\n";
            }*/
        }

    } else{ // paused update
        if(stato == 1){
            this->pmenu->update(this->mousePosView);
            this->updatePausedMenuButtons();

        } else if(stato == 2){
            this->cTab->update(this->mousePosView);
            if(this->cTab->closeCharacterTabByClicking(this->mousePosView))
                this->changeStato(0);
        }

    }

}

void GameState::render(sf::RenderTarget* target) {
    if(!target){
        target = this->window;
    }

    this->player->render(*target, true);
    for(auto i : this->enemis){
        i->render(*target, true);
    }

    target->draw(this->hints);
    if(this->paused){ // pause menu render
        if(stato == 1){
            this->pmenu->render(*target);
        } else if(stato == 2){

            this->cTab->render(*target);
        }

    }

    //debbuging tool: show mouse pos coords
    sf::Text mouseText;
    mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 15);
    mouseText.setFont(*this->font);
    mouseText.setCharacterSize(14);
    std::stringstream ss;
    ss << this->mousePosView.x << " " << this->mousePosView.y;
    mouseText.setString(ss.str());
    target->draw(mouseText);
}








