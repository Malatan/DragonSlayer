//
// Created by Zheng on 19/10/2020.
//

#ifndef DRAGONSLAYER_SHOPTAB_H
#define DRAGONSLAYER_SHOPTAB_H

#include "CharacterTab.h"

class GameState;

class ShopTab {
public:
    ShopTab(const std::shared_ptr<sf::RenderWindow>& window, sf::Font* font, std::shared_ptr<Player> player, State *state,
            std::shared_ptr<ResourcesHandler> rsHandler, std::shared_ptr<LootGenerator> lootGenerator,
            std::map<std::string, sf::Texture> textures);
    virtual ~ShopTab();

    void initShopSlots();

    const vector<std::shared_ptr<gui::ShopSlot>> &getShopSlots() const;
    //functions
    void buyItem(const std::string& item_name, const std::string& key,
                 item_usage_type item_usage, const unsigned price);
    bool closeTabByClicking(const sf::Vector2f& mousePos);
    void updateGoldLbl();
    void updateInvSpaceLbl();
    void updateInputs();
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);

private:
    sf::RectangleShape background;
    sf::RectangleShape container;
    sf::Text containerTitle;
    sf::Text playerGoldLbl;
    sf::Text playerInvSpaceLbl;

    std::shared_ptr<sf::RenderWindow> window;
    sf::Font* font;
    std::map<std::string, sf::Texture> textures;
    std::shared_ptr<ResourcesHandler> rsHandler;
    std::shared_ptr<Player> player;
    GameState* gState;
    std::shared_ptr<LootGenerator> lootGenerator;

    std::vector<std::shared_ptr<gui::ShopSlot>> shopSlots;
};


#endif //DRAGONSLAYER_SHOPTAB_H
