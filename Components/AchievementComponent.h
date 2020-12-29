//
// Created by Zheng on 20/12/2020.
//

#ifndef DRAGONSLAYER_ACHIEVEMENTCOMPONENT_H
#define DRAGONSLAYER_ACHIEVEMENTCOMPONENT_H

#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
#include <queue>
#include <map>
#include "AchievementsEnum.h"
#include "../Core/Observer.h"
#include "../Game/Achievement.h"
#include "../Gui/AchievementTab.h"
#include "../Gui/Gui.h"

typedef std::pair<int, int> achievementRecord;

class AchievementTab;
namespace gui{
    class AchievementNotification;
}

class AchievementComponent : public Observer{
public:
    //constructor/destructor
    AchievementComponent(sf::Font* font);
    ~AchievementComponent() override;

    //accessor&modifers
    std::vector<std::shared_ptr<Achievement>>& getAchievements();
    int getAchievementsSize();
    int getUnlockedAchievementsSize();
    std::shared_ptr<Achievement> getAchievement(achievement_event event_type, int series_index);
    int getAchievementEventValue(achievement_event event_type) const;
    void setAchievementTab(std::shared_ptr<AchievementTab> achievement_tab);
    float getExpGoldBonus() const;
    std::map<achievement_event, achievementRecord> getRecords();

    //functions
    void loadRecords(std::map<achievement_event, achievementRecord>& save_records);
    void loadAchievements(std::vector<Achievement>& save_achievements);
    void unlockAllAchievements();
    void calculateExpGoldBonus();
    void checkAchievement(achievement_event event_type, int max_series, achievementRecord& achievement_record);
    void createNotification(const std::shared_ptr<Achievement>& unlocked_achievement);
    std::string toString();
    void onNotify(achievement_event event, int value) override;
    void update(const float& dt, const sf::Vector2f &mousePos);
    void render(sf::RenderTarget& target);

private:
    sf::Font* font;
    std::vector<std::shared_ptr<Achievement>> achievements;
    std::queue<gui::AchievementNotification> achievementNotifications;
    std::shared_ptr<AchievementTab> aTab;
    float expGoldBonus{};
    //achievementRecord = {serie progress, value}
    achievementRecord playerDeaths{};
    achievementRecord playerKills{};
    achievementRecord playerExpGain{};
    achievementRecord playerGoldGain{};
    achievementRecord playerDmg{};
    achievementRecord playerSpellDmg{};
    achievementRecord playerDmgTaken{};
    achievementRecord playerPotionUses{};
    achievementRecord playerDodge{};
    achievementRecord playerMiss{};
    achievementRecord playerCritHit{};
    achievementRecord playerEscapeFails{};
    achievementRecord playerEscapeSuccesses{};
    achievementRecord playerLevel{};
    achievementRecord floorReached{};
    achievementRecord playerMaxedSpells{};
};


#endif //DRAGONSLAYER_ACHIEVEMENTCOMPONENT_H
