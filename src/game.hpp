#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SDL.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400

#define GAME_TITLE "Pong"

class Game {


private:
    bool running = false;
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    void processEvents();
    void updateState();
    void render();

public:
    Game();
    virtual ~Game();

    void init();
    void start();

};


#endif /* GAME_HPP */
