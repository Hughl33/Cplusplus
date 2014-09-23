//
//  Inventory.cpp
//  Zorkish
//
//  Created by Hugh Lee on 11/09/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Inventory.h"
Inventory::Inventory(std::string b, bool h, int i, std::vector<std::string> items) : Container("Inventory", "player", "My two hands", i, true, true, items) {
    changeMax(i);
    bagID = b;
    bag = h;
}

std::string Inventory::getBagID() {
    return bagID;
}

void Inventory::getBag(std::vector<std::string> items, int i, std::string b) {
    if (bag) {
        std::cout << "You already have a bag" << std::endl;
    } else {
        bag = true;
        changeMax(size() + i);
        bagID = b;
        for (int i = 0; i < items.size(); i++) {
            addItem(items[i]);
        }
    }
}

std::vector<std::string> Inventory::dropBag() {
    bag = false;
    changeMax(2);
    bagID = "none";
    return emptyInventory();
}

bool Inventory::hasBag() {
    return bag;
}

std::string Inventory::save(std::string name) {
    std::string inventory = *new std::string();
    inventory = bagID + "|";
    if (bag) {
        inventory += "true|";
    } else {
        inventory += "false|";
    }
    inventory += std::to_string(max()) + "|";
    if (getAllItems().empty()) {
        inventory += "empty";
    } else {
        for (int i = 0; i < getAllItems().size(); i++) {
            if (i != 0) inventory += ",";
            inventory += getAllItems()[i];
        }
    }
    return inventory;
}