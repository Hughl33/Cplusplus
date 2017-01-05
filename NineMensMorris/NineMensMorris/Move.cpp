//
//  Move.cpp
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#include "Move.h"

bool Move::performPlace(Player& p, Vertex& a) {
    if (a.ifOccupied()) {
        Interface::broadcast("This move is invalid! There is already a piece there!");
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

bool Move::performSlide(Vertex& a, Vertex& b) {
    for (int i = 0; i < a.neighbourSize(); i++) {
        if (a.getNeighbour(i) == b.getID()) {
            if (b.ifOccupied()) {
                Interface::broadcast("Sorry, you cannot move there! There is already a piece on that intersection.");
                return false;
            } else {
                b.place(*a.getPiece());
                a.remove();
                return true;
            }
        }
    }
    Interface::broadcast("Sorry, this move is invalid! You have to move the piece to a neighbouring intersection.");
    return false;
}

bool Move::performHop(Vertex& a, Vertex& b) {
    if (b.ifOccupied()) {
        Interface::broadcast("Sorry, you cannot move there! There is already a piece on that intersection.");
        return false;
    } else {
        b.place(*a.getPiece());
        a.remove();
        return true;
    }
}

bool Move::performRemove(Player& p, Vertex& a) {
    if (a.ifOccupied()) {
        if (p.getPiece(0)->getColour() == a.getPiece()->getColour()) {
            p.removePiece();
            a.remove();
        } else {
            Interface::broadcast("This move is invalid! You can't choose your own piece.");
            return false;
        }
    } else {
        Interface::broadcast("This move is invalid! There is no piece there!");
        return false;
    }
    return true;
}

void Move::performUndo(Player& p, Player& q, std::vector<Vertex>& v) {
    switch (p.getMove().state) {
        case PlayState::State::PLACE:
            undoPlace(p, v[p.getMove().fInt - 1]);
            break;
        case PlayState::State::SLIDE:
        case PlayState::State::HOP:
            undoMove(p, v[p.getMove().fInt - 1], v[p.getMove().tInt - 1]);
            break;
        case PlayState::State::REMOVE:
            undoRemove(p, q, v[p.getMove().fInt - 1]);
            break;
        default:
            break;
    }
}

void  Move::undoPlace(Player& p, Vertex& a) {
    for (int i = 0; i < p.piecesLeft(); i++) {
        if (p.getPiece(i)->getState()) {
            p.getPiece(i)->deactivate();
            a.remove();
            break;
        }
    }
    p.setState(p.getMove().state);
    p.clearMove();
}

void Move::undoMove(Player& p, Vertex& a, Vertex& b) {
    a.place(*b.getPiece());
    b.remove();
    p.setState(p.getMove().state);
    p.clearMove();
}

void Move::undoRemove(Player& p, Player& q, Vertex& a) {
    q.addPiece();
    for (int i = 0; i < q.piecesLeft(); i++) {
        if (!q.getPiece(i)->getState()) {
            q.getPiece(i)->activate();
            a.place(*q.getPiece(i));
            break;
        }
    }
    p.setState(p.getMove().state);
    p.clearMove();
}