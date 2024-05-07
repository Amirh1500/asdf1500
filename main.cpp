#include <iostream>
#include <string>

using namespace std;

class Object
{
public:
private:
    int lifescore;
    int x;
    int y;
};

class Moveable : public Object
{
public:
private:
    int damage;
};

class Zombies : public Moveable
{
public:
};

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

int main()
{

    return 0;
}