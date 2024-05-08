#pragma once
#include "Object.hpp"

#include "global.hpp"

class Moveable : public Object
{
public:
    void Move();

private:
    int step; // zombie = -1 , bullet = +1
    int damage_power;
};