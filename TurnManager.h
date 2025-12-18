#ifndef TURNMANAGER_H
#define TURNMANAGER_H

#include <vector>
#include "Unit.h"

class TurnManager
{
    std::vector<Unit *> units;
    
    int index;

public:
    static int currentTurn;

    TurnManager();

    void addUnit(Unit *unit);

    Unit *getCurrentUnit();

    void nextTurn();

    bool isGameOver() const;

    const std::vector<Unit *> &getUnits() const;
};

#endif
