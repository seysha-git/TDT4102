#pragma once

#include "AnimationWindow.h"
#include <string>

struct Settings {
    const int windowPositionX = 300;
    const int windowPositionY = 100;
    const int windowWidth = 1000;
    const int windowHeight = 800;
    const int title_font = 40;
    const static constexpr int pad = 30;

    const int max_hinderence = 3;
    const int freezone_width = 200; 
    TDT4102::Color navColor = TDT4102::Color::dark_green;
    TDT4102::Color cellColor = TDT4102::Color::dark_grey;
    TDT4102::Color titleColor = TDT4102::Color::white_smoke;

};




