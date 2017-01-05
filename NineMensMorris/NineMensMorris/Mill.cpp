//
//  Mill.cpp
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2015.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#include "Mill.h"
Mill::Mill(std::vector<Set> m) {
    mills = m;
}

bool Mill::check(Board b, int current) {
    bool result = false;
    for (int i = 0; i < mills.size(); i++)
        if (mills[i].Exists(b.getVertex(current - 1)->getID())) {
            if (b.getVertex(current - 1)->getPiece()->getColour() ==
                b.getVertex(mills[i].a - 1)->getPiece()->getColour() &&
                b.getVertex(current - 1)->getPiece()->getColour() ==
                b.getVertex(mills[i].b - 1)->getPiece()->getColour() &&
                b.getVertex(current - 1)->getPiece()->getColour() ==
                b.getVertex(mills[i].c - 1)->getPiece()->getColour())
                result = true;
        }
    
    return result;
}

bool Mill::checkNonMillPieces(Board b, Player p) {
    for (int i = 0; i < b.numberOfVertices(); i++)
        if (b.getVertex(i)->getPiece()->getColour() == p.getPiece(0)->getColour())
            if (!check(b, b.getVertex(i)->getID()))
                return true;
    return false;
}