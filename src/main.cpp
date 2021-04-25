#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL.h>

#include "../include/pong.hpp"

int main(int argc, char **argv) {
    
    std::cout << "Starting..." << std::endl;

    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "Error" << std::endl;
        return 1;
    }

    Pong* pong = new Pong();
    pong->init();
    pong->start();

    // SDL_CreateWindow("Hello", 200, 200, 64, 64, )
    
    SDL_Quit();
    return 0;
}