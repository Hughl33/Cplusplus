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
    std::vector<std::string> elems = *new std::vector<std::string>();
    split(s, delim, elems);
    return elems;
}

std::string Data::inBetween(std::string s, char a, char b) {
    return s.substr(s.find(a), s.find(b));
}

std::string Data::toLower(std::string s) {
    char temp[s.size()];
    strcpy(temp, s.c_str());
    for (int i = 0; i < s.size(); i++) {
        temp[i] = tolower(temp[i]);
    }
    return std::string(temp);
}

std::string Data::toUpper(std::string s) {
    char temp[s.size()];
    strcpy(temp, s.c_str());
    for (int i = 0; i < s.size(); i++) {
        temp[i] = toupper(temp[i]);
    }
    return std::string(temp);
}

std::string Data::toProper(std::string s) {
    char temp[s.size()];
    strcpy(temp, s.c_str());
    for (int i = 0; i < s.size(); i++) {
        if (temp[i - 1] == ' ' || i == 0) temp[i] = toupper(temp[i]);
        else temp[i] = tolower(temp[i]);
    }
    return std::string(temp);
}

bool Data::equals(std::string a, std::string b) {
    return toLower(a) == toLower(b);
}

bool Data::canMove(std::string s, std::vector<std::string> m) {
    for (int i = 0; i < m.size(); i++) {
        if (equals(s, Data::split(m[i], ':')[0])) return true;
    }
    return false;
}

std::string Data::getMenu(std::string name) {
    std::string data;
    std::string line;
    std::ifstream myfile("Menus.txt");
    
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
    bool found = false;
    std::ifstream myfile("Data/Items.txt");
    
    if (myfile.is_open()) {
        while (getline (myfile,line)) {
            if (equals(line.substr(0, name.length()), name)) {
                found = true;
                break;
            }
        }
        myfile.close();
        
        if (found) {
            data = Data::split(line, '|');
            Item item = *new Item(data[0], data[1], data[2]);
            return item;
        } else {
            Item item = *new Item(" ", " ", " ");
            return item;
        }
    } else {
        std::cout << "Unable to open file" << std::endl;
        Item item = *new Item(NULL, NULL, NULL);
        return item;
    }
}

std::vector<std::string> Data::getPlaceItems(std::string name) {
    std::vector<std::string> data = *new std::vector<std::string>();
    std::string line;
    bool found = false;
    std::ifstream myfile("PlaceItems.txt");
    
    if (myfile.is_open()) {
        while (getline (myfile,line)) {
            if (equals(line.substr(0, name.length()), name)) {
                found = true;
                break;
            }
        }
        myfile.close();
        
        if (found) {
            if (!equals(Data::split(line, '|')[1], "empty")) {
                data = Data::split(Data::split(line, '|')[1], ',');
            }
        }
        return data;
    } else {
        std::cout << "Unable to open file" << std::endl;
        return data;
    }
}

Place Data::getPlace(std::string name) {
    std::vector<std::string> data;
    std::string line;
    bool found = false;
    std::ifstream myfile("Data/Places.txt");
    
    if (myfile.is_open()) {
        while (getline (myfile,line)) {
            if (equals(line.substr(0, name.length()), name)) {
                found = true;
                break;
            }
        }
        myfile.close();
        
        if (found) {
            data = Data::split(line, '|');
            Place place = *new Place(data[0], data[1], data[2]);
            data = Data::getPlaceItems(name);
            for (int i = 0; i < data.size(); i++) {
                place.addItem(data[i]);
            }
            return place;
        } else {
            Place place = *new Place(" ", " ", " ");
            return place;
        }
    } else {
        std::cout << "Unable to open file" << std::endl;
        Place place = *new Place(NULL, NULL, NULL);
        return place;
    }
}

Structure Data::getStructure() {
    std::vector<std::string> data;
    std::string line;
    std::ifstream myfile("Data/Structure.txt");
    
    if (myfile.is_open()) {
        while (getline (myfile,line)) {
            data.push_back(line);
        }
        myfile.close();
        
        Structure s = *new Structure();
        for (int i = 0; i < data.size(); i++) {
            std::cout << data[i] << std::endl;
            s.addNode(*new Node(split(data[i], '|')[0], split(split(data[i], '|')[1], ',')));
        }
        return s;
    } else {
        std::cout << "Unable to open file" << std::endl;
        Structure struc = *new Structure();
        return struc;
    }
}

void Data::copyFile(std::string file, std::string name) {
    std::string temp;
    std::vector<std::string> lines = *new std::vector<std::string>();
    
    std::ifstream myfile("Data/" + file); //change this file only
    if (myfile.is_open()) {
        while (getline (myfile,temp)) {
            lines.push_back(temp);
        }
        myfile.close();
        
        std::ofstream newFile(name + ".txt");
        for (int j = 0; j < lines.size(); j++) {
            newFile << lines[j] << "\n";
        }
        newFile.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
}

void Data::copyFile(std::string file) {
    std::string temp;
    std::vector<std::string> lines = *new std::vector<std::string>();
    
    std::ifstream myfile("Data/" + file); //change this file only
    if (myfile.is_open()) {
        while (getline (myfile,temp)) {
            lines.push_back(temp);
        }
        myfile.close();
    
        std::ofstream newFile(file);
        for (int j = 0; j < lines.size(); j++) {
            newFile << lines[j] << "\n";
        }
        newFile.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
}

void Data::save(std::vector<std::string> file, std::string name) {
    std::ofstream myfile(name + ".txt");
    for (int i = 0; i < file.size(); i++) {
        myfile << file[i] + "\n";
    }
    myfile.close();
}

void Data::save(std::string line, std::string name) {
    std::vector<std::string> temp = load("PlaceItems");
    for (int i = 0; i < temp.size(); i++) {
        if (equals(temp[i].substr(0, name.length()), name)) {
            temp[i] = name + "|" + line;
        }
    }
    
    std::ofstream file("PlaceItems.txt");
    for (int i = 0; i < temp.size(); i++) {
        if (i != temp.size() - 1) file <<  temp[i] + "\n";
        else file << temp[i];
    }
    file.close();
}

std::vector<std::string> Data::load(std::string name) {
    std::string temp;
    std::vector<std::string> lines = *new std::vector<std::string>();
    std::ifstream myfile(name + ".txt");
    if (myfile.is_open()) {
        while (getline (myfile,temp)) {
            lines.push_back(temp);
        }
        myfile.close();
    }
    return lines;
}

std::vector<std::string> Data::createNew(std::string name) {
    std::vector<std::string> files = {"New.txt", "PlaceItems.txt"};
//    getline(std::cin,name);
    
    for (int i = 0; i < files.size(); i++) {
        if (i == 0) {
            copyFile(files[i], name);
        } else {
            copyFile(files[i]);
        }
    }
    return load(name);
}

bool Data::existingSave(std::string name) {
    std::ifstream myfile(name + ".txt");
    if (myfile.is_open()) {
        myfile.close();
        return true;
    } else {
        return false;
    }
}

