#include "Maingame.hpp"

void Maingame::paint_back_ground()
{

    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("photo/background.png"))
    {
        cerr << "Error loading background image!" << endl;
        return;
    }
    Sprite backgroundSprite(backgroundTexture);
    RenderWindow window(VideoMode(1035, 600), "My Game");
    float zombieX = 950;
    vector<float> yPositions = {5.0f,
                                80.0f,
                                180.0f,
                                270.0f,
                                380.0f};
    float randomY = yPositions[rand() % yPositions.size()];
    Clock movementClock;
    float zombieSpeed = 0.1f;
    vector<Texture> zombieTextures;
    for (int i = 1; i <= 19; ++i)
    {
        Texture texture;
        if (!texture.loadFromFile("photo/zombie/image" + to_string(i) + ".png"))
        {
            cerr << "Error loading zombie image " << i << "!" << endl;
            return;
        }
        zombieTextures.push_back(texture);
    }
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

        Sprite zombieSprite(zombieTextures[static_cast<int>(movementClock.getElapsedTime().asMilliseconds() / 100) % 19]);
        zombieSprite.setPosition(zombieX, 80);
        zombieSprite.setScale(0.35f, 0.35f);
        zombieX -= zombieSpeed;
        window.draw(zombieSprite);
        window.display();
    }
}

void Maingame::add_zombie() {

}

;
int Maingame::play()
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
