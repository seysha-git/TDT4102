#pragma once
#include "GameObject.h"
#include <cmath>
#include <random>


class Ghost : public GameObject{
    public:
    //Medlems funksjoner
    int vel_x = 3;
    int vel_y = 2;
    int radius{50};
    TDT4102::Point pos;
    Ghost(){
        std::random_device rd;
        std::default_random_engine generator{rd()};
        std::uniform_int_distribution<int> distribution_x{s.freezone_width + radius, s.windowWidth - s.freezone_width-radius};
        std::uniform_int_distribution<int> distribution_y{radius, s.windowHeight - radius};
        int start_x = distribution_x(generator);
        int start_y = distribution_y(generator);
        this->pos = {start_x, start_y};
    };
    virtual void update(TDT4102::AnimationWindow *main_window) override;
    void draw(TDT4102::AnimationWindow *main_window) override;
};

