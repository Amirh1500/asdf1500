#include "Background.hpp"

void Background::play()
{

    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("photo/background.png"))
    {
        cerr << "Error loading background image!" << endl;
        return;
    }
    Sprite backgroundSprite(backgroundTexture);
    RenderWindow window(VideoMode(1035, 600), "My Game");


    sf::Clock movementClock;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        window.draw(backgroundSprite);
    // HWERE you should check mouse click
        bool add_greenplants = should_add_zombie();

        if(add_greenplants)
        {
            Greenplants g;
            g.X = 0;
            g.Y = 80;
            greenplants_list.push_back(g);
       
        }

        //add new zombie by 0.5% chance      
        if( should_add_zombie())
         {
            Zombies z;
            zombie_list.push_back(z);

         }

        // DRAW Zombis
        for (Zombies &z : zombie_list)
        {
            Sprite zombieSprite(z.obj_Textures[z.next_frame()]);
            zombieSprite.setPosition(z.X, z.Y);
            zombieSprite.setScale(z.Xlen,z.Ylen);
            z.Move();
            window.draw(zombieSprite);
        }

        //DRAW Greenpants)

        for (Greenplants &g : greenplants_list)
        {
            Sprite greenplantsSprite(g.obj_Textures[g.next_frame()]);
            greenplantsSprite.setPosition(g.X, g.Y);
            greenplantsSprite.setScale(g.Xlen, g.Ylen);
            window.draw(greenplantsSprite);
        }


        window.display();
    }
}

bool Background::should_add_zombie()
{
if((((float) ((float)rand()/RAND_MAX) )*1000) > 995)
    return true;
return false;
}