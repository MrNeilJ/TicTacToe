//
// Created by Neil Johnson on 3/3/17.
//

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Board.hpp"


class TicTacToe {
private:
    bool isXFirst;


public:
    TicTacToe(char firstPlayer);

    // Set the board officially
    void play();
};


#endif //TICTACTOE_HPP
