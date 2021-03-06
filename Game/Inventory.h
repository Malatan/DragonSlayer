//
// Created by root on 10/2/20.
//

#ifndef DRAGONSLAYER_INVENTORY_H
#define DRAGONSLAYER_INVENTORY_H
#include "Item.h"
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

class Inventory {
public:
    const static int MAX_SPACE = 70; //MASSIMO NUMERO DI SLOT OCCUPABILI NEL GIOCO
    //CONSTRUCTOR & DESTRUCTOR
    explicit Inventory(int* currentSpace);
    ~Inventory();

    //functions
    void fill(std::vector<Item>& item_list);
    bool isFull();
    void expandInventorySpace(int n);
    bool isExpandable();
    bool removeItemById(unsigned int id);
    bool hasItemByName(const std::string& item_name) const;
    bool addItem(std::shared_ptr<Item> new_item);
    void sortByItemType();

    //GET & SET
    string listInventory();
    int getItemsSize();
    std::shared_ptr<Item> getItemByIndex(int n);
    std::shared_ptr<Item> getItemById(unsigned int id);
    void setCurrentMaxSpace(int current_maxSpace);
    int getCurrentMaxSpace();
    int getAvailableSpace();
    vector<std::shared_ptr<Item>> getItems();

private:
    int* currentMaxSpace;           //MASSIMO NUMERO DI SLOT OCCUPABILI SECONDO I NOSTRI POWER UP DELL'INVENTARIO
    vector<std::shared_ptr<Item>> items;
};


#endif //DRAGONSLAYER_INVENTORY_H
