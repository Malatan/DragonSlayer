//
// Created by Zheng on 08/10/2020.
//

#ifndef DRAGONSLAYER_CHARACTERTAB_H
#define DRAGONSLAYER_CHARACTERTAB_H

#include "Gui.h"
#include "../Game/Player.h"
#include "../Core/GameState.h"
#include "../Game/Npc.h"

class GameState;

class CharacterTab {
public:
    CharacterTab(const std::shared_ptr<sf::RenderWindow>& window, sf::Font* font, std::shared_ptr<Player> player, State* state, map<string,
            sf::Texture> textures, std::shared_ptr<ResourcesHandler> rsHandler, npc_type* npcInteract);
    virtual ~CharacterTab();

    //initializers
    void initStatsContainer();
    void initEquipContainer();
    void initInventoryContainer();
    void initInventorySlots();

    //accessor
    unique_ptr<gui::ItemSlot> * getEquipSlots();
    const vector<std::unique_ptr<gui::ItemSlot>>& getInventorySlots() const;
    GameState *getGState() const;

    //functions
    std::string playerStatsToString();

    void equipUnequipItem(int equip_slot, const std::shared_ptr<Item>& item, std::unique_ptr<gui::ItemSlot>& i, const std::string& typeIcon);
    void unselectAll();
    void statsContainerUpdate(const sf::Vector2f& mousePos);
    void statsContainerRender(sf::RenderTarget& target);
    void equipContainerUpdate(const sf::Vector2f& mousePos);
    void equipContainerRender(sf::RenderTarget& target);
    void invContainerUpdate(const sf::Vector2f& mousePos);
    void invContainerRender(sf::RenderTarget& target);

    void updatePlayerStatsLbl();
    void updateEquipBonusLbl();
    void updateGoldLbl();
    void updateInventoryCapLbl();
    void deleteItemFromInventory();
    void deleteConsumableInBattle(const std::shared_ptr<Item>& item);
    bool closeCharacterTabByClicking(const sf::Vector2f& mousePos, gui::Button* cTab_Btn);
    void updateButtons();
    void equipUnEquipBtnFunction();
    void useConsumable(const std::shared_ptr<Item>& item, std::unique_ptr<gui::ItemSlot>& i);
    void deleteBtnFunction();
    void sellBtnFunction();
    void processDialogResult();
    void updateMouseInput();
    void updateKeyboardInput();
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);

private:
    std::shared_ptr<ResourcesHandler> rsHandler;
    std::shared_ptr<sf::RenderWindow> window;
    sf::Font* font;
    std::shared_ptr<Player> player;
    GameState* gState;
    State* state;
    std::unique_ptr<gui::CustomDialog> sellDeleteDialog;
    int selectedItem;
    bool openDialog;
    npc_type* npcInteract;
    std::map<std::string, sf::Texture> textures;

    //container
    sf::RectangleShape backgorund;
    sf::RectangleShape container;
    sf::Text tabText;
    sf::Text hpBarLbl;
    sf::Text mpBarLbl;
    sf::Text expBarLbl;
    gui::ProgressBar hpBar;
    gui::ProgressBar mpBar;
    gui::ProgressBar expBar;

    //stats container
    sf::RectangleShape statsContainer;
    sf::Text statsContainerTitle;
    sf::Text statsName;
    sf::Text statsValue;
    sf::Text attributesHints;
    gui::Button addStrengthBtn;
    gui::Button addWisdomBtn;
    gui::Button addAgilityBtn;

    //equip container
    sf::RectangleShape equipContainer;
    sf::Text equipContainerTitle;
    sf::Text equipBonusLbl;
    std::unique_ptr<gui::ItemSlot> equipSlots[6];

    //inventory container
    std::vector<std::unique_ptr<gui::ItemSlot>> inventorySlots;
    sf::RectangleShape inventoryContainer;
    sf::Text invContainerTitle;
    sf::Text selectedNumberLbl;
    sf::Text goldLbl;
    sf::Text inventorySpaceLbl;
    sf::Text keysHintLbl;
    gui::Button EquipUnEquipBtn;
    gui::Button deleteBtn;
    gui::Button sellBtn;
};


#endif //DRAGONSLAYER_CHARACTERTAB_H
