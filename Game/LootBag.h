//
// Created by Administrator on 08/12/2020.
//

#ifndef DRAGONSLAYER_LOOTBAG_H
#define DRAGONSLAYER_LOOTBAG_H

#include "Entity.h"
#include "Item.h"
#include "../Core/GameState.h"
#include "../Gui/Gui.h"

class GameState;

typedef std::pair<int, int> lifeTimePair;

class LootBag : public Entity  {
public:
    //constructors/destructor
    LootBag(const std::shared_ptr<sf::RenderWindow>& window, sf::Vector2f position, std::map<std::string, sf::Texture> textures,
            std::shared_ptr<Player> player, State* state, std::vector<shared_ptr<Item>> loots, sf::Font* font,
            int life_time_s, unsigned int id);
    ~LootBag() override;

    //getters && setters
    unsigned int getId() const;
    void canInteract(bool b);
    bool isExpired() const;

    //functions
    bool lootItem(const std::shared_ptr<Item>& loot_item);
    void lootAllItem();
    void sortByItemType();
    void updateLifeTime(const float &dt);
    void updateLifeTimeLbl();
    void updateButtons();
    void updatePage(const sf::Vector2f& mousePos);
    void renderPage(sf::RenderTarget& target);
    void setPosition(float x, float y) override;
    void update(const float& dt) override;
    void render(sf::RenderTarget& target, bool show_hitbox);

private:
    unsigned int id{};
    float msCounter{};
    bool expired{};
    bool interact{};
    lifeTimePair lifeTime;
    GameState* gState;
    std::shared_ptr<Player> player;
    std::vector<shared_ptr<Item>> loots;
    std::map<std::string, sf::Texture> textures;

    sf::Font* font;
    sf::Text textLbl;
    sf::Text lifeTimeLbl;
    sf::RectangleShape interactIcon;

    sf::Text containerTitleLbl;
    sf::RectangleShape background;
    sf::RectangleShape container;
    std::vector<std::unique_ptr<gui::LootSlot>> lootSlots;
    gui::Button lootAllBtn;
    gui::Button cancelBtn;

    //initializzers
    void initLootContainer(sf::Vector2f window_size);
    void initLootSlots();
};


#endif //DRAGONSLAYER_LOOTBAG_H
