//
// Created by Leonardo on 09/11/2020.
//
#include "Generator.h"

Item Generator::generateItem(int floor, unsigned int enemy_level) {

    Item i;

    //Rarity: COMMON - UNCOMMON - RARE - EPIC - LEGGENDARY
    //CALCOLO RARITA'
    double gen = utils::generateRandomNumber(1, 10);
    double mul = 1 + 1/gen;
    double rarity =  enemy_level * floor * mul;
    double doubleGold = rarity;

    if(rarity < 10){
        i.setRarity("Common");
        rarity = 10;    //aggiorno la variabile che verrà usata poi per calcolare danni/armor dell'oggeto in base a rarità
    }else if(rarity >= 10 && rarity <20){
        i.setRarity("Uncommon");
        rarity = 20;
    }else if(rarity >= 20 && rarity <30){
        i.setRarity("Rare");
        rarity = 30;
    }else if(rarity >= 30 && rarity <40){
        i.setRarity("Epic");
        rarity = 40;
    }else if(rarity > 40){
        i.setRarity("Leggendary");
        rarity = 50;
    }

    //SET VALUE
    doubleGold = doubleGold + 0.5 - (doubleGold<0); //arrotondamento
    int gold = (int) doubleGold;
    i.setValue(gold);


    //GENERO TIPOLOGIA CASUALE

    int type = utils::generateRandomNumber(0, 9);    //tra 0 e 9
    gen = utils::generateRandomNumber(1, 10);
    mul = 1 + (1/gen);      //reset moltiplicatore statistiche

    if(type < 5){           //WEAPON

        int weaponType = utils::generateRandomNumber(0, 2);   // 3 TIPI DI ARMI PRESENTI NEL GIOCO -> aggiungibili

        if(weaponType == 0){            //SWORD
            i.setItemType("sword");

            if(rarity == 10){           //COMMON
                i.setName("Common Sword");
            }else if(rarity == 20){     //UNCOMMON
                i.setName("Uncommon Sword");
            }else if(rarity == 30){     //RARE
                i.setName("Rare Sword");
            }else if(rarity == 40){     //EPIC
                i.setName("Epic Sword");
            }else{                      //LEGGENDARY
                i.setName("Leggendary Sword");
            }

            //GENERA STATISTICHE
            double doubleDmg = (5 + rarity) * mul;
            doubleDmg = doubleDmg + 0.5 - (doubleDmg<0);
            int dmg = (int) doubleDmg;
            i.setDamage(dmg);

        }else if(weaponType == 1){      //BOW
            i.setItemType("bow");

            if(rarity == 10){           //COMMON
                i.setName("Common Bow");
            }else if(rarity == 20){     //UNCOMMON
                i.setName("Uncommon Bow");
            }else if(rarity == 30){     //RARE
                i.setName("Rare Bow");
            }else if(rarity == 40){     //EPIC
                i.setName("Epic Bow");
            }else{                      //LEGGENDARY
                i.setName("Leggendary Bow");
            }

            //GENERA STATISTICHE
            double doubleDmg = (8 + rarity) * mul;
            doubleDmg = doubleDmg + 0.5 - (doubleDmg<0);
            int dmg = (int) doubleDmg;
            i.setDamage(dmg);

        }else if(weaponType == 2){      //AXE
            i.setItemType("axe");

            if(rarity == 10){           //COMMON
                i.setName("Common Axe");
            }else if(rarity == 20){     //UNCOMMON
                i.setName("Uncommon Axe");
            }else if(rarity == 30){     //RARE
                i.setName("Rare Axe");
            }else if(rarity == 40){     //EPIC
                i.setName("Epic Axe");
            }else{                      //LEGGENDARY
                i.setName("Leggendary Axe");
            }

            //GENERA STATISTICHE
            double doubleDmg = (4 + rarity) * mul;
            doubleDmg = doubleDmg + 0.5 - (doubleDmg<0);
            int dmg = (int) doubleDmg;
            i.setDamage(dmg);

        }

    }else if(type == 5){    //SHIELD
        i.setItemType("shield");

        if(rarity == 10){           //COMMON
            i.setName("Common Shield");
        }else if(rarity == 20){     //UNCOMMON
            i.setName("Uncommon Shield");
        }else if(rarity == 30){     //RARE
            i.setName("Rare Shield");
        }else if(rarity == 40){     //EPIC
            i.setName("Epic Shield");
        }else{                      //LEGGENDARY
            i.setName("Leggendary Shield");
        }

        //GENERA STATISTICHE
        double doubleArmor = (10 + rarity) * mul;
        doubleArmor = doubleArmor + 0.5 - (doubleArmor<0);
        int armor = (int) doubleArmor;
        i.setArmor(armor);

    }else if(type == 6){    //HEAD
        i.setItemType("head");

        if(rarity == 10){           //COMMON
            i.setName("Common Head");
        }else if(rarity == 20){     //UNCOMMON
            i.setName("Uncommon Head");
        }else if(rarity == 30){     //RARE
            i.setName("Rare Head");
        }else if(rarity == 40){     //EPIC
            i.setName("Epic Head");
        }else{                      //LEGGENDARY
            i.setName("Leggendary Head");
        }

        //GENERA STATISTICHE
        double doubleArmor = (5 + rarity) * mul;
        doubleArmor = doubleArmor + 0.5 - (doubleArmor<0);
        int armor = (int) doubleArmor;
        i.setArmor(armor);

    }else if(type == 7){    //CHEST
        i.setItemType("chest");

        if(rarity == 10){           //COMMON
            i.setName("Common Chest");
        }else if(rarity == 20){     //UNCOMMON
            i.setName("Uncommon Chest");
        }else if(rarity == 30){     //RARE
            i.setName("Rare Chest");
        }else if(rarity == 40){     //EPIC
            i.setName("Epic Chest");
        }else{                      //LEGGENDARY
            i.setName("Leggendary Chest");
        }

        //GENERA STATISTICHE
        double doubleArmor = (8 + rarity) * mul;
        doubleArmor = doubleArmor + 0.5 - (doubleArmor<0);
        int armor = (int) doubleArmor;
        i.setArmor(armor);

    }else if(type == 8){    //ARMS
        i.setItemType("arms");

        if(rarity == 10){           //COMMON
            i.setName("Common Arms");
        }else if(rarity == 20){     //UNCOMMON
            i.setName("Uncommon Arms");
        }else if(rarity == 30){     //RARE
            i.setName("Rare Arms");
        }else if(rarity == 40){     //EPIC
            i.setName("Epic Arms");
        }else{                      //LEGGENDARY
            i.setName("Leggendary Arms");
        }

        //GENERA STATISTICHE
        double doubleArmor = (4 + rarity) * mul;
        doubleArmor = doubleArmor + 0.5 - (doubleArmor<0);
        int armor = (int) doubleArmor;
        i.setArmor(armor);

    }else if(type == 9){    //LEGS
        i.setItemType("legs");

        if(rarity == 10){           //COMMON
            i.setName("Common Legs");
        }else if(rarity == 20){     //UNCOMMON
            i.setName("Uncommon Legs");
        }else if(rarity == 30){     //RARE
            i.setName("Rare Legs");
        }else if(rarity == 40){     //EPIC
            i.setName("Epic Legs");
        }else{                      //LEGGENDARY
            i.setName("Leggendary Legs");
        }

        //GENERA STATISTICHE
        double doubleArmor = (2 + rarity) * mul;
        doubleArmor = doubleArmor + 0.5 - (doubleArmor<0);
        int armor = (int) doubleArmor;
        i.setArmor(armor);
    }

    i.updateUsageType();
    i.setIsNew(true);
    i.setEquipped(false);
    i.setQuantity(1);

    return i;
}

Generator::Generator() {

}

Generator::~Generator() {

}