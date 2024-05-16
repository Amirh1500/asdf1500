#include "Bullets.hpp"

Bullets::Bullets()
{ 
    X = 0;
    Y = 0;
    num_of_frames = 1;
    Speed = -2.0f;
    Xlen = 0.04f;
    Ylen = 0.04f;
    Texture texture;
    if (!texture.loadFromFile("photo/bullet.png"))
    {
        cerr << "Error loading bullet image!" << endl;
        return;
    }
    obj_Textures.push_back(texture);
    obj_Sprite.setScale(Xlen,Ylen);

}