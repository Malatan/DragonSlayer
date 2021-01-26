#include "BattleAI.h"


BattleAI::BattleAI(std::shared_ptr<Enemy> currentEnemy, std::shared_ptr<Player> player) {
    this->currentEnemy = currentEnemy;
    this->player = player;
}

int BattleAI::behaviour(){
    int result = 0;

    if((currentEnemy->getStats()->getHp()*100)/currentEnemy->getStats()->getFinalHp() < 40) {   //mob hp less than 40%
        if(currentEnemy->getStats()->getMobHealSpell() > 0){  //Enemy has heal spell
            if(currentEnemy->getCd() == 0) {
                result = 1; //HEAL SPELL
            }else if(currentEnemy->getStats()->getMobHealPotions() > 0){
                    result = 2; //HEAL POTION
            }else{
                result = 0; //ATTACK
            }
        }else{  //Enemy has NO heal spell
            if(currentEnemy->getStats()->getMobHealPotions() > 0){
                result = 2; //HEAL POTION
            }else{
                result = 0; //ATTACK
            }
        }
    }else{
        result = 0;
    }

    return result;
}