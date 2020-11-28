//
// Created by Zheng on 19/10/2020.
//

#include "ShopTab.h"

#include <utility>

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
    for(auto i : items){
        if((count % max_per_row) == 0 && count != 0){
            yMultiplier ++;
        }
        shopSlots.push_back(std::make_shared<gui::ShopSlot>(80.f, 80.f,
                container.getPosition().x + 35.f + (modifierX * (count % max_per_row)),
                container.getPosition().y + 80.f + (modifierY * yMultiplier) ,
                i.second->getName(), i.second->getValue(), font, i.second));
        count++;
    }
}

ShopTab::ShopTab(const std::shared_ptr<sf::RenderWindow>& window, sf::Font* font, std::shared_ptr<Player> player, State *state,
                 std::shared_ptr<ResourcesHandler> rsHandler, std::map<std::string, sf::Texture> textures) :
                 window(window), font(font), player(std::move(player)), rsHandler(std::move(rsHandler)), textures(std::move(textures)){
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

    initItemList();
    initShopSlots();
}

ShopTab::~ShopTab() {
    for(const auto& i : items){
        delete i.second;
    }
}

void ShopTab::initItemList() {
    items["HealthPotion(S)"] = new Item("C-potionS", "HealthPotion(S)", "Restore 100 hp",
            50, COMMON, 0, 3,
            0, 0, 0, 0, 0.f, 0.f,
            1, false);
    items["HealthPotion(M)"] = new Item("C-potionM", "HealthPotion(M)", "Restore 200 hp",
                                              100, COMMON, 7, 2,
                                              0, 0, 0, 0, 0.f, 0.f,
                                              1, false);
    items["HealthPotion(L)"] = new Item("C-potionL", "HealthPotion(L)", "Restore 400 hp",
                                              200, COMMON, 7, 3,
                                              0, 0, 0, 0, 0.f, 0.f,
                                              1, false);
    items["ManaPotion(S)"] = new Item("C-potionS", "ManaPotion(S)", "Restore 100 mp",
                                            50, COMMON, 3, 3,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, false);
    items["ManaPotion(M)"] = new Item("C-potionM", "ManaPotion(M)", "Restore 200 mp",
                                            100, COMMON, 10, 2,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, false);
    items["ManaPotion(L)"] = new Item("C-potionL", "ManaPotion(L)", "Restore 400 mp",
                                            200, COMMON, 10, 3,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, false);
    items["UpgradeInventory"] = new Item("Upgrade", "UpgradeInventory", "Gives you extra 5 inventory capacity",
                                            1500, LEGENDARY, 0, 30,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, false);
}


//functions
void ShopTab::buyItem(Item* item, const unsigned price) {
    if(player->getGold() >= price){
        Item* it = new Item(items[item->getName()]);
        if(it->getName() == "UpgradeInventory"){
            if(player->getGold() < it->getValue()){
                gState->getPopUpTextComponent()->addPopUpTextCenter(DEFAULT,
                        "Insufficient Gold","","");
            } else if(!player->getInventory()->isExpandable()){
                gState->getPopUpTextComponent()->addPopUpTextCenter(DEFAULT,
                        "Your inventory cannot be expanded anymore(Limit:" +
                        to_string(Inventory::MAX_SPACE),"",")");
            } else{
                player->minusGold(price);
                player->getInventory()->expandInventorySpace(5);
                gState->updateTabsGoldLbl();
                gState->updateTabsInvSpaceLbl();
                gState->getPopUpTextComponent()->addPopUpTextCenter(DEFAULT,
                        to_string(player->getInventory()->getCurrentMaxSpace()-5)+"->","Inventory capacity +5 (",
                        to_string(player->getInventory()->getCurrentMaxSpace()));
            }

        }else{
            player->minusGold(price);
            gState->addItem(it);
            gState->updateTabsGoldLbl();
            gState->getPopUpTextComponent()->addPopUpTextCenter(DEFAULT,
                    "1 "+item->getName(),"You bought","for "+to_string(price)+" gold");
        }

    }else{
        gState->getPopUpTextComponent()->addPopUpTextCenter(DEFAULT,
                "Insufficient Gold","","");
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
    for(const auto& i : shopSlots){
        i->update(mousePos);
        if(i->isPressed() && gState->getKeyTime()){
            buyItem(i->getItem(), i->getPrice());
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

const vector<std::shared_ptr<gui::ShopSlot>> &ShopTab::getShopSlots() const {
    return shopSlots;
}

std::string ShopTab::toStringShopItems() {
    std::stringstream ss;
    for(auto i : items){
        ss << i.second->listItem() << "\n";
    }
    return ss.str();
}








