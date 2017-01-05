//
//  Set.h
//  NineMensMorris
//
//  Created by Hugh Lee on 9/05/2016.
//  Copyright © 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#ifndef Set_h
#define Set_h

class Set {
public:
    int a;
    int b;
    int c;
    bool Exists(int i) {
        return a == i || b == i || c == i;
    }
};

#endif /* Set_h */
