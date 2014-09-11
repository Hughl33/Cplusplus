//
//  Output.h
//  Zorkish
//
//  Created by Hugh Lee on 2/09/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#ifndef __Zorkish__Output__
#define __Zorkish__Output__

#include <iostream>
class Output {
private:
public:
    void static print(std::string s);
    void static printMenu();
    void static printItemDesc();
    void static printPlaceDesc();
    void static printAddItem();
    void static printDropItem();
};
#endif /* defined(__Zorkish__Output__) */
