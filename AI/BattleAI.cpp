#include "BattleAI.h"


BattleAI::BattleAI(std::shared_ptr<Player> player, std::vector<std::shared_ptr<Enemy>> enemies, std::vector<unsigned int> enemiesOrder, unsigned int current, std::shared_ptr<PopUpTextComponent> popUpTextComponent) {
    this->player = player;
    this->enemies = enemies;
    this->enemiesOrder = enemiesOrder;
    this->current = current;
    this->popUpTextComponent = popUpTextComponent;
}

int BattleAI::behaviour(){
    int action = 0;
    bool done = false;
    int ctr = enemies.size();

    if(player->getPlayerStats()->getHp() < 25){     //If Player might die with attack -> priority attack Player
            action = 0; //ATTACK
            done = true;
    }

    if(!done) {     //If Current Enemy has < 40% HP -> priority heal Current Enemy
        if ((enemies[enemiesOrder[current - 1]]->getStats()->getHp() * 100) /enemies[enemiesOrder[current - 1]]->getStats()->getFinalHp() < 40) {   //mob hp less than 40%
            if (enemies[enemiesOrder[current - 1]]->getStats()->getMobHealSpell() > 0) {  //Enemy has heal spell
                if (enemies[enemiesOrder[current - 1]]->getCd() == 0 && enemies[enemiesOrder[current - 1]]->getStats()->getFinalMp() >= 250) {    //Spell avaiable
                    // HEAL SPELL
                    enemies[enemiesOrder[current - 1]]->getStats()->gainHp(100);
                    enemies[enemiesOrder[current - 1]]->getStats()->consumeMana(250);
                    enemies[enemiesOrder[current - 1]]->setCd(enemies[enemiesOrder[current - 1]]->getStats()->getMobHealSpell() +1); //Set healSpell Cooldown

                    popUpTextComponent->addPopUpText(DEFAULT_TAG,
                                                     enemies[enemiesOrder[current - 1]]->getPosition().x,
                                                     enemies[enemiesOrder[current - 1]]->getPosition().y - 100.f,
                                                     "HEALED", "", "");

                    action = 1;
                    done = true;
                } else if (enemies[enemiesOrder[current - 1]]->getStats()->getMobHealPotions() > 0) {    //Got Potions
                    //HEAL POTION
                    enemies[enemiesOrder[current - 1]]->getStats()->gainHp(50);
                    enemies[enemiesOrder[current - 1]]->getStats()->setMobHealPotions(
                            enemies[enemiesOrder[current - 1]]->getStats()->getMobHealPotions() - 1);   //Update potions cont

                    action = 2;
                    done = true;
                }
            } else if (enemies[enemiesOrder[current - 1]]->getStats()->getMobHealPotions() > 0) {    //Enemy has NO heal spell and Got Potions
                //HEAL POTION
                enemies[enemiesOrder[current - 1]]->getStats()->gainHp(50);
                enemies[enemiesOrder[current - 1]]->getStats()->setMobHealPotions(
                        enemies[enemiesOrder[current - 1]]->getStats()->getMobHealPotions() - 1);   //Update potions cont

                action = 2;
                done = true;
            }
        }
    }



    if(!done){  //If another Enemy has < 40% HP -> priority heal other Enemy
        if (enemies[enemiesOrder[current - 1]]->getStats()->getMobHealSpell() > 0) {  //If Current Enemy has heal spell
            if (enemies[enemiesOrder[current - 1]]->getCd() == 0 && enemies[enemiesOrder[current - 1]]->getStats()->getFinalMp() >= 250) {    //Spell avaiable
                for (auto enemy : enemies) {
                    if(ctr != current && !done){
                        if (!enemy->isDead() && (enemy->getStats()->getHp() * 100) / enemy->getStats()->getFinalHp() < 40 ) {  //mob hp less than 40%
                            //HEAL SPELL
                            enemy->getStats()->gainHp(100);
                            enemies[enemiesOrder[current - 1]]->getStats()->consumeMana(250);
                            enemies[enemiesOrder[current - 1]]->setCd(enemies[enemiesOrder[current - 1]]->getStats()->getMobHealSpell() +1); //Set healSpell Cooldown

                            popUpTextComponent->addPopUpText(DEFAULT_TAG,
                                                             enemy->getPosition().x,
                                                             enemy->getPosition().y - 100.f,
                                                             "HEALED", "", "");

                            action = 1;
                            done = true;
                        }
                    }
                    ctr--;
                }
            }
        }
    }

    if(!done){
        action = 0;
        done = true;
    }

    return action;
}