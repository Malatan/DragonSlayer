//
// Created by Zheng on 19/10/2020.
//

#include "ShopTab.h"

void ShopTab::initShopSlots() {
    //init shop slots
    if(this->shopSlots.size() != 0){
        this->shopSlots.clear();
    }

    int max_per_row = 6;
    float modifierX = 95.f;
    float modifierY = 120.f;
    float yMultiplier = 0;
    int count = 0;
    for(auto i : this->items){
        if((count % max_per_row) == 0 && count != 0){
            yMultiplier ++;
        }
        this->shopSlots.push_back(new gui::ShopSlot(80.f, 80.f,
                this->container.getPosition().x + 35.f + (modifierX * (count % max_per_row)),
                this->container.getPosition().y + 80.f + (modifierY * yMultiplier) ,
                i.second->getName(), i.second->getValue(), this->font, i.second));
        count++;
    }
}

ShopTab::ShopTab(sf::RenderWindow *window, sf::Font *font, Player *player, State *state, ResourcesHandler *rsHandler,
                 std::map<std::string, sf::Texture> textures) : window(window), font(font), player(player),
                 state(state), rsHandler(rsHandler), textures(textures){
    //init background
    this->background.setSize(sf::Vector2f(
            static_cast<float>(window->getSize().x),
            static_cast<float>(window->getSize().y)));
    this->background.setFillColor(sf::Color(20, 20, 20, 100));

    //init container
    this->container.setSize(sf::Vector2f(625.f,820.f));
    this->container.setFillColor(sf::Color(20, 20, 20, 200));

    this->container.setPosition(sf::Vector2f(
            static_cast<float>(window->getSize().x) / 2.f - this->container.getSize().x / 2.f,
            40.f));

    //init text
    this->containerTitle.setFont(*this->font);
    this->containerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    this->containerTitle.setCharacterSize(40);
    this->containerTitle.setString("Shop");
    this->containerTitle.setPosition(
            this->container.getPosition().x + (this->container.getGlobalBounds().width/2.f) - (this->containerTitle.getGlobalBounds().width/2.f),
            this->container.getPosition().y + 10.f);

    this->playerGoldLbl.setFont(*this->font);
    this->playerGoldLbl.setCharacterSize(30);
    this->playerGoldLbl.setPosition(this->container.getPosition().x + 20.f, 750.f);

    this->playerInvSpaceLbl.setFont(*this->font);
    this->playerInvSpaceLbl.setCharacterSize(30);
    this->playerInvSpaceLbl.setPosition(this->container.getPosition().x + 20.f, 790.f);

    this->updateGoldLbl();
    this->updateInvSpaceLbl();

    this->initItemList();
    this->initShopSlots();
}

ShopTab::~ShopTab() {
    for(auto i : this->items){
        delete i.second;
    }

    for(auto i : this->shopSlots){
        delete i;
    }
}

void ShopTab::initItemList() {
    this->items["HealthPotion(S)"] = new Item("C-potionS", "HealthPotion(S)", "Restore 100 hp",
            50, "Common", 0, 3,
            0, 0, 0, 0, 0.f, 0.f,
            1, false);
    this->items["HealthPotion(M)"] = new Item("C-potionM", "HealthPotion(M)", "Restore 200 hp",
                                              100, "Common", 7, 2,
                                              0, 0, 0, 0, 0.f, 0.f,
                                              1, false);
    this->items["HealthPotion(L)"] = new Item("C-potionL", "HealthPotion(L)", "Restore 400 hp",
                                              200, "Common", 7, 3,
                                              0, 0, 0, 0, 0.f, 0.f,
                                              1, false);
    this->items["ManaPotion(S)"] = new Item("C-potionS", "ManaPotion(S)", "Restore 100 mp",
                                            50, "Common", 3, 3,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, false);
    this->items["ManaPotion(M)"] = new Item("C-potionM", "ManaPotion(M)", "Restore 200 mp",
                                            100, "Common", 10, 2,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, false);
    this->items["ManaPotion(L)"] = new Item("C-potionL", "ManaPotion(L)", "Restore 400 mp",
                                            200, "Common", 10, 3,
                                            0, 0, 0, 0, 0.f, 0.f,
                                            1, false);
}


//functions
void ShopTab::buyItem(Item* item, const unsigned price) {
    if(this->player->getGold() >= price){
        GameState* gs = dynamic_cast<GameState*>(this->state);
        this->player->minusGold(price);

        Item* it = new Item(this->items[item->getName()]);
        gs->addItem(it);

        gs->updateTabsGoldLbl();
        this->state->getPopUpTextComponent()->addPopUpTextCenter(DEFAULT,
                "1 "+item->getName(),"You bought","for "+to_string(price)+" gold");
    }else{
        this->state->getPopUpTextComponent()->addPopUpTextCenter(DEFAULT,
                "Insufficient Gold","","");
    }
}

bool ShopTab::closeTabByClicking(const sf::Vector2f& mousePos) {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
       this->background.getGlobalBounds().contains(mousePos)
       && !this->container.getGlobalBounds().contains(mousePos)){
        return true;
    }
    return false;
}

void ShopTab::updateGoldLbl() {
    std::stringstream ss;
    std::string gold = to_string(this->player->getGold());
    unsigned len = gold.length();

    for(int index =(int) len-3; index > 0; index -= 3)
        gold.insert(index, ",");
    ss << "Gold: " << gold;

    this->playerGoldLbl.setString(ss.str());
}

void ShopTab::updateInvSpaceLbl() {
    std::stringstream ss;
    ss << "Inventory Capacity: " << this->player->getInventory()->getItemsSize()
       << "/" << this->player->getInventory()->getCurrentMaxSpace();
    this->playerInvSpaceLbl.setString(ss.str());
}

void ShopTab::update(const sf::Vector2f &mousePos) {
    for(auto i : this->shopSlots){
        i->update(mousePos);
        if(i->isPressed() && this->state->getKeyTime()){
            this->buyItem(i->getItem(), i->getPrice());
        }
    }
}

void ShopTab::render(sf::RenderTarget &target) {
    target.draw(this->background);
    target.draw(this->container);
    target.draw(this->containerTitle);
    target.draw(this->playerInvSpaceLbl);
    target.draw(this->playerGoldLbl);
    for(auto i : this->shopSlots){
        i->render(target);
    }
}

const vector<gui::ShopSlot *> &ShopTab::getShopSlots() const {
    return this->shopSlots;
}

std::string ShopTab::toStringShopItems() {
    std::stringstream ss;
    for(auto i : this->items){
        ss << i.second->listItem() << "\n";
    }
    return ss.str();
}








