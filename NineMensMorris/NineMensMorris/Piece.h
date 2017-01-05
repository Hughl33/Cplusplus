//
//  Piece.h
//  NineMensMorris
//
//  Created by Hugh Lee on 22/05/2015.
//  Copyright (c) 2015 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#ifndef __NineMensMorris__Piece__
#define __NineMensMorris__Piece__

#include <iostream>
#include <curses.h>
#include "Colour.h"

class Piece {
private:
    Colour::ColourCode colour;
    bool state;
public:
    Piece(Colour::ColourCode c);
    Colour::ColourCode getColour();
    bool getState();
    void activate();
    void deactivate();
};

#endif /* defined(__NineMensMorris__Piece__) */
