#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL.h>

#include "game.hpp"

int main(int argc, char **argv) {
    
    std::cout << "Starting..." << std::endl;

    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "Error" << std::endl;
        return 1;
    }

    Game* game = new Game();
    game->init();
    
    game->start();

    game->cleanup();
    SDL_Quit();
    return 0;
}