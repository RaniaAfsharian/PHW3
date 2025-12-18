#include "TurnManager.h"

int TurnManager::currentTurn = 1;

TurnManager::TurnManager() : index(0) {}

void TurnManager::addUnit(Unit *unit)
{
    units.push_back(unit);
}

Unit *TurnManager::getCurrentUnit()
{
    if (units.empty())
    {
        return nullptr;
    }
    return units[index];
}

void TurnManager::nextTurn()
{
    do
    {
        index = (index + 1) % units.size();
    } while (!units[index]->isAlive());
    currentTurn++;
}

bool TurnManager::isGameOver() const
{
    int alive = 0;
    for (auto u : units)
        if (u->isAlive())
        {
            alive++;
        }
    return alive <= 1;
}

const std::vector<Unit *> &TurnManager::getUnits() const
{
    return units;
}
