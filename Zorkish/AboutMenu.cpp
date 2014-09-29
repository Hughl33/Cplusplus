//
//  AboutMenu.cpp
//  Zorkish
//
//  Created by Hugh Lee on 19/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "AboutMenu.h"
AboutMenu::AboutMenu() {
    title = "About";
}

void AboutMenu::Render() {
    std::cout << hr << std::endl;
    std::cout << "Zorkish :: " << title << std::endl;
    std::cout << hr << std::endl;
    std::cout << "Written by: Hugh Lee (OysterFinish)" << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter to return to the Main Menu" << std::endl;
    std::cin.get();
}