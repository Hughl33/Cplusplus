//
//  Undo.cpp
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//

#include "Undo.h"
void Undo::performMove(Player& p, Player& q, Board& b) {
    switch (p.getMove().state) {
        case PlayState::State::PLACE:
            undoPlace(p, *b.getVertex(p.getMove().fInt - 1));
            break;
        case PlayState::State::SLIDE:
        case PlayState::State::FLY:
            undoMove(p, *b.getVertex(p.getMove().fInt - 1), *b.getVertex(p.getMove().tInt - 1));
            break;
        case PlayState::State::REMOVE:
            undoRemove(p, q, *b.getVertex(p.getMove().fInt - 1));
            break;
        default:
            break;
    }
}

void Undo::undoPlace(Player& p, Vertex& a) {
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

void Undo::undoMove(Player& p, Vertex& a, Vertex& b) {
    a.place(b.getPiece());
    b.remove();
    p.setState(p.getMove().state);
    p.clearMove();
}

void Undo::undoRemove(Player& p, Player& q, Vertex& a) {
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