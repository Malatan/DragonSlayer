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
namespace gui{
    class BuffSlot;
}


class BuffComponent {
public:
    //constructor/destructor
    BuffComponent(std::shared_ptr<PopUpTextComponent> popUpTextComponent, std::shared_ptr<Player> player, State *state, sf::Font* font);
    virtual ~BuffComponent();

    //accessors
    std::vector<std::shared_ptr<Buff>>& getPlayerBuffsList();
    std::string toStringBuffs() const;
    std::string toStringPlayerBuffs() const;

    //functions
    void loadPlayerBuffs(std::vector<Buff>& save_buffs);
    void addBuff(const std::string& key, const std::shared_ptr<Buff>& buff);
    void addPlayerBuff(const std::shared_ptr<Buff>& buff);
    void applyItemBuff(const std::string& key, bool popup_text_center, float popup_text_x = 0.f, float popup_text_y = 0.f);
    void expireItemBuff(const std::shared_ptr<Buff>& expired_buff);
    void updateBuffBar();
    void updatePlayerBuffList();
    void update(const float& dt, const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);

private:
    GameState* gState;
    sf::Font* font;
    std::shared_ptr<Player> player;
    std::shared_ptr<PopUpTextComponent> popUpTextComponent;
    std::map<std::string, std::shared_ptr<Buff>> buffs;
    std::vector<std::shared_ptr<Buff>> playerBuffsList;
    std::vector<std::unique_ptr<gui::BuffSlot>> buffBar;

    //init
    void initBuffs();
};


#endif //DRAGONSLAYER_BUFFCOMPONENT_H
