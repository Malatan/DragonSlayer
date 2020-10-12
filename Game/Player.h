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
    Spell spells[30];           //TUTTE SPELL DEL GIOCO - ALCUNE SARANNO SBLOCCATE E ALTRE NO
    int gold;
    Item weapon;
    Item shield;
    Item head;
    Item chest;
    Item arms;
    Item legs;

    //initializer functions
    void initVariables();
    void initAnimations();

protected:

public:
    Player();
    Player(float x, float y, float scale_x, float scale_y, sf::Texture& texture_sheet);
    virtual ~Player();


    //funtions
    void updateAnimation(const float &dt);
    void update(const float &dt);
    void render(sf::RenderTarget& target, const bool show_hitbox = false);

    int takeDamage(int dmg);        //RETURN DMG reduced by Player ARMOR
    string playerDetails();


    void reloadEquipStats();    //applica i bonus degli oggetti alle stats
    string listEquipment();
    void importEquipment();
    bool exportEquipment();
    string listSpells();
    void importSpells();
    bool exportSpells();
    void learnSpell(string spell);
    void earnExp(int exp);

    Stats* getPlayerStats();
    void setPlayerStats(Stats* playerStats);
    Inventory* getInventory();
    void setInventory(Inventory* invent);
    int getGold();
    void setGold(int gold);
    Item getWeapon();
    void equipWeapon(Item weapon);
    Item getShield();
    void equipShield(Item shield);
    Item getHead();
    void equipHead(Item head);
    Item getChest();
    void equipChest(Item chest);
    Item getLegs();
    void equipLegs(Item legs);
    Item getArms();
    void equipArms(Item arms);
};



#endif //DRAGONSLAYER_PLAYER_H
