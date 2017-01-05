//
//  Remove.cpp
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//

#include "Remove.h"
bool Remove::performMove(Player& p, Vertex& a) {
    if (a.ifOccupied()) {
        if (p.getPiece(0)->getColour() == a.getPiece().getColour()) {
            p.removePiece();
            a.remove();
        } else {
            Interface::broadcast("This move is invalid! You can't choose your own piece.");
            std::cout << "This move is invalid! You can't choose your own piece." << std::endl;
            return false;
        }
    } else {
        Interface::broadcast("This move is invalid! There is no piece there!");
        std::cout << "This move is invalid! There is no piece there!" << std::endl;
        return false;
    }
    return true;
}