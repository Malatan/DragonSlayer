//
// Created by Administrator on 08/10/2020.
//

#ifndef DRAGONSLAYER_HITBOXCOMPONENT_H
#define DRAGONSLAYER_HITBOXCOMPONENT_H

#include <SFML/Graphics.hpp>

class HitboxComponent
{
private:
    sf::Sprite& sprite;
    sf::RectangleShape hitbox;
    float offsetX;
    float offsetY;

public:
    HitboxComponent(sf::Sprite& sprite,
                    float offset_x, float offset_y,
                    float width, float height);
    virtual ~HitboxComponent();

    //Accessors
    const sf::Vector2f& getPosition() const;
    const sf::FloatRect getGlobalBounds() const;


    //Modifiers
    void setPosition(const sf::Vector2f& position);
    void setPosition(const float x, const float y);

    //Functions
    bool intersects(const sf::FloatRect& frect);
    sf::Vector2f getCenter();
    void update();
    void render(sf::RenderTarget& target);
};


#endif //DRAGONSLAYER_HITBOXCOMPONENT_H
