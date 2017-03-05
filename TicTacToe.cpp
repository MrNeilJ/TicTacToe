/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 3.3.2017
 *
 * Description: This program hosts the member functions of the
 * class TicTacToe.  The goal of this class is to initialize
 * a board and allow the user to successfully play a game of
 * TicTacToe until there is a winner or there are no more
 * available spots on the board.
**************************************************************/

#include "TicTacToe.hpp"
#include <iostream>
#include <cctype>

/**************************************************************
 *                  TicTacToe::TicTacToe
 * Description: Constructor function that takes in a character
 * value, letting the game know who have go first.
**************************************************************/
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

/**************************************************************
 *                  TicTacToe::play
 * Description: Member function that causes the game to loop
 * indefinitely until there are either no more moves or until
 * there is a winner.  It will create a board object and allow
 * the users to make move after move. It will then print out
 * the board after every move.  Once there is a change in
 * game status it will return the Console one of four responses
**************************************************************/
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
        case Board::UNFINISHED : std::cout << "GAME IS STILL PLAYING, KEEP GOING!" << std::endl;
    }
};
