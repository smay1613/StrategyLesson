#include "gameboard.h"
#include "pawnmovestrategy.h"

GameBoard::GameBoard()
    : m_gameMap {BoardSize}
{
    setup();
}

GameBoard& GameBoard::instance()
{
    static GameBoard instance;
    return instance;
}

CellConstIterator GameBoard::get(BoardCellPosition position) const
{
    return std::next(m_gameMap.at(position.row).cbegin(), static_cast<long>(position.column));
}

CellIterator GameBoard::at(BoardCellPosition position)
{
    return std::next(m_gameMap.at(position.row).begin(), static_cast<long>(position.column));
}

bool GameBoard::move(BoardCellPosition fromPosition, BoardCellPosition toPosition)
{
    std::unique_ptr<ChessPiece>& pieceRef = *at(fromPosition);
    if (!pieceRef) {
        return false;
    }
    if (pieceRef->move(toPosition)) {
        placePiece(std::move(pieceRef), toPosition);
        removePiece(fromPosition);
    }
}

void GameBoard::setup()
{
    for (auto& column : m_gameMap)
    {
        column.resize(BoardSize);
    }

    setupPawns();
}

void GameBoard::setupPawns()
{
    std::array<size_t, 2> pawnsRows {1, 6};

    for (auto row : pawnsRows) {
        for (size_t i = 0; i < BoardSize; ++i) {
            BoardCellPosition position {row, i};
            const CellIterator& cell = at(position);
            cell->reset(new ChessPiece {row == 1 ? Side::Black : Side::White,
                                        position});
            (*cell)->setMoveStrategy(std::make_unique<PawnMoveStrategy>());
        }
    }
}

void GameBoard::removePiece(const BoardCellPosition cellPosition)
{
    const CellIterator& cell = at(cellPosition);
    cell->release();
}

void GameBoard::placePiece(std::unique_ptr<ChessPiece> piece, BoardCellPosition toPosition)
{
    const CellIterator& cell = at(toPosition);
    cell->reset(piece.release());
}
