#pragma once
#include "global.hpp"
class Object
{
public:
    Object(int xi, int yi, int xl, int yl, string f1, string f2, string f3, string f4, string f5);
    void paint();
    void clear();

private:
    int lifescore;
    int x;
    int y;
    int xlen;
    int ylen;
    string frame0_file_name;
    string frame1_file_name;
    string frame2_file_name;
    string frame3_file_name;
    string frame4_file_name;
    int current_frame;
};