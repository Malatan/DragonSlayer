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

enum item_slot_states{
    SLOT_IDLE = 0,
    SLOT_ACTIVE,
    SLOT_HOVER,
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

    class ProgressBar{
    private:
        sf::Window* window;
        sf::Font* font;
        sf::Text text;
        sf::RectangleShape barShape;
        sf::RectangleShape progressShape;

        int min;
        int max;
        int currentValue;
        float progressPercentage;
        bool textPrint;

    protected:

    public:
        //constuctors/destructors
        ProgressBar(sf::Window* window, float x, float y, float width, float height, int min, int max, int currentValue, sf::Font* font);
        virtual ~ProgressBar();

        //accessors
        sf::Vector2f getPosition();

        //modifiers
        void setMax(int max);
        void setMin(int min);
        void setCurrentValue(int currentValue);
        void setText(std::string text);
        void setBarShapeColor(sf::Color color);
        void setProgressShapeColor(sf::Color color);

        //functions
        void update(float current, int max);
        void render(sf::RenderTarget& target);
    };

    class ItemSlot{
    private:
        short unsigned slotState;
        bool renderItemInfoContainer;

        sf::Window* window;
        sf::RectangleShape shape;
        sf::Font* font;
        sf::Text itemName;

        sf::RectangleShape itemInfoContainer;


    protected:


    public:
        //constructors/destructors
        ItemSlot(float x, float y, float width, float height, sf::Window* window, sf::Font* font);
        virtual ~ItemSlot();


        //accessors

        //modifiers

        //functions
        void itemInfo(const sf::Vector2f& mousePos);
        void updateItemInfoPos(const sf::Vector2f& mousePos);
        void update(const sf::Vector2f& mousePos);
        void render(sf::RenderTarget& target);
    };

}


#endif //DRAGONSLAYER_GUI_H
