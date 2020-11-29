//
// Created by Zheng on 16/10/2020.
//

#ifndef DRAGONSLAYER_BUFFCOMPONENT_H
#define DRAGONSLAYER_BUFFCOMPONENT_H

#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include "PopUpTextComponent.h"
#include "../Game/Stats.h"
#include "../Game/Buff.h"
#include "../Gui/Gui.h"
#include "../Core/GameState.h"

class GameState;

class BuffComponent {
public:
    BuffComponent(std::shared_ptr<PopUpTextComponent> popUpTextComponent, State *state, sf::Font* font);
    virtual ~BuffComponent();



    void addBuff(const std::string& key, const std::shared_ptr<Buff>& buff);
    void addPlayerBuff(const std::shared_ptr<Buff>& buff);
    void applyItemBuff(const std::string& key, const std::shared_ptr<Stats>& stats, bool popup_text_center, float popup_text_x = 0.f,
            float popup_text_y = 0.f);
    void updateBuffBar();
    void updatePlayerBuffList();
    void update(const float& dt, const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);

    std::string toStringBuffs() const;
    std::string toStringPlayerBuffs() const;

private:
    std::shared_ptr<PopUpTextComponent> popUpTextComponent;
    GameState* gState;
    sf::Font* font;
    std::map<std::string, std::shared_ptr<Buff>> buffs;
    std::vector<std::shared_ptr<Buff>> playerBuffsList;
    std::vector<std::unique_ptr<gui::BuffSlot>> buffBar;
};


#endif //DRAGONSLAYER_BUFFCOMPONENT_H
