#pragma once
#include "GameObject.h"
#include "Sheep.h"
#include "Ghost.h"


class Human : public GameObject{
    public:
    int vx = 5;
    int vy = 5;
    int width = 50; 
    int height = 50;
    bool carry = false;
    TDT4102::Point pos {x, y};
    virtual void update(TDT4102::AnimationWindow *main_window) override;
    void draw(TDT4102::AnimationWindow *main_window) override;
    void set_start_pos(int new_x, int new_y);
    bool sheep_collided(std::shared_ptr<Sheep> sheep);
    bool ghost_collided(std::shared_ptr<Ghost> ghost);
    bool left_freezone_collided(int freezone);
    void carry_sheep();
    void release_sheep();
    void move(TDT4102::AnimationWindow *main_window);
};
