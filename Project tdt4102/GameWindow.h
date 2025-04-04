#pragma once

#include "AnimationWindow.h"
#include "Settings.h"
#include "./modules/Human.h"
#include "./modules/Ghost.h"
#include "./modules/Sheep.h"
#include "./modules/GameObject.h"
#include <string>
#include <vector>
class GameWindow {
public:
    //Medlemsvariabler og klasser
    Settings s;
    TDT4102::AnimationWindow window{200, 80, s.windowWidth, s.windowHeight};
    std::vector<std::shared_ptr<GameObject>> all_objects;
    std::vector<std::shared_ptr<Ghost>> ghosts;
    std::vector<std::shared_ptr<Sheep>> sheeps;
    TDT4102::Point topLeftCorner {0, 0};
    int freezone_width = 200;
    TDT4102::Point topRightCorner {s.windowWidth - freezone_width, 0};
    TDT4102::Point TextPos {10, 40};
    TDT4102::Point TitlePos {s.windowWidth/4-150, s.windowHeight/2-300};
    TDT4102::Point StatsPos {s.windowWidth/4-200, s.windowHeight/2-150};
    TDT4102::Point NewPos {150, s.windowHeight/2};
    TDT4102::Point EndPos {600, s.windowHeight/2};
    std::shared_ptr<Human> player{new Human{}};
    Sheep sheep;
    int curr_sheeps;
    int curr_ghosts;
    int max_ghosts;
    int max_sheep;
    int sheeps_saved;

    bool playing;
    bool running = true;

    //Medlemsfunksjoner
    void new_game();
    void run();
    void update();
    void add_object(std::shared_ptr<GameObject> new_object);
    void add_sheep(std::shared_ptr<Sheep> new_sheep);
    void add_ghost(std::shared_ptr<Ghost> new_ghost);
    void delete_object(std::shared_ptr<GameObject> new_object);
    void delete_sheep(std::shared_ptr<Sheep> new_sheep);
    //void delete_ghost(std::shared_ptr<Ghost> new_ghost);
    void show_start_screen();
    void show_over_screen();
    void draw_animation();
};
