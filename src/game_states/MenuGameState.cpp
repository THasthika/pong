#include "MenuGameState.hpp"


void MenuGameState::init() {

}

void MenuGameState::cleanup() {
    
}

void MenuGameState::resume() {
    
}

void MenuGameState::pause() {
    
}

void MenuGameState::processEvents() {
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

void MenuGameState::updateState(float deltaTime) {
    
}

void MenuGameState::render() {
    
}