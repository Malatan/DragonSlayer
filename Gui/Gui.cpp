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

    this->shape.setPosition(sf::Vector2f(x,y));
    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setFillColor(idle_color);
    this->shape.setOutlineThickness(1.f);
    this->shape.setOutlineColor(sf::Color::Transparent);

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


//functions
void gui::Button::update(const sf::Vector2f& mousePos) {

    if(!this->disabled){
        //idle
        this->buttonState = BTN_IDLE;

        //hover
        if(this->shape.getGlobalBounds().contains(mousePos)){
            this->buttonState = BTN_HOVER;
            //pressed
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                this->buttonState = BTN_ACTIVE;
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
    target.draw(this->shape);
    target.draw(this->text);
}

sf::Vector2f gui::Button::getPosition() {
    return this->shape.getPosition();
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
    this->itemInfoLbl.setCharacterSize(20.f);

    this->quantityLbl.setFont(*this->font);
    this->quantityLbl.setCharacterSize(20.f);
    if(this->item != nullptr){
        std:stringstream ss;
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
           << "\nType: " << this->item->getItemUsageType()
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


gui::ConfirmDialog::ConfirmDialog(float x, float y, std::string text, sf::Window* window, State* state, sf::Font* font, float characterSize) :
    window(window), state(state){
    this->dialog.setSize(sf::Vector2f(500.f, 150.f));
    this->dialog.setPosition(x, y);
    this->dialog.setFillColor(sf::Color(61, 61, 61, 230));

    this->text.setString(text);
    this->text.setFont(*font);
    this->text.setCharacterSize(characterSize);
    this->text.setPosition(this->dialog.getPosition().x + (this->dialog.getGlobalBounds().width / 2.f) -
            this->text.getGlobalBounds().width / 2.f,
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
