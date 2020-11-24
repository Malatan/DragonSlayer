//
// Created by Leonardo on 09/11/2020.
//

#include "BattleState.h"

#include <utility>

bool BattleState::battle() {
  /*  bool playerWin = false;
    bool enemyWin = false;
    int turn = 0;

    while (playerWin == false && enemyWin == false){
        if(turn == 0) {
            cout<<"-----------------------------------------"<<endl;
            cout<<"-----------------------------------------"<<endl;
            cout<<player->playerDetails();           //Player STATS
            for(int i=0; i<enemyCount; i++){         //Enemies STATS
                if(enemies[i].getName() != "")
                    cout<<enemies[i].enemyDetails();
            }
            cout<<"----------------------- YOUR TURN"<<endl;
            playerWin = BattleState::playerTurn();       //Player TURN
            turn = 1;
            player->refreshSpells();    //refresh Spells cooldown
        } else {
            for(int i=0; i<enemyCount; i++) {        //Enemies TURN
                if(enemies[i].getName() != "")
                {
                    if(enemies[i].getHp() > 0){         //Check which enemies are ALIVE
                        cout << "---------------------- "<<enemies[i].getName()<<" turn"<<endl;
                        enemyWin = BattleState::enemyTurn(i);
                    }
                }
            }
            turn = 0;
        }
    }

    if(playerWin) {
        cout<<"You dropped: "<<endl;

        for(auto i : this->player->getInventory()->items){  //Show drops
            if(i->getIsNew()){
                cout<<i->listItem()<<endl;
            }
        }
        return true;
    }else
        return false;*/
}

void BattleState::dropItem(int enemyIndex) {
  /*  Generator gen = Generator();
    drops[killCounter] = gen.generateItem(floor, enemies[enemyIndex]);  //Generate ITEM
    this->player->getInventory()->items.push_back(&drops[killCounter]);*/
}

bool BattleState::enemyTurn(int enemyIndex) {
/*
    int playerEvade = rand() % 100;
    if (playerEvade <= player->getPlayerStats()->getFinalEvadeChance()*100) {       //Player succeed EVADE
        cout << "You evade "<<enemies[enemyIndex].getName()<< " attack" << endl;
    } else {
        int damage = enemies[enemyIndex].getDamage();
        damage = player->takeDamage(damage);    //Player take dmg
        cout<<enemies[enemyIndex].getName()<<" hits you - "<<damage<<"dmg"<<endl;
        if (player->getPlayerStats()->getHp() <= 0){
            cout<<"You was defeated"<<endl;
            return true;
        }
    }

    return false;*/
}

bool BattleState::playerTurn() {
/*
    int choose;
    bool done = false;  //TRUE if player has done an ACTION
    bool result;
    while(!done){

        cout<<" 1 - ATTACK"<<endl;
        cout<<" 2 - SPELL"<<endl;
        cout<<" 3 - ITEM"<<endl;
        cout<<" 4 - ESCAPE"<<endl;
        cout<<"    -> ";
        cin>>choose;

        switch (choose) {
            case 1: {   //ATTACK

                int target;
                if((enemyCount - killCounter) != 1){           //IF multiple enemies ALIVE

                    cout<<"CHOOSE ENEMY: \n";
                    for(int i=0; i<enemyCount; i++){
                        if(enemies[i].getName() != "")
                            cout<<i+1<<")"<<enemies[i].getName()<<endl;
                    }
                    cout<<"    -> ";
                    cin>>target;
                    target --;
                }else{                  //ONE enemy ALIVE
                    for(int i=0; i<enemyCount; i++){
                        if(enemies[i].getHp() > 0)
                            target = i;
                    }
                }

                int enemyEvade = rand() % 100;
                if (enemyEvade <= enemies[target].getEvadeChance()*100) {       //Enemy succeed EVADE
                    cout <<enemies[target].getName()<<" evades your attack"<< endl;
                } else {

                    int damage = player->getPlayerStats()->getFinalDamage();
                    int playerCrit = rand() % 100;
                    if (playerCrit <= player->getPlayerStats()->getFinalCritChance()*100)     //Player succeed CRIT ATTACK
                    {
                        damage = damage + (damage / 2);   //Critical dmg applied
                    }
                    damage = enemies[target].takeDamage(damage);
                    cout<<"You hit "<<enemies[target].getName()<<" - "<<damage<<"dmg"<<endl;

                    if (enemies[target].getHp() <= 0){
                        BattleState::dropItem(target);     //Enemy drop
                        this->killCounter++;
                        cout<<enemies[target].getName()<<" defeated"<<endl;
                    }

                    if(checkWin()) {
                        return true;
                    }
                }

                done = true;
                break;
            }
            case 2: {   //SPELL
                int spell;
                cout<<player->listSpells();
                cout<<"    -> ";
                cin>>spell;
                spell--;

                if(player->getSpellbyIndex(spell)->getReady() == 0){      //IF cooldown NOT activated
                    if(player->getPlayerStats()->getMp() >= player->getSpellbyIndex(spell)->getCost()){     //IF enough MP

                        if(player->getSpellbyIndex(spell)->getAoe() < (enemyCount - killCounter)){     //IF player can choose multiple TARGETS

                            int targets[player->getSpellbyIndex(spell)->getAoe()];
                            int targetCount = 0;
                            int target;
                            bool targetCheck = true;

                            while(targetCount != player->getSpellbyIndex(spell)->getAoe())      //Choose TARGETS
                            {
                                targetCheck = true;
                                cout<<"CHOOSE ENEMY: \n";
                                for(int i=0; i<enemyCount; i++){
                                    if(enemies[i].getName() != "")
                                        cout<<i+1<<")"<<enemies[i].getName()<<endl;
                                }
                                cout<<"    -> ";
                                cin>>targets[targetCount];
                                targets[targetCount] --;

                                for (int j=0; j<targetCount; j++){  //Check IF already targetted
                                    if(targets[targetCount] == targets[j]){
                                        targetCheck = false;
                                    }
                                }

                                if(targetCheck){
                                    targetCount++;
                                }else{
                                    cout<<"Enemy already targetted"<<endl;
                                }
                            }

                            int damage = player->getSpellbyIndex(spell)->getDamage();

                            for(int i=0; i<player->getSpellbyIndex(spell)->getAoe(); i++)   //Enemies take dmg
                            {
                                enemies[(targets[i])].takeSpellDamage(damage);
                                cout<<"You hit "<<enemies[(targets[i])].getName()<<" - "<<damage<<"dmg"<<endl;

                                if (enemies[(targets[i])].getHp() <= 0){
                                    BattleState::dropItem( (targets[i]));     //Enemy drop
                                    this->killCounter++;
                                    cout<<enemies[(targets[i])].getName()<<" defeated"<<endl;
                                }
                            }
                            if(checkWin())
                                return true;
                        }else{                  //IF spell hits all enemies alive -> NO need to choose targets

                            int damage = player->getSpellbyIndex(spell)->getDamage();

                            for(int i=0; i<enemyCount; i++)     //Enemies take dmg
                            {
                                if(enemies[i].getHp() > 0)
                                {
                                    enemies[i].takeSpellDamage(damage);
                                    cout<<"You hit "<<enemies[i].getName()<<" - "<<damage<<"dmg"<<endl;

                                    if (enemies[i].getHp() <= 0){
                                        BattleState::dropItem(i);     //Enemy drop
                                        this->killCounter++;
                                        cout<<enemies[i].getName()<<" defeated"<<endl;
                                    }
                                }

                            }
                        }

                        player->getSpellbyIndex(spell)->setReady(player->getSpellbyIndex(spell)->getCooldown());  //Spell cooldown ACTIVATED
                        player->useSpell(player->getSpellbyIndex(spell)->getName());        //Spell consume MP

                        if(checkWin())
                            return true;

                        done = true;
                    }else{
                        cout<<"You don't have enough MP"<<endl;
                    }
                }else{
                    cout<<"Spell's cooldown still active"<<endl;
                }
                break;
            }
            case 3: {   //ITEMS

                int item;
                cout<<player->getInventory()->listConsumabiles();
                cout<<"    -> ";
                cin>>item;

                if(player->getInventory()->getItem(item)->getName() == "Health Potion"){        //Health Potion
                    player->heal(50);                    //Item EFFECT
                    player->useItem("Health Potion");   //update Item QUANTITY

                    cout<<"Heal 50 hp"<<endl;
                    cout<<player->playerDetails();
                }

                done = true;
                break;
            }
            case 4: {   //ESCAPE
                int playerEscape = rand() % 100;

                if (playerEscape <= player->getPlayerStats()->getFinalEvadeChance()*100) {      //Player succeed ESCAPE
                    cout << "You escape" << endl;
                    return true;
                } else {
                    cout << "Failed to escape" << endl;
                }

                done = true;
                break;
            }
            default:
                break;
        }
    }
    return false;
}


bool BattleState::checkWin() {
    bool win = true;
    for(int i=0; i<enemyCount; i++){
        if(enemies[i].getHp() > 0) {    //IF a enemy is ALIVE
            win = false;
        }
    }
    if(win)
        return true;
    else
        return false;*/
}

void BattleState::initResources() {
    rsHandler->addResouce("../Resources/Images/Backgrounds/battleBG.png", "battleBG", "BattleState");
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

}

void BattleState::initEscapePanel() {
    escapeActionPanel.setPosition(actionPanel.getPosition());
    escapeActionPanel.setFillColor(sf::Color(150, 150, 150));
    escapeActionPanel.setSize(actionPanel.getSize());
    escapeText.setFont(*this->font);
    stringstream ss;
    int highestAgility = 0;
    for(auto i : enemiesModels){
        if(i->getAgility() > highestAgility)
            highestAgility = i->getAgility();
    }
    escapeChance = player->getPlayerStats()->getAgility() - highestAgility;
    if(escapeChance <= 0.f)
        escapeChance = 1.5f;
    if(escapeChance > 10.f)
        escapeChance = 10.f;

    ss << "Are you sure you want to ESCAPE?" << endl <<
          "Your agility is " << player->getPlayerStats()->getAgility() << endl <<
          "Enemy's highest agility is " << highestAgility << endl <<
          "You will have " << escapeChance*10.f << " % to escape successfully";
    escapeText.setString(ss.str());
    escapeText.setCharacterSize(25);
    escapeText.setPosition(escapeActionPanel.getPosition().x + 10.f, escapeActionPanel.getPosition().y + 10.f);

    escapeConfirmBtn.setPosition(escapeActionPanel.getPosition().x + escapeActionPanel.getGlobalBounds().width/2.f -
            escapeConfirmBtn.getGlobalBounds().width/2.f,
            escapeActionPanel.getPosition().y + 200.f);
}

void BattleState::spawnEnemy(sf::Vector2f pos, enemy_types type, bool generateStats) {
    std::shared_ptr<Enemy> enemy;
    switch(type){
        case WITCH:
            enemy = std::make_shared<Enemy>(WITCH, pos.x, pos.y, -3.2f, 3.2f,
                              0.f, 0.f, 0.f, 0.f,
                              0.f, 0.f, 0.f,
                              textures["ENEMY_WIZARD_SHEET"], 0);
            enemy->setOrigin(125.f, 167.f);
            if(generateStats)
                enemy->generateEnemyStats(floor);
            enemiesModels.push_back(enemy);
            break;
        case SKELETON:
            enemy = std::make_shared<Enemy>(SKELETON, pos.x, pos.y, -4.f, 4.f,
                             0.f, 0.f, 0.f, 0.f,
                             0.f, 0.f, 0.f,
                             textures["ENEMY_SKELETON_SHEET"], 0);
            enemy->setOrigin(12.f, 32.f);
            if(generateStats)
                enemy->generateEnemyStats(floor);
            enemiesModels.push_back(enemy);
            break;
        case SKELETON_2:
            enemy = std::make_shared<Enemy>(SKELETON_2, pos.x, pos.y, -3.2f, 3.2f,
                              0.f, 0.f, 0.f, 0.f,
                              0.f, 0.f, 0.f,
                              textures["ENEMY_SKELETON_2_SHEET"], 0);
            enemy->setOrigin(75.f, 100.f);
            if(generateStats)
                enemy->generateEnemyStats(floor);
            enemiesModels.push_back(enemy);
            break;
        case FLYING_EYE:
            enemy = std::make_shared<Enemy>(FLYING_EYE, pos.x, pos.y, -3.3f, 3.3f,
                              0.f, 0.f, 0.f, 0.f,
                              0.f, 0.f, 0.f,
                              textures["ENEMY_FLYINGEYE_SHEET"], 0);
            enemy->setOrigin(75.f, 110.f);
            if(generateStats)
                enemy->generateEnemyStats(floor);
            enemiesModels.push_back(enemy);
            break;
        case GOBLIN:
            enemy = std::make_shared<Enemy>(GOBLIN, pos.x, pos.y, -3.0f, 3.0f,
                              0.f, 0.f, 0.f, 0.f,
                              0.f, 0.f, 0.f,
                              textures["ENEMY_GOBLIN_SHEET"], 0);
            enemy->setOrigin(75.f, 100.f);
            if(generateStats)
                enemy->generateEnemyStats(floor);
            enemiesModels.push_back(enemy);
            break;
        case MUSHROOM:
            enemy = std::make_shared<Enemy>(MUSHROOM, pos.x, pos.y, -3.4f, 3.4f,
                              0.f, 0.f, 0.f, 0.f,
                              0.f, 0.f, 0.f,
                              textures["ENEMY_MUSHROOM_SHEET"], 0);
            enemy->setOrigin(75.f, 100.f);
            if(generateStats)
                enemy->generateEnemyStats(floor);
            enemiesModels.push_back(enemy);
            break;
        case BANDIT_HEAVY:
            enemy = std::make_shared<Enemy>(BANDIT_HEAVY, pos.x, pos.y, 4.3f, 4.3f,
                              0.f, 0.f, 0.f, 0.f,
                              0.f, 0.f, 0.f,
                              textures["ENEMY_BANDITHEAVY_SHEET"], 0);
            enemy->setOrigin(24.f, 46.f);
            if(generateStats)
                enemy->generateEnemyStats(floor);
            enemiesModels.push_back(enemy);
            break;
        case BANDIT_LIGHT:
            enemy = std::make_shared<Enemy>(BANDIT_LIGHT, pos.x, pos.y, 4.f, 4.f,
                              0.f, 0.f, 0.f, 0.f,
                              0.f, 0.f, 0.f,
                              textures["ENEMY_BANDITLIGHT_SHEET"], 0);
            enemy->setOrigin(24.f, 46.f);
            if(generateStats)
                enemy->generateEnemyStats(floor);
            enemiesModels.push_back(enemy);
            break;
        default:
            std::cout<<"No such enemy: " << type;
            break;
    }
}

void BattleState::generateModels(Enemy* enemy) {
    playerModel = new Player(220.f, 300.f, 5.f, 5.f,textures["PLAYER_SHEET"]);
    playerModel->setOrigin(20, 33);
    playerModel->setPosition(220.f,475.f);
    int enemyNumber = utils::generateRandomNumber(1, 5, false);
    std::vector<int> enemyEnums = utils::generateRandomNumbers(0, 7, enemyNumber-1, false);

    spawnEnemy(enemyPos[0].getPosition(), enemy->getType(), false);
    enemiesModels[0]->copyStats(enemy);

    for(int i = 0 ; i < enemyEnums.size() ; i++){
            spawnEnemy(enemyPos[i+1].getPosition(), static_cast<enemy_types>(enemyEnums[i]), true);
    }

    for(int i = 0 ; i < enemiesModels.size() ; i++){
        enemiesStatusPanel[i] = gui::EnemyStatusPanel(enemiesModels[i], enemyPos[i].getPosition().x,
                enemyPos[i].getPosition().y - 200.f, font, textures["ARROWDOWN_ICON"], this, i);
    }

    playerStatusPanel = gui::PlayerStatusPanel(player, playerPos.getPosition().x,
            playerPos.getPosition().y - playerModel->getGlobalBounds().height - 150.f, font);

    for(const auto& i : enemiesModels)
        std::cout<<i->toString()<<endl;

  /*spawnEnemy(enemyPos[1].getPosition(), GOBLIN);
    spawnEnemy(enemyPos[2].getPosition(), SKELETON);
    spawnEnemy(enemyPos[3].getPosition(), SKELETON_2);
    spawnEnemy(enemyPos[4].getPosition(), FLYING_EYE);*/
}

void BattleState::initButtons() {
    sf::Color text_idle_color = sf::Color(71, 17, 13,250);
    sf::Color text_hover_color = sf::Color(250, 250, 250, 250);
    sf::Color text_active_color = sf::Color(20, 20, 20, 50);

    sf::Color hover_color = sf::Color(150, 150, 150, 0);
    sf::Color active_color = sf::Color(20, 20, 20, 0);

    actionBtn = gui::Button(10.f, mainActionPanel.getPosition().y + 10.f, 250.f, 50.f,
                            font, "Action", 40,
                            text_idle_color ,text_hover_color, text_active_color,
                            sf::Color(50, 50, 50), hover_color, active_color);
    itemActionBtn = gui::Button(10.f, mainActionPanel.getPosition().y + 60.f, 250.f, 50.f,
                            font, "Inventory", 40,
                            text_idle_color ,text_hover_color, text_active_color,
                            sf::Color(100, 100, 100), hover_color, active_color);
    escapeActionBtn = gui::Button(10.f, mainActionPanel.getPosition().y + 110.f, 250.f, 50.f,
                            font, "Escape", 40,
                            text_idle_color ,text_hover_color, text_active_color,
                            sf::Color(150, 150, 150), hover_color, active_color);

    escapeConfirmBtn = gui::Button(10.f, 10.f, 500.f, 80.f,
                                  font, "Raaaaaaan!!!", 40,
                                  text_idle_color ,text_hover_color, text_active_color,
                                  sf::Color(150, 150, 150), hover_color, active_color);
}

BattleState::BattleState(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Player> player, std::stack<std::unique_ptr<State>>* states,
        std::shared_ptr<PopUpTextComponent> popUpTextComponent, std::shared_ptr<ResourcesHandler> rsHandler, std::map<std::string, sf::Texture> textures,
        sf::Font *font, Enemy* enemy, int floor) : State(std::move(window), states, std::move(rsHandler)){
    this->player = std::move(player);
    this->textures = std::move(textures);
    this->popUpTextComponent = std::move(popUpTextComponent);
    this->font = font;
    this->floor = floor;
    this->selectedId = 10;
    currentPanel = 0;

    initResources();
    initBattleFieldComponents();
    generateModels(enemy);

    background.setSize(sf::Vector2f(
            static_cast<float>(this->window->getSize().x),
            static_cast<float>(this->window->getSize().y)));
    backgroundTexture.loadFromImage(this->rsHandler->getResouceByKey("battleBG")->getImage());
    background.setTexture(&backgroundTexture);
    mainActionPanel.setSize(sf::Vector2f(
            static_cast<float>(this->window->getSize().x),
            300.f));
    mainActionPanel.setPosition(0.f, static_cast<float>(this->window->getSize().y - 300.f));
    mainActionPanel.setFillColor(sf::Color(80, 80, 80));
    initButtons();
    actionPanel.setPosition(actionBtn.getPosition().x + 250.f , actionBtn.getPosition().y);
    actionPanel.setFillColor(sf::Color(50, 50, 50));
    actionPanel.setSize(sf::Vector2f(
            static_cast<float>(this->window->getSize().x) - 270.f,
            280.f));
    itemActionPanel.setPosition(actionPanel.getPosition());
    itemActionPanel.setFillColor(sf::Color(100, 100, 100));
    itemActionPanel.setSize(actionPanel.getSize());
    initEscapePanel();

  /*  this->player = player;
    this->enemyCount = enemyCount;
    this->floor = floor;

    for(int i=0; i<enemyCount; i++){
        this->enemies[i] = enemies[i];
    }
*/
}

BattleState::~BattleState() {
    delete playerModel;
}

void BattleState::updateInput(const float &dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && getKeyTime()) {
        endState();
        playerModel->setOrigin(player->getGlobalBounds().width/2.f, playerModel->getGlobalBounds().height/2.f);
    }else  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && getKeyTime()) {

    }else  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && getKeyTime()) {

    }
}

void BattleState::updateButtons() {
    actionBtn.update(mousePosView);
    itemActionBtn.update(mousePosView);
    escapeActionBtn.update(mousePosView);
    if(actionBtn.isPressed() && getKeyTime()){
        currentPanel = 1;
    }else if(itemActionBtn.isPressed() && getKeyTime()){
        currentPanel = 2;
    }else if(escapeActionBtn.isPressed() && getKeyTime()){
        currentPanel = 3;
    }
}

void BattleState::update(const float &dt) {
    updateInput(dt);
    updateKeyTime(dt);
    updateMousePosition();
    updateButtons();
    playerModel->update(dt);
    for(const auto& i : enemiesModels){
        i->update(dt);
    }
    playerStatusPanel.update(mousePosView);

    for(int i = 0 ; i < enemiesModels.size() ; i++){
        enemiesStatusPanel[i].update(mousePosView, dt, selectedId);
    }
    popUpTextComponent->update(dt);
    switch(currentPanel){
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            escapeConfirmBtn.update(mousePosView);
            if(escapeConfirmBtn.isPressed() && getKeyTime()){
                if(utils::trueFalse(escapeChance*10.f, false)){
                    endState();
                }else{
                    popUpTextComponent->addPopUpTextCenter(DEFAULT_TAG, "", "You failed to escape!", "");
                }
            }
            break;
    }
}

void BattleState::render(sf::RenderTarget *target) {
    if(!target){
        target = window.get();
    }

    target->draw(background);
    target->draw(mainActionPanel);
    actionBtn.render(*target);
    itemActionBtn.render(*target);
    escapeActionBtn.render(*target);

    switch(currentPanel){
        case 0:
            break;
        case 1:
            target->draw(actionPanel);
            break;
        case 2:
            target->draw(itemActionPanel);
            break;
        case 3:
            target->draw(escapeActionPanel);
            target->draw(escapeText);
            escapeConfirmBtn.render(*target);
            break;
    }

    playerModel->render(*target);
    for(const auto& i : enemiesModels){
        i->render(*target, true);
    }

    target->draw(playerPos);
    playerStatusPanel.render(*target);
    for(const auto& i : enemyPos)
        target->draw(i);
    for(int i = 0 ; i < enemiesModels.size() ; i++){
        enemiesStatusPanel[i].render(*target);
    }



    popUpTextComponent->render(*target);
      //tool per il debug : mostre le coordinate del mouse
    sf::Text mouseText;
    mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 15);
    mouseText.setFont(*font);
    mouseText.setCharacterSize(14);
    std::stringstream ss;
    ss << this->mousePosView.x << " " << this->mousePosView.y;
    mouseText.setString(ss.str());
    target->draw(mouseText);
}












