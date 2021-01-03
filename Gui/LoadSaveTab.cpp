//
// Created by Zheng on 25/12/2020.
//

#include "LoadSaveTab.h"

void LoadSaveTab::initSlots() {
    float x = container.getPosition().x + 10.f;
    float y = containerTitle.getPosition().y + 65.f;
    float mod_y = 120.f;
    for(auto i = 0 ; i < 5 ; i++){
        slots.push_back(std::make_shared<gui::LoadSaveSlot>(x,y + (mod_y * i), 680.f, 100.f, font));
    }
}

//constructors/destructor
LoadSaveTab::LoadSaveTab(const std::shared_ptr<sf::RenderWindow>& window, std::shared_ptr<ResourcesHandler> rs_handler,
                         std::shared_ptr<PopUpTextComponent> popuptext_component, sf::Font* font, State* state)
                         : font(font), state(state), rsHandler(std::move(rs_handler)), popUpTextComponent(std::move(popuptext_component)){
    //init background
    background.setSize(sf::Vector2f(
            static_cast<float>(window->getSize().x),
            static_cast<float>(window->getSize().y)));
    background.setFillColor(sf::Color(20, 20, 20, 100));
    //init container
    container.setSize(sf::Vector2f(700.f,750.f));
    container.setFillColor(sf::Color(50, 50, 50));
    container.setPosition(sf::Vector2f(
            static_cast<float>(window->getSize().x)/2.f - container.getGlobalBounds().width/2.f,
            static_cast<float>(window->getSize().y)/2.f - container.getGlobalBounds().height/2.f
    ));
    container.setOutlineThickness(5.f);
    container.setOutlineColor(sf::Color(10, 10, 10));
    //init text
    containerTitle.setFont(*this->font);
    containerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    containerTitle.setCharacterSize(40);
    containerTitle.setString("Saves");
    containerTitle.setPosition(
            container.getPosition().x + (container.getGlobalBounds().width/2.f) - (containerTitle.getGlobalBounds().width/2.f),
            container.getPosition().y + 10.f);

    backBtn = std::make_unique<gui::Button>(container.getPosition().x + container.getGlobalBounds().width/2.f - 75.f,
                          container.getPosition().y + container.getGlobalBounds().height - 80.f,
                          150.f, 40.f, this->font, "Back", 30);

    loadingLbl.setFont(*this->font);
    loadingLbl.setCharacterSize(50);
    loadingLbl.setString("Loading...");
    loadingLbl.setPosition(container.getPosition().x + container.getGlobalBounds().width/2.f -
                            loadingLbl.getGlobalBounds().width/2.f,
                           container.getPosition().y + container.getGlobalBounds().height/2.f -
                           loadingLbl.getGlobalBounds().height/2.f);

    savesHandler = std::make_unique<SavesHandler>();
    initSlots();
}

LoadSaveTab::~LoadSaveTab() = default;

//accessor
void LoadSaveTab::setState(State *new_state) {
    state = new_state;
}

bool LoadSaveTab::isHide() const {
    return hide;
}

void LoadSaveTab::setHide(bool b) {
    if(!b)
        loading = true;
    hide = b;
}

bool LoadSaveTab::canApplySave() const {
    return applySave;
}

Save *LoadSaveTab::getApplySave() {
    return savesHandler->getSave(beAppliedSaveName);
}

save_load_option LoadSaveTab::getSLOption() const {
    return slOption;
}

//functions
void LoadSaveTab::refresh() {
    std::string path = savesHandler->savePath + "/";
    boost::filesystem::path p(path);
    std::vector<std::string> files;
    if(boost::filesystem::exists(p)){
        for (auto i = boost::filesystem::directory_iterator(p); i != boost::filesystem::directory_iterator(); i++) {
            if(!is_directory(i->path())){
                files.push_back(i->path().stem().string());
                if(files.size() == savesHandler->maxSaves)
                    break;
            }
        }

        if(!files.empty()){
            savesHandler->clear();
            for(const auto& i : files){
                if(savesHandler->read(i)){
                    std::cout << " >>>> LOADED " << savesHandler->getSave(i)->toString();
                }
            }

            int count = 0;
            for(const auto& i : savesHandler->getLoadedSaves()){
                slots[count]->setInfo(i.second.getName(), i.second.getLastModifiedTime());
                slots[count]->setLoadBtnDisabled(false);
                count++;
            }
        }
    }
    for(const auto& i : slots){
        i->setLoadBtnDisabled(i->isEmpty());
    }
    loading = false;
}

std::string LoadSaveTab::generateSaveName() const {
    bool flag = false;
    int count = 1;
    while(!flag){
        std::stringstream ss;
        ss << "save" << std::setfill('0') << std::setw(3) << count;
        std::string s_path = savesHandler->savePath + "/" + ss.str() + ".dat";
        if(!boost::filesystem::exists(s_path)){
            flag = true;
        }else{
            count++;
        }
    }
    std::stringstream ss;
    ss << "save" << std::setfill('0') << std::setw(3) << count;
    return ss.str();
}

void LoadSaveTab::generateSave(const std::shared_ptr<gui::LoadSaveSlot>& s_slot) {
    //genera data modifica
    std::time_t result = std::time(nullptr);
    std::string time_str = std::asctime(std::localtime(&result));
    time_str.pop_back();

    std::string save_name;
    if(!s_slot->isEmpty()){ //overwrite
        save_name = s_slot->getName();
    }else{  // genera nuovo nome
        save_name = generateSaveName();
    }

    Save new_save = Save(save_name, time_str, rsHandler->getGameVersion());
    auto* game_state = dynamic_cast<GameState*>(state);
    new_save.saveRsHandlerInfo(game_state->getResourceHandler());
    new_save.savePlayerInfo(game_state->getPlayer());
    new_save.saveSpellsInfo(game_state->getSpellComponent());
    new_save.saveAchievementsInfo(game_state->getAchievementComponent());
    new_save.saveBuffsInfo(game_state->getBuffComponent());
    new_save.saveMapsInfo(game_state->getMapGenerator(), game_state->getMap(),
                          game_state->getCurrentFloor(), game_state->getReachedFloor());
    if(game_state->getCurrentFloor() != 0){
        new_save.saveEnemiesInfo(game_state->getEnemyCount(true), game_state->getEnemies());
        new_save.saveLootBagsInfo(game_state->getLootBags());
    }

    savesHandler->write(new_save);
    loading = true;
    std::cout << "SAVED <<<< " << new_save.toString();
}

void LoadSaveTab::loadSave(const std::string& save_name) {
    beAppliedSaveName = save_name;
    applySave = true;
    if(state->getStateEnum() == MAINMENU_STATE){
        hide = true;
    }else if(state->getStateEnum() == GAME_STATE){
        state->endState();
    }
}

void LoadSaveTab::endApplySave() {
    applySave = false;
    savesHandler->clear();
}

bool LoadSaveTab::stateMatch(state_enum current_state) const {
    return state->getStateEnum() == current_state;
}

void LoadSaveTab::setAccessOption(save_load_option option) {
    slOption = option;
    switch(option){
        case LOAD_SAVE:{
            for(const auto& i : slots){
                i->setLoadBtnDisabled(true);
                i->setSaveBtnDisabled(false);
            }
            break;
        }
        case SAVE_ONLY:{
            for(const auto& i : slots){
                i->setLoadBtnDisabled(true);
                i->setSaveBtnDisabled(false);
            }
            break;
        }
        case LOAD_ONLY:{
            for(const auto& i : slots){
                i->setLoadBtnDisabled(false);
                i->setSaveBtnDisabled(true);
            }
            break;
        }
        case NO_LOADSAVE:{
            for(const auto& i : slots){
                i->setLoadBtnDisabled(true);
                i->setSaveBtnDisabled(true);
            }
            break;
        }
    }
}

void LoadSaveTab::updateButtons(const sf::Vector2f &mousePos) {
    if(backBtn->isPressed() && state->getKeyTime()){
        hide = true;
    }
    for(const auto& i : slots){
        if(i->saveBtnIsPressed() && state->getKeyTime()){
            i->setSaveBtnDisabled(BTN_IDLE);
            generateSave(i);
        }
        if(i->loadBtnIsPressed() && state->getKeyTime()){
            i->setLoadBtnDisabled(BTN_IDLE);
            loadSave(i->getName());
        }
    }
}

void LoadSaveTab::update(const sf::Vector2f &mousePos) {
    if(loading)
        refresh();
    updateButtons(mousePos);
    backBtn->update(mousePos);
    for(const auto& i : slots)
        i->update(mousePos);
}

void LoadSaveTab::render(sf::RenderTarget &target) {
    target.draw(background);
    target.draw(container);
    target.draw(containerTitle);
    if(!loading){
        backBtn->render(target);
        for(const auto& i : slots)
            i->render(target);
    }else{
        target.draw(loadingLbl);
    }
}
