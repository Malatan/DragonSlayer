//
// Created by Zheng on 22/01/2021.
//

#include "MiniMap.h"

//initializzers
void MiniMap::initGui(sf::Vector2u window_size) {
    minimapBackground.setSize(sf::Vector2f(window_size.x / 4.0f, window_size.y / 4.0f));
    minimapBackground.setPosition(sf::Vector2f((window_size.x / 100.f) * 74, (window_size.y / 100.f) * 1));
    minimapBackground.setOutlineColor(sf::Color::Blue);
    minimapBackground.setOutlineThickness(5.f);
    minimapBackground.setFillColor(sf::Color::Black);
    locationLbl.setFont(*font);
    locationLbl.setCharacterSize(20);
    locationLbl.setFillColor(sf::Color::Blue);
    locationLbl.setPosition(minimapBackground.getPosition().x + 5.f,
                            minimapBackground.getPosition().y + 5.f);

    sf::Vector2f center_down = {minimapBackground.getPosition().x + minimapBackground.getGlobalBounds().width/2.f,
                                minimapBackground.getPosition().y + minimapBackground.getGlobalBounds().height - 5.f};
    hideBtn = new gui::Button(minimapBackground.getPosition().x, center_down.y,
                              50.f, 30.f, font, "Hide", 15, 0);
    zoomInBtn = new gui::Button(hideBtn->getPosition().x + 55.f, hideBtn->getPosition().y,
                                90.f, 30.f, font, "Zoom In", 15, 0);
    zoomOutBtn = new gui::Button(zoomInBtn->getPosition().x + 95.f, zoomInBtn->getPosition().y,
                                 90.f, 30.f, font, "Zoom Out", 15, 0);
    zoomInBtn->setBorderLineThickness(5.f);
    zoomInBtn->setBorderColor(sf::Color::Blue);
    zoomInBtn->setIdleTextColor(sf::Color::Blue);
    zoomOutBtn->setBorderLineThickness(5.f);
    zoomOutBtn->setBorderColor(sf::Color::Blue);
    zoomOutBtn->setIdleTextColor(sf::Color::Blue);
    hideBtn->setBorderLineThickness(5.f);
    hideBtn->setBorderColor(sf::Color::Blue);
    hideBtn->setIdleTextColor(sf::Color::Blue);
}

//Constructor/desctructor
MiniMap::MiniMap(State* state, sf::Font* _font, sf::Vector2u window_size, int _scale) : font(_font), scale(_scale){
    gState = dynamic_cast<GameState*>(state);
    minimapView.setViewport(sf::FloatRect(0.74f, 0.01f, 0.25f, 0.25f));
    initGui(window_size);
}

MiniMap::~MiniMap() {
    delete zoomOutBtn;
    delete zoomInBtn;
    delete hideBtn;
}

//getters
int MiniMap::getZoomFactor() const {
    return zoomFactor;
}

int MiniMap::getMaxZoomFactor() const {
    return maxZoomFactor;
}

int MiniMap::getMinZoomFactor() const {
    return minZoomFactor;
}

int MiniMap::getScale() const {
    return scale;
}

bool MiniMap::isHide() const {
    return hide;
}

//functions
void MiniMap::hideMinimap() {
    hide = !hide;
    if(hide){
        hideBtn->setText("Show");
        hideBtn->setPosition(minimapBackground.getPosition().x + minimapBackground.getGlobalBounds().width -
                                hideBtn->getGlobalBounds().width,
                             minimapBackground.getPosition().y);
    }else{
        hideBtn->setText("Hide");
        hideBtn->setPosition(minimapBackground.getPosition().x,
                             minimapBackground.getPosition().y + minimapBackground.getGlobalBounds().height - 5.f);
    }
}

void MiniMap::updateLocationLbl(int floor) {
    std::stringstream ss;
    switch (floor) {
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
}

void MiniMap::updateValues() {
    if(gState->getCurrentFloor() == 0){
        zoomFactor = 10;
        maxZoomFactor = zoomFactor;
        minZoomFactor = zoomFactor;
    }else{
        zoomFactor = 2;
        maxZoomFactor = 10;
        minZoomFactor = zoomFactor;
    }
    mapWidth = gState->getMap()->getWidth();
    mapHeight = gState->getMap()->getHeight();
    mapWidthP = (int) gState->getMap()->getWidthP() / scale;
    mapHeightP = (int) gState->getMap()->getHeightP() / scale;
    viewSize = {(float)mapWidthP, (float)mapHeightP};
    minimapView.setSize(viewSize * (float)zoomFactor/10.f);
    minimapTexture.create((int)mapWidthP, (int)mapHeightP);
    entitiesTexture.create((int)mapWidthP, (int)mapHeightP);
    minimapView.setCenter(gState->getPlayer()->getCollisionBoxCenter()/(float)scale);
}

void MiniMap::updateView() {
    sf::Vector2f player_pos = gState->getPlayer()->getCollisionBoxCenter()/(float)scale;
    minimapView.setCenter(player_pos);
    sf::Vector2f view_center = minimapView.getCenter();
    sf::Vector2f view_size = minimapView.getSize();
    if(player_pos.y - (view_size.y/2.f) < 0.f){
        view_center.y = view_size.y /2;
    }
    if(player_pos.y + (view_size.y/2.f) > (float)mapHeightP){
        view_center.y = (float)mapHeightP - (view_size.y/2);
    }
    if(player_pos.x - (view_size.x/2.f) < 0.f){
        view_center.x = view_size.x/2;
    }
    if(player_pos.x + (view_size.x/2) > (float)mapWidthP){
        view_center.x = (float)mapWidthP - (view_size.x/2);
    }
    minimapView.setCenter(view_center);
}

void MiniMap::drawTexture(bool update_values) {
    if(update_values)
        updateValues();
    minimapTexture.clear(sf::Color::Transparent);
    auto tiles = gState->getMap()->getTiles();
    float pixel_size = Tile::TILE_SIZE / (float)scale;
    sf::RectangleShape minimap_pixel(sf::Vector2f(pixel_size ,pixel_size));
    for(int y = 0 ; y < mapHeight ; y++) {
        for (int x = 0 ; x < mapWidth ; x++) {
            sf::Vector2f pixep_pos = {(float)x * pixel_size, (float)y * pixel_size};
            switch (tiles[y][x]->GetType()) {
                case WALL: case UPPERWALL: case WALLH: case COLUMNS: case COLUMND: case ROOFL: case ROOFD: case ROOF:
                    minimap_pixel.setFillColor(sf::Color(85, 85, 87));
                    minimap_pixel.setPosition(pixep_pos);
                    minimapTexture.draw(minimap_pixel);
                    break;
                case SHOPH: case CHURCH:
                    minimap_pixel.setFillColor(sf::Color::Magenta);
                    minimap_pixel.setPosition(pixep_pos);
                    minimapTexture.draw(minimap_pixel);
                    break;
                case UPSTAIRS: case DOWNSTAIRS:
                    minimap_pixel.setFillColor(sf::Color::Yellow);
                    minimap_pixel.setPosition(pixep_pos);
                    minimapTexture.draw(minimap_pixel);
                    break;
                case FLOOR:
                    minimap_pixel.setFillColor(sf::Color::White);
                    minimap_pixel.setPosition(pixep_pos);
                    minimapTexture.draw(minimap_pixel);
                    break;
                case VOID:
                    minimap_pixel.setFillColor(sf::Color::Black);
                    minimap_pixel.setPosition(pixep_pos);
                    minimapTexture.draw(minimap_pixel);
                    break;
                case OPENDOOR:
                    minimap_pixel.setFillColor(sf::Color(197, 227, 132));
                    minimap_pixel.setPosition(pixep_pos);
                    minimapTexture.draw(minimap_pixel);
                    break;
                case CLOSEDOOR:
                    minimap_pixel.setFillColor(sf::Color::Red);
                    minimap_pixel.setPosition(pixep_pos);
                    minimapTexture.draw(minimap_pixel);
                    break;
                case GRASS:
                    minimap_pixel.setFillColor(sf::Color(177, 245, 118));
                    minimap_pixel.setPosition(pixep_pos);
                    minimapTexture.draw(minimap_pixel);
                    break;
                case GROUND:
                    minimap_pixel.setFillColor(sf::Color(181, 146, 103));
                    minimap_pixel.setPosition(pixep_pos);
                    minimapTexture.draw(minimap_pixel);
                    break;
                case DOORH:
                    minimap_pixel.setFillColor(sf::Color(59, 44, 16));
                    minimap_pixel.setPosition(pixep_pos);
                    minimapTexture.draw(minimap_pixel);
                    break;
                case TREES:
                    minimap_pixel.setFillColor(sf::Color(25, 115, 36));
                    minimap_pixel.setPosition(pixep_pos);
                    minimapTexture.draw(minimap_pixel);
                    break;
                default:
                    minimap_pixel.setFillColor(sf::Color::Blue);
                    minimap_pixel.setPosition(pixep_pos);
                    minimapTexture.draw(minimap_pixel);
                    break;
            }
        }
    }
    minimapTexture.display();
    minimapSprite.setTexture(minimapTexture.getTexture(), true);
}

void MiniMap::drawEntities() {
    entitiesTexture.clear(sf::Color::Transparent);
    sf::CircleShape entity_pixel{(Tile::TILE_SIZE/(float)scale)/4.f};
    entity_pixel.setOrigin(entity_pixel.getRadius(), entity_pixel.getRadius());

    //draw player
    entity_pixel.setFillColor(sf::Color::Green);
    entity_pixel.setPosition(gState->getPlayer()->getCollisionBoxCenter()/(float)scale);
    entitiesTexture.draw(entity_pixel);

    //draw enemis
    for(const auto& i : gState->getEnemies()){
        entity_pixel.setFillColor(sf::Color::Red);
        entity_pixel.setPosition(i->getCollisionBoxCenter()/(float)scale);
        entitiesTexture.draw(entity_pixel);
    }

    //draw lootbags
    for(const auto& i : gState->getLootBags()){
        entity_pixel.setFillColor(sf::Color(184, 116, 33));
        entity_pixel.setPosition(i->getCollisionBoxCenter()/(float)scale);
        entitiesTexture.draw(entity_pixel);
    }

    //draw npcs
    for(const auto& i : gState->getNpcs()){
        entity_pixel.setFillColor(sf::Color::Cyan);
        entity_pixel.setPosition(i->getCollisionBoxCenter()/(float)scale);
        entitiesTexture.draw(entity_pixel);
    }

    entitiesTexture.display();
    entitiesSprite.setTexture(entitiesTexture.getTexture(), true);
}

void MiniMap::update(const sf::Vector2f& mousePos) {
    hideBtn->update(mousePos);
    if(hide){
        if(hideBtn->isPressed() && gState->getKeyTime()){
            hideBtn->setButtonState(BTN_IDLE);
            hideMinimap();
        }
    }else{
        updateView();
        zoomInBtn->update(mousePos);
        zoomOutBtn->update(mousePos);
        if(zoomInBtn->isPressed() && gState->getKeyTime()){
            zoomInBtn->setButtonState(BTN_IDLE);
            if(zoomFactor > minZoomFactor){
                zoomFactor--;
                minimapView.setSize(viewSize * (float)zoomFactor/10.f);
            }
        }else if(zoomOutBtn->isPressed() && gState->getKeyTime()){
            zoomOutBtn->setButtonState(BTN_IDLE);
            if(zoomFactor < maxZoomFactor){
                zoomFactor++;
                minimapView.setSize(viewSize * (float)zoomFactor/10.f);
            }
        }else if(hideBtn->isPressed() && gState->getKeyTime()){
            hideBtn->setButtonState(BTN_IDLE);
            hideMinimap();
        }
    }
}

void MiniMap::render(sf::RenderTarget *target) {
    if(!hide){
        drawEntities();
        target->draw(minimapBackground);
        target->setView(minimapView);
        target->draw(minimapSprite);
        target->draw(entitiesSprite);
        target->setView(target->getDefaultView());
        target->draw(locationLbl);
        zoomInBtn->render(*target);
        zoomOutBtn->render(*target);
    }else{
        target->setView(target->getDefaultView());
    }
    hideBtn->render(*target);
}




