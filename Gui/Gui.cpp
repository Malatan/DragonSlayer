//
// Created by Zheng on 06/10/2020.
// componenti grafici customizzati

#include "Gui.h"
#include <iostream>
#include <sstream>

gui::Button::Button(float x, float y, float width, float height,
                    sf::Font *font, std::string text, unsigned character_size,
                    sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
                    sf::Color idle_color, sf::Color hover_color, sf::Color active_color, short unsigned id) {
    this->buttonState = BTN_IDLE;
    this->id = id;
    this->disabled = false;
    this->tooltipDisabled = true;
    this->backgroundDisabled = true;
    if(text.empty())
        this->textDisabled = true;
    else
        this->textDisabled = false;


    this->shape.setPosition(sf::Vector2f(x,y));
    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setFillColor(idle_color);
    this->shape.setOutlineThickness(1.f);
    this->shape.setOutlineColor(sf::Color::Transparent);

    this->background.setPosition(sf::Vector2f(x,y));
    this->background.setSize(sf::Vector2f(width, height));


    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(text_idle_color);
    this->text.setCharacterSize(character_size);
    this->text.setPosition(
            (this->shape.getPosition().x + width /2.f) - this->text.getGlobalBounds().width/2.f,
            (this->shape.getPosition().y + height /2.f) - this->text.getGlobalBounds().height/1.5f
    );

    //colore testo bottone
    this->textIdleColor = text_idle_color;
    this->textHoverColor = text_hover_color;
    this->textActiveColor = text_active_color;

    //colore sfondo bottone
    this->idleColor = idle_color;
    this->hoverColor = hover_color;
    this->activeColor = active_color;

    //tooltip
    this->tooltipContainer.setFillColor(sf::Color(71, 71, 71));

    this->tooltipText.setFont(*this->font);
    this->tooltipText.setCharacterSize(20);

}

gui::Button::~Button() {

}

//accessors
const bool gui::Button::isPressed() const {
    if(this->buttonState == BTN_ACTIVE){
        return true;
    }

    return false;
}

const std::string gui::Button::getText() const {
    return this->text.getString();
}

const short unsigned &gui::Button::getId() const {
    return this->id;
}

const bool gui::Button::isTooltipDisabled() {
    return this->tooltipDisabled;
}

sf::Vector2f gui::Button::getPosition() {
    return this->shape.getPosition();
}

//modifiers
void gui::Button::setPosition(float x, float y) {
    this->shape.setPosition(x,y);
    this->text.setPosition(
            (x + this->shape.getGlobalBounds().width /2.f) - this->text.getGlobalBounds().width/2.f,
            (y + this->shape.getGlobalBounds().height /2.f) - this->text.getGlobalBounds().height/1.5f
    );
}

void gui::Button::setPosition(sf::Vector2f pos) {
    this->shape.setPosition(pos);
    this->text.setPosition(
            (pos.x + this->shape.getGlobalBounds().width /2.f) - this->text.getGlobalBounds().width/2.f,
            (pos.y + this->shape.getGlobalBounds().height /2.f) - this->text.getGlobalBounds().height/1.5f
    );
}

void gui::Button::setSize(sf::Vector2f size) {
    this->shape.setSize(size);
}

void gui::Button::setText(const std::string text) {
    this->text.setString(text);
}

void gui::Button::setId(const short unsigned id) {
    this->id = id;
}

void gui::Button::setBorderColor(sf::Color color) {
    this->shape.setOutlineColor(color);
}

void gui::Button::setBorderLineThickness(float value) {
    this->shape.setOutlineThickness(value);
}

void gui::Button::setTextPosition(sf::Vector2f position) {
    this->text.setPosition(position);
}

void gui::Button::setTextPositionAddY(float y) {
    this->text.setPosition(this->text.getPosition().x, this->text.getPosition().y + y);
}

void gui::Button::setTooltipText(std::string text) {
    this->tooltipText.setString(text);
    this->tooltipContainer.setSize(sf::Vector2f(this->tooltipText.getGlobalBounds().width + 10.f,
                                                 this->tooltipText.getGlobalBounds().height + 15.f));
}

void gui::Button::setTooltipDisabled(bool b) {
    this->tooltipDisabled = b;
}

void gui::Button::setDisabled(bool b) {
    if(b){
        this->shape.setOutlineColor(sf::Color(128, 128, 128));
        this->text.setFillColor(sf::Color(128, 128, 128));
    } else{
        this->shape.setOutlineColor(sf::Color::White);
        this->text.setFillColor(sf::Color(this->textIdleColor));
    }
    this->disabled = b;
}

void gui::Button::setButtonState(button_states btnstates) {
    this->buttonState = btnstates;
}

void gui::Button::setBackgroundTexture(const sf::Texture* texture) {
    this->background.setTexture(texture);
}

void gui::Button::setBackbgroundDisabled(bool b) {
    this->backgroundDisabled = b;
}


//functions
void gui::Button::updateTooltipPos(const sf::Vector2f &mousePos) {
    this->tooltipContainer.setPosition(sf::Vector2f(mousePos.x,
            mousePos.y - this->tooltipContainer.getGlobalBounds().height));
    this->tooltipText.setPosition(this->tooltipContainer.getPosition().x + 5.f,
                                  this->tooltipContainer.getPosition().y);
}

void gui::Button::update(const sf::Vector2f& mousePos) {
    this->hover = false;
    if(!this->tooltipDisabled && this->shape.getGlobalBounds().contains(mousePos)){
        this->updateTooltipPos(mousePos);
        this->hover = true;
    }
    if(!this->disabled){
        //idle
        this->buttonState = BTN_IDLE;

        //hover
        if(this->shape.getGlobalBounds().contains(mousePos)){
            this->buttonState = BTN_HOVER;
            this->hover = true;
            //pressed
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                this->buttonState = BTN_ACTIVE;
            }
            if(!this->tooltipDisabled){
                this->updateTooltipPos(mousePos);
            }
        }
    }

    //cambia colore in base allo stato del bottone
    switch(this->buttonState){
        case BTN_IDLE:
            this->shape.setFillColor(this->idleColor);
            this->text.setFillColor(this->textIdleColor);
            break;
        case BTN_HOVER:
            this->shape.setFillColor(this->hoverColor);
            this->text.setFillColor(this->textHoverColor);
            break;
        case BTN_ACTIVE:
            this->shape.setFillColor(this->activeColor);
            this->text.setFillColor(this->textActiveColor);
            break;
    }
}

void gui::Button::render(sf::RenderTarget& target) {
    if(!this->backgroundDisabled){
        target.draw(this->background);
    }
    target.draw(this->shape);
    if(!this->textDisabled)
        target.draw(this->text);

    if(!this->tooltipDisabled && this->hover){
        target.draw(this->tooltipContainer);
        target.draw(this->tooltipText);
    }
}

bool gui::Button::contains(const sf::Vector2f &mousePos) {
    return this->shape.getGlobalBounds().contains(mousePos);
}


/*
 *
 *          PROGRESSBAR
 *
 */

gui::ProgressBar::ProgressBar(sf::Window *window, float x, float y, float width, float height, int min, int max, int currentValue, sf::Font *font)
: window(window), font(font), min(min), max(max), currentValue(currentValue){
    this->progressPercentage = 0.f;
    this->barShape.setSize(sf::Vector2f(width, height));
    this->barShape.setPosition(x, y);
    this->barShape.setFillColor(sf::Color::Transparent);
    this->barShape.setOutlineColor(sf::Color::Magenta);
    this->barShape.setOutlineThickness(2.f);

    this->progressShape.setFillColor(sf::Color::Green);
    this->progressShape.setSize(sf::Vector2f(width, height));
    this->progressShape.setPosition(x , y);

    this->text.setString("200/300");
    this->text.setFont(*this->font);
    this->text.setStyle(sf::Text::Bold);
    this->text.setCharacterSize(15.f);
    this->text.setOrigin(this->text.getGlobalBounds().width / 2.f,
            this->text.getGlobalBounds().height / 2.f);
    this->text.setPosition(this->barShape.getPosition().x + (this->barShape.getGlobalBounds().width / 2.f),
            this->barShape.getPosition().y + (this->barShape.getGlobalBounds().height / 2.8f));

}

gui::ProgressBar::~ProgressBar() {

}

sf::Vector2f gui::ProgressBar::getPosition() {
    return this->barShape.getPosition();
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
    this->currentValue = current;
    this->text.setString(ss.str());
    this->progressPercentage = (float)this->currentValue / (float)this->max;
    if(this->progressPercentage == 1){
        this->progressShape.setSize(sf::Vector2f(this->barShape.getGlobalBounds().width * this->progressPercentage -4.f,
                                                 this->progressShape.getGlobalBounds().height));
    } else{
        this->progressShape.setSize(sf::Vector2f(this->barShape.getGlobalBounds().width * this->progressPercentage,
                                                 this->progressShape.getGlobalBounds().height));
    }

}

void gui::ProgressBar::render(sf::RenderTarget &target) {
    target.draw(this->barShape);
    target.draw(this->progressShape);
    target.draw(this->text);
}




/*
 *                      ITEMSLOT
 *
 */

gui::ItemSlot::ItemSlot(float x, float y, float width, float height, int id,
        sf::Window* window, sf::Font *font, Item* item, State* state, bool isEquipSlot)
    : window(window), font(font), item(item), id(id), state(state), isEquipSlot(isEquipSlot){
    this->renderItemInfoContainer = false;
    this->renderRightClickMenu = false;
    this->isSelected = false;
    this->shape.setPosition(sf::Vector2f(x,y));
    this->shape.setSize(sf::Vector2f(width, height));
    if(this->isEquipSlot){
        this->shape.setOutlineThickness(-3.f);
        this->shape.setOutlineColor(sf::Color::Transparent);
    }


    this->downRight.setPosition(this->shape.getPosition().x + 42.f,
            this->shape.getPosition().y + 38.f);
    this->downRight.setSize(sf::Vector2f(15.f, 20.f));

    this->upRight.setPosition(this->shape.getPosition().x + 42.f,
                                this->shape.getPosition().y);
    this->upRight.setSize(sf::Vector2f(25.f, 25.f));

    this->cover.setPosition(sf::Vector2f(x,y));
    this->cover.setSize(sf::Vector2f(width, height));
    this->cover.setOutlineThickness(3.f);
    this->cover.setOutlineColor(sf::Color::Transparent);

    this->itemInfoContainer.setSize(sf::Vector2f(width*2, height*2));
    this->itemInfoContainer.setFillColor(sf::Color(71, 71, 71));

    this->itemInfoLbl.setFont(*this->font);
    this->itemInfoLbl.setCharacterSize(20);

    this->quantityLbl.setFont(*this->font);
    this->quantityLbl.setCharacterSize(20);
    if(this->item != nullptr){
        std::stringstream ss;
        ss << "x" << this->item->getQuantity();
        this->quantityLbl.setString(ss.str());
    }
    this->quantityLbl.setPosition(
            this->shape.getPosition().x +  5.f,
            this->shape.getPosition().y + 35.f
    );
}

gui::ItemSlot::~ItemSlot() {

}

int gui::ItemSlot::getId() {
    return this->id;
}

bool gui::ItemSlot::getIsSelected() {
    return this->isSelected;
}

bool gui::ItemSlot::hasItem() {
    return (this->item != nullptr);
}

void gui::ItemSlot::setSlotTexture(const sf::Texture *texture, float size) {
    if(this->item != nullptr){
        this->shape.setTexture(texture);
        this->intRect = sf::IntRect(
                this->item->getIconRectX() * size,
                this->item->getIconRectY() * size,
                size, size);
        this->shape.setTextureRect(this->intRect);
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
        this->updateItemInfo();
        this->itemInfoContainer.setSize(sf::Vector2f(this->itemInfoLbl.getGlobalBounds().width + 10.f,
                                                     this->itemInfoLbl.getGlobalBounds().height + 15.f));
    }

}

void gui::ItemSlot::setSlotTexture(sf::Texture* texture, sf::IntRect intRect) {
    this->shape.setTexture(texture);
    this->shape.setTextureRect(intRect);
}

void gui::ItemSlot::setDownRightTexture(sf::Texture *texture) {
    this->downRight.setTexture(texture);
}

void gui::ItemSlot::setUpRightTexture(sf::Texture *texture) {
    this->upRight.setTexture(texture);
}

void gui::ItemSlot::setSelectedBool(bool b) {
    this->isSelected = b;
}

void gui::ItemSlot::itemInfo(const sf::Vector2f &mousePos) {

}

void gui::ItemSlot::updateItemInfo() {
    if(this->item != nullptr){
        std::stringstream ss;
        ss << this->item->getName()
           << "\nType: " << this->item->getItemUsageTypeString()
           << "\n" << this->item->getRarity();
        if(this->item->getHp() !=0){
            ss << "\n+" << this->item->getHp() << " hp";
        }
        if(this->item->getMp() !=0){
            ss << "\n+" << this->item->getMp() << " mp";
        }
        if(this->item->getDamage() !=0){
            ss << "\n+" << this->item->getDamage() << " dmg";
        }
        if(this->item->getArmor() !=0){
            ss << "\n+" << this->item->getArmor() << " armor";
        }
        if(this->item->getCritChance() !=0){
            ss << "\n+" << this->item->getCritChance() << " % crit chance";
        }
        if(this->item->getEvadeChance() !=0){
            ss << "\n+" << this->item->getEvadeChance() << " % evade chance";
        }
        ss << "\n' " << this->item->getDescription() << "'";

        ss << "\nValue: " << this->item->getValue();

        this->itemInfoLbl.setString(ss.str());
        this->itemInfoContainer.setSize(sf::Vector2f(this->itemInfoLbl.getGlobalBounds().width + 10.f,
                                                     this->itemInfoLbl.getGlobalBounds().height + 15.f));
    }
}

void gui::ItemSlot::updateItemInfoPos(const sf::Vector2f &mousePos) {
    this->itemInfoContainer.setPosition(mousePos);
    this->itemInfoLbl.setPosition(this->itemInfoContainer.getPosition().x + 5.f,
                                  this->itemInfoContainer.getPosition().y);
}

void gui::ItemSlot::update(const sf::Vector2f &mousePos, int *updateSlot, bool inv) {

    //hover
    if(this->shape.getGlobalBounds().contains(mousePos)){
        //pressed
        if(this->item != nullptr){
            if(this->item->getIsNew()){
                this->item->setIsNew(false);
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->state->getKeyTime() && !this->isEquipSlot){
                this->slotState = SLOT_ACTIVE;
                this->renderItemInfoContainer = false;
                if(inv){
                    if(this->isSelected){
                        this->isSelected = false;
                        this->cover.setOutlineColor(sf::Color::Transparent);
                    } else{
                        this->isSelected = true;
                        this->cover.setOutlineColor(sf::Color::Cyan);
                    }
                }
            }
            if(this->hasItem()){
                this->renderItemInfoContainer = true;
                this->updateItemInfoPos(mousePos);
                this->window->setMouseCursorVisible(false);
                this->slotState = SLOT_HOVER;
                *updateSlot = this->id;
            }
        }
    } else{
        //idle
        this->slotState = SLOT_IDLE;
        this->renderItemInfoContainer = false;
        this->window->setMouseCursorVisible(true);
        *updateSlot = 100;
        if(this->isSelected){
            this->cover.setOutlineColor(sf::Color::Cyan);
        } else{
            this->cover.setOutlineColor(sf::Color::Transparent);
        }

    }

    //cambia colore in base allo stato del bottone
    switch(this->slotState){
        case SLOT_IDLE:
            this->cover.setFillColor(sf::Color::Transparent);
            break;
        case SLOT_HOVER:
            this->cover.setFillColor(sf::Color(212, 212, 212,70));
            break;
        case SLOT_ACTIVE:
            this->cover.setFillColor(sf::Color(112, 112, 112, 210));
            break;
    }
}

void gui::ItemSlot::render(sf::RenderTarget &target) {
    target.draw(this->shape);
    target.draw(this->cover);
    if(this->isSelected){
        target.draw(this->downRight);
    }

    if(this->item != nullptr && !this->isEquipSlot){
        if(this->item->getIsNew() || this->item->isEquipped()){
            target.draw(this->upRight);
        }
        if(this->item->isConsumable())
            target.draw(this->quantityLbl);
    }

    if(this->renderItemInfoContainer){
        target.draw(this->itemInfoContainer);
        target.draw(this->itemInfoLbl);
    }
   // target.draw(this->itemName);
}

Item *gui::ItemSlot::getItem() {
    return this->item;
}

void gui::ItemSlot::setItem(Item *item) {
    this->item = item;
}

sf::RectangleShape* gui::ItemSlot::getShape() {
    return &this->shape;
}

void gui::ItemSlot::setShapeTexture(const sf::Texture *texture, const sf::IntRect* intRect) {
    this->shape.setTexture(texture);
    this->shape.setTextureRect(*intRect);
}

sf::IntRect* gui::ItemSlot::getIntRect() {
    return &this->intRect;
}

void gui::ItemSlot::updateQuantityLbl() {
    if(this->item != nullptr){
        std:stringstream ss;
        ss << "x" << this->item->getQuantity();
        this->quantityLbl.setString(ss.str());
    }
}


/*
 *                      CONFIRM DIALOG
 *
 */


gui::ConfirmDialog::ConfirmDialog(float x, float y, std::string text, sf::Window* window, State* state, sf::Font* font, float characterSize,
                                  dialog_type dType) :
    window(window), state(state){
    this->sellValue = 0;
    this->dialogType = dType;
    this->window->setMouseCursorVisible(true);

    this->dialog.setSize(sf::Vector2f(500.f, 150.f));
    this->dialog.setPosition(x, y);
    this->dialog.setFillColor(sf::Color(61, 61, 61, 230));
    this->dialog.setOutlineColor(sf::Color(25, 25, 25, 200));
    this->dialog.setOutlineThickness(10.f);

    this->text.setString(text);
    this->text.setFont(*font);
    this->text.setCharacterSize(characterSize);
    this->text.setPosition(this->dialog.getPosition().x + (this->dialog.getGlobalBounds().width / 2.f) -
                                   (this->text.getGlobalBounds().width / 2.f) - 10.f,
            this->dialog.getPosition().y + (this->dialog.getGlobalBounds().height / 2.f) -
            this->text.getGlobalBounds().height / 2.f - 30.f);

    this->yesBtn = new Button(this->text.getPosition().x + (this->text.getGlobalBounds().width / 2.f) - 120.f,
                            this->text.getPosition().y + 50.f , 40.f, 30.f,
                             font, "Yes", 30,
                              sf::Color(38, 38, 38),
                              sf::Color(250, 250, 250, 250),
                              sf::Color(20, 20, 20, 50),
                              sf::Color::Transparent,
                              sf::Color(150, 150, 150, 0),
                              sf::Color(20, 20, 20, 0));


    this->noBtn = new Button(this->text.getPosition().x + (this->text.getGlobalBounds().width / 2.f) + 80.f,
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
    delete this->yesBtn;
    delete this->noBtn;
}

int gui::ConfirmDialog::update(const sf::Vector2f &mousePos, bool* openDialog) {
    this->yesBtn->update(mousePos);
    this->noBtn->update(mousePos);
    if(this->yesBtn->isPressed() && this->state->getKeyTime()){
        *openDialog = false;
        return 1;
    }
    if(this->noBtn->isPressed() && this->state->getKeyTime()){
        *openDialog = false;
        return 0;
    }
    return 2;
}

void gui::ConfirmDialog::render(sf::RenderTarget &target) {
    target.draw(this->dialog);
    target.draw(this->text);
    this->yesBtn->render(target);
    this->noBtn->render(target);
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
gui::ShopSlot::ShopSlot(float width, float height, float pos_x, float pos_y, std::string key,
                        unsigned price, sf::Font* font, Item* item) : key(key), item(item){

    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setPosition(pos_x, pos_y);

    this->price = price * 1.5;

    this->priceLbl.setString(to_string(this->price));
    this->priceLbl.setFillColor(sf::Color::Yellow);
    this->priceLbl.setFont(*font);
    this->priceLbl.setCharacterSize(20.f);
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
}

gui::ShopSlot::~ShopSlot() {
    delete this->buyBtn;
}

//accessors


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

void gui::ShopSlot::update(const sf::Vector2f &mousePos) {
    this->buyBtn->update(mousePos);
}

void gui::ShopSlot::render(sf::RenderTarget &target) {
    target.draw(this->shape);
    target.draw(this->priceLbl);
    this->buyBtn->render(target);
}

Item *gui::ShopSlot::getItem() const {
    return this->item;
}

const unsigned gui::ShopSlot::getPrice() const {
    return this->price;
}

/*
 *                      SPELLSLOT
 *
 */

gui::SpellSlot::SpellSlot(float width, float height, float pos_x, float pos_y, Spell *spell,
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

Spell *gui::SpellSlot::getSpell() {
    return this->spell;
}
