//
// Created by Zheng on 25/12/2020.
//

#ifndef DRAGONSLAYER_LOADSAVETAB_H
#define DRAGONSLAYER_LOADSAVETAB_H

#include "Gui.h"
#include "SavesHandler.h"
#include <dirent.h>
#include <iomanip>

class PopUpTextComponent;
class SavesHandler;
class Save;

namespace gui{
    class LoadSaveSlot;
}

enum save_load_option{
    LOAD_SAVE,
    SAVE_ONLY,
    LOAD_ONLY,
    NO_LOADSAVE
};

class LoadSaveTab {
public:
    //constructors/destructor
    LoadSaveTab(const std::shared_ptr<sf::RenderWindow>& window, std::shared_ptr<ResourcesHandler> rs_handler,
                std::shared_ptr<PopUpTextComponent> popuptext_component, sf::Font* font, State* state);
    ~LoadSaveTab();

    //accessor
    bool canApplySave() const;
    void setState(State* new_state);
    bool isHide() const;
    void setHide(bool b);
    Save* getApplySave();
    save_load_option getSLOption() const;
    void setGameScreen(const sf::Image &game_screen);

    //functions
    void refresh();
    std::string generateSaveName() const;
    void generateSave(const std::shared_ptr<gui::LoadSaveSlot>& s_slot);
    void loadSave(const std::string& save_name);
    bool stateMatch(state_enum current_state) const;
    void endApplySave();
    void setAccessOption(save_load_option option);
    void updateButtons(const sf::Vector2f& mousePos);
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);

private:
    sf::Image gameScreen;
    bool hide{};
    bool loading{};
    bool applySave{};
    save_load_option slOption{};
    std::string beAppliedSaveName{};
    State* state;
    sf::Font* font;
    sf::RectangleShape background;
    sf::RectangleShape container;
    sf::Text containerTitle;
    std::unique_ptr<gui::Button> backBtn;
    std::vector<std::shared_ptr<gui::LoadSaveSlot>> slots;
    std::unique_ptr<SavesHandler> savesHandler;
    std::shared_ptr<ResourcesHandler> rsHandler;
    std::shared_ptr<PopUpTextComponent> popUpTextComponent;

    //loading gui
    sf::Text loadingLbl;

    void initSlots();
};


#endif //DRAGONSLAYER_LOADSAVETAB_H
