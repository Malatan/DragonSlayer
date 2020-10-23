//
// Created by Zheng on 23/10/2020.
//

#ifndef DRAGONSLAYER_SPELLTAB_H
#define DRAGONSLAYER_SPELLTAB_H

#include "CharacterTab.h"
#include <iomanip>

class GameState;

class SpellTab {
private:
    sf::RectangleShape background;
    sf::RectangleShape container;
    sf::Text containerTitle;
    sfe::RichText infoLbl;

    sf::RenderWindow* window;
    sf::Font* font;
    std::map<std::string, sf::Texture> textures;

    ResourcesHandler* rsHandler;
    Player* player;
    GameState* gState;
    SpellComponent* spellComponent;

    std::vector<gui::SpellSlot*> spellSlots;
    std::string dmgMultiplier;
protected:

public:
    SpellTab(sf::RenderWindow* window, sf::Font* font, Player* player, State *state, ResourcesHandler* rsHandler,
    std::map<std::string, sf::Texture> textures);
    virtual ~SpellTab();

    void initSpellSlots();

    bool closeTabByClicking(const sf::Vector2f& mousePos, gui::Button* spellTab_Btn);

    void updateSpellsInfoLbl();
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);
};


#endif //DRAGONSLAYER_SPELLTAB_H
