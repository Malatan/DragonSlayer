//
// Created by Leonardo on 09/11/2020.
//


#include "BattleState.h"

void BattleState::initResources() {
    rsHandler->addResource("../Resources/Images/Backgrounds/battleBG.png", "battleBG", "BattleState");
    rsHandler->addResource("../Resources/Images/Backgrounds/battleStateWall.png", "battleStateWall", "BattleState");
    rsHandler->addResource("../Resources/Images/Backgrounds/turnsWall.png", "turnsWall", "BattleState");
}

void BattleState::initBattleFieldComponents() {
    enemyPos[0].setPosition(1325.f, 490.f);
    enemyPos[0].setFillColor(sf::Color::Red);
    enemyPos[0].setSize(sf::Vector2f(5.f, 5.f));

    enemyPos[1].setPosition(1125.f, 430.f);
    enemyPos[1].setFillColor(sf::Color::Green);
    enemyPos[1].setSize(sf::Vector2f(5.f, 5.f));

    enemyPos[2].setPosition(975.f, 570.f);
    enemyPos[2].setFillColor(sf::Color::White);
    enemyPos[2].setSize(sf::Vector2f(5.f, 5.f));

    enemyPos[3].setPosition(800.f, 430.f);
    enemyPos[3].setFillColor(sf::Color::Blue);
    enemyPos[3].setSize(sf::Vector2f(5.f, 5.f));

    enemyPos[4].setPosition(625.f, 570.f);
    enemyPos[4].setFillColor(sf::Color::Yellow);
    enemyPos[4].setSize(sf::Vector2f(5.f, 5.f));

    playerPos.setPosition(220.f, 475.f);
    playerPos.setFillColor(sf::Color::Magenta);
    playerPos.setSize(sf::Vector2f(5.f, 5.f));

    turnPanel.setSize(sf::Vector2f(1430.f, 40.f));
    turnPanel.setPosition(5.f, 5.f);
    turnsTexture.loadFromImage(this->rsHandler->getResourceByKey("turnsWall")->getImage());
    turnPanel.setTexture(&turnsTexture);
    turnPanel.setFillColor(sf::Color(80, 80, 80));
    turnPanel.setOutlineColor(sf::Color(15, 15, 15));
    turnPanel.setOutlineThickness(5.f);

    turnPanelTitle.setFont(*font);
    turnPanelTitle.setCharacterSize(25);
    turnPanelTitle.setString("TURN :");
    turnPanelTitle.setPosition(turnPanel.getPosition().x + 10.f, turnPanel.getPosition().y);

    turnPanelWho.setFont(*font);
    turnPanelWho.setCharacterSize(25);
    turnPanelWho.setString("Your Turn");
    turnPanelWho.setPosition(turnPanel.getPosition().x + 150.f, turnPanel.getPosition().y);

    turnPanelLbl.setFont(*font);
    turnPanelLbl.setCharacterSize(25);
    turnPanelLbl.setString("Player is deciding...");
    turnPanelLbl.setPosition(turnPanel.getPosition().x + turnPanel.getGlobalBounds().width / 2.f -
                             turnPanelLbl.getGlobalBounds().width / 2.f,turnPanel.getPosition().y);

    turnPanelActionLbl.setFont(*font);
    turnPanelActionLbl.setCharacterSize(25);
    turnPanelActionLbl.setString("Enemy selected: None");
    turnPanelActionLbl.setPosition(turnPanelLbl.getPosition().x + 325.f, turnPanel.getPosition().y);

    messageLbl.setFont(*font);
    messageLbl.setCharacterSize(20);
    messageLbl.setPosition(turnPanel.getPosition().x,
                           turnPanel.getPosition().y + turnPanel.getGlobalBounds().height);
    stringstream ss;
    ss << "Be aware! Enemy Captain has been enhanced\n"
                  "by its followers\n"
                  "Current stats boost: " << enemyLeader->getAliveFollowersNumber() * Enemy::BASE_BOOST << "%";
    messageLbl.setString(ss.str());
}

void BattleState::initEscapePanel() {
    escapeActionPanel.setPosition(actionPanel.getPosition());
    escapeActionPanel.setFillColor(sf::Color(150, 150, 150, 0));
    escapeActionPanel.setSize(actionPanel.getSize());

    escapeText.setFont(*this->font);
    stringstream ss;
    int highestAgility = 0;
    for (const auto &i : enemiesModels) {
        if (i->getStats()->getAgility() > highestAgility)
            highestAgility = i->getStats()->getAgility();
    }
    escapeChance = (float)(player->getPlayerStats()->getAgility() - highestAgility);
    if (escapeChance <= 0.f)
        escapeChance = 1.5f;
    if (escapeChance > 10.f)
        escapeChance = 10.f;

    ss << "Your Agility - " << player->getPlayerStats()->getAgility() << endl
       << "Enemy's highest Agility - " << highestAgility << endl
       << "Do you want to try to escape?";

    escapeText.setString(ss.str());
    escapeText.setCharacterSize(25);
    escapeText.setPosition(escapeActionPanel.getPosition().x + 30.f, escapeActionPanel.getPosition().y + 50.f);

    escapeConfirmBtn->setPosition(escapeActionPanel.getPosition().x + escapeActionPanel.getGlobalBounds().width / 2.f -
                                 escapeConfirmBtn->getGlobalBounds().width / 2.f,
                                 escapeActionPanel.getPosition().y + 200.f);
}

void BattleState::initStatsPanel() {
    playerStatsPanel.setSize(sf::Vector2f(
            (static_cast<float>(this->window->getSize().x) - 270.f - actionPanel.getGlobalBounds().width) / 2.f,
            291.f));
    playerStatsPanel.setPosition(actionPanel.getPosition().x + actionPanel.getGlobalBounds().width - 3.f,
                                 actionPanel.getPosition().y);
    playerStatsPanel.setFillColor(sf::Color(170, 170, 170, 30));
    playerStatsPanel.setOutlineColor(sf::Color(15, 15, 15));
    playerStatsPanel.setOutlineThickness(3.f);

    playerStatsPanelTitle.setFont(*this->font);
    playerStatsPanelTitle.setCharacterSize(30);
    playerStatsPanelTitle.setString("Player Stats");
    playerStatsPanelTitle.setPosition(playerStatsPanel.getPosition().x + playerStatsPanel.getGlobalBounds().width / 2.f
                                      - playerStatsPanelTitle.getGlobalBounds().width / 2.f,
                                      playerStatsPanel.getPosition().y);

    playerStatsNameLbl.setFont(*this->font);
    playerStatsNameLbl.setCharacterSize(20);
    playerStatsNameLbl.setPosition(playerStatsPanel.getPosition().x + 5.f,
                                   playerStatsPanel.getPosition().y + playerStatsPanelTitle.getGlobalBounds().height +
                                   50.f);
    playerStatsNameLbl.setString(
            " Level:       \n"
            " Max Hp:      \n"
            " Max Mp:      \n"
            " Damage:      \n"
            " Armor:       \n"
            " Critical %: \n"
            " Evade %:\n");

    playerStatsValueLbl.setFont(*this->font);
    playerStatsValueLbl.setCharacterSize(20);
    playerStatsValueLbl.setPosition(playerStatsNameLbl.getPosition().x + 150.f,
                                    playerStatsNameLbl.getPosition().y);

    updatePlayerStatsLbl();

    enemyStatsPanel.setSize(sf::Vector2f(
            playerStatsPanel.getGlobalBounds().width ,
            291.f));
    enemyStatsPanel.setPosition(playerStatsPanel.getPosition().x + playerStatsPanel.getGlobalBounds().width - 3.f,
                                playerStatsPanel.getPosition().y);
    enemyStatsPanel.setFillColor(sf::Color(170, 170, 170, 30));

    enemyStatsPanel.setOutlineColor(sf::Color(15, 15, 15));
    enemyStatsPanel.setOutlineThickness(3.f);

    enemyStatsPanelTitle.setFont(*this->font);
    enemyStatsPanelTitle.setCharacterSize(30);
    enemyStatsPanelTitle.setString("Enemy stats");
    enemyStatsPanelTitle.setPosition(enemyStatsPanel.getPosition().x + enemyStatsPanel.getGlobalBounds().width / 2.f
                                     - enemyStatsPanelTitle.getGlobalBounds().width / 2.f,
                                     enemyStatsPanel.getPosition().y);

    enemyStatsNameLbl.setFont(*this->font);
    enemyStatsNameLbl.setCharacterSize(20);
    enemyStatsNameLbl.setPosition(enemyStatsPanel.getPosition().x + 5.f,
                                  enemyStatsPanel.getPosition().y + enemyStatsPanelTitle.getGlobalBounds().height +
                                  50.f);
    enemyStatsNameLbl.setString(
            " Level:       \n"
            " Max Hp:      \n"
            " Max Mp:      \n"
            " Damage:      \n"
            " Armor:       \n"
            " Critical %: \n"
            " Evade %:\n");

    enemyStatsValueLbl.setFont(*this->font);
    enemyStatsValueLbl.setCharacterSize(20);
    enemyStatsValueLbl.setPosition(enemyStatsNameLbl.getPosition().x + 150.f,
                                   enemyStatsNameLbl.getPosition().y);
    enemyStatsValueLbl.setString("-\n"
                                 "-\n"
                                 "-\n"
                                 "-\n"
                                 "-\n"
                                 "- %\n"
                                 "- %\n");
}

void BattleState::initActionPanel() {
    actionPanel.setPosition(actionBtn->getPosition().x + 253.f, actionBtn->getPosition().y);
    actionPanel.setFillColor(sf::Color(50, 50, 50, 0));
    actionPanel.setSize(sf::Vector2f(
            static_cast<float>(this->window->getSize().x) - 270.f - 500.f,
            291.f));

    actionPanel.setOutlineColor(sf::Color(15, 15, 15));
    actionPanel.setOutlineThickness(3.f);

    int count = 2;
    float total_count = 2.f;
    float columnMod = 65.f;
    currentActionPage = 1;
    maxActionPage = 1;

    std::shared_ptr<Spell> spell = std::make_shared<Spell>(
            DEFAULT_SPELL_TYPE, "Normal attack", "normal", "Attack enemy with your main hand weapon",
            0, 0, 0, 1, true,
            1, 1, 0, 1, 30);
    actionRows.push_back(std::make_unique<gui::ActionRow>(
            525.f, 50.f,
            actionPanel.getPosition().x + 15.f, actionPanel.getPosition().y + 15.f,
            spell, 1.f, font, textures["ITEMS_SHEET"]
    ));

    stringstream ss;
    if(!player->hasShield()){
        playerBlockPercentage = 15.f;
        ss << "Raise your hands and defend yourself this turn by blocking " << playerBlockPercentage << "% of incoming damage";
    }else{
        playerBlockPercentage = (float)player->getEquippedItem(SHIELD_SLOT)->getArmor();
        ss << "Raise your shield and defend yourself this turn by blocking "
        << playerBlockPercentage << "% of incoming damage";
    }
    spell = std::make_shared<Spell>(
            DEFAULT_SPELL_TYPE, "Defense", "normal", ss.str(),
            0, 0, 0, 1, true,
            1, 1, 0, 2, 30);
    actionRows.push_back(std::make_unique<gui::ActionRow>(
            525.f, 50.f,
            actionPanel.getPosition().x + 15.f, actionPanel.getPosition().y + 15.f + 65.f,
            spell, 1.f, font, textures["ITEMS_SHEET"]
    ));

    for (auto & i : spellComponent->getPlayerSpells()) {
        if (i->isLearned()) {
            actionRows.push_back(std::make_unique<gui::ActionRow>(
                    525.f, 50.f,
                    actionPanel.getPosition().x + 15.f, actionPanel.getPosition().y + 15.f + ((float)count * columnMod),
                    i, player->getPlayerStats()->getSpellDmgMultiplier(),
                    font, textures["ITEMS_SHEET"]
            ));
            total_count++;
            if (count == 3) {
                count = 0;
            } else {
                count++;
            }
        }
    }
    maxActionPage = std::ceil(total_count / 4.f);

    pageLbl.setFont(*font);
    pageLbl.setCharacterSize(25);
    ss.str("");
    ss << currentActionPage << " / " << maxActionPage;
    pageLbl.setString(ss.str());
    pageLbl.setOrigin(pageLbl.getGlobalBounds().width / 2.f, pageLbl.getGlobalBounds().height / 2.f);
    pageLbl.setPosition(865.f, 700.f);
    nextPageBtn->setPosition(875.f,
                            740.f);

    previousPageBtn->setPosition(nextPageBtn->getPosition().x - 45.f,
                                nextPageBtn->getPosition().y);
}

void BattleState::initInventoryPanel() {
    itemActionPanel.setPosition(actionPanel.getPosition());
    itemActionPanel.setFillColor(sf::Color(100, 100, 100, 0));
    itemActionPanel.setSize(actionPanel.getSize());

    itemActionPanel.setOutlineColor(sf::Color(15, 15, 15));
    itemActionPanel.setOutlineThickness(3.f);

    currentInvPage = 1;
    maxInvPage = 1;
    int count = 0;
    float total_count = 0.f;
    float columnMod = 65.f;
    if(!itemRows.empty())
        itemRows.clear();
    for (int i = 0; i < player->getInventory()->getItemsSize(); i++) {
        if (player->getInventory()->getItemByIndex(i)->getUsageType() == CONSUMABLE_USAGE) {
            itemRows.push_back(std::make_unique<gui::ItemRow>(
                    525.f, 50.f,
                    itemActionPanel.getPosition().x + 15.f,
                    itemActionPanel.getPosition().y + 15.f + ((float)count * columnMod),
                    player->getInventory()->getItemByIndex(i), font, textures["ITEMS_SHEET"]
            ));
            total_count++;
            if (count == 3) {
                count = 0;
            } else {
                count++;
            }
        }
    }
    maxInvPage = std::ceil(total_count / 4.f);
    if(maxInvPage == 0)
        maxInvPage = 1;
}

void BattleState::initPauseMenu() {
    pmenu = std::make_unique<PauseMenu>(window, font);

    pmenu->addButton("LOAD_SAVE", 360.f, "Load Game", 30);
    pmenu->addButton("QUIT", 440.f, "Quit Game", 40);
}

void BattleState::initBattleResultPanel() {
    resultTitleLbl.setFont(*font);
    resultTitleLbl.setCharacterSize(30);
    resultTextLbl.setFont(*font);
    resultTextLbl.setCharacterSize(20);
    stringstream ss;
    switch (battleResultEnum) {
        case WIN:{
            //calcola xp, range [x, 2x]
            int xp_gain_base = enemyLeader->getStats()->getLevel();
            for(const auto& i : enemyLeader->getFollowers()){
                if(i->isDead()){
                    xp_gain_base += i->getStats()->getLevel();
                }
            }
            int xp_gain = utils::generateRandomNumber(xp_gain_base, xp_gain_base*2);
            float multiplier = utils::generateRandomNumberf(1.2f, 2.f, 2);
            xp_gain = (int)((float)xp_gain * multiplier);
            multiplier = utils::generateRandomNumberf(1.5f, 2.5f, 2);
            int gold_gain = (int)((float)xp_gain * multiplier);

            if(enemyLeader->getType() == DRAGON){
                xp_gain *= 9;
                gold_gain *= 9;
            }
            int final_exp = std::ceil((float)xp_gain * expGoldBonus);
            int final_gold = std::ceil((float)gold_gain * expGoldBonus);
            resultTitleLbl.setFillColor(sf::Color::Green);
            resultTitleLbl.setStyle(sf::Text::Italic);
            resultTitleLbl.setString("YOU WIN!");
            ss << "You killed " << enemyLeader->getDeadFollowersNumber() + 1 << " enemis and won the battle!" << std::endl;
            ss << "   + " << final_exp << " exp(" << xp_gain << " * " << expGoldBonus << ")" << std::endl;
            ss << "   + " << final_gold << " golds(" << gold_gain << " * " << expGoldBonus << ")" << std::endl;
            battleResult->setExpGainCount(final_exp);
            battleResult->setGoldGainCount(final_gold);
            break;
        }
        case LOST:{
            ss << "You will respawn at hub" << std::endl;
            resultTitleLbl.setFillColor(sf::Color::Red);
            resultTitleLbl.setStyle(sf::Text::Italic);
            resultTitleLbl.setString("YOU DIED!");
            //perde 10 - 30 % di oro e 10 - 30 % di oggetti nell'inventario
            int min_penalty = 15;
            int max_penalty = 30;
            int min_quantity_penalty = 25;
            int max_quantity_penalty = 60;

            if(player->getGold() > 0){
                auto gold_lose_perc = (float)utils::generateRandomNumber(min_penalty, max_penalty);
                int gold_lose = std::ceil(((float)player->getGold() / 100.f) * gold_lose_perc);
                if(gold_lose > 0){
                    player->minusGold(gold_lose);
                    cTab->updateGoldLbls();
                    ss << "You lost " << gold_lose << " golds" << std::endl;
                }
            }

            if(!cTab->getInventorySlots().empty()){
                bool delete_items = true;
                auto item_lose_perc = (float)utils::generateRandomNumber(min_penalty, max_penalty);
                int item_lose = std::ceil(((float)player->getInventory()->getItemsSize() / 100.f) * item_lose_perc);
                ss << "You dropped: " << std::endl;
                int n = 0;
                while(item_lose > 0){
                    int random_index = utils::generateRandomNumber(0, (int)cTab->getInventorySlots().size() - 1);
                    auto& app = cTab->getInventorySlots()[random_index];
                    // se l'oggetto e' un consumabile oppure materiale allora genera una certa quantita da perdere
                    if(app->getItem()->getUsageType() == MATERIAL_USAGE || app->getItem()->getUsageType() == CONSUMABLE_USAGE){
                        auto quantity_lose_perc = (float)utils::generateRandomNumber(min_quantity_penalty, max_quantity_penalty);
                        int quantity_lose = std::ceil(((float)app->getItem()->getQuantity() / 100.f) * quantity_lose_perc);
                        app->getItem()->minusQuantity(quantity_lose);
                        ss << "  You lost x" << quantity_lose << " [" << app->getItem()->getName() << "]" << std::endl;
                        if(app->getItem()->getQuantity() == 0){
                            app->setSelectedBool(true);
                            n++;
                        }
                    }else{
                        n++;
                        app->setSelectedBool(true);
                        ss << "  You lost [" << app->getItem()->getName() << "]" << std::endl;
                    }
                    item_lose--;
                    delete_items = true;
                }
                if(delete_items){
                    cTab->setSeletecItem(n);
                    cTab->deleteItemFromInventory();
                }
            }
            break;
        }
        case ESCAPED:
            resultTitleLbl.setFillColor(sf::Color::White);
            resultTitleLbl.setStyle(sf::Text::Italic);
            resultTitleLbl.setString("RAN AWAY");
            ss << "You abandoned the battle and escaped";
            break;
        case NOT_FINISHED: case QUIT_GAME:
            break;
    }
    resultTextLbl.setString(ss.str());

    if(resultTextLbl.getGlobalBounds().width > 460){
        resultContainer.setSize(sf::Vector2f(resultTextLbl.getGlobalBounds().width + 20.f,
                                              resultTitleLbl.getGlobalBounds().height +
                                              resultTextLbl.getGlobalBounds().height +
                                              100.f));
    }else{
        resultContainer.setSize(sf::Vector2f(500.f,
                                              resultTitleLbl.getGlobalBounds().height +
                                              resultTextLbl.getGlobalBounds().height +
                                              100.f));
    }
    resultBackground.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    resultBackground.setFillColor(sf::Color(0, 0, 0, 150));

    resultContainer.setPosition(window->getSize().x / 2.f - resultContainer.getGlobalBounds().width / 2.f,
                                 window->getSize().y/2.f - resultContainer.getGlobalBounds().height / 2.f);
    resultContainer.setFillColor(sf::Color(90, 90, 90));
    resultContainer.setOutlineColor(sf::Color(60, 60, 60));
    resultContainer.setOutlineThickness(3.f);
    resultTitleLbl.setPosition(resultContainer.getPosition().x + resultContainer.getGlobalBounds().width / 2.f
                               - resultTitleLbl.getGlobalBounds().width/2.f,
                               resultContainer.getPosition().y + 15.f);
    resultTextLbl.setPosition(resultContainer.getPosition().x + resultContainer.getGlobalBounds().width / 2.f
                              - resultTextLbl.getGlobalBounds().width/2.f,
                              resultTitleLbl.getPosition().y + resultTitleLbl.getGlobalBounds().height + 10.f);
    continueBtn = std::make_unique<gui::Button>(resultContainer.getPosition().x + resultContainer.getGlobalBounds().width / 2.f - 50.f,
                              resultContainer.getPosition().y + resultContainer.getGlobalBounds().height - 65.f,
                              100.f, 50.f,
                              font, "Continue", 25);

}

void BattleState::spawnEnemyModel(sf::Vector2f pos, enemy_types type, unsigned int enemy_id) {
    std::shared_ptr<Enemy> enemy;
    switch (type) {
        case WITCH:
            enemy = std::make_shared<Enemy>(WITCH, pos.x, pos.y, -3.2f, 3.2f,
                                            0.f, 0.f, 0.f, 0.f,
                                            0.f, 0.f, 0.f,
                                            textures["ENEMY_WIZARD_SHEET"]);
            enemy->setOrigin(125.f, 167.f);
            break;
        case SKELETON:
            enemy = std::make_shared<Enemy>(SKELETON, pos.x, pos.y, -4.f, 5.f,
                                            0.f, 0.f, 0.f, 0.f,
                                            0.f, 0.f, 0.f,
                                            textures["ENEMY_SKELETON_SHEET"]);
            enemy->setOrigin(50.f, 69.f);
            break;
        case SKELETON_2:
            enemy = std::make_shared<Enemy>(SKELETON_2, pos.x, pos.y, -3.2f, 3.2f,
                                            0.f, 0.f, 0.f, 0.f,
                                            0.f, 0.f, 0.f,
                                            textures["ENEMY_SKELETON_2_SHEET"]);
            enemy->setOrigin(80.f, 100.f);
            break;
        case FLYING_EYE:
            enemy = std::make_shared<Enemy>(FLYING_EYE, pos.x, pos.y, -3.3f, 3.3f,
                                            0.f, 0.f, 0.f, 0.f,
                                            0.f, 0.f, 0.f,
                                            textures["ENEMY_FLYINGEYE_SHEET"]);
            enemy->setOrigin(75.f, 110.f);
            break;
        case GOBLIN:
            enemy = std::make_shared<Enemy>(GOBLIN, pos.x, pos.y, -3.0f, 3.0f,
                                            0.f, 0.f, 0.f, 0.f,
                                            0.f, 0.f, 0.f,
                                            textures["ENEMY_GOBLIN_SHEET"]);
            enemy->setOrigin(75.f, 100.f);
            break;
        case MUSHROOM:
            enemy = std::make_shared<Enemy>(MUSHROOM, pos.x, pos.y, -3.4f, 3.4f,
                                            0.f, 0.f, 0.f, 0.f,
                                            0.f, 0.f, 0.f,
                                            textures["ENEMY_MUSHROOM_SHEET"]);
            enemy->setOrigin(75.f, 100.f);
            break;
        case BANDIT_HEAVY:
            enemy = std::make_shared<Enemy>(BANDIT_HEAVY, pos.x, pos.y, 4.3f, 4.3f,
                                            0.f, 0.f, 0.f, 0.f,
                                            0.f, 0.f, 0.f,
                                            textures["ENEMY_BANDITHEAVY_SHEET"]);
            enemy->setOrigin(24.f, 46.f);
            break;
        case BANDIT_LIGHT:
            enemy = std::make_shared<Enemy>(BANDIT_LIGHT, pos.x, pos.y, 4.f, 4.f,
                                            0.f, 0.f, 0.f, 0.f,
                                            0.f, 0.f, 0.f,
                                            textures["ENEMY_BANDITLIGHT_SHEET"]);
            enemy->setOrigin(24.f, 46.f);
            break;
        case DRAGON:
            enemy = std::make_shared<Enemy>(DRAGON, pos.x, pos.y, -4.f, 4.f,
                                            0.f, 0.f, 0.f, 0.f,
                                            0.f, 0.f, 0.f,
                                            textures["ENEMY_DRAGON_SHEET"]);
            enemy->setOrigin(105.f, 155.f);
            break;
        default:
            std::cout << "No such enemy: " << type;
            break;
    }
    if(enemy){
        enemy->setId(enemy_id);
        enemiesModels.push_back(enemy);
    }
}

void BattleState::generateModels() {
    playerModel = std::make_shared<Player>(220.f, 300.f, 5.f, 5.f, textures["PLAYER_SHEET"]);
    playerModel->setOrigin(20, 33);
    playerModel->setPosition(220.f, 475.f);

    enemyCount = enemyLeader->getFollowersNumber() + 1;
    //inizializza il vettore ordine di azione dei nemici
    for(unsigned int i = 0 ; i < enemyCount ; i++){
        enemiesMoveOrder.push_back(i);
    }
    std::reverse(enemiesMoveOrder.begin(), enemiesMoveOrder.end());

    spawnEnemyModel(enemyPos[0].getPosition(), enemyLeader->getType(), enemyLeader->getId());
    enemiesModels[0]->setStats(enemyLeader->getStats());

    int alive_followers_count = 1;
    for (unsigned int i = 0; i < enemyLeader->getFollowers().size(); i++) {
        if(!enemyLeader->getFollowers()[i]->isDead()){
            spawnEnemyModel(enemyPos[i + 1].getPosition(),
                    enemyLeader->getFollowers()[i]->getType(), enemyLeader->getFollowers()[i]->getId());
            enemiesModels[i + 1]->setStats(enemyLeader->getFollowers()[i]->getStats());
            alive_followers_count++;
        }
    }

    for (unsigned int i = 0; i < alive_followers_count; i++) {
        enemiesStatusPanel[i] = std::make_unique<gui::EnemyStatusPanel>(enemiesModels[i], enemyPos[i].getPosition().x,
                                                      enemyPos[i].getPosition().y - 200.f, font,
                                                      textures["ARROWDOWN_ICON"], this, i);
    }
    playerStatusPanel = std::make_unique<gui::PlayerStatusPanel>(player, playerPos.getPosition().x,
                                               playerPos.getPosition().y - playerModel->getGlobalBounds().height -
                                               150.f, font);
}

void BattleState::initButtons() {
    sf::Color text_idle_color = sf::Color(250, 250, 250, 250);
    sf::Color text_hover_color = sf::Color(71, 17, 13, 250);
    sf::Color text_active_color = sf::Color(20, 20, 20, 50);

    sf::Color hover_color = sf::Color(150, 150, 150, 0);
    sf::Color active_color = sf::Color(20, 20, 20, 0);

    actionBtn = std::make_unique<gui::Button>(5.f, mainActionPanel.getPosition().y + 0.f, 250.f, 95.f,
                            font, "Action", 40,
                            text_idle_color, text_hover_color, text_active_color,
                            sf::Color(170, 170, 170, 30), hover_color, active_color);

    actionBtn->setBorderColor(sf::Color(15, 15, 15));
    actionBtn->setBorderLineThickness(3.f);

    itemActionBtn = std::make_unique<gui::Button>(5.f, mainActionPanel.getPosition().y + 98.f, 250.f, 95.f,
                                font, "Inventory", 40,
                                text_idle_color, text_hover_color, text_active_color,
                                sf::Color(170, 170, 170, 30), hover_color, active_color);

    itemActionBtn->setBorderColor(sf::Color(15, 15, 15));
    itemActionBtn->setBorderLineThickness(3.f);

    escapeActionBtn = std::make_unique<gui::Button>(5.f, mainActionPanel.getPosition().y + 196.f, 250.f, 95.f,
                                  font, "Escape", 40,
                                  text_idle_color, text_hover_color, text_active_color,
                                  sf::Color(170, 170, 170, 30), hover_color, active_color);

    escapeActionBtn->setBorderColor(sf::Color(15, 15, 15));
    escapeActionBtn->setBorderLineThickness(3.f);

    nextPageBtn = std::make_unique<gui::Button>(0.f, 0.f, 30.f, 30.f,
                              font, "=>", 25,
                              text_idle_color, text_hover_color, text_active_color,
                              sf::Color::Transparent, hover_color, active_color);
    previousPageBtn = std::make_unique<gui::Button>(0.f, 0.f, 30.f, 30.f,
                                  font, "<=", 25,
                                  text_idle_color, text_hover_color, text_active_color,
                                  sf::Color::Transparent, hover_color, active_color);

    escapeConfirmBtn = std::make_unique<gui::Button>(0.f, 0.f, 300.f, 70.f,
                                   font, "Run", 40,
                                   text_idle_color, text_hover_color, text_active_color,
                                   sf::Color(170, 170, 170, 30), hover_color, active_color);

    escapeConfirmBtn->setBorderColor(sf::Color(15, 15, 15));
    escapeConfirmBtn->setBorderLineThickness(3.f);
}

BattleState::BattleState(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Player> player,
                         std::stack<std::unique_ptr<State>> *states, state_enum _state_enum,
                         std::shared_ptr<PopUpTextComponent> popUpTextComponent, std::shared_ptr<SpellComponent> spellComponent,
                         std::shared_ptr<BuffComponent> buffComponent, std::shared_ptr<ResourcesHandler> rsHandler,
                         std::map<std::string, sf::Texture> textures, sf::Font *font, std::shared_ptr<Enemy> enemy,
                         float exp_gold_bonus, int floor, std::shared_ptr<CharacterTab> cTab)
                         : expGoldBonus(exp_gold_bonus), State(std::move(window), states, std::move(rsHandler), _state_enum) {
    this->player = std::move(player);
    enemyLeader = std::move(enemy);
    this->textures = std::move(textures);
    this->popUpTextComponent = std::move(popUpTextComponent);
    this->spellComponent = std::move(spellComponent);
    this->buffComponent = std::move(buffComponent);
    this->cTab = std::move(cTab);
    this->font = font;
    this->floor = floor;
    whoseTurn = true;
    selectedId = 10;
    currentPanel = DEFAULT_PANEL;
    turnLengthKeyTime = 0.f;
    turnLengthMaxKeyTime = 40.f;
    enemyMoveDone = false;
    countPlayerTurnTimer = false;
    enemyCount = 0;
    turnCount = 1;
    criticalhitMultiplier = 1.75f;
    enemiesMoves = 10;
    battleResultEnum = NOT_FINISHED;
    potionUsed = false;
    currentWindowState = UNPAUSED;

    battleResult = std::make_shared<BattleResult>();
    initResources();
    initBattleFieldComponents();
    generateModels();

    background.setSize(sf::Vector2f(
            static_cast<float>(this->window->getSize().x),
            static_cast<float>(this->window->getSize().y)));
    backgroundTexture.loadFromImage(this->rsHandler->getResourceByKey("battleBG")->getImage());
    background.setTexture(&backgroundTexture);

    mainActionPanel.setSize(sf::Vector2f(
            static_cast<float>(this->window->getSize().x - 10),
            293.f));
    mainActionPanel.setPosition(5.f, static_cast<float>(this->window->getSize().y - 297.f));
    mainActionPanel.setFillColor(sf::Color(80, 80, 80));
    mainActionPanel.setOutlineColor(sf::Color(15,15,15));
    mainActionPanel.setOutlineThickness(5.f);
    commandsTexture.loadFromImage(this->rsHandler->getResourceByKey("battleStateWall")->getImage());
    mainActionPanel.setTexture(&commandsTexture);

    tipsLbl.setFont(*font);
    tipsLbl.setCharacterSize(20);
    tipsLbl.setString("Tips: You can use 1 potion and perfom 1 action each turn");
    tipsLbl.setPosition(mainActionPanel.getPosition().x + 3.f,
                        mainActionPanel.getPosition().y - tipsLbl.getGlobalBounds().height - 13.f);

    initButtons();
    initActionPanel();
    initInventoryPanel();
    initEscapePanel();
    initStatsPanel();
    initPauseMenu();
}

BattleState::~BattleState() = default;

void BattleState::playerBattle(unsigned int row_index) {
    if (whoseTurn) {
        if ((actionRows[row_index]->getAction()->getTypeEnum() == DEFAULT_SPELL_TYPE &&
             actionRows[row_index]->getAction()->getName() != "Normal attack") ||
            actionRows[row_index]->getAction()->getTypeEnum() == HOLY ||
            actionRows[row_index]->getAction()->getAoe() == 5){// i spell che non fanno i danni e gli aoe spells
            if(player->getPlayerStats()->consumeMana(actionRows[row_index]->getAction()->getFinalCost())){
                if (actionRows[row_index]->getAction()->getName() == "Defense") {
                    playerModel->setAnimation(CAST_ANIMATION, IDLE_ANIMATION);
                    player->setDefense(true);
                    popUpTextComponent->addPopUpText(DEFAULT_TAG,
                            playerModel->getPosition().x,
                            playerModel->getPosition().y - 100.f,
                            "DEFENSE", "", "");
                } else if (actionRows[row_index]->getAction()->getName() == "Meditation") {
                    playerModel->setAnimation(CAST_ANIMATION, IDLE_ANIMATION);
                    int mp_restored = player->getPlayerStats()->gainMp(actionRows[row_index]->getActionFinalDamage());
                    popUpTextComponent->addPopUpText(MANA_RESTORE_TAG,
                            playerModel->getPosition().x,
                            playerModel->getPosition().y - 100.f,
                            mp_restored, "MEDITATION\n+", "MP");

                } else if (actionRows[row_index]->getAction()->getName() == "Cleanse") {
                    playerModel->setAnimation(CAST_ANIMATION, IDLE_ANIMATION);
                    popUpTextComponent->addPopUpText(DEFAULT_TAG,
                            playerModel->getPosition().x,
                            playerModel->getPosition().y - 100.f,
                            "CLEANSE", "", "");
                } else if (actionRows[row_index]->getAction()->getName() == "Heal") {
                    playerModel->setAnimation(CAST_ANIMATION, IDLE_ANIMATION);
                    int hp_restored = player->getPlayerStats()->gainHp(actionRows[row_index]->getActionFinalDamage());
                    popUpTextComponent->addPopUpText(HEAL_TAG,
                            playerModel->getPosition().x,
                            playerModel->getPosition().y - 100.f,
                            hp_restored, "HEAL\n+", "HP");
                } else if(actionRows[row_index]->getAction()->getAoe() == 5){ // aoe spells
                    std::vector<unsigned int> deadEnemiesIndex;
                    for (unsigned int i = 0 ; i < enemyCount ; i++) {
                        if(!enemiesModels[enemiesMoveOrder[i]]->isDead()){
                            int dmg_dealt = enemiesModels[enemiesMoveOrder[i]]->getStats()->getHit(
                                    actionRows[row_index]->getActionFinalDamage(), 0.f, true);
                            enemiesModels[enemiesMoveOrder[i]]->setAnimation(GETHIT_ANIMATION, IDLE_ANIMATION);
                            popUpTextComponent->addPopUpText(NEGATIVE_TAG,
                                                             enemyPos[enemiesMoveOrder[i]].getPosition().x,
                                                             enemyPos[enemiesMoveOrder[i]].getPosition().y - 100.f,
                                                             to_string(dmg_dealt), "-", "");
                            if(enemiesModels[enemiesMoveOrder[i]]->isDead())
                                deadEnemiesIndex.push_back(enemiesMoveOrder[i]);
                            battleResult->addStatistics(SPELL_DAMAGE_DEALT_COUNT, dmg_dealt);
                        }
                    }
                    if(!deadEnemiesIndex.empty()){
                        for(unsigned int i : deadEnemiesIndex){
                            enemiesModels[i]->setAnimation(DEATH_ANIMATION, CORPSE_ANIMATION);
                            enemiesMoveOrder.erase(std::remove(enemiesMoveOrder.begin(), enemiesMoveOrder.end(),
                                                               i), enemiesMoveOrder.end());
                            enemyCount--;
                            updateMessageLbl();
                            selectedId = 10;
                            if(enemyCount == 0 || enemyLeader->isDead()){
                                battleResultEnum = WIN;
                            }
                        }
                    }
                    playerModel->setAnimation(CAST_ANIMATION, IDLE_ANIMATION);

                    popUpTextComponent->addPopUpText(MANA_RESTORE_TAG,
                                                     playerModel->getPosition().x,
                                                     playerModel->getPosition().y - 100.f,
                                                     actionRows[row_index]->getAction()->getFinalCost(), "-", "");

                    stringstream ss;
                    ss << "You casted " << actionRows[row_index]->getAction()->getName() << " to the field!";
                    popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG,
                                                           ss.str(), "", "");
                }
                actionRows[row_index]->startCd();
                endPlayerTurn();
            }else{
                popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG,
                                                       "Not enough mana!", "", "");
            }
        } else { // i spell che fanno i danni
            if (selectedId < 5) {
                if(player->getPlayerStats()->consumeMana(actionRows[row_index]->getAction()->getFinalCost())){
                    if(actionRows[row_index]->getAction()->getName() == "Normal attack"){
                        //player attack animation determine
                        if(player->getEquippedWeaponType() == "Melee"){
                            playerModel->setAnimation(ATTACK_ANIMATION, IDLE_ANIMATION);
                        }else if(player->getEquippedWeaponType() == "Ranged"){
                            playerModel->setAnimation(ATTACK2_ANIMATION, IDLE_ANIMATION);
                        }else if(player->getEquippedWeaponType() == "Empty Handed"){
                            if(utils::trueFalse(50.f)){
                                playerModel->setAnimation(ATTACK3_ANIMATION, IDLE_ANIMATION);
                            }else{
                                playerModel->setAnimation(ATTACK4_ANIMATION, IDLE_ANIMATION);
                            }
                        }
                        // enemy evade determine
                        if(!utils::trueFalse(enemiesModels[selectedId]->getStats()->getFinalEvadeChance())){
                            // player critical hit determine
                            if(utils::trueFalse(player->getPlayerStats()->getFinalCritChance())){
                                int dmg_dealt = enemiesModels[selectedId]->getStats()->getHit(
                                        (int)((float)player->getPlayerStats()->getFinalDamage() * criticalhitMultiplier),
                                        0.f, false);
                                popUpTextComponent->addPopUpText(NEGATIVE_TAG,
                                                                 enemyPos[selectedId].getPosition().x,
                                                                 enemyPos[selectedId].getPosition().y - 100.f,
                                                                 dmg_dealt, "Critical Hit!\n-", "");
                                battleResult->addStatistics(DAMAGE_DEALT_COUNT, dmg_dealt);
                                battleResult->addStatistics(CRITICAL_HIT_COUNT, 1);
                            }else{
                                int dmg_dealt = enemiesModels[selectedId]->getStats()->getHit(
                                        player->getPlayerStats()->getFinalDamage(), 0.f, false);
                                popUpTextComponent->addPopUpText(NEGATIVE_TAG,
                                                                 enemyPos[selectedId].getPosition().x,
                                                                 enemyPos[selectedId].getPosition().y - 100.f,
                                                                 dmg_dealt, "-", "");
                                battleResult->addStatistics(DAMAGE_DEALT_COUNT, dmg_dealt);
                            }
                            enemiesModels[selectedId]->setAnimation(GETHIT_ANIMATION, IDLE_ANIMATION);

                            stringstream ss;
                            ss << "You used " << actionRows[row_index]->getAction()->getName() << " on '"
                               << enemiesModels[selectedId]->getName() << "Lv." << enemiesModels[selectedId]->getStats()->getLevel();
                            popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG,
                                                                   ss.str(), "", "");
                        }else{
                            popUpTextComponent->addPopUpText(DEFAULT_TAG,
                                    enemiesModels[selectedId]->getPosition().x,
                                    enemiesModels[selectedId]->getPosition().y - 100.f,
                                    "MISS", "", "");
                            battleResult->addStatistics(MISS_COUNT, 1);
                        }
                    }else if(actionRows[row_index]->getAction()->getAoe() == 1){
                        actionRows[row_index]->startCd();
                        int dmg_dealt = enemiesModels[selectedId]->getStats()->getHit(
                                actionRows[row_index]->getActionFinalDamage(), 0.f, true);
                        playerModel->setAnimation(CAST_ANIMATION, IDLE_ANIMATION);
                        enemiesModels[selectedId]->setAnimation(GETHIT_ANIMATION, IDLE_ANIMATION);
                        popUpTextComponent->addPopUpText(NEGATIVE_TAG,
                                                         enemyPos[selectedId].getPosition().x,
                                                         enemyPos[selectedId].getPosition().y - 100.f,
                                                         dmg_dealt, "-", "");

                        popUpTextComponent->addPopUpText(MANA_RESTORE_TAG,
                                                         playerModel->getPosition().x,
                                                         playerModel->getPosition().y - 100.f,
                                                         actionRows[row_index]->getAction()->getFinalCost(), "-", "");

                        stringstream ss;
                        ss << "You used " << actionRows[row_index]->getAction()->getName() << " on '"
                           << enemiesModels[selectedId]->getName() << "Lv." << enemiesModels[selectedId]->getStats()->getLevel();
                        popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG,
                                                               ss.str(), "", "");
                        battleResult->addStatistics(SPELL_DAMAGE_DEALT_COUNT, dmg_dealt);
                    }

                    if(enemiesModels[selectedId]->isDead()){
                        enemiesModels[selectedId]->setAnimation(DEATH_ANIMATION, CORPSE_ANIMATION);
                        enemiesMoveOrder.erase(std::remove(enemiesMoveOrder.begin(), enemiesMoveOrder.end(),
                                                           selectedId), enemiesMoveOrder.end());
                        enemyCount--;
                        updateMessageLbl();
                        selectedId = 10;
                        if(enemyCount == 0 || enemyLeader->isDead()){
                            battleResultEnum = WIN;
                        }
                    }
                    endPlayerTurn();

                }else{
                    popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG,
                            "Not enough mana!", "", "");
                }
            } else {
                popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG,
                                                       "Select an Enemy to perform action!", "", "");
            }
        }
    } else {
        popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG,
                                               "Wait for your turn!", "", "");
    }
}

void BattleState::useItem(unsigned int row_index) {
    if (whoseTurn) {
        potionUsed = true;
        if(itemRows[row_index]->getItem()->use()){

        }else{  // empty after use
            cTab->deleteConsumableInBattle(itemRows[row_index]->getItem());
            initInventoryPanel();
        }
        buffComponent->applyItemBuff(itemRows[row_index]->getItem()->getName(), false,
                                     playerModel->getPosition().x,
                                     playerModel->getPosition().y - 100.f);
        itemRows[row_index]->updateQuantityLbl();

        stringstream ss;
        ss << "You used " << itemRows[row_index]->getItem()->getName();
        popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG,
                                               ss.str(), "", "");
        playerModel->setAnimation(CAST_ANIMATION, IDLE_ANIMATION);
        updatePlayerStatsLbl();
        battleResult->addStatistics(POTION_USED_COUNT, 1);
        //endPlayerTurn();
    }else{
        popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG,
                "Wait for your turn!", "", "");
    }
}

void BattleState::endPlayerTurn() {
    // variabili per il turno nemico
    whoseTurn = false;
    countPlayerTurnTimer = true;
    enemiesMoves = enemyCount;
    for(auto &i : actionRows){
        i->setDisabled(true);
    }
    for(auto &i : itemRows){
        i->setDisabled(true);
    }
    escapeConfirmBtn->setDisabled(true);
}

void BattleState::enemyBattle(const float &dt) {
    stringstream ss;
    ss << "TURN " << turnCount << " : ";
    turnPanelTitle.setString(ss.str());
    ss.str("");
    ss<< "Enemy Turn";
    turnPanelWho.setString(ss.str());
    turnPanelWho.setFillColor(sf::Color(190, 30, 30));
    ss.str("");
    ss << "Enemy moves: " << enemiesMoves;
    turnPanelLbl.setString(ss.str());

    if (!enemyMoveDone) {
        ss.str("");
        ss << enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->getName() << " Lv."
           << enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->getStats()->getLevel() << " is deciding...";
        turnPanelActionLbl.setString(ss.str());
    }
    if (turnLengthKeyTime < turnLengthMaxKeyTime) {
        turnLengthKeyTime += 10.f * dt;
        if (turnLengthKeyTime > turnLengthMaxKeyTime / 1.5f && !enemyMoveDone) {
            enemyMoveDone = true;
            BattleAI enemyAI = BattleAI(player, enemiesModels, enemiesMoveOrder, enemiesMoves, popUpTextComponent);

            switch(enemyAI.behaviour()){

                case 0: //ATTACK

                    enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->setAnimation(ATTACK_ANIMATION, IDLE_ANIMATION);
                    // player evade determine
                    if (!utils::trueFalse(player->getPlayerStats()->getFinalEvadeChance())) {
                        int dmg_dealt;
                        //enemy criticalhit determine
                        bool critical_hit = utils::trueFalse(
                                enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->getStats()->getFinalCritChance());
                        float critical_hit_multiplier = 1.f;
                        std::string critical_hit_prefix;
                        if(critical_hit){
                            critical_hit_multiplier = criticalhitMultiplier;
                            critical_hit_prefix = "Critical Hit!\n";
                        }
                        if(player->isDefense()){
                            int enemy_dmg = (int)((float)enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->getStats()->getFinalDamage()
                                                  * critical_hit_multiplier);
                            dmg_dealt = player->getPlayerStats()->getHit(enemy_dmg, playerBlockPercentage, false);
                            popUpTextComponent->addPopUpText(DEFAULT_TAG,
                                                             playerModel->getPosition().x,
                                                             playerModel->getPosition().y - 120.f,
                                                             "DAMAGE REDUCED", "", "");
                            if(player->isDead()){
                                playerModel->setAnimation(DEATH_ANIMATION, CORPSE_ANIMATION);
                            }else{
                                playerModel->setAnimation(SHIELD_ANIMATION, IDLE_ANIMATION);
                            }
                            int dmg_reduced_by_defense = enemy_dmg - dmg_dealt - player->getPlayerStats()->getFinalArmor();
                            battleResult->addStatistics(DAMAGE_TAKEN_COUNT, dmg_dealt);
                            battleResult->addStatistics(DAMAGE_REDUCED_COUNT, dmg_reduced_by_defense);
                        }else{
                            dmg_dealt = player->getPlayerStats()->getHit(
                                    (int)((float)enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->getStats()->getFinalDamage()
                                          * critical_hit_multiplier), 0.f, false);
                            if(player->isDead()){
                                playerModel->setAnimation(DEATH_ANIMATION, CORPSE_ANIMATION);
                            }else{
                                playerModel->setAnimation(GETHIT_ANIMATION, IDLE_ANIMATION);
                            }
                            battleResult->addStatistics(DAMAGE_TAKEN_COUNT, dmg_dealt);
                        }
                        popUpTextComponent->addPopUpText(NEGATIVE_TAG,
                                                         playerModel->getPosition().x,
                                                         playerModel->getPosition().y - 100.f,
                                                         dmg_dealt, critical_hit_prefix+"-", "");
                    } else {
                        popUpTextComponent->addPopUpText(DEFAULT_TAG,
                                                         playerModel->getPosition().x,
                                                         playerModel->getPosition().y - 100.f,
                                                         "MISS", "", "");
                        battleResult->addStatistics(DODGE_COUNT, 1);
                    }
                    ss.str("");
                    ss << enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->getName() << " Lv."
                       << enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->getStats()->getLevel() << " uses Normal Attack";
                    turnPanelActionLbl.setString(ss.str());

                    if(enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->getCd() > 0){
                        enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->updateCd();
                    }
                    break;
                case 1: //HEAL SPELL

                    enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->setAnimation(ATTACK_ANIMATION, IDLE_ANIMATION);

                    ss.str("");
                    ss << enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->getName() << " Lv."
                       << enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->getStats()->getLevel() << " uses Heal Spell";
                    turnPanelActionLbl.setString(ss.str());

                    if(enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->getCd() > 0){
                        enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->updateCd();
                    }
                    break;
                case 2: //HEAL POTION

                    enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->setAnimation(ATTACK_ANIMATION, IDLE_ANIMATION);

                    popUpTextComponent->addPopUpText(DEFAULT_TAG,
                                                     enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->getPosition().x,
                                                     enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->getPosition().y - 100.f,
                                                     "HEALED", "", "");

                    ss.str("");
                    ss << enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->getName() << " Lv."
                       << enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->getStats()->getLevel() << " uses Heal Potion";
                    turnPanelActionLbl.setString(ss.str());

                    if(enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->getCd() > 0){
                        enemiesModels[enemiesMoveOrder[enemiesMoves-1]]->updateCd();
                    }
                    break;
                default:
                    break;
            }

        }
    } else {
        turnLengthKeyTime = 0.f;
        enemiesMoves--;
        enemyMoveDone = false;
        if(player->isDead()){
            battleResultEnum = LOST;
        }
        if (enemiesMoves == 0) {
            endEnemyTurn();
        }
    }
}

void BattleState::endEnemyTurn() {
    playerStatusPanel->setShapeOutlineThickness(5.f);
    player->setDefense(false);
    whoseTurn = true;
    potionUsed = false;
    turnCount++;
    for(auto &i : actionRows){
        i->updateCd();
        i->setDisabled(false);
    }
    for(auto &i : itemRows){
        i->setDisabled(false);
    }
    escapeConfirmBtn->setDisabled(false);
    buffComponent->updatePlayerBuffList();
    updatePlayerStatsLbl();
}

void BattleState::endBattle() {
    switch(battleResultEnum){
        case WIN: case LOST: case ESCAPED:
            initBattleResultPanel();
            currentWindowState = BATTLE_REPORT;
            break;
        case QUIT_GAME:
            endState();
            break;
        case NOT_FINISHED:
            break;
    }
    if(battleResultEnum != NOT_FINISHED){
        battleResult->updateBattleResult(battleResultEnum, player->isDead(), enemyLeader);
        enemyLeader.reset();
        cTab->getGState()->checkBattleResult(battleResult.get());
    }
}

void BattleState::updateMessageLbl() {
    enemyLeader->updateStatsBoost(false);
    stringstream ss;
    ss << "Be aware! Enemy Captain has been enhanced\n"
          "by its followers\n"
          "Current stats boost: " << enemyLeader->getAliveFollowersNumber() * Enemy::BASE_BOOST << "%";
    messageLbl.setString(ss.str());
}

void BattleState::updatePlayerStatsLbl() {
    stringstream ss;
    ss << player->getPlayerStats()->getLevel() << "\n"
       << player->getPlayerStats()->getFinalHp() << "\n"
       << player->getPlayerStats()->getFinalMp() << "\n"
       << player->getPlayerStats()->getFinalDamage() << "\n"
       << player->getPlayerStats()->getFinalArmor() << "\n"
       << player->getPlayerStats()->getFinalCritChance() << "%\n"
       << player->getPlayerStats()->getFinalEvadeChance() << "%\n";
    playerStatsValueLbl.setString(ss.str());
}

void BattleState::updateTurnPanel() {
    stringstream ss;
    if (whoseTurn) {
        ss << "TURN " << turnCount << " : ";
        turnPanelTitle.setString(ss.str());
        ss.str("");
        ss << "Your Turn";
        turnPanelWho.setString(ss.str());
        turnPanelWho.setFillColor(sf::Color(20, 160, 50));
        ss.str("");
        turnPanelLbl.setString("Player is deciding...");
        if (selectedId < 5) {
            ss << "Enemy selected: " << enemiesModels[selectedId]->getName()
               << " Lv." << enemiesModels[selectedId]->getStats()->getLevel();
        } else {
            ss << "Enemy selected: None";
        }
        turnPanelActionLbl.setString(ss.str());
        turnPanel.setFillColor(sf::Color(80, 80, 80));
    } else {
        if (!countPlayerTurnTimer)
            turnPanel.setFillColor(sf::Color(80, 80, 80));
    }
}

void BattleState::updatePageLbl(panel_types type) {
    stringstream ss;
    switch (type) {
        case ACTION_PANEL:
            ss << currentActionPage << " / " << maxActionPage;
            pageLbl.setString(ss.str());
            break;
        case INVENTORY_PANEL:
            ss << currentInvPage << " / " << maxInvPage;
            pageLbl.setString(ss.str());
            break;
        default:
            std::cout << "Unknown panel" << endl;
            break;
    }

}

void BattleState::updateEnemyStatsLbl(const std::shared_ptr<Enemy> &enemy) {
    stringstream ss;
    if (selectedId < 5) {
        ss << enemy->getStats()->getLevel() << "\n"
           << enemy->getStats()->getFinalHp() << "\n"
           << enemy->getStats()->getFinalMp() << "\n"
           << enemy->getStats()->getFinalDamage() << "\n"
           << enemy->getStats()->getFinalArmor() << "\n"
           << enemy->getStats()->getFinalCritChance() << "%\n"
           << enemy->getStats()->getFinalEvadeChance() << "%\n";
    } else {
        ss << "-\n"
           << "-\n"
           << "-\n"
           << "-\n"
           << "-\n"
           << "-%\n"
           << "-%\n";
    }

    enemyStatsValueLbl.setString(ss.str());
}

void BattleState::enableDisableDebugTool() {

}

void BattleState::updateInput(const float &dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && getKeyTime()) {
        if(currentWindowState == PAUSE_MENU)
            currentWindowState = UNPAUSED;
        else
            currentWindowState = PAUSE_MENU;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F12) && getKeyTime()) {
        std::string msg = saveScreenShoot();
        popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG, msg, "", "");
    }
}

void BattleState::updateButtons() {
    actionBtn->update(mousePosView);
    itemActionBtn->update(mousePosView);
    escapeActionBtn->update(mousePosView);
    if (actionBtn->isPressed() && getKeyTime()) {
        currentActionPage = 1;
        currentPanel = ACTION_PANEL;
        updatePageLbl(ACTION_PANEL);
    } else if (itemActionBtn->isPressed() && getKeyTime()) {
        currentInvPage = 1;
        currentPanel = INVENTORY_PANEL;
        updatePageLbl(INVENTORY_PANEL);
    } else if (escapeActionBtn->isPressed() && getKeyTime()) {
        currentPanel = ESCAPE_PANEL;
    }
}

void BattleState::updateMainPanel(const float &dt) {
    switch (currentPanel) {
        case DEFAULT_PANEL:
            break;
        case ACTION_PANEL:
            nextPageBtn->update(mousePosView);
            previousPageBtn->update(mousePosView);
            for (unsigned int i = (currentActionPage - 1) * 4; i < ((currentActionPage - 1) * 4 + 4); i++) {
                if (i < actionRows.size() && i >= 0) {
                    actionRows[i]->update(mousePosView, dt);
                    if (actionRows[i]->isUseBtnPressed() && getKeyTime()) {
                        actionRows[i]->setUseBtnState(BTN_IDLE);
                        playerBattle(i);
                    }
                }
            }
            if (nextPageBtn->isPressed() && getKeyTime()) {
                if (currentActionPage < maxActionPage) {
                    currentActionPage++;
                    updatePageLbl(ACTION_PANEL);
                }
            } else if (previousPageBtn->isPressed() && getKeyTime()) {
                if (currentActionPage <= maxActionPage && currentActionPage > 1) {
                    currentActionPage--;
                    updatePageLbl(ACTION_PANEL);
                }
            }
            break;
        case INVENTORY_PANEL:
            nextPageBtn->update(mousePosView);
            previousPageBtn->update(mousePosView);
            for (int i = (currentInvPage - 1) * 4; i < ((currentInvPage - 1) * 4 + 4); i++) {
                if (i < itemRows.size() && i >= 0){
                    itemRows[i]->update(mousePosView);
                    if (itemRows[i]->isUseBtnPressed() && getKeyTime()) {
                        itemRows[i]->setUseBtnState(BTN_IDLE);
                        if(!potionUsed)
                            useItem(i);
                        else{
                            popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG,
                                                                   "You can only use 1 potion per turn! ", "", "");
                        }
                    }
                }
            }
            if (nextPageBtn->isPressed() && getKeyTime()) {
                if (currentInvPage < maxInvPage) {
                    currentInvPage++;
                    updatePageLbl(INVENTORY_PANEL);
                }
            } else if (previousPageBtn->isPressed() && getKeyTime()) {
                if (currentInvPage <= maxInvPage && currentInvPage > 1) {
                    currentInvPage--;
                    updatePageLbl(INVENTORY_PANEL);
                }
            }
            break;
        case ESCAPE_PANEL:
            escapeConfirmBtn->update(mousePosView);
            if (escapeConfirmBtn->isPressed() && getKeyTime()) {
                escapeConfirmBtn->setButtonState(BTN_IDLE);
                if (whoseTurn) {
                    if (utils::trueFalse(escapeChance * 10.f)) {
                        battleResultEnum = ESCAPED;
                        battleResult->addStatistics(ESCAPE_SUCCESS_COUNT, 1);
                    } else {
                        popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG, "", "You failed to escape!", "");
                        battleResult->addStatistics(ESCAPE_FAIL_COUNT, 1);
                        endPlayerTurn();
                    }
                } else {
                    popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG,
                                                           "Wait for your turn!", "", "");
                }
            }
            break;
    }
}

void BattleState::updatePausedMenuButtons() {
    if(pmenu->isButtonPressed("QUIT") && getKeyTime()){
        battleResultEnum = QUIT_GAME;
        endBattle();
    } else if(pmenu->isButtonPressed("LOAD_SAVE") && getKeyTime()){
        std::cout<<"1";
    }
}

void BattleState::update(const float &dt) {
    updateMousePosition(nullptr);
    updateKeyTime(dt);
    switch(currentWindowState){
        case UNPAUSED:{
            updateInput(dt);
            updateButtons();
            updateEnemyStatsLbl(enemiesModels[selectedId]);
            updateTurnPanel();
            if (countPlayerTurnTimer) {
                if (turnLengthKeyTime < turnLengthMaxKeyTime){
                    turnLengthKeyTime += 15.f * dt;
                    playerStatusPanel->setShapeOutlineThickness(5.f);
                } else {
                    turnLengthKeyTime = 0.f;
                    countPlayerTurnTimer = false;
                    playerStatusPanel->setShapeOutlineThickness(0.f);
                }
            } else {
                if(battleResultEnum != NOT_FINISHED){
                    endBattle();
                    return;
                } else if (!whoseTurn){
                    enemyBattle(dt);
                }
            }
            playerModel->update(dt);
            for (const auto &i : enemiesModels) {
                i->update(dt);
            }
            playerStatusPanel->update(mousePosView);
            for (unsigned int i = 0; i < enemiesModels.size(); i++) {
                if(!enemiesModels[i]->isDead())
                    enemiesStatusPanel[i]->update(mousePosView, dt,selectedId,
                                                 enemiesMoves == 10 || enemiesMoves == 0 ? 10 : enemiesMoveOrder[enemiesMoves - 1],
                                                 countPlayerTurnTimer);
            }

            buffComponent->update(dt, mousePosView);
            popUpTextComponent->update(dt);
            updateMainPanel(dt);
            break;
        }
        case PAUSE_MENU:{
            updateInput(dt);
            pmenu->update(mousePosView);
            updatePausedMenuButtons();
            break;
        }
        case BATTLE_REPORT:{
            popUpTextComponent->update(dt);
            continueBtn->update(mousePosView);
            if(continueBtn->isPressed() && getKeyTime()){
                endState();
            }
            break;
        }
    }

}

void BattleState::render(sf::RenderTarget *target) {
    if (!target) {
        target = window.get();
    }

    target->draw(background);
    target->draw(mainActionPanel);
    target->draw(tipsLbl);
    target->draw(playerStatsPanel);
    target->draw(playerStatsPanelTitle);
    target->draw(playerStatsNameLbl);
    target->draw(playerStatsValueLbl);
    target->draw(enemyStatsPanel);
    target->draw(enemyStatsPanelTitle);
    target->draw(enemyStatsNameLbl);
    target->draw(enemyStatsValueLbl);
    target->draw(turnPanel);
    target->draw(turnPanelTitle);
    target->draw(turnPanelWho);
    target->draw(turnPanelLbl);
    target->draw(turnPanelActionLbl);
    if(enemyCount > 1)
        target->draw(messageLbl);
    actionBtn->render(*target);
    itemActionBtn->render(*target);
    escapeActionBtn->render(*target);

    switch (currentPanel) {
            case DEFAULT_PANEL:
                break;
            case ACTION_PANEL:
                target->draw(actionPanel);
                target->draw(pageLbl);
                nextPageBtn->render(*target);
                previousPageBtn->render(*target);
                for (int i = (currentActionPage - 1) * 4; i < ((currentActionPage - 1) * 4 + 4); i++) {
                    if (i < actionRows.size() && i >= 0)
                        actionRows[i]->render(*target);
                }
                break;
            case INVENTORY_PANEL:
                target->draw(itemActionPanel);
                target->draw(pageLbl);
                nextPageBtn->render(*target);
                previousPageBtn->render(*target);
                for (int i = (currentInvPage - 1) * 4; i < ((currentInvPage - 1) * 4 + 4); i++) {
                    if (i < itemRows.size() && i >= 0)
                        itemRows[i]->render(*target);
                }
                break;
            case ESCAPE_PANEL:
                target->draw(escapeActionPanel);
                target->draw(escapeText);
                escapeConfirmBtn->render(*target);
                break;
        }

    playerModel->render(*target);
    for (const auto &i : enemiesModels) {
        i->render(*target, nullptr, player->getCenter());
    }
    target->draw(playerPos);
    for (const auto &i : enemyPos)
        target->draw(i);
    for (unsigned int i = 0; i < enemiesModels.size(); i++) {
        if(!enemiesModels[i]->isDead())
            enemiesStatusPanel[i]->render(*target);
    }
    buffComponent->render(*target);

    switch(currentWindowState){
        case UNPAUSED:
            playerStatusPanel->render(*target);
            break;
        case PAUSE_MENU:
            playerStatusPanel->render(*target);
            pmenu->render(*target);
            break;
        case BATTLE_REPORT:
            target->draw(resultBackground);
            target->draw(resultContainer);
            target->draw(resultTitleLbl);
            target->draw(resultTextLbl);
            continueBtn->render(*target);
            break;
    }
    popUpTextComponent->render(*target);

 /*   //tool per il debug : mostre le coordinate del mouse
    sf::Text mouseText;
    mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 15);
    mouseText.setFont(*font);
    mouseText.setCharacterSize(14);
    std::stringstream ss;
    ss << this->mousePosView.x << " " << this->mousePosView.y;
    mouseText.setString(ss.str());
    target->draw(mouseText);*/
}










































