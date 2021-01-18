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
             sf::Texture& texture_sheet, State* gameState) : type(type){
    scale.x = scale_x;
    scale.y = scale_y;
    sprite.setScale(scale);
    animationEnum = IDLE_ANIMATION;
    nextAnimationEnum = IDLE_ANIMATION;
    animationDone = false;
    currentBoost = 0;
    createAnimationComponent(texture_sheet);
    createHitboxComponent(sprite, hitbox_offset_x, hitbox_offset_y, hitbox_width, hitbox_height);
    createCollisionBoxComponent(sprite, clsBox_offset_x, clsBox_offset_y, clsBox_radius);
    createMovementComponent(200.f, 14.f, 7.f);
    initAnimations();
    Enemy::setPosition(x, y);
    generateNameByType();
    wayPoints.emplace_back(sf::Vertex(sf::Vector2f(x, y)));
    spawnPos = {x,y};
    auto i = dynamic_cast<GameState*>(gameState);
    player = i->getPlayer();
    aIBehaviour = new AIBehaviour(i->getPathFinder(), *this, *i->getPlayer(), spawnPos);

}

Enemy::Enemy(enemy_types type, int level, int floor, unsigned int id) : type(type), Id(id){
    scale.x = 1.f;
    scale.y = 1.f;
    currentBoost = 0;
    generateNameByType();
    generateEnemyStats(floor, level);
}

Enemy::Enemy(enemy_types type, std::string  name, unsigned int id, const Stats &_stats)
        : type(type), name(std::move(name)), Id(id) {
    scale.x = 1.f;
    scale.y = 1.f;
    currentBoost = 0;
    stats = std::make_shared<Stats>(_stats);
}

Enemy::~Enemy(){

    delete aIBehaviour;
}

//functions
bool Enemy::canBeRendered(float distance, sf::Vector2f from) {
    sf::Vector2f v_diff = {getPosition().x - from.x, getPosition().y - from.y};
    auto vec_length = (float)sqrt(pow(v_diff.x, 2) + pow(v_diff.y, 2));
    return vec_length <= distance;
}

void Enemy::updateStatsBoost(bool recover) {
    int alive_followers = getAliveFollowersNumber();
    if(!followers.empty() && alive_followers != currentBoost){
        float new_boost_mod = ((float)alive_followers * (float)BASE_BOOST)/100.f;
        new_boost_mod += 1.f;

        float old_boost_mod = ((float)currentBoost * (float)BASE_BOOST)/100.f;
        old_boost_mod += 1.f;

        if(currentBoost != alive_followers){
            stats->setMaxHpBonus(stats->getMaxHpBonus() - (int)((float)stats->getMaxHp() * old_boost_mod));
            stats->setMaxMpBonus(stats->getMaxMpBonus() - (int)((float)stats->getMaxMp() * old_boost_mod));
            stats->setDamageBonus(stats->getDamageBonus() - (int)((float)stats->getDamage() * old_boost_mod));
            stats->setArmorBonus(stats->getArmorBonus() - (int)((float)stats->getArmor() * old_boost_mod));
            stats->setCritChanceBonus(stats->getCritChanceBonus() -
                                      utils::roundf(stats->getCritChance() * old_boost_mod, 2));
            stats->setEvadeChanceBonus(stats->getEvadeChanceBonus() -
                                       utils::roundf(stats->getEvadeChance() * old_boost_mod, 2));
        }
        stats->setMaxHpBonus(stats->getMaxHpBonus() + (int)((float)stats->getMaxHp() * new_boost_mod));
        stats->setMaxMpBonus(stats->getMaxMpBonus() + (int)((float)stats->getMaxMp() * new_boost_mod));
        stats->setDamageBonus(stats->getDamageBonus() + (int)((float)stats->getDamage() * new_boost_mod));
        stats->setArmorBonus(stats->getArmorBonus() + (int)((float)stats->getArmor() * new_boost_mod));
        stats->setCritChanceBonus(stats->getCritChanceBonus() +
                                  utils::roundf(stats->getCritChance() * new_boost_mod, 2));
        stats->setEvadeChanceBonus(stats->getEvadeChanceBonus() +
                                   utils::roundf(stats->getEvadeChance() * new_boost_mod, 2));
        stats->checkHpLimit();
        stats->checkMpLimit();
        currentBoost = alive_followers;
        if(recover){
            stats->refillHp();
            stats->refillMp();
        }
    }
}

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

void Enemy::generateEnemyStats(int floor, int level) {
    if(floor <= 0 ){
        floor = 5;
    }
    if(level == 0){
        level = utils::generateRandomNumber((floor-1)*10+1, floor*10);
    }
    stats = std::make_shared<Stats>();
    float modModifier = (float)utils::generateRandomNumber(-50, 100)/100.f;
    float mod = ((float)level/10.f) + (float)floor + modModifier;
    switch(type){
        case WITCH:
            stats->setLevel(level);
            stats->setAgility((int)(2 * mod));
            stats->setWisdom((int)(4 * mod));
            stats->setStrength((int)(2 * mod));
            stats->setMaxHp(140 * (int)(mod + ((float)stats->getStrength()/10.f)));
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
            stats->setMaxHp(120 * (int)(mod + ((float)stats->getStrength()/10.f)));
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
    if(movementComponent->getState(IDLE)) {
        switch (animationEnum) {
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
            default:
                break;
        }
        if (animationDone)
            animationEnum = nextAnimationEnum;
    } else if(movementComponent->getState(MOVING_LEFT)){
         sprite.setOrigin(animationComponent->getWalkWidth(), 0.f);
         sprite.setScale(-scale.x, scale.y);
         animationComponent->play("WALK", dt);
    } else if(movementComponent->getState(MOVING_RIGHT)){
          sprite.setOrigin(0.f, 0.f);
          sprite.setScale(scale.x, scale.y);
        animationComponent->play("WALK", dt);
    } else if(movementComponent->getState(MOVING_UP) || movementComponent->getState(MOVING_DOWN)){
         animationComponent->play("WALK", dt);
    }
}

void Enemy::update(const float &dt) {
    updateAnimation(dt);
    hitboxComponent->update();
    collisionBoxComponent->update();
    if(aIBehaviour != nullptr) {
        updateWaypoint(dt);
        aIBehaviour->update(dt);
    }
    movementComponent->update(dt);

}

void Enemy::render(sf::RenderTarget &target, sf::Shader* shader, sf::Vector2f light_position, bool show_hitbox, bool show_clsBox) {
    if(show_clsBox)
        collisionBoxComponent->render(target);
    if(shader){
        shader->setUniform("hasTexture", true);
        shader->setUniform("lightPos", light_position);
        target.draw(sprite, shader);
    }
    else{
        target.draw(sprite);
    }
    if(show_hitbox)
        hitboxComponent->render(target);

    target.draw(&wayPoints[0], wayPoints.size(), sf::LineStrip);
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

int Enemy::getFollowersNumber() const{
    return followers.size();
}

int Enemy::getAliveFollowersNumber() const{
    int count = 0;
    for(const auto& i : followers){
        if(!i->isDead())
            count++;
    }
    return count;
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

void Enemy::setStats(const Stats &_stats) {
    stats = std::make_shared<Stats>(_stats);
}

void Enemy::setPosition(float x, float y) {
    if(hitboxComponent)
        hitboxComponent->setPosition(x, y);
    else
        sprite.setPosition(x, y);
}

int Enemy::getDeadFollowersNumber() const{
    int count = 0;
    for(const auto& i : followers){
        if(i->isDead())
            count++;
    }
    return count;
}

int Enemy::getCurrentBoost() const {
    return currentBoost;
}

void Enemy::setCurrentBoost(int current_boost) {
    currentBoost = current_boost;
}

Enemy::Enemy(enemy_types type, float x, float y, float scale_x, float scale_y, float hitbox_offset_x,
             float hitbox_offset_y, float hitbox_width, float hitbox_height, float clsBox_offset_x,
             float clsBox_offset_y, float clsBox_radius, sf::Texture &texture_sheet): type(type) {
    scale.x = scale_x;
    scale.y = scale_y;
    sprite.setScale(scale);
    animationEnum = IDLE_ANIMATION;
    nextAnimationEnum = IDLE_ANIMATION;
    animationDone = false;
    currentBoost = 0;
    createAnimationComponent(texture_sheet);
    createHitboxComponent(sprite, hitbox_offset_x, hitbox_offset_y, hitbox_width, hitbox_height);
    createCollisionBoxComponent(sprite, clsBox_offset_x, clsBox_offset_y, clsBox_radius);
    createMovementComponent(100.f, 14.f, 7.f);
    initAnimations();
    Enemy::setPosition(x, y);
    generateNameByType();
    wayPoints.emplace_back(sf::Vertex(sf::Vector2f(x, y)));
}

const sf::Vector2f &Enemy::getSpawnPos() const {
    return spawnPos;
}











