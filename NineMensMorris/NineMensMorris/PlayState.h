//
//  PlayState.h
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#ifndef NineMensMorris_PlayState_h
#define NineMensMorris_PlayState_h

#include <iostream>

class PlayState {
public:
    enum State {
        NONE = 0,
        PLACE = 1,
        SLIDE = 2,
        HOP = 3,
        REMOVE = 4
    };
};

#endif
