
#pragma once
#include "Static.hpp"
#include "global.hpp"

class Greenplants : public Static
{
public:
   Greenplants();
    FloatRect globalbound();
private:
Texture greenplanttex;
Sprite greenplantsp;
};