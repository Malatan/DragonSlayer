//
// Created by root on 10/2/20.
//

#include "Inventory.h"

int Inventory::getMaxSpace() {
    return Inventory::maxSpace;
}

void Inventory::setCurrentSpace(int currentSpace) {
    Inventory::currentSpace = currentSpace;
}

int Inventory::getCurrentSpace() {
    return Inventory::currentSpace;
}

Item Inventory::getItemByIndex(int i) {
    return Inventory::items[i];
}

void Inventory::replaceItem(int i, Item in) {
    items[i] = in;
}

bool Inventory::addItem(Item in) {
    for(int i=0; i<currentSpace; i++){
        if(Inventory::items[i].getName() == ""){
            Inventory::items[i] = in;
            return true;
        }
    }
    return false;
}

string Inventory::listInventory(){
    string desc;
    for(int i=0; i<Inventory::currentSpace; i++){
        if(Inventory::items[i].getName() != ""){
            desc+= Inventory::items[i].listItem() + "\n";
        }
    }

    return desc;
}

bool Inventory::exportInventory() {

    ofstream file;
    file.open("Inventory.txt");

    if (!file.is_open()){
        return false;
    } else {
        for(int i=0; i<Inventory::currentSpace; i++){
            if(Inventory::items[i].getName() != ""){
                file<<Inventory::items[i].getItemType() + " ";
                file<<Inventory::items[i].getName() + " ";
                file<<Inventory::items[i].getDescription() + " ";
                file<<to_string(Inventory::items[i].getValue()) + " ";
                file<<Inventory::items[i].getRarity() + " ";
                file<<Inventory::items[i].getIcon() + " ";

                if(Inventory::items[i].getItemType() == "W"){
                    file<<to_string(Inventory::items[i].getDamage()) + " ";
                    file<<Inventory::items[i].getWeaponType() + " ";
                    file<<to_string(Inventory::items[i].getDurability()) + " ";
                }

                if(Inventory::items[i].getItemType() == "E"){
                    file<<to_string(Inventory::items[i].getArmor()) + " ";
                    file<<Inventory::items[i].getArmorType() + " ";
                }

                if(Inventory::items[i].getItemType() == "C"){
                    file<<to_string(Inventory::items[i].getQuantity()) + " ";
                }

                file<<"\n";
            }
        }

        file.close();
        return true;
    }

}

void Inventory::importInventory(){
    ifstream file;
    file.open("Inventory.txt");

    if (!file.is_open()){
        cout<<"#Can't open Inventory.txt";
    } else {
        string word;
        int newlineCont = 0;
        int current;

        Item i = Item();

        while (file >> word) {
            if(newlineCont == 0){
                if(word == "C"){            //CONSUMABLE
                    current = 1;
                    newlineCont = 6;
                    i.setItemType(word);
                }else if(word == "W"){      //WEAPON
                    current = 2;
                    newlineCont = 8;
                    i.setItemType(word);
                }else if(word == "E"){      //EQUIP
                    current = 3;
                    newlineCont = 7;
                    i.setItemType(word);
                }
            }else{
                switch(current){
                    case 1:             //ITEM
                        if(newlineCont == 6){
                            i.setName(word);
                        }else if(newlineCont == 5){
                            i.setDescription(word);
                        }else if(newlineCont == 4){
                            stringstream intValue(word);
                            int value;
                            intValue >> value;
                            i.setValue(value);
                        }else if(newlineCont == 3){
                            i.setRarity(word);
                        }else if(newlineCont == 2){
                            i.setIcon(word);
                        }else if(newlineCont == 1) {
                            stringstream intQnt(word);
                            int quantity;
                            intQnt >> quantity;
                            i.setQuantity(quantity);

                            i.setDamage(0);
                            i.setWeaponType("");
                            i.setDurability(0);
                            i.setArmor(0);
                            i.setArmorType("");

                            Inventory::addItem(i);
                        }

                        newlineCont --;
                        break;

                    case 2:             //WEAPON
                        if(newlineCont == 8){
                            i.setName(word);
                        }else if(newlineCont == 7){
                            i.setDescription(word);
                        }else if(newlineCont == 6){
                            stringstream intValue(word);
                            int value;
                            intValue >> value;
                            i.setValue(value);
                        }else if(newlineCont == 5){
                            i.setRarity(word);
                        }else if(newlineCont == 4){
                            i.setIcon(word);
                        }else if(newlineCont == 3){
                            stringstream intValue(word);
                            int damage;
                            intValue >> damage;
                            i.setDamage(damage);
                        }else if(newlineCont == 2){
                            i.setWeaponType(word);
                        }else if(newlineCont == 1){
                            stringstream intValue(word);
                            int durability;
                            intValue >> durability;
                            i.setDurability(durability);

                            i.setArmor(0);
                            i.setArmorType("");

                            Inventory::addItem(i);
                        }

                        newlineCont --;
                        break;

                    case 3:             //EQUIP
                        if(newlineCont == 7){
                            i.setName(word);
                        }else if(newlineCont == 6){
                            i.setDescription(word);
                        }else if(newlineCont == 5){
                            stringstream intValue(word);
                            int value;
                            intValue >> value;
                            i.setValue(value);
                        }else if(newlineCont == 4){
                            i.setRarity(word);
                        }else if(newlineCont == 3){
                            i.setIcon(word);
                        }else if(newlineCont == 2){
                            stringstream intValue(word);
                            int armor;
                            intValue >> armor;
                            i.setArmor(armor);
                        }else if(newlineCont == 1){
                            i.setArmorType(word);

                            i.setDamage(0);
                            i.setWeaponType("");
                            i.setDurability(0);

                            Inventory::addItem(i);
                        }

                        newlineCont --;
                        break;

                    default:
                        cout<<"#Import error"<<endl;
                        break;
                }

            }

        }
    }
}

Inventory::Inventory(int currentSpace) {
    Inventory::currentSpace = currentSpace;
    for (int i=0; i<Inventory::maxSpace; i++)
    {
        Inventory::items[i] = Item();
    }
}

Inventory::Inventory() {

}

Inventory::~Inventory() {

}
