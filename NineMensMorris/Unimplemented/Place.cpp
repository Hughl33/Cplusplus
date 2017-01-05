//
//  Place.cpp
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//

#include "Place.h"
bool Place::performMove(Player& p, Vertex& a) {
    if (a.ifOccupied()) {
        Interface::broadcast("This move is invalid! There is already a piece there!");
        std::cout << "This move is invalid! There is already a piece there!" << std::endl;
        return false;
    } else {
        for (int i = 0; i < p.piecesLeft(); i++) {
            if (!p.getPiece(i)->getState()) {
                p.getPiece(i)->activate();
                a.place(*p.getPiece(i));
                break;
            }
        }
        return true;
    }
}