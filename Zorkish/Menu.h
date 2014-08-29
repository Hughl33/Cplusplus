//
//  Menu.h
//  Zorkish
//
//  Created by Hugh Lee on 19/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#ifndef __Zorkish__Menu__
#define __Zorkish__Menu__

#include <iostream>
class Menu {
protected:
    std::string title;
    std::string content;
    std::string hr = "===================================";
public:
    Menu() {}
    ~Menu(){}
    std::string Title();
    virtual void Render() = 0;
};
#endif /* defined(__Zorkish__Menu__) */
