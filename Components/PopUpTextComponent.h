//
// Created by Zheng on 17/10/2020.
//

#ifndef DRAGONSLAYER_POPUPTEXTCOMPONENT_H
#define DRAGONSLAYER_POPUPTEXTCOMPONENT_H

#include <SFML/Graphics.hpp>
#include <sstream>

enum TextTypes { DEFAULT_TAG, NEGATIVE_TAG, EXPERIENCE_TAG, GOLD_TAG, HEAL_TAG, MANA_RESTORE_TAG};

class PopUpTextComponent {
private:
    class PopUpText {
    private:
        sf::Text text;
        float dirY;
        float dirX;
        float lifetime;
        float speed;
        float acceleration;
        sf::Vector2f velocity;
        int fadeValue;
        bool reverse;

    public:
        PopUpText(sf::Font& font, std::string text, float pos_x, float pos_y, float dir_x, float dir_y,
                sf::Color color, unsigned char_size, float lifetime, bool reverse, float speed, float acceleration, int fade_value) {
            this->text.setFont(font);
            this->text.setPosition(pos_x, pos_y);
            this->text.setFillColor(color);
            this->text.setCharacterSize(char_size);
            this->text.setString(text);

            this->dirX = dir_x;
            this->dirY = dir_y;
            this->lifetime = lifetime;
            this->speed = speed;
            this->acceleration = acceleration;
            this->fadeValue = fade_value;
            this->reverse	= reverse;

            if (this->reverse){
                this->velocity.x = this->dirX * this->speed;
                this->velocity.y = this->dirY * this->speed;
            }
        }

        PopUpText(PopUpText* tag, float pos_x, float pos_y, std::string str) {
            this->text = tag->text;
            this->text.setString(str);
            this->text.setPosition(pos_x, pos_y);

            this->dirX = tag->dirX;
            this->dirY = tag->dirY;
            this->lifetime = tag->lifetime;
            this->speed = tag->speed;
            this->acceleration = tag->acceleration;
            this->fadeValue = tag->fadeValue;
            this->reverse = tag->reverse;
            this->velocity = tag->velocity;
        }

        ~PopUpText() {

        }

        //Accessor
        inline const bool isExpired() const{ return this->lifetime <= 0.f; }

        //Function
        void update(const float& dt) {
            if (this->lifetime > 0.f) {
                //Update the lifetime
                this->lifetime -= 100.f * dt;

                //Accelerate
                if (this->acceleration > 0.f) {
                    if (this->reverse) {
                        this->velocity.x -= this->dirX * this->acceleration * dt;
                        this->velocity.y -= this->dirY * this->acceleration * dt;

                        if (abs(this->velocity.x) < 0.f)
                            this->velocity.x = 0.f;

                        if (abs(this->velocity.y) < 0.f)
                            this->velocity.y = 0.f;

                        this->text.move(this->velocity * dt);
                    }
                    else {
                        this->velocity.x += this->dirX * this->acceleration * dt;
                        this->velocity.y += this->dirY * this->acceleration * dt;

                        if (abs(this->velocity.x) > this->speed)
                            this->velocity.x = this->dirX * this->speed;

                        if (abs(this->velocity.y) > this->speed)
                            this->velocity.y = this->dirY * this->speed;

                        this->text.move(this->velocity * dt);
                    }
                }
                else {
                    //Move the tag
                    this->text.move(this->dirX * this->speed * dt, this->dirY * this->speed * dt);
                }

                if (this->fadeValue > 0 && this->text.getFillColor().a >= this->fadeValue) {
                    this->text.setFillColor(sf::Color(
                                            this->text.getFillColor().r,
                                            this->text.getFillColor().g,
                                            this->text.getFillColor().b,
                                            this->text.getFillColor().a - this->fadeValue));
                }
            }
        }

        void render(sf::RenderTarget& target) {
            target.draw(this->text);
        }
    };

    sf::Window* window;
    sf::Font font;
    std::map<unsigned, PopUpText*> popUpTextTemplates;
    std::vector<PopUpText*> popUpTexts;

    sf::Vector2f windowCenter;

    //Private functions
    void initTagTemplates();

public:
    PopUpTextComponent(sf::Font font, sf::Window* window);
    virtual ~PopUpTextComponent();

    //Functions
    void addPopUpText(const unsigned tag_type, const float pos_x, const float pos_y,
            const std::string str, const std::string prefix, const std::string postfix);
    void addPopUpText(const unsigned tag_type, const float pos_x, const float pos_y,
            const int i, const std::string prefix, const std::string postfix);

    void addPopUpTextCenter(const unsigned tag_type, const std::string str, const std::string prefix, const std::string postfix);
    void addPopUpTextCenter(const unsigned tag_type, const int i, const std::string prefix, const std::string postfix);

    void update(const float &dt);
    void render(sf::RenderTarget & target);
};


#endif //DRAGONSLAYER_POPUPTEXTCOMPONENT_H
