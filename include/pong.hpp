#ifndef PONG_HPP
#define PONG_HPP

#include <iostream>
#include <SDL.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400

#define GAME_TITLE "Pong"

class Pong {


private:
    bool running = false;
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    void processEvents();
    void updateState();
    void render();

public:
    Pong();
    virtual ~Pong();

    void init();
    void start();

};


#endif /* PONG_HPP */
