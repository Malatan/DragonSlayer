//
// Created by Zheng on 22/01/2021.
//

#ifndef DRAGONSLAYER_MINIMAP_H
#define DRAGONSLAYER_MINIMAP_H

#include "../Core/GameState.h"

class MiniMap {
public:
    //Constructor/desctructor
    MiniMap(State* state, sf::Font* font, sf::Vector2u window_size, int scale);
    ~MiniMap();

    //getters
    int getZoomFactor() const;
    int getMaxZoomFactor() const;
    int getMinZoomFactor() const;
    int getScale() const;
    bool isHide() const;

    //functions
    void hideMinimap();
    void updateLocationLbl(int floor);
    void updateValues();
    void updateView();
    void drawTexture(bool update_values = true);
    void drawEntities();
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget* target);

private:
    GameState* gState;
    sf::Font* font;
    sf::View minimapView;
    sf::RenderTexture minimapTexture;
    sf::RenderTexture entitiesTexture;
    sf::Sprite minimapSprite;
    sf::Sprite entitiesSprite;
    sf::RectangleShape minimapBackground;
    sf::Text locationLbl;
    gui::Button* zoomInBtn{};
    gui::Button* zoomOutBtn{};
    gui::Button* hideBtn{};

    sf::Vector2f viewSize{};
    bool hide{};
    int zoomFactor{1};
    int maxZoomFactor{1};
    int minZoomFactor{1};
    int scale{};
    int mapWidth{};
    int mapHeight{};
    int mapWidthP{};
    int mapHeightP{};

    //initializzers
    void initGui(sf::Vector2u window_size);
};


#endif //DRAGONSLAYER_MINIMAP_H
