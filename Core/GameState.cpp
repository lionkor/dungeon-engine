#include "GameState.h"
#include "Application.h"
#include "Window.h"

void GameState::update(float dt)
{
    for (auto& [id, entity] : m_entities)
    {
        entity->update(dt);
    }

    if (Window::the().is_key_pressed(Key::Escape))
    {
        Application::the().shutdown(ShutdownHint::GameExit);
    }
}

GameState::GameState() : State()
{
}
