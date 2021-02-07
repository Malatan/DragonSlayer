//
// Created by Zheng on 08/10/2020.
//

#ifndef DRAGONSLAYER_ENEMY_H
#define DRAGONSLAYER_ENEMY_H
#include <string>
#include <sstream>
#include "Stats.h"
#include "Entity.h"
#include "Utils.h"
#include "Player.h"
#include "../AI/AIBehaviour.h"

class AIBehaviour;

enum enemy_types : unsigned int{
    WITCH,
    SKELETON,
    SKELETON_2,
    FLYING_EYE,
    GOBLIN,
    MUSHROOM,
    BANDIT_HEAVY,
    BANDIT_LIGHT,
    DRAGON
};


class Enemy : public Entity{
public:
    //CONSTRUCTOR & DESTRUCTOR
    Enemy(enemy_types type, float x, float y,float scale_x ,float scale_y, float hitbox_offset_x, float hitbox_offset_y,
            float hitbox_width, float hitbox_height, float clsBox_offset_x, float clsBox_offset_y, float clsBox_radius,
            sf::Texture& texture_sheet, State* gameState);
    Enemy(enemy_types type, float x, float y,float scale_x ,float scale_y, float hitbox_offset_x, float hitbox_offset_y,
          float hitbox_width, float hitbox_height, float clsBox_offset_x, float clsBox_offset_y, float clsBox_radius,
          sf::Texture& texture_sheet);
    Enemy(enemy_types type, int level, int floor, unsigned int id);
    Enemy(enemy_types type, std::string name, unsigned int id, const Stats& _stats);
    ~Enemy() override;

    //variables
    static const unsigned int MAX_FOLLOWERS = 4;
    static const int BASE_BOOST = 15;


    //functions
    void updateStatsBoost(bool recover);
    void generateNameByType();
    void generateEnemyStats(int floor, int level = 0);
    void updateAnimation(const float &dt);
    void update(const float &dt) override;
    void render(sf::RenderTarget& target, sf::Shader* shader = nullptr, sf::Vector2f light_position = sf::Vector2f());

    //getters/setters
    bool canBeRendered(float distance, sf::Vector2f from);
    const vector<std::shared_ptr<Enemy>> &getFollowers() const;
    bool isDead() const;
    void addFollower(const std::shared_ptr<Enemy>& new_follower);
    int getFollowersNumber() const;
    int getAliveFollowersNumber() const;
    int getDeadFollowersNumber() const;
    void setPosition(float x, float y) override;
    void setId(unsigned int new_id);
    unsigned int getId() const;
    enemy_types getType() const;
    std::string getName() const;
    std::string toString();
    void setAnimation(entity_animation animation, entity_animation next_animation);
    void setStats(std::shared_ptr<Stats> new_stats);
    const std::shared_ptr<Stats> &getStats() const;
    int getCurrentBoost() const;
    void setStats(const Stats& _stats);
    void setCurrentBoost(int current_boost);
    std::string getAIStatoString() const;
    std::string toStringDebug() const;
    const sf::Vector2f &getSpawnPos() const;
    int generatePotions();
    int getCd() const;
    void setCd(int cd);
    void updateCd();

private:
    //variables
    bool leftRightReverse{};
    unsigned int Id{};
    string name;
    enemy_types type{};
    int currentBoost{};
    sf::Vector2f spawnPos;
    bool animationDone{};
    entity_animation animationEnum{};
    entity_animation nextAnimationEnum{};
    std::vector<std::shared_ptr<Enemy>> followers;
    std::shared_ptr<Stats> stats;
    std::shared_ptr<Player> player;
    AIBehaviour* aIBehaviour{};
    int cd = 0;

    //initializer functions
    void initAnimations();
};

#endif //DRAGONSLAYER_ENEMY_H
