//
//  Fly.cpp
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//

#include "Fly.h"
bool Fly::performMove(Vertex& a, Vertex& b) {
    if (b.ifOccupied()) {
        Interface::broadcast("Sorry, you cannot move there! There is already a piece on that intersection.");
        std::cout << "Sorry, you cannot move there! There is already a piece on that intersection." << std::endl;
        return false;
    } else {
        b.place(a.getPiece());
        a.remove();
        return true;
    }
}