//
// Created by Zheng on 23/10/2020.
//

#include "SpellComponent.h"

//constructors/desctructor
SpellComponent::SpellComponent() = default;

SpellComponent::~SpellComponent() = default;

//accessors
std::vector<std::shared_ptr<Spell>> SpellComponent::getPlayerSpells() {
    return playerSpells;
}

//functions
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

std::string SpellComponent::toStringPlayer() const {
    std::stringstream ss;
    ss << "---------------Player Spell list---------------\n";
    for(const auto& i : playerSpells){
        ss << i->toString() << "\n";
    }
    ss << "------------------------------------------------\n";
    return ss.str();
}
