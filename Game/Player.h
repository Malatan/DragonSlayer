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
public:
    //CONSTRUCTOR & DESTRUCTOR
    Player();
    Player(float x, float y, float scale_x, float scale_y, sf::Texture& texture_sheet);
    virtual ~Player();

    //GRAPHICS
    void updateAnimation(const float &dt);
    void update(const float &dt) override;
    void render(sf::RenderTarget& target, bool show_hitbox = false, const bool show_clsBox = false);

    //BATTLE
    int takeDamage(int dmg);        //RETURN DMG reduced by Player ARMOR
    void heal(int hp);
    void useSpell(string spell);
    void refreshSpells();           //REFRESH cooldown spell
    bool useItem(string item);

    //TOSTRING
    std::string toStringEquipment();
    string listSpells();
    string playerDetails();

    //INVENTORY & STATS
    void setEquipItem(std::shared_ptr<Item> item, int equip_slot);
    void setBonusStats(int hp, int mp, int dmg, int armor, float cc, float ec);
    bool isSlotEquipped(int equip_slot);
    void unequipItem(int equip_slot);
    void addGold(unsigned gold);
    void minusGold(unsigned gold);

    //GET & SET
    Stats* getPlayerStats();
    Inventory* getInventory();
    unsigned getGold();
    void setGold(unsigned gold);
    Spell* getSpellbyIndex(int index);
    std::shared_ptr<Item> getEquippedItem(int equip_slot);

private:
    //variables
    Stats* playerStats;
    Inventory* inventory;
    int currentInventorySpace;
    Spell spells[30];   //contain all game's spells (locked/unlocked)
    unsigned gold;
    std::shared_ptr<Item> weapon;   //equip_slot = 5
    std::shared_ptr<Item> shield;   //equip_slot = 4
    std::shared_ptr<Item> head;     //equip_slot = 3
    std::shared_ptr<Item> chest;    //equip_slot = 2
    std::shared_ptr<Item> arms;     //equip_slot = 1
    std::shared_ptr<Item> legs;     //equip_slot = 0

    //initializer functions
    void initAnimations();

};



#endif //DRAGONSLAYER_PLAYER_H
