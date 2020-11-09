//
// Created by Leonardo on 09/11/2020.
//

#include "BattleState.h"

bool BattleState::battle() {
    bool playerWin = false;
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
        return false;
}

void BattleState::dropItem(int enemyIndex) {
    Generator gen = Generator();
    drops[killCounter] = gen.generateItem(floor, enemies[enemyIndex]);  //Generate ITEM
    this->player->getInventory()->items.push_back(&drops[killCounter]);
}

bool BattleState::enemyTurn(int enemyIndex) {

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

    return false;
}

bool BattleState::playerTurn() {

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
        return false;
}

BattleState::BattleState(Player* player, Enemy *enemies, int enemyCount, int floor) {
    this->player = player;
    this->enemyCount = enemyCount;
    this->floor = floor;

    for(int i=0; i<enemyCount; i++){
        this->enemies[i] = enemies[i];
    }

}