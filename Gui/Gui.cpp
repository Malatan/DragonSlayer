//
// Created by Zheng on 06/10/2020.
// componenti grafici customizzati

#include "Gui.h"
#include <iostream>
#include <sstream>
gui::Button::Button(){

};

gui::Button::Button(float x, float y, float width, float height,
                    sf::Font *font, const std::string& text, unsigned character_size,
                    sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
                    sf::Color idle_color, sf::Color hover_color, sf::Color active_color, short unsigned id) {
    buttonState = BTN_IDLE;
    this->id = id;
    disabled = false;
    tooltipDisabled = true;
    backgroundDisabled = true;
    textDisabled = text.empty();
    hover = false;

    shape.setPosition(sf::Vector2f(x,y));
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(idle_color);
    shape.setOutlineThickness(1.f);
    shape.setOutlineColor(sf::Color::Transparent);

    background.setPosition(sf::Vector2f(x,y));
    background.setSize(sf::Vector2f(width, height));


    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(text_idle_color);
    this->text.setCharacterSize(character_size);
    this->text.setPosition(
            (shape.getPosition().x + width /2.f) - this->text.getGlobalBounds().width/2.f,
            (shape.getPosition().y + height /2.f) - this->text.getGlobalBounds().height/1.5f
    );

    //colore testo bottone
    textIdleColor = text_idle_color;
    textHoverColor = text_hover_color;
    textActiveColor = text_active_color;

    //colore sfondo bottone
    idleColor = idle_color;
    hoverColor = hover_color;
    activeColor = active_color;

    //tooltip
    tooltipContainer.setFillColor(sf::Color(71, 71, 71));

    tooltipText.setFont(*this->font);
    tooltipText.setCharacterSize(20);

}

gui::Button::~Button() {

}

//accessors
bool gui::Button::isPressed() const {
    return buttonState == BTN_ACTIVE;
}

const short unsigned &gui::Button::getId() const {
    return id;
}

sf::Vector2f gui::Button::getPosition() {
    return shape.getPosition();
}

//modifiers
void gui::Button::setPosition(float x, float y) {
    shape.setPosition(x,y);
    text.setPosition(
            (x + shape.getGlobalBounds().width /2.f) - text.getGlobalBounds().width/2.f,
            (y + shape.getGlobalBounds().height /2.f) - text.getGlobalBounds().height/1.5f
    );
}

void gui::Button::setPosition(sf::Vector2f pos) {
    shape.setPosition(pos);
    text.setPosition(
            (pos.x + shape.getGlobalBounds().width /2.f) - text.getGlobalBounds().width/2.f,
            (pos.y + shape.getGlobalBounds().height /2.f) - text.getGlobalBounds().height/1.5f
    );
}

void gui::Button::setSize(sf::Vector2f size) {
    shape.setSize(size);
}

void gui::Button::setText(const std::string text) {
    this->text.setString(text);
}

void gui::Button::setId(const short unsigned id) {
    this->id = id;
}

void gui::Button::setBorderColor(sf::Color color) {
    shape.setOutlineColor(color);
}

void gui::Button::setBorderLineThickness(float value) {
    shape.setOutlineThickness(value);
}

void gui::Button::setTextPosition(sf::Vector2f position) {
    text.setPosition(position);
}

void gui::Button::setTextPositionAddY(float y) {
    this->text.setPosition(this->text.getPosition().x, this->text.getPosition().y + y);
}

void gui::Button::setTooltipText(std::string text) {
    tooltipText.setString(text);
    tooltipContainer.setSize(sf::Vector2f(tooltipText.getGlobalBounds().width + 10.f,
                                                 tooltipText.getGlobalBounds().height + 15.f));
}

void gui::Button::setTooltipDisabled(bool b) {
    tooltipDisabled = b;
}

void gui::Button::setDisabled(bool b) {
    if(b){
        shape.setOutlineColor(sf::Color(128, 128, 128));
        text.setFillColor(sf::Color(128, 128, 128));
    } else{
        shape.setOutlineColor(sf::Color::White);
        text.setFillColor(sf::Color(textIdleColor));
    }
    disabled = b;
}

void gui::Button::setButtonState(button_states btnstates) {
    buttonState = btnstates;
}

void gui::Button::setBackgroundTexture(const sf::Texture* texture) {
    background.setTexture(texture);
}

void gui::Button::setBackbgroundDisabled(bool b) {
    backgroundDisabled = b;
}


//functions
void gui::Button::updateTooltipPos(const sf::Vector2f &mousePos) {
    tooltipContainer.setPosition(sf::Vector2f(mousePos.x,
            mousePos.y - tooltipContainer.getGlobalBounds().height));
    tooltipText.setPosition(tooltipContainer.getPosition().x + 5.f,
                                  tooltipContainer.getPosition().y);
}

void gui::Button::update(const sf::Vector2f& mousePos) {
    hover = false;
    if(!tooltipDisabled && shape.getGlobalBounds().contains(mousePos)){
        updateTooltipPos(mousePos);
        hover = true;
    }
    if(!disabled){
        //idle
        buttonState = BTN_IDLE;

        //hover
        if(shape.getGlobalBounds().contains(mousePos)){
            buttonState = BTN_HOVER;
            hover = true;
            //pressed
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                buttonState = BTN_ACTIVE;
            }
            if(!tooltipDisabled){
                updateTooltipPos(mousePos);
            }
        }
    }

    //cambia colore in base allo stato del bottone
    switch(buttonState){
        case BTN_IDLE:
            shape.setFillColor(idleColor);
            text.setFillColor(textIdleColor);
            break;
        case BTN_HOVER:
            shape.setFillColor(hoverColor);
            text.setFillColor(textHoverColor);
            break;
        case BTN_ACTIVE:
            shape.setFillColor(activeColor);
            text.setFillColor(textActiveColor);
            break;
    }
}

void gui::Button::render(sf::RenderTarget& target) {
    if(!backgroundDisabled){
        target.draw(background);
    }
    target.draw(shape);
    if(!textDisabled)
        target.draw(text);

    if(!tooltipDisabled && hover){
        target.draw(tooltipContainer);
        target.draw(tooltipText);
    }
}

bool gui::Button::contains(const sf::Vector2f &mousePos) {
    return shape.getGlobalBounds().contains(mousePos);
}

void gui::Button::setBackgroundFilLColor(sf::Color color) {
    shape.setFillColor(color);
}

sf::FloatRect gui::Button::getGlobalBounds() const {
    return shape.getGlobalBounds();
}


/*
 *
 *          PROGRESSBAR
 *
 */
gui::ProgressBar::ProgressBar() {

};

gui::ProgressBar::ProgressBar(float x, float y, float width, float height, int min, int max, int currentValue, sf::Font *font)
: font(font), min(min), max(max), currentValue(currentValue){
    progressPercentage = 0.f;
    barShape.setSize(sf::Vector2f(width, height));
    barShape.setPosition(x, y);
    barShape.setFillColor(sf::Color::Transparent);
    barShape.setOutlineColor(sf::Color::Magenta);
    barShape.setOutlineThickness(2.f);

    progressShape.setFillColor(sf::Color::Green);
    progressShape.setSize(sf::Vector2f(width, height));
    progressShape.setPosition(x , y);

    text.setString("10/10");
    text.setFont(*font);
    text.setStyle(sf::Text::Bold);
    text.setCharacterSize(15.f);
    text.setOrigin(text.getGlobalBounds().width / 2.f,
            text.getGlobalBounds().height / 2.f);
    text.setPosition(barShape.getPosition().x + (barShape.getGlobalBounds().width / 2.f),
            barShape.getPosition().y + (barShape.getGlobalBounds().height / 2.8f));

}

gui::ProgressBar::~ProgressBar() {

}

sf::Vector2f gui::ProgressBar::getPosition() {
    return barShape.getPosition();
}

void gui::ProgressBar::setMax(int max) {
    this->max = max;
}

void gui::ProgressBar::setMin(int min) {
    this->min = min;
}

void gui::ProgressBar::setCurrentValue(int currentValue) {
    this->currentValue = currentValue;
}

void gui::ProgressBar::setText(std::string text) {
    this->text.setString(text);
}

void gui::ProgressBar::setBarShapeColor(sf::Color color) {
    this->barShape.setFillColor(color);
}

void gui::ProgressBar::setProgressShapeColor(sf::Color color) {
    this->progressShape.setFillColor(color);
}

void gui::ProgressBar::update(float current, int max) {
    std::stringstream ss;
    ss << current << "/" << max;
    this->max = max;
    currentValue = current;
    this->text.setString(ss.str());
    this->progressPercentage = (float)this->currentValue / (float)this->max;
    if(this->progressPercentage == 1){
        progressShape.setSize(sf::Vector2f(barShape.getGlobalBounds().width * progressPercentage -4.f,
                                                 progressShape.getGlobalBounds().height));
    } else{
        progressShape.setSize(sf::Vector2f(barShape.getGlobalBounds().width * progressPercentage,
                                                 progressShape.getGlobalBounds().height));
    }

}

void gui::ProgressBar::render(sf::RenderTarget &target) {
    target.draw(barShape);
    target.draw(progressShape);
    target.draw(text);
}




/*
 *                      ITEMSLOT
 *
 */
gui::ItemSlot::ItemSlot(){

};

gui::ItemSlot::ItemSlot(float x, float y, float width, float height, int id,
        std::shared_ptr<sf::RenderWindow> window, sf::Font *font, const std::shared_ptr<Item>& item, State* state, bool isEquipSlot)
    : window(window), font(font), item(item), id(id), isEquipSlot(isEquipSlot){
    renderItemInfoContainer = false;
    isSelected = false;
    shape.setPosition(sf::Vector2f(x,y));
    shape.setSize(sf::Vector2f(width, height));
    this->state = state;
    if(isEquipSlot){
        shape.setOutlineThickness(-3.f);
        shape.setOutlineColor(sf::Color::Transparent);
    }


    downRight.setPosition(shape.getPosition().x + 42.f,
            shape.getPosition().y + 38.f);
    downRight.setSize(sf::Vector2f(15.f, 20.f));

    upRight.setPosition(shape.getPosition().x + 42.f,
                                shape.getPosition().y);
    upRight.setSize(sf::Vector2f(25.f, 25.f));

    cover.setPosition(sf::Vector2f(x,y));
    cover.setSize(sf::Vector2f(width, height));
    cover.setOutlineThickness(3.f);
    cover.setOutlineColor(sf::Color::Transparent);

    itemInfoContainer.setSize(sf::Vector2f(width*2, height*2));
    itemInfoContainer.setFillColor(sf::Color(71, 71, 71));

    itemInfoLbl.setFont(*font);
    itemInfoLbl.setCharacterSize(20);

    quantityLbl.setFont(*font);
    quantityLbl.setCharacterSize(20);
    if(item != nullptr){
        std::stringstream ss;
        ss << "x" << item->getQuantity();
        quantityLbl.setString(ss.str());
    }
    quantityLbl.setPosition(
            shape.getPosition().x +  5.f,
            shape.getPosition().y + 35.f
    );
}

gui::ItemSlot::~ItemSlot() {

}

int gui::ItemSlot::getId() {
    return id;
}

bool gui::ItemSlot::getIsSelected() {
    return isSelected;
}

bool gui::ItemSlot::hasItem() {
    return (item != nullptr);
}

void gui::ItemSlot::setSlotTexture(const sf::Texture *texture, float size) {
    if(item != nullptr){
        shape.setTexture(texture);
        intRect = sf::IntRect(
                item->getIconRectX() * size,
                item->getIconRectY() * size,
                size, size);
        shape.setTextureRect(intRect);
        shape.setOutlineThickness(-3.f);

        if(item->getRarity() == "Uncommon"){
            shape.setOutlineColor(sf::Color::White);
        } else if(item->getRarity() == "Common"){
            shape.setOutlineColor(sf::Color::Green);
        } else if(item->getRarity() == "Rare"){
            shape.setOutlineColor(sf::Color::Blue);
        } else if(item->getRarity() == "Epic"){
            shape.setOutlineColor(sf::Color::Magenta);
        } else if(item->getRarity() == "Legendary"){
            shape.setOutlineColor(sf::Color(255,127,80));
        }
        updateItemInfo();
        itemInfoContainer.setSize(sf::Vector2f(itemInfoLbl.getGlobalBounds().width + 10.f,
                                                     itemInfoLbl.getGlobalBounds().height + 15.f));
    }

}

void gui::ItemSlot::setSlotTexture(sf::Texture* texture, sf::IntRect intRect) {
    shape.setTexture(texture);
    shape.setTextureRect(intRect);
}

void gui::ItemSlot::setDownRightTexture(sf::Texture *texture) {
    downRight.setTexture(texture);
}

void gui::ItemSlot::setUpRightTexture(sf::Texture *texture) {
    upRight.setTexture(texture);
}

void gui::ItemSlot::setSelectedBool(bool b) {
    isSelected = b;
}

void gui::ItemSlot::itemInfo(const sf::Vector2f &mousePos) {

}

void gui::ItemSlot::updateItemInfo() {
    if(item != nullptr){
        std::stringstream ss;
        ss << item->getName()
           << "\nType: " << item->getItemUsageTypeString()
           << "\n" << item->getRarity();
        if(item->getHp() !=0){
            ss << "\n+" << item->getHp() << " hp";
        }
        if(item->getMp() !=0){
            ss << "\n+" << item->getMp() << " mp";
        }
        if(item->getDamage() !=0){
            ss << "\n+" << item->getDamage() << " dmg";
        }
        if(item->getArmor() !=0){
            ss << "\n+" << item->getArmor() << " armor";
        }
        if(item->getCritChance() !=0){
            ss << "\n+" << item->getCritChance() << " % crit chance";
        }
        if(item->getEvadeChance() !=0){
            ss << "\n+" << item->getEvadeChance() << " % evade chance";
        }
        ss << "\n' " << item->getDescription() << "'";

        ss << "\nValue: " << item->getValue();

        itemInfoLbl.setString(ss.str());
        itemInfoContainer.setSize(sf::Vector2f(itemInfoLbl.getGlobalBounds().width + 10.f,
                                                     itemInfoLbl.getGlobalBounds().height + 15.f));
    }
}

void gui::ItemSlot::updateItemInfoPos(const sf::Vector2f &mousePos) {
    itemInfoContainer.setPosition(mousePos);
    itemInfoLbl.setPosition(itemInfoContainer.getPosition().x + 5.f,
                                  itemInfoContainer.getPosition().y);
}

void gui::ItemSlot::update(const sf::Vector2f &mousePos, int *updateSlot, bool inv) {

    //hover
    if(shape.getGlobalBounds().contains(mousePos)){
        //pressed
        if(item != nullptr){
            if(item->getIsNew()){
                item->setIsNew(false);

            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && state->getKeyTime() && !isEquipSlot){
                slotState = SLOT_ACTIVE;
                renderItemInfoContainer = false;
                if(inv){
                    if(isSelected){
                        isSelected = false;
                        cover.setOutlineColor(sf::Color::Transparent);
                    } else{
                        isSelected = true;
                        cover.setOutlineColor(sf::Color::Cyan);
                    }
                }
            }
            if(hasItem()){
                renderItemInfoContainer = true;
                updateItemInfoPos(mousePos);
                window->setMouseCursorVisible(false);
                slotState = SLOT_HOVER;
                *updateSlot = id;
            }
        }
    } else{
        //idle
        slotState = SLOT_IDLE;
        renderItemInfoContainer = false;
        window->setMouseCursorVisible(true);
        *updateSlot = 100;
        if(isSelected){
            cover.setOutlineColor(sf::Color::Cyan);
        } else{
            cover.setOutlineColor(sf::Color::Transparent);
        }

    }

    //cambia colore in base allo stato del bottone
    switch(slotState){
        case SLOT_IDLE:
            cover.setFillColor(sf::Color::Transparent);
            break;
        case SLOT_HOVER:
            cover.setFillColor(sf::Color(212, 212, 212,70));
            break;
        case SLOT_ACTIVE:
            cover.setFillColor(sf::Color(112, 112, 112, 210));
            break;
    }
}

void gui::ItemSlot::render(sf::RenderTarget &target) {
    target.draw(shape);
    target.draw(cover);
    if(isSelected){
        target.draw(downRight);
    }

    if(item != nullptr && !isEquipSlot){
        if(item->getIsNew() || item->isEquipped()){
            target.draw(upRight);
        }
        if(item->isConsumable())
            target.draw(quantityLbl);
    }

    if(renderItemInfoContainer){
        target.draw(itemInfoContainer);
        target.draw(itemInfoLbl);
    }
   // target.draw(this->itemName);
}

std::shared_ptr<Item> gui::ItemSlot::getItem() {
    return item;
}

void gui::ItemSlot::setItem(std::shared_ptr<Item> item) {
    this->item = item;
}

sf::RectangleShape* gui::ItemSlot::getShape() {
    return &shape;
}

void gui::ItemSlot::setShapeTexture(const sf::Texture *texture, const sf::IntRect* intRect) {
    shape.setTexture(texture);
    shape.setTextureRect(*intRect);
}

sf::IntRect* gui::ItemSlot::getIntRect() {
    return &intRect;
}

void gui::ItemSlot::updateQuantityLbl() {
    if(item != nullptr){
        std:stringstream ss;
        ss << "x" << item->getQuantity();
        quantityLbl.setString(ss.str());
    }
}


/*
 *                      CONFIRM DIALOG
 *
 */

gui::ConfirmDialog::ConfirmDialog(){

};

gui::ConfirmDialog::ConfirmDialog(float x, float y, const std::string& text, const std::shared_ptr<sf::RenderWindow>& window,
        State* state, sf::Font* font, unsigned int characterSize, dialog_type dType) : state(state){
    sellValue = 0;
    dialogType = dType;
    window->setMouseCursorVisible(true);

    dialog.setSize(sf::Vector2f(500.f, 150.f));
    dialog.setPosition(x, y);
    dialog.setFillColor(sf::Color(61, 61, 61, 230));
    dialog.setOutlineColor(sf::Color(25, 25, 25, 200));
    dialog.setOutlineThickness(10.f);

    this->text.setString(text);
    this->text.setFont(*font);
    this->text.setCharacterSize(characterSize);
    this->text.setPosition(dialog.getPosition().x + (dialog.getGlobalBounds().width / 2.f) -
                                   (this->text.getGlobalBounds().width / 2.f) - 10.f,
            dialog.getPosition().y + (dialog.getGlobalBounds().height / 2.f) -
                    this->text.getGlobalBounds().height / 2.f - 30.f);

    yesBtn = Button(this->text.getPosition().x + (this->text.getGlobalBounds().width / 2.f) - 120.f,
                        this->text.getPosition().y + 50.f , 40.f, 30.f,
                             font, "Yes", 30,
                              sf::Color(38, 38, 38),
                              sf::Color(250, 250, 250, 250),
                              sf::Color(20, 20, 20, 50),
                              sf::Color::Transparent,
                              sf::Color(150, 150, 150, 0),
                              sf::Color(20, 20, 20, 0));


    noBtn = Button(this->text.getPosition().x + (this->text.getGlobalBounds().width / 2.f) + 80.f,
                       this->text.getPosition().y + 50.f, 40.f, 30.f,
                             font, "No", 30,
                             sf::Color(38, 38, 38),
                             sf::Color(250, 250, 250, 250),
                             sf::Color(20, 20, 20, 50),
                             sf::Color::Transparent,
                             sf::Color(150, 150, 150, 0),
                             sf::Color(20, 20, 20, 0));

}

gui::ConfirmDialog::~ConfirmDialog() {

}

int gui::ConfirmDialog::update(const sf::Vector2f &mousePos, bool* openDialog) {
    this->yesBtn.update(mousePos);
    this->noBtn.update(mousePos);
    if(this->yesBtn.isPressed() && this->state->getKeyTime()){
        *openDialog = false;
        return 1;
    }
    if(this->noBtn.isPressed() && this->state->getKeyTime()){
        *openDialog = false;
        return 0;
    }
    return 2;
}

void gui::ConfirmDialog::render(sf::RenderTarget &target) {
    target.draw(this->dialog);
    target.draw(this->text);
    this->yesBtn.render(target);
    this->noBtn.render(target);
}

dialog_type gui::ConfirmDialog::getDialogType() {
    return this->dialogType;
}

void gui::ConfirmDialog::setSellValue(unsigned value) {
    this->sellValue = value;
}

unsigned gui::ConfirmDialog::getSellValue() {
    return this->sellValue;
}

/*
 *                      SHOPSLOT
 *
 */

//constructors/destructor
gui::ShopSlot::ShopSlot(){

};

gui::ShopSlot::ShopSlot(float width, float height, float pos_x, float pos_y, std::string key,
                        unsigned int price, sf::Font* font, Item* item) : key(key), item(item){

    this->mouseHoverImage = false;

    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setPosition(pos_x, pos_y);

    this->price = price * 1.5;

    this->priceLbl.setString(to_string(this->price));
    this->priceLbl.setFillColor(sf::Color::Yellow);
    this->priceLbl.setFont(*font);
    this->priceLbl.setCharacterSize(20);
    this->priceLbl.setPosition(this->shape.getPosition().x + 4.f,
            this->shape.getPosition().y + height - this->priceLbl.getGlobalBounds().height * 1.8f);

    this->buyBtn = new gui::Button(
            this->shape.getPosition().x,
            this->shape.getPosition().y + height,
            width, height/4.f,
            font, "Buy", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    this->buyBtn->setBorderColor(sf::Color(90,90,90));
    this->buyBtn->setBorderLineThickness(2.f);

    this->itemInfoContainer.setFillColor(sf::Color(90,90,90));
    this->itemInfoContainer.setOutlineColor(sf::Color(60,60,60));
    this->itemInfoContainer.setOutlineThickness(3.f);

    this->itemInfoLbl.setFont(*font);
    this->itemInfoLbl.setCharacterSize(18);
    this->itemInfoLbl << sf::Text::Bold << item->getName() << "\n"
    << "Type: " << item->getItemType() << "\n"
    << item->getRarity() << "\n"
    << sf::Text::Italic << "' " << item->getDescription() << " '";

    this->itemInfoContainer.setSize(sf::Vector2f(this->itemInfoLbl.getGlobalBounds().width + 10.f,
                                                  this->itemInfoLbl.getGlobalBounds().height + 15.f));

}

gui::ShopSlot::~ShopSlot() {
    delete this->buyBtn;
}

//accessors
Item *gui::ShopSlot::getItem() const {
    return this->item;
}

unsigned int gui::ShopSlot::getPrice() const {
    return this->price;
}

//modifiers

void gui::ShopSlot::setSlotTexture(const sf::Texture *texture, float size) {
    if(this->item != nullptr){
        this->shape.setTexture(texture);
        this->shape.setTextureRect(sf::IntRect(
                this->item->getIconRectX() * size,
                this->item->getIconRectY() * size,
                size, size));
        this->shape.setOutlineThickness(-3.f);
        if(this->item->getRarity() == "Uncommon"){
            this->shape.setOutlineColor(sf::Color::White);
        } else if(this->item->getRarity() == "Common"){
            this->shape.setOutlineColor(sf::Color::Green);
        } else if(this->item->getRarity() == "Rare"){
            this->shape.setOutlineColor(sf::Color::Blue);
        } else if(this->item->getRarity() == "Epic"){
            this->shape.setOutlineColor(sf::Color::Magenta);
        } else if(this->item->getRarity() == "Legendary"){
            this->shape.setOutlineColor(sf::Color(255,127,80));
        }
    }

}

//functions
bool gui::ShopSlot::isPressed() {
    return this->buyBtn->isPressed();
}

void gui::ShopSlot::updateItemInfoContainerPos(const sf::Vector2f &mousePos) {
    this->itemInfoContainer.setPosition(mousePos.x + 10.f,
                                         mousePos.y);
    this->itemInfoLbl.setPosition(this->itemInfoContainer.getPosition().x + 5.f,
                                   this->itemInfoContainer.getPosition().y);
}

void gui::ShopSlot::update(const sf::Vector2f &mousePos) {
    this->buyBtn->update(mousePos);
    if(this->shape.getGlobalBounds().contains(mousePos)){
        this->mouseHoverImage = true;
        this->updateItemInfoContainerPos(mousePos);
    }else{
        this->mouseHoverImage = false;
    }
}

void gui::ShopSlot::render(sf::RenderTarget &target) {
    target.draw(this->shape);
    target.draw(this->priceLbl);
    this->buyBtn->render(target);
    if(this->mouseHoverImage){
        target.draw(this->itemInfoContainer);
        target.draw(this->itemInfoLbl);
    }
}

/*
 *                      SPELLSLOT
 *
 */
gui::SpellSlot::SpellSlot(){

};

gui::SpellSlot::SpellSlot(float width, float height, float pos_x, float pos_y,  std::shared_ptr<Spell> spell,
        const sf::Texture* texture, float rect_size, sf::Font* font, unsigned int char_size) : spell(spell) {

    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setPosition(pos_x, pos_y);
    this->shape.setOutlineThickness(4.f);
    switch(spell->getTypeEnum()){
        case FIRE:
            this->shape.setOutlineColor(sf::Color(235, 70, 59));
            this->shape.setFillColor(sf::Color(235, 70, 59, 50));
            break;
        case WATER:
            this->shape.setOutlineColor(sf::Color(50, 83, 173));
            this->shape.setFillColor(sf::Color(50, 83, 173, 50));
            break;
        case ICE:
            this->shape.setOutlineColor(sf::Color(92, 193, 247));
            this->shape.setFillColor(sf::Color(92, 193, 247, 50));
            break;
        case ELECTRIC:
            this->shape.setOutlineColor(sf::Color(126, 0, 222));
            this->shape.setFillColor(sf::Color(126, 0, 222, 50));
            break;
        case HOLY:
            this->shape.setOutlineColor(sf::Color(255, 254, 173));
            this->shape.setFillColor(sf::Color(255, 254, 173, 50));
            break;
        default:
            this->shape.setOutlineColor(sf::Color::White);
            break;
    }


    float app = width / 4.0f;
    this->spellImage.setSize(sf::Vector2f(app, app));
    app = app /5.0f;
    this->spellImage.setPosition(this->shape.getPosition().x,
            this->shape.getPosition().y);
    this->spellImage.setTexture(texture);
    this->spellImage.setTextureRect(sf::IntRect(
            spell->getIntRectX() * rect_size,
            spell->getIntRectY() * rect_size,
            rect_size, rect_size));
    this->spellImage.setOutlineColor(sf::Color::White);

    //init texts
    this->spellInfoLbl.setFont(*font);
    this->spellInfoLbl.setCharacterSize(char_size);
  /*  this->spellInfoLbl << sf::Text::Bold << spell->getName() << "(" << spell->getType() << ")\n"
                        << "Damage: " << sf::Color(34, 0, 79) << to_string(spell->getDamage()) << "\n" << sf::Color::White
                        << "Cost: " << sf::Color::Blue << to_string(spell->getCost()) << sf::Color::White
                        << "\nCooldown: " << to_string(spell->getCooldown()) << " turn/s"
                        << "\nAoe: " << to_string(spell->getAoe()) << " target/s";*/

    this->spellInfoLbl.setPosition(this->spellImage.getPosition().x + this->spellImage.getGlobalBounds().width ,
            this->spellImage.getPosition().y);

    this->descriptionLbl.setFont(*font);
    this->descriptionLbl.setCharacterSize(char_size);
    this->descriptionLbl << sf::Text::Italic << spell->getDescription();
    this->descriptionLbl.setPosition(this->spellImage.getPosition().x + 10.f,
            this->spellImage.getPosition().y + this->spellImage.getGlobalBounds().height + app);
}

gui::SpellSlot::~SpellSlot() {

}

void gui::SpellSlot::update(const sf::Vector2f &mousePos) {

}

void gui::SpellSlot::render(sf::RenderTarget &target) {
    target.draw(this->shape);
    target.draw(this->spellImage);
    target.draw(this->spellInfoLbl);
    target.draw(this->descriptionLbl);
}

sfe::RichText* gui::SpellSlot::getSpellInfoLbl() {
    return &this->spellInfoLbl;
}

std::shared_ptr<Spell> gui::SpellSlot::getSpell() {
    return spell;
}

/*
 *                      WIZARDSPELLSLOT
 *
 */

//constructors/desctructor
gui::WizardSpellSlot::WizardSpellSlot(){

};

gui::WizardSpellSlot::WizardSpellSlot(float width, float height, float pos_x, float pos_y, std::shared_ptr<Spell> spell,
                                      const sf::Texture *texture, float rect_size, sf::Font *font,
                                      unsigned int char_size) : spell(spell){
    //init variables
    mouseHoverImage = false;

    //init containers
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(pos_x, pos_y);
    shape.setOutlineThickness(4.f);
    switch(spell->getTypeEnum()){
        case FIRE:
            shape.setOutlineColor(sf::Color(235, 70, 59, 100));
            shape.setFillColor(sf::Color(235, 70, 59, 50));
            spellImage.setOutlineColor(sf::Color(235, 70, 59));
            break;
        case WATER:
            shape.setOutlineColor(sf::Color(50, 83, 173, 100));
            shape.setFillColor(sf::Color(50, 83, 173, 50));
            spellImage.setOutlineColor(sf::Color(50, 83, 173));
            break;
        case ICE:
            shape.setOutlineColor(sf::Color(92, 193, 247, 100));
            shape.setFillColor(sf::Color(92, 193, 247, 50));
            spellImage.setOutlineColor(sf::Color(92, 193, 247));
            break;
        case ELECTRIC:
            shape.setOutlineColor(sf::Color(126, 0, 222, 100));
            shape.setFillColor(sf::Color(126, 0, 222, 50));
            spellImage.setOutlineColor(sf::Color(126, 0, 222));
            break;
        case HOLY:
            shape.setOutlineColor(sf::Color(255, 254, 173, 100));
            shape.setFillColor(sf::Color(255, 254, 173, 50));
            spellImage.setOutlineColor(sf::Color(255, 254, 173));
            break;
        default:
            shape.setOutlineColor(sf::Color::White);
            break;
    }

    spellImage.setSize(sf::Vector2f(height - 20.f, height - 20.f));
    spellImage.setPosition(shape.getPosition().x + 10.f,
                                 shape.getPosition().y + 10.f);
    spellImage.setTexture(texture);
    spellImage.setTextureRect(sf::IntRect(
            spell->getIntRectX() * rect_size,
            spell->getIntRectY() * rect_size,
            rect_size, rect_size));
    spellImage.setOutlineThickness(3.f);
    spellInfoContainer.setFillColor(sf::Color(90,90,90));
    spellInfoContainer.setOutlineColor(sf::Color(60,60,60));
    spellInfoContainer.setOutlineThickness(3.f);

    //init texts
    slotDescriptionLbl.setFont(*font);
    slotDescriptionLbl.setCharacterSize(char_size);
    slotDescriptionLbl.setPosition(spellImage.getPosition().x + spellImage.getGlobalBounds().width + 10.f,
            spellImage.getPosition().y);

    spellInfoLbl.setFont(*font);
    spellInfoLbl.setCharacterSize(char_size);

    //init btn
    slotBtn = std::make_shared<Button>(
            spellImage.getPosition().x + shape.getGlobalBounds().width - spellImage.getGlobalBounds().width - 40.f,
            spellImage.getPosition().y + 10.f,
            height, height - 40.f,
            font, "upgrade", 18.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 70),
            sf::Color(130, 130, 130));
    slotBtn->setBorderColor(sf::Color(120,120,120));
    slotBtn->setBackgroundFilLColor(sf::Color(120,120,120, 120));
    slotBtn->setBorderLineThickness(2.f);

    updateBtnText();
    updateSpellInfo();

}

gui::WizardSpellSlot::~WizardSpellSlot() {

}

std::shared_ptr<Spell> gui::WizardSpellSlot::getSpell() {
    return spell;
}

//accessors
sfe::RichText *gui::WizardSpellSlot::getSpellDescriptionLbl() {
    return &slotDescriptionLbl;
}

sfe::RichText *gui::WizardSpellSlot::getSpellInfoLbl() {
    return &spellInfoLbl;
}

//functions
bool gui::WizardSpellSlot::isBtnPressed() {
    return slotBtn->isPressed();
}

void gui::WizardSpellSlot::updateBtnText() {
    if(!spell->isLearned()){
        slotBtn->setText("Learn");
    }else if(spell->isMaxed() && spell->isLearned()){
        slotBtn->setText("Lv.Max");
        slotBtn->setButtonState(BTN_IDLE);
        slotBtn->setDisabled(true);
    }else{
        slotBtn->setText("Upgrade");
    }
}

void gui::WizardSpellSlot::updateSpellInfo() {
    spellInfoLbl.clear();
    if(spell->isLearned() && spell->isMaxed()){
        spellInfoLbl << sf::Text::Bold << spell->getName() << sf::Text::Regular
        << "(Lv" << to_string(spell->getLevel()) << ")"
        << "\n Damage: " << sf::Color(255, 60, 31) << to_string(spell->getFinalDamage()) << sf::Color::White
        << "\n Cost: " << sf::Color::Blue << to_string(spell->getFinalCost()) << " mp" << sf::Color::White;
    } else if(spell->isLearned()){
        spellInfoLbl << sf::Text::Bold << spell->getName() << sf::Text::Regular
        << "(Lv" << to_string(spell->getLevel()) << " -> Lv" << to_string(spell->getLevel()+1)<< ")"
        << "\n Damage: " << sf::Color(255, 60, 31) << to_string(spell->getFinalDamage())
        << " -> " << to_string(spell->getDamage()*(spell->getLevel()+1)) << sf::Color::White
        << "\n Cost: " << sf::Color::Blue << to_string(spell->getFinalCost())
        << " -> " << to_string(spell->getCost()*(spell->getLevel()+1)) << " mp" << sf::Color::White;
    } else if(!spell->isLearned()){
        spellInfoLbl << sf::Text::Bold << spell->getName() << sf::Text::Regular
        << "(Lv" << to_string(spell->getLevel()-1) << " -> Lv1)"
        << "\n Damage: " << sf::Color(255, 60, 31)
        << "0 -> " << to_string(spell->getDamage()) << sf::Color::White
        << "\n Cost: " << sf::Color::Blue
        << "0 -> " << to_string(spell->getCost()) << " mp" << sf::Color::White;
    }
    spellInfoLbl << "\n Cooldown: " << to_string(spell->getCooldown()) << " turn/s"
                       << "\n " << sf::Text::Italic << spell->getDescription();
    spellInfoContainer.setSize(sf::Vector2f(spellInfoLbl.getGlobalBounds().width + 10.f,
                                                 spellInfoLbl.getGlobalBounds().height + 15.f));
}

void gui::WizardSpellSlot::updateSpellInfoContainerPos(const sf::Vector2f& mousePos) {
    spellInfoContainer.setPosition(mousePos.x,
            mousePos.y - spellInfoContainer.getGlobalBounds().height);
    spellInfoLbl.setPosition(spellInfoContainer.getPosition().x + 5.f,
                                  spellInfoContainer.getPosition().y);
}

void gui::WizardSpellSlot::update(const sf::Vector2f &mousePos) {
    slotBtn->update(mousePos);
    if(spellImage.getGlobalBounds().contains(mousePos)){
        mouseHoverImage = true;
        updateSpellInfoContainerPos(mousePos);
    }else{
        mouseHoverImage = false;
    }
}

void gui::WizardSpellSlot::render(sf::RenderTarget &target) {
    target.draw(shape);
    target.draw(spellImage);
    target.draw(slotDescriptionLbl);
    slotBtn->render(target);
    if(mouseHoverImage){
        target.draw(spellInfoContainer);
        target.draw(spellInfoLbl);
    }
}

/*
 *                      PLAYERSTATUSPANEL
 *
 */

gui::PlayerStatusPanel::PlayerStatusPanel() {

}

gui::PlayerStatusPanel::PlayerStatusPanel(std::shared_ptr<Player> player, float x, float y, sf::Font* font) {
    this->player = std::move(player);
    this->font = font;

    x-=80.f;
    y-=50.f;
    shape.setSize(sf::Vector2f(160.f, 90.f));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color(20, 20, 20));

    infoText.setPosition(x + 5.f, y + 5.f);
    infoText.setFont(*this->font);
    infoText.setCharacterSize(20);
    stringstream ss;
    ss << "Player Lv." << this->player->getPlayerStats()->getLevel();
    infoText.setString(ss.str());

    hpBar = gui::ProgressBar(x + 5.f, y + infoText.getGlobalBounds().height + 14.f, 150.f, 25.f,
            0, this->player->getPlayerStats()->getMaxHp(),
            this->player->getPlayerStats()->getHp(), font);
    hpBar.setProgressShapeColor(sf::Color::Red);
    mpBar = gui::ProgressBar(x + 5.f, hpBar.getPosition().y + 30.f, 150.f, 25.f,
            0, this->player->getPlayerStats()->getMaxMp(),
            this->player->getPlayerStats()->getMp(), font);
    mpBar.setProgressShapeColor(sf::Color::Blue);
}

gui::PlayerStatusPanel::~PlayerStatusPanel() {

}

void gui::PlayerStatusPanel::update(const sf::Vector2f &mousePos) {
    hpBar.update(player->getPlayerStats()->getHp(), player->getPlayerStats()->getFinalHp());
    mpBar.update(player->getPlayerStats()->getMp(), player->getPlayerStats()->getFinalMp());
}

void gui::PlayerStatusPanel::render(sf::RenderTarget &target) {
    target.draw(shape);
    target.draw(infoText);
    hpBar.render(target);
    mpBar.render(target);
}

/*
 *                      EnemyStatusPanel
 *
 */


gui::EnemyStatusPanel::EnemyStatusPanel() {

}

gui::EnemyStatusPanel::EnemyStatusPanel(const std::shared_ptr<Enemy>& enemy, float x, float y,
        sf::Font *font, sf::Texture& selected_icon_texture, State* state, int id)
        : enemy(enemy), font(font), state(state), idPos(id){
    isSelected = false;
    isHovered = false;
    selectedIconAnimationKeyTime = 0.f;
    selectedIconAnimationMaxKeyTime = 10.f;
    isSelectedIconAnimated = false;

    x-=90.f;
    y-=50.f;
    shape.setSize(sf::Vector2f(180.f, 90.f));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color(20, 20, 20));

    selectedIcon.setTexture(&selected_icon_texture);
    selectedIcon.setSize(sf::Vector2f(150.f, 40.f));
    selectedIcon.setPosition(x + 15.f, y - 60.f);

    infoText.setPosition(x + 5.f, y + 5.f);
    infoText.setFont(*this->font);
    infoText.setCharacterSize(20);
    stringstream ss;
    ss << enemy->getName() << " Lv." << enemy->getLevel();
    infoText.setString(ss.str());

    hpBar = gui::ProgressBar(x + 5.f, y + infoText.getGlobalBounds().height + 14.f, 170.f, 25.f,
                             0, enemy->getMaxHp(), enemy->getHp(), font);
    hpBar.setProgressShapeColor(sf::Color::Red);
    mpBar = gui::ProgressBar(x + 5.f, hpBar.getPosition().y + 30.f, 170.f, 25.f,
                             0, enemy->getMaxMp(), enemy->getMp(), font);
    mpBar.setProgressShapeColor(sf::Color::Blue);
}

gui::EnemyStatusPanel::~EnemyStatusPanel() {

}

void gui::EnemyStatusPanel::update(const sf::Vector2f &mousePos, const float &dt, int& selected_id) {
    hpBar.update(enemy->getHp(), enemy->getMaxHp());
    mpBar.update(enemy->getMp(), enemy->getMaxMp());
    isSelected = selected_id == idPos;
    if(shape.getGlobalBounds().contains(mousePos)){
        shape.setOutlineColor(sf::Color::Cyan);
        shape.setOutlineThickness(5.f);
        isHovered = true;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && state->getKeyTime()){
            if(isSelected){
                selected_id = 10;
            }else{
                selected_id = idPos;
            }
            isSelected = !isSelected;
        }
    }else{
        shape.setOutlineThickness(0.f);
        isHovered = false;
    }
    if((selected_id == idPos) || isHovered)
        selectedIconAnimation(dt);
}

void gui::EnemyStatusPanel::render(sf::RenderTarget &target) {
    target.draw(shape);
    target.draw(infoText);
    hpBar.render(target);
    mpBar.render(target);
    if(isHovered || isSelected)
        target.draw(selectedIcon);
}

void gui::EnemyStatusPanel::selectedIconAnimation(const float &dt) {
    if(selectedIconAnimationKeyTime < selectedIconAnimationMaxKeyTime){
        selectedIconAnimationKeyTime += 40.f * dt;
    }else{
        if(!isSelectedIconAnimated){
            selectedIcon.setPosition(selectedIcon.getPosition().x, selectedIcon.getPosition().y + 8.f);
        }else{
            selectedIcon.setPosition(selectedIcon.getPosition().x, selectedIcon.getPosition().y - 8.f);
        }
        selectedIconAnimationKeyTime = 0.f;
        isSelectedIconAnimated = !isSelectedIconAnimated;
    }
}
