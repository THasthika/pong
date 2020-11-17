#include "../include/pong.hpp"

using namespace std;

Pong::Pong()
{
    cout << "instantiating game..." << endl;
}

Pong::~Pong()
{
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

}
