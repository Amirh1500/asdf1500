#pragma once
#include "Moveable.hpp"
#include "global.hpp"

class Zombies : public Moveable
{
public:
    Zombies(int x, int y, int damage_power);
};
