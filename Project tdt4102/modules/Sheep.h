#pragma once
#include "GameObject.h"
#include <random>


class Sheep : public GameObject{
    public:
    int width = 30; 
    int height = 30;
    TDT4102::Point pos;
    TDT4102::Color color = TDT4102::Color::red;
    std::vector<std::vector<int>> choices =  {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dx, dy;
    int steps, config;
    Sheep(){
        std::random_device rd;
        std::default_random_engine generator{rd()};
        std::uniform_int_distribution<int> distribution_x{s.windowWidth - s.freezone_width+width, s.windowWidth-width};
        std::uniform_int_distribution<int> distribution_y{height+width, s.windowHeight - height};
        int start_x = distribution_x(generator);
        int start_y = distribution_y(generator);
        pos = {start_x, start_y};
    };
    virtual ~Sheep() { }
    virtual void update(TDT4102::AnimationWindow *main_window) override;
    //virtual void update(TDT4102::AnimationWindow *main_window) override;
    void draw(TDT4102::AnimationWindow *main_window) override;
};
