#ifndef H_GAME_STATE
#define H_GAME_STATE

/**
 *  IGameState
 * */
class IGameState {

public:
    virtual void init() = 0;
    virtual void cleanup() = 0;

    virtual void resume() = 0;
    virtual void pause() = 0;

    virtual void processEvents() = 0;
    virtual void updateState(float deltaTime) = 0;
    virtual void render() = 0;

};

#endif /* H_GAME_STATE */