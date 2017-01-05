//
//  Move.h
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#ifndef __NineMensMorris__Move__
#define __NineMensMorris__Move__

#include <iostream>
#include "Board.h"
#include "Interface.h"
#include "Vertex.h"
#include "Player.h"

class Move {
private:
    Move();
    void static undoPlace(Player& p, Vertex& a);
    void static undoMove(Player& p, Vertex& a, Vertex& b);
    void static undoRemove(Player& p, Player& q, Vertex& a);
public:
    bool static performPlace(Player& p, Vertex& a);
    bool static performSlide(Vertex& a, Vertex& b);
    bool static performHop(Vertex& a, Vertex& b);
    bool static performRemove(Player& p, Vertex& a);
    void static performUndo(Player& p, Player& q, std::vector<Vertex>& v);
};

#endif /* defined(__NineMensMorris__Move__) */
