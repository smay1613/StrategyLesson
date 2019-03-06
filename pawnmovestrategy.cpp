#include "pawnmovestrategy.h"
#include "gameboard.h"

std::vector<BoardCellPosition> PawnMoveStrategy::getAvailableMoves(const ChessPiece& piece)
{
    std::vector<BoardCellPosition> result {};
    const GameBoard& board {GameBoard::instance()};
    const BoardCellPosition& currentPosition = piece.position();

    int stepOffset {piece.side() == Side::White ? -1
                                                : 1};

    const size_t nextRowPosition = currentPosition.row + stepOffset;

    // next forward, must be empty
    const BoardCellPosition nextForwardPosition {nextRowPosition,
                                                 currentPosition.column};
    if (!*board.get(nextForwardPosition)) {
        result.push_back(nextForwardPosition);
    }

    std::array<int, 2> sideOffsets {-1, 1};

    // attack, must be with opposite side piece
    for (int offset : sideOffsets) {
        if (isValidPosition(nextRowPosition, currentPosition.column + offset)) {
            const BoardCellPosition leftAttackPosition {nextRowPosition,
                                                        currentPosition.column + offset};
            if (const auto& attackedPiece = *board.get(leftAttackPosition)) {
                if (attackedPiece->side() != piece.side()) {
                    result.push_back(leftAttackPosition);
                }
            }
        }
    }

    // two next if empty
    if (piece.isFirstMove()) {
        const BoardCellPosition twoNextForwardPosition {nextRowPosition + stepOffset,
                                                        currentPosition.column};
        if (!*board.get(twoNextForwardPosition)) {
            result.push_back(twoNextForwardPosition);
        }
    }

    return result;
}

bool PawnMoveStrategy::isValidPosition(size_t row, size_t column)
{
    return column < BoardSize && row < BoardSize;
}
