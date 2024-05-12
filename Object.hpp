#pragma once
#include "global.hpp"
class Object
{
public:
    Object()
    {

    };
    sf::Clock movementClock;
    int num_of_frames;
    int next_frame();
    void paint();
    void clear();
    vector<Texture> obj_Textures;

    int lifescore;
    float X;
    float Y;
    float Xlen, Ylen;

};