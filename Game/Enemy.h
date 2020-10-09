//
// Created by Zheng on 08/10/2020.
//

#ifndef DRAGONSLAYER_ENEMY_H
#define DRAGONSLAYER_ENEMY_H
#include <string>
#include <sstream>
#include "Item.h"
#include "Inventory.h"
#include "Stats.h"
#include "iostream"
#include "fstream"
#include "Spell.h"
#include "Entity.h"

class Enemy : public Entity{
private:
    //variables
    string name;
    string type;

    int level;
    int hp;
    int maxHp;
    int armor;
    int damage;
    int critChance;
    int evadeChance;


    //initializer functions
    void initVariables();
    void initAnimations();

protected:

public:
    Enemy(float x, float y,float scale_x ,float scale_y, sf::Texture& texture_sheet);
    Enemy(float x, float y,float scale_x ,float scale_y, float hitbox_offset_x, float hitbox_offset_y,
            float hitbox_width, float hitbox_height, sf::Texture& texture_sheet);
    virtual ~Enemy();

    //funtions
    void updateAnimation(const float &dt);
    virtual void update(const float &dt);
    void render(sf::RenderTarget& target, const bool show_hitbox = false);

    int takeDamage(int dmg);    //RETURN DMG reduced by Enemy ARMOR

    string enemyDetails();

    string getName();
    void setName(string name);
    string getType();
    void setType(string type);
    int getLevel();
    void setLevel(int level);
    int getHp();
    void setHp(int hp);
    int getMaxHp();
    void setMaxHp(int maxHp);
    int getArmor();
    void setArmor(int armor);
    int getDamage();
    void setDamage(int damage);
    int getCritChance();
    void setCritChance(int critChance);
    int getEvadeChance();
    void setEvadeChance(int evadeChance);

    Enemy();

    Enemy(string name, string type, int level, int hp, int maxHp, int armor, int damage, int critChance,
    int evadeChance);

};


#endif //DRAGONSLAYER_ENEMY_H
