#include "Moveable.hpp"

void Moveable::MoveX()
{
    X -= Speed;
};

void Moveable::MoveY()
{
    Y += Speed;
}
