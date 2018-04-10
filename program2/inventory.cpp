#include <vector>
#include <string>
#include <iostream>
#include "inventory.h"

using namespace std;

/**
* Constructor for inventories
*/
Inventory::Inventory()
{
    numItems = 0;
}

/**
* Adds amount to the quantity of the named item in the inventory, 
* or inserts the item into the inventory with the given quantity if not already in stock.
*/
void Inventory::Update(string item, int amount)
{
    itemBox toAdd = { item, amount };
    int byNameIndex = -1;
    int byQuantityIndex = -1;
    int namePos = 0; // Where it belongs in sortedByName
    int quantPos = 0; // Where it belongs in sortedByQuantity
    for (int i = 0; i < numItems; i += 1) {
        if (sortedByName[i].entry == item) {
            byNameIndex = i;
        }
        if (sortedByName[i].entry < item) {
            // Entry is before item alphabetically
            namePos += 1;
        }
        if (sortedByQuantity[i].entry == item) {
            byQuantityIndex = i;
        }
        if (sortedByQuantity[i].value < amount) {
            quantPos += 1;
        }
    }
    if (byNameIndex >= 0) {
        // item is already in our inventory
        sortedByName[byNameIndex].value += amount;
        sortedByQuantity[byQuantityIndex].value += amount;
    } else {
        // adding a new item
        sortedByName.insert(sortedByName.begin() + namePos, toAdd);
        sortedByQuantity.insert(sortedByQuantity.begin() + quantPos, toAdd);
        numItems += 1;
    }
}

/**
* Prints inventory entries (name plus quantity) sorted alphabetically by name.
*/
void Inventory::ListByName()
{
    cout << "### Listing Inventory Sorted By Name ###" << endl;
    for (int i = 0; i < numItems; i += 1) {
        string num = std::to_string(sortedByName[i].value);
        cout << "Item: " + sortedByName[i].entry  + ", Quantity: " + num << endl;
    }
}

/**
* Prints inventory entries (name plus quantity) sorted in increasing order by quantity.
*/
void Inventory::ListByQuantity()
{
    cout << "### Listing Inventory Sorted By Quantity ###" << endl;
    for (int i = 0; i < numItems; i += 1) {
        string num = std::to_string(sortedByQuantity[i].value);
        cout << "Item: " + sortedByQuantity[i].entry  + ", Quantity: " + num << endl;
    }
}