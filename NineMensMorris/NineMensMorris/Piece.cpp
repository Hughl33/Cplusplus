//
//  Piece.cpp
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#include "Piece.h"
Piece::Piece(Colour::ColourCode c) {
    colour = c;
    state = false;
}

Colour::ColourCode Piece::getColour() {
    return colour;
}

bool Piece::getState() {
    return state;
}

void Piece::activate() {
    state = true;
}

void Piece::deactivate() {
    state = false;
}