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
#include "Utils.h"

enum enemy_types{
    WITCH,
    SKELETON,
    SKELETON_2,
    FLYING_EYE,
    GOBLIN,
    MUSHROOM,
    BANDIT_HEAVY,
    BANDIT_LIGHT
};

class Enemy : public Entity{
public:
    //CONSTRUCTOR & DESTRUCTOR
    Enemy(enemy_types type, float x, float y,float scale_x ,float scale_y, float hitbox_offset_x, float hitbox_offset_y,
            float hitbox_width, float hitbox_height, float clsBox_offset_x, float clsBox_offset_y, float clsBox_radius,
            sf::Texture& texture_sheet, int floor = 0);
    virtual ~Enemy();

    //functions
    bool isDead() const;
    void generateNameByType();
    void copyStats(std::shared_ptr<Enemy> enemy);
    int getHit(int hit_damage, bool spell_damage);
    void generateEnemyStats(int floor);
    void updateAnimation(const float &dt);
    void update(const float &dt) override;
    void render(sf::RenderTarget& target, bool show_hitbox = false, bool show_clsBox = false);

    //getters/setters
    enemy_types getType() const;
    std::string getName() const;
    int getLevel() const;
    int getAgility() const;
    int getWisdom() const;
    int getStrength() const;
    int getHp() const;
    void setHp(int new_hp);
    int getMp() const;
    void setMp(int new_mp);
    int getMaxHp() const;
    int getMaxMp() const;
    int getArmor() const;
    int getDamage() const;
    float getCritChance() const;
    float getEvadeChance() const;
    std::string toString();
    void setAnimation(entity_animation animation);
    void setAnimation(entity_animation animation, entity_animation next_animation);
    void setNextAnimation(entity_animation next_animation);
    void setDefense(bool b);
    bool isDefense() const;
private:
    //variables
    string name;
    enemy_types type;

    int level;
    int hp;
    int maxHp;
    int mp;
    int maxMp;
    int armor;
    int damage;
    float critChance;
    float evadeChance;
    int agility;
    int wisdom;
    int strength;

    bool defense;
    bool animationDone;
    entity_animation animationEnum;
    entity_animation nextAnimationEnum;
    //initializer functions
    void initAnimations();
};


#endif //DRAGONSLAYER_ENEMY_H
