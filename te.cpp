#include "Background.hpp"
void Background::pressed_mouse()
{
    Vector2f mousePosFloat = Vector2f(Mouse::getPosition(window));
    for (Greenplants *g : greenplants_list)
    {
        if (g->globalbound().contains(mousePosFloat))
        {
            isDragging = true;
            draggedPlant = g;
            break;
        }
    }
}

void Background::released_mouse()
{
    if (isDragging && draggedPlant)
    {
        Vector2i currentMousePos = Mouse::getPosition(window);
        Vector2i delta = currentMousePos - lastMousePos;
        draggedPlant->X += delta.x;
        draggedPlant->Y += delta.y;
        isDragging = false;
    }
}
void Background::add_greenplants()
{
    Greenplants *g = new Greenplants();
    g->X = 250;
    g->Y = 80;
    greenplants_list.push_back(g);
}
void Background::play()
{

    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("photo/background.png"))
    {
        cerr << "Error loading background image!" << endl;
        return;
    }
    Sprite backgroundSprite(backgroundTexture);
    window.create(VideoMode(1035, 600), "My Game");

    Clock movementClock;
    add_greenplants();
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            else if (event.type == Event::MouseMoved)
            {
                 lastMousePos = Mouse::getPosition(window);
            }
            else if (event.type == Event::MouseButtonPressed)
            {
                pressed_mouse();
            }
            else if (event.type == Event::MouseButtonReleased)
            {
                released_mouse();
            }
        }
        window.draw(backgroundSprite);
        // HWERE you should check mouse click
        // bool add_greenplants = should_add_zombie();

        // if (add_greenplants)
        // {
        //     Greenplants *g = new Greenplants();
        //     g->X = 0;
        //     g->Y = 80;
        //     greenplants_list.push_back(g);
        // }

        // add new zombie by 0.5% chance
        if (should_add_zombie())
        {
            Zombies *z = new Zombies();
            zombie_list.push_back(z);
        }

        // DRAW Zombis
        for (Zombies *z : zombie_list)
        {
            Sprite zombieSprite(z->obj_Textures[z->next_frame()]);
            zombieSprite.setPosition(z->X, z->Y);
            zombieSprite.setScale(z->Xlen, z->Ylen);
            z->Move();
            if (z->X < 190)
            {
                // delete z;
                // zombie_list.erase(find(zombie_list.begin(),zombie_list.end(),z));
                abort();
            }
            window.draw(zombieSprite);
        }
        for (Greenplants *g : greenplants_list)
        {
            Sprite geSprite(g->obj_Textures[g->next_frame()]);
            geSprite.setPosition(g->X, g->Y);
            geSprite.setScale(0.025f, 0.025f);
            window.draw(geSprite);
        }

        // DRAW Greenpants)

        // for (Greenplants *g : greenplants_list)
        // {
        //     Sprite greenplantsSprite(g->obj_Textures[g->next_frame()]);
        //     greenplantsSprite.setPosition(g->X, g->Y);
        //     greenplantsSprite.setScale(g->Xlen, g->Ylen);
        //     window.draw(greenplantsSprite);
        // }

        window.display();
    }
}
// GLOBALBOUND.CONTAINS
void Background::mouse_handler()
{
    Event event;
    switch (event.type)
    {
    case Event::Closed:
        window.close();
        game_state = EXIT;
        break;
    case Event::MouseButtonPressed:
        break;
    case Event::MouseButtonReleased:
        break;
    case Event::MouseMoved:
        break;
    }
}

bool Background::should_add_zombie()
{
    if ((((float)((float)rand() / RAND_MAX)) * 1000) > 995)
        return true;
    return false;
}
