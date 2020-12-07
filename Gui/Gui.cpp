//
// Created by Zheng on 06/10/2020.
// componenti grafici customizzati

#include "Gui.h"
#include <iostream>
#include <utility>

gui::Button::Button()= default;

gui::Button::Button(float x, float y, float width, float height,
                    sf::Font *font, const std::string& text, unsigned character_size, short unsigned id) {
    buttonState = BTN_IDLE;
    this->id = id;
    disabled = false;
    tooltipDisabled = true;
    backgroundDisabled = true;
    textDisabled = text.empty();
    hover = false;

    //colore testo bottone
    textIdleColor = sf::Color(38, 38, 38);
    textHoverColor = sf::Color(250, 250, 250, 250);
    textActiveColor = sf::Color(20, 20, 20, 50);

    //colore sfondo bottone
    idleColor = sf::Color::Transparent;
    hoverColor = sf::Color(150, 150, 150, 0);
    activeColor = sf::Color(20, 20, 20, 0);

    shape.setPosition(sf::Vector2f(x,y));
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(idleColor);
    shape.setOutlineThickness(1.f);
    shape.setOutlineColor(sf::Color::Transparent);

    background.setPosition(sf::Vector2f(x,y));
    background.setSize(sf::Vector2f(width, height));


    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(textIdleColor);
    this->text.setCharacterSize(character_size);
    this->text.setPosition(
            (shape.getPosition().x + width /2.f) - this->text.getGlobalBounds().width/2.f,
            (shape.getPosition().y + height /2.f) - this->text.getGlobalBounds().height/1.5f
    );

    //tooltip
    tooltipContainer.setFillColor(sf::Color(71, 71, 71));

    tooltipText.setFont(*this->font);
    tooltipText.setCharacterSize(20);

}

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

gui::Button::~Button() = default;

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

void gui::Button::setText(const std::string& new_text) {
    this->text.setString(new_text);
    this->text.setPosition(
            (shape.getPosition().x + shape.getGlobalBounds().width /2.f) - this->text.getGlobalBounds().width/2.f,
            (shape.getPosition().y + shape.getGlobalBounds().height /2.f) - this->text.getGlobalBounds().height/1.5f
    );
}

void gui::Button::setId(const short unsigned new_id) {
    this->id = new_id;
}

void gui::Button::setBorderColor(sf::Color color) {
    shape.setOutlineColor(color);
}

void gui::Button::setBorderLineThickness(float value) {
    shape.setOutlineThickness(value);
}

void gui::Button::setTextPositionAddY(float y) {
    this->text.setPosition(this->text.getPosition().x, this->text.getPosition().y + y);
}

void gui::Button::setTooltipText(const std::string& new_text) {
    tooltipText.setString(new_text);
    tooltipContainer.setSize(sf::Vector2f(tooltipText.getGlobalBounds().width + 10.f,
                                                 tooltipText.getGlobalBounds().height + 15.f));
}

void gui::Button::setTooltipDisabled(bool b) {
    tooltipDisabled = b;
}

void gui::Button::setDisabled(bool b, bool change_color) {
    if(change_color){
        if(b){
            shape.setOutlineColor(sf::Color(128, 128, 128));
            text.setFillColor(sf::Color(128, 128, 128));
        } else{
            shape.setOutlineColor(sf::Color::White);
            text.setFillColor(sf::Color(textIdleColor));
        }
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

bool gui::Button::isDisabled() const {
    return disabled;
}


/*
 *
 *          PROGRESSBAR
 *
 */
gui::ProgressBar::ProgressBar() = default;

gui::ProgressBar::ProgressBar(float x, float y, float width, float height, int min, int max, int currentValue, sf::Font *font)
: font(font), min(min), max(max), currentValue(currentValue){
    progressPercentage = 0.f;
    barShape.setSize(sf::Vector2f(width, height));
    barShape.setPosition(x, y);
    barShape.setFillColor(sf::Color::Transparent);
    barShape.setOutlineColor(sf::Color::Transparent);
    barShape.setOutlineThickness(2.f);

    progressShape.setFillColor(sf::Color::Green);
    progressShape.setSize(sf::Vector2f(width, height));
    progressShape.setPosition(x , y);

    text.setString("10/10");
    text.setFont(*font);
    text.setStyle(sf::Text::Bold);
    text.setCharacterSize(15.f);
    text.setPosition(barShape.getPosition().x + (barShape.getGlobalBounds().width / 2.f) - text.getGlobalBounds().width/2.f,
            barShape.getPosition().y + (barShape.getGlobalBounds().height / 2.f) - text.getGlobalBounds().height/2.f);

}

gui::ProgressBar::~ProgressBar() = default;

sf::Vector2f gui::ProgressBar::getPosition() {
    return barShape.getPosition();
}

void gui::ProgressBar::setText(const std::string& new_text) {
    this->text.setString(new_text);
}

void gui::ProgressBar::setProgressShapeColor(sf::Color color) {
    this->progressShape.setFillColor(color);
}

void gui::ProgressBar::setProgressBorderColor(sf::Color color) {
    this->barShape.setOutlineColor(color);
}

void gui::ProgressBar::update(int current, int max_value) {
    std::stringstream ss;
    ss << current << "/" << max_value;
    max = max_value;
    currentValue = current;
    text.setString(ss.str());
    text.setPosition(barShape.getPosition().x + (barShape.getGlobalBounds().width / 2.f) - text.getGlobalBounds().width/2.f,
                     barShape.getPosition().y + (barShape.getGlobalBounds().height / 2.f) - text.getGlobalBounds().height);
    progressPercentage = (float)currentValue / (float)max_value;
    if(progressPercentage == 0.f){
        progressShape.setSize(sf::Vector2f(barShape.getGlobalBounds().width * progressPercentage,
                                           progressShape.getGlobalBounds().height));
    }else{
        progressShape.setSize(sf::Vector2f(barShape.getGlobalBounds().width * progressPercentage - 4.f,
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
gui::ItemSlot::ItemSlot()= default;

gui::ItemSlot::ItemSlot(float x, float y, float width, float height,
        std::shared_ptr<sf::RenderWindow> window, sf::Font *font, const std::shared_ptr<Item>& item, State* state, bool isEquipSlot)
    : window(std::move(window)), font(font), item(item), isEquipSlot(isEquipSlot){
    renderItemInfoContainer = false;
    isSelected = false;
    shape.setPosition(sf::Vector2f(x,y));
    shape.setSize(sf::Vector2f(width, height));
    this->state = state;
    if(isEquipSlot){
        shape.setOutlineThickness(-3.f);
        shape.setOutlineColor(sf::Color::Transparent);
    }

    downRight.setPosition(shape.getPosition().x + 42.f, shape.getPosition().y + 38.f);
    downRight.setSize(sf::Vector2f(15.f, 20.f));

    upRight.setPosition(shape.getPosition().x + 42.f, shape.getPosition().y);
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
    quantityLbl.setFillColor(sf::Color(0, 0, 0));
    if(item != nullptr){
        std::stringstream ss;
        ss << "x" << item->getQuantity();
        quantityLbl.setString(ss.str());
    }
    quantityLbl.setPosition(
            shape.getPosition().x +  5.f,
            shape.getPosition().y + 35.f
    );

    itemInfoContainer.setFillColor(sf::Color(90,90,90));
    itemInfoContainer.setOutlineColor(sf::Color(60,60,60));
    itemInfoContainer.setOutlineThickness(3.f);
}

gui::ItemSlot::~ItemSlot() = default;

bool gui::ItemSlot::getIsSelected() const {
    return isSelected;
}

void gui::ItemSlot::setSlotTexture(const sf::Texture *new_texture, float size) {
    shape.setTexture(new_texture);
    intRect = sf::IntRect(
            item->getIconRectX() * (int)size,
            item->getIconRectY() * (int)size,
            size, size);
    shape.setTextureRect(intRect);
    shape.setOutlineThickness(-3.f);
    if(item->getRarity() == "Uncommon"){
        shape.setOutlineColor(sf::Color::White);
        itemInfoContainer.setOutlineColor(sf::Color::White);
    } else if(item->getRarity() == "Common"){
        shape.setOutlineColor(sf::Color::Green);
        itemInfoContainer.setOutlineColor(sf::Color::Green);
    } else if(item->getRarity() == "Rare"){
        shape.setOutlineColor(sf::Color::Blue);
        itemInfoContainer.setOutlineColor(sf::Color::Blue);
    } else if(item->getRarity() == "Epic"){
        shape.setOutlineColor(sf::Color::Magenta);
        itemInfoContainer.setOutlineColor(sf::Color::Magenta);
    } else if(item->getRarity() == "Legendary"){
        shape.setOutlineColor(sf::Color(255,127,80));
        itemInfoContainer.setOutlineColor(sf::Color(255,127,80));
    }
    updateItemInfo();
    itemInfoContainer.setSize(sf::Vector2f(itemInfoLbl.getGlobalBounds().width + 10.f,
                                           itemInfoLbl.getGlobalBounds().height + 15.f));
}

void gui::ItemSlot::setSlotTexture(sf::Texture* new_texture, sf::IntRect texture_intRect) {
    shape.setTexture(new_texture);
    shape.setTextureRect(texture_intRect);
}

void gui::ItemSlot::setDownRightTexture(sf::Texture *new_texture) {
    downRight.setTexture(new_texture);
}

void gui::ItemSlot::setUpRightTexture(sf::Texture *new_texture) {
    upRight.setTexture(new_texture);
}

void gui::ItemSlot::setSelectedBool(bool b) {
    isSelected = b;
}

void gui::ItemSlot::updateQuantityLbl() {
    if(item != nullptr){
        std::stringstream ss;
        ss << "x" << item->getQuantity();
        quantityLbl.setString(ss.str());
    }
}

void gui::ItemSlot::updateItemInfo() {
    if(item != nullptr){
        std::stringstream ss;
        ss << item->getName()
           << "\nType: " << item->getItemUsageTypeString()
           << "\nTier: " << item->getRarity();
        if(item->getHp() !=0)
            ss << "\n+" << item->getHp() << " hp";
        if(item->getMp() !=0)
            ss << "\n+" << item->getMp() << " mp";
        if(item->getDamage() !=0)
            ss << "\n+" << item->getDamage() << " dmg";
        if(item->getArmor() !=0 && item->getUsageType() != SHIELD_USAGE)
            ss << "\n+" << item->getArmor() << " armor";
        if(item->getCritChance() !=0)
            ss << "\n+" << item->getCritChance() << " % crit chance";
        if(item->getEvadeChance() !=0)
            ss << "\n+" << item->getEvadeChance() << " % evade chance";
        if(item->isDescriptionWrapped()){
            ss << "\n\" " << item->getDescription();
        }else{
            float line_length = 200.f;
            itemInfoLbl.setString(ss.str());
            if(itemInfoLbl.getGlobalBounds().width > 200.f){
                line_length = itemInfoLbl.getGlobalBounds().width;
            }
            std::string wrapped_desc = utils::textWrap(itemInfoLbl, item->getDescription(), line_length);
            item->setDescription(wrapped_desc);
            item->setDescriptionWrapped(true);
            ss << "\n\" " << wrapped_desc;
        }
        ss << " \"\nValue: " << item->getValue();

        itemInfoLbl.setString(ss.str());
        itemInfoContainer.setSize(sf::Vector2f(itemInfoLbl.getGlobalBounds().width + 10.f,
                                                     itemInfoLbl.getGlobalBounds().height + 15.f));
    }
}

void gui::ItemSlot::updateItemInfoPos(const sf::Vector2f &mousePos) {
    bool out_width = false;
    itemInfoContainer.setPosition(mousePos.x + 10.f, mousePos.y);
    if(itemInfoContainer.getPosition().x + itemInfoContainer.getGlobalBounds().width > window->getSize().x){
        itemInfoContainer.setPosition(mousePos.x - itemInfoContainer.getGlobalBounds().width, mousePos.y);
        out_width = true;
    }
    if(itemInfoContainer.getPosition().y + itemInfoContainer.getGlobalBounds().height > window->getSize().y){
        itemInfoContainer.setPosition(mousePos.x, mousePos.y - itemInfoContainer.getGlobalBounds().height);
        if(out_width){
            itemInfoContainer.setPosition(mousePos.x - itemInfoContainer.getGlobalBounds().width,
                                          mousePos.y - itemInfoContainer.getGlobalBounds().height);
        }
    }
    itemInfoLbl.setPosition(itemInfoContainer.getPosition().x + 5.f,
                                  itemInfoContainer.getPosition().y);
}

void gui::ItemSlot::update(const sf::Vector2f &mousePos, bool inv) {
    //hover
    if(shape.getGlobalBounds().contains(mousePos) && item){
        //pressed
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
        if(item->getIsNew())
            item->setIsNew(!item->getIsNew());
        renderItemInfoContainer = true;
        updateItemInfoPos(mousePos);
        slotState = SLOT_HOVER;
    } else{
        //idle
        slotState = SLOT_IDLE;
        renderItemInfoContainer = false;
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

void gui::ItemSlot::renderInfoContainer(sf::RenderTarget &target) {
    if(renderItemInfoContainer){
        target.draw(itemInfoContainer);
        target.draw(itemInfoLbl);
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
        if(item->canBeMultiple())
            target.draw(quantityLbl);
    }
}

std::shared_ptr<Item> gui::ItemSlot::getItem() {
    return item;
}

void gui::ItemSlot::setItem(std::shared_ptr<Item> new_item) {
    item = std::move(new_item);
}

sf::RectangleShape* gui::ItemSlot::getShape() {
    return &shape;
}

void gui::ItemSlot::setShapeTexture(const sf::Texture *new_shape_texture, const sf::IntRect* texture_intRect) {
    shape.setTexture(new_shape_texture);
    shape.setTextureRect(*texture_intRect);
}

sf::IntRect* gui::ItemSlot::getIntRect() {
    return &intRect;
}

void gui::ItemSlot::setOutlineColors(sf::Color new_color) {
    shape.setOutlineColor(new_color);
    itemInfoContainer.setOutlineColor(new_color);
}

/*
 *                      CONFIRM DIALOG
 *
 */

gui::CustomDialog::CustomDialog()= default;

gui::CustomDialog::CustomDialog(float x, float y, std::shared_ptr<Item> item,
                                State* state, sf::Font* font, dialog_type dType) : item(std::move(item)), state(state){
    dialogType = dType;
    currentQuantity = 1;
    maxQuantity = this->item->getQuantity();
    singleQuantity = maxQuantity == 1;
    answer = PENDING_RESULT;

    dialog.setSize(sf::Vector2f(600.f, 150.f));
    dialog.setPosition(x - 300.f, y - 75.f);
    dialog.setFillColor(sf::Color(61, 61, 61, 230));
    dialog.setOutlineColor(sf::Color(25, 25, 25, 200));
    dialog.setOutlineThickness(10.f);

    textLbl.setFont(*font);
    textLbl.setCharacterSize(25);

    quantityLbl.setFont(*font);
    quantityLbl.setCharacterSize(20);

    updateLbls();
    initButtons(font);
    if(singleQuantity){
        plusOneBtn.setDisabled(true, false);
        plusFiveBtn.setDisabled(true, false);
        maxBtn.setDisabled(true, false);
        minusOneBtn.setDisabled(true, false);
        minusFiveBtn.setDisabled(true, false);
        minBtn.setDisabled(true, false);
    }
}

gui::CustomDialog::CustomDialog(float x, float y, int tot_value, int selected_quantity,
                                State* state, sf::Font* font, dialog_type dType) : state(state){
    dialogType = dType;
    multipleItem = true;
    answer = PENDING_RESULT;
    totValue = tot_value;

    dialog.setSize(sf::Vector2f(500.f, 120.f));
    dialog.setPosition(x - 250.f, y - 60.f);
    dialog.setFillColor(sf::Color(61, 61, 61, 230));
    dialog.setOutlineColor(sf::Color(25, 25, 25, 200));
    dialog.setOutlineThickness(10.f);

    stringstream ss;
    switch (dType) {
        case DELETE_CONFIRM:
            ss << "Deleting selected " << selected_quantity << " items";
            break;
        case SELL_CONFIRM:
            ss << "Selling selected " << selected_quantity << " items for " << tot_value << " gold";
            break;
    }
    textLbl.setString(ss.str());
    textLbl.setFont(*font);
    textLbl.setCharacterSize(22);
    textLbl.setPosition(dialog.getPosition().x + dialog.getGlobalBounds().width/2.f - textLbl.getGlobalBounds().width/2.f,
                        dialog.getPosition().y + 10.f + 5.f);

    yesBtn = Button(dialog.getPosition().x + dialog.getGlobalBounds().width/2.f - 30.f - 40.f,
                    textLbl.getPosition().y + textLbl.getGlobalBounds().height + 30.f,
                    40.f, 30.f, font, "Yes", 30);

    noBtn = Button(dialog.getPosition().x + dialog.getGlobalBounds().width/2.f + 30.f,
                   yesBtn.getPosition().y,
                   40.f, 30.f, font, "No", 30);
}

gui::CustomDialog::~CustomDialog() = default;

void gui::CustomDialog::updateLbls() {
    stringstream ss;
    switch (dialogType) {
        case DELETE_CONFIRM:
            ss << "Deleting " << currentQuantity << " " << item->getName();
            textLbl.setString(ss.str());
            ss.str("");
            ss << currentQuantity << "/" << maxQuantity;
            quantityLbl.setString(ss.str());
            break;
        case SELL_CONFIRM:
            ss << "Selling " << currentQuantity << " " << item->getName() << " for " << item->getValue()*currentQuantity
               << " gold, " << item->getValue() << " each";
            textLbl.setString(ss.str());
            ss.str("");
            ss << currentQuantity << "/" << maxQuantity;
            quantityLbl.setString(ss.str());
            break;
    }
    textLbl.setPosition(dialog.getPosition().x + dialog.getGlobalBounds().width/2.f - textLbl.getGlobalBounds().width/2.f,
                        dialog.getPosition().y + 15.f);
    quantityLbl.setPosition(dialog.getPosition().x + dialog.getGlobalBounds().width/2.f - quantityLbl.getGlobalBounds().width/2.f,
                            dialog.getPosition().y + textLbl.getGlobalBounds().height + 20.f);


}

void gui::CustomDialog::update(const sf::Vector2f &mousePos) {
    yesBtn.update(mousePos);
    noBtn.update(mousePos);
    if(!multipleItem){
        if(!singleQuantity){
            plusOneBtn.update(mousePos);
            plusFiveBtn.update(mousePos);
            maxBtn.update(mousePos);
            minusOneBtn.update(mousePos);
            minusFiveBtn.update(mousePos);
            minBtn.update(mousePos);
            if(plusOneBtn.isPressed() && state->getKeyTime()){
                if(currentQuantity < maxQuantity)
                    currentQuantity++;
            } else if(plusFiveBtn.isPressed() && state->getKeyTime()){
                if(currentQuantity < maxQuantity){
                    currentQuantity += 5;
                    if(currentQuantity > maxQuantity)
                        currentQuantity = maxQuantity;
                }
            } else if(maxBtn.isPressed() && state->getKeyTime()){
                currentQuantity = maxQuantity;
            } else if(minusOneBtn.isPressed() && state->getKeyTime()){
                if(currentQuantity > 1)
                    currentQuantity--;
            } else if(minusFiveBtn.isPressed() && state->getKeyTime()){
                if(currentQuantity > 1){
                    currentQuantity -= 5;
                    if(currentQuantity < 0)
                        currentQuantity = 1;
                }
            } else if(minBtn.isPressed() && state->getKeyTime()){
                currentQuantity = 1;
            }
        }
        updateLbls();
    }
    if(yesBtn.isPressed() && state->getKeyTime()){
        answer = YES_RESULT;
    } else if(noBtn.isPressed() && state->getKeyTime()){
        answer = NO_RESULT;
    }
}

void gui::CustomDialog::render(sf::RenderTarget &target) {
    target.draw(dialog);
    target.draw(textLbl);
    yesBtn.render(target);
    noBtn.render(target);
    if(!multipleItem){
        target.draw(quantityLbl);
        plusOneBtn.render(target);
        plusFiveBtn.render(target);
        maxBtn.render(target);
        minusOneBtn.render(target);
        minusFiveBtn.render(target);
        minBtn.render(target);
    }
}

dialog_type gui::CustomDialog::getDialogType() {
    return dialogType;
}

void gui::CustomDialog::initButtons(sf::Font* font) {
    plusOneBtn = Button(dialog.getPosition().x + dialog.getGlobalBounds().width/2.f + 4.f,
                        quantityLbl.getPosition().y + quantityLbl.getGlobalBounds().height + 5.f,
                        40.f, 30.f, font, "+1", 30);

    plusFiveBtn = Button(plusOneBtn.getPosition().x + plusOneBtn.getGlobalBounds().width + 8.f,
                         plusOneBtn.getPosition().y,
                         40.f, 30.f, font, "+5", 30);

    maxBtn = Button(plusFiveBtn.getPosition().x + plusFiveBtn.getGlobalBounds().width + 8.f,
                    plusFiveBtn.getPosition().y,
                    40.f, 30.f, font, "Max", 30);

    minusOneBtn = Button(plusOneBtn.getPosition().x - plusOneBtn.getGlobalBounds().width - 8.f,
                         plusOneBtn.getPosition().y,
                         40.f, 30.f, font, "-1", 30);

    minusFiveBtn = Button(minusOneBtn.getPosition().x - minusOneBtn.getGlobalBounds().width - 8.f,
                          minusOneBtn.getPosition().y,
                          40.f, 30.f, font, "-5", 30);

    minBtn = Button(minusFiveBtn.getPosition().x - minusFiveBtn.getGlobalBounds().width - 8.f,
                    minusFiveBtn.getPosition().y,
                    40.f, 30.f, font, "Min", 30);

    yesBtn = Button(dialog.getPosition().x + dialog.getGlobalBounds().width/2.f - 30.f - 40.f,
                    minBtn.getPosition().y + minBtn.getGlobalBounds().height + 5.f,
                    40.f, 30.f, font, "Yes", 30);

    noBtn = Button(dialog.getPosition().x + dialog.getGlobalBounds().width/2.f + 30.f,
                   minBtn.getPosition().y + minBtn.getGlobalBounds().height + 5.f,
                   40.f, 30.f, font, "No", 30);

}

dialog_result gui::CustomDialog::getResult() {
    return answer;
}

int gui::CustomDialog::getFinalQuantity() const {
    return currentQuantity;
}

std::shared_ptr<Item> gui::CustomDialog::getItem() {
    return item;
}

int gui::CustomDialog::getTotValue() const {
    return totValue;
}

/*
 *                      SHOPSLOT
 *
 */

//constructors/destructor
gui::ShopSlot::ShopSlot()= default;

gui::ShopSlot::ShopSlot(float width, float height, float pos_x, float pos_y, sf::Font* font, Item item, std::string  key)
                    : item(item), key(std::move(key)){
    mouseHoverImage = false;
    price = (unsigned int)(item.getValue() * 1.5);

    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(pos_x, pos_y);

    priceLbl.setString(to_string(price));
    priceLbl.setFillColor(sf::Color::Yellow);
    priceLbl.setFont(*font);
    priceLbl.setCharacterSize(20);
    priceLbl.setPosition(shape.getPosition().x + 4.f,
            shape.getPosition().y + height - priceLbl.getGlobalBounds().height * 1.8f);

    buyBtn = gui::Button(
            shape.getPosition().x,
            shape.getPosition().y + height + 4.f,
            width, height/4.f,
            font, "Buy", 20.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(130, 130, 130));
    buyBtn.setBorderColor(sf::Color(90,90,90));
    buyBtn.setBorderLineThickness(2.f);

    itemInfoContainer.setFillColor(sf::Color(90,90,90));
    itemInfoContainer.setOutlineColor(sf::Color(60,60,60));
    itemInfoContainer.setOutlineThickness(3.f);

    itemInfoLbl.setFont(*font);
    itemInfoLbl.setCharacterSize(18);
    stringstream ss;
    ss << item.getName() << std::endl
       << "Type: " << item.getItemUsageTypeString() << std::endl
       << item.getRarity() << std::endl
       << "   " << item.getDescription() << std::endl
       << "Value: " << price;
    itemInfoLbl.setString(utils::textWrap(itemInfoLbl, ss.str(), 250.f));

    itemInfoContainer.setSize(sf::Vector2f(itemInfoLbl.getGlobalBounds().width + 10.f,
                                                  itemInfoLbl.getGlobalBounds().height + 15.f));
}

gui::ShopSlot::~ShopSlot() = default;

//accessors
Item gui::ShopSlot::getItem() const {
    return item;
}

unsigned int gui::ShopSlot::getPrice() const {
    return price;
}

//modifiers
void gui::ShopSlot::setSlotTexture(const sf::Texture *slot_texture, float size) {
    shape.setTexture(slot_texture);
    shape.setTextureRect(sf::IntRect(
            item.getIconRectX() * (int)size,
            item.getIconRectY() * (int)size,
            size, size));
    shape.setOutlineThickness(2.f);
    if(item.getRarity() == "Uncommon"){
        shape.setOutlineColor(sf::Color::White);
    } else if(item.getRarity() == "Common"){
        shape.setOutlineColor(sf::Color::Green);
    } else if(item.getRarity() == "Rare"){
        shape.setOutlineColor(sf::Color::Blue);
    } else if(item.getRarity() == "Epic"){
        shape.setOutlineColor(sf::Color::Magenta);
    } else if(item.getRarity() == "Legendary"){
        shape.setOutlineColor(sf::Color(255,127,80));
    }
}

//functions

bool gui::ShopSlot::isPressed() {
    return buyBtn.isPressed();
}

void gui::ShopSlot::updateItemInfoContainerPos(const sf::Vector2f &mousePos) {
    itemInfoContainer.setPosition(mousePos.x + 10.f,
                                         mousePos.y);
    itemInfoLbl.setPosition(itemInfoContainer.getPosition().x + 5.f,
                                   itemInfoContainer.getPosition().y);
}

void gui::ShopSlot::update(const sf::Vector2f &mousePos) {
    buyBtn.update(mousePos);
    if(shape.getGlobalBounds().contains(mousePos)){
        mouseHoverImage = true;
        updateItemInfoContainerPos(mousePos);
    }else{
        mouseHoverImage = false;
    }
}

void gui::ShopSlot::render(sf::RenderTarget &target) {
    target.draw(shape);
    target.draw(priceLbl);
    buyBtn.render(target);
    if(mouseHoverImage){
        target.draw(itemInfoContainer);
        target.draw(itemInfoLbl);
    }
}

std::string gui::ShopSlot::getKey() const {
    return key;
}

/*
 *                      SPELLSLOT
 *
 */
gui::SpellSlot::SpellSlot()= default;

gui::SpellSlot::SpellSlot(float width, float height, float pos_x, float pos_y,  const std::shared_ptr<Spell>& spell,
        const sf::Texture* texture, float rect_size, sf::Font* font, unsigned int char_size) : spell(spell) {

    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(pos_x, pos_y);
    shape.setOutlineThickness(4.f);
    switch(spell->getTypeEnum()){
        case FIRE:
            shape.setOutlineColor(sf::Color(235, 70, 59));
            shape.setFillColor(sf::Color(235, 70, 59, 50));
            break;
        case WATER:
            shape.setOutlineColor(sf::Color(50, 83, 173));
            shape.setFillColor(sf::Color(50, 83, 173, 50));
            break;
        case ICE:
            shape.setOutlineColor(sf::Color(92, 193, 247));
            shape.setFillColor(sf::Color(92, 193, 247, 50));
            break;
        case ELECTRIC:
            shape.setOutlineColor(sf::Color(126, 0, 222));
            shape.setFillColor(sf::Color(126, 0, 222, 50));
            break;
        case HOLY:
            shape.setOutlineColor(sf::Color(255, 254, 173));
            shape.setFillColor(sf::Color(255, 254, 173, 50));
            break;
        default:
            shape.setOutlineColor(sf::Color::White);
            break;
    }


    float app = width / 4.0f;
    spellImage.setSize(sf::Vector2f(app, app));
    app = app /5.0f;
    spellImage.setPosition(shape.getPosition().x,
            shape.getPosition().y);
    spellImage.setTexture(texture);
    spellImage.setTextureRect(sf::IntRect(
            spell->getIntRectX() * (int)rect_size,
            spell->getIntRectY() * (int)rect_size,
            rect_size, rect_size));
    spellImage.setOutlineColor(sf::Color::White);

    //init texts
    spellInfoLbl.setFont(*font);
    spellInfoLbl.setCharacterSize(char_size - 1);
  /*  this->spellInfoLbl << sf::Text::Bold << spell->getName() << "(" << spell->getType() << ")\n"
                        << "Damage: " << sf::Color(34, 0, 79) << to_string(spell->getDamage()) << "\n" << sf::Color::White
                        << "Cost: " << sf::Color::Blue << to_string(spell->getCost()) << sf::Color::White
                        << "\nCooldown: " << to_string(spell->getCooldown()) << " turn/s"
                        << "\nAoe: " << to_string(spell->getAoe()) << " target/s";*/

    spellInfoLbl.setPosition(spellImage.getPosition().x + spellImage.getGlobalBounds().width ,
            spellImage.getPosition().y);

    descriptionLbl.setFont(*font);
    descriptionLbl.setCharacterSize(char_size - 2);
    descriptionLbl.setStyle(sf::Text::Italic);
    descriptionLbl.setString(utils::textWrap(descriptionLbl, spell->getDescription(), width - 30.f));
    descriptionLbl.setPosition(spellImage.getPosition().x + 10.f,
            spellImage.getPosition().y + spellImage.getGlobalBounds().height + app);
}

gui::SpellSlot::~SpellSlot() = default;

void gui::SpellSlot::update(const sf::Vector2f &mousePos) {

}

void gui::SpellSlot::render(sf::RenderTarget &target) {
    target.draw(shape);
    target.draw(spellImage);
    target.draw(spellInfoLbl);
    target.draw(descriptionLbl);
}

sfe::RichText* gui::SpellSlot::getSpellInfoLbl() {
    return &spellInfoLbl;
}

std::shared_ptr<Spell> gui::SpellSlot::getSpell() {
    return spell;
}

/*
 *                      WIZARDSPELLSLOT
 *
 */

//constructors/desctructor
gui::WizardSpellSlot::WizardSpellSlot()= default;

gui::WizardSpellSlot::WizardSpellSlot(float width, float height, float pos_x, float pos_y, const std::shared_ptr<Spell>& spell,
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
            spell->getIntRectX() * (int)rect_size,
            spell->getIntRectY() * (int)rect_size,
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

gui::WizardSpellSlot::~WizardSpellSlot() = default;

std::shared_ptr<Spell> gui::WizardSpellSlot::getSpell() {
    return spell;
}

//accessors
sfe::RichText *gui::WizardSpellSlot::getSpellDescriptionLbl() {
    return &slotDescriptionLbl;
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

gui::PlayerStatusPanel::PlayerStatusPanel() = default;

gui::PlayerStatusPanel::PlayerStatusPanel(std::shared_ptr<Player> player, float x, float y, sf::Font* font) {
    this->player = std::move(player);
    this->font = font;

    x-=80.f;
    y-=50.f;
    shape.setSize(sf::Vector2f(160.f, 95.f));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color(15, 15, 15));
    shape.setOutlineColor(sf::Color(15, 15, 15, 150));
    shape.setOutlineThickness(5.f);

    infoText.setPosition(x + 15.f, y + 2.f);
    infoText.setFont(*this->font);
    infoText.setCharacterSize(20);
    stringstream ss;
    ss << "Player Lv." << this->player->getPlayerStats()->getLevel();
    infoText.setString(ss.str());

    hpBar = gui::ProgressBar(x + 5.f, y + infoText.getGlobalBounds().height + 14.f, 150.f, 25.f,
            0, this->player->getPlayerStats()->getMaxHp(),
            this->player->getPlayerStats()->getHp(), font);
    hpBar.setProgressShapeColor(sf::Color(190, 30, 30));
    hpBar.setProgressBorderColor(sf::Color(110, 15, 15));

    mpBar = gui::ProgressBar(x + 5.f, hpBar.getPosition().y + 30.f, 150.f, 25.f,
            0, this->player->getPlayerStats()->getMaxMp(),
            this->player->getPlayerStats()->getMp(), font);
    mpBar.setProgressShapeColor(sf::Color(40, 70, 220));
    mpBar.setProgressBorderColor(sf::Color(20, 35, 130));
}

gui::PlayerStatusPanel::~PlayerStatusPanel() = default;

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

void gui::PlayerStatusPanel::setShapeOutlineThickness(float thickness) {
    shape.setOutlineThickness(thickness);
}

/*
 *                      EnemyStatusPanel
 *
 */


gui::EnemyStatusPanel::EnemyStatusPanel() = default;

gui::EnemyStatusPanel::EnemyStatusPanel(const std::shared_ptr<Enemy>& enemy, float x, float y,
        sf::Font *font, sf::Texture& selected_icon_texture, State* state, unsigned int id)
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
    shape.setFillColor(sf::Color(15, 15, 15));

    selectedIcon.setTexture(&selected_icon_texture);
    selectedIcon.setSize(sf::Vector2f(150.f, 40.f));
    selectedIcon.setPosition(x + 15.f, y - 50.f);

    infoText.setPosition(x + 5.f, y + 2.f);
    infoText.setFont(*this->font);
    infoText.setCharacterSize(20);
    stringstream ss;
    ss << enemy->getName() << " Lv." << enemy->getStats()->getLevel();
    infoText.setString(ss.str());

    hpBar = gui::ProgressBar(x + 5.f, y + infoText.getGlobalBounds().height + 14.f, 170.f, 25.f,
                             0, enemy->getStats()->getFinalHp(), enemy->getStats()->getHp(), font);
    hpBar.setProgressShapeColor(sf::Color(190, 30, 30));
    hpBar.setProgressBorderColor(sf::Color(110, 15, 15));

    mpBar = gui::ProgressBar(x + 5.f, hpBar.getPosition().y + 30.f, 170.f, 25.f,
                             0, enemy->getStats()->getFinalMp(), enemy->getStats()->getMp(), font);
    mpBar.setProgressShapeColor(sf::Color(40, 70, 220));
    mpBar.setProgressBorderColor(sf::Color(20, 35, 130));
}

gui::EnemyStatusPanel::~EnemyStatusPanel() = default;

void gui::EnemyStatusPanel::update(const sf::Vector2f &mousePos, const float &dt,
        unsigned int& selected_id, const unsigned int current_enemy_pos, const bool player_turn) {
    hpBar.update(enemy->getStats()->getHp(), enemy->getStats()->getFinalHp());
    mpBar.update(enemy->getStats()->getMp(), enemy->getStats()->getFinalMp());
    isSelected = selected_id == idPos;

    if(shape.getGlobalBounds().contains(mousePos)){
        shape.setOutlineColor(sf::Color(15, 15, 15, 150));
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
        if(current_enemy_pos == idPos && !player_turn){
            shape.setOutlineColor(sf::Color(15, 15, 15, 150));
            shape.setOutlineThickness(5.f);
        }else if(isSelected){
            shape.setOutlineColor(sf::Color(15, 15, 15, 150));
            shape.setOutlineThickness(5.f);
        }
        else
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

/*
 *                      ActionRow
 *
 */

gui::ActionRow::ActionRow(float width, float height, float x, float y, const std::shared_ptr<Spell>& spell, float spellDmgMultiplier,
                          sf::Font* font, sf::Texture& action_texture) :
                          font(font), spell(spell), spellDmgMultiplier(spellDmgMultiplier) {
    mouseHoverImage = false;
    isCd = false;
    cdRemain = 0;
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(x, y);
    shape.setOutlineThickness(3.f);
    switch(spell->getTypeEnum()){
        case FIRE:
            shape.setOutlineColor(sf::Color(15, 15, 15, 255));
            shape.setFillColor(sf::Color(235, 70, 59, 50));
            imageShape.setOutlineColor(sf::Color(235, 70, 59));
            break;
        case WATER:
            shape.setOutlineColor(sf::Color(15, 15, 15, 255));
            shape.setFillColor(sf::Color(50, 83, 173, 50));
            imageShape.setOutlineColor(sf::Color(50, 83, 173));
            break;
        case ICE:
            shape.setOutlineColor(sf::Color(15, 15, 15, 255));
            shape.setFillColor(sf::Color(92, 193, 247, 50));
            imageShape.setOutlineColor(sf::Color(92, 193, 247));
            break;
        case ELECTRIC:
            shape.setOutlineColor(sf::Color(15, 15, 15, 255));
            shape.setFillColor(sf::Color(126, 0, 222, 50));
            imageShape.setOutlineColor(sf::Color(126, 0, 222));
            break;
        case HOLY:
            shape.setOutlineColor(sf::Color(15, 15, 15, 255));
            shape.setFillColor(sf::Color(255, 254, 173, 50));
            imageShape.setOutlineColor(sf::Color(255, 254, 173));
            break;
        case DEFAULT_SPELL_TYPE:
            shape.setOutlineColor(sf::Color(15, 15, 15, 255));
            shape.setFillColor(sf::Color(150, 150, 150, 50));
            imageShape.setOutlineColor(sf::Color(200, 200, 200));
            break;
    }

    imageShape.setSize(sf::Vector2f(height - 10.f, height - 10.f));
    imageShape.setPosition(shape.getPosition().x + 5.f,
                           shape.getPosition().y + 5.f);
    imageShape.setTexture(&action_texture);
    imageShape.setTextureRect(sf::IntRect(
            spell->getIntRectX() * 34,
            spell->getIntRectY() * 34,
            34.f, 34.f));
    imageShape.setOutlineThickness(3.f);

    titleLbl.setFont(*font);
    titleLbl.setCharacterSize(15);
    titleLbl.setPosition(imageShape.getPosition().x + imageShape.getGlobalBounds().width + 10.f,
                         imageShape.getPosition().y);
    if(spell->getTypeEnum() == DEFAULT_SPELL_TYPE)
        titleLbl.setString(spell->getName());
    else{
        stringstream ss;
        ss << spell->getName() << " Lv." << spell->getLevel();
        titleLbl.setString(ss.str());
    }

    costLbl.setFont(*font);
    costLbl.setCharacterSize(15);
    costLbl.setPosition(titleLbl.getPosition().x,
                        titleLbl.getPosition().y + titleLbl.getGlobalBounds().height + 5.f);
    if(spell->getFinalCost() == 0){
        costLbl << "Cost: N/A";
    }else{
        costLbl << "Cost: " << sf::Color::Blue << to_string(spell->getFinalCost()) << " Mana";
    }

    cdLbl.setFont(*font);
    cdLbl.setCharacterSize(15);
    cdLbl.setPosition(costLbl.getPosition().x + 120.f,
                      costLbl.getPosition().y);


    useBtn = gui::Button(
            shape.getPosition().x + shape.getGlobalBounds().width - height * 2.f - 20.f,
            shape.getPosition().y + 5.f,
            height * 2.f, height - 10.f,
            font, "Use", 18.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 70),
            sf::Color(130, 130, 130));
    useBtn.setBorderColor(sf::Color(15, 15, 15, 255));
    useBtn.setBackgroundFilLColor(sf::Color(120,120,120, 120));
    useBtn.setBorderLineThickness(2.f);

    actionInfoLbl.setFont(*this->font);
    actionInfoLbl.setCharacterSize(20);
    actionInfoLbl << sf::Text::Bold << spell->getName() << sf::Text::Regular;
    if(spell->getTypeEnum() != DEFAULT_SPELL_TYPE){
        stringstream ss;
        ss << spell->getFinalDamage() << " x" << spellDmgMultiplier << " = " << getActionFinalDamage();
        actionInfoLbl << "(Lv" << to_string(spell->getLevel()) << ")";
        if(spell->getName() == "Cleanse"){
            actionInfoLbl << "\n Effect: Remove all debuffs";
        }else if(spell->getName() == "Heal"){
            ss.str("");
            ss << spellDmgMultiplier;
            actionInfoLbl << "\n Effect: " << sf::Color::Red << to_string(spell->getDamage())
            << " x " << ss.str() << " = " << to_string(getActionFinalDamage());
        }else if(spell->getName() == "Meditation"){
            ss.str("");
            ss << spellDmgMultiplier;
            actionInfoLbl << "\n Effect: " << sf::Color::Blue << to_string(spell->getDamage())
            << " x " << ss.str() << " = " << to_string(getActionFinalDamage());
        }else{
            actionInfoLbl << "\n Damage: " << sf::Color(255, 60, 31) << ss.str();
        }
    }
    actionInfoLbl << sf::Color::White;
    if(spell->getFinalCost() == 0){
        actionInfoLbl << "\n Cost: N/A";
    }else{
        actionInfoLbl << "\n Cost: " << sf::Color::Blue << to_string(spell->getFinalCost()) ;
    }
    actionInfoLbl << sf::Color::White;
    if(spell->getCooldown() == 0){
        actionInfoLbl << "\n Cooldown: N/A";
    }else{
        actionInfoLbl << "\n Cooldown: " << to_string(spell->getCooldown()) << " turn/s";
    }
    actionInfoLbl << "\n " << sf::Text::Italic << spell->getDescription();

    actionInfoContainer.setFillColor(sf::Color(90,90,90));
    actionInfoContainer.setOutlineColor(sf::Color(60,60,60));
    actionInfoContainer.setOutlineThickness(3.f);
    actionInfoContainer.setSize(sf::Vector2f(actionInfoLbl.getGlobalBounds().width + 10.f,
                                             actionInfoLbl.getGlobalBounds().height + 15.f));
}

gui::ActionRow::~ActionRow() = default;

bool gui::ActionRow::isUseBtnPressed() const {
    return useBtn.isPressed();
}

void gui::ActionRow::updateInfoContainer(const sf::Vector2f& mousePos) {
    actionInfoContainer.setPosition(mousePos.x,
                                   mousePos.y - actionInfoContainer.getGlobalBounds().height);
    actionInfoLbl.setPosition(actionInfoContainer.getPosition().x + 5.f,
                             actionInfoContainer.getPosition().y);
}

void gui::ActionRow::update(const sf::Vector2f &mousePos, const float &dt) {
    useBtn.update(mousePos);
    if(imageShape.getGlobalBounds().contains(mousePos)){
        mouseHoverImage = true;
        updateInfoContainer(mousePos);
    }else{
        mouseHoverImage = false;
    }
}

void gui::ActionRow::render(sf::RenderTarget &target) {
    target.draw(shape);
    target.draw(imageShape);
    target.draw(titleLbl);
    target.draw(costLbl);
    if(isCd)
        target.draw(cdLbl);
    useBtn.render(target);
    if(mouseHoverImage){
        target.draw(actionInfoContainer);
        target.draw(actionInfoLbl);
    }

}

std::shared_ptr<Spell> gui::ActionRow::getAction() const{
    return spell;
}

int gui::ActionRow::getActionFinalDamage() const {
    return (int)((float)spell->getFinalDamage() * spellDmgMultiplier);
}

void gui::ActionRow::startCd() {
    if(spell->getCooldown() > 0){
        isCd = true;
        cdRemain = spell->getCooldown();
        useBtn.setText("Not Ready");
        useBtn.setDisabled(true);
        stringstream ss;
        ss << cdRemain << " turn/s remaining";
        cdLbl.setString(ss.str());
    }
}

void gui::ActionRow::updateCd() {
    if(isCd && cdRemain > 0){
        cdRemain -= 1;
        stringstream ss;
        ss << cdRemain << " turn/s remaining";
        cdLbl.setString(ss.str());
        if(cdRemain == 0)
            endCd();
    }
}

void gui::ActionRow::endCd() {
    isCd = false;
    useBtn.setText("USE");
    useBtn.setDisabled(false);
}

void gui::ActionRow::setUseBtnState(button_states btn_state) {
    useBtn.setButtonState(btn_state);
}

/*
 *                      ItemRow
 *
 */

gui::ItemRow::ItemRow(float width, float height, float x, float y, const std::shared_ptr<Item> &item, sf::Font *font,
                      sf::Texture &item_texture) : font(font), item(item) {
    mouseHoverImage = false;
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(x, y);
    shape.setOutlineColor(sf::Color(15, 15, 15, 255));
    shape.setFillColor(sf::Color(50, 50, 50, 100));
    shape.setOutlineThickness(3.f);

    imageShape.setSize(sf::Vector2f(height - 10.f, height - 10.f));
    imageShape.setPosition(shape.getPosition().x + 5.f,
                           shape.getPosition().y + 5.f);
    imageShape.setTexture(&item_texture);
    imageShape.setTextureRect(sf::IntRect(
            item->getIconRectX() * 34,
            item->getIconRectY() * 34,
            34.f, 34.f));
    imageShape.setOutlineThickness(3.f);
    switch(item->getRarityEnum()){
        case UNCOMMON:
            imageShape.setOutlineColor(sf::Color::White);
            break;
        case COMMON:
            imageShape.setOutlineColor(sf::Color::Green);
            break;
        case RARE:
            imageShape.setOutlineColor(sf::Color::Blue);
            break;
        case EPIC:
            imageShape.setOutlineColor(sf::Color::Magenta);
            break;
        case LEGENDARY:
            imageShape.setOutlineColor(sf::Color(255,127,80));
            break;
        case DEFAULT_RARITY:
            break;
    }

    titleLbl.setFont(*font);
    titleLbl.setCharacterSize(15);
    titleLbl.setPosition(imageShape.getPosition().x + imageShape.getGlobalBounds().width + 10.f,
                         imageShape.getPosition().y);
    titleLbl.setString(item->getName());

    quantityLbl.setFont(*font);
    quantityLbl.setCharacterSize(15);
    quantityLbl.setPosition(titleLbl.getPosition().x,
                        titleLbl.getPosition().y + titleLbl.getGlobalBounds().height + 5.f);
    updateQuantityLbl();

    useBtn = gui::Button(
            shape.getPosition().x + shape.getGlobalBounds().width - height * 2.f - 20.f,
            shape.getPosition().y + 5.f,
            height * 2.f, height - 10.f,
            font, "Use", 18.f,
            sf::Color(255, 255, 255, 255),
            sf::Color(160, 160, 160),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 70),
            sf::Color(130, 130, 130));
    useBtn.setBorderColor(sf::Color(15, 15, 15, 255));
    useBtn.setBackgroundFilLColor(sf::Color(120,120,120, 120));
    useBtn.setBorderLineThickness(2.f);

    infoLbl.setFont(*this->font);
    infoLbl.setCharacterSize(15);
    infoLbl << sf::Text::Bold << item->getName() << "\n" << sf::Text::Regular
            << "Type: " << item->getItemType() << "\n" << imageShape.getOutlineColor()
            << item->getRarity() << sf::Color::White << "\n'" << item->getDescription() << "'\n";

    infoContainer.setFillColor(sf::Color(90,90,90));
    infoContainer.setOutlineColor(sf::Color(60,60,60));
    infoContainer.setOutlineThickness(3.f);
    infoContainer.setSize(sf::Vector2f(infoLbl.getGlobalBounds().width + 10.f,
                                       infoLbl.getGlobalBounds().height + 10.f));
}

gui::ItemRow::~ItemRow() = default;

bool gui::ItemRow::isUseBtnPressed() const {
    return useBtn.isPressed();
}

void gui::ItemRow::updateQuantityLbl() {
    stringstream ss;
    ss << "Quantity: " << item->getQuantity();
    quantityLbl.setString(ss.str());
}

void gui::ItemRow::updateInfoContainer(const sf::Vector2f &mousePos) {
    infoContainer.setPosition(mousePos.x,
                                    mousePos.y - infoContainer.getGlobalBounds().height);
    infoLbl.setPosition(infoContainer.getPosition().x + 5.f,
                              infoContainer.getPosition().y);
}

void gui::ItemRow::update(const sf::Vector2f &mousePos) {
    useBtn.update(mousePos);
    if(imageShape.getGlobalBounds().contains(mousePos)){
        mouseHoverImage = true;
        updateInfoContainer(mousePos);
    }else{
        mouseHoverImage = false;
    }
}

void gui::ItemRow::render(sf::RenderTarget &target) {
    target.draw(shape);
    target.draw(imageShape);
    target.draw(titleLbl);
    target.draw(quantityLbl);
    useBtn.render(target);
    if(mouseHoverImage){
        target.draw(infoContainer);
        target.draw(infoLbl);
    }
}

void gui::ItemRow::setUseBtnState(button_states btn_state) {
    useBtn.setButtonState(btn_state);
}

std::shared_ptr<Item> gui::ItemRow::getItem() const {
    return item;
}

/*
 *                      BuffSlot
 *
 */

//constructors/desctructor
gui::BuffSlot::BuffSlot() = default;

gui::BuffSlot::BuffSlot(float x, float y, float width, float height, const std::shared_ptr<Buff>& buff,
                        const sf::Texture &buff_texture, sf::Font *font) : buff(buff), mouseHoverImage(false){
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(x, y);
    shape.setTexture(&buff_texture);
    shape.setTextureRect(sf::IntRect(
            buff->getIntRectX() * 34,
            buff->getIntRectY() * 34,
            34.f, 34.f));
    shape.setOutlineThickness(1.f);
    if(this->buff->isDebuff()){
        shape.setOutlineColor(sf::Color::Red);
    }else{
        shape.setOutlineColor(sf::Color::Green);
    }
    stringstream ss;
    infoLbl.setFont(*font);
    infoLbl.setCharacterSize(20);
    ss << buff->getName() << std::endl << buff->getDescription();
    infoLbl.setString(ss.str());

    ss.str("");
    ss << "Time remaining: " << buff->getTurns() << " turn/s";
    lifeTimeLbl.setFont(*font);
    lifeTimeLbl.setCharacterSize(17);
    lifeTimeLbl.setPosition(infoLbl.getPosition().x, infoLbl.getPosition().y + infoLbl.getGlobalBounds().height);
    lifeTimeLbl.setString(ss.str());

    infoContainer.setFillColor(sf::Color(90,90,90));
    infoContainer.setOutlineColor(sf::Color(60,60,60));
    infoContainer.setOutlineThickness(3.f);
    infoContainer.setSize(sf::Vector2f(infoLbl.getGlobalBounds().width + 10.f,
                                       infoLbl.getGlobalBounds().height + lifeTimeLbl.getGlobalBounds().height + 10.f));
}

gui::BuffSlot::~BuffSlot() = default;

//functions
void gui::BuffSlot::updateInfoContainer(const sf::Vector2f &mousePos) {
    stringstream ss;
    ss << "Time remaining: " << buff->getTurns() << " turn/s";
    lifeTimeLbl.setString(ss.str());
    infoContainer.setPosition(mousePos.x + 10.f, mousePos.y);
    infoLbl.setPosition(infoContainer.getPosition().x + 5.f, infoContainer.getPosition().y);
    lifeTimeLbl.setPosition(infoLbl.getPosition().x, infoLbl.getPosition().y + infoLbl.getGlobalBounds().height + 4.f);
}

void gui::BuffSlot::update(const sf::Vector2f &mousePos) {
    if(shape.getGlobalBounds().contains(mousePos)){
        mouseHoverImage = true;
        updateInfoContainer(mousePos);
    }else{
        mouseHoverImage = false;
    }
}

void gui::BuffSlot::render(sf::RenderTarget &target) {
    target.draw(shape);
    if(mouseHoverImage){
        target.draw(infoContainer);
        target.draw(infoLbl);
        target.draw(lifeTimeLbl);
    }
}

std::shared_ptr<Buff> gui::BuffSlot::getBuff() const {
    return buff;
}

void gui::BuffSlot::setBuff(std::shared_ptr<Buff> new_buff, bool updateLbl) {
    buff = std::move(new_buff);
    if(updateLbl)
        updateDescriptionLbl();
}

void gui::BuffSlot::updateDescriptionLbl() {
    stringstream ss;
    ss << buff->getName() << std::endl << buff->getDescription();
    infoLbl.setString(ss.str());
    infoContainer.setSize(sf::Vector2f(infoLbl.getGlobalBounds().width + 10.f,
            infoLbl.getGlobalBounds().height + lifeTimeLbl.getGlobalBounds().height + 10.f));
}


