//
// Created by Neil Johnson on 3/3/17.
//

#ifndef BOARD_HPP
#define BOARD_HPP

#include "TicTacToe.hpp"


class Board {
private:
    char table[3][3];
    int currentState = UNFINISHED;
public:

    enum Status {X_WON = 0, O_WON = 1, DRAW = 2, UNFINISHED = 3};
    // Initializes the board
    Board();

    bool makeMove(int x, int y, bool playerTurn);

    int gameState();

    void print();


    void hasWon();
};


#endif //BOARD_HPP
