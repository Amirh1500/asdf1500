#include "Background.hpp"

void Background::paint_back_ground()
{
    sf::Clock movementClock; 
    float zombieX = 950;      
    float zombieSpeed = 0.5f;
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("photo/background.png"))
    {
        cerr << "Error loading background image!" << endl;
        return;
    }
    Sprite backgroundSprite(backgroundTexture);
    RenderWindow window(VideoMode(1035, 600), "My Game");
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
        Texture zombieTexture;
        if (!zombieTexture.loadFromFile("photo/zombie/image1.png"))
        {
            cerr << "Error loading zombie image!" << endl;
            return;
        }

        Sprite zombieSprite(zombieTexture);
        zombieSprite.setScale(0.35f, 0.35f);
        zombieX -= zombieSpeed; 
        movementClock.restart(); 
        zombieSprite.setPosition(zombieX, 260); 
        window.draw(zombieSprite);

        for (const Zombies &zombie : zombie_list)
        {
        }

        window.display();
    }
}

void Background::add_zombie() {
    /*zombie_list.push_back(new zombie());*/
};
int Background::play()
{
    paint_back_ground();

    /*while (true)
    {
        for (auto z = zombie_list.begin(); z < zombie_list.end(); z++)
        {
            z.clear();
            z.move();
            z.paint();
        }

        if (rand() > 1000)
            add_zombie();
    };*/
};
