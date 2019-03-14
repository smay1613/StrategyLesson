#ifndef ROCKMOVENTSTRATEGY_H
#define ROCKMOVENTSTRATEGY_H
#include "imovestrategy.h"

class RockMoventStrategy : public IMoveStrategy
{
public:
    std::vector<BoardCellPosition> getAvailableMoves(const ChessPiece& piece) override;

private:
    bool isValidPosition(size_t row, size_t column);
};

#endif // ROCKMOVENTSTRATEGY_H
