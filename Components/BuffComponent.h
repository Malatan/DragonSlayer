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
    BuffComponent(std::shared_ptr<PopUpTextComponent> popUpTextComponent, std::shared_ptr<Player> player, State *state, sf::Font* font);
    virtual ~BuffComponent();

    void addBuff(const std::string& key, const std::shared_ptr<Buff>& buff);
    bool addPlayerBuff(const std::shared_ptr<Buff>& buff);
    void applyItemBuff(const std::string& key, bool popup_text_center, float popup_text_x = 0.f, float popup_text_y = 0.f);
    void expireItemBuff(const std::shared_ptr<Buff>& expired_buff);
    void updateBuffBar();
    void updatePlayerBuffList();
    void update(const float& dt, const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);

    std::string toStringBuffs() const;
    std::string toStringPlayerBuffs() const;

private:
    GameState* gState;
    sf::Font* font;
    std::shared_ptr<Player> player;
    std::shared_ptr<PopUpTextComponent> popUpTextComponent;
    std::map<std::string, std::shared_ptr<Buff>> buffs;
    std::vector<std::shared_ptr<Buff>> playerBuffsList;
    std::vector<std::unique_ptr<gui::BuffSlot>> buffBar;
};


#endif //DRAGONSLAYER_BUFFCOMPONENT_H
