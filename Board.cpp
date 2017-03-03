/*
 Write a class called Board that represents a tic-tac-toe board.  It should have a 3x3 array as a data member,
 which will store the locations of the players' moves.  It should have a default constructor that initializes
 the 3x3 array to being empty.  It should have a method called makeMove that takes the x and y coordinates of
 the move (see the example below) and which player's turn it is as parameters.  If that location is unoccupied,
 makeMove should record the move and return true.  If that location is already occupied, makeMove should just
 return false.  There should be a method called gameState that takes no parameters and returns one of the four
 following values: X_WON, O_WON, DRAW, or UNFINISHED - use an enum for this, not strings (the enum definition
 should go in Board.hpp).  There should also be a method called print, which just prints out the current board
 to the screen.
*/

#include "Board.hpp"
