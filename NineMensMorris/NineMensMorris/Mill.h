//
//  Mill.h
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#ifndef __NineMensMorris__Mill__
#define __NineMensMorris__Mill__

#include <iostream>
#include <vector>
#include "Board.h"
#include "Vertex.h"
#include "Player.h"
#include "Set.h"

class Mill {
private:
    std::vector<Set> mills;
public:
    Mill(std::vector<Set> m);
    bool check(Board b, int current);
    bool checkNonMillPieces(Board b, Player p);
};

#endif /* defined(__NineMensMorris__Mill__) */
