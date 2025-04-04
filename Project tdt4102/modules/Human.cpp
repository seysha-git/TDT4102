#include "Human.h"
#include <iostream>


void Human::move(TDT4102::AnimationWindow *main_window){

    if(main_window->is_key_down(KeyboardKey::D)){
        pos.x += vx;
        //std::cout << '\n' << "Move: " << pos.x << '\n';
    }
    if(main_window->is_key_down(KeyboardKey::W)){
        pos.y -= vy;
    }
    if(main_window->is_key_down(KeyboardKey::S)){
        pos.y += vy;
    }
    if(main_window->is_key_down(KeyboardKey::A)){
        pos.x -= vx;
    }
    //std::cout << '\n' << "Moving position: " << pos.x << '\n';
}

void Human::update(TDT4102::AnimationWindow *main_window){
    if(pos.x + width >= s.windowWidth){
        pos.x = s.windowWidth - width;
    }
    if(pos.y + height >= s.windowHeight){
        pos.y = s.windowHeight - height;
    }
    if(pos.y<=0){
        pos.y = 0;
    }
    if(pos.x<= 0){
        pos.x = 0;
    }
    move(main_window);
}

void Human::set_start_pos(int new_x, int new_y){
    pos.x = new_x;
    pos.y = new_y;
}


bool Human::sheep_collided(std::shared_ptr<Sheep> sheep) {
    if( (pos.x+width >= sheep->pos.x) &&
        (pos.x <= sheep->pos.x + sheep->width) &&
        (pos.y + height >= sheep->pos.y) &&
        (pos.y <= sheep->y + sheep->height)
    ){
        return true;
    }
    return false;
}

bool Human::ghost_collided(std::shared_ptr<Ghost> ghost){
    float testX = ghost->pos.x;
    float testY = ghost->pos.y;

    if(ghost->pos.x < pos.x){ //Test left edge
        testX = pos.x;
    }
    else if(ghost->pos.x > pos.x+width){ //right edge
        testX = pos.x + width;
    }
    if(ghost->pos.y < pos.y){ // top edge
        testY = pos.y;
    }
    else if(ghost->pos.y > pos.y + height){ // bottom edge
        testY = pos.y + height;
    }
    //distance from closest edge
    float distX = ghost->pos.x - testX;
    float distY = ghost->pos.y-testY;
    float distance = sqrt( (distX*distX) + (distY*distY));

    //distance less than radius, collision
    if(distance <= ghost->radius){
        return true;
    }
    return false;
}

bool Human::left_freezone_collided(int freezone){
    if(pos.x <= freezone){
        return true;
    }
    return false;
}

void Human::carry_sheep(){
    vx = vy = 2;
    carry = true;
}
void Human::release_sheep(){
    vx = vy = 5;
    carry = false;
}

void Human::draw(TDT4102::AnimationWindow *main_window) {
    //std::cout << "Pos" << pos.x << " " << pos.y << '\n';
    main_window->draw_rectangle(pos, width, height, color);
}
