//
// Created by Administrator on 03/12/2020.
//

#include "BattleResult.h"

BattleResult::BattleResult() = default;

BattleResult::~BattleResult() = default;

void BattleResult::updateBattleResult(battle_result_types b_result, bool player_killed,
                                      const shared_ptr<Enemy> &enemy_leader) {
    battleResult = b_result;
    playerKilled = player_killed;
    enemyLeaderId = enemy_leader->getId();
    enemyLeaderKilled = enemy_leader->isDead();
    enemyDeadFollowersCount = enemy_leader->getDeadFollowersNumber();
    enemyFollowersCount = enemy_leader->getAliveFollowersNumber() + enemyDeadFollowersCount;
}

void BattleResult::addStatistics(statistic_types statistic, int value) {
    switch (statistic) {
        case DAMAGE_DEALT_COUNT:
            damageDealtCount += value;
            break;
        case SPELL_DAMAGE_DEALT_COUNT:
            spellDamageDealtCount += value;
            break;
        case DAMAGE_TAKEN_COUNT:
            damageTakenCount += value;
            break;
        case POTION_USED_COUNT:
            potionUsedCount += value;
            break;
        case DODGE_COUNT:
            dodgeCount += value;
            break;
        case MISS_COUNT:
            missCount += value;
            break;
        case CRITICAL_HIT_COUNT:
            criticalHitCount += value;
            break;
        case ESCAPE_FAIL_COUNT:
            escapeFailCount += value;
            break;
        case ESCAPE_SUCCESS_COUNT:
            escapeSuccessCount += value;
            break;
        case DAMAGE_REDUCED_COUNT:
            damageReducedCount += value;
            break;
    }
}

std::string BattleResult::generateReport() const {
    stringstream ss;
    ss << "--------------------Battle Report--------------------" << std::endl << "Battle result: ";
    switch(battleResult){
        case WIN:
            ss << "Won" << std::endl;
            break;
        case LOST:
            ss << "Lost" << std::endl;
            break;
        case ESCAPED:
            ss << "Escaped" << std::endl;
            break;
        case NOT_FINISHED:
        case QUIT_GAME:
            break;
    }
    ss << "Player killed: " << std::boolalpha << playerKilled << std::endl
       << "Enemy leader id: " << enemyLeaderId << std::endl
       << "Enemy leader killed: " << std::boolalpha << enemyLeaderKilled << std::endl
       << "Enemy followers count: " << enemyFollowersCount << std::endl
       << "Enemy followers killed: " << enemyDeadFollowersCount;
    if(enemyLeaderKilled)
        ss << "+1";
    ss << endl
       << "Damage dealt: " << damageDealtCount << std::endl
       << "Spell damage dealt: " << spellDamageDealtCount << std::endl
       << "Damage taken: " << damageTakenCount << std::endl
       << "Damage reduced: " << damageReducedCount << std::endl
       << "Potion used: " << potionUsedCount << std::endl
       << "Dodge count: " << dodgeCount << std::endl
       << "Miss count: " << missCount << std::endl
       << "Critical hit count: " << criticalHitCount << std::endl
       << "Escape fails: " << escapeFailCount << std::endl
       << "Escape success: " << escapeSuccessCount << std::endl
       << "------------------End-Battle Report-End------------------" << std::endl;

    return ss.str();
}

battle_result_types BattleResult::getResultType(){
    return battleResult;
}

unsigned int BattleResult::getEnemyLeaderId() const {
    return enemyLeaderId;
}

void BattleResult::setExpGainCount(int value) {
    expGainCount = value;
}

int BattleResult::getExpGainCount() const {
    return expGainCount;
}

void BattleResult::setGoldGainCount(int value) {
    goldGainCount = value;
}

int BattleResult::getGoldGainCount() const {
    return goldGainCount;
}

std::vector<achievementPair> BattleResult::getAchievementDataSet() {
    std::vector<achievementPair> v;
    if(playerKilled)
        v.emplace_back(AE_P_DEATHS,1);

    if(enemyLeaderKilled){
        v.emplace_back(AE_P_KILLS,1 + enemyDeadFollowersCount );
    }else{
        v.emplace_back(AE_P_KILLS, enemyDeadFollowersCount);
    }

    if(expGainCount)
        v.emplace_back(AE_P_EXP, expGainCount);

    if(goldGainCount)
        v.emplace_back(AE_P_GOLD, goldGainCount);

    if(damageDealtCount)
        v.emplace_back(AE_P_DMG, damageDealtCount);

    if(spellDamageDealtCount)
        v.emplace_back(AE_P_SPELL_DMG, spellDamageDealtCount);

    if(damageTakenCount)
        v.emplace_back(AE_P_DMG_TAKEN, damageTakenCount);

    if(potionUsedCount)
        v.emplace_back(AE_P_POTION, potionUsedCount);

    if(dodgeCount)
        v.emplace_back(AE_P_DODGE, dodgeCount);

    if(missCount)
        v.emplace_back(AE_P_MISS, missCount);

    if(criticalHitCount)
        v.emplace_back(AE_P_CRITHIT, criticalHitCount);

    if(escapeFailCount)
        v.emplace_back(AE_P_ESCAPE_F, escapeFailCount);

    if(escapeSuccessCount)
        v.emplace_back(AE_P_ESCAPE_S, escapeSuccessCount);

    return v;
}




