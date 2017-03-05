/*
 Write a class called TicTacToe that allows two people to play a game.  This class will have a field for a
 Board object and a field to keep track of which player's turn it is.  It should have a constructor that
 takes a char parameter that specifies whether 'x' or 'o' should have the first move.

 It should have a method called play that starts the game.  The play method should keep looping, asking the
 correct player for their move and sending it to the board (with makeMove) until someone has won or it's a
 draw (as indicated by gameState), and then declare what the outcome was.
*/

#include "TicTacToe.hpp"
#include <iostream>
#include <cctype>


TicTacToe::TicTacToe(char firstPlayer)
{

    if (std::tolower(firstPlayer) == 'x')
    {
        isXFirst = true;
    }
    else
    {
        isXFirst = false;
    }
}

void TicTacToe::play()
{
    Board newBoard1;

    do
    {
        // Print the board
        newBoard1.print();

        // Ask the next player for their move
        if (isXFirst == true)
        {
            std::cout << "Player X: please enter your move." << std::endl;
        }
        else
        {
            std::cout << "Player O: please enter your move." << std::endl;
        }

        // Variables used for the user to store their current answer
        int x;
        int y;

        std::cin >> x;
        std::cin >> y;

        bool moveSuccess = newBoard1.makeMove(x, y, isXFirst);
        if (moveSuccess == true)
        {
            if (isXFirst == true)
            {
                isXFirst = false;
            }
            else
            {
                isXFirst = true;
            }
        }
    } while(newBoard1.gameState() == Board::UNFINISHED);

    newBoard1.print();

    Board::Status result = newBoard1.gameState();

    switch (result) {
        case Board::X_WON : std::cout << "CONGRATS, X, YOU WON!" << std::endl;
            break;
        case Board::O_WON : std::cout << "CONGRATS, O, YOU WON!" << std::endl;
            break;
        case Board::DRAW : std::cout << "CONGRATS, NEITHER OF YOU WON!" << std::endl;
            break;
    }
};
