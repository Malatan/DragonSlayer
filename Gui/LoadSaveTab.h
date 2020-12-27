//
// Created by Zheng on 25/12/2020.
//

#ifndef DRAGONSLAYER_LOADSAVETAB_H
#define DRAGONSLAYER_LOADSAVETAB_H

#include "Gui.h"
#include "SavesHandler.h"

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
    LoadSaveTab(const std::shared_ptr<sf::RenderWindow>& window, std::shared_ptr<ResourcesHandler> rs_handler, sf::Font* font,
                State* state);
    virtual ~LoadSaveTab();

    //accessor
    void setState(State* new_state);
    bool isHide() const;
    void setHide(bool b);

    //functions
    void generateSave();
    void loadSave();
    void setAccessOption(save_load_option option);
    void updateButtons(const sf::Vector2f& mousePos);
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);

private:
    bool hide{};
    State* state;
    sf::Font* font;
    sf::RectangleShape background;
    sf::RectangleShape container;
    sf::Text containerTitle;
    std::unique_ptr<gui::Button> backBtn;
    std::vector<std::shared_ptr<gui::LoadSaveSlot>> slots;
    std::shared_ptr<ResourcesHandler> rsHandler;
    void initSlots();
};


#endif //DRAGONSLAYER_LOADSAVETAB_H
