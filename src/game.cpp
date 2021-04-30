#include "pong.hpp"

using namespace std;

Pong::Pong()
{
    cout << "instantiating game..." << endl;
}

Pong::~Pong()
{
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }

    if (window != nullptr)
    {
        SDL_DestroyWindow(window);
        // delete window;
    }

    cout << "destroying game..." << endl;
}

void Pong::init()
{
    cout << "init variables..." << endl;

    window = SDL_CreateWindow(GAME_TITLE, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    renderer = SDL_CreateRenderer(this->window, -1, 0);
}

void Pong::start()
{
    cout << "starting game..." << endl;
    running = true;

    while (running)
    {
        this->processEvents();
        this->updateState();
        this->render();
    }

    cout << "stopping event loop..." << endl;
}

void Pong::processEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_WINDOWEVENT:
            switch (event.window.event)
            {
            case SDL_WINDOWEVENT_CLOSE:
                running = false;
                break;

            default:
                break;
            }
            break;
        case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
                case SDLK_q:
                    running = false;
                    break;
            }
        break;
        default:
            break;
        }
    }
}

void Pong::updateState()
{

}

void Pong::render()
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
