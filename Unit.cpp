#include "Unit.h"
#include <iostream>

Unit::Unit(int id, const std::string &name, int hp, int atk, int def, Position pos)
    : id(id), name(name), hp(hp), attackPower(atk), defensePower(def), position(pos) {}

Unit::~Unit() {}

bool Unit::isAlive() const
{
    return hp > 0;
}

void Unit::move(const Position &newPos)
{
    if (position.distanceTo(newPos) <= 1)
    {
        position = newPos;
    }
}

void Unit::attack(Unit &target)
{
    if (!isAlive() || !target.isAlive())
        return;
    target -= attackPower;
}

Unit &Unit::operator-=(int damage)
{
    int actualDamage = damage - defensePower;
    if (actualDamage < 0)
        actualDamage = 0;

    hp -= actualDamage;
    if (hp < 0)
        hp = 0;

    return *this;
}

Position Unit::getPosition() const
{
    return position;
}

void Unit::setPosition(const Position &pos)
{
    position = pos;
}

void Unit::printStatus() const
{
    std::cout << "[" << id << "] " << name
              << " | HP: " << hp
              << " | ATK: " << attackPower
              << " | DEF: " << defensePower
              << " | Pos(" << position.x << "," << position.y << ")";

    if (!isAlive())
    {
        std::cout << " [DEAD]";
    }
    
    std::cout << std::endl;
}
