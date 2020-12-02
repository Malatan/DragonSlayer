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
            sf::Texture& texture_sheet, int floor, unsigned int id);
    Enemy(enemy_types type, int level, int floor, unsigned int id);
    ~Enemy() override;

    //variables
    static const unsigned int MAX_FOLLOWERS = 4;

    //follwers
    void addFollower(const std::shared_ptr<Enemy>& new_follower);
    int getFollowersNumber();
    const vector<std::shared_ptr<Enemy>> &getFollowers() const;

    //functions
    void setPosition(float x, float y) override;
    bool isDead() const;
    void generateNameByType();
    void generateEnemyStats(int level, int floor);
    void updateAnimation(const float &dt);
    void update(const float &dt) override;
    void render(sf::RenderTarget& target, bool show_hitbox = false, bool show_clsBox = false);

    //getters/setters
    void setId(unsigned int new_id);
    unsigned int getId() const;
    enemy_types getType() const;
    std::string getName() const;
    std::string toString();
    void setAnimation(entity_animation animation, entity_animation next_animation);
    void setStats(std::shared_ptr<Stats> new_stats);
    const std::shared_ptr<Stats> &getStats() const;

private:
    //variables
    unsigned int Id;
    string name;
    enemy_types type;

    bool animationDone{};
    entity_animation animationEnum{};
    entity_animation nextAnimationEnum{};

    std::vector<std::shared_ptr<Enemy>> followers;
    std::shared_ptr<Stats> stats;

    //initializer functions
    void initAnimations();
};

#endif //DRAGONSLAYER_ENEMY_H
