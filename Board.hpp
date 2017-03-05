/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 3.3.2017
 *
 * Description: This program hosts a function known as stdDev
 * which allows the user to provide it with an array of pointers
 * aimed at objects, as well as the size of array, and will
 * return to the user the standard deviation between the students
 * stored scores.
**************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

#include "TicTacToe.hpp"


class Board {
private:
    char table[3][3];

public:
    // Create the enumerated values to see current status of game
    enum Status {X_WON, O_WON, DRAW, UNFINISHED};

    // Initializes the board
    Board();

    // Allow the user to make their next move on the board and make sure it is
    // a legal move
    bool makeMove(int x, int y, bool playerTurn);

    // Return the Status of the game to see if some has won, a draw, or still going
    Status gameState();

    // Print the current board in a visually pleasing layout
    void print();

};

#endif //BOARD_HPP
