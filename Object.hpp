#pragma once
#include "global.hpp"

class Object
{
public:
    Object();
    Clock movementClock;
    int num_of_frames;
    int next_frame();
    void paint();
    void clear();
    bool is_in_Rect(int x, int y);

    vector<Texture> obj_Textures;
    Sprite          obj_Sprite;
    int lifescore;
    float X;
    float Y;
    float Xlen, Ylen;

};