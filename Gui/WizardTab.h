//
// Created by Zheng on 24/10/2020.
//

#ifndef DRAGONSLAYER_WIZARDTAB_H
#define DRAGONSLAYER_WIZARDTAB_H

#include "SpellTab.h"


class WizardTab {
private:
    sf::RectangleShape background;
    sf::RectangleShape container;
    sf::Text containerTitle;
    sf::Text playerGoldLbl;

    sf::RenderWindow* window;
    sf::Font* font;
    std::map<std::string, sf::Texture> textures;
    Player* player;
    GameState* gState;
    SpellComponent* spellComponent;

    std::vector<gui::WizardSpellSlot*> spellSlots;
protected:

public:
    //constructors/destructor
    WizardTab(sf::RenderWindow* window, sf::Font* font, Player* player,
            State *state, std::map<std::string, sf::Texture> textures);
    virtual ~WizardTab();

    void initWizardSpellSlots();

    //functions
    void updateSpellLevel(gui::WizardSpellSlot* spellSlot);
    void updateSpellInfo();
    bool closeTabByClicking(const sf::Vector2f& mousePos);
    void updateGoldLbl();
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);
};


#endif //DRAGONSLAYER_WIZARDTAB_H
