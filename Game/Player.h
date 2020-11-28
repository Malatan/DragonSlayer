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

enum player_equip_slot{
    LEGS_SLOT = 0,
    ARMS_SLOT = 1,
    CHEST_SLOT = 2,
    HEAD_SLOT = 3,
    SHIELD_SLOT = 4,
    WEAPON_SLOT = 5
};

class Player : public Entity{
public:
    //CONSTRUCTOR & DESTRUCTOR
    Player();
    Player(float x, float y, float scale_x, float scale_y, sf::Texture& texture_sheet);
    virtual ~Player();

    //functions
    bool hasShield();
    bool isDead();
    void updateAnimation(const float &dt);
    void update(const float &dt) override;
    void render(sf::RenderTarget& target, bool show_hitbox = false, bool show_clsBox = false);

    //TOSTRING
    std::string toStringEquipment();

    //INVENTORY & STATS
    void setEquipItem(std::shared_ptr<Item> item, int equip_slot);
    void setBonusStats(int hp, int mp, int dmg, int armor, float cc, float ec);
    bool isSlotEquipped(int equip_slot);
    void unequipItem(int equip_slot);
    void addGold(unsigned gold);
    void minusGold(unsigned gold);

    //GET & SET
    std::string getEquippedWeaponType();
    std::shared_ptr<Stats> getPlayerStats();
    std::shared_ptr<Inventory> getInventory();
    unsigned getGold();
    void setGold(unsigned gold);
    std::shared_ptr<Item> getEquippedItem(int equip_slot);
    void setAnimation(entity_animation animation);
    void setAnimation(entity_animation animation, entity_animation next_animation);
    void setNextAnimation(entity_animation next_animation);
    void setDefense(bool b);
    bool isDefense() const;

private:
    //variables
    std::shared_ptr<Stats> playerStats;
    std::shared_ptr<Inventory> inventory;
    int currentInventorySpace;
    unsigned gold;
    bool defense;

    bool animationDone;
    entity_animation animationEnum;
    entity_animation nextAnimationEnum;

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
