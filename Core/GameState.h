#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Global.h"
#include "State.h"

class GameState : public State
{
    OBJECT_CAST_CTOR(GameState, State, override);

public:
    virtual void update(float dt) override;

protected:
    GameState();
};

#endif // GAMESTATE_H
