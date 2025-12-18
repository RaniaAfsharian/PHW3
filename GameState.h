#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "GameMap.h"
#include "TurnManager.h"

class GameState
{
public:
    static void report(const TurnManager &tm, const GameMap &map);
};

#endif
