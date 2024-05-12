#pragma once
#include "global.hpp"
#include "Zombies.hpp"
#include "Greenplants.hpp"
#include "Potatos.hpp"
#include "Bullets.hpp"

class Background
{
public:
    void play();

private:    
    bool should_add_zombie();
    
    vector<Greenplants> greenplants_list;
    vector<Bullets> bullets_list;
    vector<Zombies> zombie_list;
    // vector<Potatos> bullets_list;
};