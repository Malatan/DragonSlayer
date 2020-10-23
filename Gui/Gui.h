//
// Created by Zheng on 06/10/2020.
//

#ifndef DRAGONSLAYER_GUI_H
#define DRAGONSLAYER_GUI_H

#include <SFML/Graphics.hpp>
#include "../Game/Item.h"
#include "../Core/State.h"
#include "libraries/RichText.hpp"

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

enum dialog_type{
    DELETE_CONFIRM,
    SELL_CONFIRM
};

namespace gui{
    class Button {
    private:
        short unsigned buttonState;
        short unsigned id;

        bool pressed;
        bool hover;
        bool disabled;
        bool tooltipDisabled;
        bool textDisabled;
        bool backgroundDisabled;

        sf::RectangleShape shape;
        sf::RectangleShape background;
        sf::RectangleShape tooltipContainer;
        sf::Text tooltipText;
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
        const bool isTooltipDisabled();

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
        void setTooltipText(std::string text);
        void setTooltipDisabled(bool b);
        void setDisabled(bool b);
        void setBackgroundTexture(const sf::Texture* texture);
        void setBackbgroundDisabled(bool b);

        //functions
        bool contains(const sf::Vector2f& mousePos);
        void updateTooltipPos(const sf::Vector2f& mousePos);
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

    class ShopSlot{
    private:
        sf::RectangleShape shape;
        sf::Text priceLbl;
        sf::Texture texture;
        gui::Button* buyBtn;
        Item* item;

        unsigned price;
        std::string key;
        bool equipment;


    protected:

    public:
        //constructors/destructor
        ShopSlot(float width, float height, float pos_x, float pos_y, std::string key, unsigned price, sf::Font* font, Item* item);
        virtual ~ShopSlot();

        //accessors
        Item *getItem() const;
        const unsigned getPrice() const;

        //modifiers

        void setSlotTexture(const sf::Texture *texture, float size);


        //functions
        bool isPressed();
        void update(const sf::Vector2f &mousePos);
        void render(sf::RenderTarget& target);

    };

    class SpellSlot{
    private:
        sf::RectangleShape shape;
        sf::RectangleShape spellImage;
        sfe::RichText spellInfoLbl;
        sfe::RichText descriptionLbl;

        Spell* spell;


    protected:

    public:
        //constructors/destructor
        SpellSlot(float width, float height, float pos_x, float pos_y, Spell* spell,
                const sf::Texture* texture, float rect_size, sf::Font* font, unsigned int char_size);
        virtual ~SpellSlot();

        //accessor
        sfe::RichText* getSpellInfoLbl();
        Spell* getSpell();

        //functions
        void update(const sf::Vector2f& mousePos);
        void render(sf::RenderTarget& target);

    };

    class ConfirmDialog{
    private:
    protected:
        dialog_type  dialogType;
        unsigned sellValue;

        sf::Window* window;
        State* state;

        sf::RectangleShape dialog;
        Button* yesBtn;
        Button* noBtn;
        sf::Text text;

    public:
        ConfirmDialog(float x, float y, std::string text, sf::Window* window, State* state, sf::Font* font, float characterSize,
                dialog_type dType);
        virtual ~ConfirmDialog();

        void setSellValue(unsigned value);

        dialog_type getDialogType();
        unsigned getSellValue();

        int update(const sf::Vector2f& mousePos, bool* openDialog);
        void render(sf::RenderTarget& target);
    };
}


#endif //DRAGONSLAYER_GUI_H
