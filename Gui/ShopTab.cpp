//
// Created by Zheng on 19/10/2020.
//

#include "ShopTab.h"

void ShopTab::initShopSlots() {
    //init shop slots
    if(!shopSlots.empty()){
        shopSlots.clear();
    }

    int max_per_row = 6;
    float modifierX = 95.f;
    float modifierY = 120.f;
    float yMultiplier = 0;
    int count = 0;
    for(const auto& i : lootGenerator->getShopList()){
        if((count % max_per_row) == 0 && count != 0){
            yMultiplier ++;
        }
        shopSlots.push_back(std::make_shared<gui::ShopSlot>(80.f, 80.f,
                container.getPosition().x + 35.f + (modifierX * (float)(count % max_per_row)),
                container.getPosition().y + 80.f + (modifierY * yMultiplier), font, i.second, i.first));
        count++;
    }
}

ShopTab::ShopTab(const std::shared_ptr<sf::RenderWindow>& window, sf::Font* font, std::shared_ptr<Player> player, State *state,
                 std::shared_ptr<ResourcesHandler> rsHandler, std::shared_ptr<LootGenerator> lootGenerator,
                 std::map<std::string, sf::Texture> textures) :
                 window(window), font(font), player(std::move(player)),
                 rsHandler(std::move(rsHandler)), lootGenerator(std::move(lootGenerator)), textures(std::move(textures)){
    gState = dynamic_cast<GameState*>(state);

    //init background
    background.setSize(sf::Vector2f(
            static_cast<float>(window->getSize().x),
            static_cast<float>(window->getSize().y)));
    background.setFillColor(sf::Color(20, 20, 20, 100));

    //init container
    container.setSize(sf::Vector2f(625.f,820.f));
    container.setFillColor(sf::Color(20, 20, 20, 200));

    container.setPosition(sf::Vector2f(
            static_cast<float>(window->getSize().x) / 2.f - container.getSize().x / 2.f,
            40.f));
    container.setOutlineThickness(5.f);
    container.setOutlineColor(sf::Color(10, 10, 10));
    //init text
    containerTitle.setFont(*this->font);
    containerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    containerTitle.setCharacterSize(40);
    containerTitle.setString("Shop");
    containerTitle.setPosition(
            container.getPosition().x + (container.getGlobalBounds().width/2.f) - (containerTitle.getGlobalBounds().width/2.f),
            container.getPosition().y + 10.f);

    playerGoldLbl.setFont(*this->font);
    playerGoldLbl.setCharacterSize(30);
    playerGoldLbl.setPosition(container.getPosition().x + 20.f, 750.f);

    playerInvSpaceLbl.setFont(*this->font);
    playerInvSpaceLbl.setCharacterSize(30);
    playerInvSpaceLbl.setPosition(container.getPosition().x + 20.f, 790.f);

    updateGoldLbl();
    updateInvSpaceLbl();

    initShopSlots();
}

ShopTab::~ShopTab() = default;

//functions
void ShopTab::buyItem(const std::string& item_name, const std::string& key, item_usage_type item_usage, const unsigned price) {
    if(player->getGold() >= price){
        if(item_name == "Upgrade Inventory"){
            if(!player->getInventory()->isExpandable()){
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG,
                        "Your inventory cannot be expanded anymore(Limit:" +to_string(Inventory::MAX_SPACE),
                        "", ")");
            } else{
                player->minusGold(price);
                player->getInventory()->expandInventorySpace(5);
                gState->updateTabsGoldLbl();
                gState->updateTabsInvSpaceLbl();
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG,
                        to_string(player->getInventory()->getCurrentMaxSpace()-5)+"->", "Inventory capacity +5 (",
                        to_string(player->getInventory()->getCurrentMaxSpace()));
            }

        } else if(!player->getInventory()->isFull() ||
                (player->getInventory()->hasItemByName(item_name) && item_usage == CONSUMABLE_USAGE)){
            std::shared_ptr<Item> it = std::make_shared<Item>(lootGenerator->getShopList().at(key));
            if(it->getName() == "Mystery Box"){
                std::shared_ptr<Item> new_item = gState->getLootGenerator()->generateTierEquipment(
                        DEFAULT_RARITY, true);
                player->minusGold(price);
                gState->updateTabsGoldLbl();
                gState->addItem(new_item);
                gState->updateTabsInvSpaceLbl();
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, new_item->getName(), "You got [", "]");
            } else if(it->getName() == "Mystery Box(Uncommon)"){
                std::shared_ptr<Item> new_item = gState->getLootGenerator()->generateTierEquipment(
                        UNCOMMON, false);
                player->minusGold(price);
                gState->updateTabsGoldLbl();
                gState->addItem(new_item);
                gState->updateTabsInvSpaceLbl();
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, new_item->getName(), "You got [", "]");
            } else if(it->getName() == "Mystery Box(Common)"){
                std::shared_ptr<Item> new_item = gState->getLootGenerator()->generateTierEquipment(
                        COMMON, false);
                player->minusGold(price);
                gState->updateTabsGoldLbl();
                gState->addItem(new_item);
                gState->updateTabsInvSpaceLbl();
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, new_item->getName(), "You got [", "]");
            } else if(it->getName() == "Mystery Box(Rare)"){
                std::shared_ptr<Item> new_item = gState->getLootGenerator()->generateTierEquipment(
                        RARE, false);
                player->minusGold(price);
                gState->updateTabsGoldLbl();
                gState->addItem(new_item);
                gState->updateTabsInvSpaceLbl();
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, new_item->getName(), "You got [", "]");
            } else if(it->getName() == "Mystery Box(Epic)"){
                std::shared_ptr<Item> new_item = gState->getLootGenerator()->generateTierEquipment(
                        EPIC, false);
                player->minusGold(price);
                gState->updateTabsGoldLbl();
                gState->addItem(new_item);
                gState->updateTabsInvSpaceLbl();
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, new_item->getName(), "You got [", "]");
            } else if(it->getName() == "Mystery Box(Legendary)"){
                std::shared_ptr<Item> new_item = gState->getLootGenerator()->generateTierEquipment(
                        LEGENDARY, false);
                player->minusGold(price);
                gState->updateTabsGoldLbl();
                gState->addItem(new_item);
                gState->updateTabsInvSpaceLbl();
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, new_item->getName(), "You got [", "]");
            } else{
                player->minusGold(price);
                it->setId(rsHandler->generateId());
                gState->addItem(it);
                gState->updateTabsGoldLbl();
                gState->getPopUpTextComponent()->addPopUpTextCenter(DEFAULT_RARITY,"1 "+item_name,
                                                                    "You bought","for "+to_string(price)+" gold");
            }
        } else{
            gState->getPopUpTextComponent()->addPopUpTextCenter(DEFAULT_RARITY,
                                                                "Your inventory is full!", "", "");
        }
    }else{
        gState->getPopUpTextComponent()->addPopUpTextCenter(DEFAULT_RARITY,
                                                            "Insufficient Gold", "", "");
    }
}

bool ShopTab::closeTabByClicking(const sf::Vector2f& mousePos) {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
           background.getGlobalBounds().contains(mousePos)
           && !container.getGlobalBounds().contains(mousePos);
}

void ShopTab::updateGoldLbl() {
    std::stringstream ss;
    std::string gold = to_string(player->getGold());
    unsigned len = gold.length();

    for(int index =(int) len-3; index > 0; index -= 3)
        gold.insert(index, ",");
    ss << "Gold: " << gold;

    playerGoldLbl.setString(ss.str());
}

void ShopTab::updateInvSpaceLbl() {
    std::stringstream ss;
    ss << "Inventory Capacity: " << player->getInventory()->getItemsSize()
       << "/" << player->getInventory()->getCurrentMaxSpace();
    playerInvSpaceLbl.setString(ss.str());
}

void ShopTab::update(const sf::Vector2f &mousePos) {
    updateInputs();
    for(const auto& i : shopSlots){
        i->update(mousePos);
        if(i->isPressed() && gState->getKeyTime()){
            buyItem(i->getItem().getName(), i->getKey(), i->getItem().getUsageType(), i->getPrice());
        }
    }
}

void ShopTab::render(sf::RenderTarget &target) {
    target.draw(background);
    target.draw(container);
    target.draw(containerTitle);
    target.draw(playerInvSpaceLbl);
    target.draw(playerGoldLbl);
    for (auto it = shopSlots.rbegin(); it != shopSlots.rend(); ++it){
        (*it)->render(target);
    }
}

void ShopTab::updateInputs() {
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::E) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) &&
       gState->getKeyTime()){
        gState->changeStato(NO_TAB);
    }
}

const vector<std::shared_ptr<gui::ShopSlot>> &ShopTab::getShopSlots() const {
    return shopSlots;
}








