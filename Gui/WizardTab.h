//
// Created by Zheng on 24/10/2020.
//

#ifndef DRAGONSLAYER_WIZARDTAB_H
#define DRAGONSLAYER_WIZARDTAB_H

#include "SpellTab.h"

namespace gui{
    class WizardSpellSlot;
}

class WizardTab {
public:
    //constructors/destructor
    WizardTab(const std::shared_ptr<sf::RenderWindow>& window, sf::Font* font, std::shared_ptr<Player> player, State *state,
            std::map<std::string, sf::Texture> textures);
    ~WizardTab();

    void initWizardSpellSlots();

    //functions
    void updateSpellLevel(const std::shared_ptr<gui::WizardSpellSlot>& spellSlot);
    void updateSpellInfo();
    bool closeTabByClicking(const sf::Vector2f& mousePos);
    void updateGoldLbl();
    void updatePageLbl();
    void updateInputs();
    void updateButtons(const sf::Vector2f& mousePos);
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);

private:
    int currentPage{};
    int maxPage{};
    sf::Text pageLbl;
    std::unique_ptr<gui::Button> nextPageBtn;
    std::unique_ptr<gui::Button> previousPageBtn;

    sf::RectangleShape background;
    sf::RectangleShape container;
    sf::Text containerTitle;
    sf::Text playerGoldLbl;

    std::shared_ptr<sf::RenderWindow> window;
    sf::Font* font;
    std::map<std::string, sf::Texture> textures;
    std::shared_ptr<Player> player;
    GameState* gState;
    std::shared_ptr<SpellComponent> spellComponent;

    std::vector<std::shared_ptr<gui::WizardSpellSlot>> spellSlots;
};


#endif //DRAGONSLAYER_WIZARDTAB_H
