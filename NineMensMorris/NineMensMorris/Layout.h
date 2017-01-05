//
//  Layout.h
//  NineMensMorris
//
//  Created by Hugh Lee on 9/05/2016.
//  Copyright © 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#ifndef Layout_h
#define Layout_h
#include <vector>

class Layout {
public:
    std::vector<std::string> board;
    std::vector<std::string> selector;
    std::vector<std::string> selected;
    std::vector<std::string> info;
    std::vector<std::string> piece;
    std::vector<std::string> instructions;
};

#endif /* Layout_h */
