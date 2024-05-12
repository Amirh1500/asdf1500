#include "Bullets.hpp"

Bullets::Bullets()
{ 
    X = 0;
    Y = 0;
    num_of_frames = 1;
    Speed = -2.0f;
    Xlen = 0.35f;
    Ylen = 0.35f;
    for (int i = 1; i <= num_of_frames; ++i)
    {
        Texture texture;
        if (!texture.loadFromFile("photo/zombie/image" + to_string(i) + ".png"))
        {
            cerr << "Error loading bullet image " << i << "!" << endl;
            return;
        }
        obj_Textures.push_back(texture);
    }

}