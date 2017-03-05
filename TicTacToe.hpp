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
