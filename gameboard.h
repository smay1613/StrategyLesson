#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <unordered_map>
#include <vector>
#include <memory>
#include "chesspiece.h"

using BoardMatrix = std::vector<std::vector<std::unique_ptr<ChessPiece>>>;
using CellConstIterator = std::vector<std::unique_ptr<ChessPiece>>::const_iterator;
using CellIterator = std::vector<std::unique_ptr<ChessPiece>>::iterator;

class GameBoard
{
public:
    static GameBoard& instance(); // Please chech Singleton pattern!
    CellConstIterator get(BoardCellPosition position) const;
    CellIterator at(BoardCellPosition position);

    bool move(BoardCellPosition fromPosition, BoardCellPosition toPosition);

private:
    BoardMatrix m_gameMap;

    GameBoard();
    void setup();
    void setupPawns();
    void removePiece(BoardCellPosition cellPosition);
    void placePiece(std::unique_ptr<ChessPiece> piece, BoardCellPosition toPosition);
};

#endif // GAMEBOARD_H