//
// Created by Zheng on 23/10/2020.
//

#ifndef DRAGONSLAYER_SPELLCOMPONENT_H
#define DRAGONSLAYER_SPELLCOMPONENT_H

#include "../Game/Spell.h"
#include <vector>

class SpellComponent {
private:
    std::vector<Spell*> spells;

protected:

public:
    SpellComponent();
    virtual ~SpellComponent();

    void addSpell(Spell* spell);
    void sortSpellList();

    const std::string toString() const;
};


#endif //DRAGONSLAYER_SPELLCOMPONENT_H
