//
// Created by Zheng on 20/12/2020.
//

#ifndef DRAGONSLAYER_ACHIEVEMENTTAB_H
#define DRAGONSLAYER_ACHIEVEMENTTAB_H

#include "CharacterTab.h"

class GameState;
class AchievementComponent;

class AchievementTab {
public:
    AchievementTab(const std::shared_ptr<sf::RenderWindow>& window, sf::Font* font, State *state,
                   std::shared_ptr<AchievementComponent> achievementComponent);
    virtual ~AchievementTab();

    bool closeTabByClicking(const sf::Vector2f& mousePos, gui::Button* achievementTab_Btn);
    void updateAchievementsSlots(bool achieved = false);
    void updateInputs();
    void updateTextLbl();
    void updatePageLbl();
    void updateButtons();
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);

private:
    sf::RectangleShape background;
    sf::RectangleShape container;
    sf::Text containerTitle;
    sf::Text textLbl;
    sf::Text pageLbl;
    gui::Button nextPageBtn;
    gui::Button previousPageBtn;
    int currentPage{1};
    int maxPage{1};

    sf::Font* font;
    GameState* gState;
    std::shared_ptr<sf::RenderWindow> window;
    std::map<std::string, sf::Texture> textures;
    std::shared_ptr<ResourcesHandler> rsHandler;
    std::shared_ptr<AchievementComponent> achievementComponent;
    std::vector<std::unique_ptr<gui::AchievementSlot>> achievementsSlots;

    void initAchievementsSlots();
};


#endif //DRAGONSLAYER_ACHIEVEMENTTAB_H
