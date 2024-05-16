#include "Sunflowers.hpp"

Sunflowers::Sunflowers()
{
 
    X = 0;
    Y = 0;
    num_of_frames = 24;
    Xlen = 1.3f;
    Ylen = 1.3f;
     Texture texture;
   for (int i = 1; i <= num_of_frames; ++i)
    {
        if (!texture.loadFromFile("photo/sunflower/tile0" + to_string(i) + ".png"))
        {
            cerr << "Error loading image " << i << "!" << endl;
            return;
        }
        obj_Textures.push_back(texture);
    }
    obj_Sprite.setTexture(obj_Textures[0]);
    obj_Sprite.setScale(Xlen,Ylen);
}