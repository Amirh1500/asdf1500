#include "Background.hpp"
void Background::pressed_mouse()
{
    Vector2i mousePosFloat = Vector2i(Mouse::getPosition(window));
    lastMousePos = mousePosFloat;
    // for (Greenplants *g : greenplants_list)
    // {
    //     if( g->is_in_Rect(mousePosFloat.x,mousePosFloat.y))
    //     {
    //         //cerr << mousePosFloat.x << "-" << mousePosFloat.y << "-" << rec.left << "-" << rec.width << "-" << rec.top << "-" << rec.height << endl;
    //         isDragging = true;
    //         draggedPlant = g;
    //         break;
    //     }
    // }
    if(logo_greenPlan.is_in_Rect(mousePosFloat.x, mousePosFloat.y))
    {
        //add new green Plan
       draggedPlant  = add_greenplants();
        isDragging = true;

    }
    for (Sun *s : sun_list)
    {
        if( s->is_in_Rect(mousePosFloat.x,mousePosFloat.y))
        {
            sun_list.erase(find(sun_list.begin(), sun_list.end(), s));
            delete(s);
        }
    }
}

void Background::released_mouse()
{
    if (isDragging && draggedPlant)
    {
        Vector2i currentMousePos = Vector2i(Mouse::getPosition(window));
        Vector2i delta = currentMousePos - lastMousePos;
        draggedPlant->X += delta.x;
        draggedPlant->Y += delta.y;
        lastMousePos = currentMousePos;
        isDragging = false;
    }
}

Greenplants *Background::add_greenplants()
{
    Greenplants *g = new Greenplants();
    g->X = 0;
    g->Y = 0;
    greenplants_list.push_back(g);
    return g;
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
    logo_greenPlan.X = 0;
    logo_greenPlan.Y = 0;

    bool GameOver = false;
    while (window.isOpen() && (!GameOver))
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
                lastMousePos = Vector2i(Mouse::getPosition(window));
                if (isDragging && draggedPlant) // Add this block
                {
                    Vector2i delta = lastMousePos - Vector2i(draggedPlant->X, draggedPlant->Y);
                    draggedPlant->X += delta.x;
                    draggedPlant->Y += delta.y;
                }
                // }else
                // if( isDragging && draggedSun) // Add this block
                // {

                // }else
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
        window.draw(logo_greenPlan.obj_Sprite);

        if (should_add_sun())
        {
            Sun *s = new Sun();
            sun_list.push_back(s);
        }
        
        for (Sun *s : sun_list)
        {
            s->next_frame();
            s->obj_Sprite.setPosition(s->X, s->Y);
            s->MoveY();
            window.draw(s->obj_Sprite);
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
            z->next_frame();
            z->obj_Sprite.setPosition(z->X, z->Y);
            //           zombieSprite.setScale(z->Xlen, z->Ylen);
            z->MoveX();
            if (z->X < 190)
            {
                // delete z;
                // zombie_list.erase(find(zombie_list.begin(),zombie_list.end(),z));
                GameOver = true;
            }
            window.draw(z->obj_Sprite);
        }
        for (Greenplants *g : greenplants_list)
        {
            g->next_frame();
            g->obj_Sprite.setPosition(g->X, g->Y);
            window.draw(g->obj_Sprite);
        }
        if (!music.openFromFile("music/Music.ogg"))
        {
            cout << "faild to load music" << endl;
        }

        music.setVolume(100);
        music.setLoop(true);
        music.play();
        music.stop();
        window.display();
    }
    // show gameover message
}

bool Background::should_add_zombie()
{
    if ((((float)((float)rand() / RAND_MAX)) * 1000) > 996)
        return false;
    return false;
}

bool Background::should_add_sun()
{
    if ((((float)((float)rand() / RAND_MAX)) * 1000) > 995)
        return true;
    return false;
}

// void Background::music()
// {
//     sf::Music music;

// }