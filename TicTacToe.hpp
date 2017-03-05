//
// Created by Neil Johnson on 3/3/17.
//

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Board.hpp"


class TicTacToe {
private:
    bool isXFirst;
    Board currentGame;

public:

    TicTacToe(char firstPlayer);

    // Set the board officially


    bool play();
};


#endif //TICTACTOE_HPP
