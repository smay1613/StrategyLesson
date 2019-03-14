#include "rockmoventstrategy.h"
#include "gameboard.h"

std::vector<BoardCellPosition> RockMoventStrategy::getAvailableMoves(const ChessPiece& piece)
{
    std::vector<BoardCellPosition> result {};
    const GameBoard& board {GameBoard::instance()};
    const BoardCellPosition& currentPosition = piece.position();
    size_t count;

    //0 - place row
    for (count = currentPosition.row-1; count < currentPosition.row; --count) {
        const BoardCellPosition nextForwardPosition {count, currentPosition.column};
        if (!*board.get(nextForwardPosition)) {
            result.push_back(nextForwardPosition);
        }
        else if (const auto& attackedPiece = *board.get(nextForwardPosition) ){
            if (attackedPiece->side() != piece.side()) {
                result.push_back(nextForwardPosition);
            }
            break;
        }
        else {
             break;
        }
    }

    //place - 7 row
    for (count = currentPosition.row+1; count < 8; ++count) {
        const BoardCellPosition nextForwardPosition {count, currentPosition.column};
        if (!*board.get(nextForwardPosition)) {
            result.push_back(nextForwardPosition);
        }
        else if (const auto& attackedPiece = *board.get(nextForwardPosition) ){
            if (attackedPiece->side() != piece.side()) {
                result.push_back(nextForwardPosition);
            }
            break;
        }
        else {
             break;
        }
    }

    //0 - place colum
    for (count = currentPosition.column-1; count < currentPosition.column; --count) {
        const BoardCellPosition nextForwardPosition {currentPosition.row, count};
        if (!*board.get(nextForwardPosition)) {
            result.push_back(nextForwardPosition);
        }
        else if (const auto& attackedPiece = *board.get(nextForwardPosition) ){
            if (attackedPiece->side() != piece.side()) {
                result.push_back(nextForwardPosition);
            }
            break;
        }
        else {
             break;
        }
    }
    //place - 7 colum
    for (count = currentPosition.column+1; count < 8; ++count) {
        const BoardCellPosition nextForwardPosition {currentPosition.row, count};
        if (!*board.get(nextForwardPosition)) {
            result.push_back(nextForwardPosition);
        }
        else if (const auto& attackedPiece = *board.get(nextForwardPosition) ){
            if (attackedPiece->side() != piece.side()) {
                result.push_back(nextForwardPosition);
            }
            break;
        }
        else {
             break;
        }
    }
    return result;
}

bool RockMoventStrategy::isValidPosition(size_t row, size_t column)
{
    return column < BoardSize && row < BoardSize;
}
