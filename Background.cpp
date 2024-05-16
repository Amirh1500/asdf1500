#include "Background.hpp"
Background::Background()
{
}
void Background::pressed_mouse()
{
    Vector2i mousePosFloat = Vector2i(Mouse::getPosition(window));
    lastMousePos = mousePosFloat;

    if (logo_greenPlan->is_in_Rect(mousePosFloat.x, mousePosFloat.y))
    {

        draggedPlant = add_greenplants();
        isDragging = true;
    }
    if (logo_sunflower->is_in_Rect(mousePosFloat.x, mousePosFloat.y))
    {

        draggedPlant = add_sunflowers();
        isDragging = true;
    }
    if (logo_potato->is_in_Rect(mousePosFloat.x, mousePosFloat.y))
    {
        draggedPlant = add_potatos();
        isDragging = true;
    }

    for (Sun *s : sun_list)
    {
        if (s->is_in_Rect(mousePosFloat.x, mousePosFloat.y))
        {
            sun_list.erase(find(sun_list.begin(), sun_list.end(), s));
            delete (s);
            total += 50;
        }
    }
}

void Background::show_sun()
{
    Font font;
    Text text;
    font.loadFromFile("font/font.otf");
    text.setFont(font);
    text.setString(to_string(total));
    text.setCharacterSize(30);
    text.setColor(Color::Black);
    text.setPosition(280.0f, 13.0f);
    window.draw(text);
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
    if (total > 100)
    {
        Greenplants *g = new Greenplants();
        g->X = 0;
        g->Y = 5;
        greenplants_list.push_back(g);
        total -= 100;
        return g;
    }
}

Sunflowers *Background::add_sunflowers()
{
    if (total > 50)
    {
        Sunflowers *sf = new Sunflowers();
        sf->X = 0;
        sf->Y = 100;
        sunflowers_list.push_back(sf);
        total -= 50;
        return sf;
    }
}

Potatos *Background::add_potatos()
{
    if (total > 50)
    {
        Potatos *p = new Potatos();
        p->X = 0;
        p->Y = 180;
        potato_list.push_back(p);
        total -= 50;
        return p;
    }
}

void Background::logosunflower()
{
    logo_sunflower = new Sunflowers();
    logo_sunflower->X = 0;
    logo_sunflower->Y = 100;
    sunflowers_list.push_back(logo_sunflower);
}

void Background::logogreenplant()
{
    logo_greenPlan = new Greenplants();
    logo_greenPlan->X = 0;
    logo_greenPlan->Y = 5;
    greenplants_list.push_back(logo_greenPlan);
}

void Background::logopotato()
{
    logo_potato = new Potatos();
    logo_potato->X = 0;
    logo_potato->Y = 180;
    potato_list.push_back(logo_potato);
}

void Background::play()
{
    logogreenplant();
    logosunflower();
    logopotato();
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("photo/BackgroundOrginal.png"))
    {
        cerr << "Error loading background image!" << endl;
        return;
    }
    Sprite backgroundSprite(backgroundTexture);
    window.create(VideoMode(1035, 600), "My Game");

    Clock movementClock;

    bool GameOver = false;
    if (!music.openFromFile("music/Music.ogg"))
    {
        cout << "faild to load music" << endl;
    }

    music.setVolume(100);
    music.setLoop(true);
    music.play();
    music.stop();
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
                if (isDragging && draggedPlant)
                {
                    Vector2i delta = lastMousePos - Vector2i(draggedPlant->X, draggedPlant->Y);
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
        window.draw(logo_greenPlan->obj_Sprite);
        window.draw(logo_sunflower->obj_Sprite);
        window.draw(logo_potato->obj_Sprite);

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

        if (should_add_zombie())
        {
            Zombies *z = new Zombies();
            zombie_list.push_back(z);
        }

        for (Zombies *z : zombie_list)
        {
            z->next_frame();
            z->obj_Sprite.setPosition(z->X, z->Y);
            z->MoveX();
            if (z->X < 190)
            {

                GameOver = true;
            }
            window.draw(z->obj_Sprite);
        }
        for (Greenplants *g : greenplants_list)
        {
            g->next_frame();
            Vector2f pos;
            pos.x = g->X;
            pos.y = g->Y;
            g->obj_Sprite.setPosition(pos);
            window.draw(g->obj_Sprite);
        }

        for (Sunflowers *sf : sunflowers_list)
        {
            sf->next_frame();
            Vector2f pos;
            pos.x = sf->X;
            pos.y = sf->Y;
            sf->obj_Sprite.setPosition(pos);
            window.draw(sf->obj_Sprite);
        }
        for (Potatos *p : potato_list)
        {
            p->next_frame();
            Vector2f pos;
            pos.x = p->X;
            pos.y = p->Y;
            p->obj_Sprite.setPosition(pos);
            window.draw(p->obj_Sprite);
        }
        show_sun();
        window.display();
    }
    music.stop();
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