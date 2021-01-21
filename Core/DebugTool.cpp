//
// Created by Zheng on 21/01/2021.
//

#include "DebugTool.h"

//initializers
void DebugTool::addButton(const std::string& btn_key, const std::string& text) {
    float _x = 400.f;
    float _y = 5.f;
    float width = 150.f;
    float height = 30.f;
    float height_gap = 10.f;
    float width_gap = 5.f;
    if(buttons.size() + 1 > 8){
        _x += (float)((int)(buttons.size() / 8)) * (width + width_gap);
        _y += (float)(buttons.size() - 8) * (height + height_gap);
    }else{
        _y += buttons.size() * (height + height_gap);
    }
    buttons[btn_key] = new gui::Button(_x, _y, width, height, font, text, 15, 0);
}

void DebugTool::initButtons() {
    addButton("G_ADD_EXP", "ADD 100 EXP");
    addButton("G_ADD_GOLD", "ADD 1000 GOLD");
    addButton("G_UNLOCKFLOORS", "UNLOCK FLOORS");
    addButton("G_NOCLIP", "NOCLIP");
    addButton("PRINT_G_ENEMIES", "PRINT ENEMIS");
    addButton("PRINT_G_LOOTBAGS", "PRINT LOOTBAGS");
    addButton("PRINT_P_INV", "PRINT INVENTORY");
    addButton("PRINT_P_EQUIPS", "PRINT EQUIPS");
    addButton("PRINT_P_STATS", "PRINT STATS");
    for(auto i : buttons){
        i.second->setIdleTextColor(sf::Color::Red);
        i.second->setBorderColor(sf::Color::Red);
        i.second->setBorderLineThickness(1.f);
    }
}

void DebugTool::initDebugTextLbl() {
    textLbl.setFont(*font);
    textLbl.setCharacterSize(20);
    textLbl.setFillColor(sf::Color::Red);
    textLbl.setString("Debug text");
    textLbl.setPosition(5.f, 5.f);
}

//constructors/destructor
DebugTool::DebugTool(sf::Font* _font, State* state) : font(_font){
    gstate = dynamic_cast<GameState*>(state);
    initButtons();
    initDebugTextLbl();
}

DebugTool::~DebugTool() {
    for(const auto& i : buttons)
        delete i.second;
}

//functions
void DebugTool::updateDebugText() {
    sf::Vector2f vv = gstate->player->getMovementComponent()->getVelocity();
    sf::Vector2f vd = gstate->player->getMovementComponent()->getDirection();
    std::stringstream ss;
    ss << "<Ctrl + F11> Open Debug Menu" << std::endl
       << "<Home> Close Debugtool" << std::endl
       << "Mouse pos: x: " << gstate->mousePosView.x << " y: " << gstate->mousePosView.y << std::endl
       << "Enemies: " << gstate->enemies.size() << " Lootbags: " << gstate->lootBags.size() << std::endl
       << "Nodes[x]: " << gstate->pathFinder->widthN << " Nodes[y]: " << gstate->pathFinder->heightN
       << "Nodes: " << gstate->pathFinder->nodesN << std::endl
       << "Dx: " << vd.x << std::endl << "Dy: " << vd.y << std::endl
       << "Vx: " << vv.x << std::endl << "Vy: " << vv.y << std::endl
       << "PathFinding called per second: " << gstate->pathFinder->counts << std::endl;
    textLbl.setString(ss.str());
}

void DebugTool::updateInput() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F11) && gstate->getKeyTime()){
            showMenu = !showMenu;
        }
    }
}

void DebugTool::applyFunctions(const string &key) {
    if(key == "G_ADD_EXP"){
        int exp = 100;
        if(gstate->player->getPlayerStats()->addExp(exp)){
            gstate->updateTabsPlayerStatsLbl();
            gstate->notify(AE_P_LEVEL, gstate->player->getPlayerStats()->getLevel());
        }
        gstate->popUpTextComponent->addPopUpTextCenter(EXPERIENCE_TAG, exp, "+", " Exp");
    }else if(key == "G_ADD_GOLD"){
        int gold = 1000;
        gstate->player->addGold(gold);
        gstate->updateTabsGoldLbl();
        gstate->popUpTextComponent->addPopUpTextCenter(GOLD_TAG, gold, "+", " Gold");
    }else if(key == "G_UNLOCKFLOORS"){
        while(gstate->floorReached <= 5){
            gstate->floorReached++;
            gstate->notify(AE_FLOOR_REACHED, gstate->floorReached);
            gstate->selectLevelTab->updateButtonsAccess(gstate->floorReached);
        }
    }else if(key == "G_NOCLIP"){
        noclip = !noclip;
        if(noclip){
            gstate->popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG, "Enable Noclip", "", "");
        }else{
            gstate->popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG, "Disable Noclip", "", "");
        }
    }else if(key == "PRINT_P_INV"){
        std::cout << "Player Gold: " << gstate->player->getGold() << std::endl;
        std::cout << gstate->player->getInventory()->listInventory();
    }else if(key == "PRINT_P_EQUIPS"){
        std::cout << gstate->player->toStringEquips();
    }else if(key == "PRINT_P_STATS"){
        std::cout << gstate->player->getPlayerStats()->toString("Player");
    }else if(key == "PRINT_ENEMIES"){
        if(gstate->enemies.empty()){
            std::cout << "No enemies" << std::endl;
        }else{
            for(const auto& i : gstate->enemies){
                std::cout << i->toString();
            }
        }
    }else if(key == "PRINT_LOOTBAGS"){
        if(gstate->lootBags.empty()){
            std::cout << "No lootbags" << std::endl;
        }else{
            for(const auto& i : gstate->lootBags){
                std::cout << i->toString();
            }
        }
    }else if(key.empty()){

    }else{
        gstate->popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG, key, "NO SUCH FUNCTION: ", "");
    }
}

void DebugTool::update(const float &dt, const sf::Vector2f &mousePos) {
    updateInput();
    updateDebugText();
    gstate->updateMousePosition(nullptr);
    if(showMenu){
        for(const auto& i : buttons){
            i.second->update(mousePos);
            if(i.second->isPressed() && gstate->getKeyTime()){
                i.second->setButtonState(BTN_IDLE);
                applyFunctions(i.first);
            }
        }
    }
}

void DebugTool::render(sf::RenderTarget *target) {
    for(const auto& i : gstate->enemies){
        target->draw(&i->getWayPoints()[0], i->getWayPoints().size(), sf::LineStrip);
        sf::Vertex line[] = {{gstate->player->getCollisionBoxCenter(), sf::Color::Red},
                             {i->getCollisionBoxCenter(), sf::Color::Red}};
        target->draw(line, 2, sf::Lines);
        i->getHitboxComponent()->render(*target);
    }
    for(const auto& i : gstate->lootBags){
        sf::Vertex line[] = {{gstate->player->getCollisionBoxCenter(), sf::Color::Green},
                             {i->getCollisionBoxCenter(), sf::Color::Green}};
        target->draw(line, 2, sf::Lines);
        i->getHitboxComponent()->render(*target);
    }
    target->draw(&gstate->player->getWayPoints()[0], gstate->player->getWayPoints().size(), sf::LineStrip);
    gstate->player->getHitboxComponent()->render(*target);

    target->setView(target->getDefaultView());
    target->draw(textLbl);
    if(showMenu){
        target->draw(container);
        for(auto i :buttons)
            i.second->render(*target);
    }
}
