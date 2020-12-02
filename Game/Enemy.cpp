//
// Created by Zheng on 08/10/2020.
//

#include "Enemy.h"

//initializer functions
void Enemy::initAnimations() {
    switch(type){
        case WITCH:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 2, 7, 2, 250 ,250);
            animationComponent->addAnimation("ATTACK", 10.f,
                    0, 0, 7, 0, 250 ,250);
            animationComponent->addAnimation("ATTACK2", 10.f,
                    0, 1, 7, 1, 250 ,250);
            animationComponent->addAnimation("WALK", 10.f,
                    0, 3, 7, 3, 250 ,250);
            animationComponent->addAnimation("GETHIT", 20.f,
                    0, 4, 2, 4, 250 ,250);
            animationComponent->addAnimation("DEATH", 10.f,
                    0, 5, 6, 5, 250 ,250);
            animationComponent->addAnimation("CORPSE", 10.f,
                    6, 5, 6, 5, 250 ,250);
            break;
        case SKELETON:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 2, 10, 2, 100 ,100);
            animationComponent->addAnimation("ATTACK", 10.f,
                    0, 0, 10, 0, 100 ,100);
            animationComponent->addAnimation("WALK", 10.f,
                    0, 1, 8, 1, 100 ,100);
            animationComponent->addAnimation("GETHIT", 10.f,
                    0, 3, 7, 3, 100 ,100);
            animationComponent->addAnimation("DEATH", 10.f,
                    0, 4, 10, 4, 100 ,100);
            animationComponent->addAnimation("CORPSE", 10.f,
                    10, 4, 10, 4, 100 ,100);
            break;
        case SKELETON_2:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 2, 3, 2, 150 ,150);
            animationComponent->addAnimation("ATTACK", 10.f,
                    0, 0, 7, 0, 150 ,150);
            animationComponent->addAnimation("SHIELD", 10.f,
                    0, 4, 3, 4, 150 ,150);
            animationComponent->addAnimation("WALK", 10.f,
                    0, 1, 3, 1, 150 ,150);
            animationComponent->addAnimation("GETHIT", 10.f,
                    0, 3, 3, 3, 150 ,150);
            animationComponent->addAnimation("DEATH", 10.f,
                    0, 5, 3, 5, 150 ,150);
            animationComponent->addAnimation("CORPSE", 10.f,
                    3, 5, 3, 5, 150 ,150);
            break;
        case FLYING_EYE:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 0, 7, 0, 150 ,150);
            animationComponent->addAnimation("ATTACK", 10.f,
                    0, 1, 7, 1, 150 ,150);
            animationComponent->addAnimation("WALK", 10.f,
                    0, 0, 7, 0, 150 ,150);
            animationComponent->addAnimation("GETHIT", 10.f,
                    0, 2, 3, 2, 150 ,150);
            animationComponent->addAnimation("DEATH", 10.f,
                    0, 3, 3, 3, 150 ,150);
            animationComponent->addAnimation("CORPSE", 10.f,
                    3, 3, 3, 3, 150 ,150);
            break;
        case GOBLIN:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 2, 3, 2, 150 ,150);
            animationComponent->addAnimation("ATTACK", 10.f,
                    0, 1, 7, 1, 150 ,150);
            animationComponent->addAnimation("WALK", 10.f,
                    0, 0, 7, 0, 150 ,150);
            animationComponent->addAnimation("GETHIT", 10.f,
                    0, 3, 3, 3, 150 ,150);
            animationComponent->addAnimation("DEATH", 10.f,
                    0, 4, 3, 4, 150 ,150);
            animationComponent->addAnimation("CORPSE", 10.f,
                    3, 4, 3, 4, 150 ,150);
            break;
        case MUSHROOM:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 2, 3, 2, 150 ,150);
            animationComponent->addAnimation("ATTACK", 10.f,
                    0, 1, 7, 1, 150 ,150);
            animationComponent->addAnimation("WALK", 10.f,
                    0, 0, 7, 0, 150 ,150);
            animationComponent->addAnimation("GETHIT", 10.f,
                    0, 3, 3, 3, 150 ,150);
            animationComponent->addAnimation("DEATH", 10.f,
                    0, 4, 3, 4, 150 ,150);
            animationComponent->addAnimation("CORPSE", 10.f,
                    3, 4, 3, 4, 150 ,150);
            break;
        case BANDIT_HEAVY:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 0, 3, 0, 48 ,48);
            animationComponent->addAnimation("ATTACK", 10.f,
                    3, 2, 7, 2, 48 ,48);
            animationComponent->addAnimation("WALK", 10.f,
                    0, 1, 7, 1, 48 ,48);
            animationComponent->addAnimation("GETHIT", 15.f,
                    0, 4, 2, 4, 48 ,48);
            animationComponent->addAnimation("DEATH", 10.f,
                    1, 4, 4, 4, 48 ,48);
            animationComponent->addAnimation("CORPSE", 10.f,
                    4, 4, 4, 4, 48 ,48);
            break;
        case BANDIT_LIGHT:
            animationComponent->addAnimation("IDLE", 10.f,
                    0, 0, 3, 0, 48 ,48);
            animationComponent->addAnimation("ATTACK", 10.f,
                    3, 2, 7, 2, 48 ,48);
            animationComponent->addAnimation("WALK", 10.f,
                    0, 1, 7, 1, 48 ,48);
            animationComponent->addAnimation("GETHIT", 15.f,
                    0, 4, 2, 4, 48 ,48);
            animationComponent->addAnimation("DEATH", 10.f,
                    1, 4, 4, 4, 48 ,48);
            animationComponent->addAnimation("CORPSE", 10.f,
                    4, 4, 4, 4, 48 ,48);
            break;
    }

}

//constructors/destructors
Enemy::Enemy(enemy_types type, float x, float y, float scale_x ,float scale_y, float hitbox_offset_x, float hitbox_offset_y,
             float hitbox_width, float hitbox_height, float clsBox_offset_x, float clsBox_offset_y, float clsBox_radius,
             sf::Texture& texture_sheet, int floor, unsigned int id) : type(type), Id(id){
    scale.x = scale_x;
    scale.y = scale_y;
    sprite.setScale(scale);
    animationEnum = IDLE_ANIMATION;
    nextAnimationEnum = IDLE_ANIMATION;
    animationDone = false;

    createAnimationComponent(texture_sheet);
    createHitboxComponent(sprite, hitbox_offset_x, hitbox_offset_y, hitbox_width, hitbox_height);
    createCollisionBoxComponent(sprite, clsBox_offset_x, clsBox_offset_y, clsBox_radius);
    initAnimations();

    Enemy::setPosition(x, y);
    stats = std::make_shared<Stats>();
    //floor 1 = 1-10, 2 = 11-20, 3 = 21-30, 4 = 31-40, 5 = 41-50
    int level = utils::generateRandomNumber((floor-1)*10+1, floor*10, false);
    stats->setLevel(level);
    generateEnemyStats(level, floor);
    generateNameByType();
}

Enemy::Enemy(enemy_types type, int level, int floor, unsigned int id) : type(type), Id(id){
    scale.x = 1.f;
    scale.y = 1.f;
    stats = std::make_shared<Stats>();
    stats->setLevel(level);
    generateNameByType();
    generateEnemyStats(level, floor);
}

Enemy::~Enemy() = default;

//functions
void Enemy::generateNameByType() {
    switch(type){
        case WITCH:
            name = "Witch";
            break;
        case SKELETON:
            name = "Skeleton";
            break;
        case SKELETON_2:
            name = "Skeleton Soldier";
            break;
        case FLYING_EYE:
            name = "Flying eye";
            break;
        case GOBLIN:
            name = "Goblin";
            break;
        case MUSHROOM:
            name = "Mushroom";
            break;
        case BANDIT_HEAVY:
            name = "Bandit Leader";
            break;
        case BANDIT_LIGHT:
            name = "Bandit Minion";
            break;
        default:
            std::cout<<"No such enemy: " << type;
            break;
    }
}

void Enemy::generateEnemyStats(int level, int floor) {
    // genera un modificatore di mod tra -0.5f e 1.f
    float modModifier = (float)utils::generateRandomNumber(-50, 100, false)/100.f;
    float mod = ((float)level/10.f) + (float)floor + modModifier;
    switch(type){
        case WITCH:
            stats->setLevel(level);
            stats->setAgility((int)(2 * mod));
            stats->setWisdom((int)(4 * mod));
            stats->setStrength((int)(2 * mod));
            stats->setMaxHp(100 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setMaxMp(200 * (int)(mod + ((float)stats->getWisdom()/10.f)));
            stats->setArmor(15 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setDamage(25 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setCritChance(10.f + mod + ((float)stats->getAgility()/10.f));
            stats->setEvadeChance(3.8f + mod + ((float)stats->getAgility()/10.f));
            stats->refillHp();
            stats->refillMp();
            break;
        case SKELETON:
            stats->setLevel(level);
            stats->setAgility((int)(3 * mod));
            stats->setWisdom((int)(2 * mod));
            stats->setStrength((int)(3 * mod));
            stats->setMaxHp(130 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setMaxMp(200 * (int)(mod + ((float)stats->getWisdom()/10.f)));
            stats->setArmor(15 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setDamage(20 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setCritChance(12.f + mod + ((float)stats->getAgility()/10.f));
            stats->setEvadeChance(3.4f + mod + ((float)stats->getAgility()/10.f));
            stats->refillHp();
            stats->refillMp();
            break;
        case SKELETON_2:
            stats->setLevel(level);
            stats->setAgility((int)(3 * mod));
            stats->setWisdom((int)(2 * mod));
            stats->setStrength((int)(3 * mod));
            stats->setMaxHp(150 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setMaxMp(100 * (int)(mod + ((float)stats->getWisdom()/10.f)));
            stats->setArmor(20 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setDamage(28 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setCritChance(13.f + mod + ((float)stats->getAgility()/10.f));
            stats->setEvadeChance(2.f + mod + ((float)stats->getAgility()/10.f));
            stats->refillHp();
            stats->refillMp();
            break;
        case FLYING_EYE:
            stats->setLevel(level);
            stats->setAgility((int)(4 * mod));
            stats->setWisdom((int)(2 * mod));
            stats->setStrength((int)(2 * mod));
            stats->setMaxHp(100 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setMaxMp(100 * (int)(mod + ((float)stats->getWisdom()/10.f)));
            stats->setArmor(10 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setDamage(20 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setCritChance(10.f + mod + ((float)stats->getAgility()/10.f));
            stats->setEvadeChance(5.8f + mod + ((float)stats->getAgility()/10.f));
            stats->refillHp();
            stats->refillMp();
            break;
        case GOBLIN:
            stats->setLevel(level);
            stats->setAgility((int)(3 * mod));
            stats->setWisdom((int)(2 * mod));
            stats->setStrength((int)(3 * mod));
            stats->setMaxHp(140 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setMaxMp(100 * (int)(mod + ((float)stats->getWisdom()/10.f)));
            stats->setArmor(18 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setDamage(22 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setCritChance(14.f + mod + ((float)stats->getAgility()/10.f));
            stats->setEvadeChance(2.f + mod + ((float)stats->getAgility()/10.f));
            stats->refillHp();
            stats->refillMp();
            break;
        case MUSHROOM:
            stats->setLevel(level);
            stats->setAgility((int)(3 * mod));
            stats->setWisdom((int)(3 * mod));
            stats->setStrength((int)(2 * mod));
            stats->setMaxHp(130 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setMaxMp(120 * (int)(mod + ((float)stats->getWisdom()/10.f)));
            stats->setArmor(12 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setDamage(20 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setCritChance(16.f + mod + ((float)stats->getAgility()/10.f));
            stats->setEvadeChance(2.f + mod + ((float)stats->getAgility()/10.f));
            stats->refillHp();
            stats->refillMp();
            break;
        case BANDIT_HEAVY:
            stats->setLevel(level);
            stats->setAgility((int)(4 * mod));
            stats->setWisdom((int)(4 * mod));
            stats->setStrength((int)(4 * mod));
            stats->setMaxHp(200 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setMaxMp(180 * (int)(mod + ((float)stats->getWisdom()/10.f)));
            stats->setArmor(25 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setDamage(35 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setCritChance(18.f + mod + ((float)stats->getAgility()/10.f));
            stats->setEvadeChance(3.8f + mod + ((float)stats->getAgility()/10.f));
            stats->refillHp();
            stats->refillMp();
            break;
        case BANDIT_LIGHT:
            stats->setLevel(level);
            stats->setAgility((int)(3 * mod));
            stats->setWisdom((int)(2 * mod));
            stats->setStrength((int)(3 * mod));
            stats->setMaxHp(160 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setMaxMp(100 * (int)(mod + ((float)stats->getWisdom()/10.f)));
            stats->setArmor(20 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setDamage(27 * (int)(mod + ((float)stats->getStrength()/10.f)));
            stats->setCritChance(15.f + mod + ((float)stats->getAgility()/10.f));
            stats->setEvadeChance(3.8f + mod + ((float)stats->getAgility()/10.f));
            stats->refillHp();
            stats->refillMp();
            break;
        default:
            std::cout<<"No such enemy: " << type;
            break;
    }
}

void Enemy::updateAnimation(const float &dt) {
    switch(animationEnum){
        case IDLE_ANIMATION:
            animationDone = animationComponent->play("IDLE", dt);
            break;
        case ATTACK_ANIMATION:
            animationDone = animationComponent->play("ATTACK", dt);
            break;
        case ATTACK2_ANIMATION:
            animationDone = animationComponent->play("ATTACK2", dt);
            break;
        case SHIELD_ANIMATION:
            animationDone = animationComponent->play("SHIELD", dt);
            break;
        case WALK_ANIMATION:
            animationDone = animationComponent->play("WALK", dt);
            break;
        case GETHIT_ANIMATION:
            animationDone = animationComponent->play("GETHIT", dt);
            break;
        case DEATH_ANIMATION:
            animationDone = animationComponent->play("DEATH", dt);
            break;
        case CORPSE_ANIMATION:
            animationDone = animationComponent->play("CORPSE", dt);
            break;
    }
    if(animationDone)
        animationEnum = nextAnimationEnum;
}

void Enemy::update(const float &dt) {
    updateAnimation(dt);
    hitboxComponent->update();
    collisionBoxComponent->update();
}

void Enemy::render(sf::RenderTarget &target, bool show_hitbox, bool show_clsBox) {
    if(show_clsBox)
        collisionBoxComponent->render(target);
    target.draw(sprite);
    if(show_hitbox)
        hitboxComponent->render(target);
}

//getters/setters
enemy_types Enemy::getType() const{
    return type;
}

std::string Enemy::toString() {
    stringstream ss;
    ss << " -----------------Enemy Info----------------- " << std::endl;
    switch(type){
        case WITCH:
            ss << "Enemy type: WITCH" << std::endl;
            break;
        case SKELETON:
            ss << "Enemy type: SKELETON" << std::endl;
            break;
        case SKELETON_2:
            ss << "Enemy type: SKELETON_2" << std::endl;
            break;
        case FLYING_EYE:
            ss << "Enemy type: FLYING_EYE" << std::endl;
            break;
        case GOBLIN:
            ss << "Enemy type: GOBLIN" << std::endl;
            break;
        case MUSHROOM:
            ss << "Enemy type: MUSHROOM" << std::endl;
            break;
        case BANDIT_HEAVY:
            ss << "Enemy type: BANDIT_HEAVY" << std::endl;
            break;
        case BANDIT_LIGHT:
            ss << "Enemy type: BANDIT_LIGHT" << std::endl;
            break;
    }
    ss << "id: " << Id << std::endl;
    ss << "Name: " << name << std::endl;
    ss << "Level: " << stats->getLevel() << std::endl;
    ss << "Hp/Max hp: " << stats->getHp() << "/" << stats->getFinalHp() << std::endl;
    ss << "Mp/Max mp: " << stats->getMp() << "/" << stats->getFinalMp() << std::endl;
    ss << "Damage: " << stats->getFinalDamage() << std::endl;
    ss << "Armor: " << stats->getFinalArmor() << std::endl;
    ss << "Crit chance: " << stats->getFinalCritChance() << " %" << std::endl;
    ss << "Evade chance: " << stats->getFinalEvadeChance() << " %" << std::endl;
    ss << "Agility: " << stats->getAgility() << std::endl;
    ss << "Wisdom: " << stats->getWisdom() << std::endl;
    ss << "Strength: " << stats->getStrength() << std::endl;
    ss << "Followers: " << followers.size() << std::endl;
    if(!followers.empty()){
        ss << "----------------Followers----------------" << std::endl;
        for(const auto& i : followers){
            ss << i->toString() << std::endl;
        }
        ss << "----------------END Followers END----------------" << std::endl;
    }
    ss << " -----------------END Enemy Info END----------------- " << std::endl;
    return ss.str();
}

std::string Enemy::getName() const {
    return name;
}

void Enemy::setAnimation(entity_animation animation, entity_animation next_animation) {
    animationEnum = animation;
    nextAnimationEnum = next_animation;
}

const vector<std::shared_ptr<Enemy>> &Enemy::getFollowers() const {
    return followers;
}

void Enemy::addFollower(const std::shared_ptr<Enemy>& new_follower) {
    if(followers.size() < 4){
        followers.push_back(new_follower);
    }
}

int Enemy::getFollowersNumber() {
    return followers.size();
}

bool Enemy::isDead() const {
    return stats->getHp() == 0;
}

const std::shared_ptr<Stats> &Enemy::getStats() const {
    return stats;
}

void Enemy::setStats(std::shared_ptr<Stats> new_stats) {
    stats = std::move(new_stats);
}

void Enemy::setId(unsigned int new_id) {
    Id = new_id;
}

unsigned int Enemy::getId() const {
    return Id;
}

void Enemy::setPosition(float x, float y) {
    if(hitboxComponent)
        hitboxComponent->setPosition(x, y);
    else
        sprite.setPosition(x, y);
}









