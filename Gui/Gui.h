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

enum dialog_result{
    YES_RESULT,
    NO_RESULT,
    PENDING_RESULT
};

enum notifaction_phase{
    ENTERING_PHASE,
    DISPLAYING_PHASE,
    EXITING_PHASE
};

namespace gui{
    class Button {
    public:
        Button();
        Button(float x, float y, float width, float height, sf::Font* font,
               const std::string& text, unsigned character_size, short unsigned id = 0);
        Button(float x, float y, float width, float height, sf::Font* font,
               const std::string& text, unsigned character_size,
               sf::Color text_idle_color, sf::Color text_hover_color,sf::Color text_active_color,
               sf::Color idle_color,sf::Color hover_color, sf::Color active_color, short unsigned id = 0);
        virtual ~Button();

        //accessors
        bool isPressed() const;
        bool isDisabled() const;
        const short unsigned& getId() const;
        sf::Vector2f getPosition();
        sf::FloatRect getGlobalBounds() const;

        //modifiers
        void setButtonState(button_states);
        void setPosition(float x, float y);
        void setPosition(sf::Vector2f pos);
        void setSize(sf::Vector2f size);
        void setText(const std::string& new_text);
        void setIdleTextColor(sf::Color idle_color);
        void setId(short unsigned new_id);
        void setBorderColor(sf::Color color);
        void setBorderLineThickness(float value);
        void setTooltipText(const std::string& new_text);
        void setTooltipDisabled(bool b);
        void setDisabled(bool b, bool change_color = true);
        void setBackgroundTexture(sf::Texture* texture);
        void setBackbgroundDisabled(bool b);
        void setBackgroundFilLColor(sf::Color color);

        //functions
        bool contains(const sf::Vector2f& mousePos);
        void updateTooltipPos(const sf::Vector2f& mousePos);
        void update(const sf::Vector2f& mousePos);
        void render(sf::RenderTarget& target);

    private:
        short unsigned buttonState{};
        short unsigned id{};

        bool hover{};
        bool disabled{};
        bool tooltipDisabled{};
        bool textDisabled{};
        bool backgroundDisabled{};

        sf::RectangleShape shape;
        sf::RectangleShape background;
        sf::RectangleShape tooltipContainer;
        sf::Text tooltipText;
        sf::Font* font{};
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
        int getMaxValue() const;
        void setDisabled(bool b);
        bool isDisabled() const;

        //modifiers
        void setText(const std::string& new_text);
        void setProgressShapeColor(sf::Color color);
        void setProgressBorderColor(sf::Color color);

        //functions
        void update(int current, int max_value);
        void render(sf::RenderTarget& target);

    private:
        sf::Font* font{};
        sf::Text text;
        sf::RectangleShape barShape;
        sf::RectangleShape progressShape;

        bool disabled{};
        int min{};
        int max{};
        int currentValue{};
        float progressPercentage{};
    };

    class ItemSlot{
    public:
        //constructors/destructors
        ItemSlot();
        ItemSlot(float x, float y, float width, float height, std::shared_ptr<sf::RenderWindow> window,
                sf::Font* font, const std::shared_ptr<Item>& item, State* state, bool isEquipSlot);
        virtual ~ItemSlot();

        //accessors
        bool getIsSelected() const;
        std::shared_ptr<Item> getItem();
        sf::RectangleShape* getShape();
        void setOutlineColors(sf::Color new_color);
        sf::IntRect* getIntRect();
        bool isEquipSlotUnequip() const;
        void setIsEquipSlotUnequip(bool b);

        //modifiers
        void setItem(std::shared_ptr<Item> new_item);
        void setShapeTexture(const sf::Texture *new_shape_texture, const sf::IntRect* texture_intRect);
        void setSlotTexture(const sf::Texture *new_texture, float size);
        void setSlotTexture(sf::Texture* new_texture, sf::IntRect texture_intRect);
        void setSelectedBool(bool b);
        void setDownRightTexture(sf::Texture* new_texture);
        void setUpRightTexture(sf::Texture* new_texture);

        //functions
        void updateQuantityLbl();
        void updateItemInfo();
        void updateItemInfoPos(const sf::Vector2f& mousePos);
        void update(const sf::Vector2f& mousePos, bool inv);
        void renderInfoContainer(sf::RenderTarget& target);
        void render(sf::RenderTarget& target);

    private:
        short unsigned slotState{};
        bool renderItemInfoContainer{};
        bool isSelected{};
        bool isEquipSlot{};
        bool equipSlotUnequip{};

        std::shared_ptr<Item> item;
        State* state{};
        std::shared_ptr<sf::RenderWindow> window;
        sf::RectangleShape shape;
        sf::RectangleShape cover;
        sf::RectangleShape downRight;
        sf::RectangleShape upRight;
        sf::IntRect intRect;
        sf::Font* font{};
        sf::Texture texture;

        sf::RectangleShape itemInfoContainer;
        sf::Text itemInfoLbl;
        sf::Text quantityLbl;
    };

    class ShopSlot{
    public:
        //constructors/destructor
        ShopSlot();
        ShopSlot(float width, float height, float pos_x, float pos_y, sf::Font* font, Item item, std::string  key);
        virtual ~ShopSlot();

        //accessors
        Item getItem() const;
        unsigned int getPrice() const;
        std::string getKey() const;

        //modifiers
        void setSlotTexture(const sf::Texture *slot_texture, float size);

        //functions
        void updateItemInfoContainerPos(const sf::Vector2f& mousePos);
        bool isPressed();
        void update(const sf::Vector2f &mousePos);
        void render(sf::RenderTarget& target);

    private:
        sf::RectangleShape shape;
        sf::Text priceLbl;
        sf::Texture texture;
        gui::Button buyBtn;
        Item item{};
        std::string key;

        sf::RectangleShape itemInfoContainer;
        sf::Text itemInfoLbl;
        bool mouseHoverImage{};

        unsigned int price{};
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
        sf::Text descriptionLbl;
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
        bool mouseHoverImage{};
    };

    class CustomDialog{
    public:
        CustomDialog();
        CustomDialog(float x, float y, std::shared_ptr<Item> item, std::shared_ptr<sf::RenderWindow>  window,
                     State* state, sf::Font* font, dialog_type dType);
        CustomDialog(float x, float y, int tot_value, int selected_quantity, std::shared_ptr<sf::RenderWindow>  window,
                     State* state, sf::Font* font, dialog_type dType);
        virtual ~CustomDialog();

        dialog_result getResult();
        dialog_type getDialogType();
        int getFinalQuantity() const;
        std::shared_ptr<Item> getItem();
        int getTotValue() const;

        void updateLbls();
        void update(const sf::Vector2f& mousePos);
        void render(sf::RenderTarget& target);

    protected:
        std::shared_ptr<sf::RenderWindow> window;
        dialog_type dialogType{};
        std::shared_ptr<Item> item;
        State* state{};
        sf::RectangleShape dialog;
        Button plusOneBtn;
        Button plusFiveBtn;
        Button minusOneBtn;
        Button minusFiveBtn;
        Button maxBtn;
        Button minBtn;
        Button yesBtn;
        Button noBtn;
        sf::Text textLbl;
        sf::Text quantityLbl;
        int maxQuantity{};
        int currentQuantity{};
        int totValue{};
        bool singleQuantity{};
        bool multipleItem{};
        dialog_result answer{};

        void initButtons(sf::Font* font);
    };

    class BuffSlot{
    public:
        //constructors/desctructor
        BuffSlot();
        BuffSlot(float x, float y, float width, float height,
                const std::shared_ptr<Buff>& buff, const sf::Texture& buff_texture, sf::Font* font);
        virtual ~BuffSlot();

        void setBuff(std::shared_ptr<Buff> new_buff, bool updateLbl = false);
        std::shared_ptr<Buff> getBuff() const;

        //functions
        void updateDescriptionLbl();
        void updateInfoContainer(const sf::Vector2f& mousePos);
        void update(const sf::Vector2f& mousePos);
        void render(sf::RenderTarget& target);

    private:
        bool mouseHoverImage{};
        std::shared_ptr<Buff> buff;

        sf::RectangleShape shape;
        sf::RectangleShape infoContainer;
        sf::Text infoLbl;
        sf::Text lifeTimeLbl;
    };

    class PlayerStatusPanel{
    public:
        PlayerStatusPanel();
        PlayerStatusPanel(std::shared_ptr<Player> player, float x, float y, sf::Font* font);
        virtual ~PlayerStatusPanel();

        void setShapeOutlineThickness(float thickness);
        //functions
        void update(const sf::Vector2f& mousePos);
        void render(sf::RenderTarget& target);

    private:
        std::shared_ptr<Player> player;
        sf::Font* font{};
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
                unsigned int& selected_id, unsigned int current_enemy_pos, bool player_turn);
        void render(sf::RenderTarget& target);

    private:
        bool isHovered{};
        bool isSelected{};

        float selectedIconAnimationKeyTime{};
        float selectedIconAnimationMaxKeyTime{};
        bool isSelectedIconAnimated{};

        unsigned int idPos{};
        State* state{};
        std::shared_ptr<Enemy> enemy;
        sf::Font* font{};
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
        void setDisabled(bool b);
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
        void setDisabled(bool b);
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

    class LootSlot{
    public:
        //constructors/destructor
        LootSlot(float width, float height, float pos_x, float pos_y, sf::Font* font, const std::shared_ptr<Item>& item,
                 sf::Texture& item_texture);
        virtual ~LootSlot();

        //getters
        unsigned int getId();
        std::shared_ptr<Item> getItem();

        //functions
        void updateItemInfo();
        void updateItemInfoContainerPos(const sf::Vector2f& mousePos);
        bool isPressed();
        void renderInfoContainer(sf::RenderTarget& target);
        void update(const sf::Vector2f &mousePos);
        void render(sf::RenderTarget& target);

    private:
        bool mouseHoverImage{};
        std::shared_ptr<Item> item;

        sf::RectangleShape shape;
        sf::Text quantityLbl;
        gui::Button lootBtn;

        sf::Text itemInfoLbl;
        sf::RectangleShape itemInfoContainer;
    };

    class AchievementSlot{
    public:
        //constructors/destructor
        AchievementSlot(float width, float height, float pos_x, float pos_y, sf::Font* font,
                        const std::shared_ptr<Achievement>& achievement, int current_value);
        virtual ~AchievementSlot();

        //accessor/modifiers
        achievement_event getAchievementEventType();

        //functions
        void updateAchievement(int current_value, bool achieved = false);
        void update(const sf::Vector2f& mousePos);
        void render(sf::RenderTarget& target);

    private:
        sf::RectangleShape shape;
        sf::Text titleLbl;
        sf::Text descriptionLbl;
        gui::ProgressBar progressBar;
        achievement_event eventType;
        int goal;
    };

    class AchievementNotification{
    public:
        //constructors/destructor
        AchievementNotification(float pos_x, float pos_y, const std::shared_ptr<Achievement>& achievement, sf::Font *font);
        ~AchievementNotification();

        //accessors/modifiers
        bool isDone() const;

        //functions
        void move(sf::Vector2f move_velocity);
        void update(const float& dt, const sf::Vector2f &mousePos);
        void render(sf::RenderTarget& target);

    private:
        sf::Vector2f origin;
        sf::RectangleShape shape;
        sf::Text titleLbl;
        sf::Text nameLbl;
        sf::Text descLbl;

        notifaction_phase animationPhase{};
        float lifeTime{};
        float speed{};
        sf::Vector2f velocity;
        bool done{};
    };

    class LoadSaveSlot{
    public:
        //constructors/destructor
        LoadSaveSlot(float x, float y, float width, float height, sf::Font* font);
        virtual ~LoadSaveSlot();

        //modifiers/accessors
        bool isEmpty() const;
        std::string getName() const;
        void setInfo(const std::string& s_name, const std::string& s_time);
        bool saveBtnIsPressed() const;
        bool loadBtnIsPressed() const;

        //functions
        void clear();
        void setLoadBtnDisabled(bool b);
        void setSaveBtnDisabled(bool b);
        void update(const sf::Vector2f& mousePos);
        void render(sf::RenderTarget& target);

    private:
        sf::RectangleShape container;
        sf::Text titleLbl;
        sf::Text timeLbl;
        gui::Button saveBtn;
        gui::Button loadBtn;
        std::string saveName;
        std::string saveLastMod;
        bool empty;
    };
}


#endif //DRAGONSLAYER_GUI_H
