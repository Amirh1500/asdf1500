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
    int xlen, ylen;
    string image_file_name;
    vector<Zombies> zombie_list;
};