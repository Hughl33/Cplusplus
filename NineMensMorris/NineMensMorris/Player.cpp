//
//  Player.cpp
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#include "Player.h"
Player::Player(Colour::ColourCode c) {
    pieces = *new std::vector<Piece>;
    for (int i = 0; i < 9; i++) {
        pieces.push_back(*new Piece(c));
    }
}

PlayState::State Player::getPlayState() {
    return playState;
}

void Player::setState(PlayState::State s) {
    playState = s;
}

Piece* Player::getPiece(int i) {
    return &pieces[i];
}

int Player::piecesLeft() {
    return (int)pieces.size();
}

void Player::addPiece() {
    pieces.push_back(*new Piece(pieces.front().getColour()));
}

void Player::removePiece() {
    pieces.erase(pieces.begin());
}

LastMove Player::getMove() {
    return last;
}

void Player::clearMove() {
    last.state = PlayState::State::NONE;
    last.fInt = 0;
    last.tInt = 0;
}

void Player::setMove(int f, int t) {
    last.state = playState;
    last.fInt = f;
    last.tInt = t;
}

void Player::update() {
    int a = 0;
    for (int i = 0; i < pieces.size(); i++) {
        if (pieces[i].getState()) a++;
    }
    if (a < pieces.size()) {
        playState = PlayState::State::PLACE;
    } else if (pieces.size() <= 3) {
        playState = PlayState::State::HOP;
    } else {
        playState = PlayState::State::SLIDE;
    }
}