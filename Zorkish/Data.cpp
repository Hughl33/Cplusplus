//
//  Data.cpp
//  Zorkish
//
//  Created by Hugh Lee on 25/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Data.h"

std::vector<std::string> &Data::split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> Data::split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

std::string Data::getMenu(std::string name) {
    std::string data;
    std::string line;
    std::ifstream myfile ("Menus.txt");
    
    if (myfile.is_open()) {
        while (getline (myfile,line)) {
            if (line == name) {
                while (getline (myfile,line)) {
                    if (line == "--br--") break;
                    data += line + "\n";
                }
            }
        }
        myfile.close();
    }
    else std::cout << "Unable to open file" << std::endl;
    
    return data;
}

Item Data::getItem(std::string name) {
    std::vector<std::string> data;
    std::string line;
    std::ifstream myfile ("Items.txt");
    
    if (myfile.is_open()) {
        while (getline (myfile,line)) {
            if (line.substr(5, name.length()) == name) break;
        }
        myfile.close();
    }
    else std::cout << "Unable to open file" << std::endl;

    data = Data::split(line, '|');
    Item item = *new Item(split(data[0], ':')[1], split(data[1], ':')[1], split(data[2], ':')[1]);
    
    return item;
}

Place Data::getPlace(std::string name) {
    std::vector<std::string> data;
    std::string line;
    std::ifstream myfile ("Places.txt");
    
    if (myfile.is_open()) {
        while (getline (myfile,line)) {
            if (line.substr(5, name.length()) == name) break;
        }
        myfile.close();
    }
    else std::cout << "Unable to open file" << std::endl;
    
    data = Data::split(line, '|');
    Place place = *new Place(split(data[0], ':')[1], split(data[1], ':')[1], split(data[2], ':')[1], split(split(data[3], ':')[1], ','));
    
    return place;
}