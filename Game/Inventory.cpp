//
// Created by root on 10/2/20.
//

#include "Inventory.h"

Inventory::Inventory(int* currentSpace) {
    this->currentMaxSpace = currentSpace;
}

Inventory::Inventory() {
}

Inventory::~Inventory() {

}

void Inventory::setCurrentMaxSpace(int currentMaxSpace) {
    if(currentMaxSpace > MAX_SPACE){
        *this->currentMaxSpace = MAX_SPACE;
    } else{
        *this->currentMaxSpace = currentMaxSpace;
    }
}

int Inventory::getCurrentMaxSpace() {
    return *this->currentMaxSpace;
}

int Inventory::getItemsSize() {
    return this->items.size();
}

std::shared_ptr<Item> Inventory::getItem(int n) {
    return items.at(n);
}

void Inventory::sortByItemType() {
    sort(items.begin(),items.end(),
            [](const std::shared_ptr<Item>& lhs , const std::shared_ptr<Item>& rhs)
            {
                return lhs->getItemType() < rhs->getItemType();
            });
}

bool Inventory::addItem(Item item) {
    for(const auto& i : items){
        if(i->getName() == item.getName()){
            i->setQuantity(i->getQuantity() + item.getQuantity());
            i->setIsNew(true);
            return true;
        }
    }

    if(items.size() < *currentMaxSpace){
        items.push_back(std::make_shared<Item>(&item));
        return true;
    }
    return false;
}

string Inventory::listInventory(){
    string desc;
    for(const auto& i : this->items){
        if(!i->getItemType().empty())
            desc+= i->listItem() + "\n";
    }
    return desc;
}

string  Inventory::listConsumabiles() {
    string desc;
    int cont = 1;
    for(const auto& i : this->items){
        if(i->getUsageType() == 6){
            desc += to_string(cont) + ") "+ i->listItem() + "\n";
            cont ++;
        }
    }
    return desc;
}

/*
bool Inventory::exportInventory() {

    ofstream file;
    file.open("Inventory.txt");

    if (!file.is_open()){
        return false;
    } else {
        for(int i=0; i<*this->currentMaxSpace; i++){
            if(Inventory::items[i].getName() != ""){
                file<<Inventory::items[i].getItemType() + " ";
                file<<Inventory::items[i].getName() + " ";
                file<<Inventory::items[i].getDescription() + " ";
                file<<to_string(Inventory::items[i].getValue()) + " ";
                file<<Inventory::items[i].getRarity() + " ";
                file<< Inventory::items[i].getIconRect() + " ";

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
    }
    return true;
}
*/

bool Inventory::removeItem(std::string name) {
    auto iter = std::find_if(items.begin(), items.end(),
                             [&](const std::shared_ptr<Item>& p){
        return p->getName() == name;
    });

    if ( iter != items.end()){
        items.erase(iter);
        return true;
    }

    return false;
}

std::shared_ptr<Item> Inventory::getItem(std::string name) {
    auto iter = std::find_if(items.begin(), items.end(),
                             [&](const std::shared_ptr<Item>& p){
                                 return p->getName() == name;
                             });

    if ( iter != items.end()){
        return (*iter);
    }

    return nullptr;
}

void Inventory::expandInventorySpace(int n) {
    if(*currentMaxSpace + n > MAX_SPACE){
        *currentMaxSpace = MAX_SPACE;
    }
    else{
        *currentMaxSpace += n;
    }
}

bool Inventory::isExpandable() {
    return *this->currentMaxSpace < MAX_SPACE;
}









