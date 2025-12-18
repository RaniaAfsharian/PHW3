#include "GameMap.h"
#include "TurnManager.h"
#include "GameState.h"

int main()
{
    GameMap map(5, 5);

    TurnManager tm;

    Unit warrior(1, "Warrior", 100, 25, 10, Position(1, 1));

    Unit archer(2, "Archer", 70, 30, 5, Position(3, 3));

    map.placeUnit(&warrior);

    map.placeUnit(&archer);

    tm.addUnit(&warrior);

    tm.addUnit(&archer);

    while (!tm.isGameOver())
    {
        GameState::report(tm, map);

        Unit *current = tm.getCurrentUnit();

        Unit *target = (current == &warrior) ? &archer : &warrior;

        current->attack(*target);

        tm.nextTurn();
    }

    GameState::report(tm, map);
    
    return 0;
}
