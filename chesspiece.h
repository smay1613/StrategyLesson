#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <memory>
#include "chesstypes.h"
#include "imovestrategy.h"

class ChessPiece final
{
public:
    ChessPiece(Side side = Side::Invalid, BoardCellPosition position = {-1u, -1u});

    void setMoveStrategy(std::unique_ptr<IMoveStrategy> moveStrategy);
    bool move(BoardCellPosition toPosition);

    bool isFirstMove() const;

    BoardCellPosition position() const;
    void setPosition(const BoardCellPosition &position);

    Side side() const;

private:
    Side m_side;
    BoardCellPosition m_position;
    std::unique_ptr<IMoveStrategy> m_moveStrategy;
    bool m_isFirstMove {true};
};

#endif // CHESSPIECE_H