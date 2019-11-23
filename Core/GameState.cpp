#include "GameState.h"
#include "Application.h"

void GameState::update(float dt)
{
    for (auto& [id, entity] : m_entities)
    {
        entity->update(dt);
    }

    NOTIMPL
}

GameState::GameState(Application& application) : State(application) {}
