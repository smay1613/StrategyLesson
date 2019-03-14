#include "rockmoventstrategy.h"
#include "gameboard.h"

std::vector<BoardCellPosition> RockMoventStrategy::getAvailableMoves(const ChessPiece& piece)
{
    std::vector<BoardCellPosition> result {};
    const GameBoard& board {GameBoard::instance()};
    const BoardCellPosition& currentPosition = piece.position();

    return result;
}

bool RockMoventStrategy::isValidPosition(size_t row, size_t column)
{
    return column < BoardSize && row < BoardSize;
}
