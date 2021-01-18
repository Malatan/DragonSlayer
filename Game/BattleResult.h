//
// Created by Administrator on 03/12/2020.
//

#ifndef DRAGONSLAYER_BATTLERESULT_H
#define DRAGONSLAYER_BATTLERESULT_H

#include <iostream>
#include <memory>
#include "Enemy.h"
#include "../Components/AchievementsEnum.h"

class Enemy;

typedef std::pair<achievement_event, int> achievementPair;

enum battle_result_types : unsigned int{
    WIN,
    LOST,
    ESCAPED,
    NOT_FINISHED,
    QUIT_GAME
};

enum statistic_types{
    DAMAGE_DEALT_COUNT,
    SPELL_DAMAGE_DEALT_COUNT,
    DAMAGE_TAKEN_COUNT,
    DAMAGE_REDUCED_COUNT,
    POTION_USED_COUNT,
    DODGE_COUNT,
    MISS_COUNT,
    CRITICAL_HIT_COUNT,
    ESCAPE_FAIL_COUNT,
    ESCAPE_SUCCESS_COUNT
};

class BattleResult {
public:
    BattleResult();
    virtual ~BattleResult();

    //functions
    void addStatistics(statistic_types statistic, int value);
    std::string generateReport() const;
    void updateBattleResult(battle_result_types b_result, bool player_killed, const std::shared_ptr<Enemy>& enemy_leader);
    std::vector<achievementPair> getAchievementDataSet();

    //getters setters
    void setExpGainCount(int value);
    int getExpGainCount() const;
    void setGoldGainCount(int value);
    int getGoldGainCount() const;
    battle_result_types getResultType();
    unsigned int getEnemyLeaderId() const;

private:
    battle_result_types battleResult{};
    unsigned int enemyLeaderId{};
    bool playerKilled{};
    bool enemyLeaderKilled{};
    int enemyDeadFollowersCount{};
    int enemyFollowersCount{};
    int expGainCount{};
    int goldGainCount{};

    //statiscs
    int damageDealtCount{};
    int spellDamageDealtCount{};
    int damageTakenCount{};
    int damageReducedCount{};
    int potionUsedCount{};
    int dodgeCount{};
    int missCount{};
    int criticalHitCount{};
    int escapeFailCount{};
    int escapeSuccessCount{};
};


#endif //DRAGONSLAYER_BATTLERESULT_H
