//
// Created by Zheng on 23/10/2020.
//

#include "SpellComponent.h"

SpellComponent::SpellComponent() {

}

SpellComponent::~SpellComponent() {
    for(auto i : this->spells){
        delete i;
    }
}

void SpellComponent::addSpell(Spell *spell) {
    this->spells.push_back(spell);
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

void SpellComponent::sortSpellList() {

}
