/*
 Write a class called Board that represents a tic-tac-toe board.  It should have a 3x3 array as a data member,
 which will store the locations of the players' moves.  It should have a default constructor that initializes
 the 3x3 array to being empty.

 It should have a method called makeMove that takes the x and y coordinates of
 the move (see the example below) and which player's turn it is as parameters.  If that location is unoccupied,
 makeMove should record the move and return true.  If that location is already occupied, makeMove should just
 return false.

 There should be a method called gameState that takes no parameters and returns one of the four
 following values: X_WON, O_WON, DRAW, or UNFINISHED - use an enum for this, not strings (the enum definition
 should go in Board.hpp).

 There should also be a method called print, which just prints out the current board
 to the screen.
*/
#include <iostream>
#include "Board.hpp"

// Constructor to initialize the main board
/* THIS IS HOW THE BOARD WILL LOOK
  0 1 2
0 x . .
1 . . .
2 . . .
 */

// Blank Constructor
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

bool Board::makeMove(int x, int y, bool playerTurn)
{
    // Check to make sure the space is empty, if, inform the person that the move they made is illegal
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
    else
    {
        return false;
    }
}

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





