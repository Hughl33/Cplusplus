//
//  Slide.cpp
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//

#include "Slide.h"
bool Slide::performMove(Vertex& a, Vertex& b) {
    int t = 0;
    for (int i = 0; i < a.directionSize(); i++) {
        if (a.getDirection(i).i == b.getID()) {
            t = b.getID();
            break;
        }
    }
    
    if (t == 0) {
        Interface::broadcast("Sorry, this move is invalid! You have to move the piece to a neighbouring intersection.");
        std::cout << "Sorry, this move is invalid! You have to move the piece to a neighbouring intersection." << std::endl;
        return false;
    } else {
        for (int i = 0; i < a.directionSize(); i++) {
            if (a.getDirection(i).i == t) {
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
        }
        return false;
    }
}