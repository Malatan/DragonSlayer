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

using namespace std;



class Inventory {

public:
    const static int maxSpace = 50;               //MASSIMO NUMERO DI SLOT OCCUPABILI NEL GIOCO
    int currentSpace;           //MASSIMO NUMERO DI SLOT OCCUPABILI SECONDO I NOSTRI POWER UP DELL'INVENTARIO

    Item items[maxSpace];

public:

    int getMaxSpace();

    void setCurrentSpace(int currentSpace);
    int getCurrentSpace();

    Item getItemByIndex(int i);
    void replaceItem(int i, Item in);
    bool addItem(Item in);

    void importInventory();
    bool exportInventory();
    string listInventory();

    Inventory();
    Inventory(int currentSpace);
    virtual ~Inventory();


};


#endif //DRAGONSLAYER_INVENTORY_H
