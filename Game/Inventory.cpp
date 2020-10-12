//
// Created by root on 10/2/20.
//

#include "Inventory.h"

Inventory::Inventory(int* currentSpace) {
    this->currentSpace = currentSpace;
}

Inventory::Inventory() {
}

Inventory::~Inventory() {

}

void Inventory::setCurrentSpace(int* currentSpace) {
    this->currentSpace;
}

int Inventory::getCurrentSpace() {
    return *this->currentSpace;
}

int Inventory::getItemsSize() {
    return this->items.size();
}

void Inventory::sortByItemType() {
    sort(this->items.begin(),this->items.end(),
            [](const Item* lhs , const Item* rhs)
            {
                return lhs->getItemType() < rhs->getItemType();
            });
}

bool Inventory::addItem(Item* item) {
    if(this->items.size() <= MAX_SPACE){
        this->items.push_back(item);
    }
    return false;
}

string Inventory::listInventory(){
    string desc;
    for(auto i : this->items){
        if(!i->getItemType().empty())
            desc+= i->listItem() + "\n";
    }
    return desc;
}

bool Inventory::exportInventory() {

  /*  ofstream file;
    file.open("Inventory.txt");

    if (!file.is_open()){
        return false;
    } else {
        for(int i=0; i<*this->currentSpace; i++){
            if(Inventory::items[i].getName() != ""){
                file<<Inventory::items[i].getItemType() + " ";
                file<<Inventory::items[i].getName() + " ";
                file<<Inventory::items[i].getDescription() + " ";
                file<<to_string(Inventory::items[i].getValue()) + " ";
                file<<Inventory::items[i].getRarity() + " ";
                file<< Inventory::items[i].getIconFileName() + " ";

                if(Inventory::items[i].getItemType() == "W"){
                    file<<to_string(Inventory::items[i].getDamage()) + " ";
                    file<<Inventory::items[i].getWeaponType() + " ";
                  //  file<<to_string(Inventory::items[i].getDurability()) + " ";
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
    }*/
    return true;
}







