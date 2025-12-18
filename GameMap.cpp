#include "GameMap.h"
#include <iostream>

GameMap::GameMap(int w, int h) : width(w), height(h)
{
    grid.resize(height, std::vector<Unit *>(width, nullptr));
}

bool GameMap::isInside(const Position &pos) const
{
    return pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height;
}

bool GameMap::isFree(const Position &pos) const
{
    return isInside(pos) && grid[pos.y][pos.x] == nullptr;
}

bool GameMap::placeUnit(Unit *unit)
{
    Position p = unit->getPosition();
    if (!isFree(p))
    {
        return false;
    }

    grid[p.y][p.x] = unit;
    return true;
}

void GameMap::moveUnit(Unit *unit, const Position &newPos)
{
    Position old = unit->getPosition();
    if (!isFree(newPos))
        return;

    grid[old.y][old.x] = nullptr;

    unit->move(newPos);

    grid[newPos.y][newPos.x] = unit;
}

void GameMap::print() const
{
    std::cout << "--- MAP ---" << std::endl;
    
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            std::cout << (grid[y][x] ? "U " : ". ");
        }
        std::cout << std::endl;
    }
}
