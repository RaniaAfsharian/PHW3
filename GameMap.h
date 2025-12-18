#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include "Unit.h"

class GameMap
{
    int width, height;

    std::vector<std::vector<Unit *>> grid;

public:
    GameMap(int w, int h);

    bool isInside(const Position &pos) const;

    bool isFree(const Position &pos) const;

    bool placeUnit(Unit *unit);
    
    void moveUnit(Unit *unit, const Position &newPos);

    void print() const;
};

#endif
