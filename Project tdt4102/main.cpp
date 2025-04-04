#include <iostream>
#include "GameWindow.h"
#include <random>




int main() {
    GameWindow g;
    g.show_start_screen();
    while(g.running){
        g.new_game();
        g.show_over_screen();
    }
    
   

    return 0; 
}