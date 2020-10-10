//
// Created by Zheng on 06/10/2020.
// componenti grafici customizzati

#include "Gui.h"
#include <iostream>
#include <sstream>

gui::Button::Button(float x, float y, float width, float height,
                    sf::Font *font, std::string text, unsigned character_size,
                    sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
                    sf::Color idle_color, sf::Color hover_color, sf::Color active_color,
                    sf::Color outline_idle_color,sf::Color outline_hover_color,sf::Color outline_active_color,
                    short unsigned id) {
    this->buttonState = BTN_IDLE;
    this->id = id;

    this->shape.setPosition(sf::Vector2f(x,y));
    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setFillColor(idle_color);
    this->shape.setOutlineThickness(1.f);
    this->shape.setOutlineColor(outline_idle_color);

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

    //colore bordo bottone
    this->outlineIdleColor = outline_idle_color;
    this->outlineHoverColor = outline_hover_color;
    this->outlineActiveColor = outline_active_color;
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

    //cambia colore in base allo stato del bottone
    switch(this->buttonState){
        case BTN_IDLE:
            this->shape.setFillColor(this->idleColor);
            this->text.setFillColor(this->textIdleColor);
            this->shape.setOutlineColor(this->outlineIdleColor);
            break;
        case BTN_HOVER:
            this->shape.setFillColor(this->hoverColor);
            this->text.setFillColor(this->textHoverColor);
            this->shape.setOutlineColor(this->outlineHoverColor);
            break;
        case BTN_ACTIVE:
            this->shape.setFillColor(this->activeColor);
            this->text.setFillColor(this->textActiveColor);
            this->shape.setOutlineColor(this->outlineActiveColor);
            break;
        default: //caso errato
            this->shape.setFillColor(sf::Color::Red);
            this->shape.setFillColor(sf::Color::Blue);
            this->shape.setOutlineColor(sf::Color::Green);
            break;
    }
}

void gui::Button::render(sf::RenderTarget& target) {
    target.draw(this->shape);
    target.draw(this->text);
}

/*
 *
 *          PROGRESSBAR
 *
 */

gui::ProgressBar::ProgressBar(sf::Window *window, float x, float y, float width, float height, int min, int max, int currentValue, sf::Font *font)
: window(window), font(font), min(min), max(max), currentValue(currentValue){
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
    this->progressShape.setSize(sf::Vector2f(this->barShape.getGlobalBounds().width * this->progressPercentage - 4.f,
                                             this->progressShape.getGlobalBounds().height));
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

gui::ItemSlot::ItemSlot(float x, float y, float width, float height,sf::Window* window, sf::Font *font)
    : window(window), font(font){
    this->renderItemInfoContainer = false;

    this->shape.setPosition(sf::Vector2f(x,y));
    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setOutlineThickness(1.f);
    this->shape.setOutlineColor(sf::Color::Blue);

    this->itemInfoContainer.setSize(sf::Vector2f(width*2, height*2));
    this->itemInfoContainer.setFillColor(sf::Color::Magenta);

    this->itemName.setFont(*this->font);
    this->itemName.setString("item");
    this->itemName.setCharacterSize(20.f);
    this->itemName.setOrigin(this->itemName.getGlobalBounds().width/2.f, this->itemName.getGlobalBounds().height/2.f);
    this->itemName.setPosition(
            this->shape.getPosition().x + (width/2.f),
            this->shape.getPosition().y + height + 5.f
    );
}

gui::ItemSlot::~ItemSlot() {

}

void gui::ItemSlot::itemInfo(const sf::Vector2f &mousePos) {

}

void gui::ItemSlot::updateItemInfoPos(const sf::Vector2f &mousePos) {
    this->itemInfoContainer.setPosition(mousePos);
}

void gui::ItemSlot::update(const sf::Vector2f &mousePos) {


    //hover
    if(this->shape.getGlobalBounds().contains(mousePos)){
        this->slotState = SLOT_HOVER;
        this->renderItemInfoContainer = true;
        this->updateItemInfoPos(mousePos);
        this->window->setMouseCursorVisible(false);
        //pressed
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            this->slotState = SLOT_ACTIVE;
            this->renderItemInfoContainer = false;
        }
    } else{
        //idle
        this->slotState = SLOT_IDLE;
        this->renderItemInfoContainer = false;
        this->window->setMouseCursorVisible(true);
    }

    //cambia colore in base allo stato del bottone
    switch(this->slotState){
        case SLOT_IDLE:
            this->shape.setFillColor(sf::Color::Green);
            this->shape.setOutlineColor(sf::Color::Blue);
            break;
        case SLOT_HOVER:
            this->shape.setFillColor(sf::Color::Blue);
            this->shape.setOutlineColor(sf::Color::Green);
            break;
        case SLOT_ACTIVE:
            this->shape.setFillColor(sf::Color::Transparent);
            this->shape.setOutlineColor(sf::Color::Yellow);
            break;
        default: //caso errato
            this->shape.setFillColor(sf::Color::Red);
            this->shape.setFillColor(sf::Color::Blue);
            this->shape.setOutlineColor(sf::Color::Green);
            break;
    }
}

void gui::ItemSlot::render(sf::RenderTarget &target) {
    target.draw(this->shape);
    if(this->renderItemInfoContainer){
        target.draw(this->itemInfoContainer);
    }
   // target.draw(this->itemName);
}



