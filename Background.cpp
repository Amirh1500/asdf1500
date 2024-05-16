#include "Background.hpp"
Background::Background()
{
}

int Background::Quantize(int y)
{
    if (y < 165)
        return 75;
    if (y < 260)
        return 165;
    if (y < 350)
        return 260;
    if (y < 440)
        return 350;
    return 440;
}

void Background::pressed_mouse()
{
    Vector2i mousePosFloat = Vector2i(Mouse::getPosition(window));
    lastMousePos = mousePosFloat;

    if (logo_greenPlan->is_in_Rect(mousePosFloat.x, mousePosFloat.y))
    {
        draggedPlant = add_greenplants();
        if (draggedPlant)
            isDragging = true;
        else
            isDragging = false;
    }
    if (logo_sunflower->is_in_Rect(mousePosFloat.x, mousePosFloat.y))

    {
        draggedPlant = add_sunflowers();
        if (draggedPlant)
            isDragging = true;
        else
            isDragging = false;
    }
    if (logo_potato->is_in_Rect(mousePosFloat.x, mousePosFloat.y))
    {
        draggedPlant = add_potatos();
        if (draggedPlant)
            isDragging = true;
        else
            isDragging = false;
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
    const sf::Color c = Color::Black;
    text.setColor(c);
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
    return NULL;
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
    return NULL;
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
    return NULL;
}

void Background::logosunflower()
{
    logo_sunflower = new Sunflowers();
    logo_sunflower->X = 0;
    logo_sunflower->Y = 100;
    logo_sunflower->obj_Sprite.setPosition(logo_sunflower->X, logo_sunflower->Y);

    // sunflowers_list.push_back(logo_sunflower);
}

void Background::logogreenplant()
{
    logo_greenPlan = new Greenplants();
    logo_greenPlan->X = 0;
    logo_greenPlan->Y = 5;
    logo_greenPlan->obj_Sprite.setPosition(logo_greenPlan->X, logo_greenPlan->Y);

    // greenplants_list.push_back(logo_greenPlan);
}

void Background::logopotato()
{
    logo_potato = new Potatos();
    logo_potato->X = 0;
    logo_potato->Y = 180;
    logo_potato->obj_Sprite.setPosition(logo_potato->X, logo_potato->Y);

    //   potato_list.push_back(logo_potato);
}

void Background::play()
{
    logogreenplant();
    logosunflower();
    logopotato();

    // just for test plant
    Greenplants *test_plant = new Greenplants();
    test_plant->Y = 75;
    test_plant->X = 190;

    greenplants_list.push_back(test_plant);

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
    while (window.isOpen() && (!GameOver))
    {
        window.draw(backgroundSprite);
        window.draw(logo_sunflower->obj_Sprite);
        window.draw(logo_potato->obj_Sprite);
        window.draw(logo_greenPlan->obj_Sprite);
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
                    draggedPlant->Y = Quantize(draggedPlant->Y);
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

        // check if Greenplant if infront of zombi
        if ((rand() % 1000) > 995)
        {
            for (Greenplants *g : greenplants_list)
                for (Zombies *z : zombie_list)
                {
                    if (g->Y == (z->Y + 67))
                    {
                        Bullets *b = new Bullets();
                        b->X = g->X + 20;
                        b->Y = g->Y + 45;
                        bullets_list.push_back(b);
                    }
                }
        }
/*
        // check if bulltet coliision with zombi
        for (Bullets *b : bullets_list)
            for (Zombies *z : zombie_list)
            {
                if (b->Y == (z->Y + 112) && ((b->X - z->X) < 10))
                {
                    // delte bullet
                    bullets_list.erase(find(bullets_list.begin(), bullets_list.end(), b));
                    delete (b);
                    z->lifescore -= 10;
                    if (z->lifescore < 0)
                    {
                        // delete Zombi
                        bullets_list.erase(find(bullets_list.begin(), bullets_list.end(), b));
                        delete (b);
                    }
                }
            }
*/
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
        for (Bullets *b : bullets_list)
        {
            b->next_frame();
            b->obj_Sprite.setPosition(b->X, b->Y);
            b->MoveX();
            if (b->X < 10)
            {
                // delete b
                bullets_list.erase(find(bullets_list.begin(), bullets_list.end(), b));
                delete (b);
            }
            else
                window.draw(b->obj_Sprite);
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
