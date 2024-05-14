#include "Sun.hpp"

Sun::Sun()
{
    Y = 50;
    vector<float> xPositions = {50.0f,
                                1500.0f,
                                380.0f,
                                470.0f,
                                780.0f};
    X = xPositions[rand() % xPositions.size()];
    num_of_frames = 1;
    Xlen = 1.0f;
    Ylen = 1.0f;
    Speed = 0.5f;
    Texture texture;
    for (int i = 0; i < 1; i++)
    {
        if (!texture.loadFromFile("photo/sun.png"))
        {
            cerr << "Error loading zombie image " << endl;
            return;
        }
        obj_Textures.push_back(texture);
    }
     obj_Sprite.setTexture(obj_Textures[0]);
    obj_Sprite.setScale(Xlen,Ylen);
}

// FloatRect Sun::globalbound()
// {
//     return Sunsp.getGlobalBounds();
// }