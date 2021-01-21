//
// Created by root on 10/2/20.
//

#include "Inventory.h"

//CONSTRUCTOR & DESTRUCTOR
Inventory::Inventory(int* currentSpace) {
    currentMaxSpace = currentSpace;
}

Inventory::~Inventory() = default;

//functions
void Inventory::sortByItemType() {
    sort(items.begin(),items.end(),
            [](const std::shared_ptr<Item>& lhs , const std::shared_ptr<Item>& rhs)
            {
                return lhs->sortKeyWord() < rhs->sortKeyWord();
            });
}

void Inventory::fill(vector<Item> &item_list) {
    items.clear();
    items.reserve(item_list.size());

    for(const auto& i : item_list){
        items.push_back(std::make_shared<Item>(i));
    }
}

bool Inventory::addItem(std::shared_ptr<Item> new_item) {
    for(const auto& i : items){
        if(i->getName() == new_item->getName() && i->getUsageType() == CONSUMABLE_USAGE){
            i->setQuantity(i->getQuantity() + new_item->getQuantity());
            i->setIsNew(true);
            return true;
        }
    }
    if(items.size() < *currentMaxSpace){
        items.push_back(std::move(new_item));
        return true;
    }
    return false;
}

bool Inventory::removeItemById(unsigned int id) {
    auto iter = std::find_if(items.begin(), items.end(),
                             [&](const std::shared_ptr<Item>& p){
        return p->getId() == id;
    });

    if ( iter != items.end()){
        items.erase(iter);
        return true;
    }

    return false;
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

bool Inventory::isFull() {
    return items.size() == *currentMaxSpace;
}

int Inventory::getAvailableSpace() {
    return *currentMaxSpace - (int)items.size();
}

//GET & SET
string Inventory::listInventory(){
    std::stringstream desc;
    desc << "------------------------------Player Inventory------------------------------" << std::endl;
    for(const auto& i : items){
        //if(!i->getItemType().empty())
        desc << i->listItem(true);
    }
    desc << "----------------------------End-Player Inventory-End----------------------------" << std::endl;
    return desc.str();
}

std::shared_ptr<Item> Inventory::getItemById(unsigned int id) {
    auto iter = std::find_if(items.begin(), items.end(),
                             [&](const std::shared_ptr<Item>& p){
                                 return p->getId() == id;
                             });

    if ( iter != items.end()){
        return (*iter);
    }

    return nullptr;
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

std::shared_ptr<Item> Inventory::getItemByIndex(int n) {
    return items.at(n);
}

vector<std::shared_ptr<Item>> Inventory::getItems() {
    return items;
}

bool Inventory::hasItemByName(const std::string& item_name) const {
    for(const auto& i : items){
        if(i->getName() == item_name)
            return true;
    }
    return false;
}






