#include "Background.hpp"
void Background::pressed_mouse()
{
    Vector2f mousePosFloat = Vector2f(Mouse::getPosition(window));
    lastMousePos = mousePosFloat;
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
        Vector2f currentMousePos = Vector2f(Mouse::getPosition(window));
        Vector2f delta = currentMousePos - lastMousePos;
        draggedPlant->X += delta.x;
        draggedPlant->Y += delta.y;
        lastMousePos = currentMousePos;
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
                lastMousePos = Vector2f(Mouse::getPosition(window));
                if (isDragging && draggedPlant) // Add this block
                {
                    Vector2f delta = lastMousePos - Vector2f(draggedPlant->X, draggedPlant->Y);
                    draggedPlant->X += delta.x;
                    draggedPlant->Y += delta.y;
                }
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

        if (should_add_sun())
        {
            Sun *s = new Sun();
            sun_list.push_back(s);
        }

        for (Sun *s : sun_list)
        {
            Sprite sunSprite(s->obj_Textures[0]);
            sunSprite.setPosition(s->X, s->Y);
            sunSprite.setScale(s->Xlen, s->Ylen);
            s->MoveY();
            window.draw(sunSprite);
        }
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
            z->MoveX();
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
            geSprite.setScale(0.02f, 0.02f);
            window.draw(geSprite);
        }

        window.display();
    }
}

bool Background::should_add_zombie()
{
    if ((((float)((float)rand() / RAND_MAX)) * 1000) > 996)
        return true;
    return false;
}

bool Background::should_add_sun()
{
    if ((((float)((float)rand() / RAND_MAX)) * 1000) > 995)
        return true;
    return false;
}