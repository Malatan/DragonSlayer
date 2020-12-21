//
// Created by Zheng on 20/12/2020.
//

#include "AchievementComponent.h"


//constructor/destructor
AchievementComponent::AchievementComponent(sf::Font* font) {
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
        case AE_FLOOR_REACHED:
            return floorReached.second;
        case AE_BOSS_ROOM: case AE_END_GAME:
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

//functions
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
    playerDodge.first = 4;;
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

void AchievementComponent::createNotification(const std::shared_ptr<Achievement>& unlocked_achievement) {
    achievementNotifications.push(gui::AchievementNotification(5.f, 80.f, unlocked_achievement, font));
}

void AchievementComponent::onNotify(achievement_event event, int value) {
    std::shared_ptr<Achievement> app;
    switch (event) {
        case AE_P_DEATHS: {
            playerDeaths.second += value;
            checkAchievement(AE_P_DEATHS, 4, playerDeaths);
            break;
        }
        case AE_P_KILLS: {
            playerKills.second += value;
            checkAchievement(AE_P_KILLS, 4, playerKills);
            break;
        }
        case AE_P_EXP: {
            playerExpGain.second += value;
            checkAchievement(AE_P_EXP, 4, playerExpGain);
            break;
        }
        case AE_P_GOLD: {
            playerGoldGain.second += value;
            checkAchievement(AE_P_GOLD, 4, playerGoldGain);
            break;
        }
        case AE_P_DMG: {
            playerDmg.second += value;
            checkAchievement(AE_P_DMG, 4, playerDmg);
            break;
        }
        case AE_P_SPELL_DMG: {
            playerSpellDmg.second += value;
            checkAchievement(AE_P_SPELL_DMG, 4, playerSpellDmg);
            break;
        }
        case AE_P_DMG_TAKEN: {
            playerDmgTaken.second += value;
            checkAchievement(AE_P_DMG_TAKEN, 4, playerDmgTaken);
            break;
        }
        case AE_P_POTION: {
            playerPotionUses.second += value;
            checkAchievement(AE_P_POTION, 4, playerPotionUses);
            break;
        }
        case AE_P_DODGE: {
            playerDodge.second += value;
            checkAchievement(AE_P_DODGE, 4, playerDodge);
            break;
        }
        case AE_P_MISS: {
            playerMiss.second += value;
            checkAchievement(AE_P_MISS, 4, playerMiss);
            break;
        }
        case AE_P_CRITHIT: {
            playerCritHit.second += value;
            checkAchievement(AE_P_CRITHIT, 4, playerCritHit);
            break;
        }
        case AE_P_ESCAPE_F: {
            playerEscapeFails.second += value;
            checkAchievement(AE_P_ESCAPE_F, 4, playerEscapeFails);
            break;
        }
        case AE_P_ESCAPE_S: {
            playerEscapeSuccesses.second += value;
            checkAchievement(AE_P_ESCAPE_S, 4, playerEscapeSuccesses);
            break;
        }
        case AE_FLOOR_REACHED:{
            floorReached.second = value;
            checkAchievement(AE_FLOOR_REACHED, 5, floorReached);
            break;
        }
        case AE_BOSS_ROOM: case AE_END_GAME:
            break;
    }
    aTab->updateAchievementsSlots();
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

    if (floorReached.first > 5) {
        bonus += 0.25f;
    } else if (floorReached.first > 0) {
        bonus += (0.05f * (float) (floorReached.first));
    }

    expGoldBonus = bonus;
}

void AchievementComponent::update(const float& dt, const sf::Vector2f &mousePos) {
    if (!achievementNotifications.empty()) {
        achievementNotifications.front().update(dt, mousePos);
        if (achievementNotifications.front().isDone()) {
            achievementNotifications.pop();
        }
    }
}

void AchievementComponent::render(sf::RenderTarget &target) {
    if(!achievementNotifications.empty()){
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





















