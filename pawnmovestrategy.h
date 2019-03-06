#ifndef PAWNMOVESTRATEGY_H
#define PAWNMOVESTRATEGY_H
#include "imovestrategy.h"

class PawnMoveStrategy : public IMoveStrategy
{
public:
    std::vector<BoardCellPosition> getAvailableMoves(const ChessPiece& piece) override;

private:
    bool isValidPosition(size_t row, size_t column);
};

#endif // PAWNMOVESTRATEGY_H