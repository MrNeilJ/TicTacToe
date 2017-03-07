/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 3.3.2017
 *
 * Description: This program hosts the header of the
 * class TicTacToe.  The goal of this class is to initialize
 * a board and allow the user to successfully play a game of
 * TicTacToe until there is a winner or there are no more
 * available spots on the board.
**************************************************************/

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Board.hpp"


class TicTacToe {
private:
    // Boolean used to say tell which players turn it is / who is first
    bool xTurn;

    // Board object to build the layout of the game and add game functionality
    Board newBoard1;

public:
    // Blank Constructor, just in case the user forgets to add a char value
    TicTacToe();

    // Constructor, builds the board and sets the first player for the game
    TicTacToe(char firstPlayer);

    // Set the board officially
    void play();
};


#endif //TICTACTOE_HPP
