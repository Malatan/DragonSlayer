//
// Created by Administrator on 08/10/2020.
//

#ifndef DRAGONSLAYER_HITBOXCOMPONENT_H
#define DRAGONSLAYER_HITBOXCOMPONENT_H

#include <SFML/Graphics.hpp>
#include <memory>

class HitboxComponent {
public:
    HitboxComponent(sf::Sprite& sprite,
                    float offset_x, float offset_y,
                    float width, float height);
    virtual ~HitboxComponent();

    //Accessors
    const sf::Vector2f& getPosition() const;
    sf::FloatRect getGlobalBounds() const;
    const sf::FloatRect & getNextPosition(const sf::Vector2f& velocity);


    //Modifiers
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    void setPositionY(float y);
    void setPositionX(float x);

    //Functions
    bool intersects(const sf::FloatRect& frect);
    sf::Vector2f getCenter();
    void update();
    void render(sf::RenderTarget& target);

private:
    sf::Sprite& sprite;
    sf::RectangleShape hitbox;
    sf::FloatRect nextPosition;
    float offsetX;
    float offsetY;
};


#endif //DRAGONSLAYER_HITBOXCOMPONENT_H
