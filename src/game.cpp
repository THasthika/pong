#include <iostream>

#include "interfaces/IGameState.hpp"

#include "game_states/MenuGameState.hpp"

#include "game.hpp"

using namespace std;

Game::Game()
{

}

Game::~Game()
{

}

void Game::init()
{
    cout << "instantiating game..." << endl;

    cout << "init variables..." << endl;

    window = SDL_CreateWindow(GAME_TITLE, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    renderer = SDL_CreateRenderer(this->window, -1, 0);

    IGameState* menu = new MenuGameState();
    stack.push(menu);
}

void Game::cleanup()
{
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }

    if (window != nullptr)
    {
        SDL_DestroyWindow(window);
        // delete window;
    }

    while (stack.size() > 0) {
        IGameState* state = stack.top();
        stack.pop();
        state->cleanup();
    }

    cout << "destroying game..." << endl;
}

void Game::start()
{
    cout << "starting game..." << endl;
    running = true;

    uint64_t currentFrameTime = SDL_GetPerformanceCounter();
    uint64_t lastFrameTime = 0;
    double deltaTime = 0;

    while (running)
    {

        lastFrameTime = currentFrameTime;
        currentFrameTime = SDL_GetPerformanceCounter();
        deltaTime = (double)((currentFrameTime - lastFrameTime)*1000 / (double)SDL_GetPerformanceFrequency());

        currentState = stack.top();

        this->processEvents();
        this->updateState(deltaTime);
        this->render();
    }

    cout << "stopping event loop..." << endl;
}

void Game::processEvents()
{
    currentState->processEvents();
}

void Game::updateState(double deltaTime)
{

}

void Game::render()
{
    //Set the draw color...
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	//Clear the screen.
	SDL_RenderClear(renderer);

	//Setting the actual draw color.
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

	//Drawing the lines we want. (-1, 0), (0, 1), (1, 0)
	SDL_RenderDrawLine(renderer, 0, 480, 320, 0);
	SDL_RenderDrawLine(renderer, 640, 480, 320, 0);
	SDL_RenderDrawLine(renderer, 0, 480, 640, 480);

	//Update the renderer.
	SDL_RenderPresent(renderer);
}
