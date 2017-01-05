//
//  Setup.h
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#ifndef __NineMensMorris__Setup__
#define __NineMensMorris__Setup__

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <dirent.h>
#include <vector>
#include "Vertex.h"
#include "Set.h"
#include "Link.h"
#include "Layout.h"

class Setup {
private:
    std::vector<std::string> static &split(const std::string &s, char delim, std::vector<std::string> &elems);
    std::vector<std::string> static split(const std::string &s, char delim);
    std::vector<std::string> static readFile(std::string file);
public:
    std::vector<Point2d> static initCoords();
    std::vector<Vertex> static initVertices();
    std::vector<Set> static initMills();
    Layout static initInterface();
};

#endif /* defined(__NineMensMorris__Setup__) */
