//
// Created by Zheng on 21/01/2021.
//

#include "DebugTool.h"

//initializers
void DebugTool::addButton(const std::string& btn_key, const std::string& text) {
    float _x = 450.f;
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
    addButton("G_ADD_EXP", "ADD 1000 EXP");
    addButton("G_ADD_GOLD", "ADD 10000 GOLD");
    addButton("G_STATSBOOST", "STATS BOOST");
    addButton("G_UNLOCKFLOORS", "UNLOCK FLOORS");
    addButton("G_NOCLIP", "NOCLIP");
    addButton("G_TPTOSPAWN", "TP TO SPAWN");
    addButton("G_REDRAWMINIMAP", "REDRAW MINIMAP");
    addButton("R_RELOADSHADER", "RELOAD SHADER");
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
    noclip = false;
    debug = false;
    for(const auto& i : buttons)
        delete i.second;
}

//functions
void DebugTool::updateDebugText() {
    sf::Vector2f vv = gstate->player->getMovementComponent()->getVelocity();
    sf::Vector2f vd = gstate->player->getMovementComponent()->getDirection();
    std::stringstream ss;
    ss << "<F11> Open Debug Menu" << std::endl
       << "<Home> Close Debugtool" << std::endl
       << "Pos x: " << gstate->mousePosView.x << " Pos y: " << gstate->mousePosView.y << std::endl
       << "Grid x: " << (int)(gstate->mousePosView.x/Tile::TILE_SIZE)
       << " Grid y: " << (int)(gstate->mousePosView.y/Tile::TILE_SIZE) << std::endl
       << "Enemies: " << gstate->enemies.size() << " Lootbags: " << gstate->lootBags.size() << std::endl
       << "Nodes[x]: " << gstate->pathFinder->widthN << " Nodes[y]: " << gstate->pathFinder->heightN
       << " Nodes: " << gstate->pathFinder->nodesN << std::endl
       << "Dx: " << vd.x << std::endl << "Dy: " << vd.y << std::endl
       << "Vx: " << vv.x << std::endl << "Vy: " << vv.y << std::endl
       << "Minimap zoom factor: " << gstate->minimap->getZoomFactor()
       << " [" << gstate->minimap->getMinZoomFactor() << " - " << gstate->minimap->getMaxZoomFactor() << "]" << std::endl
       << "Scale: " << gstate->minimap->getScale()
       << " Hide: " << std::boolalpha << gstate->minimap->isHide() << std::endl
       << "PathFinding called per second: " << gstate->pathFinder->counts << std::endl;
    textLbl.setString(ss.str());
}

void DebugTool::updateInput() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F11) && gstate->getKeyTime()){
        showMenu = !showMenu;
    }
}

void DebugTool::applyFunctions(const string &key) {
    if(key == "G_ADD_EXP"){
        int exp = 1000;
        if(gstate->player->getPlayerStats()->addExp(exp)){
            gstate->updateTabsPlayerStatsLbl();
            gstate->notify(AE_P_LEVEL, gstate->player->getPlayerStats()->getLevel());
        }
        gstate->popUpTextComponent->addPopUpTextCenter(EXPERIENCE_TAG, exp, "+", " Exp");
    }else if(key == "G_ADD_GOLD"){
        int gold = 10000;
        gstate->player->addGold(gold);
        gstate->updateTabsGoldLbl();
        gstate->popUpTextComponent->addPopUpTextCenter(GOLD_TAG, gold, "+", " Gold");
    }else if(key == "G_STATSBOOST"){
        int boost_quantity = 1000;
        gstate->player->getPlayerStats()->addAttribute(STRENGTH, boost_quantity, false);
        gstate->player->getPlayerStats()->addAttribute(WISDOM, boost_quantity, false);
        gstate->player->getPlayerStats()->addAttribute(AGILITY, boost_quantity, false);
        gstate->updateTabsPlayerStatsLbl(NO_TAB);
        gstate->popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG, boost_quantity,
                                                       "+", " STRENGTH, WISDOM AND AGILITY");
    }else if(key == "G_UNLOCKFLOORS"){
        while(gstate->floorReached < 5){
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
    }else if(key == "G_TPTOSPAWN"){
        gstate->player->setPosition(gstate->spawnPos.x, gstate->spawnPos.y);
    }else if(key == "G_REDRAWMINIMAP"){
        gstate->minimap->drawTexture();
    }else if(key == "R_RELOADSHADER"){
        gstate->initShader();
        gstate->popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG, "SHADER RELOADED", "", "");
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

void DebugTool::renderPlayerDebugInfo(sf::RenderTarget *target) {
    target->draw(&gstate->player->getWayPoints()[0], gstate->player->getWayPoints().size(), sf::LineStrip);
    gstate->player->getHitboxComponent()->render(*target);
}

void DebugTool::renderEnemisDebugInfo(sf::RenderTarget *target) {
    for(const auto& i : gstate->enemies){
        target->draw(&i->getWayPoints()[0], i->getWayPoints().size(), sf::LineStrip);

        sf::Vertex line[] = {{gstate->player->getCollisionBoxCenter(), sf::Color::Red},
                             {i->getCollisionBoxCenter(), sf::Color::Red}};
        target->draw(line, 2, sf::Lines);

        sf::Vertex line2[] = {{i->getSpawnPos(), sf::Color::Magenta},
                             {i->getCollisionBoxCenter(), sf::Color::Magenta}};
        target->draw(line2, 2, sf::Lines);

        i->getHitboxComponent()->render(*target);

        sf::Text ai_stato;
        ai_stato.setFont(*font);
        ai_stato.setCharacterSize(15);
        ai_stato.setString(i->toStringDebug());
        ai_stato.setPosition(i->getPosition().x, i->getPosition().y - 25.f);
        target->draw(ai_stato);
    }
}

void DebugTool::renderLootBagsDebugInfo(sf::RenderTarget *target) {
    for(const auto& i : gstate->lootBags){
        sf::Vertex line[] = {{gstate->player->getCollisionBoxCenter(), sf::Color::Green},
                             {i->getCollisionBoxCenter(), sf::Color::Green}};
        target->draw(line, 2, sf::Lines);
        i->getHitboxComponent()->render(*target);
    }
}

void DebugTool::renderMapDebugInfo(sf::RenderTarget *target) {
    auto tiles = gstate->map->getTiles();
    for (int y = gstate->map->getFromY(); y < gstate->map->getToY(); y++) {
        for (int x = gstate->map->getFromX(); x < gstate->map->getToX(); x++) {
            sf::Text tile_type;
            tile_type.setFont(*font);
            tile_type.setCharacterSize(20);
            tile_type.setString(to_string(tiles[y][x]->GetType()));
            tile_type.setPosition((float)x * Tile::TILE_SIZE, (float)y * Tile::TILE_SIZE);
            target->draw(tile_type);
        }
    }
}

void DebugTool::render(sf::RenderTarget *target) {
    renderEnemisDebugInfo(target);
    renderLootBagsDebugInfo(target);
    renderMapDebugInfo(target);
    renderPlayerDebugInfo(target);
    target->setView(target->getDefaultView());
    target->draw(textLbl);
    if(showMenu){
        target->draw(container);
        for(auto i :buttons)
            i.second->render(*target);
    }
}
