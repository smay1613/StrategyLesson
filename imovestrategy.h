#ifndef IMOVESTRATEGY_H
#define IMOVESTRATEGY_H
#include <vector>
#include "chesstypes.h"
class ChessPiece;

class IMoveStrategy
{
public:
    virtual std::vector<BoardCellPosition> getAvailableMoves(const ChessPiece& piece) = 0;
    virtual ~IMoveStrategy() = default;
};

#endif // IMOVESTRATEGY_H