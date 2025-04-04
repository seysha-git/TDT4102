#include "Sheep.h"

void Sheep::draw(TDT4102::AnimationWindow *main_window) {
    main_window->draw_rectangle(pos, width, height, color);
}

void Sheep::update(TDT4102::AnimationWindow *main_window){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, choices.size()-1);
    dx = 10*choices.at(dist6(rng)).at(0);
    dy = 10*choices.at(dist6(rng)).at(1);
    pos.x += dx;
    pos.y += dy;

    pos.x = std::max(s.windowWidth-s.freezone_width + width, std::min(pos.x, s.windowWidth - width));
    pos.y = std::max(height, std::min(pos.y, s.windowHeight - height));
}

