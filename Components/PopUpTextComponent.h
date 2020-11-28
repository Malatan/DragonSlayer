//
// Created by Zheng on 17/10/2020.
//

#ifndef DRAGONSLAYER_POPUPTEXTCOMPONENT_H
#define DRAGONSLAYER_POPUPTEXTCOMPONENT_H

#include <SFML/Graphics.hpp>
#include <sstream>
#include <memory>

enum TextTypes { DEFAULT_TAG, NEGATIVE_TAG, EXPERIENCE_TAG, GOLD_TAG, HEAL_TAG, MANA_RESTORE_TAG};

class PopUpTextComponent {
public:
    PopUpTextComponent(const sf::Font& font, const std::shared_ptr<sf::RenderWindow>& window);
    virtual ~PopUpTextComponent();

    //Functions
    void addPopUpText(unsigned tag_type, float pos_x, float pos_y,
                      const std::string& str, const std::string& prefix, const std::string& postfix, float delay = 0.f);
    void addPopUpText(unsigned tag_type, float pos_x, float pos_y,
                      int i, const std::string& prefix, const std::string& postfix, float delay = 0.f);

    void addPopUpTextCenter(unsigned tag_type, const std::string& str, const std::string& prefix, const std::string& postfix,
            float delay = 0.f);
    void addPopUpTextCenter(unsigned tag_type, int i, const std::string& prefix, const std::string& postfix,
            float delay = 0.f);

    void update(const float &dt);
    void render(sf::RenderTarget & target);

private:
    class PopUpText {
    private:
        sf::Text text;
        float dirY;
        float dirX;
        float lifetime;
        float speed;
        float acceleration;
        float delay;
        sf::Vector2f velocity;
        int fadeValue;
        bool reverse;

    public:
        PopUpText(sf::Font& font, const std::string& text, float pos_x, float pos_y, float dir_x, float dir_y,
                  sf::Color color, unsigned char_size, float lifetime, bool reverse, float speed, float acceleration,
                  int fade_value) {
            this->text.setFont(font);
            this->text.setPosition(pos_x, pos_y);
            this->text.setFillColor(color);
            this->text.setCharacterSize(char_size);
            this->text.setString(text);

            this->delay = 0.f;
            this->dirX = dir_x;
            this->dirY = dir_y;
            this->lifetime = lifetime;
            this->speed = speed;
            this->acceleration = acceleration;
            this->fadeValue = fade_value;
            this->reverse = reverse;

            if (this->reverse){
                this->velocity.x = this->dirX * this->speed;
                this->velocity.y = this->dirY * this->speed;
            }
        }

        PopUpText(const std::shared_ptr<PopUpText>& tag, float pos_x, float pos_y, const std::string& str, float delay) {
            text = tag->text;
            text.setString(str);
            text.setPosition(pos_x - text.getGlobalBounds().width/2.f, pos_y);

            this->delay = delay;
            dirX = tag->dirX;
            dirY = tag->dirY;
            lifetime = tag->lifetime;
            speed = tag->speed;
            acceleration = tag->acceleration;
            fadeValue = tag->fadeValue;
            reverse = tag->reverse;
            velocity = tag->velocity;
        }

        ~PopUpText() {

        }

        //Accessor
        inline bool isExpired() const{ return lifetime <= 0.f; }

        //Function
        void update(const float& dt) {
            if(delay > 0){
                delay -= 100.f * dt;
            }else{
                if (lifetime > 0.f) {
                    //Update the lifetime
                    lifetime -= 100.f * dt;
                    //Accelerate
                    if (acceleration > 0.f) {
                        if (reverse) {
                            velocity.x -= dirX * acceleration * dt;
                            velocity.y -= dirY * acceleration * dt;
                            if (std::abs(velocity.x) < 0.f)
                                velocity.x = 0.f;
                            if (std::abs(velocity.y) < 0.f)
                                velocity.y = 0.f;
                            text.move(velocity * dt);
                        }
                        else {
                            velocity.x += dirX * acceleration * dt;
                            velocity.y += dirY * acceleration * dt;
                            if (std::abs(velocity.x) > speed)
                                velocity.x = dirX * speed;
                            if (std::abs(velocity.y) > speed)
                                velocity.y = dirY * speed;
                            text.move(velocity * dt);
                        }
                    }
                    else {
                        //Move the tag
                        text.move(dirX * speed * dt, dirY * speed * dt);
                    }
                    if (fadeValue > 0 && text.getFillColor().a >= fadeValue) {
                        text.setFillColor(sf::Color(
                                text.getFillColor().r,
                                text.getFillColor().g,
                                text.getFillColor().b,
                                text.getFillColor().a - fadeValue));
                    }
                }
            }
        }

        void render(sf::RenderTarget& target) {
            target.draw(text);
        }
    };

    std::shared_ptr<sf::RenderWindow> window;
    sf::Font font;
    std::map<unsigned, std::shared_ptr<PopUpText>> popUpTextTemplates;
    std::vector<std::shared_ptr<PopUpText>> popUpTexts;
    sf::Vector2f windowCenter;

    //Private functions
    void initTagTemplates();
};


#endif //DRAGONSLAYER_POPUPTEXTCOMPONENT_H
