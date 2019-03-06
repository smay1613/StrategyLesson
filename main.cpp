#include "gameboard.h"
#include <iostream>

void printBoard(const GameBoard& board) {
    for (size_t i {0}; i < BoardSize; ++i) {
        for (size_t j {0}; j < BoardSize; ++j) {
            std::cout << (*board.get({i, j}) ? "1" : "_");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    auto& board = GameBoard::instance();
    printBoard(board);
    board.move({6, 0}, {5, 0});
    board.move({1, 0}, {2, 0});
    printBoard(board);

    return 0;
}
