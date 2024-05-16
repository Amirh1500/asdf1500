#include "Zombies.hpp"

Zombies::Zombies()
{
 
    X = 950;
    vector<float> yPositions = {8.0f,
                                88.0f,
                                198.0f,
                                288.0f,
                                398.0f};
    Y = yPositions[rand() % yPositions.size()];
    num_of_frames = 19;
    Xlen = 0.3f;
    Ylen = 0.3f;
    Speed = 0.5f;
    for (int i = 1; i <= num_of_frames; ++i)
    {
        Texture texture;
        if (!texture.loadFromFile("photo/zombie/image" + to_string(i) + ".png"))
        {
            cerr << "Error loading zombie image " << i << "!" << endl;
            return;
        }
        obj_Textures.push_back(texture);
    }
    obj_Sprite.setTexture(obj_Textures[0]);
    obj_Sprite.setScale(Xlen,Ylen);

}