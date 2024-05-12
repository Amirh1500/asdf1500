#include "Zombies.hpp"

Zombies::Zombies()
{
 
    X = 950;
    vector<float> yPositions = {5.0f,
                                80.0f,
                                180.0f,
                                270.0f,
                                380.0f};
    Y = yPositions[rand() % yPositions.size()];
    num_of_frames = 19;
    Xlen = 0.35f;
    Ylen = 0.35f;
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


}