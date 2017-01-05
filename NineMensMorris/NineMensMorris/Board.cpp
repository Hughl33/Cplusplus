//
//  Board.cpp
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#include "Board.h"
Board::Board(std::vector<Vertex> i) {
    players = *new std::vector<Player>();
    players.push_back(*new Player(Colour::ColourCode::WHITE));
    players.push_back(*new Player(Colour::ColourCode::BLACK));
    vertices = i;
}

Vertex* Board::getVertex(int i) {
    return &vertices[i];
}

std::vector<Vertex> Board::getVertices() {
    return vertices;
}

int Board::numberOfVertices() {
    return (int)vertices.size();
}

Player* Board::getPlayer(int i) {
    return &players[i];
}

std::vector<Player> Board::getPlayers() {
    return players;
}

bool Board::move(int turn, int current, int selected) {
    bool result = false;
    int target = 0;
    switch (players[turn].getPlayState()) {
        case PlayState::State::PLACE:
            result = Move::performPlace(players[turn], *getVertex(current - 1));
            players[turn].setMove(getVertex(current - 1)->getID(), getVertex(current - 1)->getID());
            break;
        case PlayState::State::SLIDE:
            result = Move::performSlide(*getVertex(selected - 1), *getVertex(current - 1));
            players[turn].setMove(getVertex(selected - 1)->getID(), getVertex(current - 1)->getID());
            break;
        case PlayState::State::HOP:
            result = Move::performHop(*getVertex(selected - 1), *getVertex(current - 1));
            players[turn].setMove(getVertex(selected - 1)->getID(), getVertex(current - 1)->getID());
            break;
        case PlayState::State::REMOVE:
            if (turn == 0) target = 1;
            result = Move::performRemove(players[target], *getVertex(current - 1));
            players[turn].setMove(getVertex(current - 1)->getID(), getVertex(current - 1)->getID());
            break;
        default:
            Interface::broadcast("Error: Unknown/Unimplemented move has been utilised...");
            break;
    }
    return result;
}

void Board::move(int a, int b) {
    Move::performUndo(players[a], players[b], vertices);
}

bool Board::update(int& turn) {
    bool end = false;
    if (players[turn].getPlayState() != PlayState::State::REMOVE)
        for (int i = 0; i < players.size(); i++) players[i].update();
    
    if (players[0].getPlayState() == PlayState::State::PLACE && players[1].getPlayState() != PlayState::PLACE) {
        end = true;
        for (int i = 0; i < vertices.size(); i++)
            if (players[turn].getPiece(0)->getColour() == vertices[i].getPiece()->getColour())
                for (int j = 0; j < vertices[i].neighbourSize(); j++)
                    if (!vertices[vertices[i].getNeighbour(j) - 1].ifOccupied())
                        end = false;
        if (end) {
            if (turn == 0) turn += 1;
            else if (turn == 1) turn -= 1;
        }
        
    }
    
    for (int i = 0; i < players.size(); i++) {
        if (players[i].piecesLeft() < 3) {
            end = true;
            if (turn == 0) turn += 1;
            else if (turn == 1) turn -= 1;
        }
    }
    return end;
}