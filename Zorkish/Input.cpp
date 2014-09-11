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
    } else if (input[0] == "drop" || input[0] == "take") {
        item(input, p);
//    } else if (input[0] == "quit" || input[0] == "q") {
//        
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
        if (Data::getPlace(p.getPlace()).itemCount() == 0) {
            std::cout << "There is nothing here..." << std::endl;
        } else {
            std::cout << "You can see a: " << std::endl;
            for (int i = 0; i < Data::getPlaceItems(p.getPlace()).size(); i++) {
                std::cout << Data::getPlaceItems(p.getPlace())[i] << std::endl;
            }
        }
    } else if (input[1] == "at") {
        if (p.hasItem(input[2])) {
            std::cout << Data::getItem(input[2]).getDesc() << std::endl;
        } else if (Data::getPlace(p.getPlace()).hasItem(input[2])) {
            std::cout << Data::getItem(input[2]).getDesc() << std::endl;
        } else {
            std::cout << "Can't find the " << Data::toProper(input[2]) << std::endl;
        }
    } else if (input[1].empty()) {
        std::cout << "Look where?" << std::endl;
    } else {
        std::cout << "I can't see that" << std::endl;
    }
}

void Input::item(std::vector<std::string> input, Player& p) {
    if (input[1].empty()) {
        std::cout << input[0] << " what?" << std::endl;
    } else if (Data::getItem(input[1]).getName() == " ") {
        std::cout << "Can't find the " << input[1] << std::endl;
    } else if (input[0] == "take") {
        if (Data::getPlace(p.getPlace()).hasItem(input[1])){
            Place place = Data::getPlace(p.getPlace());
            place.removeItem(input[1]);
            p.addItem(input[1]);
            Data::save(place.save(), p.getPlace());
            std::cout << "The " << Data::toProper(input[1]) << " has been added to your inventory." << std::endl;
        } else {
            std::cout << "Can't find the " << input[1] << std::endl;
        }
    } else if (input[0] == "drop") {
        if (p.hasItem(input[1])) {
            p.dropItem(input[1]);
            Place place = Data::getPlace(p.getPlace());
            place.addItem(input[1]);
            Data::save(place.save(), p.getPlace());
            std::cout << "The " << Data::toProper(input[1]) << " has been removed from your inventory." << std::endl;
        } else {
            std::cout << "You don't have the " << input[1] << std::endl;
        }
    }
}