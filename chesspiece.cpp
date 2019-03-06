#include "chesspiece.h"
#include <algorithm>

bool operator==(const BoardCellPosition& lhs, const BoardCellPosition& rhs)
{
    return lhs.column == rhs.column
            && lhs.row == rhs.row;
}

ChessPiece::ChessPiece(Side side, BoardCellPosition position)
    : m_side {side},
      m_position {position}
{
}

void ChessPiece::setMoveStrategy(std::unique_ptr<IMoveStrategy> moveStrategy)
{
    m_moveStrategy.reset(moveStrategy.release());
}

bool ChessPiece::move(BoardCellPosition toPosition)
{
    if (!m_moveStrategy) {
        return false;
    }
    const std::vector<BoardCellPosition>& legalMoves = m_moveStrategy->getAvailableMoves(*this);
    bool isLegalMove {std::find(legalMoves.begin(), legalMoves.end(), toPosition) != legalMoves.end()};
    if (isLegalMove) {
        m_isFirstMove = false;
        return true;
    } else {
        return false;
    }
}

bool ChessPiece::isFirstMove() const
{
    return m_isFirstMove;
}

BoardCellPosition ChessPiece::position() const
{
    return m_position;
}

void ChessPiece::setPosition(const BoardCellPosition &position)
{
    m_position = position;
}

Side ChessPiece::side() const
{
    return m_side;
}
