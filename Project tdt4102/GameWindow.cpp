#include "GameWindow.h"
#include <iostream>

void GameWindow::new_game(){
    //Reset and start 
    sheeps_saved = 0;
    curr_sheeps = 0;
    curr_ghosts = 0;
    max_ghosts = 1;
    max_sheep = 3;
    all_objects = {};
    ghosts = {} ;
    sheeps = {};
    player->set_start_pos(100, 300);
    add_object(player);
    run();
}

void GameWindow::run(){
    playing = true;
    while(!window.should_close() && playing){
        update();
        draw_animation();
        window.next_frame();
    }
}

void GameWindow::update(){
    for(int i = 0; i < all_objects.size(); i++){
        all_objects.at(i)->update(&window);
    }

    //spawn right_siwaide sheeps
    while(curr_sheeps < max_sheep){
        std::shared_ptr<Sheep> new_sheep{new Sheep{}};
        add_object(new_sheep);
        add_sheep(new_sheep);
        //add_sheep(std::move(std::make_shared<Sheep>(new_sheep)));
        curr_sheeps += 1;
    }

    //Spawn ghosts in enemy zone. 
    while(curr_ghosts < max_ghosts){
        std::shared_ptr<Ghost> new_ghost{new Ghost{}};
        add_object(new_ghost);
        add_ghost(new_ghost);
        curr_ghosts += 1;
    }

    //check colission between player and sheep
    for(int i = 0; i < sheeps.size(); i++){
      if(player->sheep_collided(sheeps.at(i))){
        //std::cout << "Hit sheep";
        player->carry_sheep();
        delete_sheep(sheeps.at(i));

      }
    }

    //Check colission between player and ghost
    for(int i = 0; i < ghosts.size(); i++){
        if(player->ghost_collided(ghosts.at(i))){
            playing = false;
        }
    }
    if(player->carry && player->left_freezone_collided(freezone_width)){
        max_ghosts += 1;
        player->release_sheep();   
        sheeps_saved += 1;    
    }
}

void GameWindow::draw_animation(){
    window.draw_rectangle(topLeftCorner, freezone_width, s.windowHeight, TDT4102::Color::dark_olivegreen);
    window.draw_rectangle(topRightCorner, freezone_width, s.windowHeight, TDT4102::Color::dark_olivegreen);
    window.draw_rectangle(topLeftCorner, freezone_width, 100, TDT4102::Color::ghost_white);
    std::string message = "Sheep saved:" + std::to_string(sheeps_saved);
    window.draw_text(TextPos, message, TDT4102::Color::black, 23, TDT4102::Font::courier_bold_italic);
    for(int i = 0; i < all_objects.size(); i++){
        all_objects.at(i)->draw(&window);
    }
}

void GameWindow::show_start_screen(){
    bool waiting = true;
    while(waiting){
        window.draw_rectangle(topLeftCorner,s.windowWidth, s.windowHeight, TDT4102::Color::bisque);
        std::string message1 = "Save the red sheeps";
        std::string message2 = "Difficulty level: U(Easy) | O(Hard)";
        std::string message3 = "N to start | E to exit";
        std::string message4 = "Controls: W.A.S.D";
        window.draw_text(TitlePos, message1, TDT4102::Color::black, 80, TDT4102::Font::courier_bold_italic);
        window.draw_text(StatsPos, message2, TDT4102::Color::black, 50, TDT4102::Font::courier_bold_italic);
        window.draw_text(NewPos, message3, TDT4102::Color::black, 30, TDT4102::Font::courier_bold_italic);
        window.draw_text(EndPos, message4, TDT4102::Color::black, 30, TDT4102::Font::courier_bold_italic);
        window.next_frame();
        if(window.is_key_down(KeyboardKey::N)){
            waiting = false;
            playing = true;
        }
        if(window.is_key_down(KeyboardKey::E)){
            waiting = false;
            running = false;
        }
    }
}
void GameWindow::show_over_screen(){
    if(!running){
        return;
    }
    bool waiting = true;
    while(waiting){
        window.draw_rectangle(topLeftCorner,s.windowWidth, s.windowHeight, TDT4102::Color::bisque);
        std::string message1 = "Game over";
        std::string message2 = "Sheep saved:" + std::to_string(sheeps_saved);
        std::string message3 = "N for new game";
        std::string message4 = "E to end game";
        
        window.draw_text(TitlePos, message1, TDT4102::Color::black, 80, TDT4102::Font::courier_bold_italic);
        window.draw_text(StatsPos, message2, TDT4102::Color::black, 50, TDT4102::Font::courier_bold_italic);
        window.draw_text(NewPos, message3, TDT4102::Color::black, 30, TDT4102::Font::courier_bold_italic);
        window.draw_text(EndPos, message4, TDT4102::Color::black, 30, TDT4102::Font::courier_bold_italic);
        window.next_frame();
        if(window.is_key_down(KeyboardKey::N)){
            std::cout << "New game";
            waiting = false;
            playing = true;
        }
        if(window.is_key_down(KeyboardKey::E)){
            std::cout << "End game";
            waiting = false;
            running = false;
        }
    }
    
}




void GameWindow::add_object(std::shared_ptr<GameObject> new_object){
    all_objects.emplace_back(new_object);
}
void GameWindow::add_sheep(std::shared_ptr<Sheep> new_sheep){
    sheeps.emplace_back(new_sheep);
}
void GameWindow::add_ghost(std::shared_ptr<Ghost> new_ghost){
    ghosts.emplace_back(new_ghost);
}
void GameWindow::delete_sheep(std::shared_ptr<Sheep> new_sheep){
    std::cout << "Delete sheep" << '\n';
    all_objects.erase(std::remove(all_objects.begin(), all_objects.end(), new_sheep), all_objects.end());
    sheeps.erase(std::remove(sheeps.begin(), sheeps.end(), new_sheep), sheeps.end());
    curr_sheeps -= 1;
}






