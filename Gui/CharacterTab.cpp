//
// Created by Zheng on 08/10/2020.
//

#include "CharacterTab.h"

//initializers

void CharacterTab::initStatsContainer() {
//containere per le statistiche
    this->statsContainer.setFillColor(sf::Color(50, 50, 50, 100));
    this->statsContainer.setSize(sf::Vector2f(((this->container.getGlobalBounds().width - 60.f) / 3.f) - 120.f, 720.f));
    this->statsContainer.setPosition(this->container.getPosition().x + 20.f,
                                          this->container.getPosition().y + 60.f);

    this->statsContainerTitle.setString("-Stats-");
    this->statsContainerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    this->statsContainerTitle.setFont(*this->font);
    this->statsContainerTitle.setCharacterSize(27);
    this->statsContainerTitle.setPosition(this->statsContainer.getPosition().x + this->statsContainer.getGlobalBounds().width/2.f
            - this->statsContainerTitle.getGlobalBounds().width/2.f,
            this->statsContainer.getPosition().y);


    this->statsName.setString("Level:\n"
                              "Exp:\n"
                              "Max Hp:\n"
                              "Max Mp:\n"
                              "Damage:\n"
                              "Armor:\n"
                              "Critical Chance:\n"
                              "Evade Chance:\n"
                              "\n\n\n"
                              "Strength:\n"
                              "Wisdom:\n"
                              "Agility:\n"
                              "Available Points:\n");
    this->statsName.setFillColor(sf::Color(255, 255, 255, 200));
    this->statsName.setFont(*this->font);
    this->statsName.setCharacterSize(21);
    this->statsName.setPosition(this->statsContainer.getPosition().x + 10.f,
                                this->statsContainer.getPosition().y + 50.f);

    this->statsValue.setString(this->playerStatsToString());
    this->statsValue.setFont(*this->font);
    this->statsValue.setCharacterSize(21);
    this->statsValue.setPosition(this->statsContainer.getPosition().x + 160.f,
                                 this->statsContainer.getPosition().y + 50.f);

    this->attributesHints.setString("Hints:\n"
                                    "Strength: increases your hp and\n"
                                    "   armor\n"
                                    "Wisdom: increases your mp\n"
                                    "Agility: increases your evade and\n"
                                    "   critical chance\n");
    this->attributesHints.setFont(*this->font);
    this->attributesHints.setCharacterSize(20);
    this->attributesHints.setPosition(this->statsContainer.getPosition().x + 10.f,
                                      this->statsContainer.getPosition().y + 500.f);

    //add attributes btns
    float btnSide = 17.f;
    this->addStrengthBtn = new gui::Button(
            this->statsValue.getPosition().x + 60.f, this->statsValue.getPosition().y + 268.f, btnSide, btnSide,
            this->font, "+", 48.f,
            sf::Color(200, 200, 200, 200),
            sf::Color(250, 250, 250, 250),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(20, 20, 20, 0));

    this->addWisdomBtn = new gui::Button(
            this->statsValue.getPosition().x + 60.f, this->statsValue.getPosition().y + 294.f, btnSide, btnSide,
            this->font, "+", 48.f,
            sf::Color(200, 200, 200, 200),
            sf::Color(250, 250, 250, 250),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(20, 20, 20, 0));

    this->addAgilityBtn = new gui::Button(
            this->statsValue.getPosition().x + 60.f, this->statsValue.getPosition().y + 320.f, btnSide, btnSide,
            this->font, "+", 48.f,
            sf::Color(200, 200, 200, 200),
            sf::Color(250, 250, 250, 250),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(20, 20, 20, 0));

    this->addStrengthBtn->setTextPositionAddY(-22.f);
    this->addWisdomBtn->setTextPositionAddY(-22.f);
    this->addAgilityBtn->setTextPositionAddY(-22.f);
}

void CharacterTab::initEquipContainer() {
    this->equipContainer.setFillColor(sf::Color(70, 70, 70, 100));
    this->equipContainer.setSize(sf::Vector2f(190.f, this->statsContainer.getGlobalBounds().height));
    this->equipContainer.setPosition(this->statsContainer.getPosition().x + this->statsContainer.getGlobalBounds().width + 10.f,
                                     this->container.getPosition().y + 60.f);

    this->equipContainerTitle.setString("-Equipment-");
    this->equipContainerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    this->equipContainerTitle.setFont(*this->font);
    this->equipContainerTitle.setCharacterSize(27);
    this->equipContainerTitle.setPosition(this->equipContainer.getPosition().x + this->equipContainer.getGlobalBounds().width/2.f
                                          - this->equipContainerTitle.getGlobalBounds().width/2.f,
                                          this->equipContainer.getPosition().y);

    this->equipBonusLbl.setString("Equip Effects:\n");
    this->equipBonusLbl.setFont(*this->font);
    this->equipBonusLbl.setCharacterSize(18);
    this->equipBonusLbl.setPosition(this->equipContainer.getPosition().x + 10.f,
                                    this->equipContainer.getPosition().y + 320.f);

    float posX = 15.f;
    float posY = 40.f;
    float slotSize = 70.f;

    this->equipSlots[5] = new gui::ItemSlot(
            this->equipContainer.getPosition().x + posX,
            this->equipContainer.getPosition().y + posY,
            slotSize, slotSize, 5, this->window, this->font, nullptr, this->gState, true
    );
    this->equipSlots[4] = new gui::ItemSlot(
            this->equipContainer.getPosition().x + posX + 90.f,
            this->equipContainer.getPosition().y + posY, slotSize,
            slotSize, 4, this->window, this->font, nullptr, this->gState, true
    );
    this->equipSlots[3] = new gui::ItemSlot(
            this->equipContainer.getPosition().x + posX,
            this->equipContainer.getPosition().y + posY + 90.f,
            slotSize, slotSize, 3, this->window, this->font, nullptr, this->gState, true
    );
    this->equipSlots[2] = new gui::ItemSlot(
            this->equipContainer.getPosition().x + posX + 90.f,
            this->equipContainer.getPosition().y + posY + 90.f,
            slotSize, slotSize, 2, this->window, this->font, nullptr, this->gState, true
    );
    this->equipSlots[1] = new gui::ItemSlot(
            this->equipContainer.getPosition().x + posX,
            this->equipContainer.getPosition().y + posY + 180.f,
            slotSize, slotSize, 1, this->window, this->font, nullptr, this->gState, true
    );
    this->equipSlots[0] = new gui::ItemSlot(
            this->equipContainer.getPosition().x + posX + 90.f,
            this->equipContainer.getPosition().y + posY + 180.f,
            slotSize, slotSize, 0, this->window, this->font, nullptr, this->gState, true
    );


}

void CharacterTab::initInventoryContainer() {
    this->inventoryContainer.setFillColor(sf::Color(90, 90, 90, 100));
    this->inventoryContainer.setSize(sf::Vector2f(this->container.getGlobalBounds().width - 60.f
    -this->statsContainer.getGlobalBounds().width -this->equipContainer.getGlobalBounds().width
            , this->statsContainer.getGlobalBounds().height));
    this->inventoryContainer.setPosition(this->equipContainer.getPosition().x + this->equipContainer.getGlobalBounds().width + 10.f,
            this->equipContainer.getPosition().y );

    this->invContainerTitle.setString("-Inventory-");
    this->invContainerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    this->invContainerTitle.setFont(*this->font);
    this->invContainerTitle.setCharacterSize(27);
    this->invContainerTitle.setPosition(this->inventoryContainer.getPosition().x + this->inventoryContainer.getGlobalBounds().width/2.f
                                        - this->invContainerTitle.getGlobalBounds().width/2.f,
                                        this->inventoryContainer.getPosition().y);

    this->selectedNumberLbl.setFont(*this->font);
    this->selectedNumberLbl.setCharacterSize(15);
    this->selectedNumberLbl.setString("Items selected: ");
    this->selectedNumberLbl.setPosition(this->inventoryContainer.getPosition().x + 20.f,
            this->inventoryContainer.getPosition().y + 30.f);

    this->initInventorySlots();

    this->sellBtn = new gui::Button(
            this->inventoryContainer.getPosition().x + 340.f,
            this->inventoryContainer.getPosition().y + 580.f, 180.f, 40.f,
            this->font, "Sell items", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    this->sellBtn->setBorderColor(sf::Color::White);
    this->sellBtn->setBorderLineThickness(5.f);
    this->sellBtn->setTooltipDisabled(false);
    this->sellBtn->setTooltipText("You must be near a Npc for selling items");

    this->EquipUnEquipBtn = new gui::Button(
            this->inventoryContainer.getPosition().x + 540.f,
            this->inventoryContainer.getPosition().y + 580.f, 180.f, 40.f,
            this->font, "Equip/Unequip/Use", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    this->EquipUnEquipBtn->setBorderColor(sf::Color::White);
    this->EquipUnEquipBtn->setBorderLineThickness(5.f);

    this->deleteBtn = new gui::Button(
            this->inventoryContainer.getPosition().x + 540.f,
            this->inventoryContainer.getPosition().y + 640.f, 180.f, 40.f,
            this->font, "Delete items", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    this->deleteBtn->setBorderColor(sf::Color::White);
    this->deleteBtn->setBorderLineThickness(5.f);

    this->goldLbl.setFont(*this->font);
    this->goldLbl.setCharacterSize(20);
    this->goldLbl.setString("Inventory Capacity:");
    this->goldLbl.setPosition(this->inventoryContainer.getPosition().x + 40.f,
                              this->EquipUnEquipBtn->getPosition().y);

    this->inventorySpaceLbl.setFont(*this->font);
    this->inventorySpaceLbl.setCharacterSize(20);
    this->inventorySpaceLbl.setString("Gold:");
    this->inventorySpaceLbl.setPosition(this->goldLbl.getPosition().x,
                                        this->goldLbl.getPosition().y + 30.f);

    this->keysHintLbl.setFont(*this->font);
    this->keysHintLbl.setCharacterSize(20);
    this->keysHintLbl.setString("Hints: \n"
                                "<R> equip/unequip/use selected item\n"
                                "<Del> delete selected items");
    this->keysHintLbl.setPosition(this->goldLbl.getPosition().x,
                                  this->inventorySpaceLbl.getPosition().y + 30.f);
}

void CharacterTab::initInventorySlots() {
    //init inventory slots
    if(this->inventorySlots.size() != 0){
        this->inventorySlots.clear();
    }

    int max_per_row = 10;
    float modifierX = 70.f;
    float modifierY = 70.f;
    float yMultiplier = 0;
    for(int i = 0 ; i < this->player->getInventory()->getItemsSize() ; i++){
        if((i % max_per_row) == 0 && i != 0){
            yMultiplier ++;
        }
        this->inventorySlots.push_back(new gui::ItemSlot(
                this->inventoryContainer.getPosition().x + 36.f + (modifierX * (i % max_per_row)),
                this->inventoryContainer.getPosition().y + 70.f + (modifierY * yMultiplier) ,
                60.f, 60.f, 6+i, this->window, this->font, this->player->getInventory()->getItem(i),
                this->gState, false
        ));
    }
}

CharacterTab::CharacterTab(sf::RenderWindow* window, sf::Font* font, Player* player, State* state,
        map<string, sf::Texture> textures, ResourcesHandler* rsHandler, npc_type* npcInteract) :
font(font), player(player), window(window), textures(textures), rsHandler(rsHandler), npcInteract(npcInteract)
{
    this->openDialog = false;
    this->confirmDialog = nullptr;
    this->gState = dynamic_cast<GameState*>(state);
    //init background
    this->backgorund.setSize(sf::Vector2f(
            static_cast<float>(window->getSize().x),
            static_cast<float>(window->getSize().y)));
    this->backgorund.setFillColor(sf::Color(20, 20, 20, 100));
    this->updateSlot = (int *) malloc(sizeof(int));
    *this->updateSlot = 100;


    //initi container
    this->container.setSize(sf::Vector2f(
            static_cast<float>(window->getSize().x / 1.1f),
            static_cast<float>(window->getSize().y - 100.f )));
    this->container.setFillColor(sf::Color(20, 20, 20, 200));

    this->container.setPosition(sf::Vector2f(
            static_cast<float>(window->getSize().x) / 2.f - this->container.getSize().x / 2.f,
            40.f));

    //init text
    this->tabText.setFont(*this->font);
    this->tabText.setFillColor(sf::Color(255, 255, 255, 200));
    this->tabText.setCharacterSize(30);
    this->tabText.setString("Character Tab");
    this->tabText.setPosition(
            this->container.getPosition().x + 20.f,
            this->container.getPosition().y + 10.f);

    this->hpBarLbl.setCharacterSize(20);
    this->hpBarLbl.setFont(*this->font);
    this->hpBarLbl.setString("Hp:");
    this->hpBarLbl.setPosition(
            this->tabText.getPosition().x + 300.f,
            this->tabText.getPosition().y + 10.f);

    this->hpBar = new gui::ProgressBar(window, this->hpBarLbl.getPosition().x + 35.f, this->tabText.getPosition().y + 10.f, 150.f, 25.f,
                                       0, this->player->getPlayerStats()->getMaxHp(), this->player->getPlayerStats()->getHp(), font);
    this->hpBar->setProgressShapeColor(sf::Color::Red);

    this->mpBarLbl.setCharacterSize(20);
    this->mpBarLbl.setFont(*this->font);
    this->mpBarLbl.setString("Mp:");
    this->mpBarLbl.setPosition(
            this->hpBarLbl.getPosition().x + 230.f,
            this->tabText.getPosition().y + 10.f);

    this->mpBar = new gui::ProgressBar(window, this->mpBarLbl.getPosition().x + 35.f, this->tabText.getPosition().y + 10.f, 150.f, 25.f,
                                       0, this->player->getPlayerStats()->getMaxMp(), this->player->getPlayerStats()->getMp(), font);
    this->mpBar->setProgressShapeColor(sf::Color::Blue);

    this->expBarLbl.setCharacterSize(20);
    this->expBarLbl.setFont(*this->font);
    this->expBarLbl.setString("Exp:");
    this->expBarLbl.setPosition(
            this->mpBarLbl.getPosition().x + 230.f,
            this->tabText.getPosition().y + 10.f);

    this->expBar = new gui::ProgressBar(window, this->expBarLbl.getPosition().x + 35.f, this->tabText.getPosition().y + 10.f, 150.f, 25.f,
                                       0, this->player->getPlayerStats()->getMaxExp(), this->player->getPlayerStats()->getExp(), font);
    this->expBar->setProgressShapeColor(sf::Color::Green);


    this->initStatsContainer();
    this->initEquipContainer();
    this->initInventoryContainer();
    this->updateGoldLbl();
    this->updateInventoryCapLbl();
}

CharacterTab::~CharacterTab() {
    delete this->addStrengthBtn;
    delete this->addWisdomBtn;
    delete this->addAgilityBtn;
    delete this->EquipUnEquipBtn;
    delete this->deleteBtn;
    delete this->sellBtn;
    delete this->hpBar;
    delete this->mpBar;
    delete this->expBar;
    delete this->confirmDialog;
    for(auto i : this->equipSlots)
        delete i;
    for(auto i : this->inventorySlots)
        delete i;
}

//accessor

gui::ItemSlot** CharacterTab::getEquipSlots() {
    return this->equipSlots;
}

//functions
std::string CharacterTab::playerStatsToString() {
    std::stringstream ss;
    ss << this->player->getPlayerStats()->getLevel()  << "\n"
            <<this->player->getPlayerStats()->getExp() <<"/" << this->player->getPlayerStats()->getMaxExp() << "\n"
            <<this->player->getPlayerStats()->getFinalHp() << "\n"
            <<this->player->getPlayerStats()->getFinalMp() << "\n"
            <<this->player->getPlayerStats()->getFinalDamage() << "\n"
            <<this->player->getPlayerStats()->getFinalArmor() << "\n"
            <<this->player->getPlayerStats()->getFinalCritChance() << "%\n"
            <<this->player->getPlayerStats()->getFinalEvadeChance() << "%\n\n\n\n"
            <<this->player->getPlayerStats()->getStrength() << "\n"
            <<this->player->getPlayerStats()->getWisdom() << "\n"
            <<this->player->getPlayerStats()->getAgility() << "\n"
            <<this->player->getPlayerStats()->getFreePoints() << "\n";
    return ss.str();
}

void CharacterTab::unselectAll() {
    for(auto i : this->inventorySlots){
        i->setSelectedBool(false);
    }
}

void CharacterTab::statsContainerUpdate(const sf::Vector2f& mousePos) {
    this->statsValue.setString(this->playerStatsToString());
    if(this->player->getPlayerStats()->getFreePoints() > 0) {
        this->addStrengthBtn->update(mousePos);
        this->addWisdomBtn->update(mousePos);
        this->addAgilityBtn->update(mousePos);
    }
}

void CharacterTab::statsContainerRender(sf::RenderTarget &target) {
    target.draw(this->statsContainer);
    target.draw(this->statsContainerTitle);
    target.draw(this->statsName);
    target.draw(this->statsValue);
    target.draw(this->attributesHints);
    if(this->player->getPlayerStats()->getFreePoints() > 0) {
        this->addStrengthBtn->render(target);
        this->addWisdomBtn->render(target);
        this->addAgilityBtn->render(target);
    }
}

void CharacterTab::equipContainerUpdate(const sf::Vector2f &mousePos) {

    for(auto i : this->equipSlots){
        if(*this->updateSlot < 6 || *this->updateSlot == 100){
            if(*this->updateSlot != 100) {
                this->equipSlots[*this->updateSlot]->update(mousePos, this->updateSlot, false);
            }
            else if(*this->updateSlot){
                i->update(mousePos, this->updateSlot, false);
            }
        }
    }
}

void CharacterTab::equipContainerRender(sf::RenderTarget &target) {
    target.draw(this->equipContainer);
    target.draw(this->equipContainerTitle);
    target.draw(this->equipBonusLbl);
    for(auto i : this->equipSlots){
        i->render(target);
    }
}

void CharacterTab::updateGoldLbl() {
    std::stringstream ss;
    std::string gold = to_string(this->player->getGold());
    unsigned len = gold.length();

    for(int index =(int) len-3; index > 0; index -= 3)
        gold.insert(index, ",");
    ss << "Gold: " << gold;

    this->goldLbl.setString(ss.str());
}

void CharacterTab::updateInventoryCapLbl() {
    std::stringstream ss;
    ss << "Inventory Capacity: " << this->player->getInventory()->getItemsSize()
       << "/" << this->player->getInventory()->getCurrentMaxSpace();
    this->inventorySpaceLbl.setString(ss.str());
}

void CharacterTab::invContainerUpdate(const sf::Vector2f &mousePos) {
    this->selectedItem = 0;
    std::stringstream ss;
    for(auto i : this->inventorySlots){
        if(i->getIsSelected())
            this->selectedItem++;
        if(*this->updateSlot > 5){
            if(*this->updateSlot != 100 && *this->updateSlot > 5) {
                this->inventorySlots[(*this->updateSlot - 6)]->update(mousePos, this->updateSlot, true);
            }
            else{
                i->update(mousePos, this->updateSlot, true);
            }
        }
    }
    ss << "Items selected: " << this->selectedItem;
    this->selectedNumberLbl.setString(ss.str());

    if(this->selectedItem != 0){
        this->deleteBtn->setDisabled(false);
    }else{
        this->deleteBtn->setDisabled(true);
    }
    if(this->selectedItem == 1){
        this->EquipUnEquipBtn->setDisabled(false);
    } else{
        this->EquipUnEquipBtn->setDisabled(true);
    }

    if(this->selectedItem != 0 && *this->npcInteract != NO_NPC){
        this->sellBtn->setDisabled(false);
    }else{
        this->sellBtn->setDisabled(true);
    }

    this->EquipUnEquipBtn->update(mousePos);
    this->deleteBtn->update(mousePos);
    this->sellBtn->update(mousePos);
}

void CharacterTab::invContainerRender(sf::RenderTarget &target) {
    target.draw(this->inventoryContainer);
    target.draw(this->invContainerTitle);
    target.draw(this->selectedNumberLbl);
    target.draw(this->goldLbl);
    target.draw(this->inventorySpaceLbl);
    target.draw(this->keysHintLbl);
    this->EquipUnEquipBtn->render(target);
    this->deleteBtn->render(target);
    this->sellBtn->render(target);
 /*   for(auto i : this->inventorySlots){
        i->render(target);
    }*/
    for (auto it = this->inventorySlots.rbegin(); it != this->inventorySlots.rend(); it++){
        (*it)->render(target);
    }
}

bool CharacterTab::closeCharacterTabByClicking(const sf::Vector2f& mousePos, gui::Button* cTab_Btn) {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            this->backgorund.getGlobalBounds().contains(mousePos)
       && !this->container.getGlobalBounds().contains(mousePos) && !cTab_Btn->contains(mousePos)){
        return true;
    }
    return false;
}

void CharacterTab::equipUnequipItem(int equip_slot, Item *item, gui::ItemSlot* i, std::string typeIcon) {
    if(!item->isEquipped() && !this->player->isSlotEquipped(equip_slot)){ // equip item
        this->player->setEquipItem(item, equip_slot);
        this->equipSlots[equip_slot]->setItem(item);
        this->equipSlots[equip_slot]->updateItemInfo();
        this->equipSlots[equip_slot]->setShapeTexture(i->getShape()->getTexture(),
                                                      i->getIntRect());
        this->equipSlots[equip_slot]->getShape()->setOutlineColor(i->getShape()->getOutlineColor());
        item->setEquipped(true);
        i->setUpRightTexture(&this->textures[typeIcon]);
        i->setSelectedBool(false);

    } else if(item->isEquipped() && this->player->isSlotEquipped(equip_slot)){ // unequip item
        this->player->unequipItem(equip_slot);
        this->equipSlots[equip_slot]->setItem(nullptr);
        this->equipSlots[equip_slot]->setSlotTexture(&this->textures["EquipSlotsSheet"],
                this->rsHandler->getEquipSlotTextureRect(equip_slot));
        this->equipSlots[equip_slot]->getShape()->setOutlineColor(sf::Color::Transparent);
        item->setEquipped(false);
        i->setSelectedBool(false);

    } else if(!item->isEquipped() && this->player->isSlotEquipped(equip_slot)){ // unequip then equip
        this->player->unequipItem(equip_slot);
        this->equipSlots[equip_slot]->setItem(nullptr);
        this->equipSlots[equip_slot]->setSlotTexture(&this->textures["EquipSlotsSheet"],
                this->rsHandler->getEquipSlotTextureRect(equip_slot));
        this->equipSlots[equip_slot]->getShape()->setOutlineColor(sf::Color::Transparent);
        item->setEquipped(false);

        this->player->setEquipItem(item, equip_slot);
        this->equipSlots[equip_slot]->setItem(item);
        this->equipSlots[equip_slot]->updateItemInfo();
        this->equipSlots[equip_slot]->setShapeTexture(i->getShape()->getTexture(),
                                                      i->getIntRect());
        this->equipSlots[equip_slot]->getShape()->setOutlineColor(i->getShape()->getOutlineColor());
        item->setEquipped(true);
        i->setUpRightTexture(&this->textures[typeIcon]);
        i->setSelectedBool(false);

    }
    this->updateEquipBonusLbl();
}

void CharacterTab::useConsumable(Item* item, gui::ItemSlot* i) {
    bool have_more = true;

    if(item->getQuantity() > 0 && item->getUsageType() == 6){
        have_more = item->use();
        this->gState->getBuffComponent()->applyItemBuff(item->getName(), this->player->getPlayerStats());
        i->updateQuantityLbl();
    }

    if(!have_more){
        this->deleteItemFromInventory();
    }
}

void CharacterTab::equipUnEquipBtnFunction() {
    bool flag = false;
    for(auto i : this->inventorySlots){
        if(i->getIsSelected()){
            Item* item = this->player->getInventory()->getItem(i->getItem()->getName());
            switch(i->getItem()->getUsageType()){
                case 5:
                    this->equipUnequipItem(5, item, i, "WEAPON_ICON");
                    break;
                case 4:
                    this->equipUnequipItem(4, item, i, "SHIELD_ICON");
                    break;
                case 3:
                    this->equipUnequipItem(3, item, i, "HELMET_ICON");
                    break;
                case 2:
                    this->equipUnequipItem(2, item, i, "ARMOR_ICON");
                    break;
                case 1:
                    this->equipUnequipItem(1, item, i, "GLOVES_ICON");
                    break;
                case 0:
                    this->equipUnequipItem(0, item, i, "BOOTS_ICON");
                    break;
                case 6:
                    this->useConsumable(item, i);
                    break;
                default:
                    break;
            }
            flag = true;
        }
        if(flag)
            break;
    }
}

void CharacterTab::deleteBtnFunction() {
    std::stringstream ss;
    ss << "Are you sure you want to delete selected " << this->selectedItem << " items?";
    this->confirmDialog = new gui::ConfirmDialog(this->container.getPosition().x + (this->container.getGlobalBounds().width / 2.f) - 250.f,
            this->container.getPosition().y + (this->container.getGlobalBounds().height / 2.f) - 125.f,
            ss.str(), this->window, this->gState, this->font, 25.f, DELETE_CONFIRM);
    this->openDialog = true;
}

void CharacterTab::sellBtnFunction() {
    std::stringstream ss;
    int totValue = 0;
    for(auto i : this->inventorySlots) {
        if (i->getIsSelected()) {
            totValue += i->getItem()->getQuantity() * i->getItem()->getValue();
        }
    }
    ss << "Selling selected " << this->selectedItem << " items for " << totValue << " gold";

    this->confirmDialog = new gui::ConfirmDialog(this->container.getPosition().x + (this->container.getGlobalBounds().width / 2.f) - 250.f,
            this->container.getPosition().y + (this->container.getGlobalBounds().height / 2.f) - 125.f,
            ss.str(), this->window, this->gState, this->font, 25.f, SELL_CONFIRM);
    this->confirmDialog->setSellValue(totValue);
    this->openDialog = true;
}

void CharacterTab::updateButtons() {
    if(this->addStrengthBtn->isPressed() && this->gState->getKeyTime()){
        this->addStrengthBtn->setButtonState(BTN_IDLE);
        if(this->player->getPlayerStats()->getFreePoints() > 0){
            this->player->getPlayerStats()->addAttribute(0);
        }
    } else if(this->addWisdomBtn->isPressed() && this->gState->getKeyTime()){
        this->addWisdomBtn->setButtonState(BTN_IDLE);
        if(this->player->getPlayerStats()->getFreePoints() > 0){
            this->player->getPlayerStats()->addAttribute(1);
        }
    } else if(this->addAgilityBtn->isPressed() && this->gState->getKeyTime()){
        this->addAgilityBtn->setButtonState(BTN_IDLE);
        if(this->player->getPlayerStats()->getFreePoints() > 0){
            this->player->getPlayerStats()->addAttribute(2);
        }
    } else if(this->EquipUnEquipBtn->isPressed() && this->gState->getKeyTime()) {
        this->EquipUnEquipBtn->setButtonState(BTN_IDLE);
        this->equipUnEquipBtnFunction();
    } else if(this->deleteBtn->isPressed() && this->gState->getKeyTime()) {
        this->deleteBtn->setButtonState(BTN_IDLE);
        this->deleteBtnFunction();
    } else if(this->sellBtn->isPressed() && this->gState->getKeyTime()) {
        this->sellBtn->setButtonState(BTN_IDLE);
        this->sellBtnFunction();
    }
}

void CharacterTab::updateKeyboardInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && this->gState->getKeyTime()) {
        // equip / unequip
        if(this->selectedItem == 1){
            this->equipUnEquipBtnFunction();
        }
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Delete) && this->gState->getKeyTime()) {
        // equip / unequip
        if(this->selectedItem > 0){
            this->deleteBtnFunction();
        }
    }
}

void CharacterTab::update(const sf::Vector2f& mousePos) {
    this->updateButtons();
    this->updateKeyboardInput();

    if(!this->openDialog){
        this->statsContainerUpdate(mousePos);
        this->equipContainerUpdate(mousePos);
        this->invContainerUpdate(mousePos);

        this->hpBar->update(this->player->getPlayerStats()->getHp(), this->player->getPlayerStats()->getFinalHp());
        this->mpBar->update(this->player->getPlayerStats()->getMp(), this->player->getPlayerStats()->getFinalMp());
        this->expBar->update(this->player->getPlayerStats()->getExp(), this->player->getPlayerStats()->getMaxExp());
    } else if(this->openDialog){
        if(this->confirmDialog->update(mousePos, &this->openDialog) == 1){
            switch(this->confirmDialog->getDialogType()){
                case DELETE_CONFIRM:{
                    int seletected = this->selectedItem;
                    this->deleteItemFromInventory();
                    this->gState->getPopUpTextComponent()->addPopUpTextCenter(
                            DEFAULT_TAG, to_string(seletected), "You deleted", "items from your inventory");
                    break;
                }

                case SELL_CONFIRM:{
                    this->deleteItemFromInventory();
                    this->player->addGold(this->confirmDialog->getSellValue());
                    this->gState->updateTabsGoldLbl();
                    this->gState->getPopUpTextComponent()->addPopUpTextCenter(
                            GOLD_TAG, to_string(this->confirmDialog->getSellValue()),
                            "+", " gold");
                    break;
                }
            }

        }else if(this->confirmDialog->update(mousePos, &this->openDialog) == 0){
            delete this->confirmDialog;
        }
    }
}

void CharacterTab::render(sf::RenderTarget &target) {
    target.draw(this->backgorund);
    target.draw(this->container);
    target.draw(this->tabText);

    target.draw(this->hpBarLbl);
    this->hpBar->render(target);
    target.draw(this->mpBarLbl);
    this->mpBar->render(target);
    target.draw(this->expBarLbl);
    this->expBar->render(target);

    this->statsContainerRender(target);
    this->invContainerRender(target);
    this->equipContainerRender(target);

    if(this->openDialog){
        this->confirmDialog->render(target);
    }
}

const vector<gui::ItemSlot *> &CharacterTab::getInventorySlots() const {
    return this->inventorySlots;
}

void CharacterTab::updateEquipBonusLbl() {
    int dmgBonus = 0;
    int armorBonus = 0;
    int hpBonus = 0;
    int mpBonus = 0;
    float critChanceBonus = 0;
    float evadeChanceBonus = 0;
    for(int i = 0 ; i < 6 ; i++){
        if(this->player->isSlotEquipped(i)){
            hpBonus += this->player->getEquippedItem(i)->getHp();
            mpBonus += this->player->getEquippedItem(i)->getMp();
            dmgBonus += this->player->getEquippedItem(i)->getDamage();
            armorBonus += this->player->getEquippedItem(i)->getArmor();
            critChanceBonus += this->player->getEquippedItem(i)->getCritChance();
            evadeChanceBonus += this->player->getEquippedItem(i)->getEvadeChance();
        }
    }
    std::stringstream ss;
    ss << "Equip Effects: \n";
    if(hpBonus != 0)
        ss << " + " << hpBonus << " hp\n";
    if(mpBonus != 0)
        ss << " + " << mpBonus << " mp\n";
    if(dmgBonus != 0)
        ss << " + " << dmgBonus << " dmg\n";
    if(armorBonus != 0)
        ss << " + " << armorBonus << " armor\n";
    if(critChanceBonus != 0)
        ss << " + " << critChanceBonus << " % critical chance\n";
    if(evadeChanceBonus != 0)
        ss << " + " << evadeChanceBonus << " % evade chance\n";

    this->equipBonusLbl.setString(ss.str());

    this->player->setBonusStats(hpBonus, mpBonus, dmgBonus, armorBonus, critChanceBonus, evadeChanceBonus);
}

void CharacterTab::deleteItemFromInventory() {
    for(auto i : this->inventorySlots){
        if(i->getIsSelected()){
            if(i->getItem()->isEquipped()){
                int equip_slot = i->getItem()->getUsageType();
                this->player->unequipItem(equip_slot);
                this->equipSlots[equip_slot]->setItem(nullptr);
                this->equipSlots[equip_slot]->setSlotTexture(&this->textures["EquipSlotsSheet"],
                        this->rsHandler->getEquipSlotTextureRect(equip_slot));
                this->equipSlots[equip_slot]->getShape()->setOutlineColor(sf::Color::Transparent);
            }
            this->player->getInventory()->removeItem(i->getItem()->getName());
            this->selectedItem--;
        }
        if(selectedItem == 0){
            break;
        }
    }
    this->player->getInventory()->sortByItemType();
    this->initInventorySlots();
    for(auto i : this->getInventorySlots()){
        i->setSlotTexture(&this->textures["ITEMS_SHEET"], 34.f);
        i->setDownRightTexture(&this->textures["SELECTED_ICON"]);
        i->setUpRightTexture(&this->textures["NEW_TAG"]);
    }
    for(auto i : this->inventorySlots){
        if(i->getItem()->isEquipped()){
            switch(i->getItem()->getUsageType()){
                case 5:
                    i->setUpRightTexture(&this->textures["WEAPON_ICON"]);
                    break;
                case 4:
                    i->setUpRightTexture(&this->textures["SHIELD_ICON"]);
                    break;
                case 3:
                    i->setUpRightTexture(&this->textures["HELMET_ICON"]);
                    break;
                case 2:
                    i->setUpRightTexture(&this->textures["ARMOR_ICON"]);
                    break;
                case 1:
                    i->setUpRightTexture(&this->textures["GLOVES_ICON"]);
                    break;
                case 0:
                    i->setUpRightTexture(&this->textures["BOOTS_ICON"]);
                    break;
                default:
                    break;
            }
        }
    }
    this->updateEquipBonusLbl();
    this->updateInventoryCapLbl();
}


































