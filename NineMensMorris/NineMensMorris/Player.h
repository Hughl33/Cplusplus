//
//  Player.h
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#ifndef __NineMensMorris__Player__
#define __NineMensMorris__Player__

#include <iostream>
#include <vector>
#include "LastMove.h"
#include "Piece.h"
#include "PlayState.h"

class Player {
private:
    std::vector<Piece> pieces;
    PlayState::State playState;
    LastMove last;
public:
    Player(Colour::ColourCode c);
    PlayState::State getPlayState();
    void setState(PlayState::State s);
    Piece *getPiece(int i);
    int piecesLeft();
    void addPiece();
    void removePiece();
    LastMove getMove();
    void setMove(int f, int t);
    void clearMove();
    void update();
};

#endif /* defined(__NineMensMorris__Player__) */
