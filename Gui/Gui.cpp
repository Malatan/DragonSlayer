//
// Created by Zheng on 06/10/2020.
// componenti grafici customizzati

#include "Gui.h"

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






