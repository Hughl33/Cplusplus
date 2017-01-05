//
//  Game.cpp
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#include "Game.h"
Game::Game(int w, int h) : board(Setup::initVertices()), gui(Setup::initInterface(), w, h), mill(Setup::initMills()) {
    current = 1;
    selected = 0;
    turn = 0;
    end = false;
}

bool Game::isRunning() {
    return !end;
}

void Game::update() {
    int target = 0;
    if (turn == 0) target = 1;
    int d = ' ';
    d = wgetch(gui.getWindow());
    if (d == KEY_UP) {
        for (int i = 0; i < board.getVertex(current - 1)->neighbourSize(); i++) {
            if (board.getVertex(current - 1)->getNeighbours()[i].dir == "north") {
                current = board.getVertex(current - 1)->getNeighbour(i);
                break;
            }
        }
    } else if (d == KEY_DOWN) {
        for (int i = 0; i < board.getVertex(current - 1)->neighbourSize(); i++) {
            if (board.getVertex(current - 1)->getNeighbours()[i].dir == "south") {
                current = board.getVertex(current - 1)->getNeighbour(i);
                break;
            }
        }
    } else if (d == KEY_LEFT) {
        for (int i = 0; i < board.getVertex(current - 1)->neighbourSize(); i++) {
            if (board.getVertex(current - 1)->getNeighbours()[i].dir == "west") {
                current = board.getVertex(current - 1)->getNeighbour(i);
                break;
            }
        }
    } else if (d == KEY_RIGHT) {
        for (int i = 0; i < board.getVertex(current - 1)->neighbourSize(); i++) {
            if (board.getVertex(current - 1)->getNeighbours()[i].dir == "east") {
                current = board.getVertex(current - 1)->getNeighbour(i);
                break;
            }
        }
    } else if (d == '\n') {
        if (board.getPlayer(turn)->getPlayState() == PlayState::State::REMOVE) {
            if (mill.checkNonMillPieces(board, *board.getPlayer(target))) {
                if (!mill.check(board, current)) {
                    if (board.move(turn, current, selected)) {
                        board.getPlayer(turn)->update();
                        if (turn == 0) turn += 1;
                        else if (turn == 1) turn -= 1;
                    }
                } else {
                    Interface::broadcast("You can't remove pieces that are currently in a mill, unless there are no other pieces left.");
                }
            } else {
                if (board.move(turn, current, selected)) {
                    board.getPlayer(turn)->update();
                    if (turn == 0) turn += 1;
                    else if (turn == 1) turn -= 1;
                }
            }
        } else if (board.getPlayer(turn)->getPlayState() == PlayState::State::PLACE) {
            if (board.move(turn, current, selected)) {
                if (mill.check(board, current)) {
                    Interface::broadcast("Player " + std::to_string(turn + 1) + " made a mill! ");
                    board.getPlayer(turn)->setState(PlayState::State::REMOVE);
                }
                if (board.getPlayer(turn)->getPlayState() != PlayState::State::REMOVE) {
                    if (turn == 0) turn += 1;
                    else if (turn == 1) turn -= 1;
                }
            }
        } else {
            if (selected == 0) {
                if (board.getVertex(current - 1)->ifOccupied()) {
                    if (board.getVertex(current - 1)->getPiece()->getColour() == turn + 1) {
                        selected = current;
                    } else {
                        Interface::broadcast("Sorry, that is your opponents piece, you cannot move that.");
                    }
                } else {
                    Interface::broadcast("There is no piece on that Vertex");
                }
            } else {
                if (board.move(turn, current, selected)) {
                    selected = 0;
                    if (mill.check(board, current)) {
                        Interface::broadcast("Player " + std::to_string(turn + 1) + " made a mill! ");
                        std::cout << "Player " << turn + 1 << " made a mill! " << std::endl;
                        board.getPlayer(turn)->setState(PlayState::State::REMOVE);
                    }
                    if (board.getPlayer(turn)->getPlayState() != PlayState::State::REMOVE) {
                        if (turn == 0) turn += 1;
                        else if (turn == 1) turn -= 1;
                    }
                }
            }
        }
    } else if (d == 'q') {
        if (board.getPlayer(target)->getMove().state == PlayState::State::NONE) {
            Interface::broadcast("Sorry, you cannot undo anymore.");
        } else {
            if (board.getPlayer(turn)->getPlayState() == PlayState::State::REMOVE) board.move(turn, target);
            else {
                board.move(target, turn);
                if (turn == 0) turn += 1;
                else if (turn == 1) turn -= 1;
            }
        }
        selected = 0;
    } else if (d == 'w') {
        selected = 0;
    } else if (d == 27) {
        Interface::broadcast("Player " + std::to_string(turn + 1) + " has quit the game! Press Enter to Close...");
        end = true;
    }
    
    if (board.update(turn)) {
        Interface::broadcast("Player " + std::to_string(turn + 1) + " has won the game! Press Enter to Close...");
        end = true;
    }
}

void Game::render() {
    gui.render(board.getVertices(), current, board.getPlayers(), selected);
}

void Game::close() {
    gui.close();
}