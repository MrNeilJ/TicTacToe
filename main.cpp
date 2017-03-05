#include <iostream>
#include "TicTacToe.hpp"

int main() {
    TicTacToe game1('x');
    game1.play();

    // EXAMPLE INPUTS FOR TESTING THE VALUES
    // TIE
    // 0 0 1 1 2 2 1 0 1 2 0 2 2 0 2 1 0 1
    // X WIN
    // 0 0 1 1 2 2 1 0 1 2 0 2 2 0 0 1 2 1
    // O WIN
    // 0 0 1 1 2 2 1 0 0 2 1 2



    return 0;
}