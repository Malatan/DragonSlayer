//
// Created by root on 10/2/20.
//

#ifndef DRAGONSLAYER_INVENTORY_H
#define DRAGONSLAYER_INVENTORY_H
#include <string>
#include <sstream>
#include "Item.h"
#include "iostream"
#include "fstream"
#include <vector>
#include <algorithm>

using namespace std;



class Inventory {

public:
    const static int MAX_SPACE = 70;               //MASSIMO NUMERO DI SLOT OCCUPABILI NEL GIOCO
    int* currentMaxSpace;           //MASSIMO NUMERO DI SLOT OCCUPABILI SECONDO I NOSTRI POWER UP DELL'INVENTARIO

    vector<Item*> items;

public:
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
    bool addItem(Item* item);
    //bool exportInventory();
    void sortByItemType();
    void replaceItem(int index, Item* in);

    //GET & SET
    int getItemsSize();
    Item* getItem(int n);
    Item* getItem(std::string name);
    void setCurrentMaxSpace(int currentMaxSpace);
    int getCurrentMaxSpace();
};


#endif //DRAGONSLAYER_INVENTORY_H
