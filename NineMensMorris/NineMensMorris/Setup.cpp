//
//  Setup.cpp
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#include "Setup.h"
std::vector<std::string> &Setup::split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> Setup::split(const std::string &s, char delim) {
    std::vector<std::string> elems = *new std::vector<std::string>();
    split(s, delim, elems);
    return elems;
}

std::vector<std::string> Setup::readFile(std::string file) {
    std::vector<std::string> data;
    std::string line;
    std::ifstream myfile(file);
    if (myfile.is_open()) {
        while (getline (myfile,line)) data.push_back(line);
        myfile.close();
        return data;
    } else {
        std::cout << "Unable to open file" << std::endl;
        return data;
    }
}

std::vector<Point2d> Setup::initCoords() {
    std::vector<Point2d> tempCoords = *new std::vector<Point2d>;
    std::vector<std::string> temp = readFile("Coordinates.txt");

    for (int i = 0; i < 24; i++) {
        Point2d coord = *new Point2d;
        coord.x = atoi(split(temp[i], ',')[0].c_str());
        coord.y = atoi(split(temp[i], ',')[1].c_str());
        tempCoords.push_back(coord);
    }
    
    return tempCoords;
}

std::vector<Vertex> Setup::initVertices() {
    std::vector<Vertex> tempInts = *new std::vector<Vertex>;
    std::vector<Point2d> tempCoords = initCoords();
    std::vector<std::string> temp = readFile("Neighbours.txt");
    for (int i = 0; i < 24; i++) {
        std::vector<Link> tempNei = *new std::vector<Link>;
        std::vector<std::string> line = split(temp[i], ',');
        for (int j = 0; j < line.size(); j++) {
            Link l = *new Link;
            l.i = atoi(split(line[j], ':')[0].c_str());
            l.dir = split(line[j], ':')[1];
            tempNei.push_back(l);
        }
        Vertex tempInt = *new Vertex(i + 1, tempCoords[i], tempNei);
        tempInts.push_back(tempInt);
    }
    return tempInts;
}

std::vector<Set> Setup::initMills() {
    std::vector<std::string> temp = readFile("Mills.txt");
    std::vector<Set> mills = *new std::vector<Set>;
    for (int i = 0; i < temp.size(); i++) {
        Set s = *new Set;
        s.a = atoi(split(temp[i], ',')[0].c_str());
        s.b = atoi(split(temp[i], ',')[1].c_str());
        s.c = atoi(split(temp[i], ',')[2].c_str());
        mills.push_back(s);
    }
    return mills;
}

Layout Setup::initInterface() {
    std::vector<std::string> temp = readFile("Layout.txt");
    std::vector<std::string> words = readFile("Instructions.txt");
    Layout layout = *new Layout;
    for (int i = 0; i < 41; i++) layout.board.push_back(temp[i]);
    for (int i = 41; i < 46; i++) layout.selector.push_back(temp[i]);
    for (int i = 46; i < 51; i++) layout.selected.push_back(temp[i]);
    for (int i = 51; i < 69; i++) layout.info.push_back(temp[i]);
    for (int i = 69; i < 72; i++) layout.piece.push_back(temp[i]);
    for (int i = 0; i < words.size(); i++) layout.instructions.push_back(words[i]);
    return layout;
}















