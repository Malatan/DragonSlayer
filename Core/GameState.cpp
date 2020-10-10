//
// Created by Zheng on 07/10/2020.
//

#include "GameState.h"

void GameState::initTextures() {
    if(!this->rsHandler->checkIfKeyExist("player sheet")){
        this->rsHandler->addResouce(new Resource("../Resources/Images/Sprites/Player/player_sheet.png", "player sheet", "GameState"));

    }

    if(!this->rsHandler->checkIfKeyExist("wizard sheet")) {
        this->rsHandler->addResouce(
                new Resource("../Resources/Images/Sprites/Enemy/wizard_Idle.png", "wizard sheet", "GameState"));
    }

    this->textures["PLAYER_SHEET"].loadFromImage(this->rsHandler->getResouceByKey("player sheet")->getImage());
    this->textures["ENEMY_WIZARD_SHEET"].loadFromImage(this->rsHandler->getResouceByKey("wizard sheet")->getImage());

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

    this->enemis.push_back(new Enemy(30.f, 30.f, 1.2f, 1.2f,
                                     127.f, 134.f, 50.f, 65.f,
                                     this->textures["ENEMY_WIZARD_SHEET"]));

}

void GameState::initCharacterTab(Player* player) {
    this->cTab = new CharacterTab(*this->window, this->font, player, this);
}

void GameState::initHintsTab() {
    this->hints.setFont(*this->font);
    this->hints.setCharacterSize(30);
    this->hints.setString(" Press Esc to pause\n"
                                " Press WASD to move\n"
                                " Press E to interact and loot non funzia\n"
                                " Press C to open character tab and inventory");

    this->hints.setPosition(5.f, (this->window->getSize().y/100.f) * 83.f);
}

//constructors/destructors
GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, ResourcesHandler* rsHandler, sf::Font* font)
        : State(window, states, rsHandler){
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && this->getKeyTime()){
        this->changeStato(1);
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::C) && this->getKeyTime()){
        this->changeStato(2);
    }
}

void GameState::updatePlayerInput(const float &dt) {
    //aggiorna player input
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






