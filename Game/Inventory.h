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
    Inventory();
    Inventory(int* currentSpace);
    virtual ~Inventory();

    //TOSTRING
    string listInventory();
    string listConsumabiles();

    //MANAGE INVENTORY
    void expandInventorySpace(int n);
    bool isExpandable();
    bool removeItem(std::string name);
    bool addItem(Item item);
    //bool exportInventory();
    void sortByItemType();

    //GET & SET
    int getItemsSize();
    std::shared_ptr<Item> getItem(int n);
    std::shared_ptr<Item> getItem(std::string name);
    void setCurrentMaxSpace(int currentMaxSpace);
    int getCurrentMaxSpace();

private:
    int* currentMaxSpace;           //MASSIMO NUMERO DI SLOT OCCUPABILI SECONDO I NOSTRI POWER UP DELL'INVENTARIO
    vector<std::shared_ptr<Item>> items;
};


#endif //DRAGONSLAYER_INVENTORY_H
