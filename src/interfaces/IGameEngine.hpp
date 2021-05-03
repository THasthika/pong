#ifndef H_GAME_ENGINE
#define H_GAME_ENGINE

#include <stack>

#include "IGameState.hpp"

/**
 *  IGameEngine
 * */
class IGameEngine {

public:
    virtual void init() = 0;
    virtual void cleanup() = 0;

    virtual void processEvents() = 0;
    virtual void updateState(double deltaTime) = 0;
    virtual void render() = 0;

};

#endif /* H_GAME_ENGINE */