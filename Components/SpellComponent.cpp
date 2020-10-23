//
// Created by Zheng on 23/10/2020.
//

#include "SpellComponent.h"

//constructors/desctructor
SpellComponent::SpellComponent() {

}

SpellComponent::~SpellComponent() {
    for(auto i : this->spells){
        delete i;
    }
    for(auto i : this->playerSpells){
        delete i;
    }
}

//accessors
std::vector<Spell *> SpellComponent::getSpells() {
    return this->spells;
}

std::vector<Spell *> SpellComponent::getPlayerSpells() {
    return this->playerSpells;
}

//functions
void SpellComponent::addSpell(Spell *spell) {
    this->spells.push_back(spell);
}

void SpellComponent::addPlayerSpell(Spell *spell) {
    Spell* newSpell = new Spell(spell);
    this->playerSpells.push_back(newSpell);
}

void SpellComponent::sortSpellList() {

}

const std::string SpellComponent::toString() const {
    std::stringstream ss;
    ss << "---------------Spell list---------------\n";
    for(auto i : this->spells){
        ss << i->toString() << "\n";
    }
    ss << "----------------------------------------\n";
    return ss.str();
}

const std::string SpellComponent::toStringPlayer() const {
    std::stringstream ss;
    ss << "---------------Player Spell list---------------\n";
    for(auto i : this->playerSpells){
        ss << i->toString() << "\n";
    }
    ss << "------------------------------------------------\n";
    return ss.str();
}
