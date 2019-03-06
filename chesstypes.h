#ifndef CHESSTYPES_H
#define CHESSTYPES_H
#include <cstddef>
#include <cassert>

enum class Side
{
    Invalid,
    White,
    Black
};

static constexpr size_t BoardSize {8};

struct BoardCellPosition
{
    size_t row {};
    size_t column {};
    BoardCellPosition(size_t _row, size_t _column) : row {_row}, column {_column}
    {
        assert (column < BoardSize);
        assert (row < BoardSize);
    }
};

#endif // CHESSTYPES_H
