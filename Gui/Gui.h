//
// Created by Zheng on 06/10/2020.
//

#ifndef DRAGONSLAYER_GUI_H
#define DRAGONSLAYER_GUI_H

#include "../Game/Item.h"
#include "../Core/State.h"
#include "../Game/Player.h"
#include "../Game/Enemy.h"
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
    public:
        Button();
        Button(float x, float y, float width, float height, sf::Font* font,
               const std::string& text, unsigned character_size,
               sf::Color text_idle_color, sf::Color text_hover_color,sf::Color text_active_color,
               sf::Color idle_color,sf::Color hover_color, sf::Color active_color, short unsigned id = 0);
        virtual ~Button();

        //accessors
        bool isPressed() const;
        const short unsigned& getId() const;
        sf::Vector2f getPosition();
        sf::FloatRect getGlobalBounds() const;

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
        void setDisabled(bool b, bool change_color = true);
        void setBackgroundTexture(const sf::Texture* texture);
        void setBackbgroundDisabled(bool b);
        void setBackgroundFilLColor(sf::Color color);

        //functions
        bool contains(const sf::Vector2f& mousePos);
        void updateTooltipPos(const sf::Vector2f& mousePos);
        void update(const sf::Vector2f& mousePos);
        void render(sf::RenderTarget& target);

    private:
        short unsigned buttonState;
        short unsigned id;

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
    };

    class ProgressBar{
    public:
        //constuctors/destructors
        ProgressBar();
        ProgressBar(float x, float y, float width, float height, int min, int max, int currentValue, sf::Font* font);
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

    private:
        sf::Font* font;
        sf::Text text;
        sf::RectangleShape barShape;
        sf::RectangleShape progressShape;

        int min;
        int max;
        int currentValue;
        float progressPercentage;
    };

    class ItemSlot{
    public:
        //constructors/destructors
        ItemSlot();
        ItemSlot(float x, float y, float width, float height, int id, std::shared_ptr<sf::RenderWindow> window,
                sf::Font* font, const std::shared_ptr<Item>& item, State* state, bool isEquipSlot);
        virtual ~ItemSlot();

        //accessors
        int getId();
        bool hasItem();
        bool getIsSelected();
        std::shared_ptr<Item> getItem();
        sf::RectangleShape* getShape();
        sf::IntRect* getIntRect();

        //modifiers
        void setItem(std::shared_ptr<Item> item);
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

    private:
        short unsigned slotState;
        bool renderItemInfoContainer;
        bool isSelected;
        bool isEquipSlot;
        int id;

        std::shared_ptr<Item> item;
        State* state;
        std::shared_ptr<sf::RenderWindow> window;
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
    };

    class ShopSlot{
    public:
        //constructors/destructor
        ShopSlot();
        ShopSlot(float width, float height, float pos_x, float pos_y, std::string key, unsigned price, sf::Font* font, Item* item);
        virtual ~ShopSlot();

        //accessors
        Item *getItem() const;
        unsigned int getPrice() const;

        //modifiers

        void setSlotTexture(const sf::Texture *texture, float size);


        //functions
        void updateItemInfoContainerPos(const sf::Vector2f& mousePos);
        bool isPressed();
        void update(const sf::Vector2f &mousePos);
        void render(sf::RenderTarget& target);

    private:
        sf::RectangleShape shape;
        sf::Text priceLbl;
        sf::Texture texture;
        gui::Button* buyBtn;
        Item* item;

        sf::RectangleShape itemInfoContainer;
        sfe::RichText itemInfoLbl;
        bool mouseHoverImage;

        unsigned int price;
        std::string key;
    };

    class SpellSlot{
    public:
        //constructors/destructor
        SpellSlot();
        SpellSlot(float width, float height, float pos_x, float pos_y, const std::shared_ptr<Spell>& spell,
                const sf::Texture* texture, float rect_size, sf::Font* font, unsigned int char_size);
        virtual ~SpellSlot();

        //accessor
        sfe::RichText* getSpellInfoLbl();
        std::shared_ptr<Spell> getSpell();

        //functions
        void update(const sf::Vector2f& mousePos);
        void render(sf::RenderTarget& target);

    private:
        sf::RectangleShape shape;
        sf::RectangleShape spellImage;
        sfe::RichText spellInfoLbl;
        sfe::RichText descriptionLbl;
        std::shared_ptr<Spell> spell;
    };

    class WizardSpellSlot{
    public:
        //constructors/destructor
        WizardSpellSlot();
        WizardSpellSlot(float width, float height, float pos_x, float pos_y, const std::shared_ptr<Spell>& spell,
                  const sf::Texture* texture, float rect_size, sf::Font* font, unsigned int char_size);
        virtual ~WizardSpellSlot();

        //accessor
        sfe::RichText* getSpellDescriptionLbl();
        sfe::RichText* getSpellInfoLbl();
        std::shared_ptr<Spell> getSpell();

        //functions
        bool isBtnPressed();
        void updateBtnText();
        void updateSpellInfo();
        void updateSpellInfoContainerPos(const sf::Vector2f& mousePos);
        void update(const sf::Vector2f& mousePos);
        void render(sf::RenderTarget& target);

    private:
        sf::RectangleShape shape;
        sf::RectangleShape spellImage;
        sfe::RichText slotDescriptionLbl;
        std::shared_ptr<Button> slotBtn;

        sf::RectangleShape spellInfoContainer;
        sfe::RichText spellInfoLbl;

        std::shared_ptr<Spell> spell;
        bool mouseHoverImage;
    };

    class ConfirmDialog{
    public:
        ConfirmDialog();
        ConfirmDialog(float x, float y, const std::string& text, const std::shared_ptr<sf::RenderWindow>& window,
                State* state, sf::Font* font, unsigned int characterSize, dialog_type dType);
        virtual ~ConfirmDialog();

        void setSellValue(unsigned value);
        dialog_type getDialogType();
        unsigned getSellValue();

        int update(const sf::Vector2f& mousePos, bool* openDialog);
        void render(sf::RenderTarget& target);

    protected:
        dialog_type  dialogType;
        unsigned sellValue;
        State* state;
        sf::RectangleShape dialog;
        Button yesBtn;
        Button noBtn;
        sf::Text text;
    };

    class PlayerStatusPanel{
    public:
        PlayerStatusPanel();
        PlayerStatusPanel(std::shared_ptr<Player> player, float x, float y, sf::Font* font);
        virtual ~PlayerStatusPanel();

        void setShapeOutlineColor(sf::Color color);
        void setShapeOutlineThickness(float thickness);
        //functions
        void update(const sf::Vector2f& mousePos);
        void render(sf::RenderTarget& target);

    private:
        std::shared_ptr<Player> player;
        sf::Font* font;
        sf::RectangleShape shape;
        sf::Text infoText;
        gui::ProgressBar hpBar;
        gui::ProgressBar mpBar;
    };

    class EnemyStatusPanel{
    public:
        EnemyStatusPanel();
        EnemyStatusPanel(const std::shared_ptr<Enemy>& enemy, float x, float y, sf::Font* font,
                sf::Texture& selected_icon_texture, State* state, unsigned int id);
        virtual ~EnemyStatusPanel();

        //functions
        void selectedIconAnimation(const float& dt);
        void update(const sf::Vector2f& mousePos, const float &dt,
                unsigned int& selected_id, int current_enemy_pos, bool player_turn);
        void render(sf::RenderTarget& target);

    private:
        bool isHovered;
        bool isSelected;

        float selectedIconAnimationKeyTime;
        float selectedIconAnimationMaxKeyTime;
        bool isSelectedIconAnimated;

        unsigned int idPos;
        State* state;
        std::shared_ptr<Enemy> enemy;
        sf::Font* font;
        sf::RectangleShape shape;
        sf::Text infoText;
        gui::ProgressBar hpBar;
        gui::ProgressBar mpBar;
        sf::RectangleShape selectedIcon;
    };

    class ActionRow{
    public:
        ActionRow(float width, float height, float x, float y, const std::shared_ptr<Spell>& spell, float spellDmgMultiplier,
                sf::Font* font, sf::Texture& action_texture);
        virtual ~ActionRow();


        void setUseBtnState(button_states btn_state);
        std::shared_ptr<Spell> getAction() const;
        int getActionFinalDamage() const;
        void startCd();
        void updateCd();
        void endCd();

        bool isUseBtnPressed() const;
        void updateInfoContainer(const sf::Vector2f& mousePos);
        void update(const sf::Vector2f& mousePos, const float &dt);
        void render(sf::RenderTarget& target);
    private:
        float spellDmgMultiplier;
        bool isCd;
        unsigned int cdRemain;
        std::shared_ptr<Spell> spell;
        sf::Font* font;
        sf::RectangleShape shape;
        sf::RectangleShape imageShape;
        sf::Text titleLbl;
        sfe::RichText costLbl;
        sf::Text cdLbl;
        gui::Button useBtn;

        bool mouseHoverImage;
        sf::RectangleShape actionInfoContainer;
        sfe::RichText actionInfoLbl;
    };

    class ItemRow{
    public:
        ItemRow(float width, float height, float x, float y, const std::shared_ptr<Item>& item,
                  sf::Font* font, sf::Texture& item_texture);
        virtual ~ItemRow();

        std::shared_ptr<Item> getItem() const;
        void setUseBtnState(button_states btn_state);
        bool isUseBtnPressed() const;
        void updateQuantityLbl();
        void updateInfoContainer(const sf::Vector2f& mousePos);
        void update(const sf::Vector2f& mousePos);
        void render(sf::RenderTarget& target);
    private:
        std::shared_ptr<Item> item;
        sf::Font* font;
        sf::RectangleShape shape;
        sf::RectangleShape imageShape;
        sf::Text titleLbl;
        sf::Text quantityLbl;
        gui::Button useBtn;

        bool mouseHoverImage;
        sf::RectangleShape infoContainer;
        sfe::RichText infoLbl;
    };
}


#endif //DRAGONSLAYER_GUI_H
