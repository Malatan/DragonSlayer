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
namespace gui{
    class ItemSlot;
    class Button;
    class CustomDialog;
    class ProgressBar;
}

class CharacterTab {
public:
    CharacterTab(const std::shared_ptr<sf::RenderWindow>& window, sf::Font* font, std::shared_ptr<Player> player, State* state, map<string,
            sf::Texture> textures, std::shared_ptr<ResourcesHandler> rsHandler, npc_type* npcInteract);
    ~CharacterTab();

    //initializers
    void initStatsContainer();
    void initEquipContainer();
    void initInventoryContainer();
    void initInventorySlots();

    //accessor
    unique_ptr<gui::ItemSlot> * getEquipSlots();
    const vector<std::unique_ptr<gui::ItemSlot>>& getInventorySlots() const;
    GameState *getGState() const;

    //modifiers
    void setSeletecItem(int n);
    bool selectItemById(unsigned int item_id);

    //functions
    std::string playerStatsToString();
    void equipUnequipItem(int equip_slot, const std::shared_ptr<Item>& item, std::unique_ptr<gui::ItemSlot>& i, const std::string& typeIcon);
    void unselectAll();
    void selectAll();
    void statsContainerUpdate(const sf::Vector2f& mousePos);
    void statsContainerRender(sf::RenderTarget& target);
    void equipContainerUpdate(const sf::Vector2f& mousePos);
    void equipContainerRender(sf::RenderTarget& target);
    void invContainerUpdate(const sf::Vector2f& mousePos);
    void invContainerRender(sf::RenderTarget& target);

    void updatePlayerStatsLbl();
    void updateEquipBonusLbl();
    void updateGoldLbl();
    void updateGoldLbls();
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
    std::unique_ptr<gui::ProgressBar> hpBar;
    std::unique_ptr<gui::ProgressBar> mpBar;
    std::unique_ptr<gui::ProgressBar> expBar;

    //stats container
    sf::RectangleShape statsContainer;
    sf::Text statsContainerTitle;
    sf::Text statsName;
    sf::Text statsValue;
    sf::Text attributesHints;
    std::unique_ptr<gui::Button> addStrengthBtn;
    std::unique_ptr<gui::Button> addWisdomBtn;
    std::unique_ptr<gui::Button> addAgilityBtn;

    //equip container
    sf::RectangleShape equipContainer;
    sf::Text equipContainerTitle;
    sf::Text equipBonusLbl;
    std::unique_ptr<gui::ItemSlot> equipSlots[6];

    //inventory container
    std::vector<sf::RectangleShape> inventorySlotsBackgrounds;
    std::vector<std::unique_ptr<gui::ItemSlot>> inventorySlots;
    sf::RectangleShape inventoryContainer;
    sf::Text invContainerTitle;
    sf::Text selectedNumberLbl;
    sf::Text goldLbl;
    sf::Text inventorySpaceLbl;
    sf::Text keysHintLbl;
    std::unique_ptr<gui::Button> EquipUnEquipBtn;
    std::unique_ptr<gui::Button> deleteBtn;
    std::unique_ptr<gui::Button> sellBtn;
    std::unique_ptr<gui::Button> selectAllBtn;
};


#endif //DRAGONSLAYER_CHARACTERTAB_H
