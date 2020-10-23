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
    std::vector<Spell*> playerSpells;

protected:

public:
    //constructors/desctructor
    SpellComponent();
    virtual ~SpellComponent();

    //accessors
    std::vector<Spell*> getSpells();
    std::vector<Spell*> getPlayerSpells();

    //functions
    void addSpell(Spell* spell);
    void addPlayerSpell(Spell* spell);
    void sortSpellList();
    const std::string toString() const;
    const std::string toStringPlayer() const;
};


#endif //DRAGONSLAYER_SPELLCOMPONENT_H
