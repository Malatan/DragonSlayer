//
// Created by Zheng on 23/10/2020.
//

#include "SpellComponent.h"

//constructors/desctructor
SpellComponent::SpellComponent() = default;

SpellComponent::~SpellComponent() = default;

//accessors
std::vector<std::shared_ptr<Spell>>& SpellComponent::getPlayerSpells() {
    return playerSpells;
}

std::vector<std::shared_ptr<Spell>> &SpellComponent::getSpells() {
    return spells;
}

//functions
void SpellComponent::fill(std::vector<Spell>& save_spells, std::vector<Spell>& save_player_spells) {
    spells.clear();
    playerSpells.clear();

    spells.reserve(save_spells.size());
    playerSpells.reserve(save_player_spells.size());

    for(auto i : save_spells){
        spells.push_back(std::make_shared<Spell>(&i));
    }
    for(auto i : save_player_spells){
        playerSpells.push_back(std::make_shared<Spell>(&i));
    }
}

void SpellComponent::addSpell(Spell spell) {
    spells.push_back(std::make_shared<Spell>(&spell));
}

void SpellComponent::addPlayerSpell(Spell spell) {
    playerSpells.push_back(std::make_shared<Spell>(&spell));
}

std::string SpellComponent::toString() const {
    std::stringstream ss;
    ss << "---------------Spell list---------------\n";
    for(const auto& i : spells){
        ss << i->toString() << "\n";
    }
    ss << "----------------------------------------\n";
    return ss.str();
}

int SpellComponent::maxedPlayerSpellsSize() const {
    int count = 0;
    for(const auto& i : playerSpells){
        if(i->isMaxed() && i->isLearned())
            count++;
    }
    return count;
}
