//
// Created by Zheng on 23/10/2020.
//

#ifndef DRAGONSLAYER_SPELLCOMPONENT_H
#define DRAGONSLAYER_SPELLCOMPONENT_H

#include "../Game/Spell.h"
#include <vector>
#include <memory>

class SpellComponent {
public:
    //constructors/desctructor
    SpellComponent();
    virtual ~SpellComponent();

    //accessors
    std::vector<std::shared_ptr<Spell>>& getPlayerSpells();
    std::vector<std::shared_ptr<Spell>>& getSpells();

    //functions
    void fill(std::vector<Spell>& save_spells, std::vector<Spell>& save_player_spells);
    int maxedPlayerSpellsSize() const;
    void addSpell(Spell spell);
    void addPlayerSpell(Spell spell);
    std::string toString() const;
    std::string toStringPlayer() const;

private:
    std::vector<std::shared_ptr<Spell>> spells;
    std::vector<std::shared_ptr<Spell>> playerSpells;
};


#endif //DRAGONSLAYER_SPELLCOMPONENT_H
