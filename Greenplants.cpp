#include "Greenplants.hpp"

Greenplants::Greenplants()
{
 
    X = 0;
    Y = 0;
    num_of_frames = 4;
    Xlen = 0.35f;
    Ylen = 0.35f;
    for (int i = 1; i <= num_of_frames; ++i)
    {
        if (!greenplanttex.loadFromFile("photo/peashooter/Peashooter" + to_string(i) + ".png"))
        {
            cerr << "Error loading greenplants image " << i << "!" << endl;
            return;
        }
        obj_Textures.push_back(greenplanttex);
    }
    greenplantsp.setTexture(greenplanttex);
    greenplantsp.setPosition(200,100);
}
    FloatRect Greenplants::globalbound()
    {
        return greenplantsp.getGlobalBounds();
    }