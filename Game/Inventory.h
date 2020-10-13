//
// Created by root on 10/2/20.
//

#ifndef DRAGONSLAYER_INVENTORY_H
#define DRAGONSLAYER_INVENTORY_H
#include <string>
#include <sstream>
#include "Item.h"
#include <vector>
#include <algorithm>

using namespace std;



class Inventory {

public:
    const static int MAX_SPACE = 40;               //MASSIMO NUMERO DI SLOT OCCUPABILI NEL GIOCO
    int* currentSpace;           //MASSIMO NUMERO DI SLOT OCCUPABILI SECONDO I NOSTRI POWER UP DELL'INVENTARIO

    vector<Item*> items;

public:
    Inventory();
    Inventory(int* currentSpace);
    virtual ~Inventory();

    void setCurrentSpace(int* currentSpace);
    int getCurrentSpace();

    int getItemsSize();
    Item* getItem(int n);
    Item* getItem(std::string name);

    bool removeItem(std::string name);

    bool addItem(Item* item);
    bool exportInventory();
    string listInventory();

    void sortByItemType();
};


#endif //DRAGONSLAYER_INVENTORY_H
