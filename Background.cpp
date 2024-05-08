#include "Background.hpp"

void Background::paint_back_ground()
{
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("photo/background.png"))
    {
        cerr << "Error loading background image!" << std::endl;
        return;
    }
    Sprite backgroundSprite(backgroundTexture);
    RenderWindow window(sf::VideoMode(1035, 600), "My Game");

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
