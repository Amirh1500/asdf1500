#pragma once
#include "global.hpp"
#include "Zombies.hpp"
#include "Greenplants.hpp"
#include "Potatos.hpp"
#include "Bullets.hpp"
#include "Sun.hpp"
#include "Sunflowers.hpp"

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
    int Quantize(int y);
    void play();
    Background();
    int total = 0;

private:
    State game_state;
    Music music;
    bool should_add_zombie();
    bool should_add_sun();
    void mouse_handler();
    void pressed_mouse();
    void released_mouse();
    void logosunflower();
    void logogreenplant();
    void logopotato();
    void show_sun();
    Greenplants *logo_greenPlan;
    Sunflowers *logo_sunflower;
    Potatos *logo_potato;
    Greenplants *add_greenplants();
    Sunflowers *add_sunflowers();
    Potatos *add_potatos();
    bool isDragging = false;
    Vector2i lastMousePos;
    Static *draggedPlant = nullptr;
    RenderWindow window;
    vector<Greenplants *> greenplants_list;
    vector<Bullets *> bullets_list;
    vector<Zombies *> zombie_list;
    vector<Sun *> sun_list;
    vector<Sunflowers *> sunflowers_list;
    vector<Potatos *> potato_list;
};