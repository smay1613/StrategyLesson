#include "gameboard.h"
#include <iostream>

void printBoard(const GameBoard& board) {
    for (size_t i {0}; i < BoardSize; ++i) {
        for (size_t j {0}; j < BoardSize; ++j) {
            const auto& piece = *board.get({i, j});
            if (piece) {
                std::cout << (piece->side() == Side::White ? "W " : "B ");
            } else {
                std::cout << "_ ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    auto& board = GameBoard::instance();
    printBoard(board);
    board.move({6, 0}, {5, 0}); // white pawn
    board.move({1, 0}, {2, 0}); // black pawn

    board.move({5, 0}, {4, 0}); // white +1
    board.move({4, 0}, {3, 0}); // white +1

    board.move({1, 1}, {2, 1}); // black pawn
    board.move({2, 1}, {3, 0}); // black pawn beats white

    printBoard(board);

    return 0;
}
