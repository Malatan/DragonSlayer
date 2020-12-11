//
// Created by Zheng on 08/10/2020.
//

#include "CharacterTab.h"

//initializers
void CharacterTab::initStatsContainer() {
//containere per le statistiche
    statsContainer.setFillColor(sf::Color(50, 50, 50, 100));
    statsContainer.setSize(sf::Vector2f(((container.getGlobalBounds().width - 60.f) / 3.f) - 120.f, 720.f));
    statsContainer.setPosition(container.getPosition().x + 20.f,
                                          container.getPosition().y + 60.f);

    statsContainerTitle.setString("-Stats-");
    statsContainerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    statsContainerTitle.setFont(*font);
    statsContainerTitle.setCharacterSize(27);
    statsContainerTitle.setPosition(statsContainer.getPosition().x + statsContainer.getGlobalBounds().width/2.f
            - statsContainerTitle.getGlobalBounds().width/2.f,
            statsContainer.getPosition().y);


    statsName.setString("Level:\n"
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
    statsName.setFillColor(sf::Color(255, 255, 255, 200));
    statsName.setFont(*font);
    statsName.setCharacterSize(21);
    statsName.setPosition(statsContainer.getPosition().x + 10.f,
                                statsContainer.getPosition().y + 50.f);

    statsValue.setString(playerStatsToString());
    statsValue.setFont(*font);
    statsValue.setCharacterSize(21);
    statsValue.setPosition(statsContainer.getPosition().x + 160.f,
                                 statsContainer.getPosition().y + 50.f);

    attributesHints.setString("Hints:\n"
                                    "Strength: increases your hp and\n"
                                    "   armor\n"
                                    "Wisdom: increases your mp\n"
                                    "Agility: increases your evade and\n"
                                    "   critical chance\n");
    attributesHints.setFont(*font);
    attributesHints.setCharacterSize(20);
    attributesHints.setPosition(statsContainer.getPosition().x + 10.f,
                                      statsContainer.getPosition().y + 500.f);

    //add attributes btns
    float btnSide = 17.f;
    addStrengthBtn = gui::Button(
            statsValue.getPosition().x + 60.f, statsValue.getPosition().y + 268.f, btnSide, btnSide,
            font, "+", 48.f,
            sf::Color(200, 200, 200, 200),
            sf::Color(250, 250, 250, 250),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(20, 20, 20, 0));

    addWisdomBtn = gui::Button(
            statsValue.getPosition().x + 60.f, statsValue.getPosition().y + 294.f, btnSide, btnSide,
            font, "+", 48.f,
            sf::Color(200, 200, 200, 200),
            sf::Color(250, 250, 250, 250),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(20, 20, 20, 0));

    addAgilityBtn = gui::Button(
            statsValue.getPosition().x + 60.f, statsValue.getPosition().y + 320.f, btnSide, btnSide,
            font, "+", 48.f,
            sf::Color(200, 200, 200, 200),
            sf::Color(250, 250, 250, 250),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(20, 20, 20, 0));

    addStrengthBtn.setTextPositionAddY(-22.f);
    addWisdomBtn.setTextPositionAddY(-22.f);
    addAgilityBtn.setTextPositionAddY(-22.f);
}

void CharacterTab::initEquipContainer() {
    equipContainer.setFillColor(sf::Color(70, 70, 70, 100));
    equipContainer.setSize(sf::Vector2f(190.f, statsContainer.getGlobalBounds().height));
    equipContainer.setPosition(statsContainer.getPosition().x + statsContainer.getGlobalBounds().width + 10.f,
                                     container.getPosition().y + 60.f);

    equipContainerTitle.setString("-Equipment-");
    equipContainerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    equipContainerTitle.setFont(*font);
    equipContainerTitle.setCharacterSize(27);
    equipContainerTitle.setPosition(equipContainer.getPosition().x + equipContainer.getGlobalBounds().width/2.f
                                          - equipContainerTitle.getGlobalBounds().width/2.f,
                                          equipContainer.getPosition().y);

    equipBonusLbl.setString("Equip Effects:\n");
    equipBonusLbl.setFont(*font);
    equipBonusLbl.setCharacterSize(18);
    equipBonusLbl.setPosition(equipContainer.getPosition().x + 10.f,
                                    equipContainer.getPosition().y + 320.f);

    float posX = 15.f;
    float posY = 40.f;
    float slotSize = 70.f;

    equipSlots[WEAPON_SLOT] = std::make_unique<gui::ItemSlot>(
            equipContainer.getPosition().x + posX,
            equipContainer.getPosition().y + posY,
            slotSize, slotSize, window, font, nullptr, state, true
    );
    equipSlots[SHIELD_USAGE] = std::make_unique<gui::ItemSlot>(
            equipContainer.getPosition().x + posX + 90.f,
            equipContainer.getPosition().y + posY, slotSize,
            slotSize, window, font, nullptr, state, true
    );
    equipSlots[HEAD_USAGE] = std::make_unique<gui::ItemSlot>(
            equipContainer.getPosition().x + posX,
            equipContainer.getPosition().y + posY + 90.f,
            slotSize, slotSize, window, font, nullptr, state, true
    );
    equipSlots[CHEST_USAGE] = std::make_unique<gui::ItemSlot>(
            equipContainer.getPosition().x + posX + 90.f,
            equipContainer.getPosition().y + posY + 90.f,
            slotSize, slotSize, window, font, nullptr, state, true
    );
    equipSlots[ARMS_USAGE] = std::make_unique<gui::ItemSlot>(
            equipContainer.getPosition().x + posX,
            equipContainer.getPosition().y + posY + 180.f,
            slotSize, slotSize, window, font, nullptr, state, true
    );
    equipSlots[LEGS_USAGE] = std::make_unique<gui::ItemSlot>(
            equipContainer.getPosition().x + posX + 90.f,
            equipContainer.getPosition().y + posY + 180.f,
            slotSize, slotSize, window, font, nullptr, state, true
    );


}

void CharacterTab::initInventoryContainer() {
    inventoryContainer.setFillColor(sf::Color(90, 90, 90, 100));
    inventoryContainer.setSize(sf::Vector2f(container.getGlobalBounds().width - 60.f
    -statsContainer.getGlobalBounds().width -equipContainer.getGlobalBounds().width
            , statsContainer.getGlobalBounds().height));
    inventoryContainer.setPosition(equipContainer.getPosition().x + equipContainer.getGlobalBounds().width + 10.f,
            equipContainer.getPosition().y );

    invContainerTitle.setString("-Inventory-");
    invContainerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    invContainerTitle.setFont(*font);
    invContainerTitle.setCharacterSize(27);
    invContainerTitle.setPosition(inventoryContainer.getPosition().x + inventoryContainer.getGlobalBounds().width/2.f
                                        - invContainerTitle.getGlobalBounds().width/2.f,
                                        inventoryContainer.getPosition().y);

    selectedNumberLbl.setFont(*font);
    selectedNumberLbl.setCharacterSize(15);
    selectedNumberLbl.setString("Items selected: ");
    selectedNumberLbl.setPosition(inventoryContainer.getPosition().x + 20.f,
            inventoryContainer.getPosition().y + 30.f);

    initInventorySlots();

    sellBtn = gui::Button(
            inventoryContainer.getPosition().x + 340.f,
            inventoryContainer.getPosition().y + 580.f, 180.f, 40.f,
            font, "Sell items<S>", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    sellBtn.setBorderColor(sf::Color::White);
    sellBtn.setBorderLineThickness(5.f);
    sellBtn.setTooltipDisabled(false);
    sellBtn.setTooltipText("You must be near a Npc for selling items");

    EquipUnEquipBtn = gui::Button(
            inventoryContainer.getPosition().x + 540.f,
            inventoryContainer.getPosition().y + 580.f, 180.f, 40.f,
            font, "Equip/Unequip/Use<R>", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    EquipUnEquipBtn.setBorderColor(sf::Color::White);
    EquipUnEquipBtn.setBorderLineThickness(5.f);

    deleteBtn = gui::Button(
            inventoryContainer.getPosition().x + 540.f,
            inventoryContainer.getPosition().y + 640.f, 180.f, 40.f,
            font, "Delete items<Del>", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    deleteBtn.setBorderColor(sf::Color::White);
    deleteBtn.setBorderLineThickness(5.f);

    goldLbl.setFont(*font);
    goldLbl.setCharacterSize(20);
    goldLbl.setString("Inventory Capacity:");
    goldLbl.setPosition(inventoryContainer.getPosition().x + 40.f,
                              EquipUnEquipBtn.getPosition().y);

    inventorySpaceLbl.setFont(*font);
    inventorySpaceLbl.setCharacterSize(20);
    inventorySpaceLbl.setString("Gold:");
    inventorySpaceLbl.setPosition(goldLbl.getPosition().x,
                                        goldLbl.getPosition().y + 30.f);

    keysHintLbl.setFont(*font);
    keysHintLbl.setCharacterSize(20);
    keysHintLbl.setString("Hints: \n"
                                "Right click to select all");
    keysHintLbl.setPosition(goldLbl.getPosition().x,
                                  inventorySpaceLbl.getPosition().y + 30.f);
}

void CharacterTab::initInventorySlots() {
    //init inventory slots
    if(!inventorySlots.empty()){
        inventorySlots.clear();
    }

    int max_per_row = 10;
    float modifierX = 70.f;
    float modifierY = 70.f;
    float yMultiplier = 0;
    for(int i = 0 ; i < player->getInventory()->getItemsSize() ; i++){
        if((i % max_per_row) == 0 && i != 0){
            yMultiplier ++;
        }
        inventorySlots.push_back(std::make_unique<gui::ItemSlot>(
                inventoryContainer.getPosition().x + 36.f + (modifierX * (float)(i % max_per_row)),
                inventoryContainer.getPosition().y + 70.f + (modifierY * yMultiplier) ,
                60.f, 60.f, window, font, player->getInventory()->getItemByIndex(i), state, false
        ));
    }
    for(auto &i : inventorySlots){
        i->setSlotTexture(&textures["ITEMS_SHEET"], 34.f);
        i->setDownRightTexture(&textures["SELECTED_ICON"]);
        i->setUpRightTexture(&textures["NEW_TAG"]);
    }
}

CharacterTab::CharacterTab(const std::shared_ptr<sf::RenderWindow>& window, sf::Font* font,
        std::shared_ptr<Player> player, State* state, map<string, sf::Texture> textures,
        std::shared_ptr<ResourcesHandler> rsHandler, npc_type* npcInteract) :
font(font), player(std::move(player)), window(window), textures(std::move(textures)),
rsHandler(std::move(rsHandler)), npcInteract(npcInteract), selectedItem(0) {
    openDialog = false;
    gState = dynamic_cast<GameState*>(state);
    this->state = state;
    //init background
    backgorund.setSize(sf::Vector2f(
            static_cast<float>(window->getSize().x),
            static_cast<float>(window->getSize().y)));
    backgorund.setFillColor(sf::Color(20, 20, 20, 100));

    //initi container
    container.setSize(sf::Vector2f(
            static_cast<float>(window->getSize().x / 1.1f),
            static_cast<float>(window->getSize().y - 100.f )));
    container.setFillColor(sf::Color(20, 20, 20, 200));

    container.setPosition(sf::Vector2f(
            static_cast<float>(window->getSize().x) / 2.f - container.getSize().x / 2.f,
            40.f));

    //init text
    tabText.setFont(*this->font);
    tabText.setFillColor(sf::Color(255, 255, 255, 200));
    tabText.setCharacterSize(30);
    tabText.setString("Character Tab");
    tabText.setPosition(
            container.getPosition().x + 20.f,
            container.getPosition().y + 10.f);

    hpBarLbl.setCharacterSize(20);
    hpBarLbl.setFont(*this->font);
    hpBarLbl.setString("Hp:");
    hpBarLbl.setPosition(
            tabText.getPosition().x + 300.f,
            tabText.getPosition().y + 10.f);

    hpBar = gui::ProgressBar(hpBarLbl.getPosition().x + 35.f, tabText.getPosition().y + 10.f, 150.f, 25.f,
                                       0, this->player->getPlayerStats()->getMaxHp(), this->player->getPlayerStats()->getHp(), font);
    hpBar.setProgressShapeColor(sf::Color::Red);

    mpBarLbl.setCharacterSize(20);
    mpBarLbl.setFont(*this->font);
    mpBarLbl.setString("Mp:");
    mpBarLbl.setPosition(
            hpBarLbl.getPosition().x + 230.f,
            tabText.getPosition().y + 10.f);

    mpBar = gui::ProgressBar(mpBarLbl.getPosition().x + 35.f, tabText.getPosition().y + 10.f, 150.f, 25.f,
                                       0, this->player->getPlayerStats()->getMaxMp(), this->player->getPlayerStats()->getMp(), font);
    mpBar.setProgressShapeColor(sf::Color::Blue);

    expBarLbl.setCharacterSize(20);
    expBarLbl.setFont(*this->font);
    expBarLbl.setString("Exp:");
    expBarLbl.setPosition(
            mpBarLbl.getPosition().x + 230.f,
            tabText.getPosition().y + 10.f);

    expBar = gui::ProgressBar(expBarLbl.getPosition().x + 35.f, tabText.getPosition().y + 10.f, 150.f, 25.f,
                                       0, this->player->getPlayerStats()->getMaxExp(), this->player->getPlayerStats()->getExp(), font);
    expBar.setProgressShapeColor(sf::Color::Green);


    initStatsContainer();
    initEquipContainer();
    initInventoryContainer();
    updateGoldLbl();
    updateInventoryCapLbl();
}

CharacterTab::~CharacterTab() = default;

//accessor

unique_ptr<gui::ItemSlot> * CharacterTab::getEquipSlots() {
    return equipSlots;
}

//functions
std::string CharacterTab::playerStatsToString() {
    std::stringstream ss;
    ss << player->getPlayerStats()->getLevel()  << "\n"
            <<player->getPlayerStats()->getExp() <<"/" << player->getPlayerStats()->getMaxExp() << "\n"
            <<player->getPlayerStats()->getFinalHp() << "\n"
            <<player->getPlayerStats()->getFinalMp() << "\n"
            <<player->getPlayerStats()->getFinalDamage() << "\n"
            <<player->getPlayerStats()->getFinalArmor() << "\n"
            <<player->getPlayerStats()->getFinalCritChance() << "%\n"
            <<player->getPlayerStats()->getFinalEvadeChance() << "%\n\n\n\n"
            <<player->getPlayerStats()->getStrength() << "\n"
            <<player->getPlayerStats()->getWisdom() << "\n"
            <<player->getPlayerStats()->getAgility() << "\n"
            <<player->getPlayerStats()->getFreePoints() << "\n";
    return ss.str();
}

void CharacterTab::unselectAll() {
    for(auto &i : inventorySlots){
        i->setSelectedBool(false);
    }
}

void CharacterTab::selectAll() {
    for(auto &i : inventorySlots){
        i->setSelectedBool(true);
    }
}

void CharacterTab::statsContainerUpdate(const sf::Vector2f& mousePos) {

    if(player->getPlayerStats()->getFreePoints() > 0) {
        addStrengthBtn.update(mousePos);
        addWisdomBtn.update(mousePos);
        addAgilityBtn.update(mousePos);
    }
}

void CharacterTab::statsContainerRender(sf::RenderTarget &target) {
    target.draw(statsContainer);
    target.draw(statsContainerTitle);
    target.draw(statsName);
    target.draw(statsValue);
    target.draw(attributesHints);
    if(player->getPlayerStats()->getFreePoints() > 0) {
        addStrengthBtn.render(target);
        addWisdomBtn.render(target);
        addAgilityBtn.render(target);
    }
}

void CharacterTab::equipContainerUpdate(const sf::Vector2f &mousePos) {
    for(auto &i : equipSlots){
        i->update(mousePos, false);
    }
}

void CharacterTab::equipContainerRender(sf::RenderTarget &target) {
    target.draw(equipContainer);
    target.draw(equipContainerTitle);
    target.draw(equipBonusLbl);
    for(auto &i : equipSlots){
        i->render(target);
    }
    for(auto &i : equipSlots){
        i->renderInfoContainer(target);
    }
}

void CharacterTab::updatePlayerStatsLbl() {
    statsValue.setString(playerStatsToString());
}

void CharacterTab::updateGoldLbl() {
    std::stringstream ss;
    std::string gold = to_string(player->getGold());
    unsigned len = gold.length();

    for(int index =(int) len-3; index > 0; index -= 3)
        gold.insert(index, ",");
    ss << "Gold: " << gold;

    goldLbl.setString(ss.str());
}

void CharacterTab::updateInventoryCapLbl() {
    std::stringstream ss;
    ss << "Inventory Capacity: " << player->getInventory()->getItemsSize()
       << "/" << player->getInventory()->getCurrentMaxSpace();
    inventorySpaceLbl.setString(ss.str());
}

void CharacterTab::invContainerUpdate(const sf::Vector2f &mousePos) {
    selectedItem = 0;
    std::stringstream ss;
    for(auto &i : inventorySlots){
        if(i->getIsSelected())
            selectedItem++;
        i->update(mousePos, true);
    }
    ss << "Items selected: " << selectedItem;
    selectedNumberLbl.setString(ss.str());

    deleteBtn.setDisabled(selectedItem == 0);
    EquipUnEquipBtn.setDisabled(selectedItem != 1);

    sellBtn.setDisabled(!(selectedItem != 0 && *npcInteract != NO_NPC));

    EquipUnEquipBtn.update(mousePos);
    deleteBtn.update(mousePos);
    sellBtn.update(mousePos);
}

void CharacterTab::invContainerRender(sf::RenderTarget &target) {
    target.draw(inventoryContainer);
    target.draw(invContainerTitle);
    target.draw(selectedNumberLbl);
    target.draw(goldLbl);
    target.draw(inventorySpaceLbl);
    target.draw(keysHintLbl);
    EquipUnEquipBtn.render(target);
    deleteBtn.render(target);
    sellBtn.render(target);
 /*   for(auto i : this->inventorySlots){
        i->render(target);
    }*/
    for (auto it = inventorySlots.rbegin(); it != inventorySlots.rend(); it++){
        (*it)->render(target);
    }


}

bool CharacterTab::closeCharacterTabByClicking(const sf::Vector2f& mousePos, gui::Button* cTab_Btn) {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
           backgorund.getGlobalBounds().contains(mousePos)
           && !container.getGlobalBounds().contains(mousePos) && !cTab_Btn->contains(mousePos);
}

void CharacterTab::equipUnequipItem(int equip_slot, const std::shared_ptr<Item>& item,
        std::unique_ptr<gui::ItemSlot>& i, const std::string& typeIcon) {
    if(!item->isEquipped() && !player->isSlotEquipped(equip_slot)){ // equip item
        player->setEquipItem(item, equip_slot);
        equipSlots[equip_slot]->setItem(item);
        equipSlots[equip_slot]->updateItemInfo();
        equipSlots[equip_slot]->setShapeTexture(i->getShape()->getTexture(),
                                                      i->getIntRect());
        equipSlots[equip_slot]->setOutlineColors(i->getShape()->getOutlineColor());
        item->setEquipped(true);
        i->setUpRightTexture(&textures[typeIcon]);
        i->setSelectedBool(false);

    } else if(item->isEquipped() && player->isSlotEquipped(equip_slot)){ // unequip item
        player->unequipItem(equip_slot);
        equipSlots[equip_slot]->setItem(nullptr);
        equipSlots[equip_slot]->setSlotTexture(&textures["EquipSlotsSheet"],
                rsHandler->getEquipSlotTextureRect(equip_slot));
        equipSlots[equip_slot]->getShape()->setOutlineColor(sf::Color::Transparent);
        item->setEquipped(false);
        i->setSelectedBool(false);

    } else if(!item->isEquipped() && player->isSlotEquipped(equip_slot)){ // unequip then equip
        player->unequipItem(equip_slot);
        equipSlots[equip_slot]->setItem(nullptr);
        equipSlots[equip_slot]->setSlotTexture(&textures["EquipSlotsSheet"],
                rsHandler->getEquipSlotTextureRect(equip_slot));
        equipSlots[equip_slot]->getShape()->setOutlineColor(sf::Color::Transparent);
        item->setEquipped(false);

        player->setEquipItem(item, equip_slot);
        equipSlots[equip_slot]->setItem(item);
        equipSlots[equip_slot]->updateItemInfo();
        equipSlots[equip_slot]->setShapeTexture(i->getShape()->getTexture(), i->getIntRect());
        equipSlots[equip_slot]->setOutlineColors(i->getShape()->getOutlineColor());
        item->setEquipped(true);
        i->setUpRightTexture(&textures[typeIcon]);
        i->setSelectedBool(false);

    }
    updateEquipBonusLbl();
    updatePlayerStatsLbl();
}

void CharacterTab::useConsumable(const std::shared_ptr<Item>& item, std::unique_ptr<gui::ItemSlot>& i) {
    bool have_more = true;
    if(item->getQuantity() > 0 && item->getUsageType() == CONSUMABLE_USAGE){
        have_more = item->use();
        gState->getBuffComponent()->applyItemBuff(item->getName(), true);
        i->updateQuantityLbl();

    }

    if(!have_more){
        deleteItemFromInventory();
    }
}

void CharacterTab::equipUnEquipBtnFunction() {
    bool flag = false;
    for(auto &i : inventorySlots){
        if(i->getIsSelected()){
            //std::shared_ptr<Item> item = player->getInventory()->getItemById(i->getItem()->getId());
            std::shared_ptr<Item> item = i->getItem();
            switch(i->getItem()->getUsageType()){
                case WEAPON_USAGE:
                    equipUnequipItem(5, item, i, "WEAPON_ICON");
                    break;
                case SHIELD_USAGE:
                    equipUnequipItem(4, item, i, "SHIELD_ICON");
                    break;
                case HEAD_USAGE:
                    equipUnequipItem(3, item, i, "HELMET_ICON");
                    break;
                case CHEST_USAGE:
                    equipUnequipItem(2, item, i, "ARMOR_ICON");
                    break;
                case ARMS_USAGE:
                    equipUnequipItem(1, item, i, "GLOVES_ICON");
                    break;
                case LEGS_USAGE:
                    equipUnequipItem(0, item, i, "BOOTS_ICON");
                    break;
                case CONSUMABLE_USAGE:
                    useConsumable(item, i);
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
    if(selectedItem == 1){
        for(auto &i : inventorySlots) {
            if (i->getIsSelected()) {
                sellDeleteDialog = std::make_unique<gui::CustomDialog>(
                        container.getPosition().x + (container.getGlobalBounds().width / 2.f),
                        container.getPosition().y + (container.getGlobalBounds().height / 2.f),
                        i->getItem(), state, font, DELETE_CONFIRM);
                break;
            }
        }
    }else{
        sellDeleteDialog = std::make_unique<gui::CustomDialog>(
                container.getPosition().x + (container.getGlobalBounds().width / 2.f),
                container.getPosition().y + (container.getGlobalBounds().height / 2.f),
                0, selectedItem, state, font, DELETE_CONFIRM);
    }
    openDialog = true;
}

void CharacterTab::sellBtnFunction() {
    if(selectedItem == 1){
        for(auto &i : inventorySlots) {
            if (i->getIsSelected()) {
                sellDeleteDialog = std::make_unique<gui::CustomDialog>(
                        container.getPosition().x + (container.getGlobalBounds().width / 2.f),
                        container.getPosition().y + (container.getGlobalBounds().height / 2.f),
                        i->getItem(), state, font, SELL_CONFIRM);
                break;
            }
        }
    }else{
        int tot_value = 0;
        for(auto &i : inventorySlots)
            if (i->getIsSelected())
                tot_value += i->getItem()->getValue() * i->getItem()->getQuantity();
        sellDeleteDialog = std::make_unique<gui::CustomDialog>(
                container.getPosition().x + (container.getGlobalBounds().width / 2.f),
                container.getPosition().y + (container.getGlobalBounds().height / 2.f),
                tot_value, selectedItem, state, font, SELL_CONFIRM);
    }
    openDialog = true;
}

void CharacterTab::updateButtons() {
    if(addStrengthBtn.isPressed() && state->getKeyTime()){
        addStrengthBtn.setButtonState(BTN_IDLE);
        if(player->getPlayerStats()->getFreePoints() > 0){
            player->getPlayerStats()->addAttribute(STRENGTH, 1);
            gState->updateTabsPlayerStatsLbl();
        }
    } else if(addWisdomBtn.isPressed() && state->getKeyTime()){
        addWisdomBtn.setButtonState(BTN_IDLE);
        if(player->getPlayerStats()->getFreePoints() > 0){
            player->getPlayerStats()->addAttribute(WISDOM, 1);
            gState->updateTabsPlayerStatsLbl();
        }
    } else if(addAgilityBtn.isPressed() && state->getKeyTime()){
        addAgilityBtn.setButtonState(BTN_IDLE);
        if(player->getPlayerStats()->getFreePoints() > 0){
            player->getPlayerStats()->addAttribute(AGILITY, 1);
            gState->updateTabsPlayerStatsLbl();
        }
    } else if(EquipUnEquipBtn.isPressed() && state->getKeyTime()) {
        EquipUnEquipBtn.setButtonState(BTN_IDLE);
        equipUnEquipBtnFunction();
    } else if(deleteBtn.isPressed() && state->getKeyTime()) {
        deleteBtn.setButtonState(BTN_IDLE);
        deleteBtnFunction();
    } else if(sellBtn.isPressed() && state->getKeyTime()) {
        sellBtn.setButtonState(BTN_IDLE);
        sellBtnFunction();
    }
}

void CharacterTab::updateMouseInput() {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right) && gState->getKeyTime()){
        if(selectedItem != 0){
            unselectAll();
        }
    }
}

void CharacterTab::updateKeyboardInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && state->getKeyTime()) {
        // equip / unequip with hotkey
        if(selectedItem == 1){
            equipUnEquipBtnFunction();
        }
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Delete) && state->getKeyTime()) {
        // delete items with hotkey
        deleteBtnFunction();
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && state->getKeyTime()) {
        // sell items with hotkey
        if(!sellBtn.isDisabled()){
            sellBtnFunction();
        }
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && state->getKeyTime()) {
        selectAll();
    }
}

void CharacterTab::processDialogResult() {
    if(selectedItem == 1){
        switch (sellDeleteDialog->getDialogType()) {
            case DELETE_CONFIRM:{
                int delete_amount = sellDeleteDialog->getFinalQuantity();
                if(sellDeleteDialog->getItem()->getQuantity() == delete_amount)
                    deleteItemFromInventory();
                else{
                    sellDeleteDialog->getItem()->minusQuantity(delete_amount);
                    for(auto &i : inventorySlots){
                        if(i->getItem()->getId() == sellDeleteDialog->getItem()->getId())
                            i->updateQuantityLbl();
                    }
                }

                stringstream ss;
                ss << delete_amount << " " <<  sellDeleteDialog->getItem()->getName();
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, ss.str(), "You deleted ", " from your inventory");
                break;
            }
            case SELL_CONFIRM:{
                int sell_amount = sellDeleteDialog->getFinalQuantity();
                int earn_amount = sellDeleteDialog->getFinalQuantity() * sellDeleteDialog->getItem()->getValue();
                if(sellDeleteDialog->getItem()->getQuantity() == sell_amount)
                    deleteItemFromInventory();
                else{
                    sellDeleteDialog->getItem()->minusQuantity(sell_amount);
                    for(auto &i : inventorySlots){
                        if(i->getItem()->getId() == sellDeleteDialog->getItem()->getId())
                            i->updateQuantityLbl();
                    }
                }
                player->addGold(earn_amount);
                gState->updateTabsGoldLbl();
                stringstream ss;
                ss << earn_amount << " gold";
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        GOLD_TAG, ss.str(), "You got ", " by trading");
                break;
            }
        }
    }else{
        switch (sellDeleteDialog->getDialogType()) {
            case DELETE_CONFIRM:{
                int selected = selectedItem;
                deleteItemFromInventory();
                stringstream ss;
                ss << selected;
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        DEFAULT_TAG, ss.str(), "You deleted ", " from your inventory");
                break;
            }
            case SELL_CONFIRM:{
                int earn_amount = sellDeleteDialog->getTotValue();
                deleteItemFromInventory();
                player->addGold(earn_amount);
                gState->updateTabsGoldLbl();
                stringstream ss;
                ss << earn_amount << " gold";
                gState->getPopUpTextComponent()->addPopUpTextCenter(
                        GOLD_TAG, ss.str(), "You got ", " by trading");
                break;
            }
        }
    }
}

void CharacterTab::update(const sf::Vector2f& mousePos) {
    updateButtons();
    if(openDialog){
        window->setMouseCursorVisible(true);
        sellDeleteDialog->update(mousePos);
        switch (sellDeleteDialog->getResult()) {
            case PENDING_RESULT:
                break;
            case YES_RESULT:
                processDialogResult();
            case NO_RESULT:
                openDialog = false;
                break;
        }
    } else {
        updateMouseInput();
        updateKeyboardInput();

        statsContainerUpdate(mousePos);
        equipContainerUpdate(mousePos);
        invContainerUpdate(mousePos);

        hpBar.update(player->getPlayerStats()->getHp(), player->getPlayerStats()->getFinalHp());
        mpBar.update(player->getPlayerStats()->getMp(), player->getPlayerStats()->getFinalMp());
        expBar.update(player->getPlayerStats()->getExp(), player->getPlayerStats()->getMaxExp());
    }
}

void CharacterTab::render(sf::RenderTarget &target) {
    target.draw(backgorund);
    target.draw(container);
    target.draw(tabText);

    target.draw(hpBarLbl);
    hpBar.render(target);
    target.draw(mpBarLbl);
    mpBar.render(target);
    target.draw(expBarLbl);
    expBar.render(target);

    statsContainerRender(target);
    invContainerRender(target);
    equipContainerRender(target);
    for(auto &i : inventorySlots)
        i->renderInfoContainer(target);
    if(openDialog){
        sellDeleteDialog->render(target);
    }
}

const vector<std::unique_ptr<gui::ItemSlot>>& CharacterTab::getInventorySlots() const {
    return inventorySlots;
}

void CharacterTab::updateEquipBonusLbl() {
    int dmgBonus = 0;
    int armorBonus = 0;
    int hpBonus = 0;
    int mpBonus = 0;
    float critChanceBonus = 0;
    float evadeChanceBonus = 0;
    for(int i = 0 ; i < 6 ; i++){
        if(player->isSlotEquipped(i)){
            hpBonus += player->getEquippedItem(i)->getHp();
            mpBonus += player->getEquippedItem(i)->getMp();
            dmgBonus += player->getEquippedItem(i)->getDamage();
            if(player->getEquippedItem(i)->getUsageType() != SHIELD_USAGE)
                armorBonus += player->getEquippedItem(i)->getArmor();
            critChanceBonus += player->getEquippedItem(i)->getCritChance();
            evadeChanceBonus += player->getEquippedItem(i)->getEvadeChance();
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

    equipBonusLbl.setString(ss.str());

    player->setBonusStats(hpBonus, mpBonus, dmgBonus, armorBonus, critChanceBonus, evadeChanceBonus);
}

void CharacterTab::deleteItemFromInventory() {
    for(auto &i : inventorySlots){
        if(i->getIsSelected()){
            if(i->getItem()->isEquipped()){
                int equip_slot = i->getItem()->getUsageType();
                player->unequipItem(equip_slot);
                equipSlots[equip_slot]->setItem(nullptr);
                equipSlots[equip_slot]->setSlotTexture(&textures["EquipSlotsSheet"],
                        rsHandler->getEquipSlotTextureRect(equip_slot));
                equipSlots[equip_slot]->getShape()->setOutlineColor(sf::Color::Transparent);
            }
            player->getInventory()->removeItemById(i->getItem()->getId());
            selectedItem--;
        }
        if(selectedItem == 0){
            break;
        }
    }
    player->getInventory()->sortByItemType();
    initInventorySlots();
    for(auto &i : getInventorySlots()){
        i->setSlotTexture(&textures["ITEMS_SHEET"], 34.f);
        i->setDownRightTexture(&textures["SELECTED_ICON"]);
        i->setUpRightTexture(&textures["NEW_TAG"]);
    }
    for(auto &i : inventorySlots){
        if(i->getItem()->isEquipped()){
            switch(i->getItem()->getUsageType()){
                case WEAPON_USAGE:
                    i->setUpRightTexture(&textures["WEAPON_ICON"]);
                    break;
                case SHIELD_USAGE:
                    i->setUpRightTexture(&textures["SHIELD_ICON"]);
                    break;
                case HEAD_USAGE:
                    i->setUpRightTexture(&textures["HELMET_ICON"]);
                    break;
                case CHEST_USAGE:
                    i->setUpRightTexture(&textures["ARMOR_ICON"]);
                    break;
                case ARMS_USAGE:
                    i->setUpRightTexture(&textures["GLOVES_ICON"]);
                    break;
                case LEGS_USAGE:
                    i->setUpRightTexture(&textures["BOOTS_ICON"]);
                    break;
                default:
                    break;
            }
        }
    }
    updateEquipBonusLbl();
    gState->updateTabsInvSpaceLbl();
}

void CharacterTab::deleteConsumableInBattle(const std::shared_ptr<Item>& item) {
    player->getInventory()->removeItemById(item->getId());
    player->getInventory()->sortByItemType();
    initInventorySlots();
    gState->updateTabsInvSpaceLbl();
}

GameState *CharacterTab::getGState() const {
    return gState;
}








































