#ifndef H_MENU_GAME_STATE
#define H_MENU_GAME_STATE

#include "../interfaces/IGameState.hpp"
#include "../interfaces/IGameEngineCallback.hpp"

/**
 *  MenuGameState
 * */
class MenuGameState : public IGameState {

public:
    void init() override;
    void cleanup() override;

    void resume() override;
    void pause() override;

    void processEvents() override;
    void updateState(float deltaTime) override;
    void render() override;
    
};

#endif /* H_MENU_GAME_STATE */