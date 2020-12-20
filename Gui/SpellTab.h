//
// Created by Zheng on 23/10/2020.
//

#ifndef DRAGONSLAYER_SPELLTAB_H
#define DRAGONSLAYER_SPELLTAB_H

#include "CharacterTab.h"
#include <iomanip>

class GameState;

class SpellTab {
public:
    SpellTab(const std::shared_ptr<sf::RenderWindow>& window, sf::Font* font, std::shared_ptr<Player> player, State *state,
             std::shared_ptr<ResourcesHandler> rsHandler, std::map<std::string, sf::Texture> textures);
    virtual ~SpellTab();

    void initSpellSlots();

    bool closeTabByClicking(const sf::Vector2f& mousePos, gui::Button* spellTab_Btn);
    void updateInputs();
    void updateSpellsInfoLbl();
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);

private:
    sf::RectangleShape background;
    sf::RectangleShape container;
    sf::Text containerTitle;
    sfe::RichText infoLbl;

    std::shared_ptr<sf::RenderWindow> window;
    sf::Font* font;
    std::map<std::string, sf::Texture> textures;

    std::shared_ptr<ResourcesHandler> rsHandler;
    std::shared_ptr<Player> player;
    GameState* gState;
    std::shared_ptr<SpellComponent> spellComponent;

    std::vector<std::shared_ptr<gui::SpellSlot>> spellSlots;
    std::string dmgMultiplier;
};


#endif //DRAGONSLAYER_SPELLTAB_H
