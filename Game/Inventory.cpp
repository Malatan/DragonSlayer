//
// Created by root on 10/2/20.
//

#include "Inventory.h"

Inventory::Inventory(int* currentSpace) {
    currentMaxSpace = currentSpace;
}

Inventory::Inventory() {
}

Inventory::~Inventory() {

}

void Inventory::setCurrentMaxSpace(int current_maxSpace) {
    if(current_maxSpace > MAX_SPACE){
        *currentMaxSpace = MAX_SPACE;
    } else{
        *currentMaxSpace = current_maxSpace;
    }
}

int Inventory::getCurrentMaxSpace() {
    return *currentMaxSpace;
}

int Inventory::getItemsSize() {
    return items.size();
}

std::shared_ptr<Item> Inventory::getItem(int n) {
    return items.at(n);
}

void Inventory::sortByItemType() {
    sort(items.begin(),items.end(),
            [](const std::shared_ptr<Item>& lhs , const std::shared_ptr<Item>& rhs)
            {
                return lhs->sortKeyWord() < rhs->sortKeyWord();
            });
}

bool Inventory::addItem(Item *item) {
    for(const auto& i : items){
        if(i->getName() == item->getName()){
            i->setQuantity(i->getQuantity() + item->getQuantity());
            i->setIsNew(true);
            return true;
        }
    }

    if(items.size() < *currentMaxSpace){
        items.push_back(std::make_shared<Item>(item));
        return true;
    }
    return false;
}

string Inventory::listInventory(){
    string desc;
    for(const auto& i : items){
        if(!i->getItemType().empty())
            desc+= i->listItem() + "\n";
    }
    return desc;
}

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
    return *currentMaxSpace < MAX_SPACE;
}









