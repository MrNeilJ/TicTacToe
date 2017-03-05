/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 3.3.2017
 *
 * Description: This file hosts the member functions of the
 * board class.  These functions allow the user to create
 * a board, set moves on the blank board, as well as check
 * the status of the game to see if there is a winner or a
 * draw.
**************************************************************/

#include <iostream>
#include "Board.hpp"

/**************************************************************
 *                  Board::Board
 * Description: Constructor for the class to allow the user
 * to build a blank table 3 x 3 array
**************************************************************/
Board::Board()
{
    // Loop through the array and set the values to '.' (empty spaces)
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            table[i][j] = '.';
        }
    }
}

/**************************************************************
 *                  Board::makeMove
 * Description: Member function that allows the user to provide
 * an x / y coordinate of where they would like to set their
 * move.
**************************************************************/
bool Board::makeMove(int x, int y, bool playerTurn)
{
    // Check to make sure the space is empty, if so, inform the person that the move they made is illegal
    if (table[x][y] != '.')
    {
        std::cout << "That square is already taken" << std::endl;
        return false;
    }
    else if (playerTurn == true)
    {
        table[x][y] = 'x';

        return true;
    }
    else if (playerTurn == false)
    {
        table[x][y] = 'o';
        return true;
    }

    //
    else
    {
        return false;
    }
}

/**************************************************************
 *                  Board::gameState
 * Description: Member function that checks the status of the
 * game to see if there was a winning move, a game tie, or
 * if the game is still unfinished.  It does this by checking
 * all available spaces.
**************************************************************/
Board::Status Board::gameState()
{
    // Check to see if anyone won vertically
    for (int i = 0; i < 3; i++)
    {
        // Check to see if anyone won horizontally
        if (table[i][0] == 'x' && table[i][1] == 'x' && table[i][2] == 'x')
        {
            return X_WON;
        }
        else if (table[i][0] == 'o' && table[i][1] == 'o' && table[i][2] == 'o')
        {
            return O_WON;
        }
    }

    // Check to see if anyone won horizontally
    for (int i = 0; i < 3; i++)
    {
        if (table[0][i] == 'x' && table[1][i] == 'x' && table[2][i] == 'x')
        {
            return X_WON;
        }
        else if (table[0][i] == 'o' && table[1][i] == 'o' && table[2][i] == 'o')
        {
            return O_WON;
        }
    }

    // Check to see if anyone won diagonally
    if (table[0][0] == 'x' && table[1][1] == 'x' && table[2][2] == 'x')
    {
        return X_WON;
    }
    else if (table[0][2] == 'x' && table[1][1] == 'x' && table[2][0] == 'x')
    {
        return X_WON;
    }

    else if (table[0][0] == 'o' && table[1][1] == 'o' && table[2][2] == 'o')
    {
        return O_WON;
    }
    else if (table[0][2] == 'o' && table[1][1] == 'o' && table[2][0] == 'o')
    {
        return O_WON;
    }

    // Check to see if there are any free spaces
    bool freeSpace = false;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (table[i][j] == '.')
            {
                freeSpace = true;
            }
        }
    }
    if (!freeSpace)
    {
        return DRAW;
    }

    return UNFINISHED;
}

/**************************************************************
 *                  Board::print
 * Description: Member function that prints out the current
 * class array, laid out to be visually pleasant and easy
 * to follow.
**************************************************************/
void Board::print()
{
    // Create a gap below text and board
    std::cout << "\n";
    // Print first row of the board
    std::cout << "  0 1 2" << std::endl;
    // Loop through the array to print out the rest of the rows
    for (int i = 0; i < 3; i++)
    {
        std::cout << i;
        for (int j = 0; j < 3; j++)
        {
            std::cout << " " << table[i][j];
        }
        std::cout << "\n";

    }
    // Create a gap below the board and next line of text
    std::cout << "\n";
}





