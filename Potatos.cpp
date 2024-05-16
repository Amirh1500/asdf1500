#include "Potatos.hpp"
Potatos::Potatos()
{
    X = 0;
    Y = 0;
    num_of_frames = 3;
    Xlen = 0.022f;
    Ylen = 0.022f;
    Texture texture;
    for (int i = 1; i <= num_of_frames; ++i)
    {
        if (!texture.loadFromFile("photo/potato/p" + to_string(i) + ".png"))
        {
            cerr << "Error loading image " << i << "!" << endl;
            return;
        }
        obj_Textures.push_back(texture);
    }
    obj_Sprite.setTexture(obj_Textures[0]);
    obj_Sprite.setScale(Xlen, Ylen);
}