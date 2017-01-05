//
//  Undo.h
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//

#ifndef __NineMensMorris__Undo__
#define __NineMensMorris__Undo__

#include <iostream>
#include "Move.h"

class Undo : public Move {
private:
public:
    void static performMove(Player& p, Player& q, Board& b);
    void static undoPlace(Player& p, Vertex& a);
    void static undoMove(Player& p, Vertex& a, Vertex& b);
    void static undoRemove(Player& p, Player& q, Vertex& a);
};

#endif /* defined(__NineMensMorris__Undo__) */
