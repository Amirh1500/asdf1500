#include "Greenplants.hpp"

Greenplants::Greenplants()
{
 
    X = 0;
    Y = 0;
    num_of_frames = 4;
    Xlen = 0.015f;
    Ylen = 0.015f;
     Texture texture;
   for (int i = 1; i <= num_of_frames; ++i)
    {
        if (!texture.loadFromFile("photo/peashooters/Peashooter" + to_string(i) + ".png"))
        {
            cerr << "Error loading greenplants image " << i << "!" << endl;
            return;
        }
        obj_Textures.push_back(texture);
    }
    obj_Sprite.setTexture(obj_Textures[0]);
    obj_Sprite.setScale(Xlen,Ylen);
}
  