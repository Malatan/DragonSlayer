//
// Created by Zheng on 06/10/2020.
//

#ifndef DRAGONSLAYER_GUI_H
#define DRAGONSLAYER_GUI_H

#include <SFML/Graphics.hpp>


enum button_states{
    BTN_IDLE = 0,
    BTN_ACTIVE,
    BTN_HOVER,
};

namespace gui{
    class Button {
    private:
        short unsigned buttonState;
        short unsigned id;

        bool pressed;
        bool hover;

        sf::RectangleShape shape;
        sf::Font* font;
        sf::Text text;

        sf::Color textIdleColor;
        sf::Color textHoverColor;
        sf::Color textActiveColor;

        sf::Color idleColor;
        sf::Color hoverColor;
        sf::Color activeColor;

        sf::Color outlineIdleColor;
        sf::Color outlineHoverColor;
        sf::Color outlineActiveColor;

    protected:

    public:
        Button(float x, float y, float width, float height, sf::Font* font,
               std::string text, unsigned character_size,
               sf::Color text_idle_color, sf::Color text_hover_color,sf::Color text_active_color,
               sf::Color idle_color,sf::Color hover_color, sf::Color active_color,
               sf::Color outline_idle_color = sf::Color::Transparent,
               sf::Color outline_hover_color = sf::Color::Transparent,
               sf::Color outline_active_color = sf::Color::Transparent,
               short unsigned id = 0);
        virtual ~Button();

        //accessors
        const bool isPressed() const;
        const std::string getText() const;
        const short unsigned& getId() const;

        //modifiers
        void setText(const std::string text);
        void setId(const short unsigned id);
        void setBorderColor(sf::Color color);
        void setBorderLineThickness(float value);
        void setTextPosition(sf::Vector2f position);
        void setTextPositionAddY(float y);

        //functions
        void update(const sf::Vector2f& mousePos);
        void render(sf::RenderTarget& target);

    };


}


#endif //DRAGONSLAYER_GUI_H
