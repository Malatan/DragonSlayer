//
// Created by Zheng on 07/10/2020.
//

#include "GameState.h"

void GameState::initTextures() {
    if(!this->textures["PLAYER_SHEET"] .loadFromFile("../Resources/Images/Sprites/Player/player_sheet.png")){
        throw("Errore gamestate could not load player texture");
    }
    if(!this->textures["ENEMY_WIZARD_SHEET"] .loadFromFile("../Resources/Images/Sprites/Enemy/wizard_Idle.png")){
        throw("Errore gamestate could not load player texture");
    }
}

void GameState::initPauseMenu() {
    this->pmenu = new PauseMenu(*this->window, this->font);

    this->pmenu->addButton("QUIT", 400.f, "Quit");
}

void GameState::initPlayers() {
   this->player = new Player(this->window->getSize().x/2.f,
           this->window->getSize().y/2.f, 2.f, 2.f,
           this->textures["PLAYER_SHEET"]);

   this->enemis.push_back(new Enemy(30.f, 30.f, 1.2f, 1.2f,
           127.f, 134.f, 50.f, 65.f,
                                    this->textures["ENEMY_WIZARD_SHEET"]));

}

void GameState::initHintsTab() {
    this->hints.setFont(*this->font);
    this->hints.setCharacterSize(30);
    this->hints.setString(" Press Esc to pause\n"
                                " Press WASD to move\n"
                                " Press E to interact and loot non funzia\n"
                                " Press C to open character tab and inventory non funzia");

    this->hints.setPosition(5.f, (this->window->getSize().y/100.f) * 83.f);
}

//constructors/destructors
GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, sf::Font* font)
        : State(window, states){
    this->font = font;
    this->initTextures();
    this->initPauseMenu();
    this->initPlayers();
    this->initHintsTab();
}

GameState::~GameState() {
    delete this->pmenu;
    delete this->player;
}

//functions
void GameState::updateInput(const float &dt) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && this->getKeyTime()){
        if(!this->paused){
            this->pauseState();
        } else{
            this->unpauseState();
        }

    }
}

void GameState::updatePlayerInput(const float &dt) {
    //aggiorna player input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player->move(dt, -1.f, 0.f);
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
            if(this->player->getHitboxComponent()->intersects(i->getHitboxComponent()->getGlobalBounds())){
                std::cout<<"11";
            }
        }

    } else{ // paused update
        this->pmenu->update(this->mousePosView);
        this->updatePausedMenuButtons();
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
        this->pmenu->render(*target);
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


