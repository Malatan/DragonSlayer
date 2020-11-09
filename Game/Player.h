//
// Created by Zheng on 07/10/2020.
//

#ifndef DRAGONSLAYER_PLAYER_H
#define DRAGONSLAYER_PLAYER_H

#include "Entity.h"
#include <string>
#include <sstream>
#include "Item.h"
#include "Inventory.h"
#include "Stats.h"
#include "iostream"
#include "fstream"
#include "Spell.h"


class Player : public Entity{
private:
    //variables
    Stats* playerStats;
    Inventory* inventory;
    int currentInventorySpace;
    Spell spells[30];   //contain all game's spells (locked/unlocked)
    unsigned gold;
    Item* weapon;   //equip_slot = 5
    Item* shield;   //equip_slot = 4
    Item* head;     //equip_slot = 3
    Item* chest;    //equip_slot = 2
    Item* arms;     //equip_slot = 1
    Item* legs;     //equip_slot = 0

    //initializer functions
    void initVariables();
    void initAnimations();

protected:

public:
    //CONSTRUCTOR & DESTRUCTOR
    Player();
    Player(float x, float y, float scale_x, float scale_y, sf::Texture& texture_sheet);
    virtual ~Player();


    //GRAPHICS
    void updateAnimation(const float &dt);
    void update(const float &dt);
    void render(sf::RenderTarget& target, const bool show_hitbox = false);

    //BATTLE
    int takeDamage(int dmg);        //RETURN DMG reduced by Player ARMOR
    void heal(int hp);
    void useSpell(string spell);
    void earnExp(int exp);
    void refreshSpells();           //REFRESH cooldown spell
    bool useItem(string item);

    //TOSTRING
    std::string toStringEquipment();
    string listSpells();
    string listEquipment();
    string playerDetails();

    //INVENTORY & STATS
    void setEquipItem(Item* item, int equip_slot);
    void setBonusStats(int hp, int mp, int dmg, int armor, float cc, float ec);
    void reloadEquipBonus();    //APPLY item bonus to player stats
    void loadEquipment();       //SEARCH FOR equipped items in inventory
    bool isSlotEquipped(int equip_slot);
    void unequipItem(int equip_slot);
    void addGold(unsigned gold);
    void minusGold(unsigned gold);
    void importSpells();
    bool exportSpells();
    void learnSpell(string spell);
    bool takeItem(Item* item);

    //GET & SET
    Stats* getPlayerStats();
    void setPlayerStats(Stats* playerStats);
    Inventory* getInventory();
    void setInventory(Inventory* invent);
    unsigned getGold();
    void setGold(unsigned gold);
    Spell* getSpells();
    Spell* getSpellbyIndex(int index);
    Item* getEquippedItem(int equip_slot);

};



#endif //DRAGONSLAYER_PLAYER_H
