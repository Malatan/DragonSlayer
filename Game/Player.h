//
// Created by Zheng on 07/10/2020.
//

#ifndef DRAGONSLAYER_PLAYER_H
#define DRAGONSLAYER_PLAYER_H

#include <string>
#include <sstream>
#include "Entity.h"
#include "Item.h"
#include "Inventory.h"
#include "Stats.h"
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
    ~Player() override;

    //initializers
    void initStats();
    void initInventory();

    //functions
    void unequipItem(int equip_slot);
    void addGold(unsigned add_amount);
    void minusGold(unsigned minus_amount);
    void updateAnimation(const float &dt);
    void update(const float &dt) override;
    void render(sf::RenderTarget& target, sf::Shader* shader = nullptr, sf::Vector2f light_position = sf::Vector2f());

    //GET & SET
    void setEquipItem(const std::shared_ptr<Item>& equip_item, int equip_slot);
    void setBonusStats(int hp, int mp, int dmg, int armor, float cc, float ec);
    bool isSlotEquipped(int equip_slot);
    void setPosition(float x, float y) override;
    bool hasShield();
    bool isDead();
    void setStats(Stats* new_stats);
    void setInventory(std::vector<Item>& items);
    std::string getEquippedWeaponType();
    std::shared_ptr<Stats> getPlayerStats();
    std::shared_ptr<Inventory> getInventory();
    unsigned getGold() const;
    void setGold(unsigned new_gold);
    std::shared_ptr<Item> getEquippedItem(int equip_slot);
    void setAnimation(entity_animation animation, entity_animation next_animation);
    void setDefense(bool b);
    bool isDefense() const;
    std::string toStringEquips() const;

private:
    //variables
    std::shared_ptr<Stats> playerStats;
    std::shared_ptr<Inventory> inventory;
    int currentInventorySpace{};
    unsigned gold{};
    bool defense{};

    bool animationDone{};
    entity_animation animationEnum{};
    entity_animation nextAnimationEnum{};

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
