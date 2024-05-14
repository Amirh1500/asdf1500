#pragma once
#include "global.hpp"
#include "Zombies.hpp"
#include "Greenplants.hpp"
#include "Potatos.hpp"
#include "Bullets.hpp"
#include "Sun.hpp"

enum State
{
    IN_GAME,
    PAUSE_MENU,
    MAIN_MENU,
    VICTORY,
    GAMOVER,
    EXIT,
};

class Background
{
public:
    void play();

private:
    State game_state;
    bool should_add_zombie();
    bool should_add_sun();
    void mouse_handler();
    void pressed_mouse();
    void released_mouse();
    void add_greenplants();
    bool isDragging = false;
    Vector2f lastMousePos;
    Greenplants *draggedPlant = nullptr;
    RenderWindow window;
    vector<Greenplants *> greenplants_list;
    // vector<Bullets *> bullets_list;
    vector<Zombies *> zombie_list;
    // vector<Potatos *> bullets_list;
    vector<Sun *> sun_list;
};