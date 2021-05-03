#ifndef GAME_HPP
#define GAME_HPP

#include <SDL.h>

#include "interfaces/IGameEngine.hpp"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400

#define GAME_TITLE "Pong"


class Game : public IGameEngine {

private:
    bool running = false;
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    std::stack<IGameState*> stack;
    IGameState* currentState;

    void processEvents();
    void updateState(double deltaTime);
    void render();

public:
    Game();
    virtual ~Game();

    void init();
    void cleanup();
    
    void start();

};


#endif /* GAME_HPP */
