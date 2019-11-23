#include "Application.h"
#include "GameState.h"

Window& Application::window()
{
    ASSERT(m_window.is_not_null());
    return *m_window;
}

const Window& Application::window() const
{
    ASSERT(m_window.is_not_null());
    return *m_window;
}

Renderer& Application::renderer() { return m_window->renderer(); }

const Renderer& Application::renderer() const { return m_window->renderer(); }

Application::Application(BackendImplementation type)
    : m_window(Window::construct(type, *this)),
      m_current_state(GameState::construct(*this)), m_is_running(true)
{
    while (m_is_running)
    {
        ASSERT(m_current_state.is_not_null());

        // FIXME delta time
        m_current_state->update(0);

        m_window->draw();
    }
}
