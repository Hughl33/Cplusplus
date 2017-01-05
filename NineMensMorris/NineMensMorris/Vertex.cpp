//
//  Vertex.cpp
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#include "Vertex.h"
Vertex::Vertex(int i, Point2d c, std::vector<Link> n) : piece(Colour::ColourCode::BLANK) {
    ID = i;
    neighbours = n;
    coords = c;
    occupied = false;
}

int Vertex::getID() {
    return ID;
}

Piece* Vertex::getPiece() {
    return &piece;
}

Point2d Vertex::getCoords() {
    return coords;
}

std::vector<Link> Vertex::getNeighbours() {
    return neighbours;
}

int Vertex::getNeighbour(int i) {
    return neighbours[i].i;
}

int Vertex::neighbourSize() {
    return (int)neighbours.size();
}

bool Vertex::ifOccupied() {
    return occupied;
}

void Vertex::place(Piece a) {
    piece = a;
    occupied = true;
}

void Vertex::remove() {
    piece = *new Piece(Colour::ColourCode::BLANK);
    occupied = false;
}


