//
// Created by Zheng on 06/10/2020.
//

#ifndef DRAGONSLAYER_GUI_H
#define DRAGONSLAYER_GUI_H

#include <SFML/Graphics.hpp>
#include "../Game/Item.h"
#include "../Core/State.h"

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
        bool disabled;

        sf::RectangleShape shape;
        sf::Font* font;
        sf::Text text;

        sf::Color textIdleColor;
        sf::Color textHoverColor;
        sf::Color textActiveColor;

        sf::Color idleColor;
        sf::Color hoverColor;
        sf::Color activeColor;

    protected:

    public:
        Button(float x, float y, float width, float height, sf::Font* font,
               std::string text, unsigned character_size,
               sf::Color text_idle_color, sf::Color text_hover_color,sf::Color text_active_color,
               sf::Color idle_color,sf::Color hover_color, sf::Color active_color, short unsigned id = 0);
        virtual ~Button();

        //accessors
        const bool isPressed() const;
        const std::string getText() const;
        const short unsigned& getId() const;
        sf::Vector2f getPosition();

        //modifiers
        void setButtonState(button_states);
        void setPosition(float x, float y);
        void setPosition(sf::Vector2f pos);
        void setSize(sf::Vector2f size);
        void setText(const std::string text);
        void setId(const short unsigned id);
        void setBorderColor(sf::Color color);
        void setBorderLineThickness(float value);
        void setTextPosition(sf::Vector2f position);
        void setTextPositionAddY(float y);

        //functions
        void setDisabled(bool b);
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
        bool renderRightClickMenu;
        bool isSelected;
        bool isEquipSlot;
        int id;

        Item* item;
        State* state;
        sf::Window* window;
        sf::RectangleShape shape;
        sf::RectangleShape cover;
        sf::RectangleShape downRight;
        sf::RectangleShape upRight;
        sf::IntRect intRect;
        sf::Font* font;
        sf::Texture texture;

        sf::RectangleShape itemInfoContainer;
        sf::Text itemInfoLbl;
        sf::Text quantityLbl;
    protected:


    public:
        //constructors/destructors
        ItemSlot(float x, float y, float width, float height, int id, sf::Window* window,
                sf::Font* font, Item* item, State* state, bool isEquipSlot);
        virtual ~ItemSlot();


        //accessors
        int getId();
        bool hasItem();
        bool getIsSelected();
        Item* getItem();
        sf::RectangleShape* getShape();
        sf::IntRect* getIntRect();

        //modifiers
        void setItem(Item* item);
        void setShapeTexture(const sf::Texture *texture, const sf::IntRect* intRect);
        void setSlotTexture(const sf::Texture *texture, float size);
        void setSlotTexture(sf::Texture* texture, sf::IntRect intRect);
        void setSelectedBool(bool b);
        void setDownRightTexture(sf::Texture* texture);
        void setUpRightTexture(sf::Texture* texture);

        //functions
        void itemInfo(const sf::Vector2f& mousePos);
        void updateQuantityLbl();
        void updateItemInfo();
        void updateItemInfoPos(const sf::Vector2f& mousePos);
        void update(const sf::Vector2f& mousePos, int* updateSlot, bool inv);
        void render(sf::RenderTarget& target);
    };

    class EquipSlots{
    private:
        ItemSlot head;
        ItemSlot chest;
        ItemSlot arms;
        ItemSlot legs;
        ItemSlot weapon;
        ItemSlot shield;
    protected:

    public:

        EquipSlots();
        virtual  ~EquipSlots();

        void update(const sf::Vector2f& mousePos, int* updateSlot, bool inv);
        void render(sf::RenderTarget& target);
    };

    class ConfirmDialog{
    private:
    protected:
        sf::Window* window;
        State* state;
        sf::RectangleShape dialog;
        Button* yesBtn;
        Button* noBtn;
        sf::Text text;

    public:
        ConfirmDialog(float x, float y, std::string text, sf::Window* window, State* state, sf::Font* font, float characterSize);
        virtual ~ConfirmDialog();

        int update(const sf::Vector2f& mousePos, bool* openDialog);
        void render(sf::RenderTarget& target);
    };
}


#endif //DRAGONSLAYER_GUI_H
