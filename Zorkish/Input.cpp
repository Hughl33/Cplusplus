//
//  Input.cpp
//  Zorkish
//
//  Created by Hugh Lee on 2/09/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Input.h"

void Input::process(std::string n, Player& p, Structure s) {
    std::string a = Data::toLower(n);
    std::vector<std::string> input = Data::split(a, ' ');
    
    if (input[0] == "go" || input[0] == "walk") {
        player(input, p, s);
    } else if (input[0] == "look") {
        info(input, p);
    } else if (input[0] == "open" || input[0] == "close") {
        container(input, p);
    } else if (input[0] == "drop" || input[0] == "take" || input[0] == "put") {
        item(input, p);
//    } else if (input[0] == "quit" || input[0] == "q") {

    } else {
        std::cout << "Input valid input for " << input[0] << std::endl;
    }
}

void Input::player(std::vector<std::string> input, Player& p, Structure s) {
    if (input[1] == "north" || input[1] == "n") {
        if (Data::canMove(input[1], s.getLinks(p.getPlace()))) {
            std::string temp;
            for (int i = 0; i < s.getLinks(p.getPlace()).size(); i++) {
                if (Data::equals(input[1], Data::split(s.getLinks(p.getPlace())[i], ':')[0])) {
                    temp = Data::split(s.getLinks(p.getPlace())[i], ':')[1];
                    p.move(temp);
                    break;
                }
            }
        } else {
            std::cout << "You can't move there" << std::endl;
        }
    } else if (input[1] == "south" || input[1] == "s") {
        if (Data::canMove(input[1], s.getLinks(p.getPlace()))) {
            std::string temp;
            for (int i = 0; i < s.getLinks(p.getPlace()).size(); i++) {
                if (Data::equals(input[1], Data::split(s.getLinks(p.getPlace())[i], ':')[0])) {
                    temp = Data::split(s.getLinks(p.getPlace())[i], ':')[1];
                    p.move(temp);
                    break;
                }
            }
        } else {
            std::cout << "You can't move there" << std::endl;
        }
    } else if (input[1] == "east" || input[1] == "e") {
        if (Data::canMove(input[1], s.getLinks(p.getPlace()))) {
            std::string temp;
            for (int i = 0; i < s.getLinks(p.getPlace()).size(); i++) {
                if (Data::equals(input[1], Data::split(s.getLinks(p.getPlace())[i], ':')[0])) {
                    temp = Data::split(s.getLinks(p.getPlace())[i], ':')[1];
                    p.move(temp);
                    break;
                }
            }
        } else {
            std::cout << "You can't move there" << std::endl;
        }
    } else if (input[1] == "west" || input[1] == "w") {
        if (Data::canMove(input[1], s.getLinks(p.getPlace()))) {
            std::string temp;
            for (int i = 0; i < s.getLinks(p.getPlace()).size(); i++) {
                if (Data::equals(input[1], Data::split(s.getLinks(p.getPlace())[i], ':')[0])) {
                    temp = Data::split(s.getLinks(p.getPlace())[i], ':')[1];
                    p.move(temp);
                    break;
                }
            }
        } else {
            std::cout << "You can't move there" << std::endl;
        }
    } else if (input[1].empty()) {
        std::cout << "Go where?" << std::endl;
    } else {
        std::cout << "Don't know how to go " << input[1] << std::endl;
    }
}

void Input::info(std::vector<std::string> input, Player& p) {
    if (input[1] == "around") {
        if (Data::getPlace(p.getPlace()).itemCount() == 0 && Data::getPlace(p.getPlace()).itemCount() == 0) {
            std::cout << "There is nothing here..." << std::endl;
        } else {
            std::cout << "You can see a: " << std::endl;
            std::vector<std::string> placeItems = Data::getPlaceItems(p.getPlace());
            std::vector<std::string> placeContainers = Data::getPlaceContainers(p.getPlace());
            for (int i = 0; i < placeItems.size(); i++) {
                if (placeItems[i] != " ") std::cout << placeItems[i] << std::endl;
            }
            for (int i = 0; i < placeContainers.size(); i++) {
                std::string temp = Data::getContainer(placeContainers[i]).getType();
                if (temp != " ") std::cout << temp << std::endl;
            }
        }
    } else if (input[1] == "at") {
        if (Data::getInventory(p.getName()).hasItem(input[2])) {
            std::cout << Data::getItem(input[2]).getDesc() << std::endl;
        } else if (Data::getPlace(p.getPlace()).hasItem(input[2])) {
            std::cout << Data::getItem(input[2]).getDesc() << std::endl;
        } else if (Data::getPlace(p.getPlace()).hasContainer(Data::getContainer(p.getPlace(), input[2]).getID())) {
            std::cout << Data::getContainer(p.getPlace(), input[2]).getDesc() << std::endl;
        } else {
            bool found = false;
            for (int i = 0; i < Data::getPlace(p.getPlace()).containerCount(); i++) {
                Container c = Data::getContainer(Data::getPlace(p.getPlace()).getContainer(i));
                if (c.hasItem(input[2])) {
                    found = true;
                    std::cout << Data::getItem(input[2]).getDesc() << std::endl;
                }
            }
            if (!found) std::cout << "Can't find the " << Data::toProper(input[2]) << std::endl;
        }
    } else if (input[1] == "in") {
        Container container = Data::getContainer(p.getPlace(), input[2]);
        if (container.isOpen()) {
            if (container.getAllItems().empty()) {
                std::cout << "There is nothing inside." << std::endl;
            } else {
                std::cout << "Inside there is a:" << std::endl;
                for (int i = 0; i < container.getAllItems().size(); i++) {
                    std::cout << container.getAllItems()[i] << std::endl;
                }
            }
        } else {
            std::cout << "Apparently you have to open it first." << std::endl;
        }
    } else if (input[1].empty()) {
        std::cout << "Look where?" << std::endl;
    } else {
        std::cout << "I can't see that" << std::endl;
    }
}

void Input::item(std::vector<std::string> input, Player& p) {
    if (input[0] == "take") {
        Inventory inv = Data::getInventory(p.getName());
        if (input.size() == 4) {
            Container container = Data::getContainer(p.getPlace(), input[2]);
            container.removeItem(input[1]);
            inv.addItem(input[1]);
            Data::save(container.save(), container.getID(), "ContainerItems");
            Data::save(inv.save(p.getName()), p.getName(), "Inventory");
            std::cout << "The " << Data::toProper(input[1]) << " has been taken from " << input[3] << std::endl;
        } else if (Data::getPlace(p.getPlace()).hasItem(input[1])){
            Place place = Data::getPlace(p.getPlace());
            inv.addItem(input[1]);
            place.removeItem(input[1]);
            Data::save(place.saveItems(), p.getPlace(), "PlaceItems");
            Data::save(inv.save(p.getName()), p.getName(), "Inventory");
            std::cout << "The " << Data::toProper(input[1]) << " has been added to your inventory." << std::endl;
        } else if (Data::getPlace(p.getPlace()).hasContainer(Data::getContainer(p.getPlace(), input[1]).getID())) {
            Container c = Data::getContainer(p.getPlace(), input[1]);
            if (c.isTakeable()) {
                if (c.getType() == "bag") {
                    if (inv.hasBag()) {
                        std::cout << "You already have a bag, why would you want another?" << std::endl;
                    } else {
                        Place place = Data::getPlace(p.getPlace());
                        inv.getBag(c.getAllItems(), c.max(), c.getID());
                        place.removeContainer(c.getID());
                        Data::save(place.saveContainers(), p.getPlace(), "PlaceContainers");
                        Data::save(inv.save(p.getName()), p.getName(), "Inventory");
                        std::cout << "You have taken " << Data::toProper(input[1]) << std::endl;
                    }
                }
            } else {
                std::cout << "That's too heavy to take." << std::endl;
            }
        } else {
            std::cout << "Can't find the " << input[1] << std::endl;
        }
    } else if (input[0] == "drop" || input[0] == "put") {
        Inventory inv = Data::getInventory(p.getName());
        if (Data::equals(input[1], "bag")) {
            Place place = Data::getPlace(p.getPlace());
            Container container = Data::getContainer(inv.getBagID());
            place.addContainer(inv.getBagID());
            container.dumpAllItems(inv.dropBag());
            Data::save(inv.save(p.getName()), p.getName(), "Inventory");
            Data::save(place.saveContainers(), p.getPlace(), "PlaceContainers");
            Data::save(container.save(), container.getID(), "ContainerItems");
            std::cout << "You have dropped the bag and everything in it!" << std::endl;
        } else if (input.size() == 4) {
            inv.removeItem(input[1]);
            Container container = Data::getContainer(p.getPlace(), input[3]);
            container.addItem(input[1]);
            Data::save(inv.save(p.getName()), p.getName(), "Inventory");
            Data::save(container.save(), container.getID(), "ContainerItems");
            std::cout << "The " << Data::toProper(input[1]) << " has been placed into " << input[3] << std::endl;
        } else if (inv.hasItem(input[1])) {
            inv.removeItem(input[1]);
            Place place = Data::getPlace(p.getPlace());
            place.addItem(input[1]);
            Data::save(inv.save(p.getName()), p.getName(), "Inventory");
            Data::save(place.saveItems(), p.getPlace(), "PlaceItems");
            std::cout << "The " << Data::toProper(input[1]) << " has been removed from your inventory." << std::endl;
        } else {
            std::cout << "You don't have the " << input[1] << std::endl;
        }
    } else if (input[1].empty()) {
        std::cout << input[0] << " what?" << std::endl;
    } else {
        std::cout << "Can't find the " << input[1] << std::endl;
    }
}

void Input::container(std::vector<std::string> input, Player& p) {
    if (input[1].empty()) {
        std::cout << input[0] << " what?" << std::endl;
    } else if (Data::getContainer(p.getPlace(), input[1]).getID() == " ") {
        std::cout << "Can't find the " << input[1] << std::endl;
    } else if (input[0] == "open") {
        Container container = Data::getContainer(p.getPlace(), input[1]);
        if (container.isOpen()) {
            std::cout << "The " << input[1] << " is already open." << std::endl;
        } else {
            container.toggleAccess();
            Data::save(container.save(), container.getID(), "ContainerItems");
            std::cout << "You have opened the " << input[1] << std::endl;
        }
    } else if (input[0] == "close") {
        Container container = Data::getContainer(p.getPlace(), input[1]);
        if (!container.isOpen()) {
            std::cout << "The " << input[1] << " is already closed." << std::endl;
        } else {
            container.toggleAccess();
            Data::save(container.save(), container.getID(), "ContainerItems");
            std::cout << "You have closed the " << input[1] << std::endl;
        }
    } else {
        std::cout << "Can't find the " << input[1] << std::endl;
    }
}