//
// Created by Zheng on 19/10/2020.
//

#ifndef DRAGONSLAYER_SHOPTAB_H
#define DRAGONSLAYER_SHOPTAB_H

#include "CharacterTab.h"

class ShopTab {
private:
    sf::RectangleShape background;
    sf::RectangleShape container;
    sf::Text containerTitle;
    sf::Text playerGoldLbl;
    sf::Text playerInvSpaceLbl;
    sf::RenderWindow* window;
    sf::Font* font;
    std::map<std::string, sf::Texture> textures;

    ResourcesHandler* rsHandler;
    Player* player;
    State* state;

    std::map<std::string, Item*> items;
    std::vector<gui::ShopSlot*> shopSlots;


protected:

public:
    ShopTab(sf::RenderWindow* window, sf::Font* font, Player* player, State *state, ResourcesHandler* rsHandler,
            std::map<std::string, sf::Texture> textures);
    virtual ~ShopTab();

    void initItemList();
    void initShopSlots();

    const vector<gui::ShopSlot *> &getShopSlots() const;
    std::string toStringShopItems();
    //functions
    void buyItem(Item* item, const unsigned price);
    bool closeTabByClicking(const sf::Vector2f& mousePos);
    void updateGoldLbl();
    void updateInvSpaceLbl();
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);

};


#endif //DRAGONSLAYER_SHOPTAB_H
