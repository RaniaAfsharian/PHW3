#include "GameState.h"
#include <iostream>

void GameState::report(const TurnManager &tm, const GameMap &map)
{
    std::cout << "\n=== TURN " << TurnManager::currentTurn << " ===\n";

    for (auto u : tm.getUnits())
    {
        u->printStatus();
    }
    map.print();
}
