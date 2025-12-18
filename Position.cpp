#include "Position.h"
#include <cmath>

Position::Position(int x, int y) : x(x), y(y) {}

bool Position::operator==(const Position &other) const
{
    return x == other.x && y == other.y;
}

bool Position::operator<(const Position &other) const
{
    if (x != other.x)
    {
        return x < other.x;
    }
    return y < other.y;
}

int Position::distanceTo(const Position &other) const
{
    return std::abs(x - other.x) + std::abs(y - other.y);
}
