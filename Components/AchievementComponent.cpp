//
// Created by Zheng on 20/12/2020.
//

#include "AchievementComponent.h"


//constructor/destructor
AchievementComponent::AchievementComponent(sf::Font *font) {
    this->font = font;
}

AchievementComponent::~AchievementComponent() = default;

//accessor&modifers
std::vector<std::shared_ptr<Achievement>> &AchievementComponent::getAchievements() {
    return achievements;
}

int AchievementComponent::getAchievementsSize() {
    return achievements.size();
}

int AchievementComponent::getUnlockedAchievementsSize() {
    int count = 0;
    for (auto &i : achievements) {
        if (i->isUnlocked())
            count++;
    }
    return count;
}

int AchievementComponent::getAchievementEventValue(achievement_event event_type) const {
    switch (event_type) {
        case AE_P_DEATHS:
            return playerDeaths.second;
        case AE_P_KILLS:
            return playerKills.second;
        case AE_P_EXP:
            return playerExpGain.second;
        case AE_P_GOLD:
            return playerGoldGain.second;
        case AE_P_DMG:
            return playerDmg.second;
        case AE_P_SPELL_DMG:
            return playerSpellDmg.second;
        case AE_P_DMG_TAKEN:
            return playerDmgTaken.second;
        case AE_P_POTION:
            return playerPotionUses.second;
        case AE_P_DODGE:
            return playerDodge.second;
        case AE_P_MISS:
            return playerMiss.second;
        case AE_P_CRITHIT:
            return playerCritHit.second;
        case AE_P_ESCAPE_F:
            return playerEscapeFails.second;
        case AE_P_ESCAPE_S:
            return playerEscapeSuccesses.second;
        case AE_P_LEVEL:
            return playerLevel.second;
        case AE_P_MAXEDSPELL:
            return playerMaxedSpells.second;
        case AE_FLOOR_REACHED:
            return floorReached.second;
        case AE_BOSS_ROOM:
        case AE_END_GAME:
            return endGame.second;
        default:
            return 0;
    }
}

std::shared_ptr<Achievement> AchievementComponent::getAchievement(achievement_event event_type, int series_index) {
    for (auto i : achievements) {
        if (i->getAchievementEventType() == event_type && i->getSeriesPos() == series_index)
            return i;
    }
    return nullptr;
}

void AchievementComponent::setAchievementTab(std::shared_ptr<AchievementTab> achievement_tab) {
    aTab = std::move(achievement_tab);
}

float AchievementComponent::getExpGoldBonus() const {
    return expGoldBonus;
}

std::map<achievement_event, achievementRecord> AchievementComponent::getRecords() {
    std::map<achievement_event, achievementRecord> records;
    records.insert(std::pair<achievement_event, achievementRecord>(AE_P_DEATHS, playerDeaths));
    records.insert(std::pair<achievement_event, achievementRecord>(AE_P_KILLS, playerKills));
    records.insert(std::pair<achievement_event, achievementRecord>(AE_P_EXP, playerExpGain));
    records.insert(std::pair<achievement_event, achievementRecord>(AE_P_GOLD, playerGoldGain));
    records.insert(std::pair<achievement_event, achievementRecord>(AE_P_DMG, playerDmg));
    records.insert(std::pair<achievement_event, achievementRecord>(AE_P_SPELL_DMG, playerSpellDmg));
    records.insert(std::pair<achievement_event, achievementRecord>(AE_P_DMG_TAKEN, playerDmgTaken));
    records.insert(std::pair<achievement_event, achievementRecord>(AE_P_POTION, playerPotionUses));
    records.insert(std::pair<achievement_event, achievementRecord>(AE_P_DODGE, playerDodge));
    records.insert(std::pair<achievement_event, achievementRecord>(AE_P_MISS, playerMiss));
    records.insert(std::pair<achievement_event, achievementRecord>(AE_P_CRITHIT, playerCritHit));
    records.insert(std::pair<achievement_event, achievementRecord>(AE_P_ESCAPE_F, playerEscapeFails));
    records.insert(std::pair<achievement_event, achievementRecord>(AE_P_ESCAPE_S, playerEscapeSuccesses));
    records.insert(std::pair<achievement_event, achievementRecord>(AE_P_LEVEL, playerLevel));
    records.insert(std::pair<achievement_event, achievementRecord>(AE_FLOOR_REACHED, floorReached));
    records.insert(std::pair<achievement_event, achievementRecord>(AE_P_MAXEDSPELL, playerMaxedSpells));
    return records;
}

//functions
void AchievementComponent::loadRecords(std::map<achievement_event, achievementRecord>& save_records) {
    playerDeaths = save_records[AE_P_DEATHS];
    playerKills = save_records[AE_P_KILLS];
    playerExpGain = save_records[AE_P_EXP];
    playerGoldGain = save_records[AE_P_GOLD];
    playerDmg = save_records[AE_P_DMG];
    playerSpellDmg = save_records[AE_P_SPELL_DMG];
    playerDmgTaken = save_records[AE_P_DMG_TAKEN];
    playerPotionUses = save_records[AE_P_POTION];
    playerDodge = save_records[AE_P_DODGE];
    playerMiss = save_records[AE_P_MISS];
    playerCritHit = save_records[AE_P_CRITHIT];
    playerEscapeFails = save_records[AE_P_ESCAPE_F];
    playerEscapeSuccesses = save_records[AE_P_ESCAPE_S];
    playerLevel = save_records[AE_P_LEVEL];
    floorReached = save_records[AE_FLOOR_REACHED];
    playerMaxedSpells = save_records[AE_P_MAXEDSPELL];
}

void AchievementComponent::loadAchievements(std::vector<Achievement> &save_achievements) {
    achievements.clear();
    achievements.reserve(save_achievements.size());
    for(const auto& i : save_achievements){
        achievements.push_back(std::make_shared<Achievement>(i));
    }
}

void AchievementComponent::unlockAllAchievements() {
    for (const auto &i : achievements) {
        i->setUnlocked(true);
    }
    playerDeaths.first = 4;
    playerKills.first = 4;
    playerExpGain.first = 4;
    playerGoldGain.first = 4;
    playerDmg.first = 4;
    playerSpellDmg.first = 4;
    playerDmgTaken.first = 4;
    playerPotionUses.first = 4;
    playerDodge.first = 4;
    playerMiss.first = 4;
    playerCritHit.first = 4;
    playerEscapeFails.first = 4;
    playerEscapeSuccesses.first = 4;
    aTab->updateAchievementsSlots(true);
    aTab->updateTextLbl();
}

void AchievementComponent::checkAchievement(achievement_event event_type, int max_series,
                                            achievementRecord &achievement_record) {
    if (achievement_record.first < max_series) {
        std::shared_ptr<Achievement> app;
        bool check_again;
        do {
            check_again = false;
            app = getAchievement(event_type, achievement_record.first);
            if (app) {
                if (achievement_record.second >= app->getGoal() && achievement_record.first < max_series) {
                    app->setUnlocked(true);
                    achievement_record.first++;
                    if (achievement_record.first == max_series)
                        check_again = false;
                    else
                        check_again = true;
                    aTab->updateTextLbl();
                    createNotification(app);
                }
            } else {
                std::cout << "ERROR CHECK ACHIEVEMENT: NO SUCH ACHIEVEMENT" << std::endl;
            }
        } while (check_again);
    }
}

void AchievementComponent::createNotification(const std::shared_ptr<Achievement> &unlocked_achievement) {
    achievementNotifications.push(gui::AchievementNotification(5.f, 80.f, unlocked_achievement, font));
}

void AchievementComponent::onNotify(achievement_event event, int value) {
    std::stack<achievement_event> update_list;
    switch (event) {
        case AE_P_DEATHS: {
            playerDeaths.second += value;
            checkAchievement(AE_P_DEATHS, 4, playerDeaths);
            update_list.push(AE_P_DEATHS);
            break;
        }
        case AE_P_KILLS: {
            playerKills.second += value;
            checkAchievement(AE_P_KILLS, 4, playerKills);
            update_list.push(AE_P_KILLS);
            break;
        }
        case AE_P_EXP: {
            playerExpGain.second += value;
            checkAchievement(AE_P_EXP, 4, playerExpGain);
            update_list.push(AE_P_EXP);
            break;
        }
        case AE_P_GOLD: {
            playerGoldGain.second += value;
            checkAchievement(AE_P_GOLD, 4, playerGoldGain);
            update_list.push(AE_P_GOLD);
            break;
        }
        case AE_P_DMG: {
            playerDmg.second += value;
            checkAchievement(AE_P_DMG, 4, playerDmg);
            update_list.push(AE_P_DMG);
            break;
        }
        case AE_P_SPELL_DMG: {
            playerSpellDmg.second += value;
            checkAchievement(AE_P_SPELL_DMG, 4, playerSpellDmg);
            update_list.push(AE_P_SPELL_DMG);
            break;
        }
        case AE_P_DMG_TAKEN: {
            playerDmgTaken.second += value;
            checkAchievement(AE_P_DMG_TAKEN, 4, playerDmgTaken);
            update_list.push(AE_P_DMG_TAKEN);
            break;
        }
        case AE_P_POTION: {
            playerPotionUses.second += value;
            checkAchievement(AE_P_POTION, 4, playerPotionUses);
            update_list.push(AE_P_POTION);
            break;
        }
        case AE_P_DODGE: {
            playerDodge.second += value;
            checkAchievement(AE_P_DODGE, 4, playerDodge);
            update_list.push(AE_P_DODGE);
            break;
        }
        case AE_P_MISS: {
            playerMiss.second += value;
            checkAchievement(AE_P_MISS, 4, playerMiss);
            update_list.push(AE_P_MISS);
            break;
        }
        case AE_P_CRITHIT: {
            playerCritHit.second += value;
            checkAchievement(AE_P_CRITHIT, 4, playerCritHit);
            update_list.push(AE_P_CRITHIT);
            break;
        }
        case AE_P_ESCAPE_F: {
            playerEscapeFails.second += value;
            checkAchievement(AE_P_ESCAPE_F, 4, playerEscapeFails);
            update_list.push(AE_P_ESCAPE_F);
            break;
        }
        case AE_P_ESCAPE_S: {
            playerEscapeSuccesses.second += value;
            checkAchievement(AE_P_ESCAPE_S, 4, playerEscapeSuccesses);
            update_list.push(AE_P_ESCAPE_S);
            break;
        }
        case AE_P_MAXEDSPELL: {
            playerMaxedSpells.second = value;
            checkAchievement(AE_P_MAXEDSPELL, 4, playerMaxedSpells);
            update_list.push(AE_P_MAXEDSPELL);
            break;
        }
        case AE_P_LEVEL:{
            playerLevel.second = value;
            checkAchievement(AE_P_LEVEL, 10, playerLevel);
            update_list.push(AE_P_LEVEL);
            break;
        }
        case AE_FLOOR_REACHED: {
            floorReached.second = value;
            checkAchievement(AE_FLOOR_REACHED, 5, floorReached);
            update_list.push(AE_FLOOR_REACHED);
            break;
        }
        case AE_BOSS_ROOM:
        case AE_END_GAME:
            endGame.second = value;
            checkAchievement(AE_END_GAME, 1, endGame);
            update_list.push(AE_END_GAME);
            break;
    }
    while (!update_list.empty()) {
        aTab->updateAchievementsSlot(update_list.top());
        update_list.pop();
    }
}

void AchievementComponent::calculateExpGoldBonus() {
    float bonus = 1.f;
    if (playerDeaths.first > 3) {
        bonus += 0.25f;
    } else if (playerDeaths.first > 0) {
        bonus += (0.05f * (float) (playerDeaths.first)) + 0.05f;
    }

    if (playerKills.first > 3) {
        bonus += 0.25f;
    } else if (playerKills.first > 0) {
        bonus += (0.05f * (float) (playerKills.first)) + 0.05f;
    }

    if (playerExpGain.first > 3) {
        bonus += 0.25f;
    } else if (playerExpGain.first > 0) {
        bonus += (0.05f * (float) (playerExpGain.first)) + 0.05f;
    }

    if (playerGoldGain.first > 3) {
        bonus += 0.25f;
    } else if (playerGoldGain.first > 0) {
        bonus += (0.05f * (float) (playerGoldGain.first)) + 0.05f;
    }

    if (playerDmg.first > 3) {
        bonus += 0.25f;
    } else if (playerDmg.first > 0) {
        bonus += (0.05f * (float) (playerDmg.first)) + 0.05f;
    }

    if (playerSpellDmg.first > 3) {
        bonus += 0.25f;
    } else if (playerSpellDmg.first > 0) {
        bonus += (0.05f * (float) (playerSpellDmg.first)) + 0.05f;
    }

    if (playerDmgTaken.first > 3) {
        bonus += 0.25f;
    } else if (playerDmgTaken.first > 0) {
        bonus += (0.05f * (float) (playerDmgTaken.first)) + 0.05f;
    }

    if (playerPotionUses.first > 3) {
        bonus += 0.25f;
    } else if (playerPotionUses.first > 0) {
        bonus += (0.05f * (float) (playerPotionUses.first)) + 0.05f;
    }

    if (playerDodge.first > 3) {
        bonus += 0.25f;
    } else if (playerDodge.first > 0) {
        bonus += (0.05f * (float) (playerDodge.first)) + 0.05f;
    }

    if (playerMiss.first > 3) {
        bonus += 0.25f;
    } else if (playerMiss.first > 0) {
        bonus += (0.05f * (float) (playerMiss.first)) + 0.05f;
    }

    if (playerCritHit.first > 3) {
        bonus += 0.25f;
    } else if (playerCritHit.first > 0) {
        bonus += (0.05f * (float) (playerCritHit.first)) + 0.05f;
    }

    if (playerEscapeFails.first > 3) {
        bonus += 0.25f;
    } else if (playerEscapeFails.first > 0) {
        bonus += (0.05f * (float) (playerEscapeFails.first)) + 0.05f;
    }

    if (playerEscapeSuccesses.first > 3) {
        bonus += 0.25f;
    } else if (playerEscapeSuccesses.first > 0) {
        bonus += (0.05f * (float) (playerEscapeSuccesses.first)) + 0.05f;
    }

    if (playerMaxedSpells.first > 3) {
        bonus += 0.25f;
    } else if (playerMaxedSpells.first > 0) {
        bonus += (0.05f * (float) (playerMaxedSpells.first)) + 0.05f;
    }

    if (playerLevel.first > 9) {
        bonus += 1.f;
    } else if (playerMaxedSpells.first > 0) {
        bonus += (0.1f * (float) (playerMaxedSpells.first));
    }

    if (floorReached.first > 5) {
        bonus += 0.25f;
    } else if (floorReached.first > 0) {
        bonus += (0.05f * (float) (floorReached.first));
    }

    expGoldBonus = bonus;
}

void AchievementComponent::update(const float &dt, const sf::Vector2f &mousePos) {
    if (!achievementNotifications.empty()) {
        achievementNotifications.front().update(dt, mousePos);
        if (achievementNotifications.front().isDone()) {
            achievementNotifications.pop();
        }
    }
}

void AchievementComponent::render(sf::RenderTarget &target) {
    if (!achievementNotifications.empty()) {
        achievementNotifications.front().render(target);
    }
}

std::string AchievementComponent::toString() {
    std::stringstream ss;
    for (const auto &i : achievements) {
        ss << i->toString();
    }
    return ss.str();
}





















