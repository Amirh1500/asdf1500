#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Object
{
public:
    Object();
    paint();
    clear();
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
    int     current_frame;
};


Object::Object(int xi, int yi, int xl, int yl, string f1, string f2, string f3, string f4, string f5)
{
    current_frame = 0;
};
Object::paint()
{

};
Object::clear()
{

};
class Moveable : public Object
{
public:
    void Move();
private:
    int step; // zombie = -1 , bullet = +1
    int damage_power;
};


void Movable::Move()
{
    x += step;
};

class Zombies : public Moveable
{
public:
    Zombies();

};

Zombies::Zombies()
{
    step = -1;
    x = +1000;
    y = ((rand()*5)/RAND_MAX);
    damage_power = 1;
    xlen = 10; 
    ylen = 10;
    frame1_file_name = "Z1.JPG";    
    frame2_file_name = "Z2.JPG";    
    frame3_file_name = "Z3.JPG";    
    frame4_file_name = "Z4.JPG";    
    frame5_file_name = "Z5.JPG";    
}
class Bullets : public Moveable
{
public:
};

class Static : public Object
{
public:
private:
    int price;
};

class Sunflowers : public Static
{
public:
};

class Potato : public Static
{
public:
};

class Greenplant : public Static
{
public:
};


class background
{
    public: 
    int play();
    void add_zombi();
private:
    void paint_back_ground();
    int xlen, ylen;
    string image_file_name;
    vector<class zombie> zombi_list;

};

void background::paint_back_ground()
{
    //paint 
};
void background::add_zombie()
{
    zombi_list.push_back(new zombi());
};
int background::play()
{
    paint_back_ground();
    while(1)
    {
        for(auto z = zombi_list.begin();z<zombi_list.end();z++)
        {
            z.clear();
            z.move();
            z.paint();
        }

        if( rand() > 1000)
            add_zombi();
    };
};
int main()
{
    class background b;
    
    return 0;
}