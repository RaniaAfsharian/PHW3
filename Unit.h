#ifndef UNIT_H
#define UNIT_H

#include <string>
#include "Position.h"

class Unit
{
protected:
    int id , hp , attackPower , defensePower;
    
    std::string name;

    Position position;

public:
    Unit(int id, const std::string &name, int hp, int atk, int def, Position pos);

    virtual ~Unit();

    bool isAlive() const;

    virtual void move(const Position &newPos);

    virtual void attack(Unit &target);

    Unit &operator-=(int damage);

    Position getPosition() const;

    void setPosition(const Position &pos);

    void printStatus() const;
};

#endif
