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

/**************************************************************
 *                  TicTacToe::TicTacToe
 * Description: Blank Constructor function that prompts the
 * user to input which player should go first.
**************************************************************/
TicTacToe::TicTacToe()
{
    char firstPlayer;
    std::cout << "Which of you would like to go first? X or O?" << std::endl;
    std::cin >> firstPlayer;

    // If the user inputs 'x', set the first move to X
    if (tolower(firstPlayer) == 'x')
    {
        xTurn = true;
    }
        // Otherwise set the first move to O
    else
    {
        xTurn = false;
    }
}
/**************************************************************
 *                  TicTacToe::TicTacToe
 * Description: Constructor function that takes in a character
 * value, letting the game know who have go first.
**************************************************************/
TicTacToe::TicTacToe(char firstPlayer)
{
    // If the user inputs 'x', set the first move to X
    if (tolower(firstPlayer) == 'x')
    {
        xTurn = true;
    }
    // Otherwise set the first move to O
    else
    {
        xTurn = false;
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
    do
    {
        // Print the board
        newBoard1.print();

        // Ask the next player for their move
        if (xTurn)
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

        // Ask the user for two values, an x and y coordinate
        std::cin >> x;
        std::cin >> y;

        // Boolean to store the results of the last move, to ensure it was successful
        bool moveSuccess = newBoard1.makeMove(x, y, xTurn);

        // If the move was successful, switch to the next player.
        if (moveSuccess)
        {
            if (xTurn)
            {
                xTurn = false;
            }
            else
            {
                xTurn = true;
            }
        }
    } while(newBoard1.gameState() == Board::UNFINISHED);

    // Print the final board results so they can view the final move once the game is over
    newBoard1.print();

    // Find out the final result of the match
    Board::Status result = newBoard1.gameState();

    // Roll through all available return options for game State to inform them of who won!
    switch (result) {
        case Board::X_WON : std::cout << "CONGRATS, X, YOU WON!" << std::endl;
            break;
        case Board::O_WON : std::cout << "CONGRATS, O, YOU WON!" << std::endl;
            break;
        case Board::DRAW : std::cout << "CONGRATS, NEITHER OF YOU WON!" << std::endl;
            break;
        case Board::UNFINISHED : std::cout << "GAME IS STILL PLAYING, KEEP GOING!" << std::endl;
    }
}

