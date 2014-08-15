//
//  Player.cpp
//  GridWorld
//
//  Created by Hugh Lee on 5/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Player.h"

Player::Player (int posY, int posX) {
    this->posX = posX;
    this->posY = posY;
}

int Player::PositionX () {
    return posX;
}

int Player::PositionY () {
    return posY;
}

void Player::up() {
    posY -= 1;
}

void Player::down() {
    posY += 1;
}

void Player::left() {
    posX -= 1;
}

void Player::right() {
    posX += 1;
}