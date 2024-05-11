#pragma once
#include "global.hpp"
#include "Zombies.hpp"

class Background
{
public:
    int play();
    void add_zombie();
    void paint_back_ground();

private:

    vector<Zombies> zombie_list;
};