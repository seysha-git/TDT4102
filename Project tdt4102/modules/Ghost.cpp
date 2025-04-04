#include "Ghost.h"
#include <iostream>
#include <cmath>

void Ghost::update(TDT4102::AnimationWindow *main_window) {
    //if ((pos.x + radius) >= s.windowWidth - s.freezone_width) {
    if (pos.x >= (s.windowWidth-s.freezone_width-radius)){
        vel_x *= -1;
    }
    else if (pos.x <= s.freezone_width+radius) {
        vel_x *= -1;
    }

    if ((pos.y + radius) >= s.windowHeight) {
        vel_y *= -1;
    }
    else if (pos.y <= 0) {
        vel_y *= -1;
    }

    pos.x += vel_x;
    pos.y += vel_y;
}

void Ghost::draw(TDT4102::AnimationWindow *main_window) {
    main_window->draw_circle(pos, radius, TDT4102::Color::black);
}

